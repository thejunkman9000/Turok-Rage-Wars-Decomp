#include "b02_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00209308(B2Ctl *ctl, Vec3f *target, f32 a2, f32 a3);
void func_00209910(B2Ctl *ctl, f32 x, s32 n);
void func_00209E80(B2Ctl *ctl);
Vec3f *func_0020C994(B2Mgr *m, s32 idx);
void func_002720EC(Vec3f *v);
f32 func_0029D044(f32 a, f32 b);
extern B2Mgr D_8013B364;

void func_00208EB0(B2Ctl *ctl) {
    Vec3f d;
    Vec3f a;
    Vec3f b;
    Vec3f c;
    Vec3f e;
    Vec3f *p;
    Vec3f *ctlp;
    Vec3f *op;
    Vec3f *new_var;
    B2Actor *o;
    s32 f1;
    s32 f2;
    f32 len;
    f32 ang;
    f32 t;
    f32 w;
    f32 dy;
    f32 ang3;
    B2Mgr *m;

    if (ctl->target == NULL || ctl->unk308 != 0 || ctl->unk30C != 0 || ctl->unk314 != 0) {
        func_00209308(ctl, &ctl->v2C, 2.0f, 0.0f);
    } else {
        func_00209308(ctl, &ctl->target->owner->pos, 2.0f, 0.0f);
        func_00209E80(ctl);
    }
    if (ctl->unk300 == 0) {
        ctlp = &ctl->v2C;
        op = &ctl->owner->pos;
        o = ctl->owner;
        f2 = o->flags38 & 0x2000;
        new_var = op;
        f1 = o->flags38 & 0x1000;
        func_00271FD8(&d, ctlp, new_var);
        len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        m = &D_8013B364;
        if (f1 != 0) {
            if (1e+01f < len) {
                ang = func_00209308(ctl, ctlp, 2.0f, 0.0f);
                if (ang < 0.0f ? -ang < 0.26179942f : ang < 0.26179942f) {
                    o->unk6A8 = 0.5f;
                }
                if ((f2 != 0 || f1 != 0) && ctl->unk304 != 0) {
                    dy = d.y; func_00209910(ctl, func_0029D044(dy, sqrtf(d.x * d.x + d.z * d.z)), 1);
                    o->unk6A8 = 1.0f;
                }
            }
        } else {
            ang = ctl->owner->unk6C + 3.1415927f;
            b.x = sinf(ang);
            b.y = 0.0f;
            b.z = cosf(ang);
            a.x = ctl->v2C.x - new_var->x;
            *(u32 *)&a.y = 0;
            a.z = ctl->v2C.z - new_var->z;
            if (o != NULL) {
                p = func_0020C994(m, ctl->unk4);
            } else {
                p = func_0020C994(m, ctl->unk4);
            }
            c = *p;
            c.x = c.x - ctl->v2C.x;
            c.z = c.z - ctl->v2C.z;
            c.y = c.x;
            c.x = -c.z;
            c.z = c.y;
            c.y = 0.0f;
            ang3 = func_0029D044(c.z, c.x);
            c.x = cosf(ang3);
            c.z = sinf(ang3);
            t = a.x * c.x + a.y * c.y + a.z * c.z;
            c.x = c.x * t;
            c.z = c.z * t;
            e.x = a.x + c.x;
            e.y = 0.0f;
            e.z = a.z + c.z;
            func_002720EC(&e);
            o->unk6A8 = e.x * b.x + e.y * b.y + e.z * b.z;
            b.y = b.x;
            b.x = b.z;
            b.z = -b.y;
            b.y = 0.0f;
            o->unk6A4 = e.x * b.x + e.z * b.z;
        }
        if ((f2 != 0 || f1 != 0) && ctl->unk304 != 0) {
            dy = d.y; func_00209910(ctl, func_0029D044(dy, sqrtf(d.x * d.x + d.z * d.z)), 1);
            o->unk6A8 = 1.0f;
        }
        if (ctl->owner->unk650 == 0xF) {
            if (new_var->y > ctl->v2C.y) {
                o->unk6A8 = (-1.0f);
            } else {
                o->unk6A8 = 1.0f;
            }
        }
        if (ctl->unk310 != 0) {
            o->unk6A4 = 0.0f;
            o->unk6A8 = 0.0f;
        }
    }
}
