#include "b17_types.h"

extern f32 D_800C9A68;
extern f32 D_800C9A6C;
extern f32 D_800C9A70;
extern f32 D_800C9A74;
extern f32 D_800C9A78;
extern f32 D_800C9A7C;
extern f32 D_800C9A80;
extern f32 D_800C9A84;

f32 func_00274A24(f32 a, f32 b) {
    f32 d;

    while (b < D_800C9A68) {
        b += D_800C9A6C;
    }
    while (D_800C9A70 < b) {
        b -= D_800C9A74;
    }
    d = a - b;
    while (d < D_800C9A78) {
        d += D_800C9A7C;
    }
    while (D_800C9A80 < d) {
        d -= D_800C9A84;
    }
    return -d;
}
