#include "b21_types.h"

extern s32 D_8010F194[];
extern f32 D_800CA58C;
s32 func_00245804();
s32 func_00264B8C();

void func_00293A04(B21Game *g, s32 a, s32 b) {
    s32 f = D_8010F194[0] & 0x1000;
    s32 old;
    if (g->unk26DB8 == 11 || g->unk26DB8 == 12) {
        f = 0;
    }
    if (f && b != -1) {
        g->unk26DC1 = 2;
        g->unk26DBC = b;
        D_8010F194[0] = 0;
    } else if (func_00245804()) {
        old = g->unk26DB8;
        g->unk26DC1 = 1;
        g->unk26DC4 = 0.0f;
        g->unk26DB8 = 20;
        g->unk26DBC = a;
        g->unk26DB4 = old;
        if (func_00264B8C()) {
            g->unk26DC4 = D_800CA58C;
        }
    }
}
