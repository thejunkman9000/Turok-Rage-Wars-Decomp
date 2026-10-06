#include "b14_types.h"
f32 func_002615D4(s32 a0, s32 a1, s32 a2, s32 a3, s32 unused, f32 t) {
    return *(f32 *)&a0 + *(f32 *)&a1 * t + *(f32 *)&a2 * t * t + *(f32 *)&a3 * t * t * t;
}
