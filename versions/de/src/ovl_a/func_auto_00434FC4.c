#include "o05_types.h"

typedef struct { u8 pad[0x10]; u8 b10; } O05Obj10;
extern O05Lobby *D_800E54A4;
f32 cosf(f32 x);
O05Obj10 *func_0040ECB0(void *w, s32 id);

void func_auto_00434FC4(s32 k) {
    f32 x;
    u8 v;
    x = cosf((f32)k + (f32)D_800E54A4->h.w2C[k] * 0.0033333334f) * 100.0f + 150.0f;
    v = (u32)x;
    func_0040ECB0(D_800E54A4->plr[k].f10, 0x2E4)->b10 = v;
    func_0040ECB0(D_800E54A4->plr[k].f10, 0x2E5)->b10 = v;
}
