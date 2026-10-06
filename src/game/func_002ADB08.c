#include "b24_types.h"

typedef struct Fx24 {
    s32 *unk0;
    u8 pad4[2];
    s16 unk6;
    s16 unk8;
    u8 padA[2];
    s16 unkC;
    s16 unkE;
} Fx24;

extern u8 D_80145088[];
void func_00222BC4(Ent24 *, s32, s32);
void func_00237E70(u8 *, s32, s32);
void func_0023919C(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0025DE74(s32, s32, s32, s32, s32, s32);
void func_0025E13C(s32);

s32 func_002ADB08(Ent24 *e, Fx24 *f) {
    s32 a;
    s32 *p;
    s32 b;
    s32 c;
    a = f->unkC;
    if (a != -1) {
        func_00222BC4(e, a, f->unkE);
    }
    p = f->unk0;
    b = f->unk6;
    c = f->unk8;
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
    return 1;
}
