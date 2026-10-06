#include "b16_types.h"

extern DlCmd *D_80110634;
extern u8 D_E0470[];
extern u8 D_DE0A0[];
extern u8 D_800D0F10[];
extern u8 D_800D0F40[];

void func_0026E390(void) {
    DlCmd *g;

    g = D_80110634++;
    g->w0 = 0xE9000000;
    g->w1 = 0;
    g = D_80110634++;
    g->w0 = 0xE1000000;
    g->w1 = (u32)D_E0470;
    g = D_80110634++;
    g->w0 = 0xDD0007FF;
    g->w1 = (u32)D_DE0A0;
    g = D_80110634++;
    g->w0 = 0xDE000000;
    g->w1 = (u32)D_800D0F10;
    g = D_80110634++;
    g->w0 = 0xDE000000;
    g->w1 = (u32)D_800D0F40;
}
