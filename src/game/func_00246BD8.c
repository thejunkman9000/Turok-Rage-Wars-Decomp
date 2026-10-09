
#include "b10_types.h"

extern u8 D_800C898C[];
extern u8 D_800C89A0[];
extern u8 D_800C89B4[];
s32 func_0028FE08(s32 a, s32 b, s32 c);
s32 func_0028FE1C(s32 a, s32 b, s32 c, s32 *d);
s32 **func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, u8 *h, s32 i);
s32 **func_00254094(s32 a, s32 **p, s32 c, u8 *d, s32 e);
void func_002536F4(s32 a, s32 **p);
u8 *func_0028FD94(s32 n, s32 i);
void func_0026EE90(u8 *a, u8 *b, u8 *c);
void func_002624A0(u8 *p);
s32 func_002469F8(B10Obj *o, s32 key, s32 skip);

void func_00246BD8(B10Obj *o, s32 a1, s32 a2, s32 a3) {
    s32 **r2;
    s32 **r3;
    s32 **r1;
    s32 *hd;
    u8 *n;
    s32 v;
    s32 s1;
    s32 s0;
    s32 t;
    v = a3;
    o->fD8 = -1;
    o->fDC = 0;
    o->fE0 = 0;
    o->flags100 &= 0xFFFBFFFF;
    t = func_0028FE08(a1, a2, o->h4);
    r1 = func_002518DC(0, t, t, 0x18, 0, 0, 0, D_800C898C, 1);
    if (r1) {
        s0 = (s32)*r1;
        o->fCC = func_0028FE08(s0, t, 1);
        r2 = func_00254094(0, (s32 **)&hd, o->fCC, D_800C89A0, 1);
        if (r2) {
            o->bE7 = ((u8 *)hd)[3];
            o->fD4 = ((*hd << 2) + 0xF) & ~7;
            func_002536F4(0, r2);
        }
        o->fC4 = func_0028FE1C(s0, t, 0, &o->fD0);
        o->fC8 = func_0028FE08(s0, t, 2);
        r3 = func_002518DC(0, o->fC4, o->fC4, o->fD0, 0, 0, 0, D_800C89B4, 1);
        if (r3) {
            s1 = (s32)*r3;
            n = func_0028FD94(s1, 0);
            ((void (*)(B10Obj *, u8 *))o->fn28C)(o, &o->b170);
            func_0026EE90(&o->b74, n, &o->bE8);
            func_002624A0(&o->f104);
            func_002624A0((u8 *)&o->an118);
            o->bE6 = func_0028FD94(s1, 1)[7];
            o->flags100 |= 0x40000;
            if (a3 > 0) {
                v = func_002469F8(o, a3, -1);
            } else {
                v = -a3;
            }
            if (v == -1) {
                v = 0;
            }
            o->h10A = v;
            o->b10E = 0;
            if (o->h108 != v) {
                o->b10F = 1;
            }
            o->b1A5 = -1;
            o->b23A = v;
            func_002536F4(0, r3);
        }
        func_002536F4(0, r1);
    }
}


