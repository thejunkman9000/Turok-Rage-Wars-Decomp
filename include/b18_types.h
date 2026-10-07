#ifndef B18_TYPES_H
#define B18_TYPES_H

#include "common.h"
#include "p1_types.h"

typedef struct B18Vec2 {
    f32 x, y;
} B18Vec2;

typedef struct B18T8 {
    u32 w0;
    u32 w1;
} B18T8;

typedef struct B18Vec4 {
    f32 x, y, z, w;
} B18Vec4;

typedef struct B18Tab {
    /* 0x00 */ B18Vec2 vec[14];
    /* 0x70 */ u16 a70[14];
    /* 0x8C */ u16 a8C[14];
    /* 0xA8 */ u16 aA8[14];
} B18Tab;

typedef struct B18Cfg {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 pad4[0x14];
    /* 0x18 */ B18Tab *tab;
} B18Cfg;

typedef struct B18CfgB {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u8 pad4[0x10];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[0xC];
    /* 0x24 */ struct { u8 pad[0x18]; f32 unk18; } *unk24;
} B18CfgB;

typedef struct B18Fx {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ u8 pad18[4];
    /* 0x01C */ Vec3f unk1C;
    /* 0x028 */ u8 pad28[0x34];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ B18Cfg *cfg;
    /* 0x11C */ u8 pad11C[0x10];
    /* 0x12C */ s32 unk12C;
    /* 0x130 */ s32 unk130;
    /* 0x134 */ s32 unk134;
    /* 0x138 */ u8 pad138[0x52];
    /* 0x18A */ u8 pad18A[2];
    /* 0x18C */ u8 unk18C[0x2D];
    /* 0x1B9 */ s8 unk1B9;
    /* 0x1BA */ s8 unk1BA;
    /* 0x1BB */ u8 pad1BB[9];
    /* 0x1C4 */ s32 unk1C4;
} B18Fx;

#endif
