#include "b21_grid.h"

#define ABSF(a) ((f32)(a) < 0.0f ? -(a) : (a))

s32 func_00263174(B21Grid *o, s32 a);

s32 func_00297390(B21Grid *o, s32 x, s32 y, s32 k) {
    s32 t, dx, dy;
    if (!(ABSF(x - o->x) < 9)) {
        return 0;
    }
    if (!(ABSF(y - o->y) < 9)) {
        return 0;
    }
    dx = x - o->x;
    dy = y - o->y + 8;
    t = o->map[8 + dx + dy * 17];
    if (t == -2) {
        return 1;
    }
    if (t == -3) {
        return 0;
    }
    { s32 u = k + 9; o->unk4 = t + u; }
    return func_00263174(o, 1) != 0;
}
