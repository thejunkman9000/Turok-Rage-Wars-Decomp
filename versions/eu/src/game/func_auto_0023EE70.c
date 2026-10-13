#include "b09_types.h"

extern B09Obj2 *D_80103FCC;

typedef struct B09Out {
    /* 0x00 */ s32 w0;
    /* 0x04 */ u8 b4;
    /* 0x05 */ u8 b5;
    /* 0x06 */ u8 b6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ f32 f8;
    /* 0x0C */ f32 fC;
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ f32 f18;
} B09Out;

/* 0x28 byte input records */
typedef struct B09InRec {
    /* 0x00 */ B09Out *dst;
    /* 0x04 */ s32 w4;
    /* 0x08 */ u8 pad8[3];
    /* 0x0B */ u8 bB;
    /* 0x0C */ u8 padC[3];
    /* 0x0F */ u8 bF;
    /* 0x10 */ u8 pad10[3];
    /* 0x13 */ u8 b13;
    /* 0x14 */ f32 f14;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 f1C;
    /* 0x20 */ f32 f20;
    /* 0x24 */ f32 f24;
} B09InRec;

void func_auto_0023EE70(B09InRec *r) {
    while (r->dst != NULL) {
        B09Out *o = r->dst;
        D_80103FCC->unk0 = 0;
        D_80103FCC->unk14 = -1;
        D_80103FCC->unk88 = 0;
        D_80103FCC->unk9C = 0;
        D_80103FCC->unkB0 = 0;
        D_80103FCC->unkB4 = 0;
        D_80103FCC->unkC4 = 0;
        o->w0 = r->w4;
        o->b4 = r->bB;
        o->b5 = r->bF;
        o->b6 = r->b13;
        o->f8 = r->f14;
        o->fC = r->f18;
        o->f10 = r->f1C;
        o->f14 = r->f20;
        o->f18 = r->f24;
        r++;
    }
}
