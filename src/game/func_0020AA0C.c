#include "b02_types.h"

f32 func_00209AE8(B2Ctl *ctl);
extern f32 D_800C6E24;
extern f32 D_800C6E28;

f32 func_0020AA0C(B2Ctl *ctl) {
    return (D_800C6E24 - func_00209AE8(ctl)) * D_800C6E28;
}
