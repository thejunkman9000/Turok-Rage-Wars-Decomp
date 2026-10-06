#ifndef B23_TYPES_H
#define B23_TYPES_H

#include "p1_types.h"

/* 4x4 row-major float matrix (rows 0x10 apart; translation in row 3) */
typedef struct Mtx4f {
    f32 m[4][4];
} Mtx4f;

/* simple message box: queue followed by a one-slot message buffer */
typedef struct MsgBox {
    OSMesgQueue q;
    OSMesg msg;
} MsgBox;

/* pool of 16-byte entries embedded in a big object (cnt at +0x2588, cursor at +0x258C) */
typedef struct EntPool {
    /* 0x0000 */ s32 unk0;
    /* 0x0004 */ u8 pad4[0x2584];
    /* 0x2588 */ s32 cnt;
    /* 0x258C */ u8 *cur;
} EntPool;

/* node of a list hanging off StateObj.list (next at +4, type at +0xE, value at +0x10) */
typedef struct SubNode SubNode;
struct SubNode {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ SubNode *next;
    /* 0x08 */ u8 pad8[6];
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 unk10;
};

/* object with a small state machine (state at +0x5C, counter at +0x48, node list at +8) */
typedef struct StateObj {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ SubNode *list;
    /* 0x0C */ u8 padC[0x3C];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ u8 pad4C[0x10];
    /* 0x5C */ s32 unk5C;
} StateObj;

/* running value with min / max (3 words) */
typedef struct MinMaxF {
    f32 cur;
    f32 lo;
    f32 hi;
} MinMaxF;

/* animation-like object: frame range in 0x4C/0x50, mode at 0x54, current at 0x58, text buffer at 0x60 */
typedef struct AnimObj {
    /* 0x00 */ u8 pad0[0x4C];
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 pad5C[4];
    /* 0x60 */ char buf[1];
} AnimObj;

/* stream-like buffer object at D_800D2BB0 (buffer, position, size, ?, open flag) */
typedef struct StreamBuf {
    u8 *buf;
    s32 pos;
    s32 size;
    s32 unkC;
    s32 open;
} StreamBuf;

/* dispatch table entry (key, value, handler) */
typedef struct DispEnt {
    s32 key;
    s32 val;
    s32 (*fn)();
} DispEnt;

/* add a delta to a MinMaxF, clamp the current value into [lim0, lim1] and widen its lo/hi range */
#define MM_UPDATE(m, delta, lim0, lim1)     (m).cur = (m).cur + (delta);     if ((m).cur < (lim0)) {         (m).cur = (lim0);     }     if ((m).cur > (lim1)) {         (m).cur = (lim1);     }     if ((m).cur < (m).lo) {         (m).lo = (m).cur;     }     if ((m).hi < (m).cur) {         (m).hi = (m).cur;     }

typedef struct Blk16 {
    s32 w[4];
} Blk16;

/* ---- slot / entry objects of the spline-like "trail" system (owner + 0x7528 list) ---- */
typedef struct SEnt SEnt;
typedef struct SSlot SSlot;

typedef struct SShape {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ f32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0xC];
    /* 0x1C */ u8 unk1C;
} SShape;

struct SEnt {
    /* 0x00 */ SEnt *prev;
    /* 0x04 */ SEnt *next;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ u8 m10[0xC];
    /* 0x1C */ u8 m1C[0xC];
    /* 0x28 */ u8 m28[2][0x40];
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ void *unkB0;
};

struct SSlot {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ SSlot *next;
    /* 0x08 */ SShape *shape;
    /* 0x0C */ u8 padC[0x10];
    /* 0x1C */ void *owner;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[4];
    /* 0x3C */ u32 flags;
    /* 0x40 */ SEnt *list;
    /* 0x44 */ u8 pad44[4];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ f32 unk4C;
    /* 0x50 */ s32 unk50;
};

#endif
