#include "m01_types.h"

#define ABS(a) ((a) < 0.0f ? -(a) : (a))

s32 func_00217B3C(M1Actor *actor) {
    M1Pad *p = actor->pad;
    s32 x = p->stickX.s;
    s32 y = p->stickY.s;
    u8 ux = p->stickX.u;
    u8 uy = p->stickY.u;
    s32 ax;
    s32 vx;
    s32 vy;
    s32 t;
    s32 v;

    if (x * x + y * y < 0xE10) {
        return -1;
    }
    ax = ABS(x);
    if (y < 0.0f) {
        v = ax + y;
        if (v < 0.0f) goto V;
        goto H;
    } else {
        v = ax - y;
        if (!(v < 0.0f)) goto H;
    }
V:
    vx = (s8)ux;
    vx = ABS(vx);
    vy = (s8)uy;
    t = ABS(vy) - vx;
    if (t < 46) goto diag;
    goto axis;
H:
    vx = (s8)ux;
    vx = ABS(vx);
    vy = (s8)uy;
    t = vx - ABS(vy);
    if (t < 46) goto diag;
    goto axis;
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
    ax = ABS(x);
    y = (s8)uy;
    if (ABS(y) < ax) {
        v = 2;
        if ((s8)ux <= 0) v = 6;
        return v;
    }
    return ((s8)uy < 1) * 4;
}
