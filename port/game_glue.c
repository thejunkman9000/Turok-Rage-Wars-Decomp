/* Glue between the platform loop (win32_main.cpp) and the game code.
   Milestone 3: reserve guest memory at the original addresses, load the ROM's data, run the game's main thread. */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void swap_copy(unsigned char *dst, unsigned rom0, unsigned rom1) {      /* big-endian words -> native (TODO: type-aware) */
    for (unsigned i = rom0; i + 3 < rom1; i += 4) {
        dst[i - rom0 + 0] = g_rom[i + 3]; dst[i - rom0 + 1] = g_rom[i + 2];
        dst[i - rom0 + 2] = g_rom[i + 1]; dst[i - rom0 + 3] = g_rom[i];
    }
}

/* ROM data -> guest RAM.  VA = 0x80000000 + (ROM - 0xC00) for the main image's data; overlay A: VA 0x400000 = ROM 0x16E000. */
static void load_guest_data(int have_overlay) {
    swap_copy((unsigned char *)(size_t)(0x80000000u + 0xC7010u - 0xC00u), 0xC7010u, 0x160000u);
    if (have_overlay) swap_copy((unsigned char *)(size_t)(0x400000u + 0x1BCDA0u - 0x16E000u), 0x1BCDA0u, 0x1EE000u);
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

static LONG WINAPI crash_filter(EXCEPTION_POINTERS *ep) {
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
    if (!reserve(0x80000000u, 0x00800000u, "RAM(KSEG0)")) return;      /* 8 MB: data, bss, heap, stack */
    int ov = reserve(0x00400000u, 0x00080000u, "overlay A") != NULL;
    reserve(0x00200000u, 0x00200000u, "main/TLB");
    load_guest_data(ov);
    *(volatile unsigned *)0x80000300 = 1;                           /* osTvType = NTSC */
    *(volatile unsigned *)0x80000318 = 0x800000;                    /* osMemSize */
    CreateThread(NULL, 4 * 1024 * 1024, game_thread, NULL, 0, NULL);
}
void port_game_frame(void) { InterlockedIncrement(&g_frames); port_vi_tick(); }
void port_present_hook(struct ID3D11DeviceContext *ctx) { (void)ctx; }
