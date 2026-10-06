#include "b08_types.h"


void func_00272A80(void *a, s32 b, Vec3f *out);

extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_00239234(u8 *o, s32 b, f32 *outx, f32 *outy) {
    Vec3f v;

    func_00272A80(o + 0x1E0, b, &v);
    *outx = v.x * (f32)(D_800E28D0 / 2) + (f32)(D_800E28D0 / 2);
    *outy = v.y * (f32)(-D_800E28D4 / 2) + (f32)(D_800E28D4 / 2);
}
