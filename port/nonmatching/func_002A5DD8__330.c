#include "b23_types.h"

extern s32 D_800D15E0;
extern f32 D_800D15E4;
extern f32 D_800D15E8;
extern f32 D_800D15EC;
extern f32 D_800D15F0;
extern f32 D_800D15F4;
extern f32 D_800CAFF4;
extern f32 D_800CAFF8;
extern f32 D_800CAFFC;
extern f32 D_800CB000;
extern f32 D_800CB004;
extern f32 D_800CB008;
extern f32 D_800CB00C;
extern f32 D_800CB010;
extern f32 D_800CB014;

void func_002A5DD8(void) {
    f32 lo;

    lo = 0.0f;
    if (D_800D15E4 < lo || (lo = D_800CAFF4, lo < D_800D15E4)) {
        D_800D15E4 = lo;
    }
    lo = 0.0f;
    if (D_800D15E8 < lo || (lo = D_800CAFF8, lo < D_800D15E8)) {
        D_800D15E8 = lo;
    }
    lo = 0.0f;
    if (D_800D15EC < lo || (lo = D_800CAFFC, lo < D_800D15EC)) {
        D_800D15EC = lo;
    }
    lo = 0.0f;
    if (D_800D15F0 < lo || (lo = D_800CB000, lo < D_800D15F0)) {
        D_800D15F0 = lo;
    }
    lo = 0.0f;
    if (D_800D15F4 < lo || (lo = D_800CB004, lo < D_800D15F4)) {
        D_800D15F4 = lo;
    }
    if (D_800D15F4 == D_800CB008) {
        if (D_800D15F0 == 0.0f) {
            D_800D15E0 = 0;
            return;
        }
        if (D_800D15F4 != D_800CB00C && D_800D15F0 == 0.0f) {
            D_800D15E0 = 1;
            D_800D15F0 = D_800D15F4;
            return;
        }
    } else {
        if (D_800D15F0 == 0.0f) {
            D_800D15E0 = 1;
            D_800D15F0 = D_800D15F4;
            return;
        }
    }
    if (D_800D15F4 == D_800CB010) {
        if (D_800D15F0 != 0.0f) {
            D_800D15E0 = 3;
            return;
        }
        if (D_800D15F4 != D_800CB014 && D_800D15F0 != 0.0f) {
            D_800D15E0 = 6;
        }
    } else {
        if (D_800D15F0 != 0.0f) {
            D_800D15E0 = 6;
        }
    }
}
