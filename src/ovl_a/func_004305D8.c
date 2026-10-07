#include "o05_types.h"

typedef struct O05Ch { u8 pad[0x2C]; struct O05Ch *f2C; } O05Ch;
extern O05Lobby *D_800E54A4;
s32 func_0029EB58(s32 a);
s32 func_0029AB4C(void);
void func_0029A73C(void);
void func_00435010(s32 i);
void func_0025DF54(s32 a);
void func_0043442C(s32 i, s32 a);
O05Ch *func_0041B87C(void *p, s32 idx);
s32 func_0040EC50(O05Ch *c);
void func_0041B95C(void *p, s32 idx, O05Ch *c);
void func_00433DA8(s32 i);
void func_00433F14(s32 i);

s32 func_004305D8(s32 a, s32 b, u32 c, s32 ev, s32 e5) {
    s32 k = c & 0xFFFF;
    O05Ch *s;
    switch (D_800E54A4->plr[k].state) {
    case 12:
        if (func_0029EB58(e5) < func_0029AB4C()) {
            D_800E54A4->plr[k].fB4C = 0;
            D_800E54A4->plr[k].fB48 = 2;
        }
        if (ev != 1) {
            return 0;
        }
        func_0029A73C();
        D_800E54A4->plr[k].fB48 = 1;
        func_00435010(k);
        func_0025DF54(0xE81);
        return 0;
    case 4:
        if (ev != 1) {
            return 0;
        }
        func_0029A73C();
        func_0043442C(k, 0);
        D_800E54A4->h.w2C[k] = 0;
        func_0025DF54(0xE74);
        return 0;
    case 13:
        if (D_800E54A4->plr[k].f4 != 6) {
            return 0;
        }
        if (ev != 1) {
            return 0;
        }
        func_0029A73C();
        s = func_0041B87C(D_800E54A4->h.f4, k)->f2C;
        while (func_0040EC50(s) != 0) {
            s = s->f2C;
        }
        func_0041B95C(D_800E54A4->h.f4, k, s);
        func_0025DF54(0xE74);
        return 0;
    case 22:
        if (ev == 1) {
            s = func_0041B87C(D_800E54A4->h.f4, k)->f2C;
            while (func_0040EC50(s) != 0) {
                s = s->f2C;
            }
            func_0041B95C(D_800E54A4->h.f4, k, s);
            func_00433DA8(k);
        }
        func_0029A73C();
        break;
    case 27:
        if (ev == 1) {
            s = func_0041B87C(D_800E54A4->h.f4, k)->f2C;
            while (func_0040EC50(s) != 0) {
                s = s->f2C;
            }
            func_0041B95C(D_800E54A4->h.f4, k, s);
            func_00433F14(k);
        }
        func_0029A73C();
        break;
    }
    return 0;
}
