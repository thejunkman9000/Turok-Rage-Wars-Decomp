#include "o05_types.h"

typedef struct { u8 pad[0x10]; u8 b10; } O05Obj10;
extern O05Lobby *D_800E54A4;
O05Obj10 *func_0041B87C(void *p, s32 idx);
void func_0025DF54(s32 a);

s32 func_00430208(s32 a, s32 b, u32 c, s32 d) {
    s32 idx = c & 0xFFFF;
    O05Obj10 *obj;
    if (D_800E54A4->plr[idx].state == 13) {
        return 0;
    }
    if (D_800E54A4->plr[idx].state >= 14) {
        return 0;
    }
    if (D_800E54A4->plr[idx].state != 12) {
        return 0;
    }
    if (d != 1) {
        return 0;
    }
    obj = func_0041B87C(D_800E54A4->h.f4, idx);
    D_800E54A4->plr[idx].fB48 = 2;
    D_800E54A4->plr[idx].fB4C = 0;
    if (D_800E54A4->plr[idx].fB44 > 0) {
        D_800E54A4->plr[idx].fB44--;
    }
    if (D_800E54A4->plr[idx].name[D_800E54A4->plr[idx].fB44 * 2] == 0) {
        D_800E54A4->plr[idx].name[D_800E54A4->plr[idx].fB44 * 2] = 0x41;
    }
    obj->b10 = 0xFF;
    func_0025DF54(0xE74);
    return 0;
}
