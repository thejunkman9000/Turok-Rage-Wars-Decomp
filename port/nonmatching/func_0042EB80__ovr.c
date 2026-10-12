/* hand override: arena/game-type setter (src/ovl_a/func_0042EB80.c) with TUROK_ARENA=<index> to pin the arena of every match
   (the custom match picks a random arena, so arena-specific rendering bugs were not reproducible); logs "arena: N type T". */
#include "common.h"
extern s32 D_8015402C;
extern char *getenv(const char *); extern int atoi(const char *); int port_arena_from(void);   /* game_glue.c: k of TUROK_ARENA=n@k (host strings cannot be read from game code) */
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
void func_0042EB80(s32 a, s32 b) {
    s32 *p = &D_8015402C;
    static int pin = -2;
    static int from = 1, calls;                  /* TUROK_ARENA=n@k: pin only from the k-th call on (tests: fail trial 0, CONTINUE into trial n) */
    if (pin == -2) { const char *e = getenv("TUROK_ARENA"); pin = e ? atoi(e) : -1; from = port_arena_from(); }
    calls++;
    if (pin >= 0 && calls >= from) { fprintf(__acrt_iob_func(2), "arena: %d pinned by TUROK_ARENA (game chose %d), type %d\n", pin, b, a); b = pin; }
    else fprintf(__acrt_iob_func(2), "arena: %d type %d\n", b, a);
    *p = b;
    p[-1] = a;
}
