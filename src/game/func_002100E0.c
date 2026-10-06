#include "b03_types.h"

s32 func_00232AAC(ActorB *a);
s32 func_00274544(void);

void func_002100E0(CtlB *c) {
    s32 w;

    if (func_00274544() % 100 < 21) {
        do {
            w = func_00232AAC(c->actor);
        } while (w >= 16);
        c->actor->unk770 = w;
        if (w != c->actor->unk62E) {
            c->unk2E4 = 0;
        }
    }
}
