#ifndef S1005_TYPES_H
#define S1005_TYPES_H

#include "common.h"

/* s1005: types for the overlay-A tail module 0x1B84C0..0x1BA5A0 (player / camera / scene objects of the match engine).
   Offsets come from the asm; names are provisional. */

/* matrix pool: base, half of the matrices (one frame), matrices left, next free (func_00279A00 resets left/cur) */
typedef struct S5MtxStack {
    /* 0x0 */ Mtx *base;
    /* 0x4 */ s32 n;
    /* 0x8 */ s32 left;
    /* 0xC */ Mtx *cur;
} S5MtxStack;

/* global game state block at D_801462C8 (only the words used here) */
typedef struct S5Glob {
    /* 0x000 */ u32 flags;
    /* 0x004 */ u8 pad4[9];
    /* 0x00D */ u8 mode;
    /* 0x00E */ u8 padE[0xF];
    /* 0x01D */ u8 f1D;
    /* 0x01E */ u8 pad1E[0x680 - 0x1E];
    /* 0x680 */ s32 f680;
} S5Glob;

/* player stats record seen through player->stats (+0x5D8) */
typedef struct S5Stats {
    /* 0x00 */ u8 pad0[0x8F];
    /* 0x8F */ u8 u8F;
} S5Stats;

/* player object (very large; only the fields used by this module) */
typedef struct S5Player {
    /* 0x000 */ u8 pad0[0x10E];
    /* 0x10E */ s8 s10E;
    /* 0x10F */ u8 pad10F[0x5D8 - 0x10F];
    /* 0x5D8 */ S5Stats *stats;
    /* 0x5DC */ u8 pad5DC[0x5EC - 0x5DC];
    /* 0x5EC */ s32 model;
    /* 0x5F0 */ u8 pad5F0[0x133C - 0x5F0];
    /* 0x133C */ s32 respawn;
    /* 0x1340 */ s32 f1340;
    /* 0x1344 */ u8 pad1344[0x1450 - 0x1344];
    /* 0x1450 */ s32 computer;
} S5Player;

/* intrusive list header (func_00255C40 / func_00255CB4): node links at byte offsets prevOff / nextOff */
typedef struct S5List {
    /* 0x00 */ void *head;
    /* 0x04 */ void *tail;
    /* 0x08 */ s32 prevOff;
    /* 0x0C */ s32 nextOff;
    /* 0x10 */ s32 count;
} S5List;

/* vertex of the shared unit quad (Vtx layout) */
typedef struct S5Vtx {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ u16 flag;
    /* 0x8 */ s16 s;
    /* 0xA */ s16 t;
    /* 0xC */ u8 c[4];
} S5Vtx;

/* 0x1F8-byte object of the quad / decal pool (func_0044C050) */
typedef struct S5Quad {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[0x17];
    /* 0x018 */ void *info;
    /* 0x01C */ u8 pad1C[0x5C - 0x1C];
    /* 0x05C */ s32 f5C;
    /* 0x060 */ u8 pad60[0x1DC - 0x60];
    /* 0x1DC */ s32 f1DC;
    /* 0x1E0 */ u8 pad1E0[4];
    /* 0x1E4 */ s32 f1E4;
    /* 0x1E8 */ u8 links[0x10];
} S5Quad;

typedef struct S5QuadPool {
    /* 0x00000 */ S5Quad obj[0x80];
    /* 0x0FC00 */ S5List used;
    /* 0x0FC14 */ S5List listB;
    /* 0x0FC28 */ S5List listC[3];
    /* 0x0FC64 */ s32 fFC64;
    /* 0x0FC68 */ s32 fFC68;
} S5QuadPool;

/* controller / rumble slot (0x224 bytes, array of 4 at D_8010F328; same object as the main image's B14Ctl) */
typedef struct S5CtlEnt {
    /* 0 */ u8 a;
    /* 1 */ u8 b;
    /* 2 */ u8 c;
    /* 3 */ u8 d;
} S5CtlEnt;

typedef struct S5Ctl {
    /* 0x000 */ s32 f0;
    /* 0x004 */ s8 port;
    /* 0x005 */ u8 pad5[3];
    /* 0x008 */ s32 f8;
    /* 0x00C */ s32 fC;
    /* 0x010 */ s32 f10;
    /* 0x014 */ s32 f14;
    /* 0x018 */ s32 f18;
    /* 0x01C */ s32 f1C;
    /* 0x020 */ s32 f20;
    /* 0x024 */ s32 f24;
    /* 0x028 */ s32 f28;
    /* 0x02C */ S5CtlEnt ent[32];
    /* 0x0AC */ u8 padAC[0xC4 - 0xAC];
    /* 0x0C4 */ u8 fC4;
    /* 0x0C5 */ u8 fC5;
    /* 0x0C6 */ u8 fC6;
    /* 0x0C7 */ u8 fC7;
    /* 0x0C8 */ s32 fC8;
    /* 0x0CC */ s32 fCC;
    /* 0x0D0 */ s32 fD0;
    /* 0x0D4 */ s32 fD4;
    /* 0x0D8 */ u8 padD8[0x140 - 0xD8];
    /* 0x140 */ u8 blkA[0x2C];
    /* 0x16C */ u8 blkB[0xB4];
    /* 0x220 */ s32 f220;
} S5Ctl;

/* 4 bytes per controller at D_8010FBE0 (byte 3 bit 3 = not connected) */
typedef struct S5PortFlags {
    /* 0 */ u8 b[4];
} S5PortFlags;

/* 28-byte record copied out of the level data by func_0044C250 (the scene's "simple model" entries at scene+0x1B450.. step 0x1C) */
typedef struct S5Simp {
    /* 0x00 */ s32 w0;
    /* 0x04 */ s32 w4;
    /* 0x08 */ s32 w8;
    /* 0x0C */ s32 wC;
    /* 0x10 */ s32 w10;
    /* 0x14 */ s32 w14;
    /* 0x18 */ s32 w18;
} S5Simp;

/* camera record: 0xED8 bytes, array allocated by func_0044AFC0 (field 8 = index) */
typedef struct S5Cam {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ s32 id;
    /* 0x00C */ u8 padC[0xED8 - 0xC];
} S5Cam;

/* sub-block of a camera-text record (0x14 bytes, words +4..+0x10 are cleared by the init) */
typedef struct S5Sub {
    /* 0x00 */ s32 w0;
    /* 0x04 */ s32 w4;
    /* 0x08 */ s32 w8;
    /* 0x0C */ s32 wC;
    /* 0x10 */ s32 w10;
} S5Sub;

/* 0x54-byte record of the manager's list at 0x11D8 (8 of them at 0xF38) */
typedef struct S5Rec {
    /* 0x00 */ void *prev;
    /* 0x04 */ void *next;
    /* 0x08 */ s32 w8;
    /* 0x0C */ s32 wC;
    /* 0x10 */ s32 w10;
    /* 0x14 */ f32 scale;
    /* 0x18 */ S5Sub a;
    /* 0x2C */ S5Sub b;
    /* 0x40 */ S5Sub c;
} S5Rec;

/* camera manager (0x1208 bytes; func_0044B27C resets it, func_0044AFC0 initialises it with n cameras) */
typedef struct S5Cams {
    /* 0x0000 */ void **h;            /* allocation handle of the camera array */
    /* 0x0004 */ S5Cam *data;         /* *h */
    /* 0x0008 */ s32 cnt;
    /* 0x000C */ S5List camList;
    /* 0x0020 */ S5List list20;
    /* 0x0034 */ s32 f34;
    /* 0x0038 */ s32 f38;
    /* 0x003C */ u8 pad3C[4];
    /* 0x0040 */ u8 part[8];          /* embedded viewport object (func_0044ADC0 / func_0025E410) */
    /* 0x0048 */ s32 part48;
    /* 0x004C */ u8 pad4C[0xF18 - 0x4C];
    /* 0x0F18 */ void **h2;           /* handle of the text array */
    /* 0x0F1C */ u8 *data2;
    /* 0x0F20 */ s32 cnt2;
    /* 0x0F24 */ S5List txtList;
    /* 0x0F38 */ S5Rec rec[8];
    /* 0x11D8 */ S5List recList;
    /* 0x11EC */ S5List list11EC;
    /* 0x1200 */ s32 f1200;
    /* 0x1204 */ u8 pad1204[4];
} S5Cams;

/* CScene (match scene / level object, 0x1B4xx+ bytes; same object as the main image's Level in b20_types.h).
   Only the words touched by func_0044C410 (the constructor) are named; the 5 simple-model records start at 0x1B450 (step 0x1C). */
typedef struct S5Scene {
    /* 0x00000 */ s32 f0;
    /* 0x00004 */ s32 f4;
    /* 0x00008 */ s32 f8;
    /* 0x0000C */ s32 fC;
    /* 0x00010 */ s32 f10;
    /* 0x00014 */ s32 f14;
    /* 0x00018 */ s32 f18;
    /* 0x0001C */ s32 f1C;
    /* 0x00020 */ s32 f20;
    /* 0x00024 */ s32 f24;
    /* 0x00028 */ s32 f28;
    /* 0x0002C */ s32 f2C;
    /* 0x00030 */ u8 pad30[4];
    /* 0x00034 */ s32 f34;
    /* 0x00038 */ s32 f38;
    /* 0x0003C */ s32 f3C;
    /* 0x00040 */ u8 pad40[4];
    /* 0x00044 */ s32 f44;
    /* 0x00048 */ s32 f48;
    /* 0x0004C */ void *f4C;
    /* 0x00050 */ void *f50;
    /* 0x00054 */ void *f54;
    /* 0x00058 */ void *f58;
    /* 0x0005C */ void *f5C;
    /* 0x00060 */ u8 pad60[0x10];
    /* 0x00070 */ void *f70;
    /* 0x00074 */ void *f74;
    /* 0x00078 */ void *f78;
    /* 0x0007C */ u8 pad7C[4];
    /* 0x00080 */ void *f80;
    /* 0x00084 */ void *f84;
    /* 0x00088 */ s32 f88;
    /* 0x0008C */ u8 pad8C[4];
    /* 0x00090 */ void *f90;
    /* 0x00094 */ void *f94;
    /* 0x00098 */ void *f98;
    /* 0x0009C */ void *f9C;
    /* 0x000A0 */ void *fA0;
    /* 0x000A4 */ void *fA4;
    /* 0x000A8 */ void *fA8;
    /* 0x000AC */ void *fAC;
    /* 0x000B0 */ void *fB0;
    /* 0x000B4 */ void **fB4;
    /* 0x000B8 */ u8 padB8[0xF0 - 0xB8];
    /* 0x000F0 */ s32 fF0;
    /* 0x000F4 */ s32 fF4;
    /* 0x000F8 */ s32 fF8;
    /* 0x000FC */ s32 fFC;
    /* 0x00100 */ u8 pad100[0x10C - 0x100];
    /* 0x0010C */ void **f10C;
    /* 0x00110 */ u8 pad110[0x120 - 0x110];
    /* 0x00120 */ s32 f120;
    /* 0x00124 */ s32 f124;
    /* 0x00128 */ u8 pad128[0x1B308 - 0x128];
    /* 0x1B308 */ s32 f1B308;
    /* 0x1B30C */ u8 pad1B30C[0x1B31C - 0x1B30C];
    /* 0x1B31C */ s32 f1B31C;
    /* 0x1B320 */ u8 pad1B320[0x1B40C - 0x1B320];
    /* 0x1B40C */ s32 f1B40C;
    /* 0x1B410 */ u8 pad1B410[0x1B450 - 0x1B410];
    /* 0x1B450 */ S5Simp simp[5];
    /* 0x1B4DC */ u8 pad1B4DC[0x1B614 - 0x1B4DC];
    /* 0x1B614 */ s32 f1B614;
    /* 0x1B618 */ s32 f1B618;
    /* 0x1B61C */ s32 f1B61C;
    /* 0x1B620 */ u8 pad1B620[0x1B660 - 0x1B620];
    /* 0x1B660 */ s32 f1B660;
    /* 0x1B664 */ u8 pad1B664[0x1B6A4 - 0x1B664];
    /* 0x1B6A4 */ s32 f1B6A4;
    /* 0x1B6A8 */ u8 pad1B6A8[4];
    /* 0x1B6AC */ s32 f1B6AC;
} S5Scene;

#endif
