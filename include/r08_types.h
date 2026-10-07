#ifndef R08_TYPES_H
#define R08_TYPES_H
#include "common.h"

typedef struct R8Mtx { s32 w[16]; } R8Mtx;

/* ---- 0x2A52E4 family: effect emitters (list at mgr+0x7528) and their parts ---- */
typedef struct R8Info {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
} R8Info;

typedef struct R8Pawn {
    /* 0x000 */ u8 pad0[0x13B];
    /* 0x13B */ u8 unk13B;
    /* 0x13C */ u8 pad13C[0x9D];
    /* 0x1D9 */ u8 unk1D9;
} R8Pawn;

typedef struct R8Part R8Part;
struct R8Part {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ R8Part *next;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ u8 unk10[0x18];
    /* 0x28 */ R8Mtx mtx[2];
    /* 0xA8 */ u8 padA8[8];
    /* 0xB0 */ s32 owner;
};

typedef struct R8Emit R8Emit;
struct R8Emit {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ R8Emit *next;
    /* 0x08 */ R8Info *info;
    /* 0x0C */ u8 padC[0x10];
    /* 0x1C */ R8Pawn *owner;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[0x14];
    /* 0x3C */ u32 flags;
    /* 0x40 */ R8Part *parts;
};
#endif
