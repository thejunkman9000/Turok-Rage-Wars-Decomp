#include "p1_types.h"
extern f32 D_800C7DD8[];
extern f32 D_800C7DE0;
extern f32 D_800C7DE4;
extern f32 D_800C7DE8[];
f32 func_0022AA34(Actor *a) {
    f32 t = a->unk840 - D_800C7DD8[1];
    register f32 tmp asm("$f0");
    register f32 v asm("$f1");
    if (a->unk848 != 0) goto c0;
    tmp = t * D_800C7DE0;
    __asm__("" : "+f"(tmp));
    v = tmp;
    if (D_800C7DE4 < v) {
c0:
        v = D_800C7DE8[0];
    }
    return D_800C7DE8[1] - v;
}