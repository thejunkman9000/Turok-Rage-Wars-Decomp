#ifndef S802_TYPES_H
#define S802_TYPES_H

#include "common.h"

/* types recovered by worker s802 (round 8); names provisional */
typedef struct S8Vec3 { f32 x, y, z; } S8Vec3;
typedef struct S8Mat { f32 m[4][4]; } S8Mat;

/* mesh vertex record of func_00277620 (0x10 bytes): s16 position, flags, s8 normal */
typedef struct S8Vtx {
    /* 0x00 */ s16 x, y, z;
    /* 0x06 */ u16 flag;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ s8 nx, ny, nz;
    /* 0x0F */ u8 padF;
} S8Vtx;

/* collision volume (func_00277444's Probe): matrix at +0x20, aabb min +0xA0 / max +0xAC, kind +0xBA, index +0xBC */
typedef struct S8Vol {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ u8 mtx[0x80];
    /* 0xA0 */ S8Vec3 mn;
    /* 0xAC */ S8Vec3 mx;
    /* 0xB8 */ u8 padB8[2];
    /* 0xBA */ u8 kind;
    /* 0xBB */ u8 padBB;
    /* 0xBC */ u8 idx;
} S8Vol;

#endif
