#include "b17_types.h"

extern s32 D_800D2978;
extern s8 D_800D2854[];

f32 func_00278900(IdObj *o) {
    u8 m = o->id;
    s32 n = D_800D2978 + (((u8)(m % 7u)) + 1) * 16;
    n %= 90;
    return D_800D2854[n];
}
