#include "b11_types.h"

extern const f32 D_800C8E70;
extern const f32 D_800C8E74;
extern const f32 D_800C8E78;
extern const f32 D_800C8E7C;
extern Vec3f D_800D0EE0[];
extern u8 D_8011F448[];
extern u8 D_8011FE88[];
s32 func_0028CF48(void *a, u16 b);
f32 func_0024D274(ObjI *a);

void func_0024E980(ObjI *a, B11Sp2 *s, s32 id, s32 base) {
    Vec3f v;
    a->type = 3;
    a->id = s->u14;
    a->w1C0 = s->w0;
    a->pos = s->pos;
    a->pos.y = a->pos.y + D_800C8E70;
    a->f174 = s->s1E * D_800C8E74;
    a->w198 = 0;
    a->f194 = D_800C8E78;
    a->bmin.x = s->pos.x - s->r;
    a->bmin.y = s->pos.y - s->r;
    a->bmin.z = s->pos.z - s->r;
    a->bmax.x = s->pos.x + s->r;
    a->bmax.y = s->pos.y + s->r;
    a->bmax.z = s->pos.z + s->r;
    a->h54 = -1;
    a->h50 = id;
    a->h58 = 0;
    a->h5C = 0;
    if (s->u1C == 0xFFFF) {
        a->p18 = (s32)D_8011F448;
    } else {
        a->p18 = func_0028CF48(D_8011FE88, s->u1C);
    }
    if (s->u16_ == 0xFFFF) {
        a->p14 = 0;
    } else {
        a->p14 = base + (s->u16_ << 5);
    }
    a->flags = s->u18 | 2;
    a->w1A0 = 0;
    a->w1A4 = 0;
    a->u19E = s->u1A;
    v.x = a->pos.x;
    v.y = a->pos.y + func_0024D274(a) * D_800C8E7C;
    v.z = a->pos.z;
    a->v1A8 = D_800D0EE0[0];
    a->v1B4 = D_800D0EE0[1];
    a->w1C4 = 0;
}
