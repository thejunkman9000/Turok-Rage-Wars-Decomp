#include "b24_types.h"

extern DlCmd *D_80110634;
s32 func_0026925C(s32);
s32 func_00268CE0(s32);

void func_002AB9E4(void) {
    DlCmd *g;
    g = D_80110634++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_80110634++;
    g->w0 = 0xE3000A01;
    g->w1 = 0;
    func_0026925C(0x15);
    func_00268CE0(0x19);
}
