
#include "m04_types.h"

typedef struct M04Chaser {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ f32 val;
    /* 0x38 */ u8 pad38[0xC];
    /* 0x44 */ f32 x;
    /* 0x48 */ f32 y;
    /* 0x4C */ f32 z;
    /* 0x50 */ u8 pad50[8];
    /* 0x58 */ f32 dist2;
    /* 0x5C */ f32 prevDist2;
    /* 0x60 */ u8 pad60[0x48];
    /* 0xA8 */ s32 kind;
    /* 0xAC */ u8 padAC[4];
    /* 0xB0 */ M04Ctx *ctx;
    /* 0xB4 */ u8 padB4[0xC];
    /* 0xC0 */ s32 resetFlag;
} M04Chaser;

extern f32 D_800C9040;
extern f32 D_800C9044;
extern f32 D_800C9048;
extern f32 D_800C904C;
extern f32 D_800D0B28;

void func_0025AA4C(M04Chaser *o) {
    M04Tgt *t;
    f32 d2;
    f32 v;
    f32 lim;
    f32 r;
    if (o->kind != 0x8AC) {
        return;
    }
    if (o->resetFlag != 0) {
        o->val = D_800C9040;
    }
    t = o->ctx->tgt;
    d2 = (o->x - t->x) * (o->x - t->x) + (o->y - t->y) * (o->y - t->y) + (o->z - t->z) * (o->z - t->z);
    o->dist2 = d2;
    if (o->prevDist2 < d2) {
        o->val = o->val - D_800D0B28;
        goto clamp;
    }
    if (d2 < o->prevDist2) {
        o->val = o->val + D_800D0B28;
        goto clamp;
    }
    v = o->val;
    if (D_800C9044 < v) {
        r = v - D_800D0B28;
        if (r < D_800C9044) {
            r = D_800C9044;
        }
        o->val = r;
    } else if (v < D_800C9044) {
        r = v + D_800D0B28;
        if (D_800C9044 < r) {
            r = D_800C9044;
        }
        o->val = r;
    }
    return;
clamp:
    v = o->val;
    lim = D_800C9048;
    if (lim < v || (lim = D_800C904C, v < lim)) {
        o->val = lim;
    }
    o->prevDist2 = o->dist2;
}
