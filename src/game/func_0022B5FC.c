#include "b06_types.h"

void func_00216488(f32 *out, s32 a, s32 b, f32 c, s32 d, s32 e);
void func_00219A40(Plr *a, u8 *b, f32 *c);
extern f32 D_800CE3E0;

void func_0022B5FC(Plr *a, f32 x, s32 y) {
    f32 buf[6];
    f32 v = a->unk12C0 + x;
    f32 t = D_800CE3E0;
    if (!(t <= v)) {
        t = v;
    }
    a->unk12C0 = t;
    if (D_800CE3E0 <= t) {
        func_00216488(buf, y, 0x40000, 25.599998f, 0x80, 0);
        func_00219A40(a, (u8 *)a + 0x170, buf);
    }
}
