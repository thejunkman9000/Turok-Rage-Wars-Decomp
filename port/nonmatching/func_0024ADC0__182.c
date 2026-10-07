#include "b11_types.h"
#include "m03_types.h"

extern u8 D_8011FFB0[];
s32 func_00279A30(void *a, s32 b);
f32 func_0024E668(Obj *a, s32 b);
f32 func_0024E2EC(Obj *a);
void func_002725BC(M03V3 *v, f32 s);
void func_002742B4(void *q, void *m);
void func_002734EC(void *m, f32 x, f32 y, f32 z);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_002702EC(void *m, s32 node);
void func_0026992C(s32 node, s32 flag, s32 alpha);

#define MINB(x, y) ((x) < (y) ? (x) : (y))
#define MINLE(x, y) ((x) <= (y) ? (x) : (y))
#define MAXC(x, y) ((x) < (y) ? (y) : (x))

void func_0024ADC0(Obj *a, M03V3 *off, s32 flag) {
    u8 m[0x40];
    M03V3 p;
    s32 node;
    f32 base;
    f32 h;
    f32 sc;
    f32 t;
    f32 w;
    f32 f1;
    f32 f2;
    f32 al;
    s32 r;
    s32 cur;
    f32 nf;
    s32 nv;

    node = func_00279A30(D_8011FFB0, 1);
    if (node != 0) {
        base = func_0024E668(a, 0);
        h = (a->pos.y + a->unk70) - base;
        sc = func_0024E2EC(a);
        t = h * 0.1f;
        w = sc - t;
        if (!(w <= sc)) {
            w = sc;
        }
        if (w < 0.0f) {
            w = 0.0f;
        } else {
            w = sc - t;
            if (!(w <= sc)) {
                w = sc;
            }
        }
        sc = w;
        if (flag != 0) {
            f1 = 0.5f;
            f2 = 15.36f;
        } else {
            f1 = 0.7f;
            f2 = 0.0f;
        }
        sc = sc * f1;
        p.x = a->pos.x + off->x;
        p.z = a->pos.z + off->z;
        p.y = base + f2 + off->y;
        func_002725BC(&p, 20000.0f);
        func_002742B4(&a->q5C, m);
        func_002734EC(m, sc, 1.0f, sc);
        func_002734B8(m, p.x, p.y, p.z);
        func_002702EC(m, node);
        al = 200.0f - h * 1.220703125f;
        r = (u32)MAXC(MINB(255.0f, al), 0.0f);
        cur = *((u8 *)a + 0x13A);
        nf = (f32)cur + (f32)((r & 0xFF) - cur) * 0.5f;
        nv = (u32)nf;
        *((u8 *)a + 0x13A) = nv;
        func_0026992C(node, flag == 0, nv & 0xFF);
    }
}


