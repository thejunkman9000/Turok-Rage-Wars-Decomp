#include "b10_types.h"

extern s32 D_8011FE88[];
extern u8 D_800C89E4[];
void func_002472E0(B10Obj *o, u32 flags);
void func_00271FD8(Vec3f *a, Vec3f *b, Vec3f *c);
void func_00271FA4(Vec3f *a, Vec3f *b, f32 *c);
void func_0024714C(B10Obj *o, Vec3f *v);
void func_0028A258(s32 *g, B10Obj *o, Vec3f *a, Vec3f *b);
void func_00246FF4(B10Obj *o);
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u8 *h, s32 i);
void *func_0028FD94(s32 *n, s32 i);
void func_0026EE90(u8 *a, void *b, u8 *c);
void func_002536F4(s32 a, s32 **p);

void func_00246E34(B10Obj *o) {
    Vec3f a;
    Vec3f b;
    s32 **r;
    void *n;
    s32 fl = o->flags100;
    s32 mask;
    if ((fl & 0x40000) && (D_8011FE88[0] != 4 || (fl & 0x2000))) {
        mask = fl & 0x300000;
        a = *(Vec3f *)&o->u8;
        func_002472E0(o, fl);
        b = *(Vec3f *)&o->u8;
        *(Vec3f *)&o->u8 = a;
        if (mask == 0 && *o->p18 != 0) {
            func_00271FD8(&b, &b, &a);
            func_00271FA4(&b, &b, &o->f1C4);
            func_0024714C(o, &b);
            if (*o->p18 == 1) {
                func_0028A258(D_8011FE88, o, &a, (Vec3f *)&o->u8);
            }
        }
        func_00246FF4(o);
        r = func_002518DC(0, o->fC4, o->fC4, o->fD0, 0, 0, 0, D_800C89E4, 1);
        if (r) {
            n = func_0028FD94(*r, 0);
            ((void (*)(B10Obj *, u8 *))o->fn28C)(o, &o->b170);
            func_0026EE90(&o->b74, n, &o->bE8);
            func_002536F4(0, r);
        }
    }
}