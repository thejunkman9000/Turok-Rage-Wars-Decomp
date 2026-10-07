#ifndef O04_TYPES_H
#define O04_TYPES_H
#include "common.h"

/* overlay A (0x400000..): per-mode structures, only the accessed fields are named */

typedef struct O04Sub10 { u8 pad0[0x10]; u8 unk10; } O04Sub10;

/* object pointed to by D_800E4F60 (mode state) */
typedef struct O04Sub14 { u8 pad0[0x14]; s16 unk14; } O04Sub14;
typedef struct O04Sub38 { u8 pad0[0x38]; void *unk38; } O04Sub38;

typedef struct O04ModeF60 {
    /* 0x0 */ void * unk0;
    /* 0x4 */ u8 pad4[0x308 - 0x4];
    /* 0x308 */ u8 unk308[0x4C];
    /* 0x354 */ u8 pad354[0x3DC - 0x354];
    /* 0x3DC */ s32 state;
    /* 0x3E0 */ s32 unk3E0;
    /* 0x3E4 */ u8 pad3E4[0x3EC - 0x3E4];
    /* 0x3EC */ O04Sub38 * unk3EC;
    /* 0x3F0 */ void * unk3F0;
    /* 0x3F4 */ char unk3F4[0x40];
    /* 0x434 */ s32 unk434;
    /* 0x438 */ s32 unk438;
    /* 0x43C */ O04Sub10 * unk43C;
    /* 0x440 */ void * unk440;
    /* 0x444 */ void * unk444;
    /* 0x448 */ O04Sub14 * unk448;
    /* 0x44C */ O04Sub10 * unk44C;
    /* 0x450 */ O04Sub10 * unk450;
    /* 0x454 */ O04Sub10 * unk454;
    /* 0x458 */ u8 pad458[0x45C - 0x458];
    /* 0x45C */ s32 unk45C;
    /* 0x460 */ u8 pad460[0x464 - 0x460];
    /* 0x464 */ s32 unk464;
    /* 0x468 */ s32 unk468;
    /* 0x46C */ s32 unk46C;
} O04ModeF60;

/* D_800E4514 */
typedef struct O04ModeS4514 {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ s32 unkC;
} O04ModeS4514;

/* D_801468A0 (global game flags block in main image) */
typedef struct O04GFlags {
    /* 0x0 */ u8 pad0[0x14 - 0x0];
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x24 - 0x20];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C[5];
    /* 0x40 */ s32 unk40[5];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 pad5C[0x6C - 0x5C];
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ u8 pad70[0x78 - 0x70];
    /* 0x78 */ s32 unk78;
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s32 unk80;
    /* 0x84 */ u8 pad84[0x90 - 0x84];
    /* 0x90 */ s32 unk90;
    /* 0x94 */ u8 pad94[0x98 - 0x94];
    /* 0x98 */ s32 unk98;
    /* 0x9C */ s32 unk9C;
    /* 0xA0 */ s32 unkA0;
    /* 0xA4 */ s32 unkA4;
    /* 0xA8 */ s32 unkA8;
} O04GFlags;

/* D_800E4690 (mode state of ovl A "menu" mode) */
typedef struct O04ModeS4690 {
    /* 0x0 */ u8 pad0[0x20 - 0x0];
    /* 0x20 */ u8 unk20[0x970 - 0x20];
    /* 0x970 */ s32 unk970;
    /* 0x974 */ u8 pad974[0x988 - 0x974];
    /* 0x988 */ s32 unk988;
    /* 0x98C */ u8 pad98C[0x998 - 0x98C];
    /* 0x998 */ O04Sub38 * unk998;
    /* 0x99C */ u8 pad99C[0x9A0 - 0x99C];
    /* 0x9A0 */ char unk9A0[0x32];
    /* 0x9D2 */ char unk9D2[0x32];
    /* 0xA04 */ char unkA04[0x40];
    /* 0xA44 */ s32 unkA44;
    /* 0xA48 */ O04Sub10 * unkA48;
    /* 0xA4C */ u8 padA4C[0xA50 - 0xA4C];
    /* 0xA50 */ O04Sub10 * unkA50;
    /* 0xA54 */ u8 padA54[0xA5C - 0xA54];
    /* 0xA5C */ s32 unkA5C;
    /* 0xA60 */ O04Sub10 * unkA60;
    /* 0xA64 */ O04Sub10 * unkA64;
    /* 0xA68 */ s32 unkA68;
    /* 0xA6C */ s32 unkA6C;
    /* 0xA70 */ s32 unkA70;
    /* 0xA74 */ u8 unkA74[5];
    /* 0xA79 */ u8 unkA79[5];
} O04ModeS4690;

/* D_800E53C0 */
typedef struct O04ModeS53C0 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 unk20[0xE0 - 0x20];
    /* 0xE0 */ s32 unkE0;
    /* 0xE4 */ s32 unkE4;
    /* 0xE8 */ s32 unkE8;
    /* 0xEC */ s32 unkEC;
    /* 0xF0 */ s32 unkF0[8];
    /* 0x110 */ struct { s32 a; s32 b; } unk110[8];
    /* 0x150 */ u8 pad150[0x320 - 0x150];
    /* 0x320 */ s32 unk320;
    /* 0x324 */ u8 pad324[4];
    /* 0x328 */ s32 unk328;
    /* 0x32C */ s32 unk32C;
} O04ModeS53C0;

/* D_800E5430 */
typedef struct O04Hdr16 {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[2];
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u8 pad18[2];
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ u8 pad1C[0x38 - 0x1C];
    /* 0x38 */ void *unk38;
} O04Hdr16;

typedef struct O04Obj44 {
    /* 0x00 */ u8 pad0[0x44];
    /* 0x44 */ O04Hdr16 *unk44;
} O04Obj44;

typedef struct O04ModeS5430 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ O04Hdr16 *unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ char unk14[0xC];
    /* 0x20 */ s32 unk20;
} O04ModeS5430;

/* D_800E4600 */
typedef struct O04ModeS4600 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ O04Hdr16 *unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[4];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
} O04ModeS4600;

/* table entry of the event dispatch tables (stride 0xC) */
typedef struct O04Evt {
    /* 0x0 */ s32 ev;
    /* 0x4 */ s32 key;
    /* 0x8 */ s32 (*fn)(void *a, s32 b, s32 c, s32 d, s32 e);
} O04Evt;

/* 0x1C byte records at D_800E4694 */
typedef struct O04Ent1C {
    /* 0x00 */ s32 id;
    /* 0x04 */ s32 a;
    /* 0x08 */ s32 b;
    /* 0x0C */ u8 pad[0x10];
} O04Ent1C;

/* D_801462C8: saved/selected configuration block (main image, also used by ovl A) */
typedef struct O04Cfg {
    /* 0x00 */ u8 pad0[0xD];
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 pad0E[0x24 - 0x0E];
    /* 0x24 */ s8 s24;
    /* 0x25 */ s8 s25;
    /* 0x26 */ s8 s26;
    /* 0x27 */ s8 s27;
    /* 0x28 */ u8 u28;
    /* 0x29 */ u8 pad29[0x11C - 0x29];
    /* 0x11C */ u8 unk11C[8][0x96];
    /* 0x5CC */ u8 pad5CC[0x5EC - 0x5CC];
    /* 0x5EC */ f32 unk5EC;
    /* 0x5F0 */ u8 pad5F0[0x680 - 0x5F0];
    /* 0x680 */ s32 unk680;
} O04Cfg;

/* D_800E4680 */
typedef struct O04ModeS4680 {
    /* 0x00 */ u8 pad0[0x21];
    /* 0x21 */ u8 u21;
    /* 0x22 */ u8 u22;
    /* 0x23 */ u8 u23;
    /* 0x24 */ u8 u24;
} O04ModeS4680;

/* D_800E4EF0 */
typedef struct O04S4EF0 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
} O04S4EF0;

/* player "stats" block (Plr->unk5D8) */
typedef struct O04Stat {
    /* 0x00 */ u8 pad0[0x4C];
    /* 0x4C */ u8 u4C[0x16];
    /* 0x62 */ u8 u62[0x16];
    /* 0x78 */ u8 unk78;
    /* 0x79 */ u8 pad79[0x7F - 0x79];
    /* 0x7F */ s8 unk7F;
    /* 0x80 */ s8 unk80;
    /* 0x81 */ u8 pad81[0x91 - 0x81];
    /* 0x91 */ u8 unk91;
} O04Stat;

typedef struct O04BytePair { u8 a; u8 b; } O04BytePair;

/* player object (large); only the fields used by ovl A */
typedef struct O04Plr {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ void *unk18;
    /* 0x01C */ u8 pad1C[0x5D8 - 0x1C];
    /* 0x5D8 */ O04Stat *unk5D8;
    /* 0x5DC */ u8 pad5DC[0x602 - 0x5DC];
    /* 0x602 */ O04BytePair unk602[0x16];
} O04Plr;

typedef struct O04Sub2C {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 pad11[0x2C - 0x11];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u8 pad30[0x38 - 0x30];
    /* 0x38 */ s32 unk38;
} O04Sub2C;

/* D_800E4518 (title/menu mode object) */
typedef struct O04ModeS4518 {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 pad20[0x30 - 0x20];
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x44 - 0x38];
    /* 0x44 */ void *unk44;
    /* 0x48 */ u8 pad48[4];
    /* 0x4C */ void *unk4C;
    /* 0x50 */ u8 pad50[0x60 - 0x50];
    /* 0x60 */ s32 unk60;
} O04ModeS4518;

#endif
