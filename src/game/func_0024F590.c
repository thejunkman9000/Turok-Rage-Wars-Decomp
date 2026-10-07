#include "b11_types.h"

extern f32 D_800D2988;
extern f32 D_800C8EF0;
extern f32 D_800C8EF4;
extern f32 D_800C8EF8;
extern f32 D_800C8EFC;

void func_0024F590(ObjFx *a) {
    f32 t;
    if (a->unk19C & 0x10) {
        t = a->unk1A0 + D_800D2988 * D_800C8EF0;
        a->unk1A0 = t;
        if (t < D_800C8EF4) {
            a->unk194 = t * D_800C8EF8;
        } else {
            a->unk19C &= ~0x10;
            a->unk194 = D_800C8EFC;
        }
    }
}
