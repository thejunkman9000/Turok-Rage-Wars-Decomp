#include "b19_types.h"
s32 func_0028403C(B19Obj *);
void func_00265E30(B19Obj *, B19Obj *, s32, s32, B19Vec3, B19Rec8);
void func_00279BB0(B19Obj *, s32, s32, s32);
void func_0025DE74(s16, f32, f32, f32, void *, void *);
void func_00283E2C(B19Obj *o) {
    B19Parent *par = o->parent;
    s32 k = func_0028403C(o) ? 13 : 11;
    s32 s2 = par->tbl->w70[k];
    s32 a2 = par->tbl->w8C[k];
    B19Rec8 r = par->tbl->rec[k];
    s32 s3 = par->tbl->wA8[k];
    if (a2 != 0xFFFF) func_00265E30(o, o, a2, -1, o->pos, r);
    if (s2 != 0xFFFF) func_00279BB0(o, s2, o->unk1D0, 1);
    if (s3 != 0xFFFF) func_0025DE74(s3, o->pos.x, o->pos.y, o->pos.z, &o->pos, o);
}
