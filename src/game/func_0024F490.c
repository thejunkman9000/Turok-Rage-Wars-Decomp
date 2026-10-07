#include "b11_types.h"

extern f32 D_800D2988;
extern f32 D_800C8EE0;
extern f32 D_800C8EE4;
extern f32 D_800C8EE8;
extern f32 D_800C8EEC;
extern s32 D_80146894;
extern s32 D_800D2B40;
s32 func_0024F848(ObjFx *a);

void func_0024F490(ObjFx *a) {
    ObjDef *d;
    f32 t;
    a->unk1 = func_0024F848(a);
    a->unk3 = ((u8 *)a->def)[0x12];
    if (D_80146894 == 0) {
        d = a->def;
        if (d->type == 12) {
            a->unk1A4 = D_800D2988 * d->unk20;
        } else if (a->unk19C & 0x10) {
            t = a->unk1A0 + D_800D2988 * D_800C8EE0;
            a->unk1A0 = t;
            if (t < D_800C8EE4) {
                a->unk194 = t * D_800C8EE8;
            } else {
                a->unk19C &= ~0x10;
                a->unk194 = D_800C8EEC;
            }
        }
        if (a->unk14 != 0) {
            a->unk1C0 = a->unk14->unk1C;
        } else {
            a->unk1C0 = D_800D2B40;
        }
    }
}
