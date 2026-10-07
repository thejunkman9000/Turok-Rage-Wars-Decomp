#include "b17_types.h"

extern f32 D_800C9A58;
extern f32 D_800C9A5C;
extern f32 D_800C9A60;
extern f32 D_800C9A64;

f32 func_002749B4(f32 x) {
    while (x < D_800C9A58) {
        x += D_800C9A5C;
    }
    while (D_800C9A60 < x) {
        x -= D_800C9A64;
    }
    return -x;
}
