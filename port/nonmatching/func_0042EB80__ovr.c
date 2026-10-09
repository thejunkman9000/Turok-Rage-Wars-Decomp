/* hand override: arena/game-type setter (src/ovl_a/func_0042EB80.c) with TUROK_ARENA=<index> to pin the arena of every match
   (the custom match picks a random arena, so arena-specific rendering bugs were not reproducible); logs "arena: N type T". */
#include "common.h"
extern s32 D_8015402C;
extern char *getenv(const char *); extern int atoi(const char *);
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned);
void func_0042EB80(s32 a, s32 b) {
    s32 *p = &D_8015402C;
    static int pin = -2;
    if (pin == -2) { const char *e = getenv("TUROK_ARENA"); pin = e ? atoi(e) : -1; }
    if (pin >= 0) { fprintf(__acrt_iob_func(2), "arena: %d pinned by TUROK_ARENA (game chose %d), type %d\n", pin, b, a); b = pin; }
    else fprintf(__acrt_iob_func(2), "arena: %d type %d\n", b, a);
    *p = b;
    p[-1] = a;
}
