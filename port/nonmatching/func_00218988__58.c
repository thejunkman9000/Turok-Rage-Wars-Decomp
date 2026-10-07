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
    s32 d, ax, v;
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
    if ((f32)(s8)uy < 0.0f) d = -(s8)uy - v;
    else d = (s8)uy - v;
    goto chk;
horiz:
    v = (s8)ux;
    v = ABSF(v);
    if ((f32)(s8)uy < 0.0f) d = v + (s8)uy;
    else d = v - (s8)uy;
chk:
    if (d >= 0x2E) goto dirv;
    if (ux == 0 || uy == 0) {
dirv:
        v = (s8)ux;
        v = ABSF(v);
        if ((f32)(s8)uy < 0.0f) {
            if (!(-(s8)uy < v)) goto ydir;
        } else {
            if (!((s8)uy < v)) goto ydir;
        }
        if ((s8)ux > 0) return 1;
        return 3;
ydir:
        return ((s8)uy < 1) * 2;
    }
    return -1;
}
