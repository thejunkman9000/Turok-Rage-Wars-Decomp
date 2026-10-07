#include "o05_types.h"

extern O05Lobby *D_800E54A4;
void func_0029A73C(void);
void func_00435958(s32 a);
s32 func_00435790(void);
void func_00433DA8(s32 a);
void func_00433F14(s32 a);
void func_00432488(s32 a);

s32 func_00432334(s32 a, s32 b, u32 idx) {
    func_0029A73C();
    idx &= 0xFFFF;
    if (D_800E54A4->h.f54 == 7) {
        func_00435958(3);
        return 0;
    }
    switch (D_800E54A4->plr[idx].state) {
    case 0:
        if (func_00435790() > 0) {
            return 0;
        }
        func_0029A73C();
        func_00435958(0x1B);
        return 0;
    case 12:
        func_0029A73C();
        D_800E54A4->plr[idx].name[D_800E54A4->plr[idx].fB44 * 2] = 0x20;
        break;
    case 22:
        func_0029A73C();
        func_00433DA8(-1);
        D_800E54A4->plr[idx].state = 13;
        func_00432488(idx);
        break;
    case 27:
        func_0029A73C();
        func_00433F14(-1);
        D_800E54A4->plr[idx].state = 13;
        func_00432488(idx);
        break;
    default:
        return 0;
    }
    return 0;
}
