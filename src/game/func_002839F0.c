#include "b19_types.h"
extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];
void func_0028414C(B19Obj *);
void func_002A52E4(void *, B19Obj *);
void func_00268C7C(void *, s32);
void func_002839F0(B19Obj *o) {
    if (o->unk1D9 != 0) {
        func_0028414C(o);
        func_002A52E4(D_8013BA80, o);
    }
    if (o->unk138 != 0) {
        func_00268C7C(D_8013B1A8, o->unk138);
        o->unk138 = 0;
    }
}
