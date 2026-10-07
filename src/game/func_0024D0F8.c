#include "b11_types.h"

s32 func_00278530(s32 a, s32 b, void *c, s32 d, s32 e, Obj *f);
void func_00253E04(s32 a, s32 **b, s32 c);

void func_0024D0F8(Obj *a, s32 **b) {
    s32 x = **b;
    void *c = a->unkE8;
    s32 r = func_00278530(x, 0, c, a->unkB4, 1, a);
    func_00253E04(0, b, r);
}