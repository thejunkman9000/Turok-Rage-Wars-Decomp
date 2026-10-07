#include "b11_types.h"

extern f32 D_800C8D88;
extern f32 D_800C8D8C;
extern f32 D_800C8D90;
extern f32 D_80115DEC;
void func_00272088(Quat4 *q, Vec3f *a, Vec3f *b);
void func_002720EC(Quat4 *q);
f32 func_00274640(f32 x);

Quat4 func_0024D718(Obj *o) {
    Vec3f u;
    Vec3f v;
    Quat4 q;
    Quat4 r;
    f32 ang;
    f32 s;
    switch (o->type) {
    case 0:
    default:
        u.x = 0;
        u.y = D_800C8D88;
        u.z = 0;
        break;
    case 1:
    case 2:
    case 3:
        u = *(Vec3f *)((u8 *)o + 0x44);
        break;
    }
    v.x = 0;
    v.y = D_800C8D8C;
    v.z = 0;
    func_00272088(&q, &v, &u);
    func_002720EC(&q);
    ang = func_00274640(v.x * u.x + v.y * u.y + v.z * u.z) * D_800C8D90;
    s = sinf(ang);
    r.x = q.x * s;
    r.y = q.y * s;
    r.z = q.z * s;
    D_80115DEC = s;
    r.w = cosf(ang);
    return r;
}
