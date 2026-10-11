#ifndef S901_TYPES_H
#define S901_TYPES_H
#include "common.h"
#include "p4_types.h"

/* round 9 worker s901: types for func_00269A80 (material / texture state setup that emits the RDP display list words) */

/* header block of a texture, returned through S9Info.hdr by func_00296F7C */
typedef struct S9Hdr {
    /* 0x0 */ u8 pad0;
    /* 0x1 */ u8 unk1;   /* frame divisor (D_800D2980 / unk1 = frame number) */
    /* 0x2 */ u8 unk2;   /* log2 width - 6 */
    /* 0x3 */ u8 unk3;   /* log2 height - 6 */
    /* 0x4 */ u8 unk4;   /* prim lod fraction (FA command low byte of w0 >> 8) */
    /* 0x5 */ u8 unk5;   /* format class: 4..5 selects the extra FB command */
} S9Hdr;

/* three words filled by func_00296F7C(tex, &info): frame grid size (n0 x n1) and the header */
typedef struct S9Info {
    /* 0x0 */ s32 n0;
    /* 0x4 */ s32 n1;
    /* 0x8 */ S9Hdr *hdr;
} S9Info;

/* draw object / material record passed to func_00269A80 (first arg) */
typedef struct S9Obj {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 pad4[3];
    /* 0x07 */ u8 unk7;        /* last picked random frame key */
    /* 0x08 */ s32 unk8;       /* texture reference (an embedded struct starts here: passed as obj + 8) */
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ u8 unk10;       /* prim colour r,g,b,a */
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 unk14;       /* env colour r,g,b,a */
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u16 unk18;      /* default tile width */
    /* 0x1A */ u16 unk1A;      /* default tile height */
} S9Obj;

/* colour override floats at D_800D15E4..D_800D15F4 (mode word D_800D15E0 precedes them) */
typedef struct S9Col {
    f32 c0;
    f32 c1;
    f32 c2;
    f32 c3;
    f32 c4;
} S9Col;
#endif
