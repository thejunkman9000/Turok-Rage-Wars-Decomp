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

typedef struct Cfg24 {
    u8 pad0[0x14];
    u32 unk14;
} Cfg24;

typedef struct Glob24 {
    u8 pad0[0x1D];
    u8 unk1D;
    u8 pad1E[0x60E];
    s32 unk62C;
} Glob24;

extern u8 D_80145088[];
extern Glob24 D_801462C8[];
extern u8 D_801462E5;
extern Cfg24 *D_800D052C[];
s32 func_00222BC4(Ent24 *, s32, s32);
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

s32 func_002AC96C(Ent24 *e, Fx24 *f) {
    s32 r;
    s32 old;
    s32 idx;
    Cfg24 *cfg;
    s32 a1 = f->unkE;
    r = 0;
    if (a1 == -1 || e->slot[f->unkC].a == 0 || (r = func_00222BC4(e, a1, f->unk10), r != 0) ||
        (D_801462C8->unk1D != 0 && e->unk5D8->unk8F != 0 && D_801462C8->unk62C != 0)) {
        if (D_801462E5 != 0) {
            if ((D_800D052C[f->unkC]->unk14 & 8) == 0) {
                return 0;
            }
            goto B;
        }
        if ((D_800D052C[f->unkC]->unk14 & 8) != 0) {
            return 0;
        }
B:
        old = e->slot[f->unkC].a;
        e->slot[f->unkC].a = 1;
        idx = f->unkC;
        cfg = D_800D052C[idx];
        if (e->unk62E < idx) {
            if (e->unk38 & 0x1000) {
                if (cfg->unk14 & 2) {
                    goto C;
                }
            } else if (cfg->unk14 & 1) {
C:
                if (D_801462E5 == 0 && old == 0) {
                    e->unk770 = f->unkC;
                }
            }
        }
        fx(e, f);
        if (r == 0) {
            func_00222BC4(e, f->unkE, f->unk10);
        }
        return 1;
    }
    return 0;
}
