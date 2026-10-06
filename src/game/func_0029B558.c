
#include "b22_types.h"
extern SndAux *D_8014D0B0;
s32 func_0029A958(void);
void func_0029A5D4(s32, s32, s32, s32, s32);
void func_0029AE80(SndMsg *);
void func_0029B324(SndMsg *);
void func_0029B558(SndMsg *m)
{
    if (D_8014D0B0->fn0 != 0) {
        if (D_8014D0B0->fn0(m) == 1) {
            return;
        }
    }
    switch (m->b) {
    case 0: {
        u32 v = ((u32)(u16)m->type << 16) | (u16)m->a;
        s32 id = func_0029A958();
        func_0029A5D4(id, 0x11, v, m->e, m->c);
        break;
    }
    case 1:
        if (m->type == 4) {
            m->type = 3;
            func_0029AE80(m);
        }
        break;
    case 2:
    case 3:
    case 4:
        if (m->type == 4) {
            m->type = 3;
            func_0029B324(m);
        }
        break;
    }
}
