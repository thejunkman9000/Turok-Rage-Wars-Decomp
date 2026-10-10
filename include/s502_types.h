#ifndef S502_TYPES_H
#define S502_TYPES_H
#include "b02_types.h"

typedef struct S5Brain {
    /* 0x0000 */ u8 pad0[0x4];
    /* 0x0004 */ s32 key;
    /* 0x0008 */ s32 prev;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ u8 pad10[0x4];
    /* 0x0014 */ s32 unk14;
} S5Brain;

typedef struct S5Actor S5Actor;
struct S5Actor {
    /* 0x0000 */ u8 kind;
    /* 0x0001 */ u8 pad1[0x3];
    /* 0x0004 */ u16 type;
    /* 0x0006 */ u8 pad6[0x2];
    /* 0x0008 */ Vec3f pos;
    /* 0x0014 */ u8 pad14[0x4];
    /* 0x0018 */ B2Def *def;
    /* 0x001C */ u8 pad1C[0x1C];
    /* 0x0038 */ u32 flags38;
    /* 0x003C */ u8 pad3C[0x30];
    /* 0x006C */ f32 unk6C;
    /* 0x0070 */ u8 pad70[0x74];
    /* 0x00E4 */ u16 unkE4;
    /* 0x00E6 */ u8 padE6[0x1A];
    /* 0x0100 */ u32 flags;
    /* 0x0104 */ u8 pad104[0x28];
    /* 0x012C */ S5Actor *unk12C;
    /* 0x0130 */ u8 pad130[0xA8];
    /* 0x01D8 */ S5Actor *owner;
    /* 0x01DC */ u8 pad1DC[0x10];
    /* 0x01EC */ S5Actor *next1EC;
    /* 0x01F0 */ u8 pad1F0[0x20];
    /* 0x0210 */ Vec3f pos210;
    /* 0x021C */ u8 pad21C[0x378];
    /* 0x0594 */ s32 unk594;
    /* 0x0598 */ u8 pad598[0x40];
    /* 0x05D8 */ B2Stats *stats;
    /* 0x05DC */ B2Pawn *pawn;
    /* 0x05E0 */ u8 pad5E0[0x4];
    /* 0x05E4 */ s32 unk5E4;
    /* 0x05E8 */ u8 pad5E8[0x46];
    /* 0x062E */ s16 unk62E;
    /* 0x0630 */ u8 pad630[0x20];
    /* 0x0650 */ s16 unk650;
    /* 0x0652 */ u8 pad652[0x4A];
    /* 0x069C */ f32 unk69C;
    /* 0x06A0 */ f32 unk6A0;
    /* 0x06A4 */ f32 unk6A4;
    /* 0x06A8 */ f32 unk6A8;
    /* 0x06AC */ u32 unk6AC;
    /* 0x06B0 */ u32 unk6B0;
    /* 0x06B4 */ u8 pad6B4[0x1C];
    /* 0x06D0 */ s32 unk6D0;
    /* 0x06D4 */ u8 pad6D4[0xB04];
    /* 0x11D8 */ f32 unk11D8;
    /* 0x11DC */ u8 pad11DC[0x164];
    /* 0x1340 */ s32 unk1340;
    /* 0x1344 */ u8 pad1344[0x10C];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ S5Brain *brain;
};

#endif
