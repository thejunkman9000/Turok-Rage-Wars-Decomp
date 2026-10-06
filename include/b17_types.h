#ifndef B17_TYPES_H
#define B17_TYPES_H

#include "p1_types.h"

/* Types recovered in batch 17 (main image 0x7518C-0x7C390: rng/float helpers, vector/matrix code, actor handlers).
   GENERATED from wip/types_spec.py: padding arrays keep the offsets seen in the asm; names are provisional. */

typedef struct VelObj {
    /* 0x000 */ u8 pad0[0x18];
    /* 0x018 */ Vec3f vel;
    /* 0x024 */ Vec3f dir;
} VelObj;

typedef struct RayObj {
    /* 0x000 */ Vec3f pos;
    /* 0x00C */ u8 padC[0x24];
    /* 0x030 */ Vec3f dir;
} RayObj;

typedef struct PlaneObj {
    /* 0x000 */ Vec3f pos;
    /* 0x00C */ u8 padC[0xC];
    /* 0x018 */ Vec3f nrm;
} PlaneObj;

typedef struct ActorX {
    /* 0x000 */ u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x4];
    /* 0x018 */ ActorDef *def;
    /* 0x01C */ u8 pad1C[0x1C];
    /* 0x038 */ u32 flags38;
    /* 0x03C */ u8 pad3C[0x30];
    /* 0x06C */ f32 unk6C;
    /* 0x070 */ u8 pad70[0x74];
    /* 0x0E4 */ u16 unkE4;
    /* 0x0E6 */ u8 padE6[0x1A];
    /* 0x100 */ u32 flags;
    /* 0x104 */ u8 pad104[0xD4];
    /* 0x1D8 */ Actor *owner;
    /* 0x1DC */ u8 pad1DC[0x110];
    /* 0x2EC */ Actor *next2EC;
    /* 0x2F0 */ u8 pad2F0[0x2E4];
    /* 0x5D4 */ s32 unk5D4;
    /* 0x5D8 */ ActorStats *stats;
    /* 0x5DC */ u8 pad5DC[0x8];
    /* 0x5E4 */ s32 unk5E4;
    /* 0x5E8 */ u8 pad5E8[0x88];
    /* 0x670 */ f32 unk670;
    /* 0x674 */ u8 pad674[0x1CC];
    /* 0x840 */ f32 unk840;
    /* 0x844 */ u8 pad844[0x4];
    /* 0x848 */ s32 unk848;
    /* 0x84C */ u8 pad84C[0x974];
    /* 0x11C0 */ s32 unk11C0;
    /* 0x11C4 */ u8 pad11C4[0x28C];
    /* 0x1450 */ s32 unk1450;
    /* 0x1454 */ Brain *brain;
    /* 0x1458 */ u8 pad1458[0x280];
    /* 0x16D8 */ u16 unk16D8;
    /* 0x16DA */ u8 pad16DA[0x6];
    /* 0x16E0 */ Actor *next;
} ActorX;

typedef struct SessMgr {
    /* 0x000 */ s32 mode;
} SessMgr;

typedef struct Rec14 {
    /* 0x000 */ s32 w0;
    /* 0x004 */ u8 pad4[0xA];
    /* 0x00E */ u8 flagsE;
    /* 0x00F */ u8 padF[0x1];
    /* 0x010 */ u8 b10;
    /* 0x011 */ u8 b11;
    /* 0x012 */ u8 b12;
    /* 0x013 */ u8 pad13[0x1];
} Rec14;

typedef struct Evt {
    /* 0x000 */ u8 pad0[0x6];
    /* 0x006 */ u16 id;
} Evt;

#endif
