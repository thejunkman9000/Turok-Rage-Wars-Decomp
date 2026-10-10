#ifndef Q03_TYPES_H
#define Q03_TYPES_H
#include "common.h"
#include "o05_types.h"

/* round-3 overlay A types (workspace q03). */

/* one 0x96-byte player/lobby record of D_801462C8 (8 entries at +0xD0) */
typedef struct Q03Ent {
    /* 0x00 */ s16 f0;
    /* 0x02 */ s16 f2;
    /* 0x04 */ s16 f4;
    /* 0x06 */ s16 f6;
    /* 0x08 */ s16 f8;
    /* 0x0A */ u8 padA[0x78 - 0xA];
    /* 0x78 */ u8 f78;
    /* 0x79 */ u8 f79;
    /* 0x7A */ u8 f7A;
    /* 0x7B */ u8 f7B;
    /* 0x7C */ u8 f7C;
    /* 0x7D */ u8 f7D;
    /* 0x7E */ u8 f7E;
    /* 0x7F */ u8 f7F;
    /* 0x80 */ s8 f80;
    /* 0x81 */ s8 f81;
    /* 0x82 */ u8 f82;
    /* 0x83 */ u8 f83;
    /* 0x84 */ char name[0xD];
    /* 0x91 */ u8 f91;
    /* 0x92 */ u8 f92;
    /* 0x93 */ u8 f93;
    /* 0x94 */ u8 f94;
    /* 0x95 */ u8 f95;
} Q03Ent;

/* D_801462C8: configuration / lobby block of the main image */
typedef struct Q03Cfg {
    /* 0x000 */ u8 pad0[0xD];
    /* 0x00D */ u8 unkD;
    /* 0x00E */ u8 pad0E[0x1D - 0x0E];
    /* 0x01D */ u8 unk1D;
    /* 0x01E */ u8 unk1E;
    /* 0x01F */ u8 pad1F[0x24 - 0x1F];
    /* 0x024 */ s8 s24;
    /* 0x025 */ s8 s25;
    /* 0x026 */ u8 pad26[0xD0 - 0x26];
    /* 0x0D0 */ Q03Ent ent[8];
    /* 0x580 */ u8 unk580;
    /* 0x581 */ u8 pad581[0x680 - 0x581];
    /* 0x680 */ s32 unk680;
} Q03Cfg;

/* generic widget header used by the list/menu builders: byte 0x10 = alpha, 0x2C / 0x38 = value / text pointer */
typedef struct Q03Wid {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x2C - 0x11];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x38 - 0x30];
    /* 0x38 */ void *unk38;
} Q03Wid;

/* D_800E4F60: state block of the "options" mode (overlay A, 0x42A..); same shape as O04ModeS4690 shifted by 0x5AC */
typedef struct Q03H14 { u8 pad0[0x10]; u8 unk10; u8 pad11[3]; u16 unk14; u8 pad16[2]; s16 unk18; } Q03H14;
typedef union Q03W { s32 w; struct { u16 h0; u16 h1; } h; } Q03W;
typedef struct Q03F60 {
    /* 0x000 */ void *unk0;
    /* 0x004 */ u8 pad4[0x308 - 0x4];
    /* 0x308 */ u8 unk308[0x4C];
    /* 0x354 */ u8 pad354[0x3C8 - 0x354];
    /* 0x3C8 */ void *unk3C8;
    /* 0x3CC */ Q03H14 *unk3CC;
    /* 0x3D0 */ Q03W u3D0;
    /* 0x3D4 */ Q03H14 *unk3D4;
    /* 0x3D8 */ Q03W u3D8;
    /* 0x3DC */ s32 state;
    /* 0x3E0 */ s32 unk3E0;
    /* 0x3E4 */ void *unk3E4;
    /* 0x3E8 */ void *unk3E8;
    /* 0x3EC */ void *unk3EC;
    /* 0x3F0 */ void *unk3F0;
    /* 0x3F4 */ char unk3F4[0x40];
    /* 0x434 */ s32 unk434;
    /* 0x438 */ s32 unk438;
    /* 0x43C */ Q03H14 *unk43C;
    /* 0x440 */ void *unk440;
    /* 0x444 */ void *unk444;
    /* 0x448 */ Q03H14 *unk448;
    /* 0x44C */ Q03H14 *unk44C;
    /* 0x450 */ Q03H14 *unk450;
    /* 0x454 */ Q03H14 *unk454;
    /* 0x458 */ void *unk458;
    /* 0x45C */ s32 unk45C;
    /* 0x460 */ s32 unk460;
    /* 0x464 */ s32 unk464;
    /* 0x468 */ s32 unk468;
    /* 0x46C */ s32 unk46C;
} Q03F60;

/* D_800E53C0: state of the first lobby/menu mode (overlay A 0x42BD40..) */
typedef struct Q03S53 {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ s32 unk1C;
    /* 0x020 */ u8 unk20[0xE0 - 0x20];
    /* 0x0E0 */ s32 unkE0;
    /* 0x0E4 */ void *unkE4;
    /* 0x0E8 */ s32 unkE8;
    /* 0x0EC */ s32 unkEC;
    /* 0x0F0 */ s32 unkF0[8];
    /* 0x110 */ struct { s32 a; s32 b; } unk110[8];
    /* 0x150 */ char strA[4][0x19];
    /* 0x1B4 */ char strB[4][0x19];
    /* 0x218 */ char strC[4][0x19];
    /* 0x27C */ char strD[4][0x19];
    /* 0x2E0 */ char unk2E0[0x40];
    /* 0x320 */ s32 unk320;
    /* 0x324 */ s32 unk324;
    /* 0x328 */ s32 unk328;
    /* 0x32C */ s32 unk32C;
} Q03S53;

/* 0x28-byte slot records at D_800E5322 (u16 widget ids at +0,+4,..,+0x20,+0x24) */
typedef struct Q03Slot {
    /* 0x00 */ u16 id0; u16 p2;
    /* 0x04 */ u16 id4; u16 p6;
    /* 0x08 */ u16 id8; u16 pA;
    /* 0x0C */ u16 idC; u16 pE;
    /* 0x10 */ u16 id10; u16 p12;
    /* 0x14 */ u16 id14; u16 p16;
    /* 0x18 */ u16 id18; u16 p1A;
    /* 0x1C */ u16 id1C; u16 p1E;
    /* 0x20 */ u16 id20; u16 p22;
    /* 0x24 */ u16 id24; u16 p26;
} Q03Slot;


/* lobby constructor (func_0042F12C): widget seen through unsigned halfword fields / signed halfword fields */
typedef struct Q03WdU { u8 pad0[0x10]; u8 b10; u8 pad11[3]; u16 u14; u16 pad16; union { u16 u; s16 s; } w18; } Q03WdU;
typedef Q03WdU Q03WdS;

typedef struct Q03Hdr {
    /* 0x00 */ void *f0;
    /* 0x04 */ void *f4;
    /* 0x08 */ u8 blk8[0x24 - 8];
    /* 0x24 */ void *f24;
    /* 0x28 */ void *f28;
    /* 0x2C */ s32 w2C[4];
    /* 0x3C */ Q03WdS *f3C;
    /* 0x40 */ s32 f40;
    /* 0x44 */ Q03WdS *f44;
    /* 0x48 */ s32 f48;
    /* 0x4C */ s32 f4C;
    /* 0x50 */ s32 f50;
    /* 0x54 */ s32 f54;
} Q03Hdr;
/* D_800E54A4 as used by the lobby constructor (same block as O05Lobby) */
typedef struct Q03Lob {
    Q03Hdr h;
    O05Plr plr[4];
    O05Slot slot[4];
    u8 pad2E28[0x3470 - 0x2E28];
    s32 f3470;
} Q03Lob;

#endif
