#ifndef M03_TYPES_H
#define M03_TYPES_H
/* m03 round: shared small types (p2_types.h / b*_types.h are included separately by the .c files; p1 and p2 conflict) */
#include "common.h"
typedef struct M03Dl { u32 w0; u32 w1; } M03Dl;
typedef struct M03V3 { f32 x, y, z; } M03V3;
/* 0x70 byte record of a property table (8 box corners, mask at +0x6C) */
typedef struct M03Ent { M03V3 p[8]; u8 pad60[0xC]; u32 mask; } M03Ent;
typedef struct M03Tbl { s32 stride; s32 count; } M03Tbl;
/* particle emitter system (func_0023AFE0): emitter class entry (0x2C bytes, table D_8013B188) */
typedef struct M03EClass {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad2[6];
    /* 0x08 */ f32 f8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ f32 f1C;
    /* 0x20 */ f32 f20;
    /* 0x24 */ u8 pad24[5];
    /* 0x29 */ u8 flags29;
    /* 0x2A */ u8 pad2A[2];
} M03EClass;
/* live emitter node: lists at scene+0x8A0 (free) / +0x8B4 (active) */
typedef struct M03Emit M03Emit;
struct M03Emit {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ M03Emit *next;
    /* 0x008 */ u8 pad8[4];
    /* 0x00C */ M03EClass *cls;
    /* 0x010 */ u16 mask;
    /* 0x012 */ u8 pad12[2];
    /* 0x014 */ u8 mtx[8];
    /* 0x01C */ f32 f1C;
    /* 0x020 */ f32 f20;
    /* 0x024 */ u8 pad24[0x1E4];
    /* 0x208 */ f32 f208;
    /* 0x20C */ f32 f20C;
    /* 0x210 */ f32 f210;
    /* 0x214 */ f32 f214;
    /* 0x218 */ f32 f218;
    /* 0x21C */ f32 f21C;
    /* 0x220 */ f32 f220;
};
typedef struct M03EScene {
    /* 0x000 */ u8 pad0[0x8A0];
    /* 0x8A0 */ M03Emit *freeHead;
    /* 0x8A4 */ u8 pad8A4[0x10];
    /* 0x8B4 */ M03Emit *actHead;
    /* 0x8B8 */ u8 pad8B8[0x10];
    /* 0x8C8 */ u16 used;
} M03EScene;
/* record from func_0028B2D4 (class of an attached thing) */
typedef struct M03ERec {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ f32 f20;
    /* 0x24 */ u8 pad24[0x20];
    /* 0x44 */ u32 flags44;
    /* 0x48 */ u8 pad48[0xE];
    /* 0x56 */ u16 mask;
} M03ERec;
typedef struct M03EOwner {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ s32 f24;
    /* 0x28 */ u8 pad28[0x10];
    /* 0x38 */ s32 w38;
    /* 0x3C */ u8 pad3C[4];
    /* 0x40 */ s32 w40;
    /* 0x44 */ u8 pad44[0x14];
    /* 0x58 */ s32 id;
    /* 0x5C */ u8 pad5C[0xD0];
    /* 0x12C */ f32 f12C;
} M03EOwner;
/* effect actor created by the spawn functions func_0024E980 / 0024F940 / 0024FD4C (0x1C8+ bytes) */
typedef struct M03FxCls {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ f32 f8;
    /* 0x0C */ u8 padC[0x18];
    /* 0x24 */ u32 w24;
} M03FxCls;
typedef struct M03Fx {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[3];
    /* 0x004 */ u16 id;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ M03V3 pos;
    /* 0x014 */ s32 p14;
    /* 0x018 */ M03FxCls *cls;
    /* 0x01C */ s32 w1C;
    /* 0x020 */ u8 pad20[8];
    /* 0x028 */ f32 m28[16];
    /* 0x068 */ f32 m68[16];
    /* 0x0A8 */ s32 hA8;
    /* 0x0AC */ s32 hAC;
    /* 0x0B0 */ s32 hB0;
    /* 0x0B4 */ s32 hB4;
    /* 0x0B8 */ f32 bmin[3];
    /* 0x0C4 */ f32 bmax[3];
    /* 0x0D0 */ s32 wD0;
    /* 0x0D4 */ s32 wD4;
    /* 0x0D8 */ u16 flags;
    /* 0x0DA */ u8 bDA;
    /* 0x0DB */ u8 padDB;
    /* 0x0DC */ s32 wDC;
    /* 0x0E0 */ u8 bE0;
    /* 0x0E1 */ u8 padE1[3];
} M03Fx;
/* collision hit record / event block (0xDC bytes): local in the cylinder-vs-mover functions, copied to mover+0xB0 */
typedef struct M03Quad {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 nv;
    /* 0x18 */ M03V3 v[4];
    /* 0x48 */ M03V3 n;
    /* 0x54 */ void *ref;
    /* 0x58 */ s32 ref58;
    /* 0x5C */ u8 pad5C[0x70];
    /* 0xCC */ f32 t;
    /* 0xD0 */ M03V3 hit;
} M03Quad;
#endif
