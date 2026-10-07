#include "b11_types.h"

extern f32 D_800C8B38;
extern f32 D_800C8B44;
extern f32 D_800C8B48;
extern s32 D_800D15E0;
extern s32 D_800D297C;
extern u8 D_80121990[];
extern u8 D_80121990b[] asm("D_80121990");
void func_0024AA08(Obj *a, s32 c, B11R *b);
void func_0026B6A0(s32 *a, s32 b, s32 c, s32 d, B11Seg *e, s32 f, s32 g);
s32 func_0026E340();
s32 *func_0028FD94(s32 *n, s32 i);
f32 func_0024D274(Obj *a);
f32 func_0024D388(Obj *a);
void func_00280094(void *a, Obj *b, Obj *c, s32 d, s32 e, s32 f, Vec3f g, Quat4 h, Vec3f i, s32 j, s32 k, s32 l);
B11Fx *func_0028308C(void *a);

void func_0024A3A0(Obj *a, s32 b1, s32 c, B11R *b) {
    Vec3f p;
    s32 *n;
    B11Fx *r;
    f32 k;
    if (b->unk4 != 0) {
        func_0024AA08(a, c, b);
    }
    if (b->unk0 != 0) {
        func_0026B6A0(b->unkC, b1, a->unkB4, 1, &a->seg[D_800D297C], 0, a->unk3);
        if (func_0026E340() != 0) {
            n = func_0028FD94((s32 *)*b->unkC, 2);
            if (*n != 0) {
                if (*func_0028FD94(func_0028FD94(n, 0), 0) & 0x8000) {
                    p = a->pos;
                    p.y += func_0024D274(a) * D_800C8B44;
                    func_00280094(D_80121990, a, a, 0, 0, 0x94, a->v1C, a->q5C, p, 0, -1, 0);
                    r = func_0028308C(D_80121990b);
                    if (r != 0) {
                        k = D_800C8B48;
                        r->f150 = func_0024D388(a) * k;
                        r->f154 = func_0024D274(a) * k;
                    }
                }
            }
        }
    }
    D_800D15E0 = 0;
}
