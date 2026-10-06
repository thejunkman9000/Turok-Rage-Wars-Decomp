#include "b04_types.h"
f32 func_0024D388(void *);
void func_0024E78C(void *, f32, f32, f32, s32, s32, s32, s32);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
void func_00271FD8(Vec3f *, Vec3f *, Vec3f *);
void func_0027200C(Vec3f *, Vec3f *, f32);
void func_002720EC(Vec3f *);
extern f32 D_800C72D8;
typedef struct { u8 pad0[8]; Vec3f pos; } B04Ob;
void func_0021740C(B04Ob *a, s32 unused, B04Ob *b, B04Ob *c, s32 e, s32 f) {
    Vec3f d;
    Vec3f r;
    if (c != NULL) {
        func_00271FD8(&d, &b->pos, &c->pos);
        d.y = 0;
        func_002720EC(&d);
    } else {
        d.x = 0;
        d.y = 0;
        d.z = 0;
    }
    func_0027200C(&d, &d, func_0024D388(b) + func_0024D388(a) + D_800C72D8);
    func_00271FA4(&r, &b->pos, &d);
    func_0024E78C(b, r.x, r.y, r.z, e, f, 0, 0);
}
