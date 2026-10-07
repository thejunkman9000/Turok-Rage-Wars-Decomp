#include "o05_types.h"

extern O05Lobby *D_800E54A4;
extern O05Rec D_80102B00[];
void func_0022EF20(void *p);
void func_00433DA8(s32 a);

void func_00435A20(s32 i) {
    if (D_800E54A4->slot[i].c == 1) {
        func_0022EF20(&D_80102B00[i]);
        D_800E54A4->slot[i].c = 2;
        func_00433DA8(-1);
    }
}
