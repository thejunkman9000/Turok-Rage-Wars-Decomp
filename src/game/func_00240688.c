#include "b09_types.h"

s32 func_00240688(B09Obj *a0, s32 a1, B09V3 v, s32 x, s32 y, B09V3 *out) {
    u8 buf[0x20];
    *out = v;
    return *(s32 *)((u8 *)a0 + 0x14);
}
