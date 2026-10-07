#include "b19_types.h"

extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];
void func_00279A70(B19Obj *);
void func_0028414C(B19Obj *);
void func_002A52E4(void *, B19Obj *);
void func_00268C7C(void *, s32);
void func_00255E78(void *, void *);
void func_00255C58(void *, void *);
s32 func_0028403C(B19Obj *);
void func_00265E30(B19Obj *, B19Obj *, s32, s32, B19Vec3, B19Rec8);
void func_00279BB0(B19Obj *, s32, s32, s32);
void func_0025DE74(s16, f32, f32, f32, s32, s32);

#define FREE_OBJ(owner, o) \
    if ((o)->flags & 0x100) { \
      if (!((o)->flags & 0x800)) { \
        func_00279A70(o); \
        if ((o)->unk1D9 != 0) { \
            func_0028414C(o); \
            func_002A52E4(D_8013BA80, o); \
        } \
        if ((o)->unk138 != 0) { \
            func_00268C7C(D_8013B1A8, (o)->unk138); \
            (o)->unk138 = 0; \
        } \
        if ((o)->unk130 != 0) { \
            *(o)->unk130 -= 1; \
        } \
        (o)->flags &= 0xFDFFFEFF; \
        func_00255E78((o)->slotp, o); \
        (o)->slotp = 0; \
        func_00255C58(&(owner)->la, o); \
        if ((o)->flags & 0x1000000) { \
            func_00255E78(&(owner)->lb, o); \
        } \
    }}

void func_0025DF54();
void func_0028279C(B19Owner *owner, s32 key) {
    B19Obj *o;
    B19Obj *next;
    B19Parent *par;
    s32 k, s2, a2, s3;
    B19Rec8 r;
    s32 cnt = 0;
    o = owner->slot[1].head;
    while (o != 0) {
        next = o->next;
        if (o->id == 0x41E && (o->flags & 0x100) && o->unk12C == key) {
            o->flags &= ~0x100;
            par = o->parent;
            k = func_0028403C(o) ? 12 : 10;
            s2 = par->tbl->w70[k];
            a2 = par->tbl->w8C[k];
            r = par->tbl->rec[k];
            s3 = par->tbl->wA8[k];
            if (a2 != 0xFFFF) func_00265E30(o, o, a2, -1, o->pos, r);
            if (s2 != 0xFFFF) func_00279BB0(o, s2, o->unk1D0, 1);
            if (s3 != 0xFFFF) func_0025DE74(s3, o->pos.x, o->pos.y, o->pos.z, 0, -1);
            o->flags |= 0x100;
            FREE_OBJ(owner, o)
            cnt++;
        }
        o = next;
    }
    if (cnt != 0) {
        func_0025DF54(0x91A);
        func_0025DF54(0x91A);
    }
}
