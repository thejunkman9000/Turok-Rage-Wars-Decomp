#include "b24_types.h"

typedef struct Fx24 {
    s32 *unk0;
    u16 unk4;
    s16 unk6;
    s16 unk8;
} Fx24;

typedef struct Blk24b {
    u8 pad0[0xC];
    f32 unkC;
} Blk24b;

typedef struct Blk24 {
    u8 pad0[0x14];
    Blk24b b;
} Blk24;

typedef struct Ctx24 {
    u8 pad0[0x18];
    Blk24 *unk18;
} Ctx24;

extern u8 D_80145088[];
extern u8 D_auto_80152789;
extern f32 D_auto_800C6578;
extern f32 D_auto_800C657C;
s32 func_002AE1A4(Ent24 *);
s32 func_002AE254(void);
s32 func_002A7FA8(void *, s32, s32, s32, s32, f32, s32, void *, void *);
void func_00237E70(u8 *, s32, s32);
void func_0023919C(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0025DE74(s32, s32, s32, s32, s32, s32);
void func_0025E13C(s32);

s32 func_auto_002ACB58(Ent24 *e, Fx24 *f, Ctx24 *c) {
    Blk24b *b = &c->unk18->b;
    s32 *p;
    s32 bb, cc;
    switch ((s16)(f->unk4 - 0x708)) {
    case 0:
        e->unk670 = D_auto_800C6578;
        break;
    case 1:
        e->unk674 = D_auto_800C657C;
        break;
    case 2:
    case 3:
        e->unk678 += b->unkC;
        break;
    case 7:
        func_002A7FA8((u8 *)e + 0xD40, 1, 0, 0x7FD, 0, 0.0f, 0, func_002AE1A4, func_002AE254);
        break;
    }
    p = f->unk0;
    bb = f->unk6;
    cc = f->unk8;
    if (e->unk5DC != 0) {
        func_0023919C(e->unk5DC, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (p != NULL) {
            func_00237E70(D_80145088, e->unk5DC, p[D_auto_80152789]);
        }
    }
    if (bb != 0) {
        func_0025DE74(bb, e->unk8, e->unkC, e->unk10, 0, -1);
    }
    if (cc != 0) {
        func_0025E13C(cc);
    }
    return 1;
}
