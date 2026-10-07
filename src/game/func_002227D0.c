#include "b05_types.h"

typedef struct B05StEnt {
    void (*fn)();
    u8 pad4[8];
    s32 unkC;
    s32 unk10;
    u8 pad14[4];
} B05StEnt;

typedef struct B05P1 {
    u8 pad0[0x100];
    u32 flags;
    u8 pad104[0x54C];
    s16 state;
    s16 prevState;
    u8 pad654[4];
    s32 unk658;
    u8 pad65C[4];
    s32 unk660;
    s32 unk664;
    u8 pad668[0x204];
    s32 unk86C;
    u8 pad870[0xB44];
    B05StEnt *states;
} B05P1;

extern u8 D_801462E5;
s32 func_0022C450();

s32 func_002227D0(B05P1 *p, s32 arg, s32 st) {
    u16 prev;
    s32 old;

    if (D_801462E5 == 0 || func_0022C450() == 0 || st == 0x15 || st == 0x13 || st == 0x14) {
        prev = p->state;
        old = p->unk664;
        p->state = st;
        p->prevState = prev;
        p->unk660 = old;
        p->flags &= 0xFF7FFFFF;
        if (p->states[st].fn != NULL) {
            p->states[st].fn(p, arg);
        }
        p->unk664 = p->states[p->state].unkC;
        if (p->states[p->state].unk10 != 0) {
            p->unk86C = p->states[p->state].unk10;
        }
        if (p->state == st) {
            p->unk658 = 0;
            return 1;
        }
    }
    return 0;
}
