#ifndef M05_TYPES_H
#define M05_TYPES_H
#include "common.h"

/* types recovered by workspace m05 (leftover game functions) */
typedef struct M5Vec3 { f32 x, y, z; } M5Vec3;
typedef struct M5Vec4 { f32 x, y, z, w; } M5Vec4;
typedef struct M5Mtx { f32 m[4][4]; } M5Mtx;

/* homing projectile object (stride 0x1F8+) used by func_0027A0F4 / func_0027A540 */
typedef struct M5Lim { u8 pad0[0x10]; u16 a; u16 b; } M5Lim;
typedef struct M5Def { u8 pad0[0x30]; M5Lim *lim; } M5Def;
typedef struct M5Handle { u8 pad0[8]; s32 id8; s32 idC; } M5Handle;
typedef struct M5Owner { u8 pad0[0x1D8]; s32 f1D8; } M5Owner;
typedef struct M5Obj {
    /* 0x000 */ u8 pad0[8];
    /* 0x008 */ M5Vec3 pos;
    /* 0x014 */ u8 pad14[8];
    /* 0x01C */ M5Vec3 pos2;
    /* 0x028 */ u8 pad28[0x34];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ M5Def *def;
    /* 0x11C */ u8 pad11C[0x10];
    /* 0x12C */ M5Owner *owner;
    /* 0x130 */ u8 pad130[4];
    /* 0x134 */ void *tgt;
    /* 0x138 */ u8 pad138[8];
    /* 0x140 */ f32 f140;
    /* 0x144 */ u8 pad144[0x30];
    /* 0x174 */ M5Vec3 vel;
    /* 0x180 */ u8 pad180[0x39];
    /* 0x1B9 */ u8 b1B9;
    /* 0x1BA */ u8 b1BA;
    /* 0x1BB */ u8 pad1BB[0x21];
    /* 0x1DC */ M5Handle *handle;
} M5Obj;

#endif
