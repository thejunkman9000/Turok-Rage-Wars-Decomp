#include "b04_types.h"
extern f32 D_800D2988;
typedef struct { u8 pad0[8]; Vec3f pos; } B04A;
typedef struct { u8 pad0[0x78]; s32 unk78; f32 unk7C; s32 unk80; u8 pad84[4]; s32 unk88; } B04B;
typedef struct { VecDst a; VecDst b; } B04C;
void func_00214DD4(B04A *, B04B *, s32, VecDst *);
void func_00215410(B04A *, B04B *, s32, VecDst *);
static inline void fill(VecDst *d, B04A *a) {
    Vec3f p, z;
    p = a->pos;
    z.x = 0;
    z.y = 0;
    z.z = 0;
    d->unk0 = 3;
    d->unk4 = 0;
    d->unk8 = 0;
    d->a = p;
    d->b = z;
    d->unk24 = 0;
    z.y = 0;
    p.y = 0;
    d->c = p;
    d->d = z;
    d->unk40 = 0;
}
void func_00216D3C(B04A *a, B04B *b, B04C *c, s32 f1, s32 f2) {
    f32 t;
    if (b->unk7C > 0.0f) {
        t = b->unk7C - D_800D2988;
        b->unk7C = t;
        if (t <= 0.0f) {
            b->unk78 = 0;
            b->unk7C = 0.0f;
        }
    }
    if (f1 != 0)
        func_00214DD4(a, b, b->unk88, &c->b);
    else
        fill(&c->b, a);
    if (f2 != 0) {
        func_00215410(a, b, b->unk80, &c->a);
        return;
    }
    fill(&c->a, a);
}
