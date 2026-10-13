#include "b24_types.h"

typedef struct Fx24 {
    s32 *unk0;
    u8 pad4[2];
    s16 unk6;
    s16 unk8;
    u8 padA[2];
    u16 unkC;
} Fx24;

extern u8 D_80145088[];
extern u8 D_auto_80152789;
void func_00237E70(u8 *, s32, s32);
void func_0023919C(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0025DE74(s32, s32, s32, s32, s32, s32);
void func_0025E13C(s32);

s32 func_auto_002AD10C(Ent24 *e, Fx24 *f) {
    s16 t;
    s32 *p;
    s32 b, c;
    t = e->unk5E8 + f->unkC;
    e->unk5E8 = t;
    if (t >= 0x64) {
        e->unk5E8 = t - 0x64;
        if (e->unk5EA < 9) {
            e->unk5EA = e->unk5EA + 1;
        }
    }
    p = f->unk0;
    b = f->unk6;
    c = f->unk8;
    if (e->unk5DC != 0) {
        func_0023919C(e->unk5DC, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (p != NULL) {
            func_00237E70(D_80145088, e->unk5DC, p[D_auto_80152789]);
        }
    }
    if (b != 0) {
        func_0025DE74(b, e->unk8, e->unkC, e->unk10, 0, -1);
    }
    if (c != 0) {
        func_0025E13C(c);
    }
    return 1;
}
