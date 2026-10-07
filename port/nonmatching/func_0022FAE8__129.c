#include "m02_gen.h"
typedef struct M2WSlot { s8 a; s8 b; } M2WSlot;
s32 func_0022EAFC(M2Own *p, s32 w);
void func_0025DF54(s32 id);
#define WTAB(p) ((M2WSlot *)((u8 *)(p) + 0x602))
s32 func_0022FAE8(M2Own *p) {
    s32 prio;
    s32 lim;
    s32 k;
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
        if (w < 0x16) {
            if (func_0022EAFC(p, w) != 0) {
                return w;
            }
        }
        prio++;
    }
    lim = *(s8 *)((u8 *)p + (p->unk62E << 1) + 0x603);
    k = 1;
    while (k < lim) {
        for (w = 0; w < 0x16; w++) {
            if (k == WTAB(p)[w].b) {
                break;
            }
        }
        if (w < 0x16) {
            if (func_0022EAFC(p, w) != 0) {
                return w;
            }
        }
        k++;
    }
    func_0025DF54(0xD4D);
    return p->unk62E;
}
