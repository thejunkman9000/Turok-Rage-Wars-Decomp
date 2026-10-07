#include "b04_types.h"
typedef struct { u8 pad0[0xC6]; u8 x; u8 y; } B04Stk;
typedef struct { u8 pad0[0x698]; B04Stk *stk; } B04Pl3;
#define ABSF(v) ((v) < 0.0f ? -(v) : (v))
s32 func_00218988(B04Pl3 *p) {
    B04Stk *s = p->stk;
    s32 x = (s8)s->x;
    s32 y = (s8)s->y;
    u8 ux = s->x;
    u8 uy = s->y;
    s32 d, ax, v, w, r;
    if (x * x + y * y < 0xE10)
        return -1;
    ax = ABSF(x);
    if ((f32)y < 0.0f) {
        d = ax + y;
        if ((f32)d < 0.0f) goto vert;
        goto horiz;
    } else {
        d = ax - y;
        if (!((f32)d < 0.0f)) goto horiz;
    }
vert:
    v = (s8)ux;
    v = ABSF(v);
    w = (s8)uy;
    if (w < 0.0f) d = -w - v;
    else d = w - v;
    goto T;
horiz:
    v = (s8)ux;
    v = ABSF(v);
    w = (s8)uy;
    if (w < 0.0f) {
        d = v - -w;
T:
        if (d < 0x2E) goto small;
        goto dirv;
    }
    d = v - w;
    if (d >= 0x2E) goto dirv;
small:
    if (ux == 0 || uy == 0) {
dirv:
        v = (s8)ux;
        v = ABSF(v);
        w = (s8)uy;
        if (ABSF(w) < v) {
            r = 3;
            if ((s8)ux > 0) r = 1;
            return r;
        }
        return ((s8)uy < 1) * 2;
    }
    return -1;
}
