#include "o03_types.h"
extern O3Ps *D_800E39C0;
f32 cosf(f32 x);
O3Hdr *func_0040ECB0(s32 p, s32 id);
s32 func_0041ED24(s32 a0, s32 a1, s32 dt) {
    O3Hdr *it;
    f32 v;
    D_800E39C0->timer = D_800E39C0->timer + dt;
    it = func_0040ECB0(D_800E39C0->w[D_800E39C0->sel], 0x392);
    v = cosf((f32)D_800E39C0->timer * 0.0033333334f) * 100.0f + 150.0f;
    it->alpha = (u32)v;
    return 0;
}
