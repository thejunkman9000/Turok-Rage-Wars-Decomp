#include "o01_types.h"

typedef struct O01Key {
    /* 0x00 */ f32 pad0[3];
    /* 0x0C */ f32 val;
    /* 0x10 */ f32 time;
} O01Key;
extern O01Ctx *D_800E2830;
extern f32 D_800E2848;
extern f32 D_800E0B5C;
extern f32 D_800E0B60;
void *func_0028FD94(void *tree, s32 idx);

f32 func_0040170C(f32 t) {
    O01Node *n = func_0028FD94(D_800E2830->tree, 1);
    O01Key *keys = (O01Key *)((u8 *)n + 8);
    s32 cnt = n->unk4;
    f32 u, w;
    f32 res;
    n = 0;
    if (cnt == 0) {
        res = 0.0f;
    } else if (t <= keys[0].time) {
        res = keys[0].val;
    } else if (keys[cnt - 1].time <= t) {
        res = keys[cnt - 1].val;
    } else {
        if (keys[0].time < t) {
            keys++;
            while (keys->time < t) {
                keys++;
            }
        }
        u = (t - keys[-1].time) / (keys->time - keys[-1].time);
        w = D_800E0B5C - u;
        res = keys[-1].val * w + keys->val * u;
    }
    res *= (D_800E2848 + D_800E2848 + D_800E0B60);
    res -= D_800E2848;
    if (D_800E0B60 < res) {
        res = D_800E0B60;
    }
    if (res < 0.0f) {
        res = 0.0f;
    }
    return res;
}
