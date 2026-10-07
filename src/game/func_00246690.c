#include "b10_types.h"

typedef struct B10Gx { u8 pad0[0x24]; s32 f24; u8 pad28[0x2C]; s32 f54; } B10Gx;
extern B10Gx D_8011FE88[];
extern s32 D_80145044;
extern s32 D_80145048;
extern u8 D_800CFB04[];
extern u8 *D_800D0680[];
extern B10B24 D_800D0EF8;
s32 func_0028B1F8(B10Gx *g, s32 a);
void func_00246174(B10Obj *o);
void func_0024D860(B10Q4 *q, B10Obj *o);
void func_002624A0(u8 *p);
void func_0024B64C(B10Obj *o, s32 a);
void func_00272848(u8 *m);
void func_00213AAC(B10Obj *o, u8 *p, u8 *t);
void func_002193C8(u8 *p, s32 a, void *pos);
void func_00246BD8(B10Obj *o, s32 a, s32 b, s32 c);
s32 func_00250B98(void);
void func_0024A790(void);

void func_00246690(B10Obj *o, s32 id, s32 type2, s32 unused, s32 *p18, s32 a5, B10H *p14, f32 f6c,
                   Vec3f pos, u32 flags, Vec3f v50, Vec3f v1C) {
    B10Q4 q;
    u8 *tab;
    s32 s2;
    s32 s1;
    s32 j;
    u32 k;
    s32 n;
    u8 *pl;
    o->flags100 &= 0xFFFBFFFF;
    if (id == -1) {
        id = func_0028B1F8(D_8011FE88, type2);
        if (id == -1) {
            return;
        }
    }
    func_00246174(o);
    o->type = 1;
    o->h4 = id;
    o->p18 = p18;
    o->p14 = p14;
    o->f6C = f6c;
    *(Vec3f *)&o->u8 = pos;
    o->flags100 = flags;
    *(Vec3f *)((u8 *)o + 0x50) = v50;
    o->v1C = v1C;
    o->hE4 = type2;
    func_0024D860(&q, o);
    *(B10Q4 *)&o->f5C = q;
    o->f70 = 0;
    o->bE6 = 0;
    o->bE7 = 0;
    o->b139 = 0;
    o->b138 = 0;
    o->w2E0 = 0x17800074;
    func_002624A0((u8 *)&o->f104);
    func_002624A0((u8 *)&o->an118);
    func_0024B64C(o, 0);
    o->flags100 = (o->flags100 & ~0x400) | 0x2100;
    func_00272848(&o->b74);
    o->fB4 = 0;
    o->pB8 = 0;
    o->fBC = 0;
    o->b13B = 0;
    o->flags100 |= 0x10000;
    o->flags100 |= 0x20000;
    if (*o->p18 == 0 || (o->flags100 & 1)) {
        o->flags100 &= 0xFFFDFFFF;
    }
    s2 = 0;
    s1 = 0;
    k = *o->p18;
    if (k >= 15) {
null:
        tab = 0;
        goto call;
    }
    if (k == 11) {
        if (s1 < D_80145048) {
            j = 0;
            n = D_80145048;
            pl = (u8 *)D_80145044;
            for (; j < n; j++) {
                if ((B10Obj *)pl == o) {
                    goto null;
                }
                if ((B10Obj *)(pl + 0x2E8) == o) {
                    tab = D_800CFB04;
                    goto call;
                }
                pl += 0x16E8;
            }
        }
    }
    tab = D_800D0680[k];
call:
    func_00213AAC(o, &o->b170, tab);
    if (o->p1A0) {
        s2 = -o->b23A;
    }
    o->p1D8 = 0;
    if (a5 != -1) {
        func_002193C8(&o->b204, a5, &o->u8);
    }
    func_00246BD8(o, D_8011FE88->f54, D_8011FE88->f24, s2);
    if (s1) {
        o->f104 = (f32)s1;
        o->flags100 &= ~0x400;
    }
    o->w2E4 = func_00250B98() << 10;
    if (o->flags100 & 8) {
        o->fn27C = func_0024A790;
        o->s140 = D_800D0EF8;
        o->s158 = D_800D0EF8;
    }
}
