#ifndef S703_TYPES_H
#define S703_TYPES_H
#include "common.h"

/* round 7, workspace s703 types.  Names provisional. */

typedef struct S7Vec3 {
    f32 x, y, z;
} S7Vec3;

/* display list command (F3D) */
typedef struct S7Gfx {
    u32 w0;
    u32 w1;
} S7Gfx;

/* 16-byte RSP vertex */
typedef struct S7Vtx {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ u8 c6;
    /* 0x07 */ u8 c7;
    /* 0x08 */ u8 c8;
    /* 0x09 */ u8 c9;
    /* 0x0A */ s16 wA;
    /* 0x0C */ s16 wC;
    /* 0x0E */ s16 wE;
} S7Vtx;

typedef struct S7LtDef {
    /* 0x00 */ u16 w0;
    /* 0x02 */ u16 w2;
    /* 0x04 */ u8 b4;
    /* 0x05 */ u8 b5;
    /* 0x06 */ u8 b6;
    /* 0x07 */ u8 b7;
} S7LtDef;

/* light list node (list head = D_8013B1A8) */
typedef struct S7Lt {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ S7LtDef *def;
    /* 0x0C */ f32 k;
    /* 0x10 */ s16 x;
    /* 0x12 */ s16 y;
    /* 0x14 */ s16 z;
    /* 0x16 */ s16 on;
} S7Lt;

/* game object / player block as seen by func_00266830 (damage resolution); only the used words, padding explicit */
typedef struct S7Ent S7Ent;
struct S7Ent {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[3];
    /* 0x004 */ u16 kind;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ S7Vec3 pos;
    /* 0x014 */ u8 pad14[0x70 - 0x14];
    /* 0x070 */ f32 h70;
    /* 0x074 */ u8 pad74[0xE4 - 0x74];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x100 - 0xE6];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0x12C - 0x104];
    /* 0x12C */ S7Ent *owner;
    /* 0x130 */ u8 pad130[0x174 - 0x130];
    /* 0x174 */ s32 hp174;
    /* 0x178 */ u8 pad178[0x1D8 - 0x178];
    /* 0x1D8 */ S7Ent *pl;
    /* 0x1DC */ u8 pad1DC[0x45C - 0x1DC];
    /* 0x45C */ s32 hp45C;
    /* 0x460 */ u8 pad460[0x5E4 - 0x460];
    /* 0x5E4 */ s32 hp;
    /* 0x5E8 */ u8 pad5E8[0x62E - 0x5E8];
    /* 0x62E */ s16 state;
    /* 0x630 */ u8 pad630[0x11D8 - 0x630];
    /* 0x11D8 */ f32 f11D8;
    /* 0x11DC */ u8 pad11DC[0x1218 - 0x11DC];
    /* 0x1218 */ s32 w1218;
    /* 0x121C */ u8 pad121C[0x122C - 0x121C];
    /* 0x122C */ u32 flags2;
};

/* 8-byte block passed by value to func_00266830 (u16, u16, s8) */
typedef struct S7Blk {
    /* 0x0 */ u16 a;
    /* 0x2 */ u16 b;
    /* 0x4 */ s8 c;
    /* 0x5 */ u8 pad5[3];
} S7Blk __attribute__((aligned(4)));

#endif
