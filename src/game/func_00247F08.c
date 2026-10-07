#include "b10_types.h"

s32 **func_0024BFC4(B10Pa *a, s32 b);
void func_002536F4(s32 a, s32 **p);
void *func_0028FD94(s32 *n, s32 i);
void func_00271FD8(Vec3f *o, Vec3f *a, Vec3f *b);
void func_00272088(Vec3f *o, Vec3f *a, Vec3f *b);
void func_0027200C(Vec3f *o, Vec3f *a, f32 s);
void func_002720EC(Vec3f *v);

void func_00247F08(B10Pa *a, B10Pb *b, B10Pc *c, Vec3f v1, Vec3f v2, s32 idx) {
    Vec3f r;
    Vec3f t;
    Vec3f x;
    s32 **n;
    s32 *node;
    B10Ent2 *e;
    s32 i;
    s32 cur;
    if (b->b34 != 0x3C && b->b12 < 0x17 && (n = func_0024BFC4(a, a->b1)) != 0) {
        node = func_0028FD94(*n, 5);
        e = (B10Ent2 *)((u8 *)node + (idx * *node + 8));
        cur = idx;
        if ((e->b65 & 3) == 3) {
            func_002536F4(0, n);
            return;
        }
        for (i = 0; i < 4; i++) {
            b->b14[i] = cur;
            cur = e->b64;
            if (cur != -1) {
                e = (B10Ent2 *)((u8 *)node + (cur * *node + 8));
            }
        }
        func_002536F4(0, n);
        b->b12 = 0x19;
        t.x = c->f30;
        t.y = c->f34;
        t.z = c->f38;
        func_00271FD8(&v1, &v1, &t);
        func_00272088(&r, &v1, &v2);
        func_002720EC(&r);
        func_002720EC(&v1);
        func_002720EC(&v2);
        func_00272088(&x, &r, &v1);
        func_0027200C(&r, &r, x.x * v2.x + x.y * v2.y + x.z * v2.z);
        func_002720EC(&r);
        b->v18 = r;
    }
}
