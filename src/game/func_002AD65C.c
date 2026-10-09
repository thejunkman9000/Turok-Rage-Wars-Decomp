


#include "b24_types.h"

typedef struct Fx24 {
    s32 *unk0;
    u8 pad4[2];
    s16 unk6;
    s16 unk8;
    u8 padA[2];
    s16 unkC;
    s16 unkE;
    s16 unk10;
} Fx24;

extern u8 D_80145088[];
extern s32 D_801468F4;
extern u32 D_800CE474[];
void func_00222BC4(Ent24 *, s32, s32);
void func_00237E70(u8 *, s32, s32);
void func_0023919C(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0025DE74(s32, s32, s32, s32, s32, s32);
void func_0025E13C(s32);

static inline void fx(Ent24 *e, Fx24 *f) {
    s32 *p = f->unk0;
    s32 b = f->unk6;
    s32 c = f->unk8;
    if (e->unk5DC != 0) {
        func_0023919C(e->unk5DC, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (p != NULL) {
            func_00237E70(D_80145088, e->unk5DC, *p);
        }
    }
    if (b != 0) {
        func_0025DE74(b, e->unk8, e->unkC, e->unk10, 0, -1);
    }
    if (c != 0) {
        func_0025E13C(c);
    }
}

s32 func_002AD65C(Ent24 *e, Fx24 *f) {
    s32 i;
    s32 hasA = 1;
    s32 hasB = 1;
    s32 z = 0;
    s32 v;
    Slot24 *q;
    u8 *p;
    Ent24 *qq;

    if (e->slot[f->unkC].b != -1) {
        if (e->unk5D8->unk8F == 0 || D_801468F4 == 0 || e->unkE4 == D_800CE474[0] || e->unkE4 == D_800CE474[1]) {
            fx(e, f);
            return 1;
        }
    }
    for (i = 0; i < 22; i++) {
        if (e->slot[i].b == 3) {
            hasA = 0;
        } else if (e->slot[i].b == 7) {
            hasB = 0;
        }
    }
    e->slot[f->unkC].a = 1;
    if (hasA || hasB) {
        if (e->unk5D8->unk8F == 0 || D_801468F4 == 0) {
            v = 3;
            if (hasA == 0) {
                v = 7;
            }
            e->unkCC0 = v;
            qq = (Ent24 *)((u8 *)e + f->unkC * 2);
            if (hasA) {
                qq->slot[0].b = 3;
            } else {
                qq->slot[0].b = 7;
                __asm__ __volatile__("");
            }
        }
        fx(e, f);
        if (z == 0) {
            func_00222BC4(e, f->unkE, f->unk10);
        }
        return 1;
    }
    return 0;
}


