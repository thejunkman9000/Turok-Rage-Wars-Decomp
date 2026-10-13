/* EU: counterpart of func_00449B44 (player slot init): the per-slot byte tables at +0x602 and +0x644/+0x64A are initialised differently (descending loops,
   constant entries), the rest as in v1.1. */
#include "s1011_types.h"

typedef struct S11Big { u8 pad[0x18C4]; s32 unk18C4; } S11Big;
typedef struct S11E4680 { u8 pad[0x28]; u8 unk28; } S11E4680;
typedef struct S11Row { u8 pad[0x190]; } S11Row;

extern S11Game D_801462C8[];
extern u8 D_801462D5;
extern u8 D_801462E5;
extern S11Big D_80145088;
extern S11E4680 *D_800E4680;
extern S11Row D_80102B00[];
extern s32 D_80102AE0[];
extern s32 D_80103140[];

extern void func_00264B8C();
extern void *func_0044B388(S11Big *);
extern void func_0021836C(void *);
extern void func_00218E98(void *);
extern u8 func_0022F444(void *, s32);
extern void func_0021AF6C(void *);
extern void func_0044A17C(void *);
extern void func_004426E4(void *, void *, void *, void *, s32);
extern u8 D_auto_00450DD8[];
extern u8 D_auto_00450EB0[];
extern u8 D_auto_0045122C[];

#define PB(p, off) (*(u8 *)((u8 *)(p) + (off)))
#define PS(p, off) (*(s8 *)((u8 *)(p) + (off)))

void func_auto_0044A154(S11Obj *p, s32 arg1, s32 arg2) {
    s32 i;
    s32 flag;
    void *name;

    func_00264B8C();
    flag = 0;
    p->unk5D0 = 1;
    p->unk5E0 = arg1;
    if (p->unk1450 == 0) {
        p->hud = func_0044B388(&D_80145088);
        if (D_80145088.unk18C4 != 0) {
            p->unk1450 = 1;
        }
    } else {
        p->hud = 0;
    }
    func_0021836C((u8 *)p + 0x938);
    func_00218E98((u8 *)p + 0xCCC);
    for (i = 1; i < 0x16; i++) {
        PB(p, 0x602 + i * 2) = 0;
        PS(p, 0x603 + i * 2) = -1;
    }
    PB(p, 0x602) = 1;
    PB(p, 0x603) = 0;
    PB(p, 0x609) = 2;
    PB(p, 0x60A) = 1;
    PB(p, 0x60B) = 1;
    PB(p, 0x608) = 1;
    PB(p, 0x617) = 4;
    PB(p, 0x616) = 1;
    PB(p, 0x606) = 1;
    PB(p, 0x607) = 5;
    PB(p, 0x61E) = 1;
    PB(p, 0x61F) = 6;
    p->unk5E8 = 0;
    for (i = 0; i < 6; i++) {
        p->b644[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        p->b64A[i] = 0;
    }
    if (D_801462E5 != 0) {
        if (D_801462D5 == 1 && p->unk1450 == 0) {
            p->unk133C = ((func_0022F444(&D_80102B00[p->unk5D4], p->rec->b80) & 0xFF) >> 1) + 1;
        }
        if (D_801462D5 == 4 && p->unk1450 == 0 && D_800E4680 != 0) {
            p->unk133C = D_800E4680->unk28;
        }
        p->unk5EA = 1;
    } else {
        p->unk5EA = 3;
    }
    p->unk13C8 = 0;
    func_0021AF6C(p);
    p->unk670 = 0;
    p->unk674 = 0;
    p->unk86C = -1;
    p->unk870 = -1;
    for (i = 0; i < 8; i++) {
        p->rec->a2C[i] = 0;
        p->rec->a3C[i] = 0;
        p->rec->a0C[i] = 0;
        p->rec->a1C[i] = 0;
    }
    p->rec->h0 = 0;
    p->rec->h2 = 0;
    p->rec->h4 = 0;
    p->rec->h6 = 0;
    p->rec->hA = 0;
    p->rec->h8 = 0;
    p->rec->b8D = 0;
    p->rec->b8E = 0;
    p->rec->b8F = 0;
    p->rec->b90 = 0;
    p->unk638 = 0;
    p->unk63C = 1;
    p->unk640 = 0;
    p->unk868 = 1;
    func_0044A17C(p);
    if (D_801462C8->unk1D != 0) {
        p->unk13E8 = 0;
    }
    if (flag) {
        if (D_801462C8->unk1D != 0) {
            p->rec->b80 = 0;
            p->unk5E0 = 0;
            p->unk85C = 1;
            name = D_auto_00450EB0;
            if (D_801462C8->unk5FC == 0) {
                name = D_auto_00450DD8;
            }
        } else {
            name = D_auto_0045122C;
        }
        func_004426E4((u8 *)p->hud + 0x554, name, p, p->unk698, p->unk5D4);
    }
    D_80102AE0[p->unk5D4] = 0;
    D_80103140[p->unk5D4] = 0;
}
