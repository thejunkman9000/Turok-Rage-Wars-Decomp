/* Effect pool (world object, free list at +0x5F00, active list at +0x5F14, state word at +0x5F24):
   takes the head of the free list, moves it to the active list, remembers the caller's reference counter
   in the effect (+0x2F0) and bumps it.  Allowed when the debug flag D_8013B290 is set or the state is < 3.
   Hidden inside pad_063C18 (follows func_00262EA8, same object).  Upstream: func_80262FF8_de. */
#include "s1008_types.h"

extern s32 D_8013B290;
void func_00255E78(void *list, void *node);
void func_00255C58(void *list, void *node);

void *func_00263018(S1008Pool *w, s32 *counter) {
    S1008Eff *e;
    if (D_8013B290 != 0 || w->state < 3) {
        e = w->freeHead;
        if (e != NULL) {
            func_00255E78(&w->freeHead, e);
            func_00255C58(&w->activeHead, e);
            e->counter = counter;
            if (counter != NULL) {
                *counter += 1;
            }
        }
        return e;
    }
    return NULL;
}
