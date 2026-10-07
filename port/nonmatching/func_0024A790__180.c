#include "b11_types.h"

extern f32 D_800C8B54[];
extern f32 D_800C8B60;
extern f32 D_800C8B64;
extern f32 D_800C8B68;
extern s32 D_800D2640;
extern u8 D_80121990[];
extern u8 D_80121990b[] asm("D_80121990");
void func_0024AA08();
void func_0024D0F8();
s32 ***func_00251F0C(s32 a, s32 b, s32 *c, s32 d, s32 e, Obj *f, void (*g)(), void *h, s32 i);
void func_00253B5C(s32 a, void *p);
void func_002536F4(s32 a, void *p);
void func_0026DA4C(s32 *a, s32 b, s32 c, s32 d, s32 *e, s32 f);
void func_0027899C(void *a, void *b);
s32 func_0026E340();
s32 *func_0028FD94(s32 *n, s32 i);
f32 func_0024D274(Obj *a);
f32 func_0024D388(Obj *a);
void func_00280094(void *a, Obj *b, Obj *c, s32 d, s32 e, s32 f, Vec3f g, Quat4 h, Vec3f i, s32 j, s32 k, s32 l);
B11Fx *func_0028308C(void *a);

void func_0024A790(Obj *a, s32 b1, B11R *b) {
    Vec3f p;
    s32 **h;
    s32 *d;
    s32 *q;
    s32 *n;
    s32 *tq;
    B11Fx *r;
    f32 k;
    do {
    a->unk17C = 1 << a->unk1;
    if (b->unk4 != 0) {
        func_0024AA08();
    }
    } while (0);
    if (b->unk0 != 0) {
        h = (s32 **)func_00251F0C(0, *(s32 *)((u8 *)a + 0x2E4) | D_800D2640, (s32 *)b->unkC, 0, 0, a, func_0024D0F8, D_800C8B54, 1);
        if (h != 0) {
            func_00253B5C(0, h);
            d = *h;
            if (d[0] == 1) {
                q = (s32 *)d[1];
                tq = (s32 *)((u8 *)d + (s32)q);
                q = tq;
                func_0027899C(q, (u8 *)d + d[2]);
            } else {
                q = d + 2;
            }
            func_0026DA4C((s32 *)b->unkC, a->unkB4, 1, 0, q, a->unk3);
            if (func_0026E340() != 0) {
                n = func_0028FD94((s32 *)*(s32 *)b->unkC, 2);
                if (*n != 0) {
                    if (*func_0028FD94(func_0028FD94(n, 0), 0) & 0x8000) {
                        p = a->pos;
                        p.y += func_0024D274(a) * D_800C8B64;
                        func_00280094(D_80121990, a, a, 0, 0, 0x94, a->v1C, a->q5C, p, 0, -1, 0);
                        r = func_0028308C(D_80121990b);
                        if (r != 0) {
                            k = D_800C8B68;
                            r->f150 = func_0024D388(a) * k;
                            r->f154 = func_0024D274(a) * k;
                        }
                    }
                }
            }
            func_002536F4(0, h);
        }
    }
}

