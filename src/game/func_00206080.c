#include "b01_types.h"

extern u8 D_801462C8[];
f32 func_00274B00(f32 a, f32 b);

void func_00206080(B01Actor *actor, B01State *state) {
    B01Info *info = B01_INFO(actor->def);
    f32 v = func_00274B00(info->unkC.f, info->unk10.f);
    u8 *g = D_801462C8;
    state->unk64 = v;
    if (g[0x1D] != 0) {
        u32 n = *(u32 *)(g - 0x1258);
        if (n >= 3) {
            state->unk64 = v * 0.01f * (f32)(u32)(100 - (n - 2) * 25);
        }
    }
}
