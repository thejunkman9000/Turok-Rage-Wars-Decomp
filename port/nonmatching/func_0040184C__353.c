#include "o01_types.h"

typedef struct O01Key8 {
    /* 0x0 */ f32 val;
    /* 0x4 */ f32 time;
} O01Key8;
extern O01Ctx *D_800E2830;
extern f32 D_800E0B64;
extern f32 D_800E0B68;
extern f32 D_800E0B6C;
void *func_0028FD94(void *tree, s32 idx);

f32 func_0040184C(f32 t) {
    O01Node *n = func_0028FD94(D_800E2830->tree, 3);
    O01Key8 *keys = (O01Key8 *)((u8 *)n + 8);
    s32 cnt = n->unk4;
    f32 u;
    f32 s;
    s32 i;
    for (i = 0; i < cnt; i++) {
    }
    if (cnt == 0) {
        return D_800E0B64;
    }
    if (t <= keys[0].time) {
        return keys[0].val;
    }
    if (keys[cnt - 1].time <= t) {
        return keys[cnt - 1].val;
    }
    if (keys[0].time < t) {
        keys++;
        while (keys->time < t) {
            keys++;
        }
    }
    u = (t - keys[-1].time) / (keys->time - keys[-1].time);
    s = u * (u * D_800E0B68) - (u + u) * u * u;
    return keys[-1].val * (D_800E0B6C - s) + keys->val * s;
}
