#include "b08_types.h"

void func_00271FD8(Vec3f *out, void *a, s32 b);

f32 func_0023945C(u8 *p, s32 b) {
    Vec3f v;

    func_00271FD8(&v, p + 0x128, b);
    return b08_sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}
