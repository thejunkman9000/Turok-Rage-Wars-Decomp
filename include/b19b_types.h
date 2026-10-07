#ifndef B19B_TYPES_H
#define B19B_TYPES_H
#include "common.h"

/* context object used by the level loader / classifier code (batch 19b) */
typedef struct B19bCtx {
    /* 0x0 */ u8 pad0[0x24];
    /* 0x24 */ s32 f24;
    /* 0x28 */ u8 pad28[0x2C];
    /* 0x54 */ s32 f54;
    /* 0x58 */ u8 pad58[0x14];
    /* 0x6C */ s32 *f6C;
    /* 0x70 */ u8 pad70[0x10];
    /* 0x80 */ s32 *root;
    /* 0x84 */ u8 pad84[0x1B22C];
    /* 0x1B2B0 */ f32 *fl;
    /* 0x1B2B4 */ u8 pad1B2B4[0x158];
    /* 0x1B40C */ s32 key;
} B19bCtx;

/* generic table header returned by func_0028FD94: count at +4, entries from +8 */
typedef struct B19bTab {
    /* 0x0 */ s32 f0;
    /* 0x4 */ s32 cnt;
    /* 0x8 */ u8 ent[1];
} B19bTab;

/* output blob: directory of 5 section offsets at +4, section headers {stride,count} */
typedef struct B19bBlob {
    /* 0x0 */ s32 n;
    /* 0x4 */ s32 off[5];
} B19bBlob;

typedef struct B19bSec {
    /* 0x0 */ s32 stride;
    /* 0x4 */ s32 cnt;
} B19bSec;

/* source table entries (stride) and output item records */
typedef struct B19bSrcA { u8 pad0[8]; u16 f8; u8 padA[0x12]; } B19bSrcA;           /* 0x1C */
typedef struct B19bSrcB { u8 pad0[0x28]; u16 f28; u8 pad2A[0xA]; } B19bSrcB;       /* 0x34 */
typedef struct B19bSrcC { u8 pad0[0x14]; u16 f14; u8 pad16[0xA]; } B19bSrcC;       /* 0x20 */
typedef struct B19bSrcD { u8 pad0[0x4C]; } B19bSrcD;                               /* 0x4C */
typedef struct B19bItemE { u8 pad0[0xE8]; } B19bItemE;                             /* 0xE8 */
typedef struct B19bItemC {
    /* 0x0 */ u8 pad0[8];
    /* 0x8 */ f32 f8;
    /* 0xC */ f32 fC;
    /* 0x10 */ f32 f10;
    /* 0x14 */ u8 pad14[0x188];
    /* 0x19C */ u16 f19C;
    /* 0x19E */ u16 f19E;
    /* 0x1A0 */ u8 pad1A0[0x8];
    /* 0x1A8 */ u8 f1A8[0x20];
} B19bItemC;                                                                        /* 0x1C8 */
typedef struct B19bItemD { u8 pad0[0xC0]; } B19bItemD;                             /* 0xC0 */


/* classifier: object (stride 0x2E8) and world container */
typedef struct B19bInfo { s32 kind; u32 flags; } B19bInfo;
typedef struct B19bObj {
    /* 0x0 */ u8 pad0[0x18];
    /* 0x18 */ B19bInfo *info;
    /* 0x1C */ u8 pad1C[0xC8];
    /* 0xE4 */ u16 id;
    /* 0xE6 */ u8 padE6[2];
    /* 0xE8 */ f32 fE8;
    /* 0xEC */ f32 fEC;
    /* 0xF0 */ f32 fF0;
    /* 0xF4 */ f32 fF4;
    /* 0xF8 */ f32 fF8;
    /* 0xFC */ f32 fFC;
    /* 0x100 */ s32 flags;
    /* 0x104 */ u8 pad104[0xB];
    /* 0x10F */ s8 f10F;
    /* 0x110 */ u8 pad110[0x12E];
    /* 0x23E */ s8 idx;
    /* 0x23F */ u8 pad23F[0xA9];
} B19bObj;                                                                          /* 0x2E8 */

typedef struct B19bWorld {
    /* 0x0 */ u8 pad0[0x138];
    /* 0x138 */ B19bObj *objs;
    /* 0x13C */ s32 first;
    /* 0x140 */ s32 count;
    /* 0x144 */ B19bObj *l0[0x200];
    /* 0x944 */ s32 n0;
    /* 0x948 */ B19bObj *l1[0x80];
    /* 0xB48 */ s32 n1;
    /* 0xB4C */ u8 padB4C[0x104];
    /* 0xC50 */ B19bObj *l2[0x80];
    /* 0xE50 */ s32 n2;
    /* 0xE54 */ B19bObj *l3[0x40];
    /* 0xF54 */ s32 n3;
    /* 0xF58 */ s32 cur3;
    /* 0xF5C */ B19bObj *l4[0x20];
    /* 0xFDC */ s32 n4;
    /* 0xFE0 */ B19bObj *l5[0x10];
    /* 0x1020 */ s32 n5;
    /* 0x1024 */ B19bObj *l6[0x20];
    /* 0x10A4 */ s32 n6;
    /* 0x10A8 */ B19bObj *l7[4];
    /* 0x10B8 */ s32 n7;
    /* 0x10BC */ u8 pad10BC[0x4];
    /* 0x10C0 */ u8 pad10C0[0x1A348];
    /* 0x1B408 */ s32 f1B408;
} B19bWorld;


/* global at D_801462D0 (mask word and a flag byte; code also reaches back -0x1290 / -0x1228 from it) */
typedef struct B19bG0 {
    /* 0x0 */ s32 mask;
    /* 0x4 */ u8 pad4[0x11];
    /* 0x15 */ u8 f15;
} B19bG0;


/* level container used by the level builder (func_00288908) */
typedef struct B19bLvl {
    /* 0x0 */ u8 pad0[0x30];
    /* 0x30 */ s32 f30;
    /* 0x34 */ u8 pad34[0x30];
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 *root;
    /* 0x6C */ u8 pad6C[0x1C];
    /* 0x88 */ s32 *blob;
    /* 0x8C */ u8 pad8C[0x6C];
    /* 0xF8 */ s32 **hp;
    /* 0xFC */ u8 padFC[0x1B200];
    /* 0x1B2FC */ f32 minY;
} B19bLvl;

typedef struct B19bDl { u32 w0; u32 w1; } B19bDl;
typedef struct B19bE14 { u8 pad0[0x10]; s32 f10; } B19bE14;                  /* 0x14 */
typedef struct B19bEnt {                                                     /* 0xE8 */
    /* 0x0 */ u8 pad0[0x20];
    /* 0x20 */ void *f20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ u8 f28[0xB0];
    /* 0xD8 */ u16 fD8;
    /* 0xDA */ u8 padDA[0xE];
} B19bEnt;
typedef struct B19bV3s { s16 x, y, z; } B19bV3s;
typedef struct B19bV3f { f32 x, y, z; } B19bV3f;

#endif
