#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#include "b03_types.h"

extern f32 D_800C7270;
extern f32 D_800C7274;
extern s32 D_801041F0;
f32 sinf(f32 x);
f32 cosf(f32 x);
f32 sqrtf(f32 x);
s32 func_002462D8(ActorB *a, Vec3f p, void *out);
f32 func_0024D388(ActorB *a);
void func_00274090(f32 *ang);
f32 func_00274640(f32 x);

static inline f32 func_00216F44(ActorB *o, Vec3f v) {
    f32 dx, dz, len, s, c, q, r;
    dx = v.x - o->pos.x;
    dz = v.z - o->pos.z;
    len = sqrtf(dx * dx + dz * dz);
    if (len == 0.0f) return 0.0f;
    s = sinf(o->unk6C);
    c = -cosf(o->unk6C);
    q = ((dx * -s) + (dz * c)) / len;
    q = MAX(-1.0f, MIN(1.0f, q));
    __asm__("" : : "f"(s));
    r = func_00274640(q);
    if (!((dx * c + dz * s) > 0.0f))
        r = -r;
    return r;
}

f32 func_00215868(ActorB *a, Vec3f pos, s32 arg4, f32 arg5) {
    Vec3f c;
    s32 hit;
    f32 ang;
    f32 r;
    f32 step;
    f32 f;
    s32 n;
    s32 m;
    s32 par;

    r = func_00216F44(a, pos);
    if (a->flags & 0x200) {
        if (func_002462D8(a, pos, &hit) == 0) {
            return r;
        }
        if (arg4 == 0 || D_801041F0 != arg4) {
            goto loop;
        }
        return r;
    }
    return r;
found:
    ang += f;
    func_00274090(&ang);
    return ang;
loop:
    c.y = a->pos.y;
    par = ((u32)a % 744) & 1;
    for (n = 1; n < 6; n++) {
        step = (f32)n * 0.52359885f;
        for (m = 0; m < 2; m++) {
            ang = r;
            if (m != par) {
                f = 0.26179942f;
                ang = r + step;
            } else {
                ang = r - step;
                f = -0.26179942f;
            }
            c.x = a->pos.x + sinf(a->unk6C + 3.1415927f + ang) * (arg5 * func_0024D388(a));
            c.z = a->pos.z + cosf(a->unk6C + 3.1415927f + ang) * (arg5 * func_0024D388(a));
            if (func_002462D8(a, c, NULL) == 0) goto found;
        }
    }
    return r;
}
