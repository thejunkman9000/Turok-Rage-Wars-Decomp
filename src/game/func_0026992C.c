#include "b15_types.h"
#include "p4_types.h"

void func_00296FF8();
extern u8 D_800D14B0[];
extern u8 D_800D1268[];
extern u8 D_800D12F0[];
extern s32 D_800D15B0;
extern s32 D_800D15B4;
extern P4Gfx *D_80110634;

void func_0026992C(s32 a0, s32 a1, u32 color) {
    P4Gfx *g;
    P4Gfx *h;

    h = D_80110634++;
    h->words.w0 = 0xFD900000;
    h->words.w1 = (u32)D_800D14B0;
    g = D_80110634++;
    g->words.w0 = 0xF5900000;
    g->words.w1 = 0x07080200;
    g = D_80110634++;
    g->words.w0 = 0xE6000000;
    g->words.w1 = 0;
    g = D_80110634++;
    g->words.w0 = 0xF3000000;
    g->words.w1 = 0x0707F400;
    g = D_80110634++;
    g->words.w0 = 0xE7000000;
    g->words.w1 = 0;
    g = D_80110634++;
    g->words.w0 = 0xF5880400;
    g->words.w1 = 0x80200;
    g = D_80110634++;
    g->words.w0 = 0xF2000000;
    g->words.w1 = 0x3C03C;
    g = D_80110634++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = color | 0xFFFFFF00;
    g = D_80110634++;
    g->words.w0 = 0xDA380003;
    g->words.w1 = a0;
    g = D_80110634++;
    g->words.w0 = 0xDE000000;
    g->words.w1 = (u32)(a1 ? D_800D12F0 : D_800D1268);
    D_800D15B4 = -1;
    D_800D15B0 = -1;
    func_00296FF8();
}
