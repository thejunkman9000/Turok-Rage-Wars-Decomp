#include "o03_types.h"
extern O3Pk *D_800E3590;
extern O3Dl *D_80110634;
extern s32 D_800D15E0;
extern f32 D_800D15E4[];
extern s32 D_800E28D0;
extern s32 D_800E28D4;
s32 func_00439EA8();
void func_004399D0();
s32 func_0041DD30(s32 a0, s32 a1, s32 a2) {
    f32 k;
    O3Dl *g;
    if (a2 == 1 && D_800E3590->fD8 == 3) {
        k = 255.0f;
        D_800D15E0 = 0;
        D_800D15E4[0] = k;
        D_800D15E4[1] = k;
        D_800D15E4[2] = k;
        D_800D15E4[3] = k;
        g = D_80110634++;
        g->w0 = 0xED000000;
        g->w1 = (((s32)((f32)(D_800E28D0 - 1) * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(D_800E28D4 - 1) * 4.0f) & 0xFFF);
        if (func_00439EA8(D_800E3590->sub, &D_80110634, g) != 0) {
            D_800D15E0 = a2;
            D_800D15E4[3] = 210.0f;
            func_004399D0(D_800E3590->sub);
            D_800D15E0 = 0;
            D_800D15E4[3] = k;
        }
    }
    return 0;
}
