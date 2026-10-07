/* Glue between the platform loop (win32_main.cpp) and the game code.
   Milestone 3: reserve guest memory at the original addresses, load the ROM's data, run the game's main thread. */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <intrin.h>

struct ID3D11DeviceContext;

static unsigned char *g_rom; static unsigned g_rom_size;
static volatile LONG g_frames;

unsigned char *port_rom(unsigned *size) { if (size) *size = g_rom_size; return g_rom; }
extern void port_vi_tick(void);

void port_unimpl(const char *name) {
    static char seen[8192][48]; static int n;
    for (int i = 0; i < n; i++) if (!strcmp(seen[i], name)) return;     /* log each missing function once */
    if (n < 8192) { strncpy(seen[n], name, 47); n++; }
    fprintf(stderr, "UNIMPLEMENTED: %s\n", name); fflush(stderr);
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
        unsigned char *o = (unsigned char *)(size_t)(0x400000u + 0x1BCDA0u - 0x16E000u);
        raw_copy(o, 0x1BCDA0u, 0x1EE000u); relocate_fnptrs(o, 0x1EE000u - 0x1BCDA0u);
    }
}

extern void func_00293518(void);                            /* game boot thread entry: sprintf, FPU setup, then func_00291404(&D_8011FAC0) */

static DWORD WINAPI game_thread(LPVOID p) {
    (void)p;
    fprintf(stderr, "game thread: calling func_00293518\n"); fflush(stderr);
    __try { func_00293518(); }
    __except (fprintf(stderr, "game thread exception 0x%08lX at %p\n", GetExceptionCode(),
                      GetExceptionInformation()->ExceptionRecord->ExceptionAddress), EXCEPTION_EXECUTE_HANDLER) { }
    fprintf(stderr, "game thread ended\n"); fflush(stderr);
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
#define PAGED_LO 0x30000000u      /* guest asset space: the game's page number << 12, moved to a range the host leaves free */
#define PAGED_HI 0x40000000u
static unsigned be32(const void *p) { return _byteswap_ulong(*(const unsigned long *)p); }
static unsigned be16(const void *p) { return _byteswap_ushort(*(const unsigned short *)p); }
static int g_paged_faults;

static int page_in(unsigned addr) {
    unsigned page = (addr - PAGED_LO) >> 12;
    unsigned char *r = (unsigned char *)(size_t)0x80103F88u;           /* region list head (the overlay region comes first) */
    for (int guard = 0; r && guard < 4096; guard++) {
        unsigned base = be16(r + 4), size = be16(r + 6);
        if (page >= base && page < base + size) {
            unsigned rom = (be32(r + 8) & 0x0FFFFFFFu) + ((page - base) << 12);
            void *p = VirtualAlloc((void *)(size_t)(PAGED_LO + (page << 12)), 0x1000, MEM_COMMIT, PAGE_READWRITE);
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

static LONG WINAPI crash_filter2(EXCEPTION_POINTERS *ep);
static LONG WINAPI crash_filter(EXCEPTION_POINTERS *ep) {
    if (ep->ExceptionRecord->ExceptionCode == 0xC0000005 && ep->ExceptionRecord->NumberParameters >= 2) {
        unsigned a = (unsigned)ep->ExceptionRecord->ExceptionInformation[1];
        if (a >= PAGED_LO && a < PAGED_HI && page_in(a)) return EXCEPTION_CONTINUE_EXECUTION;
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

void port_game_init(void) {
    freopen("port_log.txt", "w", stderr); setvbuf(stderr, NULL, _IONBF, 0);
    SetUnhandledExceptionFilter(crash_final); AddVectoredExceptionHandler(1, crash_filter);
    if (!load_rom("baserom.us.v11.z64")) { fprintf(stderr, "baserom.us.v11.z64 not found in the working directory\n"); return; }
    /* The game's addresses are fixed (absolute symbols), so the address ranges it needs must be free in this process.  The
       system places the main thread's stack and heaps at random low addresses; when one of them is in the way, simply start
       again (a new process gets a new layout). */
    int ov = 1;
    if (!reserve(0x80000000u, 0x00800000u, "RAM(KSEG0)")) ov = 0;      /* 8 MB: data, bss, heap, stack */
    if (!reserve(0x00400000u, 0x00080000u, "overlay A")) ov = 0;
    if (!VirtualAlloc((void *)(size_t)PAGED_LO, PAGED_HI - PAGED_LO, MEM_RESERVE, PAGE_READWRITE)) {
        MEMORY_BASIC_INFORMATION mi; int shown = 0;
        fprintf(stderr, "paged asset space reservation FAILED; occupied:");
        for (unsigned a = PAGED_LO; a < PAGED_HI && shown < 8; ) {
            if (!VirtualQuery((void *)(size_t)a, &mi, sizeof mi)) break;
            if (mi.State != MEM_FREE) { fprintf(stderr, " [%08X+%X st=%lX ty=%lX]", (unsigned)(size_t)mi.BaseAddress, (unsigned)mi.RegionSize, mi.State, mi.Type); shown++; }
            a = (unsigned)(size_t)mi.BaseAddress + (unsigned)mi.RegionSize; if (!a) break;
        }
        fprintf(stderr, "\n"); ov = 0;
    }
    if (!reserve(0x00200000u, 0x00200000u, "main/TLB")) ov = 0;
    if (!ov) {
        char n[16]; DWORD k = GetEnvironmentVariableA("PORT_RETRY", n, sizeof n) ? (DWORD)atoi(n) : 0;
        if (k < 40) {
            char cmd[MAX_PATH + 8], num[16]; STARTUPINFOA si = { sizeof si }; PROCESS_INFORMATION pi;
            sprintf(num, "%lu", k + 1); SetEnvironmentVariableA("PORT_RETRY", num);
            GetModuleFileNameA(NULL, cmd, MAX_PATH);
            if (CreateProcessA(cmd, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) { fprintf(stderr, "address range busy, relaunching (%lu)\n", k + 1); fflush(stderr); ExitProcess(0); }
        }
        fprintf(stderr, "could not reserve the game's address ranges\n"); return;
    }
    load_guest_data(ov);
    *(volatile unsigned *)0x80000300 = _byteswap_ulong(1);                           /* osTvType = NTSC */
    *(volatile unsigned *)0x80000318 = _byteswap_ulong(0x800000);                    /* osMemSize */
    CreateThread(NULL, 4 * 1024 * 1024, game_thread, NULL, 0, NULL);
}
void port_game_frame(void) { InterlockedIncrement(&g_frames); port_vi_tick(); }
void port_present_hook(struct ID3D11DeviceContext *ctx) { (void)ctx; }
