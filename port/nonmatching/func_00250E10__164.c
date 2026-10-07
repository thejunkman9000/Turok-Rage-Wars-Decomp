#include "b12_types.h"

typedef struct B12P1 {
    /* 0x00 */ B12Node *nodes;
    /* 0x04 */ B12Node **stkx;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ u8 *pool2;
    /* 0x10 */ B12List l0;
    /* 0x24 */ B12List l1;
    /* 0x38 */ u8 pad38[8];
    /* 0x40 */ s32 t630[2];
    /* 0x48 */ u8 pad48[0xB94];
    /* 0xBDC */ s32 cnt;
    /* 0xBE0 */ u8 padBE0[0x20];
    /* 0xC00 */ OSMesgQueue q;
    /* 0xC18 */ OSMesg qbuf;
} B12P1;

typedef struct B12P2 {
    /* 0x000 */ s32 t628[2];
    /* 0x008 */ u8 pad8[8];
    /* 0x010 */ s32 f638;
    /* 0x014 */ u8 pad14[0xB4C];
    /* 0xB60 */ B12List lists3[3];
    /* 0xB9C */ s32 t11C4[2];
    /* 0xBA4 */ u8 padBA4[0x40];
    /* 0xBE4 */ s32 f120C;
    /* 0xBE8 */ u32 stamp;
} B12P2;

extern B12P1 D_80104560;
extern B12P2 D_80104598;
extern B12Node **D_80104564;
extern u8 D_80105140[];
extern s32 D_8010515C;
extern u32 D_800D0920;
extern s32 D_800D2B2C;
extern u8 D_801051A0[];
extern OSMesgQueue D_801047E0;
extern u8 D_801048F8[];
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
    func_002567C4(D_80105140);
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg((OSMesgQueue *)D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    D_800D0920 = 0x400;
    if (func_00265370() > 0x400000) {
        D_800D0920 *= 2;
    }
    D_80104560.nodes = (B12Node *)func_002558C0(D_801051A0, D_800D0920 * 0x28);
    D_80104560.stkx = (B12Node **)func_002558C0(D_801051A0, D_800D0920 * 4);
    D_80104560.pool2 = func_002558C0(D_801051A0, D_800D0920 * 0x2C);
    osCreateMesgQueue(&D_80104560.q, &D_80104560.qbuf, 1);
    D_80104560.t630[1] = 0;
    D_80104560.t630[0] = 0;
    func_00255C40(&D_80104560.l0, 0x18, 0x1C);
    func_00255C40(&D_80104560.l1, 0x20, 0x24);
    D_80104560.cnt = 0;
    for (i = 0; i < D_800D0920; i++) {
        n = (B12Node *)((u8 *)D_80104560.nodes + i * 0x28);
        n->flags = 0;
        D_80104564[i] = n;
        D_80104560.cnt++;
    }
    D_80104598.t628[1] = 1;
    D_80104598.t628[0] = 1;
    D_80104598.f638 = -1;
    D_80104598.t11C4[0] = 0;
    D_80104598.t11C4[1] = 0;
    *(s32 *)((u8 *)&D_80104598 - 0x30) = 0;
    D_80104598.f120C = 1;
    D_80104598.stamp = 0;
    func_00255C40(&D_80104598.lists3[0], 0x28, 0x24);
    func_00255C40(&D_80104598.lists3[1], 0x28, 0x24);
    func_00255C40(&D_80104598.lists3[2], 0x28, 0x24);
    for (i = 0; i < D_800D0920; i++) {
        n = (B12Node *)(*(u8 **)((u8 *)&D_80104598 - 0x2C) + i * 0x2C);
        n->unk10 = 0;
        func_00255CB4((B12List *)((u8 *)&D_80104598 - 0x2C + 0xB8C), n);
    }
    func_00255280(D_800D0920);
    osCreateMesgQueue(&D_801047E0, (OSMesg *)((u8 *)&D_801047E0 + 0x18), 0x40);
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg((OSMesgQueue *)D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
    memset(D_801048F8, id, 0x800);
    osCreateThread((OSThread *)(D_801048F8 - 0x348), id, func_00252450, 0, D_801048F8 + 0x800, D_800D2B2C);
    osStartThread((OSThread *)(D_801048F8 - 0x348));
}
