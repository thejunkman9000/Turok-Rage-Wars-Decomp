#include "m05_types.h"

typedef struct M5Tgt { u8 pad0[0x248]; M5Vec3 pos; } M5Tgt;
f32 Trunc16ToF32(u16);
f32 sqrtf(f32);
extern f32 D_800C9C3C;
extern f32 D_800C9C40;
extern f32 D_800C9C44;
extern f32 D_800C9C48;
extern f32 D_800C9C4C;
extern f32 D_800C9C50;
extern f32 D_800C9C54;
extern f32 D_800C9C58;
extern f32 D_800C9C5C;
extern f32 D_800C9C60;
extern f32 D_800C9C64;

void *func_0025C97C(s32, s32, M5Vec3 *, M5Vec3 *, s32);
void func_0025CA44(s32, M5Handle *);
s32 func_0025CC8C();
void func_00270D40(M5Vec4 *, f32, M5Vec4 *, M5Vec4 *);
void func_00271888(M5Vec4 *, M5Vec3 *);
void func_00271FA4(M5Vec3 *, M5Vec3 *, M5Vec3 *);
void func_00271FD8(M5Vec3 *, M5Vec3 *, M5Vec3 *);
void func_0027200C(M5Vec3 *, M5Vec3 *, f32);
void func_002720EC(M5Vec3 *);
void func_00272908(M5Mtx *, M5Vec3 *, M5Vec3 *);
void func_00274214(M5Vec4 *);
void func_002742B4(M5Vec4 *, M5Mtx *);
void func_00279E40(M5Obj *, f32);
void func_00284408(M5Obj *);

void func_0027A0F4(M5Obj *o) {
    M5Vec3 tp;
    M5Vec3 d;
    M5Vec3 ax;
    M5Vec4 q0, q1, q2;
    M5Mtx q3;
    M5Vec3 push;
    M5Vec3 vel;
    M5Tgt *tgt;
    M5Handle *h;
    f32 speed, dist, w, t, a, len, lim;
    s32 c;

    if (o->flags & 0x10000) {
        if (o->handle != 0) {
            func_0025CA44(func_0025CC8C(), o->handle);
            o->handle = 0;
        }
    } else {
        h = o->handle;
        if (h != 0) {
            if (h->idC != 0x730 || h->id8 == -1) {
                func_00284408(o);
                goto mk;
            }
        } else {
mk:
            o->handle = func_0025C97C(func_0025CC8C(), 0x730, &o->pos, &o->pos, -1);
        }
        tgt = (M5Tgt *)o->tgt;
        if (tgt != 0 && o->f140 > D_800C9C3C) {
            func_00271888(&q0, &o->vel);
            speed = sqrtf(o->pos2.x * o->pos2.x + o->pos2.y * o->pos2.y + o->pos2.z * o->pos2.z);
            tp = tgt->pos;
            func_00271FD8(&d, &tp, &o->pos);
            dist = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
            if (dist < D_800C9C40) {
                func_00271888(&q2, &d);
                func_002742B4(&q2, &q3);
                *(s32 *)&ax.x = 0;
                *(s32 *)&ax.y = 0;
                ax.z = D_800C9C44;
                func_00272908(&q3, &ax, &o->vel);
                func_0027200C(&o->pos2, &o->vel, speed);
                return;
            }
            if (D_800C9C48 < dist) {
                tp.y += D_800C9C40;
                func_00271FD8(&d, &tp, &o->pos);
                dist = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
            }
            func_002720EC(&d);
            func_00271888(&q1, &d);
            if (dist < D_800C9C4C) {
                t = dist - D_800C9C50;
                if (t < 0.0f) {
                    w = 0.0f;
                } else {
                    w = t * D_800C9C54;
                }
                w = D_800C9C5C - w * D_800C9C58;
            } else {
                w = D_800C9C60;
            }
            func_00274214(&q1);
            func_00274214(&q0);
            func_00270D40(&q2, w, &q0, &q1);
            func_002742B4(&q2, &q3);
            *(s32 *)&ax.x = 0;
            *(s32 *)&ax.y = 0;
            ax.z = D_800C9C64;
            func_00272908(&q3, &ax, &o->vel);
            func_0027200C(&o->pos2, &o->vel, speed);
        }
        a = Trunc16ToF32(o->def->lim->a);
        if (a != 0.0f) {
            vel = o->vel;
            func_0027200C(&push, &vel, a);
            func_00271FA4(&o->pos2, &o->pos2, &push);
            len = sqrtf(o->pos2.x * o->pos2.x + o->pos2.y * o->pos2.y + o->pos2.z * o->pos2.z);
            lim = Trunc16ToF32(o->def->lim->b);
            if (a > 0.0f) {
                if (lim < len) func_0027200C(&o->pos2, &vel, lim);
            } else {
                if (len < lim) func_0027200C(&o->pos2, &vel, lim);
            }
        }
        func_00279E40(o, 1.0f);
    }
}
