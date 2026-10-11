#ifndef S1011_TYPES_H
#define S1011_TYPES_H

#include "common.h"

/* Overlay A, player/actor object module (ROM 0x1B7970..0x1B8178): the object is a big struct (>= 0x1458 bytes) whose
   fields are only known from their use; unknown parts are padding.  The nested records are likewise partial. */

typedef struct S11Quad { s32 w[4]; } S11Quad;

typedef struct S11Cfg {                 /* record at obj->0x18 */
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u32 flags;
    /* 0x008 */ u8 pad8[0xFC - 8];
    /* 0x0FC */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ f32 unk104;
} S11Cfg;

typedef struct S11Rec {                 /* record at obj->0x5D8 */
    /* 0x00 */ u16 h0;
    /* 0x02 */ u16 h2;
    /* 0x04 */ u16 h4;
    /* 0x06 */ u16 h6;
    /* 0x08 */ u16 h8;
    /* 0x0A */ u16 hA;
    /* 0x0C */ u16 a0C[8];
    /* 0x1C */ u16 a1C[8];
    /* 0x2C */ u16 a2C[8];
    /* 0x3C */ u16 a3C[8];
    /* 0x4C */ u8 pad4C[0x80 - 0x4C];
    /* 0x80 */ s8 b80;
    /* 0x81 */ u8 pad81[0x8D - 0x81];
    /* 0x8D */ u8 b8D;
    /* 0x8E */ u8 b8E;
    /* 0x8F */ u8 b8F;
    /* 0x90 */ u8 b90;
    /* 0x91 */ u8 b91;
} S11Rec;

typedef struct S11Hud {                 /* record at obj->0x5DC */
    /* 0x000 */ u8 pad0[0x140];
    /* 0x140 */ S11Quad quad140;
} S11Hud;

typedef struct S11E878 {                /* sub-record at obj->0x878 */
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ u8 padC[0x90 - 0xC];
    /* 0x90 */ f32 unk90;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ f32 unk98;
    /* 0x9C */ s32 unk9C;
    /* 0xA0 */ f32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ s32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ f32 unkB0;
    /* 0xB4 */ s32 unkB4;
    /* 0xB8 */ s32 unkB8;
} S11E878;

typedef struct S11Spr {                 /* 0x3C-byte widget/sprite record */
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ f32 f34;
    /* 0x38 */ u8 pad38[4];
} S11Spr;

typedef struct S11Spr2 { u8 pad[0x38]; } S11Spr2;

typedef struct S11Obj S11Obj;
struct S11Obj {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ void *unk14;
    /* 0x018 */ S11Cfg* cfg;
    /* 0x01C */ u8 pad1C[0x34];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05C */ u8 pad5C[0xA4];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0xD4];
    /* 0x1D8 */ S11Obj* self;
    /* 0x1DC */ u8 pad1DC[0xA0];
    /* 0x27C */ void (*unk27C)();
    /* 0x280 */ void (*unk280)();
    /* 0x284 */ u8 pad284[0x4];
    /* 0x288 */ void (*unk288)();
    /* 0x28C */ void (*unk28C)();
    /* 0x290 */ void (*unk290)();
    /* 0x294 */ u8 pad294[0x54];
    /* 0x2E8 */ u8 ent2E8[80];
    /* 0x338 */ f32 unk338;
    /* 0x33C */ f32 unk33C;
    /* 0x340 */ f32 unk340;
    /* 0x344 */ u8 pad344[0xA4];
    /* 0x3E8 */ u32 flags3E8;
    /* 0x3EC */ u8 pad3EC[0x6C];
    /* 0x458 */ u8 ent458[52];
    /* 0x48C */ s8 unk48C;
    /* 0x48D */ u8 pad48D[0x33];
    /* 0x4C0 */ S11Obj* self4C0;
    /* 0x4C4 */ u8 pad4C4[0xA4];
    /* 0x568 */ void (*unk568)();
    /* 0x56C */ u8 pad56C[0x4];
    /* 0x570 */ void (*unk570)();
    /* 0x574 */ void (*unk574)();
    /* 0x578 */ u8 pad578[0x58];
    /* 0x5D0 */ s32 unk5D0;
    /* 0x5D4 */ s32 unk5D4;
    /* 0x5D8 */ S11Rec* rec;
    /* 0x5DC */ S11Hud* hud;
    /* 0x5E0 */ s32 unk5E0;
    /* 0x5E4 */ s32 unk5E4;
    /* 0x5E8 */ s16 unk5E8;
    /* 0x5EA */ s16 unk5EA;
    /* 0x5EC */ s32 unk5EC;
    /* 0x5F0 */ u8 pad5F0[0x3E];
    /* 0x62E */ s16 unk62E;
    /* 0x630 */ u8 pad630[0x8];
    /* 0x638 */ s32 unk638;
    /* 0x63C */ s32 unk63C;
    /* 0x640 */ s32 unk640;
    /* 0x644 */ u8 b644[6];
    /* 0x64A */ u8 b64A[6];
    /* 0x650 */ u8 pad650[0x20];
    /* 0x670 */ s32 unk670;
    /* 0x674 */ s32 unk674;
    /* 0x678 */ s32 unk678;
    /* 0x67C */ s32 unk67C;
    /* 0x680 */ s32 unk680;
    /* 0x684 */ s32 unk684;
    /* 0x688 */ u8 pad688[0x10];
    /* 0x698 */ void *unk698;
    /* 0x69C */ u8 pad69C[0xC4];
    /* 0x760 */ S11Quad quad760;
    /* 0x770 */ u8 pad770[0x4C];
    /* 0x7BC */ s32 unk7BC;
    /* 0x7C0 */ u8 pad7C0[0x9C];
    /* 0x85C */ s32 unk85C;
    /* 0x860 */ u8 pad860[0x8];
    /* 0x868 */ s32 unk868;
    /* 0x86C */ s32 unk86C;
    /* 0x870 */ s32 unk870;
    /* 0x874 */ u8 pad874[0x4];
    /* 0x878 */ S11E878 e878;
    /* 0x934 */ u8 pad934[0x4F8];
    /* 0xE2C */ S11Spr spr[12];
    /* 0x10FC */ S11Spr2 spr12;
    /* 0x1134 */ s32 unk1134;
    /* 0x1138 */ u8 pad1138[0x78];
    /* 0x11B0 */ s32 unk11B0;
    /* 0x11B4 */ u8 pad11B4[0x10];
    /* 0x11C4 */ s32 unk11C4;
    /* 0x11C8 */ u8 pad11C8[0x5C];
    /* 0x1224 */ s32 unk1224;
    /* 0x1228 */ s32 unk1228;
    /* 0x122C */ u8 pad122C[0x110];
    /* 0x133C */ s32 unk133C;
    /* 0x1340 */ u8 pad1340[0x88];
    /* 0x13C8 */ s32 unk13C8;
    /* 0x13CC */ u8 pad13CC[0x1C];
    /* 0x13E8 */ s32 unk13E8;
    /* 0x13EC */ u8 pad13EC[0x64];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ u8 pad1454[0x4];
};

typedef struct S11Game {                /* D_801462C8 */
    /* 0x000 */ u8 pad0[0xD];
    /* 0x00D */ u8 unkD;
    /* 0x00E */ u8 padE[0x1D - 0xE];
    /* 0x01D */ u8 unk1D;
    /* 0x01E */ u8 pad1E[0x5FC - 0x1E];
    /* 0x5FC */ s32 unk5FC;
} S11Game;

#endif
