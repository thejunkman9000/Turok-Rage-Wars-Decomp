#include "b14_types.h"
f32 func_00260654(f32 x, s32 bits) {
    return x / (f32)((1 << bits) - 1);
}
