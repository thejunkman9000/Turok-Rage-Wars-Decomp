#include "m05_types.h"

typedef struct R06Node { u8 pad0[8]; M5Vec3 pos; u8 pad14[0x5C]; f32 f70; u8 pad74[0x166C]; struct R06Node *next; } R06Node;
typedef struct R06Def { u32 flags; u8 pad4[0xA]; s16 sE; u8 pad10[0x20]; M5Lim *lim; } R06Def;
typedef struct R06Obj {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ M5Vec3 pos;
    /* 0x014 */ u8 pad14[8];
    /* 0x01C */ M5Vec3 pos2;
    /* 0x028 */ u8 pad28[0x34];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ R06Def *def;
    /* 0x11C */ u8 pad11C[0x18];
    /* 0x134 */ R06Node *tgt;
    /* 0x138 */ u8 pad138[0x3C];
    /* 0x174 */ M5Vec3 vel;
} R06Obj;

f32 Trunc16ToF32(u16);
f32 sqrtf(f32);
extern u8 D_80145040[];
extern R06Node *D_80145060;
extern f32 D_800C9CB8;
extern f32 D_800C9CBC;
extern f32 D_800C9CC0;
extern f32 D_800C9CC4;
extern f32 D_800C9CC8;
extern f32 D_800C9CCC;
extern f32 D_800C9CD0;
extern f32 D_800C9CD4;
extern f32 D_800C9CD8;
extern f32 D_800C9CDC;
extern f32 D_800C9CE0;
extern f32 D_800C9CE4;

void func_00228DA0(void *, void *);
f32 func_0024D274(void *);
f32 func_0024E410(void *);
void func_00270D40(M5Vec4 *, f32, M5Vec4 *, M5Vec4 *);
void func_00271888(M5Vec4 *, M5Vec3 *);
void func_00271FA4(M5Vec3 *, M5Vec3 *, M5Vec3 *);
void func_00271FD8(M5Vec3 *, M5Vec3 *, M5Vec3 *);
void func_0027200C(M5Vec3 *, M5Vec3 *, f32);
void func_002720EC(M5Vec3 *);
void func_002727B8(M5Vec3 *, f32);
void func_00272908(M5Mtx *, M5Vec3 *, M5Vec3 *);
void func_002742B4(M5Vec4 *, M5Mtx *);
f32 func_00274640(f32);
f32 func_00274B00(f32, f32);
void func_00279E40(void *, f32);
void func_0027A0F4(void *);
void func_0027A540(void *);

static inline void Steer(R06Obj *o, f32 a) {
    M5Vec3 push;
    M5Vec3 vel;
    f32 len, lim;
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
}

void func_0027ADBC(R06Obj *o) {
    M5Vec3 d;
    M5Vec3 tp;
    M5Vec3 vv;
    M5Vec3 dir;
    M5Vec3 ax;
    M5Vec4 q0, q1, q2;
    M5Mtx mt;
    R06Node *p;
    M5Vec3 *tpp;
    M5Vec3 *pos2p;
    R06Node *p2;
    R06Node *t;
    R06Def *def;
    f32 f70, fc, fd, fa, fb, dist, k, speed, ang, w, tt, a;

    switch (o->type) {
    case 0x2E:
        p2 = D_80145060;
        if (p2 != 0) {
            tpp = &tp;
            pos2p = &o->pos2;
            fa = D_800C9CBC;
            fb = D_800C9CC0;
            asm volatile("");
            p = p2;
            do {
                f70 = p->f70;
                tp = p->pos;
                tp.y += f70;
                tp.y += func_0024D274(p2) * fa;
                func_00271FD8(&d, tpp, &o->pos);
                k = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
                if (k < D_800C9CC4) {
                    k = D_800C9CCC - k * D_800C9CC8;
                    d.x *= k * func_00274B00(fa, fb);
                    d.y *= k * func_00274B00(fa, fb);
                    d.z *= k * func_00274B00(fa, fb);
                    func_00271FD8(pos2p, pos2p, &d);
                }
                p2 = p->next;
                p = p2;
            } while (p2 != 0);
        }
        t = o->tgt;
        tt = func_0024E410(t);
        tp = t->pos;
        tp.y += tt;
        func_00271FD8(&d, &tp, &o->pos);
        fc = D_800C9CD0;
        fd = D_800C9CD4;
        d.x *= func_00274B00(fc, fd);
        d.y *= func_00274B00(fc, fd);
        d.z *= func_00274B00(fc, fd);
        func_00271FA4(&o->pos2, &o->pos2, &d);
        func_002727B8(&o->pos2, Trunc16ToF32(o->def->lim->b));
        return;
    case 0xB:
    case 0x129:
        func_0027A0F4(o);
        return;
    case 0x414:
    case 0x42D:
        func_0027A540(o);
        return;
    case 0xE:
    case 0x127:
    case 0x3EC:
    case 0x4B4:
    case 0x5F:
    case 0x60:
        func_00228DA0(D_80145040, o);
        Steer(o, Trunc16ToF32(o->def->lim->a));
        func_00279E40(o, 1.0f);
        return;
    default:
        break;
    }
    t = o->tgt;
    if (t != 0) {
        def = o->def;
        if (def->flags & 0x40000) {
            if (def->sE != 0) {
                tt = func_0024E410(t);
                tp = t->pos;
                tp.y += tt;
                tp.y += func_0024D274(t) * D_800C9CD8;
                func_00271FD8(&dir, &tp, &o->pos);
                func_002720EC(&dir);
                func_00271888(&q1, &dir);
                func_00271888(&q0, &o->vel);
                vv = o->vel;
                func_002720EC(&vv);
                speed = sqrtf(o->pos2.x * o->pos2.x + o->pos2.y * o->pos2.y + o->pos2.z * o->pos2.z);
                ang = func_00274640(vv.x * dir.x + vv.y * dir.y + vv.z * dir.z);
                tt = (f32)o->def->sE * D_800C9CDC;
                w = D_800C9CE0;
                if (tt < ang) {
                    w = tt / ang;
                }
                func_00270D40(&q2, w, &q0, &q1);
                func_002742B4(&q2, &mt);
                *(s32 *)&ax.x = 0;
                *(s32 *)&ax.y = 0;
                ax.z = D_800C9CE4;
                func_00272908(&mt, &ax, &o->vel);
                func_0027200C(&o->pos2, &o->vel, speed);
            }
        }
    }
    if (!(o->flags & 0x70000)) {
        Steer(o, Trunc16ToF32(o->def->lim->a));
    }
    if (!(o->flags & 0x30000)) {
        func_00279E40(o, 1.0f);
    }
}