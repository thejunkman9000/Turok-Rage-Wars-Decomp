/* port (passthru_fix.py): func_0024DD00 needs a0 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "m03_types.h"

extern s32 D_800D0910;
extern u8 D_800D297B;
extern s32 D_800D2B40[];
extern u8 D_8011FE88[];
typedef struct M03FxRecB {
    /* 0x00 */ s32 w0;
    /* 0x04 */ M03V3 pos;
    /* 0x10 */ f32 sx, sy, sz;
    /* 0x1C */ u16 e[6];
    /* 0x28 */ u16 u28;
    /* 0x2A */ u16 u2A;
    /* 0x2C */ u16 u2C;
    /* 0x2E */ u8 flags;
    /* 0x2F */ s8 q[4];
} M03FxRecB;
void func_0024DD00();
f32 Trunc16ToF32(u16 v);
void func_002702EC(void *a, void *b);
void func_0027302C(void *a, void *b);
void func_002734B8(void *m, f32 x, f32 y, f32 z);
void func_002734EC(void *m, f32 x, f32 y, f32 z);
void func_00273DDC(void *m);
void func_00274214(f32 *q);
void func_002742B4(f32 *q, void *m);
M03FxCls *func_0028CF48(void *a, u16 b);

void func_0024FD4C(M03Fx *a, M03FxRecB *r, s32 arg2, s32 base) {
    f32 q[4];
    f32 m[16];
    f32 k;
    func_0024DD00(a);
    a->type = 0;
    a->id = r->u28;
    a->w1C = arg2;
    a->hA8 = -1;
    a->hAC = 0;
    a->hB0 = 0;
    a->hB4 = 0;
    a->cls = func_0028CF48(D_8011FE88, r->u2C);
    a->bE0 = 0x10;
    a->wDC = 0;
    a->cls->w24 = (u32)(a->cls->f8 * a->cls->f8);
    a->flags = r->flags;
    q[0] = r->q[0] * 0.007874016f;
    q[1] = r->q[1] * 0.007874016f;
    q[2] = r->q[2] * 0.007874016f;
    q[3] = r->q[3] * 0.007874016f;
    func_00274214(q);
    func_002742B4(q, m);
    func_002734EC(m, r->sx, r->sy, r->sz);
    func_002734B8(m, r->pos.x, r->pos.y, r->pos.z);
    func_00273DDC(m);
    if (a->flags & 0x40) {
        a->bmin[0] = r->pos.x - 102.399994f;
        a->bmin[1] = r->pos.y - 102.399994f;
        a->bmin[2] = r->pos.z - 102.399994f;
        a->bmax[0] = r->pos.x + 102.399994f;
        a->bmax[1] = r->pos.y + 102.399994f;
        a->bmax[2] = r->pos.z + 102.399994f;
        a->wD4 = D_800D2B40[0];
    } else {
        k = 0.5f;
        a->bmin[0] = (Trunc16ToF32(r->e[0]) + r->pos.x) - k;
        a->bmin[1] = (Trunc16ToF32(r->e[1]) + r->pos.y) - k;
        a->bmin[2] = (Trunc16ToF32(r->e[2]) + r->pos.z) - k;
        a->bmax[0] = Trunc16ToF32(r->e[3]) + r->pos.x + k;
        a->bmax[1] = Trunc16ToF32(r->e[4]) + r->pos.y + k;
        a->bmax[2] = Trunc16ToF32(r->e[5]) + r->pos.z + k;
        a->wD4 = r->w0;
    }
    func_0027302C(a->m68, m);
    func_002702EC(m, a->m28);
    a->pos = r->pos;
    if (r->u2A == 0xFFFF) {
        a->p14 = 0;
    } else {
        a->p14 = base + (r->u2A << 5);
    }
    D_800D0910 = D_800D0910 + 1;
    if (D_800D0910 == 0x3FFFFF) {
        D_800D0910 = 0x380000;
    }
    a->wD0 = D_800D0910 << 10;
    a->bDA = D_800D297B - 1;
}
