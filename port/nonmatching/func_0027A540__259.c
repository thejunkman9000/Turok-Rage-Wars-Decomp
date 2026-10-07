#include "m05_types.h"

typedef struct M5Tgt1 { u8 pad0[8]; M5Vec3 pos; } M5Tgt1;

f32 Trunc16ToF32(u16);
f32 sqrtf(f32);
extern f32 D_800C9C68;
extern f32 D_800C9C6C;
extern f32 D_800C9C70;
extern f32 D_800C9C74;
extern f32 D_800C9C78;
extern f32 D_800C9C7C;
extern f32 D_800C9C80;
extern f32 D_800C9C84;
extern f32 D_800C9C88;
extern f32 D_800C9C8C;
extern f32 D_800C9C90;
extern f32 D_800C9C94;
extern u8 D_80121990[];

void func_0022B08C(s32, M5Vec3 *);
f32 func_0024D274(void *);
void *func_0025C97C(s32, s32, M5Vec3 *, M5Vec3 *, s32);
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
f32 func_00274640(f32);
void func_00279E40(M5Obj *, f32);
void func_00283D24(M5Obj *);
void func_00284408(M5Obj *);
void func_00284544(void *, M5Obj *);

void func_0027A540(M5Obj *o) {
    M5Vec3 tp;
    M5Vec3 dir;
    M5Vec3 vv;
    M5Vec3 ax;
    M5Vec3 gp;
    M5Vec3 d;
    M5Vec4 q0, q1, q2;
    M5Mtx mt;
    M5Vec3 push;
    M5Vec3 vel;
    M5Handle *h;
    M5Tgt1 *tgt;
    s32 sd;
    f32 speed, w, f, ang, a, len, lim;

    func_00271888(&q0, &o->vel);
    speed = sqrtf(o->pos2.x * o->pos2.x + o->pos2.y * o->pos2.y + o->pos2.z * o->pos2.z);
    h = o->handle;
    sd = o->owner->f1D8;
    if (h != 0) {
        if (h->idC != 0x8AC || h->id8 == -1) {
            func_00284408(o);
            goto mk;
        }
    } else {
mk:
        o->handle = func_0025C97C(func_0025CC8C(), 0x8AC, &o->pos, &o->pos, -1);
    }
    if (o->tgt != 0) {
        if (o->f140 >= D_800C9C68) o->tgt = 0;
        if (o->tgt != 0) goto tpb;
    }
    *(s32 *)&gp.x = 0;
    *(s32 *)&gp.y = 0;
    gp.z = D_800C9C6C;
    func_0022B08C(sd, &gp);
    func_00271FD8(&d, &gp, &o->pos);
    if (sqrtf(d.x * d.x + d.y * d.y + d.z * d.z) < D_800C9C70 && D_800C9C74 < o->f140) {
        func_00283D24(o);
        func_00284544(D_80121990, o);
        func_00284408(o);
        return;
    }
    goto have;
tpb:
    tgt = (M5Tgt1 *)o->tgt;
    tp = tgt->pos;
    tp.y += func_0024D274(o->tgt) * D_800C9C78;
    func_00271FD8(&d, &tp, &o->pos);
have:
    dir = d;
    func_002720EC(&dir);
    func_00271888(&q1, &dir);
    func_00274214(&q1);
    func_00274214(&q0);
    func_002720EC(&dir);
    vv = o->vel;
    func_002720EC(&vv);
    f = o->f140;
    w = 0.0f;
    ang = func_00274640(dir.x * vv.x + dir.y * vv.y + dir.z * vv.z);
    if (!(f < D_800C9C7C)) {
        w = D_800C9C84;
        if ((ang < D_800C9C80 && D_800C9C88 < f) || o->tgt != 0) {
            w = D_800C9C8C;
        }
    }
    func_00270D40(&q2, w, &q0, &q1);
    func_002742B4(&q2, &mt);
    *(s32 *)&ax.x = 0;
    *(s32 *)&ax.y = 0;
    ax.z = D_800C9C90;
    func_00272908(&mt, &ax, &o->vel);
    func_0027200C(&o->pos2, &o->vel, speed);
    if (D_800C9C94 <= o->f140) {
        o->b1B9 = 0;
        o->b1BA = 0;
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
