#include "p3_types.h"

extern f32 D_800C9488;
extern f32 D_800C948C;
extern f32 D_800C9490;
extern f32 D_800C9494;

f32 func_00265734(f32 x) {
    if (x < 0.0f) {
        x = 0.0f;
    } else if (x > D_800C9488) {
        x = D_800C9488;
    }
    return (D_800C9490 - cosf(x * D_800C948C)) * D_800C9494;
}
