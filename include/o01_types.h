#ifndef O01_TYPES_H
#define O01_TYPES_H
#include "common.h"

/* Overlay A (VRAM 0x400000..) game-code types */

/* D_800E2830: HUD/menu context */
typedef struct O01Ctx {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ void *tree;
    /* 0x08 */ u8 pad8[0x10];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x1C];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 pad3C[0x1C];
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 pad5C[0x58];
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ u8 padB8[0x20];
    /* 0xD8 */ s32 unkD8;
    /* 0xDC */ s32 unkDC;
    /* 0xE0 */ s32 unkE0;
} O01Ctx;

/* self-relative offset table node (see func_0028FD94) */
typedef struct O01Node {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
} O01Node;

/* 0x20-byte Controller Pak directory entry (OSPfsState layout) */
typedef struct O01PadEnt {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u16 unk8;
    /* 0x0A */ u8 unkA[4];
    /* 0x0E */ u8 unkE[0x12];
} O01PadEnt;

/* D_800E2854: per-pad table, 0x204 bytes per pad = 4 + 16 * 0x20 */
typedef struct O01PadTab {
    /* 0x000 */ s32 unk0;
    /* 0x004 */ O01PadEnt ent[16];
} O01PadTab;

typedef struct O01Rumble {
    /* 0x00 */ u8 ok;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ OSPfs pfs;
} O01Rumble;

typedef struct O01Pad4 {
    /* 0 */ u8 pad0[3];
    /* 3 */ u8 unk3;
} O01Pad4;

typedef struct O01Vec3 {
    f32 x, y, z;
} O01Vec3;

/* menu item text holder: first word is the character buffer */
typedef struct O01Text {
    /* 0x0 */ char *buf;
} O01Text;

/* menu item (callbacks get (item, owner)) */
typedef struct O01Flags {
    /* 0x00 */ u8 pad0[0xA8];
    /* 0xA8 */ u32 unkA8;
    /* 0xAC */ u8 padAC[0x24];
    /* 0xD0 */ u32 unkD0;
    /* 0xD4 */ u8 padD4[0x4C];
    /* 0x120 */ u32 unk120;
} O01Flags;

typedef struct O01Item {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ O01Flags *unkC;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ O01Text *unk14;
} O01Item;

typedef struct O01OwnerSub {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 unk4;
    /* 0x05 */ u8 pad5[0xAB];
    /* 0xB0 */ u32 unkB0;
} O01OwnerSub;

typedef struct O01Owner {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ O01OwnerSub *unk20;
    /* 0x24 */ s32 unk24;
} O01Owner;

/* D_800E28BC: settings block edited by the menu */
typedef struct O01Cfg {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[4];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[2];
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0x68];
    /* 0x90 */ u32 unk90;
} O01Cfg;

#endif
