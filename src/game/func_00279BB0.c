#include "b17_types.h"

extern Vec3f D_801042C8;
extern u8 *D_80103FCC;
extern u8 D_801041F0[];
extern u8 D_80121990[];
void func_00271888(Quat *q, Vec3f *v);
void func_00271FA4(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00272908(Mat4F *m, Vec3f *in, Vec3f *out);
void func_002737D0(Mat4F *m, f32 angle);
Mat4F *func_0027D950(ActorX *a, s32 n);
void func_00280094(u8 *g, ActorX *a, ActorX *p12C, s32 p130, u8 *p134, s32 a1, Vec3f v, Quat q, Vec3f w, s32 zero, s32 a2, s32 flags);


void func_00279BB0(ActorX *a, s32 a1, s32 a2, s32 a3) {
    Quat q;
    Vec3f v60, v70, v80, v90, vA0, vB0;
    Mat4F m;
    u8 buf[0x108];
    Mat4F *p;
    s32 t;
    f32 x, y, px, py;

    if (a->ch118->w0 & 0x10) {
        v60 = D_801042C8;
    } else {
        v60 = a->vel;
    }
    func_00271888(&q, &v60);
    t = a->ch118->w14;
    x = 0.0f;
    if (t == 0) {
        x = a->f180;
    }
    y = 0.0f;
    if (x == y) {
        if (t == 0) {
            y = a->f184;
        }
        if (y == 0.0f) {
            vA0 = a->pos;
            goto L;
        }
    }
    px = 0.0f;
    if (a->ch118->w14 == 0) {
        px = a->f180;
    }
    v70.x = -px;
    py = 0.0f;
    if (a->ch118->w14 == 0) {
        py = a->f184;
    }
    v70.y = -py;
    v70.z = 0;
    func_002737D0(&m, a->f188);
    func_00272908(&m, &v70, &v80);
    p = func_0027D950(a, 0);
    if (p != 0) {
        func_00272908(p, &v80, &v90);
    } else {
        v90 = v80;
    }
    func_00271FA4(&vB0, &v90, &a->pos);
    D_80103FCC = buf;
    vA0 = vB0;
    D_80103FCC = D_801041F0;
L:
    func_00280094(D_80121990, a, a->tgt, a->u130, a->p134, a1, v60, q, vA0, 0, a2, a3 | (a->u5C & 0x200006));
}
