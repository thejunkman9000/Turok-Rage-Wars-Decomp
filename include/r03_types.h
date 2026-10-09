#ifndef R03_TYPES_H
#define R03_TYPES_H
#include "common.h"

/* func_002343B8: HUD colour/value fader */
typedef struct R3HudObj {
    /* 0x00 */ u8 pad0[0x58];
    /* 0x58 */ u16 *unk58;
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ u8 pad60[0x518 - 0x60];
    /* 0x518 */ s32 unk518;
    /* 0x51C */ f32 unk51C;
    /* 0x520 */ u8 col[4];
    /* 0x524 */ u8 prev[4];
    /* 0x528 */ f32 unk528;
    /* 0x52C */ f32 unk52C;
    /* 0x530 */ f32 unk530;
    /* 0x534 */ f32 unk534;
    /* 0x538 */ u8 pad538[4];
    /* 0x53C */ u32 unk53C;
    /* 0x540 */ u32 unk540;
} R3HudObj;

typedef struct R3Pl {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ u32 unk38;
    /* 0x3C */ u8 pad3C[0x5DC - 0x3C];
    /* 0x5DC */ R3HudObj *unk5DC;
    /* 0x5E0 */ u8 pad5E0[0x664 - 0x5E0];
    /* 0x664 */ u32 unk664;
    /* 0x668 */ u8 pad668[0x16E0 - 0x668];
    /* 0x16E0 */ struct R3Pl *next;
} R3Pl;

typedef struct R3Item {
    /* 0x00 */ u8 a[4];
    /* 0x04 */ u8 b[4];
    /* 0x08 */ u32 u8x;
    /* 0x0C */ u32 uCx;
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 f1C;
    /* 0x20 */ u8 pad20[4];
    /* 0x24 */ f32 f24;
} R3Item;

typedef struct R3G {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 pad4[0x68];
    /* 0x6C */ s32 unk6C;
} R3G;

/* display-list word pair appended through D_80110634 */
typedef struct R3DlCmd {
    u32 w0;
    u32 w1;
} R3DlCmd;
#endif
