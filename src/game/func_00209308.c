#include "b02_types.h"

f32 func_00216F44(B2Actor *a, f32 x, f32 y, f32 z);
void func_00209910(B2Ctl *ctl, f32 x, s32 n);
extern f32 D_800C6D14;
extern f32 D_800C6D18;
extern f32 D_800C6D1C;
extern f32 D_800C6D20;
extern f32 D_800C6D24;
extern f32 D_800C6D28;
extern f32 D_800C6D2C;
extern f32 D_800C6D30;
extern f32 D_800C6D34;
extern f32 D_800C6D38;
extern f32 D_800C6D3C;
extern f32 D_800C6D40;
extern f32 D_800C6D44;
extern f32 D_800C6D48;
extern f32 D_800C6D4C;
extern f32 D_800C6D50;
extern f32 D_800C6D54;
extern f32 D_800C6D58;
extern f32 D_800C6D5C;
extern f32 D_800C6D60;

f32 func_00209308(B2Ctl *ctl, Vec3f *target, f32 a2, f32 a3) {
    f32 d;
    f32 sign;
    f32 k;
    f32 v;
    f32 w;

    d = func_00216F44(ctl->owner, target->x, target->y, target->z) + a3;
    if (d > D_800C6D14) {
        d -= D_800C6D18;
    } else if (d < D_800C6D1C) {
        d += D_800C6D20;
    }
    sign = D_800C6D24;
    if (d > 0.0f) {
        sign = D_800C6D28;
    }
    k = a2 * D_800C6D2C;
    if (d < 0.0f ? k < -d : k < d) {
        if (d < 0.0f ? D_800C6D30 < -d : D_800C6D34 < d) {
            ctl->owner->unk69C = sign;
        } else {
            if (d < 0.0f ? D_800C6D38 < -d : D_800C6D3C < d) {
                v = D_800C6D40;
            } else if (d < 0.0f ? D_800C6D44 < -d : D_800C6D48 < d) {
                v = D_800C6D4C;
            } else if (d < 0.0f ? D_800C6D50 < -d : D_800C6D54 < d) {
                v = D_800C6D58;
            } else {
                v = D_800C6D5C;
            }
            ctl->owner->unk69C = sign * v;
        }
    }
    func_00209910(ctl, (ctl->owner->unk594 == 2 ? ctl->unk24C + ctl->unk254 : ctl->unk248 + ctl->unk250) * D_800C6D60, (s32)a2);
    return d;
}
