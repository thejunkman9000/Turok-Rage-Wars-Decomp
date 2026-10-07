#include "b11_types.h"

extern f32 D_800C8CA0;

void func_0024D018(f32 *m, f32 *q, f32 *pos) {
    f32 x = q[0];
    f32 y = q[1];
    f32 z = q[2];
    f32 w = q[3];
    f32 xx = x * x;
    f32 yy = y * y;
    f32 zz = z * z;
    f32 ww = w * w;
    f32 x2 = x + x;
    f32 xy = x2 * y;
    f32 w2 = w + w;
    f32 wz = w2 * z;
    f32 xz = x2 * z;
    f32 wy = w2 * y;
    f32 wx = w2 * x;
    f32 y2 = y + y;
    f32 yz = y2 * z;
    m[1] = xy + wz;
    m[2] = xz - wy;
    m[4] = xy - wz;
    m[8] = xz + wy;
    m[6] = yz + wx;
    m[9] = yz - wx;
    m[0] = ww + xx - yy - zz;
    m[5] = ww - xx + yy - zz;
    m[10] = ww - xx - yy + zz;
    m[12] = pos[0];
    m[13] = pos[1];
    m[14] = pos[2];
    m[15] = D_800C8CA0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
}
