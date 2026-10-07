#include "b02_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00209308(B2Ctl *ctl, Vec3f *target, f32 a2, f32 a3);
void func_00209910(B2Ctl *ctl, f32 x, s32 n);
Vec3f *func_0020C994(B2Mgr *m, s32 idx);
f32 func_0029D044(f32 a, f32 b);
extern B2Mgr D_8013B364;
extern f32 D_800C6CCC;
extern f32 D_800C6CD0;
extern f32 D_800C6CD4;
extern f32 D_800C6CD8;
extern f32 D_800C6CDC;
extern f32 D_800C6CE0;
extern f32 D_800C6CE4;
extern f32 D_800C6CE8;
extern f32 D_800C6CEC;

void func_00208AAC(B2Ctl *ctl) {
    Vec3f d;
    Vec3f a;
    Vec3f b;
    Vec3f c;
    Vec3f *p;
    Vec3f *ctlp;
    B2Actor *o;
    s32 f1;
    s32 f2;
    f32 len;
    f32 ang;
    f32 t;
    f32 dot;
    f32 w;
    f32 zero;
    Vec3f *op;
    B2Mgr *m;

    if (ctl->unk300 == 0) {
        ctlp = &ctl->v2C;
        o = ctl->owner;
        op = &o->pos;
        f2 = o->flags38 & 0x2000;
        f1 = o->flags38 & 0x1000;
        func_00271FD8(&d, ctlp, op);
        m = &D_8013B364;
        zero = 0.0f;
        len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        if (f1 != 0) {
            if (D_800C6CCC < len) {
                w = func_00209308(ctl, ctlp, 2.0f, zero);
                if (w < zero ? -w < D_800C6CD0 : w < D_800C6CD4) {
                    o->unk6A8 = D_800C6CD8;
                }
                if ((f2 != 0 || f1 != 0) && ctl->unk304 != 0) {
                    func_00209910(ctl, func_0029D044(d.y, sqrtf(d.x * d.x + d.z * d.z)), 1);
                    o->unk6A8 = D_800C6CDC;
                }
            }
        } else {
            func_00209308(ctl, ctlp, 2.0f, zero);
            ang = ctl->owner->unk6C + D_800C6CE0;
            b.x = sinf(ang);
            b.y = 0.0f;
            b.z = cosf(ang);
            ang = func_0029D044(ctl->v2C.z - op->z, ctl->v2C.x - op->x);
            a.x = cosf(ang);
            a.y = 0.0f;
            a.z = sinf(ang);
            o->unk6A8 = a.x * b.x + a.y * b.y + a.z * b.z;
            p = func_0020C994(m, ctl->unk4);
            c = *p;
            c.x = c.x - ctl->v2C.x;
            c.z = c.z - ctl->v2C.z;
            c.y = 0.0f;
            c.z = -c.z;
            ang = func_0029D044(c.x, c.z);
            c.x = cosf(ang);
            c.z = sinf(ang);
            t = a.x * c.x + a.y * c.y + a.z * c.z;
            c.x = c.x * t;
            c.z = c.z * t;
            w = b.x;
            b.x = b.z;
            b.y = 0.0f;
            b.z = -w;
            o->unk6A4 = c.x * b.x + c.z * b.z;
        }
        if ((f2 != 0 || f1 != 0) && ctl->unk304 != 0) {
            func_00209910(ctl, func_0029D044(d.y, sqrtf(d.x * d.x + d.z * d.z)), 1);
            o->unk6A8 = D_800C6CE4;
        }
        if (ctl->owner->unk650 == 0xF) {
            if (ctl->v2C.y < op->y) {
                o->unk6A8 = D_800C6CE8;
            } else {
                o->unk6A8 = D_800C6CEC;
            }
        }
        if (ctl->unk310 != 0) {
            o->unk6A4 = 0.0f;
            o->unk6A8 = 0.0f;
        }
    }
}
