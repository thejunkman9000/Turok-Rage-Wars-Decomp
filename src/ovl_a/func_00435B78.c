#include "o05_types.h"

extern O05Lobby *D_800E54A4;

void func_00435B78(s32 a, s32 b, s32 i) {
    O05SlotAt *p = (O05SlotAt *)((u8 *)D_800E54A4 + i * 12);
    p->s.a = a;
    p->s.b = b;
    p->s.c = 1;
}
