#include "b11_types.h"

extern s32 D_800D297C;
s32 func_00278530(s32 a, s32 b, void *c, void *d, s32 e, ObjM *f);
void func_00253E04(s32 a, s32 **b, s32 c);

void func_0024F8CC(ObjM *a, s32 **b) {
    s32 x = **b;
    void *c = &a->unk17C;
    s32 r = func_00278530(x, *(s32 *)a->unk60, c, &a->mtx[D_800D297C], 0, a);
    func_00253E04(0, b, r);
}