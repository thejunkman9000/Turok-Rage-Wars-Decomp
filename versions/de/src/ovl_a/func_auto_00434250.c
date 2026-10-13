#include "o05_types.h"

extern O05Lobby *D_800E54A4;
O05ItemWd *func_0040ECB0(void *w, s32 id);

void func_auto_00434250(s32 k, s32 dir) {
    s32 j;
    s32 sc;
    O05ItemWd *w;
    if (dir == 1) {
        if (D_800E54A4->plr[k].scroll < 15) {
            D_800E54A4->plr[k].scroll++;
            if (D_800E54A4->plr[k].scroll >= D_800E54A4->plr[k].cur + 3) {
                if (D_800E54A4->plr[k].cur + 3 < 15) {
                    D_800E54A4->plr[k].cur = D_800E54A4->plr[k].cur + 1;
                } else {
                    D_800E54A4->plr[k].cur = 13;
                }
            }
        }
    } else {
        if (D_800E54A4->plr[k].scroll > 0) {
            D_800E54A4->plr[k].scroll--;
            if (D_800E54A4->plr[k].cur > 0) {
                if (D_800E54A4->plr[k].scroll - D_800E54A4->plr[k].cur < 0) {
                    D_800E54A4->plr[k].cur = D_800E54A4->plr[k].cur - 1;
                }
            }
        }
    }
    for (j = 0; j < 3; j++) {
        D_800E54A4->plr[k].wd[j]->b10 = 0xFF;
        D_800E54A4->plr[k].wd[j]->f38 = &D_800E54A4->plr[k].items[D_800E54A4->plr[k].cur + j];
    }
    sc = D_800E54A4->plr[k].scroll;
    w = func_0040ECB0(D_800E54A4->plr[k].fC, 0x2EC);
    w->f38 = (u8 *)&D_800E54A4->plr[k].items[sc] + 0x3C;
}
