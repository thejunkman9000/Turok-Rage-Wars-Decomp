#ifndef B03_TYPES_H
#define B03_TYPES_H

#include "p1_types.h"

/* Batch 03 (ROM 0xFD50-0x16D08, func_0020F150..func_00216108): extra layouts.
   p1_types.h is not edited; where it lacks fields we use overlay structs
   (cast of the same pointer) with explicit padding. */

typedef struct ActorB ActorB;
typedef struct BrainB BrainB;
typedef struct CtlB CtlB;
typedef struct SpawnB SpawnB;
typedef struct DefC DefC;
typedef struct SpawnTail SpawnTail;

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
    /* 0x02C */ Vec3f unk2C;
    /* 0x038 */ s32 count;
    /* 0x03C */ ActorB *actors[10];
    /* 0x064 */ ActorB *unk64;
    /* 0x068 */ ActorB *unk68;
    /* 0x06C */ s32 valid[10];
    /* 0x094 */ s32 value[10];
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ u8 padC0[0x10C];
    /* 0x1CC */ s32 step;
    /* 0x1D0 */ f32 fa[8];
    /* 0x1F0 */ f32 fb[8];
    /* 0x210 */ f32 unk210;
    /* 0x214 */ u8 pad214[0x8];
    /* 0x21C */ u32 state;
    /* 0x220 */ s32 unk220;
    /* 0x224 */ s32 unk224;
    /* 0x228 */ s32 unk228;
    /* 0x22C */ s32 unk22C;
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
    /* 0x300 */ u8 pad300[0x14];
    /* 0x314 */ s32 unk314;
    /* 0x318 */ s32 unk318;
    /* 0x31C */ s32 unk31C;
    /* 0x320 */ s32 unk320;
    /* 0x324 */ s32 unk324;
    /* 0x328 */ ActorB *unk328;
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
    /* 0x00 */ s32 mode;          /* game mode (2 / 4 ...) */
    /* 0x04 */ u8 pad4[0x78];
    /* 0x7C */ s32 *cnt;
} PathTbl;

/* element returned by func_0028D1F4(PathTbl*, idx) */
typedef struct PathEnt {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 len;
} PathEnt;

struct ActorB {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[0x7];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ ActorDef *def;
    /* 0x01C */ Vec3f vel;
    /* 0x028 */ u8 pad28[0x10];
    /* 0x038 */ u32 flags38;
    /* 0x03C */ u8 pad3C[0x30];
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x70];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x1A];
    /* 0x100 */ u32 flags;
    /* 0x104 */ f32 unk104;
    /* 0x108 */ s16 unk108;
    /* 0x10A */ s16 unk10A;
    /* 0x10C */ s16 unk10C;
    /* 0x10E */ s8 unk10E;
    /* 0x10F */ u8 unk10F;
    /* 0x110 */ u8 pad110[0x13];
    /* 0x123 */ u8 unk123;
    /* 0x124 */ u8 pad124[0xB4];
    /* 0x1D8 */ ActorB *owner;
    /* 0x1DC */ u8 pad1DC[0x104];
    /* 0x2E0 */ u32 unk2E0;
    /* 0x2E4 */ u8 pad2E4[0x8];
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
    /* 0x630 */ u8 pad630[0x20];
    /* 0x650 */ s16 unk650;
    /* 0x652 */ u8 pad652[0x1E];
    /* 0x670 */ f32 unk670;
    /* 0x674 */ u8 pad674[0x3C];
    /* 0x6B0 */ u32 unk6B0;
    /* 0x6B4 */ u8 pad6B4[0xBC];
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

/* global game state at D_80145040 (players via func_0022A5E4); the block at +0x1860 is the game-flags block (D_801468A0) */
typedef struct GameFlagsB {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ s32 unk24;
} GameFlagsB;

typedef struct GameB {
    /* 0x0000 */ u8 pad0[0x1860];
    /* 0x1860 */ GameFlagsB gf;
} GameB;

/* actor state machine tables (ActorState.table): chain of tables, entries of 0x20 bytes starting at +0x20, end marker id == -1 */
typedef struct StateEntry StateEntry;
typedef struct StateTable StateTable;
typedef struct StateB StateB;
struct StateEntry {
    /* 0x00 */ s32 id;
    /* 0x04 */ void (*fn)(ActorB *a, StateB *s);
    /* 0x08 */ u8 pad8[8];
    /* 0x10 */ void *anim;      /* animation id / callback */
    /* 0x14 */ f32 speed;
    /* 0x18 */ s32 len;
    /* 0x1C */ u32 flags;
};
struct StateTable {
    /* 0x00 */ StateTable *next;
    /* 0x04 */ u8 pad4[0x1C];
    /* 0x20 */ StateEntry ent[1];
};


/* game-flags block D_801468A0 (fields used by the actor-class helpers) */
typedef struct GameFlagsC {
    /* 0x00 */ u8 pad0[0x98];
    /* 0x98 */ s32 unk98;
    /* 0x9C */ s32 pad9C;
    /* 0xA0 */ s32 unkA0;
} GameFlagsC;

struct StateB {
    /* 0x000 */ u32 flags;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s8 unk10;
    /* 0x011 */ u8 pad11[0x1];
    /* 0x012 */ u8 unk12;
    /* 0x013 */ u8 unk13;
    /* 0x014 */ s8 unk14;
    /* 0x015 */ s8 unk15;
    /* 0x016 */ s8 unk16;
    /* 0x017 */ s8 unk17;
    /* 0x018 */ f32 unk18;
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
    /* 0x028 */ s32 unk28;
    /* 0x02C */ StateTable *table;
    /* 0x030 */ StateEntry *cur;
    /* 0x034 */ s8 id;
    /* 0x035 */ s8 unk35;
    /* 0x036 */ u8 prevId;
    /* 0x037 */ u8 pad37[0x1];
    /* 0x038 */ u32 unk38;
    /* 0x03C */ u32 unk3C;
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s32 unk44;
    /* 0x048 */ Vec3f unk48;
    /* 0x054 */ Vec3f unk54;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
    /* 0x06C */ s32 unk6C;
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32 unk78;
    /* 0x07C */ s32 unk7C;
    /* 0x080 */ s32 unk80;
    /* 0x084 */ s32 unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08C */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ u8 unk94;
    /* 0x095 */ u8 unk95;
    /* 0x096 */ s16 unk96;
    /* 0x098 */ u8 pad98[0x4];
    /* 0x09C */ f32 unk9C;
    /* 0x0A0 */ Vec3f unkA0;
    /* 0x0AC */ s32 unkAC;
    /* 0x0B0 */ Vec3f unkB0;
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ f32 unkC0;
    /* 0x0C4 */ f32 unkC4;
    /* 0x0C8 */ s16 unkC8;
    /* 0x0CA */ s8 unkCA;
    /* 0x0CB */ u8 unkCB;
    /* 0x0CC */ s8 unkCC;
    /* 0x0CD */ u8 padCD[0x3];
    /* 0x0D0 */ s32 unkD0;
    /* 0x0D4 */ s32 unkD4;
    /* 0x0D8 */ u8 padD8[0x24];
    /* 0x0FC */ void *unkFC;
    /* 0x100 */ u8 unk100;
    /* 0x101 */ u8 pad101[0x1];
    /* 0x102 */ s16 unk102;
    /* 0x104 */ u8 pad104[0x8];
    /* 0x10C */ void *fn10C;
    /* 0x110 */ u8 pad110[0xC];
    /* 0x11C */ void *fn11C;
};

struct SpawnB {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ ActorDef *def;
    /* 0x01C */ u8 pad1C[0x50];
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ u8 pad70[0x90];
    /* 0x100 */ u32 flags;
};

/* weapon descriptor table D_800D052C[w]: ->info (+0x20) -> type (s16) */
typedef struct WpnInfo {
    /* 0x0 */ s16 type;
} WpnInfo;
typedef struct WpnDesc {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ WpnInfo *info;
} WpnDesc;

/* hit record at *D_80103FCC (collision result): position +0xE4, type +0xFC */
typedef struct HitRec {
    /* 0x00 */ u8 pad0[0xE4];
    /* 0xE4 */ Vec3f pos;
    /* 0xF0 */ u8 padF0[0xC];
    /* 0xFC */ s32 type;
} HitRec;

/* trace flags block passed (by pointer) to func_0024490C */
typedef struct TraceInfo {
    /* 0x00 */ s32 mask;
    /* 0x04 */ s8 a, b, c;
    /* 0x08 */ s32 pad8[5];
} TraceInfo;

struct DefC {
    /* 0x000 */ s32 type;
    /* 0x004 */ u8 pad4[0xA];
    /* 0x00E */ s8 unkE;
    /* 0x00F */ u8 padF[0x1];
    /* 0x010 */ s8 unk10;
    /* 0x011 */ u8 pad11[0x1];
    /* 0x012 */ s8 unk12;
    /* 0x013 */ u8 pad13[0x5];
    /* 0x018 */ s32 unk18;
    /* 0x01C */ u8 pad1C[0x24];
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 unk41;
};

struct SpawnTail {
    /* 0x000 */ u8 pad0[0x1];
    /* 0x001 */ s8 unk1;
    /* 0x002 */ s8 unk2;
    /* 0x003 */ s8 unk3;
};

#endif
