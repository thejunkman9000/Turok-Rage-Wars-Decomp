#include "o05_types.h"

extern O05Lobby *D_800E54A4;
extern u8 D_801462D5;
void func_002A338C(void);

void func_00435958(s32 a) {
    func_002A338C();
    D_800E54A4->h.f4C = 5;
    D_800E54A4->h.f50 = 4;
    D_800E54A4->f3470 = a;
    if (a == -2) {
        switch (D_801462D5) {
        case 0:
            D_800E54A4->f3470 = 7;
            break;
        case 1:
            D_800E54A4->f3470 = 7;
            break;
        case 2:
            D_800E54A4->f3470 = 9;
            break;
        case 3:
            D_800E54A4->f3470 = 7;
            break;
        case 4:
            D_800E54A4->f3470 = 10;
            break;
        }
    }
}
