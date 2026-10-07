#include "b10_types.h"

#define F32AT(o, off) (*(f32 *)((u8 *)(o) + (off)))

extern s32 D_8011FE88[];
extern const f32 D_800D2988;
extern const f32 D_800C8A38;
extern const f32 D_800C8A3C;
extern u8 D_800C8A24[];
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u8 *h, s32 i);
void func_002536F4(s32 a, s32 **p);
void func_00261690(u8 *a, s32 b, s32 c, s32 d, s32 *e, B10An *f);
void func_0026195C(u8 *a, Vec3f *b, f32 *c, B10Obj *o);
void func_002624C8(u8 *a);
s32 func_002624F8(u8 *a);
B10Cv *func_00262584(u8 *a);
void func_00272038(Vec3f *a, f32 t, Vec3f *b, Vec3f *c);
void func_00272908(B10Mt *m, Vec3f *a, Vec3f *b);
void func_00273744(B10Mt *m, f32 a);
f32 func_00273F54(f32 x, f32 y, f32 z);
void func_00274090(f32 *p);

void func_002472E0(B10Obj *o) {
    Vec3f v28;
    Vec3f v38;
    Vec3f v48;
    Vec3f v58;
    B10Mt m68;
    s32 hit;
    f32 aC;
    f32 b0;
    s32 **r;
    u8 *s3;
    B10An *s2;
    B10Cv *cv;
    f32 fs0;
    f32 t;
    f32 fv0;
    f32 fv1f;
    f32 fv1;
    f32 ft0;
    f32 tmp;
    if (D_8011FE88[0] == 4) {
        if (o->b10F == 0) {
            o->b10E = 1;
        }
        if (o->an118.b123 == 0) {
            o->an118.b122 = 1;
        }
        if (!((o->b10F != 0 || (o->flags100 & 0x400)) && (o->flags100 & 0x2000))) {
            return;
        }
    }
    r = func_002518DC(0, o->fC8, o->fC8, ((o->bE6 * 4) + 0xF) & ~7, 4, 0, 0, D_800C8A24, 0);
    s3 = (u8 *)&o->f104;
    if (r) {
        s2 = &o->an118;
        func_00261690(s3, (s32)*r, o->fC8, 1, &hit, s2);
        if (func_002624F8(s3)) {
            func_0026195C(s3, &v28, &aC, o);
            fs0 = aC;
            v48 = v28;
            if (hit != 0 && s2->h4 != -1) {
                cv = func_00262584(s3);
                if (cv->h0) {
                    o->flags100 |= 0x400;
                    o->h12C = cv->h0;
                    o->f134 = 0;
                    o->b138 = cv->b5;
                    o->b139 = cv->b7;
                } else {
                    o->flags100 &= ~0x400;
                }
            }
            if (o->flags100 & 0x400) {
                func_00261690((u8 *)s2, (s32)*r, o->fC8, 0, 0, 0);
                if (func_002624F8((u8 *)s2)) {
                    fv0 = o->f134 + D_800D2988;
                    fv1f = (f32)o->h12C;
                    o->f134 = fv0;
                    if (fv1f < fv0) {
                        o->flags100 &= ~0x400;
                    } else {
                        fv1 = (f32)o->b139;
                        ft0 = (f32)o->b138;
                        t = fv0 / (fv1f + D_800D2988);
                        o->f130 = (fv1 + D_800C8A38 + ft0) * t * t * t + ((D_800C8A3C - fv1) - 2.0f * ft0) * t * t + ft0 * t;
                        func_0026195C((u8 *)&o->an118, &v38, &b0, o);
                        func_00272038(&v48, o->f130, &v38, &v28);
                        fs0 = func_00273F54(o->f130, b0, aC);
                    }
                    func_002624C8((u8 *)s2);
                } else {
                    o->flags100 &= ~0x400;
                }
            }
            func_002624C8(s3);
            if (o->flags100 & 0x20000) {
                o->f6C = o->f6C - fs0;
                func_00274090(&o->f6C);
                tmp = v48.y;
                v48.y = 0;
                v48.z = tmp;
                func_00273744(&m68, o->f6C);
                func_00272908(&m68, &v48, &v58);
                F32AT(o, 8) = F32AT(o, 8) + v58.x * F32AT(o, 0x50);
                F32AT(o, 0x10) = F32AT(o, 0x10) + v58.z * F32AT(o, 0x58);
            } else if (!(o->flags100 & 0x300000) && o->hE4 == 0x137) {
                o->f6C = o->f6C - fs0;
                func_00274090(&o->f6C);
            }
        }
        func_002536F4(0, r);
    }
}
