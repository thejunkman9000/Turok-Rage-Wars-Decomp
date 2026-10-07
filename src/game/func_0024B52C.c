#include "b11_types.h"

extern const f32 D_800C8C40;
extern f32 D_80115DEC;
s32 func_00245788();
void func_0024D718(Quat4 *q, Obj *a);
void func_00274108(Quat4 *out, Quat4 *a, Quat4 *b);
void func_002742B4(Quat4 *q, void *m);
void func_002734EC(void *m, f32 x, f32 y, f32 z);
void func_002725BC(Vec3f *v, f32 s);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_00273DDC(void *m);

void func_0024B52C(Obj *a) {
    Quat4 u;
    Quat4 o;
    Quat4 q;
    f32 s;
    q = a->q5C;
    if (func_00245788()) {
        func_0024D718(&q, a);
    }
    s = sinf(a->unk6C.f * D_800C8C40);
    u.x = 0;
    u.y = s;
    u.z = 0;
    D_80115DEC = s;
    u.w = cosf(a->unk6C.f * D_800C8C40);
    func_00274108(&o, &u, &q);
    func_002742B4(&o, a->unk74);
    func_002734EC(a->unk74, a->unk50, a->unk54, a->unk58);
    func_002725BC(&a->pos, 20000.0f);
    func_002734B8(a->unk74, a->pos.x, a->pos.y, a->pos.z);
    func_00273DDC(a->unk74);
}
