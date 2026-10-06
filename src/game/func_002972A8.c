#include "common.h"

typedef struct B21Grid {
    u8 pad0[8];
    s32 x;
    s32 y;
    s32 unk10;
    s32 unk14;
    s16 map[17 * 17];
} B21Grid;

#define ABSF(a) ((f32)(a) < 0.0f ? -(a) : (a))

s32 func_002972A8(B21Grid *o, s32 x, s32 y) {
    s32 t, dx, dy;
    if (!(ABSF(x - o->x) < 9)) {
        return 0;
    }
    if (!(ABSF(y - o->y) < 9)) {
        return 0;
    }
    dx = x - o->x + 8;
    dy = y - o->y + 8;
    t = o->map[dx + dy * 17];
    if (t == -2) {
        return 1;
    }
    if (t == -3) {
        return 0;
    }
    if (t == -1) {
        return 3;
    }
    return 2;
}
