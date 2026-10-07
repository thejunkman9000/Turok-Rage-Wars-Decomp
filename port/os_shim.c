/* libultra shim for the Windows port: threads, message queues, timers, interrupts-as-events, PI DMA, VI, controller.
 *
 * libultra threads are priority scheduled and only switch when something blocks or a higher-priority thread is woken.
 * Each game thread is a Windows thread, but only the thread holding the "baton" (g_current) runs; everyone else waits
 * on a private event.  Message queues use the guest's own OSMesgQueue structures (msg buffer, count, first). */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <intrin.h>
#include "os_types.h"

/* Guest memory (game structs, message buffers, DMA targets) is big-endian: the game code reads it through byte-swapping
   loads/stores (port/be_ir.py).  The shim must use the same representation for every guest field it touches. */
#define LD32(x) ((u32)_byteswap_ulong(*(volatile unsigned long *)&(x)))
#define ST32(x, v) (*(volatile unsigned long *)&(x) = _byteswap_ulong((unsigned long)(v)))
#define LD16(x) ((u16)_byteswap_ushort(*(volatile unsigned short *)&(x)))
#define ST16(x, v) (*(volatile unsigned short *)&(x) = _byteswap_ushort((unsigned short)(v)))
#define LD64(x) ((u64)_byteswap_uint64(*(volatile unsigned __int64 *)&(x)))
#define ST64(x, v) (*(volatile unsigned __int64 *)&(x) = _byteswap_uint64((unsigned __int64)(v)))
/* guest pointers into the low guest space (overlay data, assets) are accessed at +0x30000000 on the host */
#define XL(p) ((void *)(size_t)((((u32)(size_t)(p)) - 0x200000u) < 0x1E00000u ? (u32)(size_t)(p) + 0x30000000u : (u32)(size_t)(p)))
#define LDP(x) ((void *)(size_t)LD32(x))                 /* guest pointer fields are 32-bit big-endian */
#define STP(x, v) ST32(x, (u32)(size_t)(v))

#define MAXT 64
typedef struct HThread {
    OSThread *t;
    HANDLE evt;
    int prio, state;             /* state: 0 free, 1 stopped, 2 ready, 3 running, 4 waiting */
    void (*entry)(void *);
    void *arg;
    OSMesgQueue *waitq; int waitkind;   /* waiting on queue: 1 = receive (empty), 2 = send (full) */
    unsigned seq;                /* FIFO order among equal priorities */
    DWORD tid;
    float fpr[32];               /* the guest FPU registers of this thread (statically recompiled code keeps them in g_fpr) */
} HThread;

static CRITICAL_SECTION g_lock;
static int g_inited;
static HThread g_th[MAXT];
static HThread *g_current;
static unsigned g_seq;
static volatile LONG g_preempt;
static __declspec(thread) HThread *tls_self;

extern void port_unimpl(const char *name);
extern unsigned char *port_rom(unsigned *size);

static void os_init(void) {
    if (g_inited) return;
    InitializeCriticalSection(&g_lock); g_inited = 1;
}

static HThread *self_thread(void) {
    if (tls_self) return tls_self;
    /* an unregistered host thread calling into the OS = the game's boot thread: adopt it as a running thread */
    EnterCriticalSection(&g_lock);
    for (int i = 0; i < MAXT; i++) if (!g_th[i].state) {
        HThread *h = &g_th[i]; memset(h, 0, sizeof *h);
        h->evt = CreateEventA(NULL, FALSE, FALSE, NULL); h->prio = 10; h->state = 3; h->seq = ++g_seq;
        tls_self = h; h->tid = GetCurrentThreadId(); if (!g_current) g_current = h;
        LeaveCriticalSection(&g_lock); return h;
    }
    LeaveCriticalSection(&g_lock); return NULL;
}

/* choose the best runnable thread; caller holds g_lock.  Returns with g_current set (or NULL when all are blocked). */
static HThread *pick(void) {
    HThread *best = NULL;
    for (int i = 0; i < MAXT; i++) {
        HThread *h = &g_th[i];
        if (h->state != 2 && h->state != 3) continue;
        if (!best || h->prio > best->prio || (h->prio == best->prio && h->seq < best->seq)) best = h;
    }
    return best;
}

/* give the baton away if someone better is runnable (or self blocked); wait until self is current again.  Holds g_lock on entry/exit. */
extern float g_fpr[32];
static void reschedule(HThread *self) {
    for (;;) {
        HThread *best = pick();
        if (best == self && self->state != 4) { self->state = 3; g_current = self; return; }
        if (self->state == 3) { self->state = 2; self->seq = ++g_seq; best = pick(); if (best == self) { self->state = 3; g_current = self; return; } }
        g_current = best;
        if (best) { best->state = 3; SetEvent(best->evt); }
        memcpy(self->fpr, g_fpr, sizeof g_fpr);
        LeaveCriticalSection(&g_lock);
        WaitForSingleObject(self->evt, INFINITE);
        EnterCriticalSection(&g_lock);
        if (g_current == self) { self->state = 3; memcpy(g_fpr, self->fpr, sizeof g_fpr); return; }
    }
}

static void maybe_yield(HThread *self) {
    if (!g_preempt) return;
    EnterCriticalSection(&g_lock); g_preempt = 0; reschedule(self); LeaveCriticalSection(&g_lock);
}

static void wake_one(OSMesgQueue *mq, int kind) {          /* wake the highest-priority waiter; caller holds g_lock */
    HThread *best = NULL;
    for (int i = 0; i < MAXT; i++) {
        HThread *h = &g_th[i];
        if (h->state == 4 && h->waitq == mq && h->waitkind == kind && (!best || h->prio > best->prio)) best = h;
    }
    if (best) { best->state = 2; best->waitq = NULL; best->seq = ++g_seq; if (!g_current || best->prio > g_current->prio) g_preempt = 1; }
}

/* ---- message queues ---- */
void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count) {
    os_init(); mq = (OSMesgQueue *)XL(mq); STP(mq->mtqueue, 0); STP(mq->fullqueue, 0); ST32(mq->validCount, 0); ST32(mq->first, 0); ST32(mq->msgCount, count); STP(mq->msg, msg);
}

static int send_common(OSMesgQueue *mq, OSMesg m, s32 flags, int jam) {
    mq = (OSMesgQueue *)XL(mq);
    HThread *self = self_thread(); os_init();
    maybe_yield(self);
    EnterCriticalSection(&g_lock);
    while ((s32)LD32(mq->validCount) >= (s32)LD32(mq->msgCount)) {
        if (flags == OS_MESG_NOBLOCK) { LeaveCriticalSection(&g_lock); return -1; }
        self->state = 4; self->waitq = mq; self->waitkind = 2; reschedule(self);
    }
    {
        OSMesg *buf = (OSMesg *)XL(LDP(mq->msg)); s32 cnt = (s32)LD32(mq->msgCount), first = (s32)LD32(mq->first), valid = (s32)LD32(mq->validCount);
        if (jam) { first = (first + cnt - 1) % cnt; ST32(mq->first, first); ST32(buf[first], (u32)(size_t)m); }
        else ST32(buf[(first + valid) % cnt], (u32)(size_t)m);
        ST32(mq->validCount, valid + 1);
    }
    wake_one(mq, 1);
    if (g_preempt) { g_preempt = 0; reschedule(self); }
    LeaveCriticalSection(&g_lock);
    return 0;
}
s32 osSendMesg(OSMesgQueue *mq, OSMesg m, s32 flags) { return send_common(mq, m, flags, 0); }
s32 osJamMesg(OSMesgQueue *mq, OSMesg m, s32 flags) { return send_common(mq, m, flags, 1); }

s32 osRecvMesg(OSMesgQueue *mq, OSMesg *m, s32 flags) {
    mq = (OSMesgQueue *)XL(mq); m = (OSMesg *)XL(m);
    HThread *self = self_thread(); os_init();
    maybe_yield(self);                                    /* a polling thread must not starve a higher-priority thread that became ready */
    EnterCriticalSection(&g_lock);
    while ((s32)LD32(mq->validCount) == 0) {
        if (flags == OS_MESG_NOBLOCK) { LeaveCriticalSection(&g_lock); return -1; }
        self->state = 4; self->waitq = mq; self->waitkind = 1;
        reschedule(self);
    }
    {
        OSMesg *buf = (OSMesg *)XL(LDP(mq->msg)); s32 cnt = (s32)LD32(mq->msgCount), first = (s32)LD32(mq->first);
        if (m) ST32(*m, LD32(buf[first]));
        ST32(mq->first, (first + 1) % cnt); ST32(mq->validCount, (s32)LD32(mq->validCount) - 1);
    }
    wake_one(mq, 2);
    if (g_preempt) { g_preempt = 0; reschedule(self); }
    LeaveCriticalSection(&g_lock);
    return 0;
}

/* messages posted from host threads (VI tick, timers, DMA completion): never block */
static void post_from_host(OSMesgQueue *mq, OSMesg m) {
    mq = (OSMesgQueue *)XL(mq);
    if (!mq) return; os_init();
    if (IsBadReadPtr(mq, 24)) { fprintf(stderr, "post_from_host: unreadable queue %p\n", (void *)mq); fflush(stderr); return; }
    EnterCriticalSection(&g_lock);
    if ((s32)LD32(mq->validCount) < (s32)LD32(mq->msgCount)) {
        OSMesg *buf = (OSMesg *)XL(LDP(mq->msg)); s32 cnt = (s32)LD32(mq->msgCount), first = (s32)LD32(mq->first), valid = (s32)LD32(mq->validCount);
        if (IsBadWritePtr(buf, 4) || cnt <= 0) { fprintf(stderr, "post_from_host: bad queue %p msg=%08X count=%d valid=%d first=%d\n", (void *)mq, LD32(mq->msg), cnt, valid, first); fflush(stderr); LeaveCriticalSection(&g_lock); return; }
        ST32(buf[(first + valid) % cnt], (u32)(size_t)m); ST32(mq->validCount, valid + 1);
        wake_one(mq, 1);
        if (!g_current) { HThread *b = pick(); if (b) { g_current = b; b->state = 3; SetEvent(b->evt); } g_preempt = 0; }
    }
    LeaveCriticalSection(&g_lock);
}

/* ---- threads ---- */
static DWORD WINAPI thread_proc(LPVOID p) {
    HThread *h = (HThread *)p; tls_self = h; h->tid = GetCurrentThreadId();
    WaitForSingleObject(h->evt, INFINITE);                /* wait for our first turn */
    h->entry(h->arg);
    EnterCriticalSection(&g_lock);                        /* entry returned: the thread is finished */
    h->state = 1; if (g_current == h) g_current = NULL;
    HThread *b = pick(); if (b) { g_current = b; b->state = 3; SetEvent(b->evt); }
    LeaveCriticalSection(&g_lock);
    return 0;
}

extern void *port_resolve(unsigned guest);
void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) {
    OSThread *tx = (OSThread *)XL(t);
    os_init(); (void)sp; entry = (void (*)(void *))port_resolve((unsigned)(size_t)entry);
    EnterCriticalSection(&g_lock);
    for (int i = 0; i < MAXT; i++) if (!g_th[i].state) {
        HThread *h = &g_th[i]; memset(h, 0, sizeof *h);
        h->t = t; h->prio = pri; h->state = 1; h->entry = entry; h->arg = arg;
        h->evt = CreateEventA(NULL, FALSE, FALSE, NULL);
        ST32(tx->priority, pri); ST32(tx->id, id); ST16(tx->state, OS_STATE_STOPPED); STP(tx->next, 0); STP(tx->queue, 0);
        CreateThread(NULL, 1024 * 1024, thread_proc, h, 0, NULL);
        break;
    }
    LeaveCriticalSection(&g_lock);
}
static HThread *find(OSThread *t) {
    if (!t) return self_thread();
    for (int i = 0; i < MAXT; i++) if (g_th[i].state && g_th[i].t == t) return &g_th[i];
    return NULL;
}
void osStartThread(OSThread *t) {
    HThread *self = self_thread(); os_init();
    EnterCriticalSection(&g_lock);
    HThread *h = find(t);
    if (h && h->state == 1) { h->state = 2; h->seq = ++g_seq; ST16(((OSThread *)XL(t))->state, OS_STATE_RUNNABLE); reschedule(self); }
    LeaveCriticalSection(&g_lock);
}
void osSetThreadPri(OSThread *t, OSPri pri) {
    HThread *self = self_thread(); os_init();
    EnterCriticalSection(&g_lock);
    HThread *h = find(t); if (h) { h->prio = pri; if (h->t) ST32(((OSThread *)XL(h->t))->priority, pri); }
    reschedule(self);
    LeaveCriticalSection(&g_lock);
}
OSId osGetThreadId(OSThread *t) { HThread *h = find(t); return h && h->t ? (OSId)LD32(((OSThread *)XL(h->t))->id) : 0; }

/* ---- time and timers ---- */
static unsigned long long counter_now(void) {
    LARGE_INTEGER f, c; QueryPerformanceFrequency(&f); QueryPerformanceCounter(&c);
    return (unsigned long long)((double)c.QuadPart * 46875000.0 / (double)f.QuadPart);
}
u64 osGetTime(void) { maybe_yield(self_thread()); return counter_now(); }

typedef struct { OSTimer *t; unsigned long long due, interval; int live; } HTimer;
static HTimer g_timers[64];
s32 osSetTimer(OSTimer *t, u64 value, u64 interval, OSMesgQueue *mq, OSMesg msg) {
    os_init(); { static int nt; if (nt++ < 30) { fprintf(stderr, "osSetTimer(%p, %llu, %llu, %p, %p)\n", (void *)t, (unsigned long long)value, (unsigned long long)interval, (void *)mq, (void *)msg); } } { OSTimer *tx = (OSTimer *)XL(t); STP(tx->mq, mq); ST32(tx->msg, (u32)(size_t)msg); ST64(tx->interval, interval); }
    EnterCriticalSection(&g_lock);
    for (int i = 0; i < 64; i++) if (!g_timers[i].live || g_timers[i].t == t) {
        g_timers[i].t = t; g_timers[i].due = counter_now() + value; g_timers[i].interval = interval; g_timers[i].live = 1; break;
    }
    LeaveCriticalSection(&g_lock);
    return 0;
}
s32 osStopTimer(OSTimer *t) {
    EnterCriticalSection(&g_lock);
    for (int i = 0; i < 64; i++) if (g_timers[i].live && g_timers[i].t == t) g_timers[i].live = 0;
    LeaveCriticalSection(&g_lock);
    return 0;
}
static void run_timers(void) {                               /* called from the platform loop */
    unsigned long long now = counter_now();
    for (int i = 0; i < 64; i++) {
        OSTimer *t = NULL;
        EnterCriticalSection(&g_lock);
        if (g_timers[i].live && now >= g_timers[i].due) {
            t = g_timers[i].t;
            if (g_timers[i].interval) g_timers[i].due += g_timers[i].interval; else g_timers[i].live = 0;
        }
        LeaveCriticalSection(&g_lock);
        if (t) { OSTimer *tx = (OSTimer *)XL(t); post_from_host((OSMesgQueue *)LDP(tx->mq), (OSMesg)(size_t)LD32(tx->msg)); }
    }
}

/* ---- events / VI ---- */
static OSMesgQueue *g_ev_mq[16]; static OSMesg g_ev_msg[16];
void osSetEventMesg(OSEvent e, OSMesgQueue *mq, OSMesg m) { fprintf(stderr, "osSetEventMesg(%d, %p, %p)\n", (int)e, (void *)mq, (void *)m); if (e < 16) { g_ev_mq[e] = mq; g_ev_msg[e] = m; } }
static OSMesgQueue *g_vi_mq; static OSMesg g_vi_msg; static int g_vi_count = 1, g_vi_phase;
void osViSetEvent(OSMesgQueue *mq, OSMesg m, u32 retraceCount) { fprintf(stderr, "osViSetEvent(%p, %p, %u)\n", (void *)mq, (void *)m, retraceCount); g_vi_mq = mq; g_vi_msg = m; g_vi_count = retraceCount ? retraceCount : 1; }
void osCreateViManager(OSPri pri) { (void)pri; os_init(); }
void osViBlack(u8 active) { (void)active; }
void osViSetMode(OSViMode *m) { (void)m; }
void osViSetSpecialFeatures(u32 f) { (void)f; }
void osViSetYScale(f32 v) { (void)v; }
static void *g_fb;
void osViSwapBuffer(void *fb) { g_fb = fb; }
void *osViGetCurrentFramebuffer(void) { return g_fb; }

void port_dump_threads(void);
static int g_tq[16], g_tq_r, g_tq_w, g_tq_n; int g_dbg_startgo, g_dbg_pop;
/* called once per displayed frame by the platform loop */
void port_vi_tick(void) {
    if (!g_inited) return;
    run_timers();
    {   /* watchdog: if the baton holder never makes progress (lost wake-up), nudge it */
        static HThread *last; static unsigned lastseq; static int stuck;
        EnterCriticalSection(&g_lock);
        if (g_current && g_current == last && g_seq == lastseq) { if (++stuck == 30) { { extern void port_dump_trace_pub(int); static int dumped; if (!dumped++) { port_dump_threads(); port_dump_trace_pub(300); } } fprintf(stderr, "baton watchdog: nudging thread %d (state %d)\n", (int)(g_current - g_th), g_current->state); fflush(stderr); SetEvent(g_current->evt); stuck = 0; } }
        else stuck = 0;
        last = g_current; lastseq = g_seq;
        LeaveCriticalSection(&g_lock);
    }
    for (;;) {                       /* one queued RSP task completion per tick: SP done, then DP done for graphics tasks */
        int isgfx = -1;
        EnterCriticalSection(&g_lock);
        if (g_tq_n) { g_dbg_pop++; isgfx = g_tq[g_tq_r]; g_tq_r = (g_tq_r + 1) & 15; g_tq_n--; }
        LeaveCriticalSection(&g_lock);
        if (isgfx < 0) break;
        if (g_ev_mq[4]) post_from_host(g_ev_mq[4], g_ev_msg[4]);                 /* SP done */
        if (isgfx && g_ev_mq[9]) post_from_host(g_ev_mq[9], g_ev_msg[9]);        /* DP done */
        break;
    }
    if (g_ev_mq[OS_EVENT_VI]) post_from_host(g_ev_mq[OS_EVENT_VI], g_ev_msg[OS_EVENT_VI]);
    if (g_vi_mq && ++g_vi_phase >= g_vi_count) { g_vi_phase = 0; post_from_host(g_vi_mq, g_vi_msg); }
}

/* ---- RSP/RDP tasks: the display list is captured for the renderer; completion is signalled immediately ---- */
static OSTask g_task; static int g_task_pending;
OSTask g_gfx_task; volatile LONG g_gfx_task_ready;
s32 osSpTaskLoad(OSTask *t) { g_task = *(OSTask *)XL(t); return 0; }
s32 osSpTaskStartGo(OSTask *t) {
    (void)t; g_dbg_startgo++;
    { int gfx = LD32(g_task.t.type) == 1; if (g_dbg_startgo < 12) { fprintf(stderr, "StartGo #%d type=%u flags=%08X\n", g_dbg_startgo, (unsigned)LD32(g_task.t.type), (unsigned)LD32(g_task.t.flags)); }
      if (gfx) { g_gfx_task = g_task; InterlockedExchange(&g_gfx_task_ready, 1); }
      os_init(); EnterCriticalSection(&g_lock); if (g_tq_n < 16) { g_tq[g_tq_w] = gfx; g_tq_w = (g_tq_w + 1) & 15; g_tq_n++; } LeaveCriticalSection(&g_lock); }   /* completion is delivered from the frame tick: the caller still has bookkeeping to do */
    return 0;
}
void osSpTaskYield(void) {}
s32 osSpTaskYielded(OSTask *t) { (void)t; return 0; }
s32 osDpSetNextBuffer(void *a, u64 b) { (void)a; (void)b; return 0; }

/* ---- cartridge DMA ---- */
static void rom_copy(void *dst, u32 dev, u32 n) {
    unsigned size; unsigned char *rom = port_rom(&size);
    u32 off = dev & 0x0FFFFFFF; if (dev >= 0x10000000) off = dev - 0x10000000;
    if (rom && off < size) memcpy(dst, rom + off, (off + n <= size) ? n : size - off);
}
s32 osPiStartDma(OSIoMesg *mb, s32 pri, s32 dir, u32 dev, void *vaddr, u32 n, OSMesgQueue *mq) {
    (void)pri;
    fprintf(stderr, "osPiStartDma dir=%d dev=%08X dram=%p size=%X\n", dir, dev, vaddr, n);
    if (dir == 0) rom_copy(XL(vaddr), dev, n);                    /* OS_READ */
    STP(((OSIoMesg *)XL(mb))->hdr.retQueue, mq);
    post_from_host(mq, (OSMesg)mb);
    return 0;
}
s32 osPiRawStartDma(s32 dir, u32 dev, void *vaddr, u32 n) {
    fprintf(stderr, "osPiRawStartDma dir=%d dev=%08X dram=%p size=%X\n", dir, dev, vaddr, n);
    if (!vaddr) return -1;
    if (dir == 0) rom_copy(XL(vaddr), dev, n);
    post_from_host(g_ev_mq[8], g_ev_msg[8]);                  /* PI interrupt: DMA finished */
    return 0;
}
u32 osPiGetStatus(void) { return 0; }

/* ---- memory / cache / TLB / interrupts: nothing to do on the host ---- */
void osInvalDCache(void *a, s32 n) { (void)a; (void)n; }
void osInvalICache(void *a, s32 n) { (void)a; (void)n; }
void osWritebackDCache(void *a, s32 n) { (void)a; (void)n; }
void osWritebackDCacheAll(void) {}
void osMapTLB(s32 i, s32 ps, void *v, u32 e0, u32 e1, s32 a) { (void)i; (void)ps; (void)v; (void)e0; (void)e1; (void)a; }
void osUnmapTLB(s32 i) { (void)i; }
void osUnmapTLBAll(void) {}
u32 osVirtualToPhysical(void *v) { u32 a = (u32)(size_t)v; return a >= 0x80000000u ? (a & 0x1FFFFFFFu) : a; }
u32 osSetIntMask(u32 m) { (void)m; return 0x3F01; }
u32 __osDisableInt(void) { return 1; }
void __osRestoreInt(u32 v) { (void)v; }
void osInitialize(void) { os_init(); }

/* ---- controllers: keyboard for now ---- */
static int key(int vk) { return (GetAsyncKeyState(vk) & 0x8000) != 0; }
s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *status) {
    (void)mq; bitpattern = (u8 *)XL(bitpattern); status = (OSContStatus *)XL(status); *bitpattern = 1;
    for (int i = 0; i < 4; i++) { ST16(status[i].type, i == 0 ? 0x0500 : 0); status[i].status = 0; status[i].errno_ = i == 0 ? 0 : 0x80; }
    return 0;
}
s32 osContStartReadData(OSMesgQueue *mq) { post_from_host(mq, (OSMesg)0); return 0; }
void osContGetReadData(OSContPad *pad) {
    pad = (OSContPad *)XL(pad);
    memset(pad, 0, 4 * sizeof *pad);
    u16 b = 0;
    if (key(VK_RETURN)) b |= 0x1000;                          /* Start */
    if (key('Z')) b |= 0x2000;                                /* Z */
    if (key('X')) b |= 0x4000;                                /* B */
    if (key('C')) b |= 0x8000;                                /* A */
    ST16(pad[0].button, b);
    pad[0].stick_x = (s8)((key(VK_RIGHT) ? 80 : 0) - (key(VK_LEFT) ? 80 : 0));
    pad[0].stick_y = (s8)((key(VK_UP) ? 80 : 0) - (key(VK_DOWN) ? 80 : 0));
}
s32 osContStartQuery(OSMesgQueue *mq) { post_from_host(mq, (OSMesg)0); return 0; }
void osContGetQuery(OSContStatus *status) { memset(status, 0, 4 * sizeof *status); ST16(status[0].type, 0x0500); }
s32 osContReset(OSMesgQueue *mq, OSContStatus *s) { (void)mq; (void)s; return 0; }
s32 osMotorInit(OSMesgQueue *mq, void *pfs, s32 ch) { (void)mq; (void)pfs; (void)ch; return 1; }
s32 osMotorStart(void *pfs) { (void)pfs; return 0; }
s32 osMotorStop(void *pfs) { (void)pfs; return 0; }

/* ---- audio interface (placeholder until the audio backend exists) ---- */
s32 osAiSetFrequency(u32 f) { return (s32)f; }
s32 osAiSetNextBuffer(void *b, u32 n) { (void)b; (void)n; return 0; }
u32 osAiGetStatus(void) { return 0; }

static HANDLE h_open(DWORD tid) { return tid ? OpenThread(THREAD_ALL_ACCESS, FALSE, tid) : NULL; }
/* debugging aid: what is every game thread doing? */
void port_dump_threads(void) {
    int i;
    EnterCriticalSection(&g_lock);
    fprintf(stderr, "threads (current=%p):\n", (void *)g_current);
    for (i = 0; i < MAXT; i++) if (g_th[i].state) {
        HANDLE th = h_open(g_th[i].tid); CONTEXT c; unsigned *sp; int k; unsigned base = (unsigned)(size_t)GetModuleHandleA(NULL);
        fprintf(stderr, "  [%d] tid=%lX state=%d prio=%d entry=%X waitq=%p kind=%d\n", i, (unsigned long)(g_th[i].tid & 0xFFFF), g_th[i].state, g_th[i].prio, (unsigned)((size_t)g_th[i].entry - base), (void *)g_th[i].waitq, g_th[i].waitkind);
        if (th && g_th[i].tid != GetCurrentThreadId()) {
            SuspendThread(th); c.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER; GetThreadContext(th, &c);
            fprintf(stderr, "      eip rva %X stack:", (unsigned)c.Eip - base); sp = (unsigned *)c.Esp;
            for (k = 0; k < 96; k++) if (sp[k] > base && sp[k] < base + 0x1C2000) fprintf(stderr, " %X", sp[k] - base);
            fprintf(stderr, "\n"); ResumeThread(th);
        }
        if (th) CloseHandle(th);
    }
    LeaveCriticalSection(&g_lock); fflush(stderr);
}

/* ---- serial interface (PIF): no controller pak / EEPROM on the host; the transfer "completes" with the buffer untouched ---- */
s32 __osSiRawStartDma(s32 dir, void *pif_ram) { (void)dir; (void)pif_ram; post_from_host(g_ev_mq[5], g_ev_msg[5]); return 0; }
u32 __osGetFpcCsr(void) { return 0; }
u32 __osSetFpcCsr(u32 v) { (void)v; return 0; }

/* a game thread that ended (returned or crashed) must give the baton back, otherwise every other thread waits for it forever */
void port_thread_died(void) {
    HThread *h = tls_self;
    if (!h || !g_inited) return;
    EnterCriticalSection(&g_lock);
    h->state = 1; if (g_current == h) g_current = NULL;
    { HThread *b = pick(); if (b) { g_current = b; b->state = 3; SetEvent(b->evt); } }
    LeaveCriticalSection(&g_lock);
}
