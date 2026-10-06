#include "b06_types.h"

f32 func_00274878(f32 a, f32 b, s32 c);
extern f32 D_800C7E04;
extern s32 D_800CF234;

void func_0022B5B0(Plr *a) {
    if (a->unk5E4 != 0) {
        a->unk12C0 = func_00274878(a->unk12C0, D_800C7E04, D_800CF234);
    }
}
