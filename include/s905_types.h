#ifndef S905_TYPES_H
#define S905_TYPES_H
#include "types.h"
#include "gfx.h"

/* libultra Vp layout */
typedef struct S9Vp {
    s16 vscale[4];
    s16 vtrans[4];
} S9Vp;

/* func_00235AD0: per-view viewport / scissor / fog setup object (the Racer of the upstream project) */
typedef struct S9View {
    /* 0x000 */ u8 pad0[0xC];
    /* 0x00C */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x68 - 0x14];
    /* 0x068 */ u16 unk68;
    /* 0x06A */ u8 pad6A[0x110 - 0x6A];
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ u8 pad118[8];
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[0x29C - 0x124];
    /* 0x29C */ f32 width;
    /* 0x2A0 */ f32 height;
    /* 0x2A4 */ f32 x;
    /* 0x2A8 */ f32 y;
    /* 0x2AC */ u8 pad2AC[4];
    /* 0x2B0 */ S9Vp vp[2];
    /* 0x2D0 */ u8 pad2D0[0x380 - 0x2D0];
    /* 0x380 */ u8 mtx[2][64];
    /* 0x400 */ u8 lookat[2][32];
    /* 0x440 */ u8 pad440[0x520 - 0x440];
    /* 0x520 */ u8 col[3];
    /* 0x523 */ u8 pad523[0x53E - 0x523];
    /* 0x53E */ u16 unk53E;
    /* 0x540 */ u8 pad540[0x17B0 - 0x540];
    /* 0x17B0 */ s32 unk17B0;
} S9View;

#endif
