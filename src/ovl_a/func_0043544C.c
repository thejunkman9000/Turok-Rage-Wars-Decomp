#include "o05_types.h"
extern O05Lobby *D_800E54A4;
s32 func_0043544C(s32 a, s32 b) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 4 && !found; i++) {
        O05SlotAt *p = (O05SlotAt *)((u8 *)D_800E54A4 + i * 12);
        if (p->s.a == a && p->s.b == b) {
            found = 1;
            p->s.a = -1;
            p->s.c = 2;
        }
    }
    return found;
}
