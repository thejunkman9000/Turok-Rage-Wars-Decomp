#ifndef B14_TYPES_H
#define B14_TYPES_H
#include "p1_types.h"

/* batch 14 (ROM 0x5FB54-0x66B20): small value types, provisional names */
typedef struct B14Vec3 { f32 x, y, z; } B14Vec3;
typedef struct B14W3 { s32 a, b, c; } B14W3;
typedef struct B14W4 { s32 a, b, c, d; } B14W4;

/* bit-stream reader: byte pointer + bit position */
typedef struct B14BitRd {
    /* 0x00 */ u8 *data;
    /* 0x04 */ s32 pos;
} B14BitRd;

/* input/pad-like object: bit flag words at 0xB4 (also read bytewise) and 0xC0 */
typedef struct B14Pad {
    /* 0x00 */ u8 pad0[0xB4];
    /* 0xB4 */ union { u32 w; u8 b[4]; } fB4;
    /* 0xB8 */ u8 padB8[8];
    /* 0xC0 */ u32 fC0;
} B14Pad;

/* bit-packed float field: n bits, scaled into [min, min+range] */
typedef struct B14FRange { u32 n; f32 min; f32 range; } B14FRange;
/* bit cursor + float field description (+0 bit address, +4 field) */
typedef struct B14FieldRd { u32 addr; B14FRange r; } B14FieldRd;

/* controller slot object, 0x224 bytes, 4 of them at D_8010F328 */
typedef struct B14Ent { u8 a, b, c, d; } B14Ent;
typedef struct B14Ctl {
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
    /* 0x02C */ B14Ent ent[32];
    /* 0x0AC */ s32 fAC;
    /* 0x0B0 */ s32 fB0;
    /* 0x0B4 */ s32 fB4;
    /* 0x0B8 */ s32 fB8;
    /* 0x0BC */ s32 fBC;
    /* 0x0C0 */ s32 fC0;
    /* 0x0C4 */ u8 fC4;
    /* 0x0C5 */ u8 fC5;
    /* 0x0C6 */ u8 fC6;
    /* 0x0C7 */ u8 fC7;
    /* 0x0C8 */ s32 fC8;
    /* 0x0CC */ s32 fCC;
    /* 0x0D0 */ union { s32 i; f32 f; } fD0;
    /* 0x0D4 */ union { s32 i; f32 f; } fD4;
    /* 0x0D8 */ OSPfs pfs;
    /* 0x140 */ u8 blkA[0x2C];
    /* 0x16C */ u8 blkB[0xB4];
    /* 0x220 */ s32 f220;
} B14Ctl;

/* 4 bytes per controller at D_8010FBE0 (byte 3 bit 3 = "not connected") */
typedef struct B14PortFlags { u8 b[4]; } B14PortFlags;

/* global player list header at D_80145040 (+4 = players base, +8 = count) */
typedef struct B14Game {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u8 *players;
    /* 0x08 */ s32 count;
} B14Game;

/* per-player snapshot tables at D_8010FC40 */
typedef struct B14Blk70 { s32 w[28]; } B14Blk70;
typedef struct B14Mgr {
    /* 0x000 */ s32 a;
    /* 0x004 */ s32 b;
    /* 0x008 */ s32 c;
    /* 0x00C */ s32 d;
    /* 0x010 */ B14Blk70 blk[4];
    /* 0x1D0 */ u8 pad1D0[0x1C0];
    /* 0x390 */ B14W3 w[4];
    /* 0x3C0 */ u8 pad3C0[0x30];
    /* 0x3F0 */ f32 f3F0[4];
    /* 0x400 */ u8 pad400[0x10];
    /* 0x410 */ s32 i410[4];
} B14Mgr;

/* keyframe track decoder state (bit-packed channel with cubic segment cache) */
typedef struct B14Trk {
    /* 0x00 */ s32 bits;
    /* 0x04 */ f32 base;
    /* 0x08 */ f32 range;
    /* 0x0C */ u32 data;     /* bit address of the segment records */
    /* 0x10 */ f32 c0;
    /* 0x14 */ f32 c1;
    /* 0x18 */ f32 c2;
    /* 0x1C */ f32 c3;
    /* 0x20 */ u32 span;
    /* 0x24 */ u32 start;
    /* 0x28 */ s32 cur;
    /* 0x2C */ s32 f2C;
} B14Trk;
#endif
