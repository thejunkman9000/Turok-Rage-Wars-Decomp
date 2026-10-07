
#include "b12_types.h"

extern B12Mgr D_80103F70;
extern s32 D_8010515C;
extern u32 D_800D0920;
extern s32 D_800D2B2C;
extern u8 D_801051A0[];
void func_002567C4(void *lock);
u32 func_00265370(void);
u8 *func_002558C0(void *heap, u32 size);
void func_00255C40(B12List *l, s32 prevOff, s32 nextOff);
void func_00255CB4(B12List *l, void *n);
void func_00255280(u32 n);
void func_00252450(void *arg);

void func_00250E10(s32 unused, s32 id) {
    u32 mask;
    u32 m2;
    u32 i;
    B12Node *n;
    s32 *t;
    func_002567C4(&D_80103F70.q11D0);
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    D_800D0920 = 0x400;
    if (func_00265370() > 0x400000) {
        D_800D0920 *= 2;
    }
    D_80103F70.nodes = (B12Node *)func_002558C0(D_801051A0, D_800D0920 * 0x28);
    D_80103F70.stk = (B12Node **)func_002558C0(D_801051A0, D_800D0920 * 4);
    D_80103F70.pool2 = func_002558C0(D_801051A0, D_800D0920 * 0x2C);
    osCreateMesgQueue(&D_80103F70.q11F0, &D_80103F70.buf11F0, 1);
    D_80103F70.tbl630[1] = 0;
    D_80103F70.tbl630[0] = 0;
    func_00255C40(&D_80103F70.lists[0], 0x18, 0x1C);
    func_00255C40(&D_80103F70.lists[1], 0x20, 0x24);
    D_80103F70.cnt = 0;
    for (i = 0; i < D_800D0920; i++) {
        n = (B12Node *)((u8 *)D_80103F70.nodes + i * 0x28);
        n->flags = 0;
        D_80103F70.stk[i] = n;
        D_80103F70.cnt++;
    }
    t = D_80103F70.tbl628;
    t[1] = 1;
    t[0] = 1;
    D_80103F70.f638 = -1;
    D_80103F70.tbl11C4[0] = 0;
    D_80103F70.tbl11C4[1] = 0;
    D_80103F70.cur = 0;
    D_80103F70.f120C = 1;
    D_80103F70.stamp = 0;
    func_00255C40(&D_80103F70.lists3[0], 0x28, 0x24);
    func_00255C40(&D_80103F70.lists3[1], 0x28, 0x24);
    func_00255C40(&D_80103F70.lists3[2], 0x28, 0x24);
    for (i = 0; i < D_800D0920; i++) {
        n = (B12Node *)(D_80103F70.pool2 + i * 0x2C);
        n->unk10 = 0;
        func_00255CB4(&D_80103F70.lists3[0], n);
    }
    func_00255280(D_800D0920);
    osCreateMesgQueue(&D_80103F70.q870, D_80103F70.buf870, 0x40);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80103F70.q11D0, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    memset(D_80103F70.stack, id, 0x800);
    osCreateThread(&D_80103F70.thread, id, func_00252450, 0, D_80103F70.stack + 0x800, D_800D2B2C);
    osStartThread(&D_80103F70.thread);
}


