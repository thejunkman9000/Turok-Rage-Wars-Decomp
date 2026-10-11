/* Effect pool: releases an effect (clears +0x174, drops the reference counter at +0x2F0) and moves it from
   the active list (+0x5F14) back to the free list (+0x5F00).  Counterpart of func_00263018; hidden inside
   pad_063C18 directly behind it.  Upstream: func_80263080_de. */
#include "s1008_types.h"

void func_00255E78(void *list, void *node);
void func_00255CB4(void *list, void *node);

void func_auto_00263020(S1008Pool *w, S1008Eff *e) {
    s32 *counter = e->counter;
    e->f174 = 0;
    if (counter != NULL) {
        *counter -= 1;
    }
    func_00255E78(&w->activeHead, e);
    func_00255CB4(&w->freeHead, e);
}
