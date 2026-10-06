#ifndef B22_TYPES_H
#define B22_TYPES_H
#include "p1_types.h"

/* Sound-system object (batch 22): stack of "sound contexts" with 0x1C byte entries */
typedef struct SndCtx SndCtx;
struct SndCtx {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ SndCtx *child1;
    /* 0x08 */ SndCtx *child2;
    /* 0x0C */ s16 id;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[2];
    /* 0x12 */ u16 flags12;
    /* 0x14 */ u8 pad14[0x28];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
};

typedef struct SndStkEnt {
    /* 0x00 */ SndCtx *ctx;
    /* 0x04 */ s32 id;
    /* 0x08 */ SndCtx *unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
} SndStkEnt;

typedef struct SndCacheEnt {
    /* 0x00 */ s32 id;
    /* 0x04 */ SndCtx *ctx;
    /* 0x08 */ s32 unk8;
} SndCacheEnt;

typedef struct SndSlot {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} SndSlot;

/* global sound manager pointed to by D_8014D080 (0x544 bytes) */
typedef struct SndMgr {
    /* 0x000 */ s32 (*fn0)();
    /* 0x004 */ s32 top;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ SndStkEnt *stk;
    /* 0x010 */ s32 (*fn10)();
    /* 0x014 */ s32 unk14;
    /* 0x018 */ s32 unk18;
    /* 0x01C */ SndSlot slot[64];
    /* 0x51C */ u8 pad51C[4];
    /* 0x520 */ s32 unk520;
    /* 0x524 */ s32 unk524;
    /* 0x528 */ s32 unk528;
    /* 0x52C */ s32 unk52C;
    /* 0x530 */ s32 unk530;
    /* 0x534 */ s32 unk534;
    /* 0x538 */ s32 unk538;
    /* 0x53C */ SndCacheEnt *unk53C;
    /* 0x540 */ s32 unk540;
} SndMgr;

/* growable byte buffer used by the sound code (0x10 bytes) */
typedef struct B22Viewport {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ f32 sx;
    /* 0x10 */ f32 sy;
    /* 0x14 */ u8 alpha;
    /* 0x18 */ s32 x2;
    /* 0x1C */ s32 w;
    /* 0x20 */ s32 y2;
    /* 0x24 */ s32 h;
} B22Viewport;

typedef struct B22Buf {
    /* 0x00 */ u8 *data;
    /* 0x04 */ s32 size;
    /* 0x08 */ s32 rdpos;
    /* 0x0C */ s32 wrpos;
} B22Buf;

typedef struct SndMsg SndMsg;
typedef s32 (*SndMsgFn)(SndMsg *);

/* per-channel control entry (12 bytes): current and next values */
typedef struct SndCtl {
    /* 0x00 */ s16 cur0;
    /* 0x02 */ s16 cur1;
    /* 0x04 */ s16 cur2;
    /* 0x06 */ s16 nxt0;
    /* 0x08 */ s16 nxt1;
    /* 0x0A */ s16 nxt2;
} SndCtl;

/* block pointed to by D_8014D0B0 (0xC44 bytes) */
typedef struct SndAux {
    /* 0x000 */ SndMsgFn fn0;
    /* 0x004 */ SndCtl ctl[16][16];
    /* 0xC04 */ u8 tbl[16][4];
} SndAux;

/* message built on the stack and handed to func_0029B558 */
struct SndMsg {
    /* 0x00 */ s16 type;
    /* 0x02 */ u16 a;
    /* 0x04 */ s16 b;
    /* 0x06 */ s16 c;
    /* 0x08 */ s32 d;
    /* 0x0C */ s16 e;
    /* 0x0E */ s16 f;
    /* 0x10 */ s16 g;
    /* 0x12 */ s16 h;
};

/* controller state object (func_0029B650) */
typedef struct B22Pad {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 ch;
    /* 0x05 */ u8 pad5[0xA7];
    /* 0xAC */ s32 prev;
    /* 0xB0 */ s32 cur;
    /* 0xB4 */ u8 padB4[0x10];
    /* 0xC4 */ s8 unkC4;
    /* 0xC5 */ s8 unkC5;
} B22Pad;

typedef struct B22Mtx { f32 m[4][4]; } B22Mtx;

float sqrtf(float);

/* guarded sqrt used by the vector helpers (inlined by the compiler) */
static inline float B22Sqrt(float x)
{
    if (x <= 0.0f) {
        return 0.0f;
    }
    return sqrtf(x);
}

#endif
