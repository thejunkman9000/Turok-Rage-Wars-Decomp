#include "o01_types.h"

extern O01Ctx *D_800E2830;
void *func_0028FD94(void *tree, s32 idx);
O01Vec3 func_00400E50(void *keys, s32 n, f32 t);
void func_00271FD8(f32 *dir, O01Vec3 *b, O01Vec3 *a);
f32 func_0027266C(f32 *dir);
f32 func_00271B18(f32 *dir);

static inline O01Vec3 getA(void) {
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

static inline O01Vec3 getB(void) {
    O01Vec3 t;
    O01Vec3 v;
    O01Node *n;
    if (D_800E2830->unk38 == 0) {
        v.x = 10.0f;
        v.y = 0;
        v.z = 0;
        return v;
    }
    n = func_0028FD94(func_0028FD94(func_0028FD94(D_800E2830->tree, 0), 0), 1);
    t = func_00400E50((u8 *)n + 8, n->unk4, 0.0f);
    return t;
}

O01Vec3 func_00403658(void) {
    O01Vec3 a;
    O01Vec3 b;
    f32 dir[4];
    O01Vec3 res;
    if (D_800E2830->unk38 == 0) {
        res.x = 0;
        res.y = 0;
    } else {
        a = getA();
        b = getB();
        func_00271FD8(dir, &b, &a);
        res.x = -func_0027266C(dir);
        res.y = func_00271B18(dir);
    }
    do {
        res.z = 0;
    } while (0);
    return res;
}
