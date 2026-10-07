#include "o01_types.h"

extern O01Ctx *D_800E2830;
void *func_0028FD94(void *tree, s32 idx);
O01Vec3 func_00400E50(void *keys, s32 n, f32 t);

O01Vec3 func_004013BC(f32 t) {
    f32 cumBefore = 0.0f;
    f32 cumAfter = 0.0f;
    s32 cnt = 0;
    u8 *keys = 0;
    s32 seg = 0;
    s32 i = 0;
    O01Node *n;
    while (i < ((O01Node *)func_0028FD94(D_800E2830->tree, 0))->unk0) {
        seg = i;
        n = func_0028FD94(func_0028FD94(func_0028FD94(D_800E2830->tree, 0), seg), 1);
        cnt = n->unk4;
        keys = (u8 *)n + 8;
        cumBefore = cumAfter;
        cumAfter = cumBefore + *(f32 *)(keys + cnt * 36 - 8);
        if (seg == 0) {
            if (t <= cumBefore) {
                break;
            }
        }
        if (seg == ((O01Node *)func_0028FD94(D_800E2830->tree, 0))->unk0 - 1) {
            if (cumAfter < t) {
                break;
            }
        }
        if (cumBefore <= t) {
            if (t <= cumAfter) {
                break;
            }
        }
        i = seg + 1;
    }
    n = func_0028FD94(func_0028FD94(func_0028FD94(D_800E2830->tree, 0), seg), 2);
    if (n->unk4 != 0) {
        t = cumBefore;
    }
    return func_00400E50(keys, cnt, t - cumBefore);
}
