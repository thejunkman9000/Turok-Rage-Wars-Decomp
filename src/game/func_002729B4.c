#include "b16_types.h"
void func_002729B4(B16Mtx4 m, Vec3f *src, Vec3f *dst, s32 n) {
    f32 x, y, z;
    s32 i;
    for (i = n - 1; i != -1; i--) {
        x = src->x; y = src->y; z = src->z;
        dst->x = m[0][0] * x + m[1][0] * y + m[2][0] * z + m[3][0];
        dst->y = m[0][1] * x + m[1][1] * y + m[2][1] * z + m[3][1];
        dst->z = m[0][2] * x + m[1][2] * y + m[2][2] * z + m[3][2];
        src++;
        dst++;
    }
}
