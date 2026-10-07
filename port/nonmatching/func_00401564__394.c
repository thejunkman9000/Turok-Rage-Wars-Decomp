#include "o01_types.h"

typedef struct O01K5 {
    /* 0x00 */ f32 x, y, z;
    /* 0x0C */ f32 w;
    /* 0x10 */ f32 time;
} O01K5;
extern O01Ctx *D_800E2830;
extern f32 D_800E0B58;
void *func_0028FD94(void *tree, s32 idx);
void func_0027200C(O01Vec3 *dst, O01Vec3 *src, f32 s);
void func_00271FA4(O01Vec3 *dst, O01Vec3 *a, O01Vec3 *b);

O01Vec3 *func_00401564(O01Vec3 *out, f32 t) {
    O01Vec3 res;
    O01Vec3 a;
    O01Vec3 b;
    O01Node *n = func_0028FD94(D_800E2830->tree, 1);
    O01K5 *keys = (O01K5 *)((u8 *)n + 8);
    s32 cnt = n->unk4;
    O01K5 *k;
    f32 u;
    if (cnt == 0) {
        res.x = 0;
        res.y = 0;
        res.z = 0;
    } else if (t <= keys[0].time) {
        res.x = keys[0].x;
        res.y = keys[0].y;
        res.z = keys[0].z;
    } else if (keys[cnt - 1].time <= t) {
        res.x = keys[cnt - 1].x;
        res.y = keys[cnt - 1].y;
        res.z = keys[cnt - 1].z;
    } else {
        n = 0;
        if (keys[0].time < t) {
            keys++;
            while (keys->time < t) {
                keys++;
            }
        }
        u = (t - keys[-1].time) / (keys->time - keys[-1].time);
        a.x = keys[-1].x;
        a.y = keys[-1].y;
        a.z = keys[-1].z;
        b.x = keys->x;
        b.y = keys->y;
        b.z = keys->z;
        func_0027200C(&a, &a, D_800E0B58 - u);
        func_0027200C(&b, &b, u);
        func_00271FA4(&res, &a, &b);
    }
    *out = res;
    return out;
}
