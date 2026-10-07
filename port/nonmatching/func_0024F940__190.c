
#include "m03_types.h"

extern s32 D_800D0910;
extern u8 D_800D297B;
extern s32 D_800D2B40[];
extern u8 D_8011FE88[];
typedef struct M03FxRecA {
    /* 0x00 */ s32 w0;
    /* 0x04 */ f32 scale;
    /* 0x08 */ u16 u8;
    /* 0x0A */ u16 uA;
    /* 0x0C */ u16 uC;
    /* 0x0E */ u16 uE;
    /* 0x10 */ s16 s10;
    /* 0x12 */ s8 b[6];
    /* 0x18 */ u8 flags;
    /* 0x19 */ u8 bx;
    /* 0x1A */ u8 bz;
} M03FxRecA;
void func_0024DD00();
void func_002702EC(void *a, void *b);
void func_0027302C(void *a, void *b);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_002734EC(void *m, f32 x, f32 y, f32 z);
void func_00273744(void *m, f32 a);
void func_00273DDC(void *m);
M03FxCls *func_0028CF48(void *a, u16 b);

void func_0024F940(M03Fx *a, M03FxRecA *r, s32 arg2, s32 base, f32 mul) {
    f32 m[16];
    M03V3 p;
    f32 ang;
    func_0024DD00();
    ang = 0.0f;
    a->type = 0;
    a->id = r->u8;
    a->w1C = arg2;
    a->hA8 = -1;
    a->hAC = 0;
    a->hB0 = 0;
    a->hB4 = 0;
    a->cls = func_0028CF48(D_8011FE88, r->uE);
    a->bE0 = 0x10;
    a->wDC = 0;
    a->cls->w24 = (u32)(a->cls->f8 * a->cls->f8);
    p.x = r->bx * mul;
    if (r->flags & 0x10) {
        p.x = -p.x;
    }
    p.z = r->bz * mul;
    if (r->flags & 0x20) {
        p.z = -p.z;
    }
    p.y = r->s10 * 0.0078125f;
    switch (r->flags & 3) {
    case 0:
        ang = 0.0f;
        break;
    case 1:
        ang = 1.5707965f;
        break;
    case 2:
        ang = 3.141593f;
        break;
    case 3:
        ang = 4.7123895f;
        break;
    }
    a->flags = r->uC;
    func_00273744(m, ang);
    func_002734EC(m, r->scale, r->scale, r->scale);
    func_002734B8(m, p.x, p.y, p.z);
    func_00273DDC(m);
    if (a->flags & 0x40) {
        a->bmin[0] = p.x - 102.399994f;
        a->bmin[1] = p.y - 102.399994f;
        a->bmin[2] = p.z - 102.399994f;
        a->bmax[0] = p.x + 102.399994f;
        a->bmax[1] = p.y + 102.399994f;
        a->bmax[2] = p.z + 102.399994f;
        a->wD4 = D_800D2B40[0];
    } else {
        a->bmin[0] = (p.x + r->b[0] * 10.24f) - 0.5f;
        a->bmin[1] = (p.y + r->b[2] * 10.24f) - 0.5f;
        a->bmin[2] = (p.z + r->b[4] * 10.24f) - 0.5f;
        a->bmax[0] = p.x + r->b[1] * 10.24f + 0.5f;
        a->bmax[1] = p.y + r->b[3] * 10.24f + 0.5f;
        a->bmax[2] = p.z + r->b[5] * 10.24f + 0.5f;
        a->wD4 = r->w0;
    }
    func_0027302C(a->m68, m);
    func_002702EC(m, a->m28);
    a->pos = p;
    if (r->uA == 0xFFFF) {
        a->p14 = 0;
    } else {
        a->p14 = base + (r->uA << 5);
    }
    D_800D0910 = D_800D0910 + 1;
    if (D_800D0910 == 0x3FFFFF) {
        D_800D0910 = 0x380000;
    }
    a->wD0 = D_800D0910 << 10;
    a->bDA = D_800D297B - 1;
}

