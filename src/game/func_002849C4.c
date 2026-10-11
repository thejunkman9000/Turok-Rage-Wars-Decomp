
#include "b19_types.h"
f32 Trunc16ToF32(u16);
f32 sqrtf(f32);
void func_0027200C(B19Vec3 *, B19Vec3 *, f32);
void func_00271FA4(B19Vec3 *, B19Vec3 *, B19Vec3 *);
static inline void func_00283A54(B19Obj *o) {
    f32 a = Trunc16ToF32(o->parent->lim->a);
    B19Vec3 d;
    B19Vec3 vel;
    B19Vec3 *p;
    f32 len, lim;
    if (a != 0.0f) {
        vel = o->vel;
        func_0027200C(&d, &vel, a);
        p = &o->pos2;
        func_00271FA4(p, p, &d);
        len = sqrtf(o->pos2.x * o->pos2.x + o->pos2.y * o->pos2.y + o->pos2.z * o->pos2.z);
        lim = Trunc16ToF32(o->parent->lim->b);
        if (a > 0.0f) {
            if (lim < len) func_0027200C(p, &vel, lim);
        } else {
            if (len < lim) func_0027200C(p, &vel, lim);
        }
    }
}

extern u8 D_80145040[];
void func_00228DA0(void *, B19Obj *);
void func_00279E40(B19Obj *, f32);
void func_002849C4(B19Obj *o) {
    func_00228DA0(D_80145040, o);
    func_00283A54(o);
    func_00279E40(o, 1.0f);
}
