#include "o05_types.h"

extern O05Lobby *D_800E54A4;
extern u8 D_801462D5;
void func_002A338C(void);
void func_00404E28(s32 i);
void func_004337EC(s32 i);
void func_002A3358(void);
s32 func_0043C4E8(void *p);
void func_0043C260(void *p);
void func_0043C484(void *p);
void func_0029A73C(void);
void func_0042D1BC(void);
void func_0042D214(void);
void func_00438BD0(void);

s32 func_0042F988(s32 a, s32 b, s32 ev) {
    s32 i;
    if (ev != 1) {
        return 0;
    }
    if (D_800E54A4->h.f4C == 3) {
        for (i = 0; i < 4; i++) {
            if (D_800E54A4->plr[i].f14 > 0) {
                D_800E54A4->plr[i].f14--;
                if (D_800E54A4->plr[i].f14 == 0) {
                    D_800E54A4->plr[i].f14 = -1;
                    func_002A338C();
                    func_00404E28(i);
                    func_004337EC(i);
                    func_002A3358();
                }
            }
        }
    }
    if (func_0043C4E8(D_800E54A4->h.blk8) != 1) {
        return 0;
    }
    func_0043C260(D_800E54A4->h.blk8);
    func_0043C484(D_800E54A4->h.blk8);
    if (func_0043C4E8(D_800E54A4->h.blk8) != 2) {
        return 0;
    }
    if (D_800E54A4->h.f54 != 5) {
        return 0;
    }
    func_0029A73C();
    switch (D_801462D5) {
    case 0:
        func_0042D1BC();
        return 0;
    case 2:
        func_0042D214();
        return 0;
    case 1:
    case 3:
    case 4:
        func_00438BD0();
        break;
    }
    return 0;
}
