#include "b22_types.h"
void func_0029BB24(s16, s32, s32);
void func_0029BAD8(s16, s16, s32);
#define BTN(mask, id)     if ((cur & (mask)) && !(prev & (mask))) {         func_0029BAD8(p->ch, id, 1);     } else if ((prev & (mask)) && !(cur & (mask))) {         func_0029BAD8(p->ch, id, 0);     } else
void func_0029B650(B22Pad *p)
{
    s32 cur, prev;
    cur = p->cur;
    prev = p->prev;
    func_0029BB24(p->ch, p->unkC4, p->unkC5);
    if (cur != prev) {
        BTN(0x1000, 13)
        BTN(0x8000, 11)
        BTN(0x4000, 12)
        BTN(0x20, 9)
        BTN(0x10, 8)
        BTN(0x2000, 10)
        BTN(0x800, 4)
        BTN(0x200, 6)
        BTN(0x100, 7)
        BTN(0x400, 5)
        BTN(0x8, 0)
        BTN(0x2, 2)
        BTN(0x1, 3)
        BTN(0x4, 1)
        {
        }
    }
}

