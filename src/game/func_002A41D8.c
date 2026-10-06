#include "b23_types.h"

typedef struct V16 {
    f32 x, y, z, w;
} V16;

typedef struct Ent41D8 {
    u8 pad0[0x10];
    Vec3f pos;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
} Ent41D8;

typedef struct Out41D8 {
    V16 a;
    V16 b;
    V16 c;
    V16 d;
} Out41D8;

extern f32 D_800CAF78;
extern f32 D_800CAF7C;

void func_00271FD8(void *out, void *a, void *b);
void func_0027200C(void *out, void *a, f32 s);
void func_00272088(void *out, void *a, void *b);
void func_002720EC(void *v);
void func_00272848(void *m);
void func_00272BA8(u8 *p, void *a, void *b);

void func_002A41D8(Ent41D8 *e0, Ent41D8 *e1, u8 *arg2, Out41D8 *out) {
    V16 v10, v20, v30, v40, v50;
    f32 ty, tz;

    func_00271FD8(&v20, &e0->pos, &e1->pos);
    func_002720EC(&v20);
    *(s32 *)&v10.x = 0;
    *(s32 *)&v10.y = 0;
    v10.z = D_800CAF7C;
    func_00272BA8(arg2 + 0x1A0, &v10, &v30);
    ty = -v30.y;
    tz = -v30.z;
    v30.y = ty;
    v30.z = tz;
    func_0027200C(&v40, &v30, v30.x * v20.x + ty * v20.y + tz * v20.z);
    func_00271FD8(&v40, &v20, &v40);
    func_002720EC(&v40);
    func_00272088(&v50, &v30, &v40);
    func_002720EC(&v50);
    func_0027200C(&v50, &v50, e0->unk1C);
    func_0027200C(&v40, &v40, e0->unk20);
    func_0027200C(&v30, &v30, e0->unk24);
    func_00272848(out);
    out->a.x = v50.x;
    out->a.y = v50.y;
    out->a.z = v50.z;
    out->b.x = v40.x;
    out->b.y = v40.y;
    out->b.z = v40.z;
    out->c.x = v30.x;
    out->c.y = v30.y;
    out->c.z = v30.z;
    out->d.x = e0->pos.x;
    out->d.y = e0->pos.y;
    out->d.z = e0->pos.z;
}
