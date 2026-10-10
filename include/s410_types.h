#ifndef S410_TYPES_H
#define S410_TYPES_H
#include "common.h"

/* sound/menu context node (same layout as b22 SndCtx, with a typed callback at +0x40) */
typedef struct S410Ctx S410Ctx;
typedef s32 (*S410Fn)(S410Ctx *, s32, s32, s32, s32);
struct S410Ctx {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ S410Ctx *child1;
    /* 0x08 */ S410Ctx *child2;
    /* 0x0C */ s16 id;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u8 pad10[2];
    /* 0x12 */ u16 flags12;
    /* 0x14 */ u8 pad14[0x28];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ S410Fn fn;
    /* 0x44 */ s32 unk44;
};

typedef struct S410Ent {
    /* 0x00 */ S410Ctx *ctx;
    /* 0x04 */ s32 id;
    /* 0x08 */ S410Ctx *unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
} S410Ent;

typedef struct S410Mgr {
    /* 0x000 */ s32 (*fn0)();
    /* 0x004 */ s32 top;
    /* 0x008 */ s32 unk8;
    /* 0x00C */ S410Ent *stk;
    /* 0x010 */ u8 pad10[0x510];
    /* 0x520 */ s32 lock;
    /* 0x524 */ s32 unk524;
} S410Mgr;

/* command classes of the sound/menu command codes */
static inline s32 S410_Classify(u32 cmd)
{
    if (cmd < 0xE00) {
        return 0;
    }
    if (cmd - 0x1000 < 0x1000) {
        return 1;
    }
    if (cmd - 0xE00 < 0x200) {
        return 2;
    }
    if (cmd - 0x4000 < 0x4000) {
        return 3;
    }
    return 0;
}
#endif
