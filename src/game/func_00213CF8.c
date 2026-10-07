#include "b03_types.h"

extern u8 D_80104338[];
ActorB *func_0024E690(void);
void func_0024E6C8(ActorB *t, Vec3f *out);
f32 func_0024E72C(ActorB *t);
void func_00271FA4(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00271FD8(Vec3f *d, Vec3f *a, Vec3f *b);
void func_00273744(f32 *m, f32 ang);
void func_002729B4(f32 *m, Vec3f *d, Vec3f *s, s32 n);
void func_00243A80(ActorB *a, Vec3f v, void *p);
void func_00207730(ActorB *t, ActorB *a);

void func_00213CF8(ActorB *a) {
    ActorB *t;
    Vec3f v18;
    Vec3f v28;
    Vec3f v38;
    f32 m48[16];
    f32 ang;

    t = func_0024E690();
    if (t != NULL && t->def->type == 2) {
        v28 = a->pos;
        func_0024E6C8(t, &v18);
        if (!(a->flags38 & 0x1000) || 0.0f < v18.y) {
            func_00271FA4(&v28, &v28, &v18);
        }
        v18 = a->vel;
        a->vel.x = 0;
        a->vel.y = 0;
        a->vel.z = 0;
        func_00271FD8(&v38, &v28, &t->pos);
        ang = func_0024E72C(t);
        func_00273744(m48, ang);
        func_002729B4(m48, &v38, &v38, 1);
        func_00271FA4(&v38, &v38, &t->pos);
        func_00271FD8(&v38, &v38, &v28);
        a->unk6C = a->unk6C + ang;
        func_00271FA4(&v28, &v28, &v38);
        func_00243A80(a, v28, D_80104338);
        a->vel = v18;
        if (t->type == 1 && t->def->type == 2) {
            func_00207730(t, a);
        }
    }
}
