#include "b24_types.h"

void func_002A98E0(s32, f32, f32, f32, f32, s32, s32, s32);

void func_002ABB6C(s32 a, f32 b, f32 c, f32 d, f32 e, s32 f, s32 g, s32 h) {
    if (f != 0) {
        func_002A98E0(a, b, c, d, e, 1, g, h);
    }
    func_002A98E0(a, b, c, d, e, 0, g, h);
}
