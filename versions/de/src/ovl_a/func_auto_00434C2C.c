#include "o05_types.h"
typedef struct { u8 pad[0x38]; void *f38; } O05Wd;
extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];
extern O05GameState D_801462C8[];
O05Wd *func_0040ECB0(void *w, s32 id);

void func_auto_00434C2C(s32 k) {
    s32 i;
    s32 n = 0;
    s32 id;
    for (i = 0; i < 4; i++) {
        switch (n) {
        case 0:
            id = 0x2AA;
            break;
        case 1:
            id = 0x2AB;
            break;
        case 2:
            id = 0x2AC;
            break;
        default:
            id = 0x2AD;
            break;
        }
        if (D_80102B00[i].bE == 0 && D_80102B00[i].bD == k && D_801462C8->rec[i].b0 == 1 && D_801462C8->rec[i].b19 == 0) {
            O05Wd *w = func_0040ECB0(D_800E54A4->plr[k].fC, id);
            n++;
            w->f38 = &D_80102B00[i];
        }
    }
}
