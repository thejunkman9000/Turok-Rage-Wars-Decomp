/* PARTIAL: 22 insns like the ROM, but the ROM does mul.s f0,f1,f0 ; mov.s f1,f0 (separate temp) before c.lt.s */
#include "p1_types.h"
extern f32 D_800C7DD8[];
extern f32 D_800C7DE0;
extern f32 D_800C7DE4;
extern f32 D_800C7DE8[];
f32 func_0022AA34(Actor *a) {
    f32 t = a->unk840;
    f32 b = D_800C7DD8[1];
    f32 v;
    if (a->unk848 != 0 || (v = (t - b) * D_800C7DE0, D_800C7DE4 < v)) {
        v = D_800C7DE8[0];
    }
    return D_800C7DE8[1] - v;
}
