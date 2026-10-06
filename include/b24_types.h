#ifndef B24_TYPES_H
#define B24_TYPES_H

#include "p1_types.h"

typedef struct Emit Emit;

/* animation slot (0x38 bytes) */
typedef struct AnimSlot {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 padE[2];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 pad1A[2];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
} AnimSlot;

typedef struct AnimCtl {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 pad2[2];
    /* 0x04 */ AnimSlot slot[4];
    /* 0xE4 */ u16 cur;
    /* 0xE6 */ s16 unkE6;
    /* 0xE8 */ s32 unkE8;
} AnimCtl;

/* emitter definition block (Emit.def, at +0x8) */
typedef struct EmitDef {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 pad4[0x19];
    /* 0x1D */ u8 unk1D;
    /* 0x1E */ u8 pad1E[3];
    /* 0x21 */ u8 unk21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 unk23;
    /* 0x24 */ s32 unk24;
} EmitDef;

typedef struct EmitOwner {
    /* 0x000 */ u8 pad0[0x118];
    /* 0x118 */ struct EmitOwnerInfo *info;
    /* 0x11C */ u8 pad11C[0x1F];
    /* 0x13B */ u8 unk13B;
    /* 0x13C */ u8 pad13C[0x9D];
    /* 0x1D9 */ u8 unk1D9;
} EmitOwner;

typedef struct EmitOwnerInfo {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 unk14;
} EmitOwnerInfo;

typedef struct Mtx64 {
    f32 m[16];
} Mtx64;

typedef struct EmitNode EmitNode;
struct EmitNode {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ EmitNode *next;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ f32 v10[3];
    /* 0x1C */ f32 v1C[3];
    /* 0x28 */ Mtx64 mtx[2];
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ EmitOwner *unkB0;
};

struct Emit {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ Emit *next;
    /* 0x08 */ EmitDef *def;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[8];
    /* 0x1C */ EmitOwner *owner;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[0xC];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[4];
    /* 0x3C */ u32 flags;
    /* 0x40 */ EmitNode *list;
    /* 0x44 */ u8 pad44[4];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ f32 unk4C;
};

/* output block of func_002A7058 */
typedef struct EmitOut {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
} EmitOut;


typedef struct EmitMgr {
    /* 0x0000 */ u8 pad0[0x7528];
    /* 0x7528 */ Emit *head;
} EmitMgr;

/* player-like object used by the pickup handlers (func_002ADxxx) */
typedef struct Stats24 {
    u8 pad0[0x8F];
    u8 unk8F;
} Stats24;

typedef struct Slot24 {
    s8 a;
    s8 b;
} Slot24;

typedef struct Ent24 {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ s32 unk8;
    /* 0x00C */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ u8 pad14[0x24];
    /* 0x038 */ u32 unk38;
    /* 0x03C */ u8 pad3C[0xA8];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x1A];
    /* 0x100 */ u32 flags100;
    /* 0x104 */ u8 pad104[0x70];
    /* 0x174 */ s32 unk174;
    /* 0x178 */ u8 pad178[0x460];
    /* 0x5D8 */ Stats24 *unk5D8;
    /* 0x5DC */ s32 unk5DC;
    /* 0x5E0 */ u8 pad5E0[4];
    /* 0x5E4 */ s32 unk5E4;
    /* 0x5E8 */ u16 unk5E8;
    /* 0x5EA */ s16 unk5EA;
    /* 0x5EC */ u8 pad5EC[0x16];
    /* 0x602 */ Slot24 slot[22];
    /* 0x62E */ s16 unk62E;
    /* 0x630 */ u8 pad630[0x40];
    /* 0x670 */ f32 unk670;
    /* 0x674 */ f32 unk674;
    /* 0x678 */ f32 unk678;
    /* 0x67C */ u8 pad67C[0xF4];
    /* 0x770 */ u16 unk770;
    /* 0x772 */ u8 pad772[0x54E];
    /* 0xCC0 */ s32 unkCC0;
} Ent24;

#endif
