#ifndef R02_GEN_H
#define R02_GEN_H
#include "r02_types.h"

typedef struct R2P5 R2P5;
typedef struct R2A5St R2A5St;
typedef struct R2A5Def R2A5Def;
typedef struct R2A5 R2A5;

struct R2P5 {
    /* 0x0000 */ u8 pad0[0x38];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0xA8];
    /* 0x00E4 */ u16 unkE4;
    /* 0x00E6 */ u8 padE6[0x4F2];
    /* 0x05D8 */ R2A5St* stats;
    /* 0x05DC */ u8 pad5DC[0x4];
    /* 0x05E0 */ s32 unk5E0;
    /* 0x05E4 */ u8 pad5E4[0x74];
    /* 0x0658 */ f32 f658;
    /* 0x065C */ u8 pad65C[0x10];
    /* 0x066C */ f32 f66C;
    /* 0x0670 */ u8 pad670[0x2C];
    /* 0x069C */ f32 f69C;
    /* 0x06A0 */ f32 f6A0;
    /* 0x06A4 */ f32 f6A4;
    /* 0x06A8 */ f32 f6A8;
    /* 0x06AC */ u8 pad6AC[0x4];
    /* 0x06B0 */ u32 unk6B0;
    /* 0x06B4 */ u8 pad6B4[0xC];
    /* 0x06C0 */ f32 f6C0;
    /* 0x06C4 */ f32 f6C4;
    /* 0x06C8 */ u8 pad6C8[0x18];
    /* 0x06E0 */ f32 f6E0;
    /* 0x06E4 */ f32 f6E4;
    /* 0x06E8 */ f32 f6E8;
    /* 0x06EC */ f32 f6EC;
    /* 0x06F0 */ f32 f6F0;
    /* 0x06F4 */ u8 pad6F4[0x30];
    /* 0x0724 */ f32 f724;
    /* 0x0728 */ f32 f728;
    /* 0x072C */ f32 f72C;
    /* 0x0730 */ u8 pad730[0xB8];
    /* 0x07E8 */ s32 unk7E8;
    /* 0x07EC */ u8 pad7EC[0x80];
    /* 0x086C */ s32 unk86C;
    /* 0x0870 */ u8 pad870[0x968];
    /* 0x11D8 */ f32 f11D8;
    /* 0x11DC */ u8 pad11DC[0x1D8];
    /* 0x13B4 */ void* unk13B4;
    /* 0x13B8 */ u8 pad13B8[0x308];
    /* 0x16C0 */ f32 f16C0;
    /* 0x16C4 */ u8 pad16C4[0x3C];
};

struct R2A5St {
    /* 0x0000 */ u8 pad0[0x8F];
    /* 0x008F */ u8 b8F;
};

struct R2A5Def {
    /* 0x0000 */ u8 pad0[0x14];
    /* 0x0014 */ u32 flags14;
};

struct R2A5 {
    /* 0x0000 */ u8 pad0[0x8];
    /* 0x0008 */ s32 w8;
    /* 0x000C */ s32 wC;
    /* 0x0010 */ s32 w10;
    /* 0x0014 */ u8 pad14[0x4];
    /* 0x0018 */ R2A5Def* def;
    /* 0x001C */ f32 f1C;
    /* 0x0020 */ u8 pad20[0x4];
    /* 0x0024 */ f32 f24;
    /* 0x0028 */ u8 pad28[0x10];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0x30];
    /* 0x006C */ f32 f6C;
};

#endif
