#include "b19_types.h"
extern B19Glob D_801041F0[];
extern B19Src D_801041F8[];
void func_00270980(B19Mtx *, B19Mtx *);
void func_0026EFC8(B19Mtx *, B19Mtx *);
void func_00272908(B19Mtx *, B19Src *, void *);
void func_002720EC(B19Vec3 *);
void func_00272BA8(B19Mtx *, B19Vec3 *, void *);
void func_00283BF0(B19Obj *o, B19Mtx *m, s32 t) {
    B19Mtx a;
    B19Mtx b;
    B19Vec3 v;
    B19GObj *g = (B19GObj *)D_801041F0->g;
    if (m != 0) {
        func_0026EFC8(&b, m);
    } else {
        func_00270980(&a, (B19Mtx *)((u8 *)g->mtx + (D_801041F0->idx << 6)));
        func_0026EFC8(&b, &a);
    }
    func_00272908(&b, D_801041F8, (u8 *)o + 0x50);
    v = D_801041F8->b;
    func_002720EC(&v);
    func_00272BA8(&b, &v, &o->pos2);
    o->unk134 = g;
    o->flags |= 0x10000;
    o->unk1D1 = D_801041F8->fF;
    if (o->id == 0x56 && t == 2) o->flags |= 0x4000000;
}
