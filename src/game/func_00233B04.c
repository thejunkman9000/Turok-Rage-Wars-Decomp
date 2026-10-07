#include "b08_types.h"

typedef struct FadeObj {
    u8 pad0[0x538];
    f32 timer;
    u8 pad53C[8];
    s32 state;
    u8 pad548[2];
    u8 level;
    u8 t1;
    u8 t2;
    u8 t3;
    u8 pad54E[3];
    u8 cur;
} FadeObj;

extern f32 D_800C8198;
extern f32 D_800C819C;
extern f32 D_800C81A0;
extern f32 D_800D2988;

void func_00233B04(FadeObj *o) {
    f32 v;
    f32 lv;

    if (o->state == 1) goto L1;
    if (o->state == 0) goto Lend;
    if (o->state == 2) goto L2;
    if (o->state == 3) goto L3;
    goto Lend;
    L1:
        if ((f32)o->t1 <= o->timer) {
            o->state = 2;
            o->timer = 0.0f;
        } else {
            v = (o->timer / (f32)(o->t1 + 1)) * (f32)o->level;
            o->cur = (u32)v;
            goto Lend;
        }
    L2:
        if (!((f32)o->t2 <= o->timer)) {
            o->cur = o->level;
            goto Lend;
        }
        o->state = 3;
        o->timer = 0.0f;
    L3:
        if ((f32)o->t3 <= o->timer) {
            o->state = 0;
            o->timer = 0.0f;
        } else {
            lv = (f32)o->level;
            v = lv - (o->timer / (f32)(o->t3 + 1)) * lv;
            o->cur = (u32)v;
        }
        goto Lend;
    Lend:
    o->timer = o->timer + D_800D2988;
}

