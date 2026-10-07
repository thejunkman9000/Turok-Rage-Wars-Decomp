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
        (o)->flags &= cmask; \
        func_00255E78((o)->slotp, o); \
        (o)->slotp = 0; \
        func_00255C58((u8 *)(owner) + c00, o); \
        if ((o)->flags & cbit) { \
            func_00255E78((u8 *)(owner) + c14, o); \
        } \
    }}

void func_0027FF2C(B19Owner *owner) {
    s32 i, c14, c00, cbit, cmask;
    B19Obj *o;
    B19Obj *next;
    i = 0;
    cmask = 0xFDFFFEFF;
    c00 = 0xFC00;
    cbit = 0x1000000;
    c14 = 0xFC14;
    do {
        next = *(B19Obj **)((u8 *)owner + i * 0x14 + 0xFC28);
        if (next != 0) {
        do {
            o = next;
            next = o->next;
            FREE_OBJ(owner, o)
        } while (next != 0);
        }
        i++;
    } while (i < 3);
}