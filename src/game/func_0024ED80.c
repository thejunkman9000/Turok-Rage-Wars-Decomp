#include "b11_types.h"

extern f32 D_800C8E80;
extern f32 D_800C8E84;
extern f32 D_800C8E88;
extern u8 D_80121990[];
s32 func_0026E340();
s32 *func_0028FD94(s32 *n, s32 i);
f32 func_0024D274(Obj *a);
f32 func_0024D388(Obj *a);
void func_00280094(void *a, Obj *b, Obj *c, s32 d, s32 e, s32 f, Vec3f g, Quat4 h, Vec3f i, s32 j, s32 k, s32 l);
B11Fx *func_0028308C(void *a);

void func_0024ED80(Obj *a, s32 **b) {
    Vec3f p;
    Quat4 q;
    s32 *n;
    B11Fx *r;
    f32 k;
    if (func_0026E340() != 0) {
        q.x = q.y = q.z = 0.0f;
        q.w = D_800C8E80;
        n = func_0028FD94(*b, 2);
        if (*n != 0) {
            if (*func_0028FD94(func_0028FD94(n, 0), 0) & 0x8000) {
                p = a->pos;
                p.y += func_0024D274(a) * D_800C8E84;
                func_00280094(D_80121990, a, a, 0, 0, 0x94, a->v1C, q, p, 0, -1, 0);
                r = func_0028308C(D_80121990);
                if (r != 0) {
                    k = D_800C8E88;
                    r->f150 = func_0024D388(a) * k;
                    r->f154 = func_0024D274(a) * k;
                }
            }
        }
    }
}
