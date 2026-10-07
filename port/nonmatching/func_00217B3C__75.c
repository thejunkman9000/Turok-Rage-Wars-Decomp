#include "m01_types.h"
#define ABS(a) ((a) < 0.0f ? -(a) : (a))
s32 func_00217B3C(M1Actor *actor) {
    M1Pad *p = actor->pad;
    s32 x = p->stickX.s;
    s32 y = p->stickY.s;
    u8 ux = p->stickX.u;
    u8 uy = p->stickY.u;
    s32 v;
    s32 vx;
    s32 vy;

    if (y * y + x * x < 0xE10) {
        return -1;
    }
    v = ABS(x);
    if (y < 0.0f) {
        v = v + y;
        if (v < 0.0f) goto V;
        goto H;
    } else {
        v = v - y;
        if (!(v < 0.0f)) goto H;
    }
V:
    vx = (s8)ux;
    vx = ABS(vx);
    vy = (s8)uy;
    v = ABS(vy) - vx;
    goto T;
H:
    vx = (s8)ux;
    vx = ABS(vx);
    vy = (s8)uy;
    if (vy < 0.0f) {
        v = vx - -vy;
T:
        if (v < 46) goto diag;
        goto axis;
    }
    v = vx - vy;
    if (v >= 46) goto axis;
diag:
    x = (s8)ux;
    if (x != 0) {
        y = (s8)uy;
        if (y != 0) {
            if (x * y > 0) {
                if (x > 0) return 1;
                return 5;
            }
            v = 3;
            if (y > 0) v = 7;
            return v;
        }
    }
axis:
    x = (s8)ux;
    vx = ABS(x);
    y = (s8)uy;
    if (ABS(y) < vx) {
        v = 2;
        if ((s8)ux <= 0) v = 6;
        return v;
    }
    return ((s8)uy < 1) * 4;
}
