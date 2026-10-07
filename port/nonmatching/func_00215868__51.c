#include "b03_types.h"

extern f32 D_800C7270;
extern f32 D_800C7274;
extern f32 D_800C7278;
extern f32 D_800C727C;
extern f32 D_800C7280;
extern f32 D_800C7284;
extern s32 D_801041F0;
f32 sinf(f32 x);
f32 cosf(f32 x);
f32 sqrtf(f32 x);
s32 func_002462D8(ActorB *a, Vec3f p, void *out);
f32 func_0024D388(ActorB *a);
void func_00274090(f32 *ang);
f32 func_00274640(f32 x);

f32 func_00215868(ActorB *a, Vec3f pos, s32 arg4, f32 arg5) {
    Vec3f c;
    Vec3f v;
    s32 hit;
    f32 ang;
    f32 dx;
    f32 dz;
    f32 len;
    f32 r;
    f32 s;
    f32 co;
    f32 x;
    f32 step;
    f32 f;
    s32 n;
    s32 m;
    s32 par;

    v = pos;
    dx = v.x - a->pos.x;
    dz = v.z - a->pos.z;
    len = sqrtf(dx * dx + dz * dz);
    if (len == 0.0f) {
        r = 0.0f;
    } else {
        s = sinf(a->unk6C);
        co = -cosf(a->unk6C);
        x = (dx * -s + dz * co) / len;
        if (D_800C7270 < x) {
            x = D_800C7270;
        }
        if (x < D_800C7274) {
            x = D_800C7274;
        }
        if (D_800C7270 < x) {
            x = D_800C7270;
        }
        r = func_00274640(x);
        if (!(dx * co + dz * s > 0.0f)) {
            r = -r;
        }
    }
    if (a->flags & 0x200) {
        if (func_002462D8(a, pos, &hit) == 0) {
            return r;
        }
        if (arg4 == 0 || D_801041F0 != arg4) {
            step = D_800C7278;
            c.y = a->pos.y;
            n = 1;
            m = 0;
            par = ((u32)a % 744) & 1;
            while (1) {
                ang = r;
                if (m != par) {
                    f = D_800C7280;
                    ang = r + (f32)n * D_800C7278;
                } else {
                    ang = r - (f32)n * D_800C7278;
                    f = D_800C7284;
                }
                c.x = a->pos.x + sinf(a->unk6C + D_800C727C + ang) * (arg5 * func_0024D388(a));
                c.z = a->pos.z + cosf(a->unk6C + D_800C727C + ang) * (arg5 * func_0024D388(a));
                m++;
                if (func_002462D8(a, c, NULL) != 0) {
                    if (m >= 2) {
                        n++;
                        m = 0;
                        if (n >= 6) {
                            return r;
                        }
                    }
                    continue;
                }
                ang += f;
                func_00274090(&ang);
                return ang;
            }
        }
    }
    return r;
}
