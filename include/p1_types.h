#ifndef P1_TYPES_H
#define P1_TYPES_H

#include "common.h"

/* Types recovered while matching pilot batch 1 (game code, low main image).
   Padding arrays keep the offsets seen in the asm; names are provisional. */

/* constants block embedded at ActorDef+0x14 (offsets relative to the block) */
typedef struct ActorInfo {
    /* 0x00 */ u32 flags;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ u8 padE[6];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[0xC];
    /* 0x24 */ u32 flags24;
    /* 0x28 */ u8 pad28[0x28];
    /* 0x50 */ f32 unk50;
} ActorInfo;

/* class constants block pointed to by Actor.def */
typedef struct ActorDef {
    /* 0x00 */ s32 type;
    /* 0x04 */ u8 pad4[0x10];
    /* 0x14 */ ActorInfo info;
} ActorDef;

/* per-actor "stats" block at Actor.stats */
typedef struct ActorStats {
    /* 0x00 */ u8 pad0[0x80];
    /* 0x80 */ s8 unk80;
    /* 0x81 */ u8 pad81[0xD];
    /* 0x8E */ u8 unk8E;
    /* 0x8F */ u8 unk8F;
    /* 0x90 */ u8 pad90[2];
    /* 0x92 */ u8 unk92;
    /* 0x93 */ u8 unk93;
    /* 0x94 */ u8 unk94;
} ActorStats;

/* block at Actor.brain (0x1454) */
typedef struct Brain {
    /* 0x000 */ u8 pad0[0xC];
    /* 0x00C */ s32 unkC;
    /* 0x010 */ u8 pad10[0x210];
    /* 0x220 */ s32 unk220;
    /* 0x224 */ u8 pad224[0x18];
    /* 0x23C */ s32 unk23C;
    /* 0x240 */ s32 unk240;
    /* 0x244 */ u8 pad244[0x94];
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ s32 unk2DC;
    /* 0x2E0 */ u8 pad2E0[0xC];
    /* 0x2EC */ s32 unk2EC;
    /* 0x2F0 */ u8 pad2F0[0xC];
    /* 0x2FC */ s32 unk2FC;
} Brain;

typedef struct Actor Actor;
struct Actor {
    /* 0x0000 */ u8 pad0[0x18];
    /* 0x0018 */ ActorDef *def;
    /* 0x001C */ u8 pad1C[0x1C];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0xA8];
    /* 0x00E4 */ u16 unkE4;
    /* 0x00E6 */ u8 padE6[0x1A];
    /* 0x0100 */ u32 flags;
    /* 0x0104 */ u8 pad104[0xD4];
    /* 0x01D8 */ Actor *owner;
    /* 0x01DC */ u8 pad1DC[0x110];
    /* 0x02EC */ Actor *next2EC;
    /* 0x02F0 */ u8 pad2F0[0x2E4];
    /* 0x05D4 */ s32 unk5D4;
    /* 0x05D8 */ ActorStats *stats;
    /* 0x05DC */ u8 pad5DC[8];
    /* 0x05E4 */ s32 unk5E4;
    /* 0x05E8 */ u8 pad5E8[0x88];
    /* 0x0670 */ f32 unk670;
    /* 0x0674 */ u8 pad674[0x1CC];
    /* 0x0840 */ f32 unk840;
    /* 0x0844 */ u8 pad844[4];
    /* 0x0848 */ s32 unk848;
    /* 0x084C */ u8 pad84C[0x974];
    /* 0x11C0 */ s32 unk11C0;
    /* 0x11C4 */ u8 pad11C4[0x28C];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ Brain *brain;
    /* 0x1458 */ u8 pad1458[0x280];
    /* 0x16D8 */ u16 unk16D8;
    /* 0x16DA */ u8 pad16DA[6];
    /* 0x16E0 */ Actor *next;
};

/* list owner: head of a linked list of Actors (linked through Actor.next) */
typedef struct ActorGroup {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ Actor *head;
} ActorGroup;

/* function table entry used through ActorState.link (+0x8 = callback) */
typedef struct ActorLink {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ void (*cb)();
} ActorLink;

/* second argument of most actor state callbacks (0x10C-0x110 etc. are handlers) */
typedef struct ActorState {
    /* 0x000 */ u32 flags;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x24];
    /* 0x02C */ void *table;
    /* 0x030 */ ActorLink *link;
    /* 0x034 */ u8 pad34;
    /* 0x035 */ s8 unk35;
    /* 0x036 */ u8 pad36[0xA];
    /* 0x040 */ f32 unk40;
    /* 0x044 */ u8 pad44[0x87];
    /* 0x0CB */ s8 unkCB;
    /* 0x0CC */ u8 padCC[0x30];
    /* 0x0FC */ void *unkFC;
    /* 0x100 */ u8 pad100[8];
    /* 0x108 */ void (*fn108)();
    /* 0x10C */ void (*fn10C)();
    /* 0x110 */ void (*fn110)();
    /* 0x114 */ u8 pad114[0x10];
    /* 0x124 */ s32 unk124;
    /* 0x128 */ union { s32 i; f32 f; } unk128;
    /* 0x12C */ union { s32 i; f32 f; } unk12C;
    /* 0x130 */ u8 pad130[0xC];
    /* 0x13C */ f32 unk13C;
} ActorState;

/* misc small types */
typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

/* AI timing config (arg of func_0020A884) */
typedef struct AiCfg {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
} AiCfg;

/* global game-mode block at D_801468A0 (only the used words are named) */
typedef struct GameFlags {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x30];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[0x10];
    /* 0x68 */ s32 unk68;
} GameFlags;

/* node of a singly linked list (link at +0x10) */
typedef struct TimedNode TimedNode;
struct TimedNode {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ TimedNode *next;
    /* 0x14 */ u8 pad14[0x10];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s32 unk28;
};

typedef struct TimedList {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ TimedNode *head;
} TimedList;

/* actor pointer holder (arg of func_00209B64) */
typedef struct ActorRef {
    Actor *actor;
} ActorRef;

/* sound/emitter source (arg of func_002172D0) */
typedef struct SndSrc {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ u8 pad14[0xBC];
    /* 0xD0 */ void *unkD0;
} SndSrc;

/* display-list word pair appended through D_80110634 */
typedef struct DlCmd {
    u32 w0;
    u32 w1;
} DlCmd;

/* request block sent to the I/O thread (func_00202198) */
typedef struct IoReq {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u32 cmd;
    /* 0x10 */ s32 a0;
    /* 0x14 */ s32 a1;
    /* 0x18 */ s32 a2;
    /* 0x1C */ OSMesgQueue *reply;
} IoReq;

/* source / destination of func_002174E4 (copies a position into a 0x44 byte block) */
typedef struct VecSrc {
    u8 pad0[8];
    Vec3f v;
} VecSrc;

typedef struct VecDst {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ Vec3f a;
    /* 0x18 */ Vec3f b;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ Vec3f c;
    /* 0x34 */ Vec3f d;
    /* 0x40 */ s32 unk40;
} VecDst;

/* sound handle / owner (func_002172D0) */
typedef struct SndHandle {
    u8 pad0[0xC];
    s32 unkC;
} SndHandle;

typedef struct SndOwner {
    u8 pad0[0xFC];
    SndHandle *unkFC;
} SndOwner;

/* 0x190 byte rows indexed by Actor.unk5D4 (D_80102B10) */
typedef struct ActorRow400 {
    s32 unk0;
    u8 pad4[0x18C];
} ActorRow400;

#endif
