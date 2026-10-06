#include "b14_types.h"
typedef struct {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ s32 f20;
    /* 0x24 */ s32 f24;
    /* 0x28 */ s32 f28;
    /* 0x2C */ u8 pad2C[0x80];
    /* 0xAC */ s32 fAC;
    /* 0xB0 */ s32 fB0;
    /* 0xB4 */ s32 fB4;
    /* 0xB8 */ s32 fB8;
    /* 0xBC */ s32 fBC;
    /* 0xC0 */ s32 fC0;
    /* 0xC4 */ u8 fC4;
    /* 0xC5 */ u8 fC5;
    /* 0xC6 */ u8 fC6;
    /* 0xC7 */ u8 fC7;
} B14Hist;


void func_002644C8(B14Hist *p) {
p->fC6 = p->fC4;
    p->fC7 = p->fC5;
    p->fAC = p->fB0;
    p->fB0 = p->f18;
    p->fB4 = p->f1C; p->f1C = 0;
    p->fB8 = p->f20; p->f20 = 0;
    p->fBC = p->f24; p->f24 = 0;
    p->fC0 = p->f28; p->f28 = 0;
}
