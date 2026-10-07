#include "b12_types.h"
#include "libaudio.h"

extern s32 D_800D2B34;
void func_00255C40(B12List *l, s32 prevOff, s32 nextOff);
void func_00255CB4(B12List *l, B12QNode *n);
void func_0025651C(void *arg);

void func_00256220(B12Ctx *c, s32 id) {
    s32 i;
    s32 off;
    osCreateMesgQueue(&c->q, c->qbuf, 0x200);
    osCreateMesgQueue(&c->q2, c->q2buf, 1);
    osSetEventMesg(8, &c->q2, (OSMesg)0x7D1);
    func_00255C40(&c->freeList, 0x18, 0x1C);
    func_00255C40(&c->usedList, 0x18, 0x1C);
    for (i = 0, off = 0xE68; i < 0x210; i++, off += 0x20) {
        B12QNode *n = (B12QNode *)((u8 *)c + off);
        n->state = 0;
        func_00255CB4(&c->freeList, n);
    }
    memset(c->stack, id, 0x400);
    osCreateThread(&c->thread, id, func_0025651C, c, c->nodes, D_800D2B34);
    osStartThread(&c->thread);
}
