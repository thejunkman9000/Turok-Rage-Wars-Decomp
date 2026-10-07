#ifndef O05_TYPES_H
#define O05_TYPES_H
#include "common.h"

/* Overlay A (menu / lobby mode code, ROM 0x16E000..), workspace o05.
 *
 * D_800E54A4 points at the lobby block ("O05Lobby"):
 *   0x0000..0x0057  header (O05Hdr)
 *   0x0058          4 player records (O05Plr), stride 0xB68
 *   0x2DF8          4 slots of 12 bytes {player, record, flag}
 *   0x2E28          0x640 bytes: copy of the four 0x190-byte records (same layout as D_80102B00[])
 */
typedef struct O05Vec3 { f32 x, y, z; } O05Vec3;

typedef struct O05Slot { s32 a, b, c; } O05Slot;

/* 0x190-byte records at D_80102B00; also embedded in each player record (4 of them at +0x18) */
typedef struct O05Rec {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s32 w8;
    /* 0x0C */ s8 bC;
    /* 0x0D */ s8 bD;
    /* 0x0E */ s8 bE;
    /* 0x0F */ u8 padF[0x189 - 0xF];
    /* 0x189 */ s8 b189;
    /* 0x18A */ u8 b18A;
    /* 0x18B */ u8 b18B;
    /* 0x18C */ u8 b18C;
    /* 0x18D */ u8 b18D;
    /* 0x18E */ u8 pad18E[2];
} O05Rec;

/* 150-byte records at D_80146410 */
typedef struct O05R150 {
    /* 0x00 */ u8 b0;
    /* 0x01 */ u8 pad1[6];
    /* 0x07 */ u8 b7;
    /* 0x08 */ u8 pad8[0x19 - 8];
    /* 0x19 */ u8 b19;
    /* 0x1A */ u8 pad1A[0x96 - 0x1A];
} O05R150;

/* 70-byte list entries inside a player record (at +0x658) */
typedef struct O05Item {
    u8 b[0x46];
} O05Item;

/* widget attached to a list row */
typedef struct O05ItemWd {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[0x38 - 0x11];
    void *f38;
} O05ItemWd;

typedef struct O05Plr {
    /* 0x000 */ s32 state;
    /* 0x004 */ s32 f4;
    /* 0x008 */ s32 f8;
    /* 0x00C */ void *fC;
    /* 0x010 */ void *f10;
    /* 0x014 */ s32 f14;
    /* 0x018 */ O05Rec rec[4];
    /* 0x658 */ O05Item items[16];
    /* 0xAB8 */ u8 padAB8[0xAD8 - 0xAB8];
    /* 0xAD8 */ s32 scroll;
    /* 0xADC */ s32 cur;
    /* 0xAE0 */ O05ItemWd *wd[3];
    /* 0xAEC */ s32 fAEC;
    /* 0xAF0 */ s32 tabAF0[4];
    /* 0xB00 */ O05ItemWd *wdB00[4];
    /* 0xB10 */ u8 padB10[0xB28 - 0xB10];
    /* 0xB28 */ s32 fB28;
    /* 0xB2C */ u8 padB2C[4];
    /* 0xB30 */ s32 fB30;
    /* 0xB34 */ u8 name[0xB44 - 0xB34];
    /* 0xB44 */ s32 fB44;
    /* 0xB48 */ s32 fB48;
    /* 0xB4C */ s32 fB4C;
    /* 0xB50 */ u8 padB50[0xB64 - 0xB50];
    /* 0xB64 */ s32 fB64;
} O05Plr;

/* header fields */
typedef struct O05Hdr {
    /* 0x00 */ void *f0;
    /* 0x04 */ void *f4;
    /* 0x08 */ u8 blk8[0x24 - 8];
    /* 0x24 */ void *f24;
    /* 0x28 */ void *f28;
    /* 0x2C */ s32 w2C[4];
    /* 0x3C */ void *f3C;
    /* 0x40 */ u8 pad40[2];
    /* 0x42 */ u16 h42;
    /* 0x44 */ void *f44;
    /* 0x48 */ u8 pad48[2];
    /* 0x4A */ u16 h4A;
    /* 0x4C */ s32 f4C;
    /* 0x50 */ s32 f50;
    /* 0x54 */ s32 f54;
} O05Hdr;

/* D_800E54A4: lobby / setup block */
typedef struct O05Lobby {
    O05Hdr h;
    O05Plr plr[4];
    O05Slot slot[4];
    /* 0x2E28 */ O05Rec recs[4];
    /* 0x3468 */ s32 f3468;
    /* 0x346C */ s32 f346C;
    /* 0x3470 */ s32 f3470;
} O05Lobby;

/* slot at lobby + i*12 (the pointer is advanced by 12 bytes per entry, then the 0x2DF8 field offset is folded) */
typedef struct O05SlotAt { u8 pad[0x2DF8]; O05Slot s; } O05SlotAt;
#define O05_SLOT(lobby, i) (((O05SlotAt *)((u8 *)(lobby) + (i) * 12))->s)

/* dispatch table entry (12 bytes) */
typedef struct O05Disp {
    s32 id;
    s32 key;
    s32 (*fn)();
} O05Disp;


/* D_800E59E0: second menu block: header {f0, f4}, 4 rows of 0x4D0 bytes at +8, footer fields past 0x1348 */
typedef struct O05Row2 {
    /* 0x000 */ u8 pad0[0x4A8];
    /* 0x4A8 */ s32 f4A8;
    /* 0x4AC */ s32 f4AC;
    /* 0x4B0 */ s32 tab4B0[6];
    /* 0x4C8 */ void *f4C8;
    /* 0x4CC */ s32 f4CC;
    /* 0x4D0 */
} O05Row2;
typedef struct O05L2 {
    /* 0x0000 */ void *f0;
    /* 0x0004 */ void *f4;
    /* 0x0008 */ O05Row2 row[4];
    /* 0x1348 */ void *f1348;
    /* 0x134C */ u8 pad134C[2];
    /* 0x134E */ u16 h134E;
    /* 0x1350 */ void *f1350;
    /* 0x1354 */ u8 pad1354[2];
    /* 0x1356 */ u16 h1356;
    /* 0x1358 */ s32 f1358;
    /* 0x135C */ s32 f135C;
    /* 0x1360 */ void *f1360;
    /* 0x1364 */ void *f1364;
    /* 0x1368 */ s32 f1368;
} O05L2;


/* D_801462C8: global game state block; the 150-byte records D_80146410[] live at +0x148, the mode byte D_801462D5 at +0xD,
 * D_801462E0/E1 at +0x18/+0x19, two flag bytes at +0x24/+0x25, D_80146398 is +0xD0 */
typedef struct O05GameState {
    /* 0x000 */ u8 pad0[0xD];
    /* 0x00D */ u8 mode;
    /* 0x00E */ u8 pad0E[0x24 - 0xE];
    /* 0x024 */ u8 f24;
    /* 0x025 */ u8 f25;
    /* 0x026 */ u8 pad26[0x148 - 0x26];
    /* 0x148 */ O05R150 rec[8];
} O05GameState;

#endif
