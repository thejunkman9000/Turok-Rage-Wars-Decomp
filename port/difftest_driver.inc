/* Differential test driver (TUROK_DIFFTEST=1): runs every matching-C function and its statically recompiled twin (dt_<name>) on identical
   random arguments and memory, and reports the ones that disagree.  Generated tables: port/native/difftest/dt_table.c.
   Included from game_glue.c (so it sees the guest memory helpers). */
#include <setjmp.h>

unsigned long long dt_call_stub(int idx, int which, const unsigned *a) { (void)idx; (void)which; (void)a; return 0; }
int dt_count_stub = 0;
const char *dt_names_stub[1] = { 0 };
const char *dt_sigs_stub[1] = { 0 };
extern unsigned long long dt_call(int idx, int which, const unsigned *a);
extern int dt_count; extern const char *dt_names[]; extern const char *dt_sigs[];
#pragma comment(linker, "/alternatename:_dt_call=_dt_call_stub")
#pragma comment(linker, "/alternatename:_dt_count=_dt_count_stub")
#pragma comment(linker, "/alternatename:_dt_names=_dt_names_stub")
#pragma comment(linker, "/alternatename:_dt_sigs=_dt_sigs_stub")

static jmp_buf g_dt_jb; static volatile int g_dt_try;
static LONG CALLBACK dt_veh(EXCEPTION_POINTERS *ep) {
    if (g_dt_try && (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION || ep->ExceptionRecord->ExceptionCode == EXCEPTION_INT_DIVIDE_BY_ZERO ||
                     ep->ExceptionRecord->ExceptionCode == EXCEPTION_PRIV_INSTRUCTION || ep->ExceptionRecord->ExceptionCode == EXCEPTION_ILLEGAL_INSTRUCTION)) { g_dt_try = 0; longjmp(g_dt_jb, 1); }
    return EXCEPTION_CONTINUE_SEARCH;
}
#define DT_ARENA 0x80700000u
#define DT_SIZE 0x20000
#define DT_GLOB 0x800C0000u
#define DT_GSIZE 0xB0000
static unsigned dt_rand(void) { static unsigned s = 0x12345678u; s = s * 1664525u + 1013904223u; return s >> 8; }
static float dt_frand(void) { return ((int)(dt_rand() % 4000) - 2000) / 10.0f; }

static volatile long g_dt_call_id; static HANDLE g_dt_thread;
static void dt_abort(void) { g_dt_try = 0; longjmp(g_dt_jb, 2); }
static DWORD WINAPI dt_watchdog(LPVOID unused) {
    long last = -1; int stuck = 0; (void)unused;
    for (;;) {
        Sleep(200);
        if (g_dt_try && g_dt_call_id == last) { if (++stuck >= 5) { CONTEXT c; SuspendThread(g_dt_thread); c.ContextFlags = CONTEXT_CONTROL; GetThreadContext(g_dt_thread, &c); c.Eip = (DWORD)(size_t)dt_abort; SetThreadContext(g_dt_thread, &c); ResumeThread(g_dt_thread); stuck = 0; } }
        else stuck = 0;
        last = g_dt_call_id;
    }
}
static int dt_run_once(int idx, int which, const unsigned *args, unsigned long long *res) {
    int crashed = 0;
    g_dt_try = 1; InterlockedIncrement(&g_dt_call_id);
    if (setjmp(g_dt_jb) == 0) { *res = dt_call(idx * 2 + which, which, args); } else crashed = 1;
    g_dt_try = 0;
    return crashed;
}

static void dt_main(void) {
    unsigned char *arena = (unsigned char *)(size_t)DT_ARENA;
    static unsigned char seed[DT_SIZE], after[DT_SIZE], gseed[DT_GSIZE], gafter[DT_GSIZE];
    unsigned char *glob = (unsigned char *)(size_t)DT_GLOB;
    memcpy(gseed, glob, DT_GSIZE);
    int idx, pass = 0, fail = 0, both_crash = 0, one_crash = 0, total = 0;
    freopen("port_log.txt", "w", stderr);
    AddVectoredExceptionHandler(1, dt_veh);
    fprintf(stderr, "difftest: %d functions" "\n", dt_count);
    for (idx = 0; idx < dt_count; idx++) {
        const char *sig = dt_sigs[idx]; int ok_all = 1, trials_ok = 0, trial;
        for (trial = 0; trial < 12 && ok_all; trial++) {
            unsigned args[8]; unsigned long long r0 = 0, r1 = 0; int c0, c1, k, i;
            for (i = 0; i < DT_SIZE; i++) seed[i] = (unsigned char)(dt_rand() >> 3);
            for (k = 0; k < 8; k++) {
                char ty = (sig && sig[0] && sig[1] == ':' && sig[2 + k]) ? sig[2 + k] : 'i';
                if (ty == 'f') { float f = dt_frand(); memcpy(&args[k], &f, 4); }
                else { unsigned kind = dt_rand() % 6, mode = trial % 3; if (mode == 0) kind = 3; else if (mode == 1) kind = (k == 0) ? 3 : 0; args[k] = kind < 2 ? dt_rand() % 40 : kind < 5 ? DT_ARENA + ((dt_rand() % 0x3000u) & ~7u) + 0x1000 : dt_rand(); }
            }
            memcpy(arena, seed, DT_SIZE); memcpy(glob, gseed, DT_GSIZE); c0 = dt_run_once(idx, 0, args, &r0); memcpy(after, arena, DT_SIZE); memcpy(gafter, glob, DT_GSIZE);
            memcpy(arena, seed, DT_SIZE); memcpy(glob, gseed, DT_GSIZE); c1 = dt_run_once(idx, 1, args, &r1);
            total++;
            if (c0 && c1) { both_crash++; continue; }
            if (c0 != c1) { one_crash++; continue; }          /* undefined behaviour with random pointers: not comparable */
            if (c0 != c1 || (sig[0] != 'v' && sig[0] != 'f' && sig[0] != 'd' && (unsigned)r0 != (unsigned)r1) || memcmp(after, arena, DT_SIZE) || memcmp(gafter, glob, DT_GSIZE)) {
                int differ = -1; for (i = 0; i < DT_SIZE; i++) if (after[i] != arena[i]) { differ = i; break; }
                if (differ < 0) for (i = 0; i < DT_GSIZE; i++) if (gafter[i] != glob[i]) { differ = -1000 - i; break; }
                int is_float = (sig[0] == 'f' || sig[0] == 'd');
                if (is_float && c0 == c1 && differ < 0) { float a, b; unsigned ua = (unsigned)r0, ub = (unsigned)r1; memcpy(&a, &ua, 4); memcpy(&b, &ub, 4);
                    if (a == b || (a - b < 0.001f * (1 + (a < 0 ? -a : a)) && b - a < 0.001f * (1 + (a < 0 ? -a : a)))) { trials_ok++; continue; } }
                fprintf(stderr, "DIFF %s sig=%s crash=%d/%d ref=%08X rc=%08X arena@%d args=%X,%X,%X,%X" "\n", dt_names[idx], sig, c0, c1, (unsigned)r0, (unsigned)r1, differ, args[0], args[1], args[2], args[3]);
                ok_all = 0;
            } else trials_ok++;
        }
        if (ok_all) pass++; else fail++;
    }
    fprintf(stderr, "difftest: %d pass, %d fail (%d trials, %d both crashed)" "\n", pass, fail, total, both_crash); fflush(stderr);
}

static DWORD WINAPI dt_thread(LPVOID unused) { (void)unused; g_dt_thread = OpenThread(THREAD_ALL_ACCESS, FALSE, GetCurrentThreadId()); CreateThread(NULL, 0, dt_watchdog, NULL, 0, NULL); dt_main(); return 0; }
/* run on a fresh thread: the main thread's stack may lie inside the guest's low address range, where pipeline code translates pointers */
void port_difftest(void) { HANDLE h = CreateThread(NULL, 4 * 1024 * 1024, dt_thread, NULL, 0, NULL); WaitForSingleObject(h, INFINITE); }
