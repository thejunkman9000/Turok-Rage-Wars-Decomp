#include "b02_types.h"

void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00209308(B2Ctl *ctl, Vec3f *target, f32 a2, f32 a3);
void func_00209910(B2Ctl *ctl, f32 x, s32 n);
void func_00209E80(B2Ctl *ctl);
Vec3f *func_0020C994(B2Mgr *m, s32 idx);
void func_002720EC(Vec3f *v);
f32 func_0029D044(f32 a, f32 b);
extern B2Mgr D_8013B364;
extern f32 D_800C6CF0;
extern f32 D_800C6CF4;
extern f32 D_800C6CF8;
extern f32 D_800C6CFC;
extern f32 D_800C6D00;
extern f32 D_800C6D04;
extern f32 D_800C6D08;
extern f32 D_800C6D0C;
extern f32 D_800C6D10;

void func_00208EB0(B2Ctl *ctl) {
    Vec3f d;
    Vec3f a;
    Vec3f b;
    Vec3f c;
    Vec3f e;
    Vec3f *p;
    Vec3f *ctlp;
    Vec3f *op;
    B2Actor *o;
    s32 f1;
    s32 f2;
    f32 len;
    f32 ang;
    f32 t;
    f32 w;
    f32 zero;

    zero = 0.0f;
    if (ctl->target == NULL || ctl->unk308 != 0 || ctl->unk30C != 0 || ctl->unk314 != 0) {
        func_00209308(ctl, &ctl->v2C, 2.0f, zero);
    } else {
        func_00209308(ctl, &ctl->target->owner->pos, 2.0f, zero);
        func_00209E80(ctl);
    }
    if (ctl->unk300 == 0) {
        ctlp = &ctl->v2C;
        o = ctl->owner;
        op = &o->pos;
        f2 = o->flags38 & 0x2000;
        f1 = o->flags38 & 0x1000;
        func_00271FD8(&d, ctlp, op);
        len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
        if (f1 != 0) {
            if (D_800C6CF0 < len) {
                w = func_00209308(ctl, ctlp, 2.0f, zero);
                if (w < zero ? -w < D_800C6CF4 : w < D_800C6CF8) {
                    o->unk6A8 = D_800C6CFC;
                }
                if ((f2 != 0 || f1 != 0) && ctl->unk304 != 0) {
                    func_00209910(ctl, func_0029D044(d.y, sqrtf(d.x * d.x + d.z * d.z)), 1);
                    o->unk6A8 = D_800C6D00;
                }
            }
        } else {
            ang = ctl->owner->unk6C + D_800C6D04;
            b.x = sinf(ang);
            b.y = 0.0f;
            b.z = cosf(ang);
            a.x = ctl->v2C.x - op->x;
            a.y = 0.0f;
            a.z = ctl->v2C.z - op->z;
            p = func_0020C994(&D_8013B364, ctl->unk4);
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
            e.x = a.x + c.x;
            e.y = 0.0f;
            e.z = a.z + c.z;
            func_002720EC(&e);
            o->unk6A8 = e.x * b.x + e.y * b.y + e.z * b.z;
            w = b.x;
            b.x = b.z;
            b.y = 0.0f;
            b.z = -w;
            o->unk6A4 = e.x * b.x + e.z * b.z;
        }
        if ((f2 != 0 || f1 != 0) && ctl->unk304 != 0) {
            func_00209910(ctl, func_0029D044(d.y, sqrtf(d.x * d.x + d.z * d.z)), 1);
            o->unk6A8 = D_800C6D08;
        }
        if (ctl->owner->unk650 == 0xF) {
            if (ctl->v2C.y < op->y) {
                o->unk6A8 = D_800C6D0C;
            } else {
                o->unk6A8 = D_800C6D10;
            }
        }
        if (ctl->unk310 != 0) {
            o->unk6A4 = 0.0f;
            o->unk6A8 = 0.0f;
        }
    }
}
