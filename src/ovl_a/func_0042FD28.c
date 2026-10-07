#include "o05_types.h"

extern O05Lobby *D_800E54A4;
void func_0029A73C(void);
void func_00432488(s32 k);
s32 func_0043492C(void);

s32 func_0042FD28(s32 a, s32 b, u32 c, s32 d) {
    s32 k = c & 0xFFFF;
    if ((c >> 16) == 3) {
        switch (D_800E54A4->h.f54) {
        case 7:
            break;
        case 5:
            break;
        case 6:
            if (d == 10) {
                if (D_800E54A4->plr[k].state == 4) {
                    func_0029A73C();
                    D_800E54A4->plr[k].f14 = 2;
                    D_800E54A4->plr[k].state = 2;
                    D_800E54A4->plr[k].f8 = 4;
                    func_00432488(k);
                }
            }
            break;
        case 4:
            switch (d) {
            case 11:
            case 13:
                if (D_800E54A4->plr[k].state == 0) {
                    func_0029A73C();
                    D_800E54A4->plr[k].f14 = 2;
                    D_800E54A4->plr[k].state = 2;
                    D_800E54A4->plr[k].f8 = 4;
                    func_00432488(k);
                }
                break;
            case 10:
                if (D_800E54A4->plr[k].state == 4) {
                    func_0029A73C();
                    D_800E54A4->plr[k].f14 = 2;
                    D_800E54A4->plr[k].state = 2;
                    D_800E54A4->plr[k].f8 = 4;
                    func_00432488(k);
                }
                break;
            }
            break;
        case 0:
            if (d == 11 || d == 13) {
                if (D_800E54A4->plr[k].state == 0) {
                    func_0029A73C();
                    D_800E54A4->plr[k].f14 = 2;
                    D_800E54A4->plr[k].state = 2;
                    D_800E54A4->plr[k].f8 = 12;
                    func_00432488(k);
                }
            }
            break;
        case 3:
            if (d == 11 || d == 13) {
                if (D_800E54A4->plr[k].state == 0) {
                    func_0029A73C();
                    D_800E54A4->plr[k].f14 = 2;
                    D_800E54A4->plr[k].state = 2;
                    D_800E54A4->plr[k].f8 = 13;
                    D_800E54A4->plr[k].f4 = 5;
                    func_00432488(k);
                }
            }
            break;
        case 1:
            if (d == 11 || d == 13) {
                if (D_800E54A4->plr[k].state == 0) {
                    func_0029A73C();
                    D_800E54A4->plr[k].state = 14;
                    if (func_0043492C() >= 0) {
                        D_800E54A4->plr[k].f14 = 2;
                        D_800E54A4->plr[k].state = 2;
                        D_800E54A4->plr[k].f8 = 13;
                        D_800E54A4->plr[k].f4 = 6;
                    }
                    func_00432488(k);
                }
            }
            break;
        case 2:
            if (d == 11 || d == 13) {
                if (D_800E54A4->plr[k].state == 0) {
                    func_0029A73C();
                    D_800E54A4->plr[k].state = 14;
                    if (func_0043492C() >= 0) {
                        D_800E54A4->plr[k].f14 = 2;
                        D_800E54A4->plr[k].state = 2;
                        D_800E54A4->plr[k].f8 = 13;
                        D_800E54A4->plr[k].f4 = 3;
                    }
                    func_00432488(k);
                }
            }
            break;
        }
    }
    return 0;
}

