
#include "b19_types.h"

extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];
void func_00279A70(B19Obj *);
void func_0028414C(B19Obj *);
void func_002A52E4(void *, B19Obj *);
void func_00268C7C(void *, s32);
void func_00255E78(void *, void *);
void func_00255C58(void *, void *);
inline void func_00284544(B19Owner *owner, B19Obj *o) {
    if (o->flags & 0x100) {
      if (!(o->flags & 0x800)) {
        func_00279A70(o);
        if (o->unk1D9 != 0) {
            func_0028414C(o);
            func_002A52E4(D_8013BA80, o);
        }
        if (o->unk138 != 0) {
            func_00268C7C(D_8013B1A8, o->unk138);
            o->unk138 = 0;
        }
        if (o->unk130 != 0) {
            *o->unk130 -= 1;
        }
        o->flags &= 0xFDFFFEFF;
        func_00255E78(o->slotp, o);
        o->slotp = 0;
        func_00255C58(&owner->la, o);
        if (o->flags & 0x1000000) {
            func_00255E78(&owner->lb, o);
        }
    }}
}

void func_0028324C(B19Owner *owner, s32 key) {
    B19Obj *o;
    B19Obj *next;
    o = owner->slot[2].head;
    while (o != 0) {
        next = o->next;
        if ((o->id == 0x414 || o->id == 0x42D) && o->unk12C == key) func_00284544(owner, o);
        o = next;
    }
}
void func_002830A0(B19Owner *owner, s32 key) {
    B19Obj *o;
    B19Obj *next;
    o = owner->slot[1].head;
    while (o != 0) {
        next = o->next;
        if ((o->id == 0x41E || o->id == 0x3EF) && (o->flags & 0x100) && o->unk12C == key) func_00284544(owner, o);
        o = next;
    }
}
