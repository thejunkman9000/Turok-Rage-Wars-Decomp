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

    v = a + D_800C70C8;
    if (D_800C70CC <= v) {
        do {
            v -= D_800C70CC;
        } while (D_800C70CC <= v);
    }
    if (v < 0.0f) {
        do {
            v += D_800C70D0;
        } while (v < 0.0f);
    }
    if (D_800C70D4 < v) {
        v = D_800C70D4;
    }
    if (v < D_800C70D8) {
        v = D_800C70D8;
    }
    v = v * D_800C70DC * D_800C70E0;
    if (v < 0.0f) {
        v = 0.0f;
    }
    if (D_800C70E0 <= v) {
        v = D_800C70E4;
    }
    return (s32)v;
}
