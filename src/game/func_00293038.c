#include "b21_types.h"

extern u32 D_800D2978;
extern u32 D_800E28A0;
extern s32 D_800D2980;
extern s32 D_800D297C;
extern s32 D_801536F4;
extern s32 D_801536F0;
extern s32 D_801536BC;
extern s32 D_801536C0;

void func_00293038(B21Game *g) {
    u32 idx;
    B21Slot *s;
    B21Slot *t;
    D_800D2978++;
    idx = D_800D2978 % D_800E28A0;
    D_800D2980++;
    D_800D297C ^= 1;
    s = g->curSlot = &g->slots[idx];
    s->unk114 = D_800D297C ? D_801536F4 : D_801536F0;
    t = g->curSlot;
    t->unk118 = D_800D297C ? D_801536BC : D_801536C0;
}
