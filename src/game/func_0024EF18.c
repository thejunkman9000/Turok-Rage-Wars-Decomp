#include "b11_types.h"

extern const f32 D_800C8E8C;
extern const f32 D_800C8E90;
extern const f32 D_800C8E94;
extern const f32 D_800C8E98;
extern s32 D_800D297C;
void func_0024D860(f32 *q, Obj *a);
f32 func_0024E2EC(Obj *a);
void func_0026992C(f32 *m, s32 a, s32 b);
void func_002702EC(f32 *a, f32 *b);
void func_002725BC(Vec3f *v, f32 s);
void func_002734B8(f32 *m, f32 x, f32 y, f32 z);
void func_002734EC(f32 *m, f32 x, f32 y, f32 z);
void func_002742B4(f32 *q, f32 *m);

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void func_0024EF18(Obj *a) {
    f32 m[16];
    Vec3f p;
    f32 q[4];
    f32 y;
    f32 dy;
    register f32 k asm("$f22");
    f32 v;
    f32 v2;
    y = a->unk40;
    dy = a->pos.y - y;
    k = D_800C8E8C;
    if (!(MIN(func_0024E2EC(a) * k, func_0024E2EC(a) * k - dy * D_800C8E90) < 0.0f)) {
        k = D_800C8E94;
        v2 = MIN(func_0024E2EC(a) * k, func_0024E2EC(a) * k - dy * D_800C8E98);
    } else {
        v2 = 0.0f;
    }
    func_0024D860(q, a);
    p.x = a->pos.x;
    p.z = a->pos.z;
    p.y = y;
    func_002725BC(&p, 20000.0f);
    func_002742B4(q, m);
    func_002734EC(m, v2, 1.0f, v2);
    func_002734B8(m, p.x, p.y, p.z);
    func_002702EC(m, ((ObjE8 *)a)->mtx[D_800D297C].m);
    func_0026992C(((ObjE8 *)a)->mtx[D_800D297C].m, 1, 0x96);
}



