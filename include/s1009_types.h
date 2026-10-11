#ifndef S1009_TYPES_H
#define S1009_TYPES_H
#include "common.h"

/* Overlay A, menu/options module (ROM 0x1ABF84..0x1ACD5C, VRAM 0x43DF84..0x43ED5C), workspace s1009.
 * 41 small callbacks of an options / controller-select menu: item text callbacks (item, menu), button handlers
 * (menu), init helpers.  Names are provisional. */

/* controller record, D_8010F328[4], stride 0x224: word 0 = connected, +4 = port number */
typedef struct S10Ctrl {
    /* 0x00 */ s32 active;
    /* 0x04 */ s8 port;
    /* 0x05 */ u8 pad5[0x224 - 5];
} S10Ctrl;

/* record behind ctx->sub (ctx + 0x5D8) */
typedef struct S10Sub {
    /* 0x00 */ u8 pad0[0x7B];
    /* 0x7B */ s8 b7B;
    /* 0x7C */ u8 pad7C[4];
    /* 0x80 */ s8 b80;
    /* 0x81 */ u8 pad81[2];
    /* 0x83 */ u8 b83;
} S10Sub;

/* menu context (menu + 0x1C) */
typedef struct S10Ctx {
    /* 0x000 */ u8 pad0[0x5D4];
    /* 0x5D4 */ s32 f5D4;
    /* 0x5D8 */ S10Sub *sub;
    /* 0x5DC */ u8 *f5DC;
    /* 0x5E0 */ s32 f5E0;
    /* 0x5E4 */ u8 pad5E4[0x698 - 0x5E4];
    /* 0x698 */ s32 f698;
    /* 0x69C */ u8 pad69C[0x858 - 0x69C];
    /* 0x858 */ s32 f858;
    /* 0x85C */ s32 f85C;
} S10Ctx;

/* object with a flag word at +0x58 (menu->fC) */
typedef struct S10Flags {
    /* 0x00 */ u8 pad0[0x58];
    /* 0x58 */ u32 flags;
} S10Flags;

/* menu (second argument of the callbacks) */
typedef struct S10Menu {
    /* 0x00 */ s16 state;
    /* 0x02 */ u8 pad2[0xA];
    /* 0x0C */ S10Flags *fC;
    /* 0x10 */ u8 pad10[0xC];
    /* 0x1C */ S10Ctx *ctx;
    /* 0x20 */ S10Ctrl *ctrl;
} S10Menu;

/* menu item (first argument of the text callbacks): +0x14 = text */
typedef struct S10Item {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ void *f14;
} S10Item;

/* global game-mode block D_801468A0 (= D_801462C8 + 0x5D8) */
typedef struct S10Game {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C[5];
    /* 0x40 */ s32 unk40[5];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ u8 pad58[0x6C - 0x58];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x78 - 0x70];
    /* 0x78 */ s32 unk78;
    /* 0x7C */ u8 pad7C[4];
    /* 0x80 */ s32 unk80;
} S10Game;

/* record of the player/controller table inside D_801462C8 (stride 0x96, first one at +0x148) */
typedef struct S10Rec {
    /* 0x00 */ u8 b0;
    /* 0x01 */ u8 pad1[7];
    /* 0x08 */ u8 b8;
    /* 0x09 */ u8 pad9[0x96 - 9];
} S10Rec;

/* options block D_801462C8 */
typedef struct S10State {
    /* 0x00 */ u8 pad0[0x1D];
    /* 0x1D */ u8 b1D;
    /* 0x1E */ u8 b1E;
    /* 0x1F */ u8 pad1F[0x2D - 0x1F];
    /* 0x2D */ u8 b2D;
    /* 0x2E */ u8 b2E;
    /* 0x2F */ u8 b2F;
    /* 0x30 */ u8 b30;
    /* 0x31 */ u8 b31;
    /* 0x32 */ u8 b32;
    /* 0x33 */ u8 b33;
    /* 0x34 */ u8 b34;
    /* 0x35 */ u8 b35;
    /* 0x36 */ u8 pad36[0x148 - 0x36];
    /* 0x148 */ S10Rec rec[8];
} S10State;

/* 0x96-byte rows at D_80146398 (and D_80146302 = one row earlier): selected-controller flag and index */
typedef struct S10Row {
    /* 0x00 */ u8 pad0[0x78];
    /* 0x78 */ u8 b78;
    /* 0x79 */ u8 pad79[6];
    /* 0x7F */ u8 b7F;
    /* 0x80 */ u8 pad80[0x96 - 0x80];
} S10Row;

/* 4-byte table entries at D_800E5DFA (s16 at +0) */
typedef struct S10Pair {
    /* 0x00 */ s16 v;
    /* 0x02 */ s16 w;
} S10Pair;

/* message / event record (first word = code) */
typedef struct S10Msg {
    /* 0x00 */ s32 code;
} S10Msg;

#endif
