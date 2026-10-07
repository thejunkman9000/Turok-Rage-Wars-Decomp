#include "b10_types.h"

extern const f32 D_800C8A40;
extern const f32 D_800C8A44;
extern const f32 D_800C8A48;
extern const f32 D_800C8A4C;
extern const f32 D_800C8A50;
extern const f32 D_800C8A54;
extern f32 D_80115DEC;
f32 sinf(f32 x);
f32 cosf(f32 x);
void func_00226C3C(B10Ow *o, B10Q4 *q);
void func_00274108(B10Q4 *o, B10Q4 *a, B10Q4 *b);
void func_00203848(B10Q4 *o, B10Obj *a, u8 *b);

B10Q4 *func_0024795C(B10Q4 *out, B10Obj *o) {
    B10Q4 r;
    B10Q4 q20;
    B10Q4 q30;
    B10Q4 q40;
    B10Q4 q50;
    B10Q4 q60;
    B10Ow *ow;
    B10Pq *pl;
    f32 k;
    f32 k2;
    f32 s;
    if (o->flags100 & 0x300000) {
        ow = o->p1D8;
        pl = ow->p5DC;
        if (pl) {
            k = D_800C8A40;
            s = sinf(k);
            D_80115DEC = s;
            q30.x = 0.0f;
            q30.y = s;
            q30.z = 0.0f;
            q30.w = cosf(k);
            func_00274108(&r, &q30, &pl->q140);
        } else {
            k = D_800C8A44;
            func_00226C3C(ow, &q60);
            s = sinf(k);
            D_80115DEC = s;
            q30.x = 0.0f;
            q30.y = s;
            q30.z = 0.0f;
            q30.w = cosf(k);
            func_00274108(&r, &q30, &q60);
        }
    } else if (*o->p18 == 4) {
        s = sinf(o->f294 * D_800C8A48);
        q20.x = s;
        q20.y = 0.0f;
        q20.z = 0.0f;
        D_80115DEC = s;
        q20.w = cosf(o->f294 * D_800C8A48);
        s = sinf((o->f6C + D_800C8A4C) * D_800C8A48);
        q30.x = 0.0f;
        q30.y = s;
        q30.z = 0.0f;
        D_80115DEC = s;
        q30.w = cosf((o->f6C + D_800C8A4C) * D_800C8A48);
        func_00274108(&q40, &q20, &q30);
        func_00203848(&q50, o, &o->b170);
        func_00274108(&r, &q40, &q50);
    } else {
        s = sinf((o->f6C + D_800C8A50) * D_800C8A54);
        q30.x = 0.0f;
        q30.y = s;
        q30.z = 0.0f;
        D_80115DEC = s;
        q30.w = cosf((o->f6C + D_800C8A50) * D_800C8A54);
        func_00274108(&r, &q30, (B10Q4 *)&o->f5C);
    }
    *out = r;
    return out;
}
