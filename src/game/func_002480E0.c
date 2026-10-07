#include "b10_types.h"

extern s32 D_800D2978;
extern f32 D_800D0724[];
extern const f32 D_800C8A74;
extern const f32 D_800C8A78;
extern const f32 D_800C8A7C;
extern const f32 D_800C8A80;
extern const f32 D_800C8A84;
extern const f32 D_800C8A88;
extern const f32 D_800C8A8C;
void func_002720EC(Vec3f *v);
void func_0027302C(B10Mt *m, B10R *o);
void func_0027200C(Vec3f *o, Vec3f *a, f32 s);
void func_002734B8(void *m, Vec3f v);
void func_00272D70(B10Mt *m, f32 ang, f32 x, f32 y, f32 z);
void func_0026F690(B10R *o, B10Mt *a, B10Mt *b);

void func_002480E0(u32 a0, u32 flags, B10R *obj) {
    B10Mt m18;
    B10Mt m58;
    Vec3f v98;
    Vec3f vA8;
    u32 t0;
    u32 k;
    f32 fs0f;
    f32 fs0;
    t0 = D_800D2978;
    t0 += (flags & 0x38) * 50;
    t0 += (a0 & 0xFFFF) / 113;
    if (!(flags & 4)) {
        t0 += 0x28;
    }
    vA8.x = 0;
    vA8.z = 0;
    vA8.y = D_800C8A74;
    k = flags & 0xC3;
    if (k == 2) {
        vA8.z = D_800C8A74;
        vA8.x = 0;
        fs0f = D_800D0724[t0 % 120] - D_800C8A78;
        vA8.y = D_800D0724[(t0 + 0xC) % 120];
    } else if (k == 0x82) {
        vA8.x = D_800C8A74;
        vA8.z = 0;
        fs0f = D_800D0724[t0 % 120] - D_800C8A7C;
        fs0f *= 2.0f;
        vA8.y = D_800D0724[(t0 + 0xC) % 120];
    } else if (k == 0x40) {
        fs0f = D_800D0724[(t0 + 0x1E) % 120] - D_800C8A80;
        fs0f *= 2.0f;
        vA8.x = D_800D0724[(t0 + 0xC) % 120];
        vA8.y = D_800D0724[(t0 + 0x2A) % 120];
        vA8.z = D_800D0724[(t0 + 0x6E) % 120];
    } else if (k == 1) {
        fs0f = D_800D0724[(t0 + 0x46) % 120] - D_800C8A84;
        fs0f = fs0f * D_800C8A88;
    } else {
        return;
    }
    func_002720EC(&vA8);
    v98.x = obj->v30.x;
    v98.y = obj->v30.y;
    v98.z = obj->v30.z;
    func_0027302C(&m58, obj);
    fs0 = D_800C8A8C;
    func_0027200C(&v98, &v98, fs0);
    func_002734B8(&m58, v98);
    func_00272D70(&m18, fs0f, vA8.x, vA8.y, vA8.z);
    func_0026F690(obj, &m58, &m18);
    func_0027200C(&v98, &v98, fs0);
    func_002734B8(obj, v98);
}
