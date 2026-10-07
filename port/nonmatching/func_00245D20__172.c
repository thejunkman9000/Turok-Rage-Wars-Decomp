

#include "r04_types.h"

extern f32 D_800C88E0;
extern f32 D_800C88E4;
extern f32 D_800C88E8;
extern f32 D_800C88EC;
extern f32 D_800C88F0;
extern f32 D_800C88F4;
extern f32 D_800C88F8;
extern f32 D_800C88FC;
extern f32 D_800C8900;
extern f32 D_800C8904;
extern f32 D_800C8908;
extern f32 D_800C890C;
extern f32 D_800C8910;
extern f32 D_800D0670;
extern f32 D_800D0674;
extern f32 D_800D2988;
s32 func_0024E61C(R4Pl *o);
void func_0027200C(Vec3f *out, Vec3f *a, f32 s);
f32 func_00271B18(Vec3f *v);
void func_00274090(f32 *a);
void func_00272038(Vec3f *v, f32 s, Vec3f *out, Vec3f *d);

void func_00245D20(R4Pl *o, R4In *in, f32 *out, s32 f) {
    Vec3f d;
    Vec3f t;
    f32 ang1;
    f32 ang0;
    f32 fs;
    f32 s;
    f32 w;
    f32 a;
    f32 b;
    f32 c;
    f32 e;
    s32 g;
    s32 m;
    u32 fl;
    R4Pl *p;

    if (o->type == 1) {
        p = o;
        fl = p->flags;
        if (fl & 0x3000) {
            g = 1;
        } else if (fl & 0x4000) {
            g = func_0024E61C(p);
        } else {
            g = 0;
        }
        m = p->flags & 3;
    } else {
        g = 0;
        m = 0;
    }
    if (m != 0 || (g == 0 && !(in->f52 & 0x8000))) {
        o->v.x = 0.0f;
        o->v.y = 0.0f;
        o->v.z = 0.0f;
        return;
    }
    if ((in->f52 & 0x100) && f != 0) {
        d.x = in->b5F * D_800C88E0;
        d.y = in->b60 * D_800C88E0;
        d.z = in->b61 * D_800C88E0;
        fs = ((f32)in->b5D + D_800C88E8) * D_800C88EC;
        func_0027200C(&d, &d, in->b5D * D_800C88E4);
        if (in->f52 & 0x600) {
            if (in->f52 & 0x400) {
                fs = -fs;
            }
            if (o->type == 1) {
                o->f6C = o->f6C + fs;
            }
        }
        if ((in->f52 & 0x2000) && o->type == 1) {
            p = o;
            t = d;
            t.y = 0.0f;
            ang1 = func_00271B18(&t);
            ang0 = o->f6C;
            if (ang1 != ang0) {
                func_00274090(&ang0);
                func_00274090(&ang1);
                a = ang0;
                b = ang1;
                if (b < a) {
                    c = b + D_800C88F0;
                    e = a - b;
                    w = c - a;
                } else {
                    c = b - D_800C88F4;
                    e = b - a;
                    w = a - c;
                }
                if (w < e) {
                    ang1 = c;
                }
                if (ang0 < ang1) {
                    ang0 = ang0 + in->b5D * D_800D0674 * D_800D2988 * D_800C88F8;
                    if (ang1 < ang0) {
                        ang0 = ang1;
                    }
                } else {
                    ang0 = ang0 - in->b5D * D_800D0674 * D_800D2988 * D_800C88FC;
                    if (ang0 < ang1) {
                        ang0 = ang1;
                    }
                }
                func_00274090(&ang0);
            }
            p->f6C = ang0;
        }
    } else {
        d.x = 0.0f;
        d.y = 0.0f;
        d.z = 0.0f;
    }
    s = in->b5D * D_800D0670 * D_800D2988;
    s = (s < 0.0f) ? 0.0f : ((s > D_800C8900) ? D_800C8900 : ((s < 0.0f) ? 0.0f : s));
    func_00272038(&o->v, s, &o->v, &d);
    out[0] = out[0] + o->v.x;
    out[2] = out[2] + o->v.z;
    if (in->f52 & 0x100) {
        if (d.y != 0.0f) {
            o->f20 = 0.0f;
        } else {
            w = o->v.y;
            o->v.y = w + (d.y - w) * D_800C8904;
        }
        o->f20 = o->f20 + ((2.0f * (o->v.y * D_800C8908)) + D_800C890C);
    } else {
        o->v.y = o->v.y + (d.y - o->v.y) * D_800C8910;
    }
}



