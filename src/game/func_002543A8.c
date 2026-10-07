#include "b12_types.h"

s32 func_0028FE1C(s32 a, s32 b, s32 c, s32 *out);
void func_002518DC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);

void func_002543A8(s32 unused, s32 a1, s32 a2, s32 a3, s32 p4, s32 p5, s32 p6) {
    s32 out;
    s32 r = func_0028FE1C(a1, a3, a2, &out);
    func_002518DC(0, r, r, out, 0x1B, p4, p5, p6, 1);
}
