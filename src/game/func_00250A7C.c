#include "b12_types.h"

extern u8 D_800D297B;
extern u32 D_800D2640;
void func_00253F2C(s32 a, u32 b);

void func_00250A7C(B12Obj *o) {
    if (!(o->unkD8 & 0x40) && o->unkDA != D_800D297B) {
        func_00253F2C(0, o->unkD0 | D_800D2640);
    }
}
