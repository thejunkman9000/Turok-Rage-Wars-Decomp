#include "common.h"

f32 Trunc16ToF32(u16 x) {
    u32 v = (u32)x << 16;
    return *(f32 *)&v;
}
