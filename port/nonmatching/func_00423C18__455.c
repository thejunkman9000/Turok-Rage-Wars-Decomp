#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x91 - 0x79]; u8 unk91; u8 pad92[0x96 - 0x92]; } O04Ent96y;
typedef struct { u8 pad0[0xD]; s8 unkD; s8 unkE; u8 padF[0x190 - 0xF]; } O04Row190y;
typedef struct { u8 pad0[0x16]; u16 unk16; u8 pad18[2]; u16 unk1A; } O04Hdl2;
typedef struct Q2S4600 { s32 unk0; s32 unk4; O04Hdr16 *unk8; s32 unkC; s32 pad10; s32 unk14; s32 unk18; } Q2S4600;
extern Q2S4600 *D_800E4600;
extern O04GFlags D_801468A0[];
extern O04Cfg D_801462C8[];
extern O04Row190y D_80102B00[];
extern u8 D_80102B83[];
extern u8 D_80102B7D[];
void func_0042B1A0(s32 a);
void func_0042EB80(s32 a, s32 b);
void func_002A33F8(f32 f);
void func_0022EF20(void *p);
void *memset(void *p, s32 v, u32 n);
void *func_00252FFC(s32 a);
void func_002A3358(void);
s32 func_00265670(void *p, s32 a);
O04Hdl2 *func_0040ECB0(s32 a, s32 b);
void func_0041B190(s32 a);
void func_0040E9D0(void *p, s32 a);
void func_0040E958(void *p, s32 a);
void func_0041DBA0(s32 *p);
s32 func_00264634(s32 a);
s32 func_0041A300(s32 a, s32 b);
void func_0041A508(s32 a);
void *func_00419ED4(s32 a, s32 b);
s32 func_0029A9F4(void);
void func_0040C4A8(s32 a);
s32 func_00423C18(s32 a) {
    s32 i;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    O04Hdl2 *h;
    O04Hdl2 *t;
    O04Hdl2 *h2;
    O04GFlags *g;
    O04Ent96y *e;
    O04Ent96y *ents;
    s32 v;
    func_0042B1A0(-1);
    func_0042EB80(0, 0);
    g = D_801468A0;
    g->unkA8 = 0;
    func_002A33F8(0.0f);
    ((u8 *)g)[-0x5BB] = 1;
    ents = (O04Ent96y *)((u8 *)g - 0x508);
    for (i = 0; i < 8; i++) {
        e = &ents[i];
        e->unk78 = 0;
        e->unk91 = 0;
    }
    s3 = 1;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].unkD >= 0 && D_80102B00[i].unkE == s3) {
            func_0022EF20(&D_80102B00[i]);
            D_80102B00[i].unkD = -1;
            D_80102B00[i].unkE = 0;
        }
        memset((u8 *)&D_80102B00[i] + 0x83, 0, 5);
    }
    D_800E4600 = func_00252FFC(0x1C);
    func_002A3358();
    s3 = 0;
    s2 = 0;
    s1 = 0;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].unkD >= 0) {
            s0 = 0;
            if (s3 != 0 || func_00265670(D_80102B7D + i * 0x190, 0) != 0) {
                s0 = 1;
            }
            s3 = s0;
            s0 = 0;
            if (s2 != 0 || func_00265670(D_80102B7D + i * 0x190, 1) != 0) {
                s0 = 1;
            }
            s2 = s0;
            s0 = 0;
            if (s1 != 0 || func_00265670(D_80102B7D + i * 0x190, 2) != 0) {
                s0 = 1;
            }
            s1 = s0;
        }
    }
    if (*(u32 *)D_801462C8 & 0x20000000) {
        s1 = 1;
        s2 = s1;
    }
    s0 = 0;
    if (s1 == 1) {
        s0 = 3;
    } else if (s2 == 1) {
        s0 = 2;
    }
    h = func_0040ECB0(a, 0x42);
    switch (s0) {
    case 2:
        func_0041B190(0x48);
        t = func_0040ECB0(a, 0x4A);
        func_0040E9D0(t, 1);
        func_0040E958(t, 0);
        h->unk16 = 0x33;
        v = 0x78;
        break;
    case 3:
        func_0041B190(0x4A);
        func_0041B190(0x48);
        h->unk16 = 0x2A;
        v = 0x88;
        break;
    default:
        t = func_0040ECB0(a, 0x48);
        func_0040E9D0(t, 1);
        func_0040E958(t, 0);
        t = func_0040ECB0(a, 0x4A);
        func_0040E9D0(t, 1);
        func_0040E958(t, 0);
        h->unk16 = 0x3C;
        v = 0x68;
        break;
    }
    h->unk1A = v;
    i = -1;
    func_0041DBA0(&i);
    if (i < 0) {
        func_0040E9D0(func_0040ECB0(a, 0x4C), 1);
    }
    s0 = func_00264634(0);
    if (s0 != 1 || func_00264634(1) != s0) {
        func_0040E9D0(func_0040ECB0(a, 0x49), 1);
    }
    D_800E4600->unk0 = func_0041A300(0x42, 0x24);
    func_0041A508(D_800E4600->unk0);
    func_0041B190(0x45);
    func_0041B190(0x46);
    func_0041B190(0x49);
    func_0041B190(0x4B);
    func_0041B190(0x4C);
    func_0041B190(0x47);
    h2 = func_0040ECB0(a, 0x43);
    D_800E4600->unk8 = (O04Hdr16 *)h2;
    ((u8 *)h2)[0x10] = 0xF;
    D_800E4600->unk4 = (s32)func_00419ED4(0x44, 0x6E);
    if (func_0029A9F4() == 2) {
        D_800E4600->unkC = 9;
    } else {
        D_800E4600->unkC = 1;
    }
    D_800E4600->unk14 = 3;
    func_0040C4A8(0);
    return 0;
}
