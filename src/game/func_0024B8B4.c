#include "b11_types.h"

void func_0024B8B4(Obj *a) {
    s32 t = a->unkB4;
    a->unkB4 = 0;
    a->unkBC = 0;
    a->unkC0 = 0;
    a->flags &= ~0x200;
    a->unkB8 = t;
}
