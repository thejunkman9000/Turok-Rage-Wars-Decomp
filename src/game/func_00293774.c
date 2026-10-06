#include "b21_types.h"

extern f32 D_800CA584;
s32 func_00264B8C();

void func_00293774(B21Game *g, s32 a) {
    s32 old = g->unk26DB8;
    g->unk26DC1 = 1;
    g->unk26DC4 = 0.0f;
    g->unk26DB8 = 20;
    g->unk26DBC = a;
    g->unk26DB4 = old;
    if (func_00264B8C()) {
        g->unk26DC4 = D_800CA584;
    }
}
