#include "common.h"

u16 F32ToTrunc16(f32 x) {
    return *(u16 *)&x;
}
