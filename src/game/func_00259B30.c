#include "m04_types.h"

extern f32 D_800C8FF0;
extern f32 D_800C8FF4;
extern f32 D_800C8FF8;
void func_00271FD8(M04Vec3 *out, void *src, s32 a);
void func_00272C3C(void *src, M04Vec3 *a, M04Vec3 *out);
void func_002720EC(M04Vec3 *v);
f32 func_00274640(f32 x);
f32 sinf(f32 x);
f32 fabsf(f32 x);

s32 func_00259B30(s32 a0, u8 *obj) {
    M04Vec3 r;
    M04Vec3 d;
    M04Vec3 w;
    f32 s;
    f32 zero;
    if (obj == 0) {
        return 0x40;
    }
    func_00271FD8(&d, obj + 0x128, a0);
    if (d.x * d.x + d.z * d.z < D_800C8FF0) {
        return 0x40;
    }
    func_00272C3C(obj + 0x160, &d, &w);
    w.y = 0.0f;
    zero = w.y;
    r.y = zero;
    r.x = zero;
    r.z = D_800C8FF4;
    func_002720EC(&w);
    s = sinf(func_00274640(w.x * r.x + w.y * r.y + w.z * r.z));
    if (w.x == zero) {
        return 0x40;
    }
    if (zero < w.x) {
        if (s < zero) {
            s = -s;
        }
    } else {
        s = -fabsf(s);
    }
    return (s16)(s32)(s * D_800C8FF8 + D_800C8FF8);
}
