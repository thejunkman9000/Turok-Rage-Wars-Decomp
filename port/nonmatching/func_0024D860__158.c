
#include "b11_types.h"
#include "b09_types.h"

extern f32 D_80115DEC;
f32 sinf(f32);
f32 cosf(f32);
s32 func_00275854(void *t);
void func_00275D04(Vec3f *o, void *t);
void func_00272088(Vec3f *o, Vec3f *a, Vec3f *b);
void func_002720EC(Vec3f *v);
f32 func_00274640(f32 x);
Quat4 func_0024D718(Obj *o);
f32 func_00240A88(B09Quad *q, f32 x0, f32 z0, f32 x1, f32 z1);
void func_00270D40(Quat4 *dst, f32 t, Quat4 *q1, Quat4 *q2);

static inline s32 m03_f1(Obj *o) {
    if (o->type == 1) {
        return o->flags & 1;
    }
    return 0;
}

Quat4 func_0024D860(Obj *o) {
    Vec3f dir;
    Vec3f fwd;
    Vec3f cross;
    Quat4 qa;
    Quat4 qb;
    Quat4 res;
    B09Quad quad;
    Obj *p;
    f32 t;
    f32 a;
    f32 s;
    f32 sn;
    f32 cs;
    f32 h;
    f32 k;
    f32 zero;

    if (o->unk14 != 0 && m03_f1(o) == 0) {
        if (o->type == 1) {
            if ((o->unk38 & 3) == 0) {
                p = o;
                if (o->flags & 0x300000) {
                    if (func_00275854(o->unk14) == 0) {
                        func_00275D04(&dir, o->unk14);
                        fwd.x = 0.0f;
                        fwd.z = 0.0f;
                        fwd.y = 1.0f;
                        func_00272088(&cross, &fwd, &dir);
                        func_002720EC(&cross);
                        t = func_00274640(fwd.x * dir.x + fwd.y * dir.y + fwd.z * dir.z);
                        D_80115DEC = sinf((0.43633235f < t) ? 0.16362463f : t * 0.375f);
                        qa.x = cross.x * D_80115DEC;
                        qa.y = cross.y * D_80115DEC;
                        qa.z = cross.z * D_80115DEC;
                        qa.w = cosf((0.43633235f < t) ? 0.16362463f : t * 0.375f);
                        qa = func_0024D718(o);
                        sn = sinf(p->unk6C.f);
                        cs = cosf(p->unk6C.f);
                        *(Vec3f *)&quad.nx = *(Vec3f *)((u8 *)p + 0x44);
                        quad.v[0].x = p->pos.x;
                        quad.v[0].y = p->unk40;
                        quad.v[0].z = p->pos.z;
                        h = func_00240A88(&quad, o->pos.x, o->pos.z, o->pos.x - sn, o->pos.z - cs);
                        a = 18.75f;
                        if (!(25.0f < h)) {
                            a = h * 0.75f;
                        }
                        k = 0.5f;
                        a = a * k;
                        D_80115DEC = sinf(a);
                        qb.y = 0;
                        qb.x = cs * D_80115DEC;
                        qb.z = -sn * D_80115DEC;
                        qb.w = cosf(a);
                        func_00270D40(&res, k, &qb, &qa);
                        return res;
                    }
                }
                else {
                    return func_0024D718(o);
                }
            }
        } else {
            return func_0024D718(o);
        }
    }
    zero = 0.0f;
    qa.z = zero;
    qa.y = zero;
    qa.x = zero;
    qa.w = 1.0f;
    return qa;
}
