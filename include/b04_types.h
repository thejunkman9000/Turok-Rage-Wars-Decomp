#ifndef B04_TYPES_H
#define B04_TYPES_H
#include "p1_types.h"

/* batch-4 (b04) recovered types; unique names prefixed B04.
   Structs between the GENERATED markers come from the offset table used while matching: padding arrays keep the
   offsets seen in the asm, field names are provisional (unkXX = offset). */

/* gcc 2.8.1 -O2 inlines sqrtf as sqrt.s + c.eq.s + (bc1t over) jal sqrtf; the ROM always calls sqrtf.
   Calling it through an asm-label alias keeps the call (alternative: compile with -fno-builtin). */
f32 b04_sqrtf(f32 x) __asm__("sqrtf");
#define sqrtf(x) b04_sqrtf(x)

typedef struct B04Pos { u8 pad0[8]; f32 x; f32 y; f32 z; } B04Pos;

/* BEGIN GENERATED */
typedef struct B04Weapon B04Weapon;
struct B04Weapon {
    /* 0x000 */ u8 pad0[0xb0];
    /* 0x0b0 */ u32 flagsB0;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ u32 flagsB8;
};

typedef struct B04Pr B04Pr;
struct B04Pr {
    /* 0x000 */ s8 a;
    /* 0x001 */ s8 b;
};

typedef struct B04Sub B04Sub;
struct B04Sub {
    /* 0x000 */ u8 pad0[0x564];
    /* 0x564 */ s32 unk564;
};

typedef struct B04Stat B04Stat;
struct B04Stat {
    /* 0x000 */ u8 pad0[0x80];
    /* 0x080 */ s8 unk80;
    /* 0x081 */ u8 unk81;
    /* 0x082 */ u8 unk82;
    /* 0x083 */ u8 pad83[0xc];
    /* 0x08f */ u8 unk8F;
    /* 0x090 */ u8 pad90[0x2];
    /* 0x092 */ u8 unk92;
};

typedef struct B04Brain B04Brain;
struct B04Brain {
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ s32 unk4;
};

typedef struct B04Act B04Act;
struct B04Act {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ ActorDef * def;
    /* 0x01c */ u8 pad1C[0x1c];
    /* 0x038 */ u32 flags38;
    /* 0x03c */ u8 pad3C[0x30];
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ u8 pad70[0x74];
    /* 0x0e4 */ u16 unkE4;
    /* 0x0e6 */ u8 padE6[0x1a];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0x70];
    /* 0x174 */ s32 unk174;
    /* 0x178 */ u8 pad178[0x2c];
    /* 0x1a4 */ s8 unk1A4;
    /* 0x1a5 */ u8 pad1A5[0x33];
    /* 0x1d8 */ B04Act * owner;
    /* 0x1dc */ u8 pad1DC[0x104];
    /* 0x2e0 */ u32 unk2E0;
    /* 0x2e4 */ u8 pad2E4[0xc];
    /* 0x2f0 */ Vec3f v2F0;
    /* 0x2fc */ s32 unk2FC;
    /* 0x300 */ u8 pad300[0x54];
    /* 0x354 */ f32 unk354;
    /* 0x358 */ u8 pad358[0x12c];
    /* 0x484 */ s32 unk484;
    /* 0x488 */ u8 pad488[0x4];
    /* 0x48c */ s8 unk48C;
    /* 0x48d */ u8 pad48D[0xeb];
    /* 0x578 */ s32 unk578;
    /* 0x57c */ u8 pad57C[0x5c];
    /* 0x5d8 */ B04Stat * stats;
    /* 0x5dc */ B04Sub * sub5DC;
    /* 0x5e0 */ s32 unk5E0;
    /* 0x5e4 */ u8 pad5E4[0x10];
    /* 0x5f4 */ s16 unk5F4[7];
    /* 0x602 */ B04Pr pr[22];
    /* 0x62e */ s16 unk62E;
    /* 0x630 */ s16 unk630;
    /* 0x632 */ s16 unk632;
    /* 0x634 */ u8 pad634[0x64];
    /* 0x698 */ B04Weapon * wpn;
    /* 0x69c */ u8 pad69C[0xd4];
    /* 0x770 */ s16 unk770;
    /* 0x772 */ u8 pad772[0x16];
    /* 0x788 */ s32 unk788;
    /* 0x78c */ u8 pad78C[0x8];
    /* 0x794 */ B04Act * unk794;
    /* 0x798 */ u8 pad798[0xcc];
    /* 0x864 */ s32 unk864;
    /* 0x868 */ s32 unk868;
    /* 0x86c */ u8 pad86C[0x454];
    /* 0xcc0 */ s32 unkCC0;
    /* 0xcc4 */ u8 padCC4[0x8];
    /* 0xccc */ s32 unkCCC;
    /* 0xcd0 */ u8 padCD0[0x4e0];
    /* 0x11b0 */ s32 unk11B0;
    /* 0x11b4 */ s32 unk11B4;
    /* 0x11b8 */ u8 pad11B8[0x20];
    /* 0x11d8 */ f32 unk11D8;
    /* 0x11dc */ u8 pad11DC[0x14];
    /* 0x11f0 */ s32 unk11F0;
    /* 0x11f4 */ u8 pad11F4[0x4];
    /* 0x11f8 */ s32 unk11F8;
    /* 0x11fc */ u8 pad11FC[0x254];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ B04Brain * brain;
    /* 0x1458 */ u8 pad1458[0x288];
    /* 0x16e0 */ B04Act * next;
};

typedef struct B04Vec4 B04Vec4;
struct B04Vec4 {
    /* 0x000 */ f32 x;
    /* 0x004 */ f32 y;
    /* 0x008 */ f32 z;
    /* 0x00c */ f32 w;
};

typedef struct B04SlotEnt B04SlotEnt;
struct B04SlotEnt {
    /* 0x000 */ s32 idx;
    /* 0x004 */ s32 val;
    /* 0x008 */ s32 on;
    /* 0x00c */ f32 f28;
    /* 0x010 */ s32 z2C;
    /* 0x014 */ f32 f30;
};

typedef struct B04Roster B04Roster;
struct B04Roster {
    /* 0x000 */ s32 w0;
    /* 0x004 */ f32 f4;
    /* 0x008 */ s32 w8;
    /* 0x00c */ s32 wC;
    /* 0x010 */ u8 pad10[0x4];
    /* 0x014 */ s32 w14;
    /* 0x018 */ s32 w18;
    /* 0x01c */ B04SlotEnt ent[36];
    /* 0x37c */ s32 w37C;
    /* 0x380 */ s32 w380;
    /* 0x384 */ s32 w384;
    /* 0x388 */ s32 w388;
    /* 0x38c */ s32 w38C;
    /* 0x390 */ s32 w390;
};

typedef struct B04Ent20 B04Ent20;
struct B04Ent20 {
    /* 0x000 */ s32 idx;
    /* 0x004 */ s32 one;
    /* 0x008 */ s32 f24;
    /* 0x00c */ s32 zero;
    /* 0x010 */ f32 f2C;
};

typedef struct B04Sel B04Sel;
struct B04Sel {
    /* 0x000 */ s32 idx;
    /* 0x004 */ Vec3f v;
    /* 0x010 */ s32 id;
    /* 0x014 */ f32 f14;
    /* 0x018 */ f32 f18;
};

typedef struct B04Draw B04Draw;
struct B04Draw {
    /* 0x000 */ s32 i;
    /* 0x004 */ s32 idx;
    /* 0x008 */ Vec3f v;
    /* 0x014 */ s32 u14;
    /* 0x018 */ f32 f18;
    /* 0x01c */ f32 f1C;
};

typedef struct B04Spawn B04Spawn;
struct B04Spawn {
    /* 0x000 */ Vec3f pos;
    /* 0x00c */ f32 w;
    /* 0x010 */ s16 kind;
    /* 0x012 */ s16 idx;
};

typedef struct B04Menu B04Menu;
struct B04Menu {
    /* 0x000 */ s32 w0;
    /* 0x004 */ f32 f4;
    /* 0x008 */ f32 f8;
    /* 0x00c */ u8 padC[0x8];
    /* 0x014 */ f32 f14;
    /* 0x018 */ u8 pad18[0x364];
    /* 0x37c */ s32 w37C;
    /* 0x380 */ s32 w380;
    /* 0x384 */ u8 pad384[0x4];
    /* 0x388 */ s32 w388;
    /* 0x38c */ u8 pad38C[0x8];
};
/* END GENERATED */
#endif
