#include "common.h"

void func_00245A10(s32 a);
void func_002459F0(f32 a);
void func_00245A4C(s32 a, s32 b, s32 c, s32 d);
extern s32 D_800E28D8;

void func_0028D8E8(void) {
    s32 w;
    s32 h;
    func_00245A10(0);
    func_002459F0(75.0f);
    w = 0x1E0;
    if (D_800E28D8 == 0) {
        w = 0x17C;
        h = 0xDC;
    } else {
        h = 0x168;
    }
    func_00245A4C(w, h, 0, 0);
}
