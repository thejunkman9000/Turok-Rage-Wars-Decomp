#include "o05_types.h"
extern O05Lobby *D_800E54A4;
s32 func_004353C0(void);
s32 func_004354A4(s32 a, s32 b) {
    s32 r = 0;
    s32 i = func_004353C0();
    s32 c;
    O05SlotAt *p;
    if (i >= 0) {
        r = 1;
        p = (O05SlotAt *)((u8 *)D_800E54A4 + i * 12);
        c = r;
        p->s.a = a;
        p->s.b = b;
        p->s.c = c;
    }
    return r;
}
