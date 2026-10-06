#ifndef B2_TYPES_H
#define B2_TYPES_H

#include "common.h"
#include "p1_types.h"

/* Types recovered by batch 02 (generated from wip/types_spec.txt; do not edit by hand).
   Offsets are the ones seen in the asm; padding arrays fill the gaps. */


typedef struct B2Info {
    /* 0x0000 */ u32 flags;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ u8 pad8[0x4];
    /* 0x000C */ s16 unkC;
    /* 0x000E */ u8 padE[0x6];
    /* 0x0014 */ f32 unk14;
    /* 0x0018 */ f32 unk18;
    /* 0x001C */ f32 unk1C;
    /* 0x0020 */ f32 unk20;
    /* 0x0024 */ u32 flags24;
    /* 0x0028 */ u8 pad28[0x4];
    /* 0x002C */ f32 unk2C;
    /* 0x0030 */ f32 unk30;
    /* 0x0034 */ f32 unk34;
    /* 0x0038 */ f32 unk38;
    /* 0x003C */ u8 pad3C[0x14];
    /* 0x0050 */ f32 unk50;
    /* 0x0054 */ u8 pad54[0xC];
} B2Info;

typedef struct B2Stats {
    /* 0x0000 */ u8 pad0[0x80];
    /* 0x0080 */ s8 unk80;
    /* 0x0081 */ u8 pad81[0xE];
    /* 0x008F */ u8 unk8F;
    /* 0x0090 */ u8 pad90[0x3];
    /* 0x0093 */ u8 unk93;
    /* 0x0094 */ u8 unk94;
    /* 0x0095 */ u8 unk95;
} B2Stats;

typedef struct B2Brain {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ s32 key;
} B2Brain;

typedef struct B2Def {
    /* 0x0000 */ s32 type;
    /* 0x0004 */ u8 pad4[0x10];
    /* 0x0014 */ B2Info info;
} B2Def;

typedef struct B2Evt {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ u16 unk4;
    /* 0x0006 */ u8 pad6[0x4];
    /* 0x000A */ u16 unkA;
} B2Evt;

typedef struct B2Actor B2Actor;
struct B2Actor {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x4];
    /* 0x0018 */ B2Def *def;
    /* 0x001C */ u8 pad1C[0x1C];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0xC4];
    /* 0x0100 */ u32 flags;
    /* 0x0104 */ u8 pad104[0xD4];
    /* 0x01D8 */ B2Actor *owner;
    /* 0x01DC */ u8 pad1DC[0x3FC];
    /* 0x05D8 */ B2Stats *stats;
    /* 0x05DC */ u8 pad5DC[0xC4];
    /* 0x06A0 */ f32 unk6A0;
    /* 0x06A4 */ u8 pad6A4[0xC9C];
    /* 0x1340 */ s32 unk1340;
    /* 0x1344 */ u8 pad1344[0x110];
    /* 0x1454 */ B2Brain *brain;
};

typedef struct B2State B2State;
struct B2State {
    /* 0x0000 */ u32 flags;
    /* 0x0004 */ u8 pad4[0x60];
    /* 0x0064 */ f32 unk64;
    /* 0x0068 */ u8 pad68[0x104];
    /* 0x016C */ s32 unk16C;
};

typedef struct B2AnimEnt {
    /* 0x0000 */ s32 id;
    /* 0x0004 */ void (*cb)();
    /* 0x0008 */ u8 pad8[0x18];
} B2AnimEnt;

typedef struct B2AnimTbl B2AnimTbl;
struct B2AnimTbl {
    /* 0x0000 */ B2AnimTbl *next;
    /* 0x0004 */ u8 pad4[0x1C];
    /* 0x0020 */ B2AnimEnt ent[1];
};

typedef struct B2Ctl {
    /* 0x0000 */ B2Actor *owner;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ s32 unk10;
    /* 0x0014 */ s32 q[4];
    /* 0x0024 */ u8 pad24[0x4];
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ s32 unk2C;
    /* 0x0030 */ s32 unk30;
    /* 0x0034 */ s32 unk34;
    /* 0x0038 */ s32 unk38;
    /* 0x003C */ B2Actor* a3C[10];
    /* 0x0064 */ B2Actor *target;
    /* 0x0068 */ s32 unk68;
    /* 0x006C */ s32 a6C[10];
    /* 0x0094 */ s32 a94[10];
    /* 0x00BC */ s32 unkBC;
    /* 0x00C0 */ u8 padC0[0xFC];
    /* 0x01BC */ s32 unk1BC;
    /* 0x01C0 */ u8 pad1C0[0x8];
    /* 0x01C8 */ s32 unk1C8;
    /* 0x01CC */ u8 pad1CC[0x48];
    /* 0x0214 */ B2AnimTbl *tbl;
    /* 0x0218 */ B2AnimEnt *cur;
    /* 0x021C */ s32 curId;
    /* 0x0220 */ s32 unk220;
    /* 0x0224 */ s32 unk224;
    /* 0x0228 */ s32 unk228;
    /* 0x022C */ u8 pad22C[0x4];
    /* 0x0230 */ s32 unk230;
    /* 0x0234 */ u8 pad234[0x4];
    /* 0x0238 */ s32 unk238;
    /* 0x023C */ s32 unk23C;
    /* 0x0240 */ s32 unk240;
    /* 0x0244 */ f32 unk244;
    /* 0x0248 */ f32 unk248;
    /* 0x024C */ f32 unk24C;
    /* 0x0250 */ f32 unk250;
    /* 0x0254 */ f32 unk254;
    /* 0x0258 */ f32 unk258;
    /* 0x025C */ f32 unk25C;
    /* 0x0260 */ f32 unk260;
    /* 0x0264 */ u8 pad264[0x28];
    /* 0x028C */ s32 unk28C;
    /* 0x0290 */ u8 pad290[0x48];
    /* 0x02D8 */ s32 unk2D8;
    /* 0x02DC */ s32 unk2DC;
    /* 0x02E0 */ s32 unk2E0;
    /* 0x02E4 */ s32 unk2E4;
    /* 0x02E8 */ s32 unk2E8;
    /* 0x02EC */ s32 unk2EC;
    /* 0x02F0 */ u8 pad2F0[0x4];
    /* 0x02F4 */ s32 unk2F4;
    /* 0x02F8 */ s32 unk2F8;
    /* 0x02FC */ s32 unk2FC;
    /* 0x0300 */ s32 unk300;
    /* 0x0304 */ s32 unk304;
    /* 0x0308 */ s32 unk308;
    /* 0x030C */ s32 unk30C;
    /* 0x0310 */ s32 unk310;
    /* 0x0314 */ u8 pad314[0x4];
    /* 0x0318 */ s32 unk318;
    /* 0x031C */ s32 unk31C;
    /* 0x0320 */ s32 unk320;
    /* 0x0324 */ s32 unk324;
    /* 0x0328 */ s32 unk328;
    /* 0x032C */ s32 unk32C;
} B2Ctl;

typedef struct B2Pool {
    /* 0x0000 */ s32 elemSize;
    /* 0x0004 */ u8 pad4[0x4];
    /* 0x0008 */ u8 data[1];
} B2Pool;

typedef struct B2Node B2Node;
struct B2Node {
    /* 0x0000 */ s32 id;
    /* 0x0004 */ f32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ u8 padC[0x4];
    /* 0x0010 */ B2Node *next;
    /* 0x0014 */ u8 pad14[0x4];
    /* 0x0018 */ f32 unk18;
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ s32 unk2C;
    /* 0x0030 */ B2Node *link30;
    /* 0x0034 */ u8 pad34[0x4];
    /* 0x0038 */ s32 unk38;
};

typedef struct B2Edge {
    /* 0x0000 */ u16 a;
    /* 0x0002 */ u16 b;
    /* 0x0004 */ u8 kind;
    /* 0x0005 */ u8 pad5[0x3];
} B2Edge;

typedef struct B2Mgr {
    /* 0x0000 */ B2Pool *pool0;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ B2Pool *pool8;
    /* 0x000C */ s32 count;
    /* 0x0010 */ B2Pool *unk10;
    /* 0x0014 */ u8 pad14[0x4];
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ f32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ B2Node *head;
    /* 0x0028 */ u8 pad28[0x10];
    /* 0x0038 */ s32 slots[64];
} B2Mgr;

typedef struct B2Edge2 {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ s32 src;
    /* 0x0008 */ u8 pad8[0x4];
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ s32 dst;
} B2Edge2;

typedef struct B2Cfg {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ u8 pad10[0x8];
    /* 0x0018 */ s32 unk18;
} B2Cfg;

typedef struct B2Rec {
    /* 0x0000 */ u8 pad0[0xC];
    /* 0x000C */ u16 flags;
    /* 0x000E */ u16 id;
} B2Rec;

typedef struct B2GameFlags {
    /* 0x0000 */ u8 pad0[0x1C];
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ u8 pad24[0x30];
    /* 0x0054 */ s32 unk54;
    /* 0x0058 */ u8 pad58[0x10];
    /* 0x0068 */ s32 unk68;
    /* 0x006C */ u8 pad6C[0xC];
    /* 0x0078 */ s32 unk78;
    /* 0x007C */ u8 pad7C[0x1C];
    /* 0x0098 */ s32 unk98;
    /* 0x009C */ s32 unk9C;
} B2GameFlags;

typedef struct B2World {
    /* 0x0000 */ u8 pad0[0x1860];
    /* 0x1860 */ B2GameFlags flags;
} B2World;

typedef struct B2Pt {
    /* 0x0000 */ s32 w[7];
} B2Pt;

#endif
