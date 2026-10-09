#ifndef R05_TYPES_H
#define R05_TYPES_H
#include "common.h"

/* round 3 (workspace r05) types.  Names provisional. */

/* controller mask table entry (D_800D0DB0): {button mask, output bits}, terminated by mask 0 */
typedef struct R05PadMap {
    /* 0x0 */ s32 mask;
    /* 0x4 */ s32 val;
} R05PadMap;

/* raw controller state (func_002631D0 reads buttons B0..C0 and the two stick bytes C6/C7) */
typedef struct R05PadCtl {
    /* 0x00 */ u8 pad0[0xB0];
    /* 0xB0 */ s32 btn[5];
    /* 0xC4 */ u8 padC4[2];
    /* 0xC6 */ s8 stickX;
    /* 0xC7 */ s8 stickY;
} R05PadCtl;

/* translated pad output of func_002631D0 */
typedef struct R05PadOut {
    /* 0x00 */ f32 f0;
    /* 0x04 */ f32 f4;
    /* 0x08 */ f32 f8;
    /* 0x0C */ f32 fC;
    /* 0x10 */ R05PadCtl *ctl;
    /* 0x14 */ f32 f14;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 f1C;
    /* 0x20 */ f32 f20;
    /* 0x24 */ s32 bits[5];
} R05PadOut;

/* settings block at owner+0x5D8 */
typedef struct R05PadCfg {
    /* 0x00 */ u8 pad0[0x7A];
    /* 0x7A */ u8 b7A;
    /* 0x7B */ s8 mode;
    /* 0x7C */ u8 b7C;
    /* 0x7D */ u8 b7D;
} R05PadCfg;

typedef struct R05PadOwn {
    /* 0x000 */ u8 pad0[0x5D8];
    /* 0x5D8 */ R05PadCfg *cfg;
    /* 0x5DC */ u8 pad5DC[0x20C];
    /* 0x7E8 */ s32 unk7E8;
    /* 0x7EC */ f32 f7EC;
    /* 0x7F0 */ u8 pad7F0[0x9C4];
    /* 0x11B4 */ s32 unk11B4;
} R05PadOwn;


/* "offset table" container: n slots, off[i] byte offsets from the table start; unused slots hold 0xDEADBEEF */
typedef struct R05Tab {
    /* 0x0 */ s32 n;
    /* 0x4 */ s32 off[1];
} R05Tab;

/* header of the scene block passed to func_0025F58C */
typedef struct R05Src {
    /* 0x0 */ R05Tab *root;
    /* 0x4 */ s32 total;
} R05Src;

/* grid description (table entry 5/0 of the source) */
typedef struct R05Grid {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 w;
    /* 0x08 */ u8 pad8[8];
    /* 0x10 */ s32 cntA;
    /* 0x14 */ s32 cntB;
    /* 0x18 */ f32 f18;
    /* 0x1C */ f32 f1C;
} R05Grid;

typedef struct R05Cfg {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s32 cntA;
    /* 0x14 */ s32 cntB;
} R05Cfg;

/* animation playback state (func_0025E5D0 / func_00261EB8 / func_0026195C) */
typedef struct R05Anim {
    /* 0x00 */ f32 time;
    /* 0x04 */ s16 f4;
    /* 0x06 */ s16 f6;
    /* 0x08 */ s16 count;
    /* 0x0A */ u8 padA[2];
    /* 0x0C */ u32 loopStart;
    /* 0x10 */ void **data;
} R05Anim;

/* sampling output of func_00261EB8 */
typedef struct R05AnimOut {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 off0;
    /* 0x14 */ s32 off1;
    /* 0x18 */ s32 off2;
    /* 0x1C */ s32 off3;
    /* 0x20 */ f32 frac;
} R05AnimOut;

typedef struct R05CurveCfg {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ f32 n;
    /* 0x1C */ f32 scale;
} R05CurveCfg;

typedef struct R05Vec3i { s32 x, y, z; } R05Vec3i;

#endif
