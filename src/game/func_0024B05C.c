#include "b11_types.h"
#include "m03_types.h"

extern const f32 D_800C8BD0;
extern f32 D_800C8BD4;
extern u8 D_801462E5;
s32 *func_0024BFC4(Obj *a, s32 idx);
void func_002536F4(s32 a, s32 *p);
void func_00270980(void *m, s32 src);
void func_00271FA4(M03V3 *o, M03V3 *a, M03V3 *b);
void func_00271FD8(M03V3 *o, M03V3 *a, M03V3 *b);
void func_0027200C(M03V3 *o, M03V3 *a, f32 s);
void func_00272908(void *m, M03V3 *in, M03V3 *out);
M03Tbl *func_0028FD94(s32 node, s32 idx);

s32 func_0024B05C(Obj *a, M03V3 v, M03Ent *out) {
    M03V3 sum;
    M03V3 d;
    u8 m[0x40];
    s32 *h;
    M03Tbl *t;
    M03Ent *best;
    M03Ent *e;
    s32 mats;
    s32 i;
    s32 k;
    s32 n;
    f32 bestd;
    f32 dist;

    mats = a->unkB4;
    if (mats == 0) {
        mats = a->unkB8;
        if (mats == 0) {
            return 0;
        }
    }
    h = func_0024BFC4(a, a->unk1);
    if (h == 0) {
        return 0;
    }
    t = func_0028FD94(*h, 5);
    n = t->count;
    bestd = D_800C8BD0;
    best = 0;
    for (i = 0; i < n; i++) {
        e = (M03Ent *)((u8 *)t + (i * t->stride + 8));
        if (e->mask & a->unk17C) {
            sum = e->p[0];
            for (k = 1; k < 8; k++) {
                func_00271FA4(&sum, &sum, &e->p[k]);
            }
            func_0027200C(&sum, &sum, 0.125f);
            func_00270980(m, mats + i * 0x40);
            func_00272908(m, &sum, &d);
            func_00271FD8(&d, &d, &v);
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist < bestd) {
                best = e;
                bestd = dist;
            }
        }
    }
    if (best != 0) {
        *out = *best;
        if ((a->flags & 0x300000) && D_801462E5 == 0) {
            *(f32 *)((u8 *)out + 0x68) = D_800C8BD4;
        }
    }
    func_002536F4(0, h);
    return best != 0;
}
