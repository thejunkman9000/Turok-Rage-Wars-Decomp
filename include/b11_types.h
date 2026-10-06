#ifndef B11_TYPES_H
#define B11_TYPES_H

#include "common.h"
#include "p1_types.h"

/* class constants block of Obj.def (ActorDef of p1_types.h) */
typedef struct ObjDef ObjDef;
struct ObjDef {
    /* 0x000 */ s32 type;
    /* 0x004 */ u32 flags4;
    /* 0x008 */ u8 pad8[0xC];
    /* 0x014 */ u32 flags14;
    /* 0x018 */ u8 pad18[0x8];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ u8 pad24[0x18];
    /* 0x03C */ f32 unk3C;
    /* 0x040 */ u8 pad40[0xC];
    /* 0x04C */ u32 flags4C;
    /* 0x050 */ f32 unk50;
};

/* 3 bytes + index */
typedef struct Vec3b Vec3b;
struct Vec3b {
    /* 0x000 */ u8 b0;
    /* 0x001 */ u8 b1;
    /* 0x002 */ u8 b2;
    /* 0x003 */ s8 b3;
};

typedef struct B11Pt B11Pt;
struct B11Pt {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
};

typedef struct B11Box B11Box;
struct B11Box {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ B11Pt * p4;
    /* 0x008 */ B11Pt * p8;
    /* 0x00C */ B11Pt * pC;
};

/* generic game object (Actor of p1_types.h seen through other fields) */
typedef struct Obj Obj;
struct Obj {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[0x3];
    /* 0x004 */ u16 unk4;
    /* 0x006 */ u8 pad6[0x6];
    /* 0x00C */ f32 unkC;
    /* 0x010 */ u8 pad10[0x4];
    /* 0x014 */ B11Box * unk14;
    /* 0x018 */ ObjDef * def;
    /* 0x01C */ u8 pad1C[0x18];
    /* 0x034 */ s32 unk34;
    /* 0x038 */ u32 unk38;
    /* 0x03C */ s32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 pad44[0xC];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05C */ u8 pad5C[0x14];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 unk74[4];
    /* 0x078 */ u8 pad78[0x3C];
    /* 0x0B4 */ s32 unkB4;
    /* 0x0B8 */ s32 unkB8;
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ s32 unkC0;
    /* 0x0C4 */ u8 padC4[0x20];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x2];
    /* 0x0E8 */ u8 unkE8[4];
    /* 0x0EC */ u8 padEC[0x14];
    /* 0x100 */ u32 flags;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s16 unk108;
    /* 0x10A */ s16 unk10A;
    /* 0x10C */ u8 pad10C[0x2];
    /* 0x10E */ u8 unk10E;
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 pad110[0x60];
    /* 0x170 */ u8 unk170[4];
    /* 0x174 */ s32 unk174;
    /* 0x178 */ u8 pad178[0x2C];
    /* 0x1A4 */ f32 unk1A4;
    /* 0x1A8 */ u8 pad1A8[0x1C];
    /* 0x1C4 */ s32 unk1C4;
    /* 0x1C8 */ u8 pad1C8[0xC4];
    /* 0x28C */ void (*unk28C)();
    /* 0x290 */ u8 pad290[0x50];
    /* 0x2E0 */ u32 unk2E0;
};

#endif
