#ifndef B06_TYPES_H
#define B06_TYPES_H

#include "common.h"
#include "p1_types.h"

/* Batch 06 types (generated from wip/structs.txt by wip/mkhdr.py; offsets are exact, padding explicit).
   B6F(): accessor for offsets not named yet.  NOTE: accesses through B6F are not seen by gcc as struct
   member accesses (MEM_IN_STRUCT_P), which changes scheduling; prefer real fields when matching. */
#define B6F(p, T, off) (*(T *)((u8 *)(p) + (off)))

typedef struct PlrStats PlrStats;
typedef struct PlrList PlrList;
typedef struct PlrRec21 PlrRec21;
typedef struct PlrAux PlrAux;
typedef struct PlrEnt PlrEnt;
typedef struct PlrDef PlrDef;
typedef struct Pawn Pawn;
typedef struct PlrCls PlrCls;
typedef struct GameB6 GameB6;
typedef struct GStateB6 GStateB6;
typedef struct Plr Plr;
typedef struct PlrGroup PlrGroup;

struct PlrStats {
    /* 0x0000 */ u8 pad0[0x3C];
    /* 0x003C */ s16 unk3C[8];
    /* 0x004C */ u8 pad4C[0x35];
    /* 0x0081 */ u8 unk81;
    /* 0x0082 */ u8 pad82[0xC];
    /* 0x008E */ u8 unk8E;
    /* 0x008F */ u8 unk8F;
    /* 0x0090 */ u8 unk90;
    /* 0x0091 */ u8 pad91[0x3];
    /* 0x0094 */ u8 unk94;
};

struct PlrList {
    /* 0x0000 */ u8 pad0[0x144];
    /* 0x0144 */ Plr* arrA[0x200];
    /* 0x0944 */ s32 cntA;
    /* 0x0948 */ Plr* arrB[0x80];
    /* 0x0B48 */ s32 cntB;
};

struct PlrRec21 {
    /* 0x0000 */ u8 b[0x15];
};

struct PlrAux {
    /* 0x0000 */ u8 pad0[0x10];
    /* 0x0010 */ s32 unk10;
};

struct PlrEnt {
    /* 0x0000 */ f32 unk0;
    /* 0x0004 */ f32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ f32 unkC;
    /* 0x0010 */ f32 unk10;
    /* 0x0014 */ s32 unk14;
};

struct PlrDef {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ u16 unk4;
    /* 0x0006 */ u8 pad6[0x1A];
    /* 0x0020 */ s16* unk20;
    /* 0x0024 */ s16* unk24;
};

struct Pawn {
    /* 0x0000 */ u8 pad0[0x24];
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ u8 pad28[0x100];
    /* 0x0128 */ Vec3f pos128;
    /* 0x0134 */ u8 pad134[0x2C];
    /* 0x0160 */ f32 m160[16];
    /* 0x01A0 */ u8 pad1A0[0x3C4];
    /* 0x0564 */ s32 unk564;
};

struct PlrCls {
    /* 0x0000 */ u8 pad0[0xC];
    /* 0x000C */ s16 unkC;
    /* 0x000E */ u8 padE[0xE6];
    /* 0x00F4 */ f32 unkF4;
    /* 0x00F8 */ u8 padF8[0x4];
    /* 0x00FC */ f32 unkFC;
    /* 0x0100 */ f32 unk100;
    /* 0x0104 */ f32 unk104;
    /* 0x0108 */ s32 unk108[1];
};

struct GameB6 {
    /* 0x0000 */ u8 pad0[0x1C];
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ u8 pad2C[0x14];
    /* 0x0040 */ s32 unk40[5];
    /* 0x0054 */ s32 unk54;
    /* 0x0058 */ u8 pad58[0x24];
    /* 0x007C */ s32 unk7C;
    /* 0x0080 */ u8 pad80[0x28];
    /* 0x00A8 */ s32 unkA8;
};

struct GStateB6 {
    /* 0x0000 */ u8 pad0[0xD];
    /* 0x000D */ u8 unkD;
    /* 0x000E */ u8 padE[0xF];
    /* 0x001D */ u8 unk1D;
    /* 0x001E */ u8 pad1E[0x12A];
    /* 0x0148 */ u8 unk148;
    /* 0x0149 */ u8 pad149[0x19];
    /* 0x0162 */ u8 unk162;
    /* 0x0163 */ u8 pad163[0x475];
    /* 0x05D8 */ GameB6 sub;
};

struct Plr {
    /* 0x0000 */ u8 pad0[0x3];
    /* 0x0003 */ u8 unk3;
    /* 0x0004 */ u8 pad4[0x4];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x4];
    /* 0x0018 */ PlrCls* unk18;
    /* 0x001C */ u8 pad1C[0x4];
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ u8 pad24[0x14];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0x14];
    /* 0x0050 */ f32 unk50;
    /* 0x0054 */ f32 unk54;
    /* 0x0058 */ f32 unk58;
    /* 0x005C */ u8 pad5C[0x14];
    /* 0x0070 */ s32 unk70;
    /* 0x0074 */ u8 pad74[0x70];
    /* 0x00E4 */ u16 unkE4;
    /* 0x00E6 */ u8 padE6[0x8E];
    /* 0x0174 */ s32 unk174;
    /* 0x0178 */ u8 pad178[0x1E0];
    /* 0x0358 */ s32 unk358;
    /* 0x035C */ u8 pad35C[0x128];
    /* 0x0484 */ PlrAux* unk484;
    /* 0x0488 */ u8 pad488[0x10C];
    /* 0x0594 */ s32 unk594;
    /* 0x0598 */ u8 pad598[0x38];
    /* 0x05D0 */ s32 unk5D0;
    /* 0x05D4 */ s32 unk5D4;
    /* 0x05D8 */ PlrStats* stats;
    /* 0x05DC */ Pawn* unk5DC;
    /* 0x05E0 */ s32 unk5E0;
    /* 0x05E4 */ s32 unk5E4;
    /* 0x05E8 */ u8 pad5E8[0xC];
    /* 0x05F4 */ s16 unk5F4[8];
    /* 0x0604 */ s8 unk604;
    /* 0x0605 */ u8 pad605[0x29];
    /* 0x062E */ s16 unk62E;
    /* 0x0630 */ u8 pad630[0x68];
    /* 0x0698 */ u8* unk698;
    /* 0x069C */ u8 pad69C[0x1D0];
    /* 0x086C */ s32 unk86C;
    /* 0x0870 */ u8 pad870[0x974];
    /* 0x11E4 */ f32 unk11E4;
    /* 0x11E8 */ u8 pad11E8[0x14];
    /* 0x11FC */ f32 unk11FC;
    /* 0x1200 */ Vec3f unk1200;
    /* 0x120C */ s32 unk120C;
    /* 0x1210 */ s32 unk1210;
    /* 0x1214 */ s32 unk1214;
    /* 0x1218 */ u8 pad1218[0x30];
    /* 0x1248 */ PlrEnt ent[5];
    /* 0x12C0 */ f32 unk12C0;
    /* 0x12C4 */ u8 pad12C4[0x80];
    /* 0x1344 */ PlrRec21 rec[5];
    /* 0x13AD */ u8 pad13AD[0x3];
    /* 0x13B0 */ s32 unk13B0;
    /* 0x13B4 */ u8 pad13B4[0x2C];
    /* 0x13E0 */ s32 unk13E0;
    /* 0x13E4 */ u8 pad13E4[0x6C];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ u8 pad1454[0x28C];
    /* 0x16E0 */ Plr* next;
};

struct PlrGroup {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ Plr* unk4;
    /* 0x0008 */ u8 pad8[0x18];
    /* 0x0020 */ Plr* head;
};

#endif
