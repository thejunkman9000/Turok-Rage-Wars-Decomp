#include "common.h"

extern f32 D_800C70C8;
extern f32 D_800C70CC;
extern f32 D_800C70D0;
extern f32 D_800C70D4;
extern f32 D_800C70D8;
extern f32 D_800C70DC;
extern f32 D_800C70E0;
extern f32 D_800C70E4;

s32 func_00210EFC(f32 a) {
    f32 v;
    f32 new_var;

    v = a + D_800C70C8;
    if (D_800C70CC <= v) {
        do {
            v -= D_800C70CC;
        } while (D_800C70CC <= v);
    }
    if (v < 0.0f) {
        new_var = 0.0f;
        do {
            v += D_800C70D0;
        } while (v < new_var);
    }
    if (D_800C70D4 < v) {
        v = D_800C70D4;
    }
    if (v < (new_var = D_800C70D8)) {
        v = new_var;
    }
    v = v * D_800C70DC;
    v = v * D_800C70E0;
    new_var = 0.0f;
    if (v < new_var) {
        v = new_var;
    }
    if (D_800C70E0 <= v) {
        v = D_800C70E4;
    }
    return (s32)v;
}
