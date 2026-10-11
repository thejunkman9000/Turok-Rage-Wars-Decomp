#ifndef S804_TYPES_H
#define S804_TYPES_H
#include "common.h"

/* display list command word pair (pushed through D_80110634) */
typedef struct S8Dl {
    u32 w0;
    u32 w1;
} S8Dl;

typedef struct S8Mtx {
    s32 w[16];
} S8Mtx;

/* emitter definition block (R4Emit->info), byte fields */
typedef struct S8Info {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 pad13[3];
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 unk19;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 pad1E[3];
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
} S8Info;

/* trail strip node: singly linked through +0, view matrices at +0x28 (selected by D_800D297C) */
typedef struct S8Node S8Node;
struct S8Node {
    /* 0x00 */ S8Node *next;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[0x1C];
    /* 0x28 */ S8Mtx mtx[2];
    /* 0xA8 */ f32 unkA8;
};

/* particle-like parts of the emitter: next pointer at +4 */
typedef struct S8Part S8Part;
struct S8Part {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ S8Part *next;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[0x9C];
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
};

typedef struct S8Emit {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ S8Info *info;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 unk14[0x14];
    /* 0x28 */ f32 unk28;
    /* 0x2C */ u8 pad2C[0x10];
    /* 0x3C */ u32 flags;
    /* 0x40 */ S8Part *parts;
    /* 0x44 */ S8Node *nodes;
    /* 0x48 */ u8 pad48[4];
    /* 0x4C */ f32 unk4C;
} S8Emit;

/* parameter block handed to the strip builders (func_002A373C / func_002A3B48) */
typedef struct S8Sp {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 *unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
} S8Sp;

#endif
