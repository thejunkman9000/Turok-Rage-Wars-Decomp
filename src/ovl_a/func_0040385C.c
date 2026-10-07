#include "o01_types.h"

extern O01Ctx *D_800E2830;
void *func_0028FD94(void *tree, s32 idx);
O01Vec3 func_00400E50(void *keys, s32 n, f32 t);

O01Vec3 func_0040385C(void) {
    O01Vec3 t;
    O01Vec3 v;
    O01Node *n;
    if (D_800E2830->unk38 == 0) {
        v.x = 0;
        v.y = 0;
        v.z = 0;
        return v;
    }
    n = func_0028FD94(func_0028FD94(func_0028FD94(D_800E2830->tree, 0), 0), 0);
    t = func_00400E50((u8 *)n + 8, n->unk4, 0.0f);
    return t;
}
