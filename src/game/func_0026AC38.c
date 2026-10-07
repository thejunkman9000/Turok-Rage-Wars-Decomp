#include "b15_types.h"
#include "p4_types.h"

void func_00296FF8();
void func_0026925C();
extern u8 D_44BDD0[];
extern s32 D_800D15D4;
extern P4Gfx *D_80110634;

void func_0026AC38(void) {
    P4Gfx *g;
    P4Gfx *h;

    func_00296FF8();
    h = D_80110634++;
    h->words.w0 = 0xFD900000;
    h->words.w1 = (u32)D_44BDD0;
    g = D_80110634++;
    g->words.w0 = 0xF5900000;
    g->words.w1 = 0x07014050;
    g = D_80110634++;
    g->words.w0 = 0xE6000000;
    g->words.w1 = 0;
    g = D_80110634++;
    g->words.w0 = 0xF3000000;
    g->words.w1 = 0x070FF400;
    g = D_80110634++;
    g->words.w0 = 0xE7000000;
    g->words.w1 = 0;
    g = D_80110634++;
    g->words.w0 = 0xF5800400;
    g->words.w1 = 0x14050;
    g = D_80110634++;
    g->words.w0 = 0xF2000000;
    g->words.w1 = 0x7C07C;
    g = D_80110634++;
    g->words.w0 = 0xD7000002;
    g->words.w1 = 0x08000800;
    g = D_80110634++;
    g->words.w0 = 0xE3001001;
    g->words.w1 = 0;
    g = D_80110634++;
    g->words.w0 = 0xD9FFFFFF;
    g->words.w1 = D_800D15D4 | 0x260404;
    func_0026925C(0x1D);
}
