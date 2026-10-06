#include "b21_types.h"

extern s32 D_8010F194[];
extern f32 D_800CA588;

s32 func_002938E8(B21Game *g, f32 x, s32 a, s32 b) {
    if (D_8010F194[0] != 0 && b != -1) {
        g->unk26DC1 = 2;
        g->unk26DBC = b;
        D_8010F194[0] = 0;
        return 1;
    }
    if (x * D_800CA588 < g->unk26DB0) {
        g->unk26DC1 = 2;
        g->unk26DBC = a;
        return 1;
    }
    return 0;
}
