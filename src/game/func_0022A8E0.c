#include "b06_types.h"

s32 func_0022A8E0(ActorGroup *g) {
    Actor *a;
    s32 n = 0;
    for (a = g->head; a != NULL; a = a->next) {
        if (B6F(a, s16, 0x5FE) != 0 && a->unk1450 == 0) {
            n++;
        }
    }
    return n;
}
