#ifndef B19A_TYPES_H
#define B19A_TYPES_H

#include "common.h"

/* Types recovered for batch 19 leftovers (part A).  Names provisional. */

typedef struct B19aDl { u32 w0; u32 w1; } B19aDl;

/* box / cell record referenced by an entry (min x,z at 0/4, max x,z at 8/0xC) */
typedef struct B19aBox {
    /* 0x0 */ f32 x0;
    /* 0x4 */ f32 z0;
    /* 0x8 */ f32 x1;
    /* 0xC */ f32 z1;
} B19aBox;

/* 12 byte visible-cell entry at ow+0x1508 */
typedef struct B19aEnt {
    /* 0x0 */ s32 **pp;
    /* 0x4 */ B19aBox *box;
    /* 0x8 */ u16 a;
    /* 0xA */ u16 b;
} B19aEnt;

/* table {?, count, items...} returned by func_0028FD94 / stored at ow+0x94 */
typedef struct B19aTbl {
    /* 0x0 */ u8 pad0[4];
    /* 0x4 */ s32 cnt;
    /* 0x8 */ u16 ids[1];
} B19aTbl;

/* class info block pointed to by an object at +0x18 */
typedef struct B19aInfo {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u32 flags4;
    /* 0x08 */ u8 pad8[0xC];
    /* 0x14 */ u32 flags14;
} B19aInfo;

/* 0xE8 byte object (table 0 of a group) */
typedef struct B19aObjA {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u16 id;
    /* 0x06 */ u8 pad6[0x12];
    /* 0x18 */ B19aInfo *info;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ s32 **owner;
    /* 0x24 */ u8 pad24[0x94];
    /* 0xB8 */ f32 mn[3];
    /* 0xC4 */ f32 mx[3];
    /* 0xD0 */ u8 padD0[8];
    /* 0xD8 */ u16 flags;
    /* 0xDA */ u8 padDA[0xE8 - 0xDA];
} B19aObjA;

/* 0x1C8 byte object (table 1 of a group) */
typedef struct B19aObjB {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ B19aInfo *info;
    /* 0x01C */ u8 pad1C[0x44];
    /* 0x060 */ s32 **owner;
    /* 0x064 */ u8 pad64[0x118];
    /* 0x17C */ f32 mn[3];
    /* 0x188 */ f32 mx[3];
    /* 0x194 */ u8 pad194[8];
    /* 0x19C */ u16 flags;
    /* 0x19E */ u8 pad19E[0x22];
    /* 0x1C0 */ u32 mask;
    /* 0x1C4 */ u8 pad1C4[4];
} B19aObjB;

/* view / frustum block (arg1) */
typedef struct B19aView {
    /* 0x000 */ u8 pad0[0x64];
    /* 0x064 */ u32 mask;
    /* 0x068 */ u8 pad68[0x288];
    /* 0x2F0 */ u8 frustum[0x60];
    /* 0x350 */ f32 mn[3];
    /* 0x35C */ f32 mx[3];
} B19aView;

typedef struct B19aGlobal {
    /* 0x00 */ u32 mask;
    /* 0x04 */ u8 pad4[0x11];
    /* 0x15 */ u8 b15;
} B19aGlobal;

typedef struct B19aOwner {
    /* 0x0000 */ u8 pad0[0x94];
    /* 0x0094 */ B19aTbl *tbl94;
    /* 0x0098 */ u8 pad98[0xB4C - 0x98];
    /* 0x0B4C */ void *visA[0x40];
    /* 0x0C4C */ s32 nA;
    /* 0x0C50 */ u8 padC50[0x10BC - 0xC50];
    /* 0x10BC */ s32 nB;
    /* 0x10C0 */ void *visB[0x40];
    /* 0x11C0 */ u8 pad11C0[0x1504 - 0x11C0];
    /* 0x1504 */ s32 nent;
    /* 0x1508 */ B19aEnt ent[1];
    /* 0x1514 */ u8 pad1514[0x1B6B0 - 0x1514];
    /* 0x1B6B0 */ s32 *f1B6B0;
    /* 0x1B6B4 */ u8 pad1B6B4[0x1B928 - 0x1B6B4];
    /* 0x1B928 */ s32 f1B928;
} B19aOwner;

/* ---- func_00286A78 (level setup) ---- */
typedef struct B19aEntInfo {
    /* 0x00 */ s32 type;
    /* 0x04 */ u8 pad4[0x24];
    /* 0x28 */ s16 f28;
} B19aEntInfo;

/* 0x2E8 byte world entity */
typedef struct B19aEnt2E8 {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ B19aEntInfo *info;
    /* 0x01C */ u8 pad1C[0xC8];
    /* 0x0E4 */ u16 id;
    /* 0x0E6 */ u8 padE6[0x2E8 - 0xE6];
} B19aEnt2E8;

typedef struct B19aBrain {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 b10;
} B19aBrain;

typedef struct B19aStats {
    /* 0x00 */ u8 pad0[0x78];
    /* 0x78 */ u8 b78;
    /* 0x79 */ u8 pad79[7];
    /* 0x80 */ s8 b80;
    /* 0x81 */ u8 pad81[0x10];
    /* 0x91 */ u8 b91;
    /* 0x92 */ u8 pad92[2];
    /* 0x94 */ u8 b94;
} B19aStats;

typedef struct B19aActBrain {
    /* 0x0 */ u8 pad0[4];
    /* 0x4 */ s32 f4;
} B19aActBrain;

/* player-like actor (huge) */
typedef struct B19aActor B19aActor;
struct B19aActor {
    /* 0x0000 */ u8 pad0[0x5D8];
    /* 0x05D8 */ B19aStats *stats;
    /* 0x05DC */ u8 pad5DC[0x1454 - 0x5DC];
    /* 0x1454 */ B19aActBrain *brain;
    /* 0x1458 */ u8 pad1458[0x16E0 - 0x1458];
    /* 0x16E0 */ B19aActor *next;
};

typedef struct B19aGF {
    s32 pad0[0x98 / 4];
    s32 f98;
} B19aGF;

typedef struct B19aBox6 {
    s32 w[6];
} B19aBox6;

typedef struct B19aWorld {
    /* 0x0 */ s32 state;
    /* 0x4 */ u8 pad4[0x18];
    /* 0x1C */ s32 f1C;
    /* 0x20 */ u8 pad20[0x10];
    /* 0x30 */ s32 f30;
    /* 0x34 */ u8 pad34[0xC];
    /* 0x40 */ s32 f40;
    /* 0x44 */ u8 pad44[0x8];
    /* 0x4C */ s32 *p4C;
    /* 0x50 */ u8 pad50[0x10];
    /* 0x60 */ s32 *p60;
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 *f68;
    /* 0x6C */ s32 *f6C;
    /* 0x70 */ u8 pad70[0x1C];
    /* 0x8C */ s32 *p8C;
    /* 0x90 */ u8 pad90[0x24];
    /* 0xB4 */ s32 *pB4;
    /* 0xB8 */ s32 fB8;
    /* 0xBC */ s32 **fBC;
    /* 0xC0 */ s32 **fC0;
    /* 0xC4 */ s32 fC4;
    /* 0xC8 */ s32 **fC8;
    /* 0xCC */ s32 **fCC;
    /* 0xD0 */ s32 **fD0;
    /* 0xD4 */ s32 **fD4;
    /* 0xD8 */ u8 padD8[0x10];
    /* 0xE8 */ s32 *fE8;
    /* 0xEC */ s32 **fEC;
    /* 0xF0 */ s32 **fF0;
    /* 0xF4 */ s32 **fF4;
    /* 0xF8 */ u8 padF8[0x4];
    /* 0xFC */ s32 **fFC;
    /* 0x100 */ s32 f100;
    /* 0x104 */ u8 pad104[0x34];
    /* 0x138 */ B19aEnt2E8 *objs;
    /* 0x13C */ s32 f13C;
    /* 0x140 */ s32 nobjs;
    /* 0x144 */ u8 pad144[0x1B16C];
    /* 0x1B2B0 */ B19aBrain *f1B2B0;
    /* 0x1B2B4 */ u8 pad1B2B4[0x48];
    /* 0x1B2FC */ f32 f1B2FC;
    /* 0x1B300 */ void *f1B300;
    /* 0x1B304 */ s32 f1B304;
    /* 0x1B308 */ u8 pad1B308[0x100];
    /* 0x1B408 */ s32 f1B408;
    /* 0x1B40C */ s32 f1B40C;
    /* 0x1B410 */ u8 pad1B410[0xC];
    /* 0x1B41C */ s32 f1B41C;
    /* 0x1B420 */ u8 pad1B420[0x14];
    /* 0x1B434 */ s32 level;
    /* 0x1B438 */ u8 pad1B438[0xA4];
    /* 0x1B4DC */ void *f1B4DC;
    /* 0x1B4E0 */ s32 f1B4E0;
    /* 0x1B4E4 */ void *f1B4E4;
    /* 0x1B4E8 */ s32 f1B4E8;
    /* 0x1B4EC */ void *f1B4EC;
    /* 0x1B4F0 */ s32 f1B4F0;
    /* 0x1B4F4 */ u8 pad1B4F4[0x170];
    /* 0x1B664 */ B19aEnt2E8 *arr1B664[16];
    /* 0x1B6A4 */ s32 f1B6A4;
    /* 0x1B6A8 */ u8 pad1B6A8[0x4];
    /* 0x1B6AC */ s32 f1B6AC;
    /* 0x1B6B0 */ u8 pad1B6B0[0x260];
    /* 0x1B910 */ B19aBox6 box;
    /* 0x1B928 */ u8 pad1B928[0x4];
    /* 0x1B92C */ s32 f1B92C;
} B19aWorld;

#endif
