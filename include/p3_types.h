#ifndef P3_TYPES_H
#define P3_TYPES_H
#include "common.h"

/* batch-3 recovered types (unique names, prefix P3) */

typedef struct { u8 b[12]; } P3Elem12;

/* object holding a table pointer at 0x2B78 (elements of 12 bytes) and a float at 0x2BBC */
typedef struct {
    u8 pad0[0x2B78];
    P3Elem12 *tab;     /* 0x2B78 */
    u8 pad1[0x2BBC - 0x2B7C];
    f32 fval;          /* 0x2BBC */
} P3Ctx;

/* mutex-like counter object: message queue + count */
typedef struct {
    OSMesgQueue q;     /* 0x00 */
    OSMesg buf;        /* 0x18 */
    s32 count;         /* 0x1C */
} P3Lock;

typedef struct {
    u8 pad0[0x110];
    P3Lock lock;       /* 0x110 */
} P3LockOwner;

typedef struct {
    u8 pad0[0x38];
    s32 unk38;
    u8 pad1[4];
    f32 unk40;
} P3Obj38;

/* 20-byte struct passed by value (a2,a3 + 3 stack words) */
typedef struct { s32 w[5]; } P3Blob20;

/* sound bank: embedded ALSndPlayer at 0x84, sound-id table at 0xDC */
typedef struct {
    u8 pad0[0x84];
    u8 sndp[0xDC - 0x84];  /* 0x84 ALSndPlayer */
    s16 snd[1];            /* 0xDC */
} P3SndBank;

/* sound wrapper object */
typedef struct {
    s32 idx;               /* 0x00 */
    u8 pad04[0xB0 - 4];
    P3SndBank *bank;       /* 0xB0 */
    u8 padB4[0xC8 - 0xB4];
    f32 volScale;          /* 0xC8 */
} P3Snd;

typedef struct { f32 x, y, z; } P3Vec3;
typedef struct { f32 m[4][4]; } P3Mtx;

/* 8-byte struct passed by value (callee reads two u16 and copies it as two words) */
typedef struct { u16 a; u16 b; s32 c; } P3S8;

#endif
