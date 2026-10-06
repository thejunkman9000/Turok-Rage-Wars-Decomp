#include "b19_types.h"
extern u8 D_80121990[];
extern u8 D_8011FE88[];
extern f32 D_800C9F4C;
extern f32 D_800C9F50;
extern f32 D_800C9F54;
void *memset(void *, s32, u32);
void func_0025DE74(s16, f32, f32, f32, void *, s32);
void func_0022B540(B19Plr *, f32, f32, s32, s32);
void func_0028CE70(void *, u8 *, s32, B19Vec3, f32, f32);
s32 func_0028403C(B19Obj *);
void func_00265E30(B19Obj *, B19Obj *, s32, s32, B19Vec3, B19Rec8);
void func_00279BB0(B19Obj *, s32, s32, s32);
void func_00284544(void *, B19Obj *);
void func_00284408(B19Obj *);
void func_00282E6C(B19Obj *o, B19Plr *p) {
    B19Vec3 v;
    B19Parent *par;
    s32 k;
    s32 s2, a2, s3;
    B19Rec8 r;
    memset(&v, 0, 12);
    if (o->id == 0x40F) {
        func_0025DE74(0xCDA, p->pos.x, p->pos.y, p->pos.z, &p->pos, -1);
        func_0022B540(p, 30.0f, 3.0f, o->unk12C, 0);
        func_0028CE70(D_8011FE88, p->f698 + 0x140, 0x14, v, D_800C9F4C, D_800C9F50);
        p->f11EC = D_800C9F54;
    }
    par = o->parent;
    k = func_0028403C(o) ? 0xC : 0xA;
    s2 = par->tbl->w70[k];
    a2 = par->tbl->w8C[k];
    r = par->tbl->rec[k];
    s3 = par->tbl->wA8[k];
    if (a2 != 0xFFFF) func_00265E30(o, o, a2, -1, o->pos, r);
    if (s2 != 0xFFFF) func_00279BB0(o, s2, o->unk1D0, 1);
    if (s3 != 0xFFFF) func_0025DE74(s3, o->pos.x, o->pos.y, o->pos.z, 0, -1);
    func_00284544(D_80121990, o);
    func_00284408(o);
}
