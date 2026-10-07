/* Glue between the platform loop (win32_main.cpp) and the game code.
   Milestone 3: reserve guest memory at the original addresses, load the ROM's data, run the game's main thread. */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <intrin.h>
#include <tlhelp32.h>

struct ID3D11DeviceContext;

static unsigned char *g_rom; static unsigned g_rom_size;
static volatile LONG g_frames;

unsigned char *port_rom(unsigned *size) { if (size) *size = g_rom_size; return g_rom; }
extern void port_vi_tick(void);

static void dump_trace(int n);
void port_unimpl(const char *name) {
    static char seen[8192][48]; static int n;
    for (int i = 0; i < n; i++) if (!strcmp(seen[i], name)) return;     /* log each missing function once */
    if (n < 8192) { strncpy(seen[n], name, 47); n++; }
    fprintf(stderr, "UNIMPLEMENTED: %s\n", name); dump_trace(14); fflush(stderr);
}

static int load_rom(const char *path) {
    FILE *f = fopen(path, "rb"); if (!f) return 0;
    fseek(f, 0, SEEK_END); g_rom_size = ftell(f); fseek(f, 0, SEEK_SET);
    g_rom = (unsigned char *)malloc(g_rom_size); fread(g_rom, 1, g_rom_size, f); fclose(f); return 1;
}

static void *reserve(unsigned addr, unsigned size, const char *what) {
    void *p = VirtualAlloc((void *)(size_t)addr, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    fprintf(stderr, "guest %-10s 0x%08X..0x%08X : %s\n", what, addr, addr + size, p ? "ok" : "FAILED");
    if (!p) {
        MEMORY_BASIC_INFORMATION mi;
        if (VirtualQuery((void *)(size_t)addr, &mi, sizeof mi))
            fprintf(stderr, "  blocked by region 0x%08X size 0x%X state 0x%lX type 0x%lX\n",
                    (unsigned)(size_t)mi.BaseAddress, (unsigned)mi.RegionSize, mi.State, mi.Type);
    }
    return p;
}

/* Guest memory keeps the ROM's big-endian byte order: the game C is compiled so that all its loads and stores are
   byte-swapped (port/be_ir.py), so data is copied unchanged. */
#define GUEST_DELTA 0x30000000u
#define PAGED_LO 0x00800000u      /* guest: virtual address = page << 12 (assets contain absolute pointers into it) */
#define PAGED_HI 0x02000000u
#define H(guest) ((unsigned char *)(size_t)((unsigned)(guest) + GUEST_DELTA))
static void raw_copy(unsigned char *dst, unsigned rom0, unsigned rom1) { memcpy(dst, g_rom + rom0, rom1 - rom0); }

/* Guest code addresses stored in data tables (callbacks, dispatch tables) -> addresses of the host functions. */
struct port_fn { unsigned guest; void *host; };
extern struct port_fn port_fn_table[]; extern int port_fn_count;
static int cmp_fn(const void *a, const void *b) { unsigned x = ((const struct port_fn *)a)->guest, y = ((const struct port_fn *)b)->guest; return x < y ? -1 : x > y; }
static unsigned bswap32(unsigned v) { return _byteswap_ulong(v); }
static void relocate_fnptrs(unsigned char *base, unsigned size) {
    int n = 0;
    qsort(port_fn_table, port_fn_count, sizeof(struct port_fn), cmp_fn);
    for (unsigned i = 0; i + 3 < size; i += 4) {
        unsigned w = bswap32(*(unsigned *)(base + i));
        if (w < 0x200400u || w > 0x4FFFFFu) continue;
        struct port_fn key = { w, 0 };
        struct port_fn *f = (struct port_fn *)bsearch(&key, port_fn_table, port_fn_count, sizeof key, cmp_fn);
        if (f) { *(unsigned *)(base + i) = bswap32((unsigned)(size_t)f->host); n++; }
    }
    fprintf(stderr, "relocated %d code pointers in 0x%X bytes\n", n, size);
}

/* ROM data -> guest RAM.  VA = 0x80000000 + (ROM - 0xC00) for the main image's data; overlay A: VA 0x400000 = ROM 0x16E000. */
static void load_guest_data(int have_overlay) {
    /* the boot loader (func_002A81B0) copies the image and then zero-fills RAM from D_800E8000 up to D_8016E000 (= .bss),
       so only the data below 0x800E8000 (ROM 0xE8C00) is initialised */
    unsigned char *d = (unsigned char *)(size_t)(0x80000000u + 0xC7010u - 0xC00u);
    raw_copy(d, 0xC7010u, 0xE8C00u); relocate_fnptrs(d, 0xE8C00u - 0xC7010u);
    if (have_overlay) {
        unsigned char *o = H(0x400000u + 0x1BCDA0u - 0x16E000u);
        raw_copy(o, 0x1BCDA0u, 0x1EE000u); relocate_fnptrs(o, 0x1EE000u - 0x1BCDA0u);
    }
}

extern void func_00293518(void);                            /* game boot thread entry: sprintf, FPU setup, then func_00291404(&D_8011FAC0) */

static void dump_trace(int n);

/* TUROK_SAMPLE=1: every 3 s print where every thread of the process currently executes (rva; symbolize with port/where.py style tools) */
static DWORD WINAPI sampler_thread(LPVOID p) {
    size_t base = (size_t)GetModuleHandleA(NULL); (void)p;
    for (;;) {
        HANDLE snap; THREADENTRY32 te; Sleep(3000);
        snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0); te.dwSize = sizeof te;
        if (snap == INVALID_HANDLE_VALUE) continue;
        fprintf(stderr, "sample:");
        if (Thread32First(snap, &te)) do {
            if (te.th32OwnerProcessID == GetCurrentProcessId() && te.th32ThreadID != GetCurrentThreadId()) {
                HANDLE h = OpenThread(THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT, FALSE, te.th32ThreadID);
                if (h) { CONTEXT c; c.ContextFlags = CONTEXT_CONTROL; if (SuspendThread(h) != (DWORD)-1) { c.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER; if (GetThreadContext(h, &c)) { unsigned long *sp = (unsigned long *)c.Esp; int i, k = 0; fprintf(stderr, " [%lX%s", te.th32ThreadID & 0xFFFF, (c.Eip > base && c.Eip < base + 0x400000) ? " RUN" : ""); __try { for (i = 0; i < 600 && k < 12; i++) if (sp[i] > base && sp[i] < base + 0x400000 && *(unsigned char *)(sp[i] - 5) == 0xE8) { fprintf(stderr, " %lX", sp[i] - (unsigned long)base); k++; } } __except (EXCEPTION_EXECUTE_HANDLER) { } fprintf(stderr, "]"); } ResumeThread(h); } CloseHandle(h); }
            }
        } while (Thread32Next(snap, &te));
        fprintf(stderr, "\n"); fflush(stderr); CloseHandle(snap);
    }
}
static void dump_trace(int n);
static DWORD WINAPI game_thread(LPVOID p) {
    (void)p;
    { extern float sinf(float), cosf(float); volatile float a = 1.309f; fprintf(stderr, "libm test: sinf=%g cosf=%g\n", (double)sinf(a), (double)cosf(a)); }
    fprintf(stderr, "game thread: calling func_00293518\n"); fflush(stderr);
    __try { func_00293518(); }
    __except (fprintf(stderr, "game thread exception 0x%08lX at %p\n", GetExceptionCode(),
                      GetExceptionInformation()->ExceptionRecord->ExceptionAddress), dump_trace(60), EXCEPTION_EXECUTE_HANDLER) { }
    fprintf(stderr, "game thread ended\n"); fflush(stderr);
    { extern void port_thread_died(void); port_thread_died(); }
    return 0;
}

/* ring buffer of the most recent instrumented function entries (see port/penter.asm) */
#define TRACE_N 8192
static volatile LONG g_trace_pos; static unsigned g_trace[TRACE_N][2];
void __cdecl port_trace_enter(unsigned ret) {
    LONG i = InterlockedIncrement(&g_trace_pos) & (TRACE_N - 1);
    g_trace[i][0] = GetCurrentThreadId(); g_trace[i][1] = ret;
}
void __cdecl __cyg_profile_func_enter(void *fn, void *site) { port_trace_enter((unsigned)(size_t)fn + 1); (void)site; }
void __cdecl __cyg_profile_func_exit(void *fn, void *site) { (void)fn; (void)site; }
static void dump_trace(int n) {
    size_t base = (size_t)GetModuleHandleA(NULL);
    LONG p = g_trace_pos;
    fprintf(stderr, "  trace (oldest first):");
    for (int k = n; k >= 0; k--) {
        unsigned *e = g_trace[(p - k) & (TRACE_N - 1)];
        if (e[1]) fprintf(stderr, " %lX:%X", (unsigned long)e[0] & 0xFFFF, e[1] - (unsigned)base);
    }
    fprintf(stderr, "\n");
}

/* ---- demand paging of TLB-mapped asset space ----------------------------------------------------------------------
   The game maps resources at virtual addresses >= 0x400000 through the N64 TLB and loads each 4 KB page from the cartridge
   when it is first touched (TLB-miss exception -> loader thread -> DMA).  Here the whole range is reserved but not committed;
   touching an uncommitted page raises an access violation, which is resolved by looking the page up in the game's own region
   list (D_80103F88: next@0, base@4 (page), size@6 (pages), romAddr@8, all big-endian) and copying it from the ROM. */
/* Guest low space [0x200000,0x2000000) (asset pages, overlay data) is accessed by the game code through an address translation
   (port/be_ir.py: guest + GUEST_DELTA), because a 32-bit process on 64-bit Windows already has system allocations scattered
   over those addresses.  The paged asset space starts at guest 0x800000. */
static unsigned be32(const void *p) { return _byteswap_ulong(*(const unsigned long *)p); }
static unsigned be16(const void *p) { return _byteswap_ushort(*(const unsigned short *)p); }
static int g_paged_faults;

static int page_in(unsigned addr) {
    unsigned page = addr >> 12;                                          /* guest virtual page */
    unsigned char *r = (unsigned char *)(size_t)0x80103F88u;           /* region list head (the overlay region comes first) */
    for (int guard = 0; r && guard < 4096; guard++) {
        unsigned base = be16(r + 4), size = be16(r + 6);
        if (page >= base && page < base + size) {
            unsigned rom = (be32(r + 8) & 0x0FFFFFFFu) + ((page - base) << 12);
            void *p = VirtualAlloc((void *)(size_t)(GUEST_DELTA + (page << 12)), 0x1000, MEM_COMMIT, PAGE_READWRITE);
            if (!p) { fprintf(stderr, "page_in: commit of va=%08X failed (error %lu)\n", page << 12, GetLastError()); return 0; }
            memset(p, 0, 0x1000);
            if (rom < g_rom_size) memcpy(p, g_rom + rom, (g_rom_size - rom < 0x1000) ? g_rom_size - rom : 0x1000);
            if (++g_paged_faults <= 40) fprintf(stderr, "page-in va=%08X rom=%08X (region base page %X size %X)\n", page << 12, rom, base, size);
            return 1;
        }
        r = (unsigned char *)(size_t)be32(r);
    }
    fprintf(stderr, "page_in: no region for va=%08X; list:", addr);
    r = (unsigned char *)(size_t)0x80103F88u;
    for (int guard = 0; r && guard < 8; guard++) { fprintf(stderr, " [%p base=%X size=%X rom=%08X]", r, be16(r + 4), be16(r + 6), be32(r + 8)); r = (unsigned char *)(size_t)be32(r); }
    fprintf(stderr, "\n");
    return 0;
}

static void *ret_stub_for(unsigned guest);
static LONG WINAPI crash_filter2(EXCEPTION_POINTERS *ep);
static LONG WINAPI crash_filter(EXCEPTION_POINTERS *ep) {
    if (ep->ExceptionRecord->ExceptionCode == 0xC0000005 && ep->ExceptionRecord->NumberParameters >= 2) {
        unsigned a = (unsigned)ep->ExceptionRecord->ExceptionInformation[1];
        if (a >= GUEST_DELTA + PAGED_LO && a < GUEST_DELTA + PAGED_HI && page_in(a - GUEST_DELTA)) return EXCEPTION_CONTINUE_EXECUTION;
    }
    if (ep->ExceptionRecord->ExceptionCode == 0xC0000005 && ep->ExceptionRecord->NumberParameters >= 2 && ep->ExceptionRecord->ExceptionInformation[0] == 8) {
        unsigned a = (unsigned)ep->ExceptionRecord->ExceptionInformation[1];     /* a code pointer a few bytes into a function (the leading instructions are dead): enter the function */
        if (a >= 0x200400u && a < 0x450000u) {
            int lo = 0, hi = port_fn_count - 1, best = -1;
            while (lo <= hi) { int mid = (lo + hi) / 2; if (port_fn_table[mid].guest <= a) { best = mid; lo = mid + 1; } else hi = mid - 1; }
            { void *rs = ret_stub_for(a); if (rs) { ep->ContextRecord->Eip = (DWORD)(size_t)rs; return EXCEPTION_CONTINUE_EXECUTION; } }
            if (best >= 0 && a - port_fn_table[best].guest <= 8) { fprintf(stderr, "code pointer %08X -> function %08X\n", a, port_fn_table[best].guest); ep->ContextRecord->Eip = (DWORD)(size_t)port_fn_table[best].host; return EXCEPTION_CONTINUE_EXECUTION; }
        }
    }
    return crash_filter2(ep);
}
static LONG WINAPI crash_filter2(EXCEPTION_POINTERS *ep) {
    static volatile LONG once;
    if (ep->ExceptionRecord->ExceptionCode != 0xC0000005 || InterlockedExchange(&once, 1)) return EXCEPTION_CONTINUE_SEARCH;
    fprintf(stderr, "CRASH: exception 0x%08lX at %p", ep->ExceptionRecord->ExceptionCode, ep->ExceptionRecord->ExceptionAddress);
    if (ep->ExceptionRecord->NumberParameters >= 2) fprintf(stderr, " (access %lu at 0x%08lX)", (unsigned long)ep->ExceptionRecord->ExceptionInformation[0], (unsigned long)ep->ExceptionRecord->ExceptionInformation[1]);
    fprintf(stderr, " rva=%08lX esp=%08lX eax=%08lX\n", (unsigned long)((size_t)ep->ExceptionRecord->ExceptionAddress - (size_t)GetModuleHandleA(NULL)), ep->ContextRecord->Esp, ep->ContextRecord->Eax);
    {   /* poor man's backtrace: stack words that look like return addresses into this module */
        size_t base = (size_t)GetModuleHandleA(NULL); unsigned long *sp = (unsigned long *)ep->ContextRecord->Esp; int n = 0;
        fprintf(stderr, "  stack rvas:");
        for (int i = 0; i < 512 && n < 14; i++) {
            __try { unsigned long v = sp[i]; if (v > base && v < base + 0x4000000) { fprintf(stderr, " %lX", (unsigned long)(v - base)); n++; } }
            __except (EXCEPTION_EXECUTE_HANDLER) { break; }
        }
        fprintf(stderr, "\n");
    }
    dump_trace(80);
    fprintf(stderr, "  D_801536B0=%08X D_801536EC=%08X D_8016E000 first=%08X\n",
            *(unsigned *)0x801536B0, *(unsigned *)0x801536EC, *(unsigned *)0x8016E000);
    fflush(stderr);
    return EXCEPTION_CONTINUE_SEARCH;
}

static LONG WINAPI crash_final(EXCEPTION_POINTERS *ep) {      /* nothing handled it: log and die (no error-reporting dialog) */
    crash_filter(ep); fflush(stderr);
    TerminateProcess(GetCurrentProcess(), 3);
    return EXCEPTION_EXECUTE_HANDLER;
}

static int g_ranges_ok;
/* Called first thing in WinMain: claim the fixed host ranges (KSEG0 RAM, and the translated low guest space) before anything else
   allocates; when one is busy start again (a new process gets a new layout). */
void port_early_init(void) {
    int ok = 1; DWORD e1 = 0, e2 = 0, e3 = 0;
    if (!VirtualAlloc((void *)(size_t)0x80000000u, 0x00800000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE)) { ok = 0; e1 = GetLastError(); }
    if (!VirtualAlloc((void *)(size_t)(GUEST_DELTA + 0x00400000u), 0x00080000u, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE)) { ok = 0; e2 = GetLastError(); }
    if (!VirtualAlloc((void *)(size_t)(GUEST_DELTA + PAGED_LO), PAGED_HI - PAGED_LO, MEM_RESERVE, PAGE_READWRITE)) { ok = 0; e3 = GetLastError(); }
    if (!ok) { FILE *f = fopen("port_early.txt", "a"); if (f) { fprintf(f, "reserve errors: ram=%lu overlay=%lu paged=%lu\n", e1, e2, e3); fclose(f); } }
    g_ranges_ok = ok;
    {   /* guest code addresses (0x200400-0x44F000) get executable jump stubs to the host functions: code pointers that are created
           or loaded at run time (object tables inside RNC packs, constants in drafts) can then be called as they are */
        MEMORY_BASIC_INFORMATION mi; unsigned a = 0x200000u; int n = 0, i;
        while (a < 0x450000u && VirtualQuery((void *)(size_t)a, &mi, sizeof mi)) {
            unsigned base = (unsigned)(size_t)mi.BaseAddress, end = base + (unsigned)mi.RegionSize;
            if (mi.State == MEM_FREE) {
                unsigned lo = a > base ? a : base, hi = end < 0x450000u ? end : 0x450000u;
                lo = (lo + 0xFFFFu) & ~0xFFFFu;
                if (hi > lo && !VirtualAlloc((void *)(size_t)lo, hi - lo, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE)) { FILE *f = fopen("port_early.txt", "a"); if (f) { fprintf(f, "code range alloc failed [%08X+%X] err=%lu" "\n", lo, hi - lo, GetLastError()); fclose(f); } }
            } else { FILE *f = fopen("port_early.txt", "a"); if (f) { fprintf(f, "code range busy [%08X+%X] st=%lX ty=%lX" "\n", base, (unsigned)mi.RegionSize, mi.State, mi.Type); fclose(f); }
            }
            if (end <= a) break;
            a = end;
        }
        for (i = 0; i < port_fn_count; i++) {
            unsigned g = port_fn_table[i].guest; unsigned char *p = (unsigned char *)(size_t)g;
            if (g >= 0x200000u && g < 0x450000u && !IsBadWritePtr(p, 8)) { p[0] = 0xE9; *(int *)(p + 1) = (int)((size_t)port_fn_table[i].host - (size_t)(g + 5)); n++; }
        }
        {   /* code pointers a few bytes into a function (its first instructions are dead): {alias, function}; the function's own stub shrinks to a short jump onto the alias stub */
            static const unsigned alias[][2] = { { 0x42F130u, 0x42F12Cu }, { 0x419B90u, 0x419B8Cu }, { 0x4396C0u, 0x4396BCu } };
            for (i = 0; i < (int)(sizeof alias / sizeof alias[0]); i++) {
                unsigned char *pa = (unsigned char *)(size_t)alias[i][0], *pb = (unsigned char *)(size_t)alias[i][1]; int k;
                for (k = 0; k < port_fn_count; k++) if (port_fn_table[k].guest == alias[i][1]) {
                    pa[0] = 0xE9; *(int *)(pa + 1) = (int)((size_t)port_fn_table[k].host - (size_t)(alias[i][0] + 5));
                    pb[0] = 0xEB; pb[1] = (unsigned char)(alias[i][0] - alias[i][1] - 2); break; }
            }
        }
        { FILE *f = fopen("port_early.txt", "a"); if (f) { fprintf(f, "code stubs installed: %d of %d" "\n", n, port_fn_count); fclose(f); } }
    }
    {   /* the guest's low space [0x200000,0x2000000) is accessed at +GUEST_DELTA; keep host allocations (thread stacks, heap) out of
           the original range, otherwise a host pointer there would be translated by mistake */
        MEMORY_BASIC_INFORMATION mi; unsigned a = 0x200000u;
        while (a < 0x2000000u && VirtualQuery((void *)(size_t)a, &mi, sizeof mi)) {
            unsigned base = (unsigned)(size_t)mi.BaseAddress, end = base + (unsigned)mi.RegionSize;
            if (mi.State == MEM_FREE) {
                unsigned lo = a > base ? a : base, hi = end < 0x2000000u ? end : 0x2000000u;
                if (hi > lo) VirtualAlloc((void *)(size_t)lo, hi - lo, MEM_RESERVE, PAGE_NOACCESS);
            }
            if (end <= a) break;
            a = end;
        }
    }
    if (!ok) {
        static const struct { unsigned lo, size; } rr[] = { { 0x80000000u, 0x800000u }, { GUEST_DELTA + 0x400000u, 0x80000u }, { GUEST_DELTA + PAGED_LO, PAGED_HI - PAGED_LO } };
        FILE *f = fopen("port_early.txt", "a"); MEMORY_BASIC_INFORMATION mi;
        if (f) {
            for (int i = 0; i < 3; i++) {
                for (unsigned a = rr[i].lo; a < rr[i].lo + rr[i].size; ) {
                    if (!VirtualQuery((void *)(size_t)a, &mi, sizeof mi)) break;
                    if (mi.State != MEM_FREE) fprintf(f, "range %d busy: [%08X+%X st=%lX ty=%lX]\n", i, (unsigned)(size_t)mi.BaseAddress, (unsigned)mi.RegionSize, mi.State, mi.Type);
                    a = (unsigned)(size_t)mi.BaseAddress + (unsigned)mi.RegionSize; if (!a) break;
                }
            }
            fclose(f);
        }
    }
    if (!ok) {
        char n[16]; DWORD k = GetEnvironmentVariableA("PORT_RETRY", n, sizeof n) ? (DWORD)atoi(n) : 0;
        if (k < 100) {
            char cmd[MAX_PATH + 8], num[16]; STARTUPINFOA si; PROCESS_INFORMATION pi; memset(&si, 0, sizeof si); si.cb = sizeof si;
            sprintf(num, "%lu", k + 1); SetEnvironmentVariableA("PORT_RETRY", num);
            GetModuleFileNameA(NULL, cmd, MAX_PATH);
            if (CreateProcessA(cmd, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) ExitProcess(0);
        }
    }
}

void port_game_init(void) {
    freopen("port_log.txt", "w", stderr); setvbuf(stderr, NULL, _IONBF, 0);
    SetUnhandledExceptionFilter(crash_final); AddVectoredExceptionHandler(1, crash_filter);
    if (!g_ranges_ok) { fprintf(stderr, "could not reserve the game's address ranges (after retries)\n"); return; }
    fprintf(stderr, "guest address ranges reserved (attempt %s)\n", getenv("PORT_RETRY") ? getenv("PORT_RETRY") : "0");
    if (!load_rom("baserom.us.v11.z64")) { fprintf(stderr, "baserom.us.v11.z64 not found in the working directory\n"); return; }
    load_guest_data(1);
    *(volatile unsigned *)0x80000300 = _byteswap_ulong(1);                           /* osTvType = NTSC */
    *(volatile unsigned *)0x80000318 = _byteswap_ulong(0x800000);                    /* osMemSize */
    CreateThread(NULL, 4 * 1024 * 1024, game_thread, NULL, 0, NULL);
    { char e[8]; if (GetEnvironmentVariableA("TUROK_SAMPLE", e, sizeof e)) CreateThread(NULL, 0, sampler_thread, NULL, 0, NULL); }
}
void port_game_frame(void) { InterlockedIncrement(&g_frames); port_vi_tick(); }
extern volatile long g_gfx_task_ready; extern unsigned char g_gfx_task[];
extern void port_dump_threads(void); extern int g_dbg_startgo, g_dbg_pop;
void port_present_hook(struct ID3D11DeviceContext *ctx) {
    static int frames; (void)ctx;
    if (frames == 3 || frames == 100 || frames == 600) fprintf(stderr, "gamestate D_80146878=%d D_800D2984=%d D_80146D68=%d D_8014ADA0=%d\n", (int)be32((void *)0x80146878), (int)be32((void *)0x800D2984), (int)be32((void *)0x80146D68), (int)be32((void *)0x8014ADA0));
    if (frames == 3 || frames == 100 || frames == 600) fprintf(stderr, "frame %d: D_800D2958=%08X D_800D295C=%08X\n", frames + 1, be32((void *)0x800D2958), be32((void *)0x800D295C));
    if (frames == 3 || frames == 100) fprintf(stderr, "startgo=%d pops=%d\n", g_dbg_startgo, g_dbg_pop);
    if (++frames == 150 || frames == 600) { port_dump_threads(); dump_trace(8000); }
}

/* Custom entry point: install a crash logger before the C runtime starts (crashes during start-up are otherwise silent). */
extern void __cdecl WinMainCRTStartup(void);
static LONG WINAPI early_crash(EXCEPTION_POINTERS *ep) {
    HANDLE h = CreateFileA("port_early.txt", FILE_APPEND_DATA, FILE_SHARE_READ, NULL, OPEN_ALWAYS, 0, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        char b[256]; DWORD n; unsigned long base = (unsigned long)GetModuleHandleA(NULL);
        unsigned long *sp = (unsigned long *)ep->ContextRecord->Esp; int i;
        int l = wsprintfA(b, "EARLY CRASH %08lX rva=%lX acc=%lu addr=%08lX\r\nstack rvas:", ep->ExceptionRecord->ExceptionCode,
            (unsigned long)ep->ExceptionRecord->ExceptionAddress - base, (unsigned long)ep->ExceptionRecord->ExceptionInformation[0], (unsigned long)ep->ExceptionRecord->ExceptionInformation[1]);
        WriteFile(h, b, l, &n, NULL);
        for (i = 0; i < 64; i++) { unsigned long v = sp[i]; if (v > base && v < base + 0x1C2000) { l = wsprintfA(b, " %lX", v - base); WriteFile(h, b, l, &n, NULL); } }
        WriteFile(h, "\r\n", 2, &n, NULL); CloseHandle(h);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}
void __cdecl port_entry(void) { AddVectoredExceptionHandler(1, early_crash); WinMainCRTStartup(); }

void port_dump_state_tables(void);
void port_log_state(void *gp, int st, void *fn) {
    static int n, last = -1;
    if (st != last || (++n % 300) == 0) { fprintf(stderr, "game state: g=%p st=%d fn_rva=%X\n", gp, st, (unsigned)((size_t)fn - (size_t)GetModuleHandleA(NULL))); fflush(stderr); }
    if (st != last) { static int once; if (!once) { once = 1; port_dump_state_tables(); } }
    last = st;
}

void port_bad_memmove(void *d, void *s, int n) { fprintf(stderr, "BAD memmove dst=%p src=%p n=%d\n", d, s, n); dump_trace(30); fflush(stderr); }

void port_dbg_words(const char *what, void *p, int n, int h) { int i; fprintf(stderr, "%s (handle %08X):", what, h); for (i = 0; i < n; i++) fprintf(stderr, " %08X", be32((unsigned char *)p + i * 4)); fprintf(stderr, "\n"); fflush(stderr); }

void port_dump_state_tables(void) { int i; unsigned base = (unsigned)(size_t)GetModuleHandleA(NULL); fprintf(stderr, "state tables (init / update):\n");
    for (i = 0; i < 26; i++) { unsigned a = be32((void *)(0x800D29D8 + i * 12)), b = be32((void *)(0x800D29DC + i * 12)); fprintf(stderr, "  st %d: init=%X update=%X\n", i, a ? a - base : 0, b ? b - base : 0); } fflush(stderr); }

void port_rnc_log(const char *what, const void *src, void *dst, int packed, int unpacked, int produced) { static int n; if (n++ < 40 || what[4] != 0x20) { const unsigned char *s = (const unsigned char *)src; fprintf(stderr, "%s: src=%p [%02X %02X %02X %02X %02X %02X] dst=%p packed=%d unpacked=%d produced=%d\n", what, src, s[0], s[1], s[2], s[3], s[4], s[5], dst, packed, unpacked, produced); fflush(stderr); } }

/* A code pointer that lands on a bare `jr $ra` (the tail of the previous function, used as a "do nothing, return 0" callback). */
static unsigned port_ret0(void) { return 0; }
static void *ret_stub_for(unsigned guest) {
    unsigned off = guest >= 0x400000u ? guest - 0x400000u + 0x16E000u : guest - 0x200000u + 0xC00u;
    if (g_rom && off + 8 <= g_rom_size && be32(g_rom + off) == 0x03E00008u) return (void *)port_ret0;
    return NULL;
}

/* guest code address -> host function (for jalr in statically recompiled code); host pointers pass through */
void *port_resolve(unsigned guest) {
    struct port_fn key; struct port_fn *f; key.guest = guest; key.host = 0;
    f = (struct port_fn *)bsearch(&key, port_fn_table, port_fn_count, sizeof key, cmp_fn);
    if (f) {
        static unsigned seen[512]; static int ns; int k; static int logr = -1;
        if (logr < 0) { char e[4]; logr = GetEnvironmentVariableA("TUROK_LOGRESOLVE", e, sizeof e) ? 1 : 0; }
        if (logr) { for (k = 0; k < ns; k++) if (seen[k] == guest) break; if (k == ns && ns < 512) { seen[ns++] = guest; fprintf(stderr, "resolve %08X\n", guest); } }
        return f->host;
    }
    if (guest >= 0x200400u && guest < 0x450000u) {        /* a code address that is no function entry: log it, enter the function that contains it when it is only a few bytes in */
        int lo = 0, hi = port_fn_count - 1, best = -1;
        while (lo <= hi) { int mid = (lo + hi) / 2; if (port_fn_table[mid].guest <= guest) { best = mid; lo = mid + 1; } else hi = mid - 1; }
        { static unsigned seen[16]; static int ns; int k, dup = 0; for (k = 0; k < ns; k++) if (seen[k] == guest) dup = 1; if (!dup && ns < 16) seen[ns++] = guest; if (dup) goto resolved_quiet; }
        fprintf(stderr, "port_resolve: %08X is not a function entry (previous entry %08X)\n", guest, best >= 0 ? port_fn_table[best].guest : 0); fflush(stderr);
        resolved_quiet:
        { void *rs = ret_stub_for(guest); if (rs) return rs; }
        if (best >= 0 && guest - port_fn_table[best].guest <= 8) return port_fn_table[best].host;
    }
    return (void *)(size_t)guest;
}

/* host stub address of a relocated code pointer -> guest code address (jump tables hold guest label addresses) */
unsigned port_unresolve(unsigned host) {
    int i; for (i = 0; i < port_fn_count; i++) if ((unsigned)(size_t)port_fn_table[i].host == host) return port_fn_table[i].guest;
    return host;
}

void port_dump_trace_pub(int n) { dump_trace(n); }

int port_skip_menu(void) { static int v = -1; if (v < 0) { char e[4]; v = GetEnvironmentVariableA("TUROK_SKIPMENU", e, sizeof e) ? 1 : 0; } return v; }

void port_bt(void) { unsigned *sp = (unsigned *)&sp; int i, k = 0; size_t b = (size_t)GetModuleHandleA(NULL); fprintf(stderr, "  bt:"); for (i = 0; i < 400 && k < 14; i++) if (sp[i] > b + 0x1000 && sp[i] < b + 0x600000 && *(unsigned char *)(size_t)(sp[i] - 5) == 0xE8) { fprintf(stderr, " %zX", sp[i] - b); k++; } fprintf(stderr, "\n"); }

/* TUROK_WATCH=80153C18: log changes of a guest word (polled every tick) with the recent call trace */
void port_watch_tick(void) {
    static unsigned addr, last; static int init;
    if (!init) { char e[16]; init = 1; if (GetEnvironmentVariableA("TUROK_WATCH", e, sizeof e)) addr = (unsigned)strtoul(e, NULL, 16); }
    if (!addr) return;
    { unsigned v = *(volatile unsigned *)(size_t)addr; if (v != last) { fprintf(stderr, "WATCH %08X: %08X -> %08X (raw bytes %02X %02X %02X %02X)\n", addr, last, v, ((unsigned char *)(size_t)addr)[0], ((unsigned char *)(size_t)addr)[1], ((unsigned char *)(size_t)addr)[2], ((unsigned char *)(size_t)addr)[3]); last = v; dump_trace(14); fflush(stderr); } }
}

/* TUROK_TRACE=func_0044E454,func_00254B2C  logs the arguments of those statically recompiled functions on every call */
static char g_trace_names[512]; static int g_trace_init;
void port_rc_enter(const char *name, unsigned a0, unsigned a1, unsigned a2, unsigned a3) {
    if (!g_trace_init) { g_trace_init = 1; if (!GetEnvironmentVariableA("TUROK_TRACE", g_trace_names, sizeof g_trace_names)) g_trace_names[0] = 0; }
    if (g_trace_names[0] && strstr(g_trace_names, name) && (!strcmp(name, "func_0044E454") || !strcmp(name, "func_0044D408") || !strcmp(name, "func_0044D024") || !strcmp(name, "func_0044CD58"))) { unsigned p1 = be32((void *)(size_t)a1), p2 = (p1 >= 0x80000000u && p1 < 0x80800000u) ? be32((void *)(size_t)p1) : 0; fprintf(stderr, "chain: *a1=%08X **a1=%08X\n", p1, p2); if (p2 >= 0x80000000u && p2 < 0x80800000u) { int i; for (i = 0; i < 24; i++) fprintf(stderr, " %08X", be32((unsigned char *)(size_t)p2 + i * 4)); fprintf(stderr, "\n"); } }
    if (g_trace_names[0] && strstr(g_trace_names, name)) { fprintf(stderr, "call %s(%08X, %08X, %08X, %08X)\n", name, a0, a1, a2, a3); fflush(stderr); }
    if (g_trace_names[0] && strstr(g_trace_names, name) && strstr(g_trace_names, "dump") && a0 >= 0x80000000u && a0 < 0x80800000u) { static int nd; int k; if (nd++ < 3) { fprintf(stderr, "  obj %08X:", a0); for (k = 0; k < 40; k++) fprintf(stderr, " %08X", be32((void *)(size_t)(a0 + k * 4))); fprintf(stderr, "\n"); } }
    if (g_trace_names[0] && strstr(g_trace_names, name) && strstr(g_trace_names, "bt")) { unsigned *sp = (unsigned *)&name; int i, k = 0; size_t b = (size_t)GetModuleHandleA(NULL); fprintf(stderr, "  bt:"); for (i = 0; i < 400 && k < 24; i++) if (sp[i] > b + 0x1000 && sp[i] < b + 0x600000 && *(unsigned char *)(size_t)(sp[i] - 5) == 0xE8) { fprintf(stderr, " %zX", sp[i] - b); k++; } fprintf(stderr, "\n"); }
}

/* the guest FPU register file shared by all statically recompiled code (saved/restored per thread by the OS shim) */
float g_fpr[32];

#include "difftest_driver.inc"
