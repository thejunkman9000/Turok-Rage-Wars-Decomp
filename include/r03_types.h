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

/* func_00235AD0: viewport / screen setup object (provisional) */
typedef struct R3Rect {
    s16 x0, y0;
    s16 pad4, pad6;
    s16 x1, y1;
    s16 padC, padE;
} R3Rect;

typedef struct R3View {
    /* 0x000 */ u8 pad0[0xC];
    /* 0x00C */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ u8 pad14[0x68 - 0x14];
    /* 0x068 */ u32 unk68;
    /* 0x06C */ u8 pad6C[0x110 - 0x6C];
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ u8 pad118[8];
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[0x29C - 0x124];
    /* 0x29C */ f32 unk29C;
    /* 0x2A0 */ f32 unk2A0;
    /* 0x2A4 */ f32 unk2A4;
    /* 0x2A8 */ f32 unk2A8;
    /* 0x2AC */ u8 pad2AC[4];
    /* 0x2B0 */ R3Rect rect[1];
    /* 0x2C0 */ u8 pad2C0[0x520 - 0x2C0];
    /* 0x520 */ u8 col[3];
    /* 0x523 */ u8 pad523[0x53E - 0x523];
    /* 0x53E */ u16 unk53E;
    /* 0x540 */ u8 pad540[0x17B0 - 0x540];
    /* 0x17B0 */ s32 unk17B0;
} R3View;

/* func_0023D370: collision mover (provisional) */
typedef struct R3V3 { f32 x, y, z; } R3V3;

typedef struct R3Def {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ f32 fC;
} R3Def;

typedef struct R3Mv {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ s32 w24;
    /* 0x028 */ s32 w28;
    /* 0x02C */ s32 w2C;
    /* 0x030 */ s32 w30;
    /* 0x034 */ s32 w34;
    /* 0x038 */ s32 w38;
    /* 0x03C */ u32 flags3C;
    /* 0x040 */ R3Def *def;
    /* 0x044 */ R3V3 v44;
    /* 0x050 */ R3V3 v50;
    /* 0x05C */ R3V3 v5C;
    /* 0x068 */ u8 pad68[0xC];
    /* 0x074 */ R3V3 v74;
    /* 0x080 */ f32 f80;
    /* 0x084 */ u8 pad84[0x2C];
    /* 0x0B0 */ s32 st;
    /* 0x0B4 */ f32 fB4;
    /* 0x0B8 */ s32 phase;
    /* 0x0BC */ u8 padBC[8];
    /* 0x0C4 */ s32 cnt;
    /* 0x0C8 */ R3V3 vv[4];
    /* 0x0F8 */ R3V3 nrm;
    /* 0x104 */ u8 pad104[0x17C - 0x104];
    /* 0x17C */ f32 t;
    /* 0x180 */ R3V3 hit;
    /* 0x18C */ u8 pad18C[0x198 - 0x18C];
    /* 0x198 */ R3V3 va;
    /* 0x1A4 */ R3V3 vb;
} R3Mv;
#endif
