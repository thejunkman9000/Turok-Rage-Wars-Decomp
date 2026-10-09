#include "m02_gen.h"
typedef struct M2WSlot { s8 a; s8 b; } M2WSlot;
s32 func_0022EAFC(M2Own *p, s32 w);
void func_0025DF54(s32 id);
#define WTAB(p) ((M2WSlot *)((u8 *)(p) + 0x602))
s32 func_0022FAE8(M2Own *p) {
    register s32 prio asm("$18");
    register s32 lim asm("$18");
    register s32 k asm("$17");
    s32 w;
    s32 w2;
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
        for (w2 = 0; w2 < 0x16; w2++) {
            if (k == WTAB(p)[w2].b) {
                break;
            }
        }
        if (w2 < 0x16) {
            if (func_0022EAFC(p, w2) != 0) {
                return w2;
            }
        }
        k++;
    }
    func_0025DF54(0xD4D);
    return p->unk62E;
}
