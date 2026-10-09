#include "m02_gen.h"
extern f32 D_800CE758;
extern f32 D_800CF22C;
extern f32 D_800D2988;
extern u8 D_800CE714[];
extern u8 D_800CE720[];
extern u8 D_800CE754[];
extern u8 D_800CE778[];
extern u8 D_800CE814[];
f32 cosf(f32);
void func_00214178(M2Sub80C *a, void *b, s32 id);
void func_002231B0(M2P3 *p, M2Q3 *q, void *t);
void func_002233CC(M2P3 *p, M2Q3 *q, void *t);
void func_00239314(M2Pawn *o, f32 a, f32 b, f32 c, f32 d, s32 e, Vec3f pos);
void func_0027200C(Vec3f *dst, Vec3f *src, f32 s);
void func_00272908(M2Mtx *m, void *a, void *b);
void func_00273744(M2Mtx *m, f32 a);
void func_002748E0(Vec3f *v, f32 a, f32 b);
void func_00225F20(M2P3 *p, M2Q3 *q) {
    M2Mtx sp28;
    M2Sub80C *s1;
    u8 *s3;
    f32 k;
    f32 t;
    f32 fs0;
    f32 ax;
    f32 d;
    f32 u;
    f32 w;
    f32 v;
    f32 w2;
    Vec3f *vp;
    s1 = p->unk80C;
    {
        register f32 fx __asm__("$f2");
        f32 c = (((cosf(p->f838 * 0.2792527f) + 1.0f) * 0.01f) + 0.06f) * 80.0f;
        fx = p->f69C;
        t = fx * c;
    }
    p->f838 = p->f838 + D_800D2988;
    k = 0.017453294f;
    t = t * k;
    fs0 = q->f6C;
    func_002748E0((Vec3f *)&q->f6C, fs0 + t, 0.9f);
    func_002748E0((Vec3f *)&p->f72C, ((fs0 - q->f6C) + p->f69C * 8.0f) * k, 0.1f);
    func_002231B0(p, q, D_800CE814);
    s3 = 0;
    if (p->unk6B8 & 8) {
        func_00214178(s1, (u8 *)s1 + 0x170, 0x2E);
        p->f704 = 90.0f;
        p->f6C0 = 2.0f * D_800CE758;
    }
    ax = p->f6C0;
    w = p->f83C;
    if (ax < 0.0f) {
        ax = -ax;
    }
    d = 2.0f * p->f6C4;
    if (d < 0.0f) {
        d = -d;
        if (d < ax) goto A;
        goto B;
    }
    if (d < ax) {
A:
        u = p->f6C0;
        if (u < 0.0f) {
            v = w - u;
        } else {
            v = w + u;
        }
    } else {
B:
        u = 2.0f * p->f6C4;
        if (u < 0.0f) {
            v = w - u;
        } else {
            v = w + u;
        }
    }
    p->f83C = v;
    if (D_800CF22C < v) {
        p->f83C = v - D_800CF22C;
        if (s1->unk1A4 != 0x2E) {
            p->f6C0 = p->f6C0 * 0.5f;
            p->f6C4 = p->f6C4 * 0.5f;
        }
        t = p->f6C0;
        if (t < 0.0f) {
            w2 = -t * 2.5f;
        } else {
            w2 = t * 2.5f;
        }
        if (50.0f < w2) {
            w2 = 50.0f;
        }
        if (p->pawn != 0) {
            func_00239314(p->pawn, 0.0f, w2, 0.0f, 1.0f, 1, q->pos);
        }
    }
    if (p->f6C0 > 0.0f) {
        func_002233CC(p, q, D_800CE754);
    } else {
        func_002233CC(p, q, D_800CE778);
    }
    t = p->f6C0;
    if (t < 0.0f) {
        if (10.24f < -t) goto S;
    } else if (10.24f < t) {
S:
        p->f704 = 15.0f;
    }
    if (p->unk810 == 0x136) {
        s3 = D_800CE714;
        p->v814 = *(Vec3f *)D_800CE720;
    }
    if (s3 != 0) {
        func_00273744(&sp28, q->f6C);
        vp = &p->v73C;
        func_00272908(&sp28, s3, vp);
        func_0027200C(vp, vp, 10.24f);
    }
}
