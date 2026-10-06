#include "b20_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, u8 *b);
void *func_0028FD94();

s32 func_0028D268(Level *lv, s32 unused, Vec3f *pt) {
    Vec3f d;
    f32 bestIdx = -1.0f;
    f32 bestD = 0.0f;
    s32 i = 0;
    s32 *t;
    s32 n;
    u8 *p;
    t = func_0028FD94(func_0028FD94(lv->unk7C), 1);
    n = t[1];
    p = (u8 *)(t + 2);
    if (n > 0) {
        do {
            f32 dd;
            func_00271FD8(&d, pt, p);
            dd = d.x * d.x + d.y * d.y + d.z * d.z;
            if (bestIdx < 0.0f || dd < bestD) {
                bestIdx = (f32)i;
                bestD = dd;
            }
            i++;
            p += 0x38;
        } while (i < n);
    }
    return (s32)bestIdx;
}
