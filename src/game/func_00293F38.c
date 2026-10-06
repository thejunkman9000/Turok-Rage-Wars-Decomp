#include "b21_types.h"

extern s32 D_800D29C8;
extern s32 D_800D29CC;
extern f32 D_800CA5B0;
u32 func_00265370();
s32 func_002938E8(B21Game *g, f32 x, s32 a, s32 b);

void func_00293F38(B21Game *g) {
    s32 mode;
    u32 r = func_00265370();
    mode = 4;
    if (r > 0x400000) {
        if (D_800D29C8 != 0) {
            mode = 3;
        }
    }
    if (g->unk26DB0 > D_800CA5B0) {
        D_800D29CC = 0;
    }
    if (D_800D29CC != 0) {
        if (func_002938E8(g, 12.0f, mode, -1)) {
            D_800D29CC = 0;
        }
    } else {
        if (func_002938E8(g, 12.0f, mode, mode)) {
            D_800D29CC = 0;
        }
    }
}
