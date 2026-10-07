#include "o05_types.h"
typedef struct { u8 pad[0x10]; u8 b10; } O05Obj10;
typedef struct R {
    s32 state;
    u8 pad4[0xB44 - 4];
    s32 fB44;
    s32 fB48;
    s32 fB4C;
    u8 padB50[0xB64 - 0xB50];
    s32 fB64;
    u8 padB68[0xB68 - 0xB68];
} R;
typedef struct { u8 pad[0x58]; R plr[4]; } LR;
extern LR *D_800E54A4;
O05Obj10 *func_0041B87C(void *p, s32 idx);
void func_0025DF54(s32 a);

s32 func_00430120(s32 a, s32 b, u32 c, s32 d) {
    s32 idx = c & 0xFFFF;
    O05Obj10 *obj;
    if (D_800E54A4->plr[idx].state != 12) {
        return 0;
    }
    obj = func_0041B87C(*(void **)((u8 *)D_800E54A4 + 4), idx);
    D_800E54A4->plr[idx].fB4C = 0;
    D_800E54A4->plr[idx].fB48 = 2;
    if (d == 1) {
        s32 v = D_800E54A4->plr[idx].fB44 + 1;
        if (v < 7) {
            D_800E54A4->plr[idx].fB44 = v;
        }
        if (*((u8 *)D_800E54A4 + (idx * 0xB68 + D_800E54A4->plr[idx].fB44 * 2) + 0xB8C) == 0) {
            *((u8 *)D_800E54A4 + (idx * 0xB68 + D_800E54A4->plr[idx].fB44 * 2) + 0xB8C) = 0x41;
        }
        obj->b10 = 0xFF;
        func_0025DF54(0xE74);
    }
    return 0;
}
