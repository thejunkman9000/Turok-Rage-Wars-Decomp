#include "b24_types.h"

extern u8 D_80145088[];
extern u8 D_auto_80152789;
void func_00237E70(u8 *, s32, s32);
void func_0023919C(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0025DE74(s16, s32, s32, s32, s32, s32);
void func_0025E13C(s32);

void func_auto_002AD370(Ent24 *e, s32 *p, s32 b, s32 c) {
    if (e->unk5DC != 0) {
        func_0023919C(e->unk5DC, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (p != NULL) {
            func_00237E70(D_80145088, e->unk5DC, p[D_80145088[0x17C1]]);
        }
    }
    if (b != 0) {
        func_0025DE74(b, e->unk8, e->unkC, e->unk10, 0, -1);
    }
    if (c != 0) {
        func_0025E13C(c);
    }
}
