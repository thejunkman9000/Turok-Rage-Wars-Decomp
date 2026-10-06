#include "b22_types.h"
extern f32 D_800CAE38;
void func_0029F8AC(Vec3f *out, Vec3f *in, s32 n, f32 ox, f32 sx, f32 oy, f32 sy)
{
    s32 i;
    for (i = 0; i < n; i++) {
        if (in[i].z > D_800CAE38) {
            out[i].x = ox + sx * (in[i].x / in[i].z);
            out[i].y = oy + sy * (in[i].y / in[i].z);
            out[i].z = in[i].z;
        } else {
            out[i].x = 0;
            out[i].y = 0;
            out[i].z = 0;
        }
    }
}
