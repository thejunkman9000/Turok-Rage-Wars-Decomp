#include "b21_grid.h"

#define ABSF(a) ((f32)(a) < 0.0f ? -(a) : (a))

s32 func_00263174(B21Grid *o, s32 a);

void func_00297474(B21Grid *o, s32 x, s32 y) {
    s32 t, dx, dy;
    if (!(ABSF(x - o->x) < 9)) {
        return;
    }
    if (!(ABSF(y - o->y) < 9)) {
        return;
    }
    dx = x - o->x;
    dy = y - o->y + 8;
    t = o->map[8 + dx + dy * 17];
    if (t == -2) {
        o->unk10 = 1;
    } else if (t == -3) {
        o->unk10 = 0;
    } else if (t == -1) {
        o->unk10 = 3;
    } else {
        o->unk10 = 2;
        o->unk4 = t;
        o->unk14 = func_00263174(o, 9);
    }
}
