#include "o05_types.h"

extern O05Lobby *D_800E54A4;
extern s32 D_800D7700;
s32 func_00404F04(void);
s32 func_00404BE8(s32 a, s32 k, s32 *out);
s32 func_00434814(s32 k, s32 a);
s32 func_00435304(s32 k);
s32 func_00435360(s32 k);
s32 func_00435AE8(s32 k);
s32 func_00274544(void);
void func_00432488(s32 k);

void func_004337EC(s32 k) {
    s32 done = 1;
    s32 r;
    s32 v;
    s8 one;
    r = func_00404F04() + 5;
    one = done;
    do {
        switch (r) {
        case 1:
        case 2:
        case 4:
            D_800E54A4->plr[k].state = 3;
            break;
        case 5:
            if (D_800E54A4->h.f54 == 6) {
                D_800E54A4->plr[k].state = D_800E54A4->plr[k].f8;
                break;
            }
            if (func_00404BE8(D_800D7700, k, &v) == one) {
                if (func_00434814(k, v) == one) {
                    D_800E54A4->plr[k].state = D_800E54A4->plr[k].f8;
                    switch (D_800E54A4->h.f54) {
                    case 0:
                        if (func_00435304(k) == -1) {
                            D_800E54A4->plr[k].state = 24;
                        }
                        break;
                    case 7:
                        if (func_00435360(k) == one) {
                            D_800E54A4->plr[k].state = 15;
                        }
                        break;
                    case 2:
                        if (func_00435360(k) == one) {
                            goto st25;
                        } else if (D_800E54A4->plr[k].fB30 == one) {
                            if (func_00435304(k) == -1) {
                                D_800E54A4->plr[k].state = 24;
                            }
                        }
                        break;
                    case 5:
                        if (func_00435AE8(k) == 0) {
                            D_800E54A4->plr[k].state = 21;
                        }
                        break;
                    }
                }
            } else {
                switch (D_800E54A4->h.f54) {
                case 0:
                case 1:
                case 7:
                    D_800E54A4->plr[k].fB64 = func_00274544() % 9999999 + 1;
                    D_800E54A4->plr[k].state = 15;
                    break;
                case 5:
                    D_800E54A4->plr[k].state = 21;
                    break;
                case 4:
                    D_800E54A4->plr[k].state = D_800E54A4->plr[k].f8;
                    break;
                case 2:
                case 3:
                st25:
                    D_800E54A4->plr[k].state = 25;
                    break;
                }
            }
            break;
        case 0:
        case 3:
        default:
            D_800E54A4->plr[k].state = one;
            break;
        }
    } while (!done);
    func_00432488(k);
}
