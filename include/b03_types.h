#ifndef B03_TYPES_H
#define B03_TYPES_H

#include "p1_types.h"

/* Batch 03 (ROM 0xFD50-0x16D08, func_0020F150..func_00216108): extra layouts.
   p1_types.h is not edited; where it lacks fields we use overlay structs
   (cast of the same pointer) with explicit padding. */

typedef struct ActorB ActorB;
typedef struct BrainB BrainB;
typedef struct CtlB CtlB;

/* raw field access for fields not yet in the shared structs */
#define FLD(type, ptr, off) (*(type *)((u8 *)(ptr) + (off)))

/* Brain (Actor.brain) overlay.  Brain +0 holds the owning object pointer; +0x1CC.. camera/anim sequencing data */
struct BrainB {
    /* 0x000 */ ActorB *actor;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[0x10];
    /* 0x028 */ s32 unk28;
    /* 0x02C */ u8 pad2C[0xC];
    /* 0x038 */ s32 count;
    /* 0x03C */ ActorB *actors[10];
    /* 0x064 */ ActorB *unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06C */ s32 valid[10];
    /* 0x094 */ s32 value[10];
    /* 0x0BC */ u8 padBC[0x110];
    /* 0x1CC */ s32 step;
    /* 0x1D0 */ f32 fa[8];
    /* 0x1F0 */ f32 fb[8];
    /* 0x210 */ f32 unk210;
    /* 0x214 */ u8 pad214[0x8];
    /* 0x21C */ u32 state;
    /* 0x220 */ s32 unk220;
    /* 0x224 */ s32 unk224;
    /* 0x228 */ s32 unk228;
    /* 0x22C */ u8 pad22C[0x4];
    /* 0x230 */ s32 unk230;
    /* 0x234 */ u8 pad234[0x4];
    /* 0x238 */ s32 unk238;
    /* 0x23C */ u8 pad23C[0x1C];
    /* 0x258 */ f32 unk258;
    /* 0x25C */ f32 unk25C;
    /* 0x260 */ f32 unk260;
    /* 0x264 */ u8 pad264[0x24];
    /* 0x288 */ s32 unk288;
    /* 0x28C */ ActorB *target;
    /* 0x290 */ u8 pad290[0x48];
    /* 0x2D8 */ s32 unk2D8;
    /* 0x2DC */ s32 unk2DC;
    /* 0x2E0 */ s32 unk2E0;
    /* 0x2E4 */ u8 pad2E4[0x18];
    /* 0x2FC */ s32 unk2FC;
    /* 0x300 */ u8 pad300[0x18];
    /* 0x318 */ s32 unk318;
    /* 0x31C */ s32 unk31C;
    /* 0x320 */ s32 unk320;
};

/* the target table views (func_0020F8F0 etc.) are Brain fields: TargetSet is an alias of BrainB */
typedef struct BrainB TargetSet;

/* entity list at D_8013B364: list head at +0x24, nodes linked at +0x10, key at +0 (id), owner object at +0x34 */
typedef struct EntNode EntNode;
typedef struct EntOwner {
    /* 0x000 */ u8 pad0[0x1A4];
    /* 0x1A4 */ s8 unk1A4;
    /* 0x1A5 */ u8 pad1A5[0xEF];
    /* 0x294 */ s32 unk294;
} EntOwner;
struct EntNode {
    /* 0x00 */ s32 key;
    /* 0x04 */ u8 pad4[0xC];
    /* 0x10 */ EntNode *next;
    /* 0x14 */ u8 pad14[0x20];
    /* 0x34 */ EntOwner *owner;
};
typedef struct EntList {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 count;
    /* 0x08 */ u8 pad8[0x10];
    /* 0x18 */ s32 sel;          /* current selection (-1 = none) */
    /* 0x1C */ u8 pad1C[8];
    /* 0x24 */ EntNode *head;
} EntList;
/* record returned by func_0020C994(list, key) */
typedef struct EntRec {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ u16 flags;
    /* 0x0E */ u16 id;
} EntRec;

/* object filled in by the entity-query helpers (func_0020F2A8 / func_0020F388) */
typedef struct QueryObj {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 key;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 pad18[0x50];
    /* 0x68 */ EntOwner *unk68;
    /* 0x6C */ u8 pad6C[0x50];
    /* 0xBC */ s32 unkBC;
} QueryObj;

/* id list given to func_0020F150 (30 ids, cleared by the callers) */
typedef struct IdQuery {
    s32 ids[30];
} IdQuery;

/* path/animation table D_8011FE88: +0x7C -> counter pointer */
typedef struct PathTbl {
    /* 0x00 */ u8 pad0[0x7C];
    /* 0x7C */ s32 *cnt;
} PathTbl;

/* element returned by func_0028D1F4(PathTbl*, idx) */
typedef struct PathEnt {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 len;
} PathEnt;

struct ActorB {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ ActorDef *def;
    /* 0x01C */ u8 pad1C[0x1C];
    /* 0x038 */ u32 flags38;
    /* 0x03C */ u8 pad3C[0xA8];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x1A];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0xD4];
    /* 0x1D8 */ ActorB *owner;
    /* 0x1DC */ u8 pad1DC[0x110];
    /* 0x2EC */ ActorB *next2EC;
    /* 0x2F0 */ u8 pad2F0[0x2A4];
    /* 0x594 */ s32 unk594;
    /* 0x598 */ u8 pad598[0x3C];
    /* 0x5D4 */ s32 unk5D4;
    /* 0x5D8 */ ActorStats *stats;
    /* 0x5DC */ u8 pad5DC[0x4];
    /* 0x5E0 */ s32 unk5E0;
    /* 0x5E4 */ s32 unk5E4;
    /* 0x5E8 */ u8 pad5E8[0x46];
    /* 0x62E */ s16 unk62E;
    /* 0x630 */ u8 pad630[0x40];
    /* 0x670 */ f32 unk670;
    /* 0x674 */ u8 pad674[0xFC];
    /* 0x770 */ s16 unk770;
    /* 0x772 */ u8 pad772[0xCE];
    /* 0x840 */ f32 unk840;
    /* 0x844 */ u8 pad844[0x4];
    /* 0x848 */ s32 unk848;
    /* 0x84C */ u8 pad84C[0x974];
    /* 0x11C0 */ s32 unk11C0;
    /* 0x11C4 */ u8 pad11C4[0x68];
    /* 0x122C */ u32 unk122C;
    /* 0x1230 */ u8 pad1230[0x220];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ BrainB *brain;
    /* 0x1458 */ u8 pad1458[0x280];
    /* 0x16D8 */ u16 unk16D8;
    /* 0x16DA */ u8 pad16DA[0x6];
    /* 0x16E0 */ ActorB *next;
};

struct CtlB {
    /* 0x000 */ ActorB *actor;
    /* 0x004 */ u8 pad4[0x2E0];
    /* 0x2E4 */ s32 unk2E4;
};

#endif
