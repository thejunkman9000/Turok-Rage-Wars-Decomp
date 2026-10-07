#ifndef M02_TYPES_H
#define M02_TYPES_H
#include "common.h"
#include "b06_types.h"

/* m02: partial view of a generic world object (what PlrEnt.unk8 points to) */
typedef struct M2Obj {
    /* 0x0000 */ u8 type;
    /* 0x0001 */ u8 pad1[0xFF];
    /* 0x0100 */ u32 flags100;
    /* 0x0104 */ u8 pad104[0x1128];
    /* 0x122C */ u32 flags122C;
} M2Obj;

typedef void (*M2Fn)();
typedef struct M2Mtx { f32 m[16]; } M2Mtx;
typedef struct M2Quat { f32 x, y, z, w; } M2Quat;
typedef struct M2Row38 { u8 pad0[0x38]; Vec3f v38; } M2Row38;
#endif
