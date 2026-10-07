#include "b08_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00265734(f32 x);
f32 func_00274B00(f32 a, f32 b);

extern f32 D_800C8180;
extern f32 D_800C8184;
extern f32 D_800C8188;
extern f32 D_800C818C;

#define WAVE(w, c, k)                                  \
    switch ((c)->mode) {                               \
    case 1:                                            \
        w = sinf((c)->d * (k)) * (c)->v.z;             \
        break;                                         \
    case 0:                                            \
        w = func_00274B00(-(c)->v.z, (c)->v.z);        \
        break;                                         \
    default:                                           \
        w = 0.0f;                                      \
        break;                                         \
    }

void func_00233920(ChanObj *o, Vec3f p, Vec3f *out) {
    f32 s;
    Chan *c;
    f32 w;

    func_00271FD8(&p, &p, &o->ch[0].v);
    s = b08_sqrtf(p.x * p.x + p.y * p.y + p.z * p.z);
    if (s < o->ch[0].d) {
        s = func_00265734(D_800C8180 - s / o->ch[0].d);
        c = &o->ch[1];
        WAVE(w, c, D_800C8184)
        out->x = out->x + w * s;
        c = &o->ch[2];
        WAVE(w, c, D_800C8188)
        out->y = out->y + w * s;
        c = &o->ch[3];
        WAVE(w, c, D_800C818C)
        out->z = out->z + w * s;
    }
}
