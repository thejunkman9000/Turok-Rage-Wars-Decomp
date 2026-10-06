#include "b20_types.h"

void func_0028FFB0(u8 *base, s32 zero, s32 a, Vec3f z, Vec3f v, s32 b, f32 f);

void func_0028BFB4(Level *lv, s32 a1, Vec3f v, s32 x, f32 f) {
    Vec3f z;
    z.x = 0;
    z.y = 0;
    z.z = 0;
    func_0028FFB0((u8 *)lv + 0x11778, 0, x, z, v, a1, f);
}
