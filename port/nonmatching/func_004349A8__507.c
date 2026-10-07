#include "o05_types.h"

extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];
void func_002A1724(void *dst, void *src, s32 n);
void func_0022EF20(void *p);

void func_004349A8(void) {
    s32 tmp[4];
    s32 i;
    s32 j;
    s32 s;
    s32 sz = 0x190;
    func_002A1724(D_800E54A4->recs, D_80102B00, 0x640);
    for (i = 0; i < 4; i++) {
        func_0022EF20(&D_80102B00[i]);
        tmp[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        s = D_800E54A4->plr[i].fB28;
        if (s >= 0) {
            func_002A1724(&D_80102B00[i], &D_800E54A4->recs[s], sz);
            tmp[s] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (tmp[i] == 0 && D_800E54A4->recs[i].bD >= 0) {
            for (j = 0; j < 4; j++) {
                if (D_80102B00[j].bD < 0) {
                    func_002A1724(&D_80102B00[j], &D_800E54A4->recs[i], sz);
                    break;
                }
            }
        }
    }
}
