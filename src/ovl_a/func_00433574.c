#include "o05_types.h"

extern O05Lobby *D_800E54A4;
f32 cosf(f32 x);
void func_004351A0(s32 i);
void func_00435010(s32 i);
void func_004350D0(s32 i);
O05ItemWd *func_0041B87C(void *p, s32 idx);

void func_00433574(s32 dt) {
    s32 i;
    O05ItemWd *w;
    for (i = 0; i < 4; i++) {
        switch (D_800E54A4->plr[i].state) {
        case 0:
            func_004351A0(i);
            break;
        case 12:
            w = func_0041B87C(D_800E54A4->h.f4, i);
            w->b10 = (u32)(cosf((f32)i + (f32)D_800E54A4->h.w2C[i] * 0.005f) * 100.0f + 150.0f);
            switch (D_800E54A4->plr[i].fB48) {
            case 0:
                D_800E54A4->plr[i].fB4C++;
                if (D_800E54A4->plr[i].fB4C >= 6) {
                    func_004350D0(i);
                }
                break;
            case 1:
                D_800E54A4->plr[i].fB4C++;
                if (D_800E54A4->plr[i].fB4C >= 6) {
                    func_00435010(i);
                }
                break;
            case 2:
                break;
            }
            break;
        case 4:
            w = D_800E54A4->plr[i].wd[D_800E54A4->plr[i].scroll - D_800E54A4->plr[i].cur];
            w->b10 = (u32)(cosf((f32)i + (f32)D_800E54A4->h.w2C[i] * 0.005f) * 100.0f + 150.0f);
            break;
        }
        D_800E54A4->h.w2C[i] += dt;
    }
}
