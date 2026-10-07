#include "m02_types.h"
typedef struct M2WSlot { s8 a; s8 b; } M2WSlot;
s32 func_0022EAFC(Plr *p, s32 w);
#define WTAB(p) ((M2WSlot *)((u8 *)(p) + 0x602))
s32 func_0022F95C(Plr *p) {
    s32 prio;
    s32 w;
    prio = *(s8 *)((u8 *)p + (p->unk62E << 1) + 0x603);
    if (prio < 0) {
        prio = 0;
    }
    if (prio >= 8) {
        prio = 0;
    }
    prio = prio + 1;
    while (prio < 8) {
        for (w = 0; w < 0x16; w++) {
            if (prio == WTAB(p)[w].b) {
                break;
            }
        }
        if (w < 0x16 && func_0022EAFC(p, w) != 0 && (w != 6 || p->unk5F4[0] >= 0xB)) {
            if (B6F(p, s32, 0x1450) == 0 || w < 0x12) {
                return w;
            }
        }
        prio++;
    }
    prio = *(s8 *)((u8 *)p + (p->unk62E << 1) + 0x603);
    if (prio < 0) {
        prio = 0;
    }
    if (prio >= 8) {
        prio = 0;
    }
    prio = prio - 1;
    while (prio > 0) {
        for (w = 0; w < 0x16; w++) {
            if (prio == WTAB(p)[w].b) {
                break;
            }
        }
        if (w < 0x16 && func_0022EAFC(p, w) != 0) {
            if (w != 6 || p->unk5F4[0] >= 0xB) {
                return w;
            }
        }
        prio--;
    }
    return 0;
}
