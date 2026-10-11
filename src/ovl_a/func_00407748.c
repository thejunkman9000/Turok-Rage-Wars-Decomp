#include "common.h"

/* Controller Pak note check / load state machine (goto transcription of the ROM CFG).
   Types: K7Mem is an allocation handle (first word = buffer address); reading m->addr is a struct-member load (see func_004058B0).
   HACKS: the two empty asm statements  __asm__("" : : "r"(s1)) / __asm__("" : : "r"(s3))  only add one reference each to the pseudos
   (call result R and flag X): global-alloc priority is refs*floor_log2(refs)/live_length, and the ROM allocates R (s1) and X (s3) before
   the flag/size variables; without the extra references every callee-saved pseudo is shifted by one register (63 operand diffs).
   k7_chk is a static inline helper on purpose: parameters of an inlined function make gcc re-materialise `addiu a0,sp,N` per use. */

typedef struct K7Sub { u8 pad0[4]; s8 b4; } K7Sub;
typedef struct K7Obj {
    s16 state;
    u8 pad2[0x12];
    s32 f14;
    u8 pad18[4];
    s32 f1C;
    K7Sub *f20;
} K7Obj;
typedef struct K7Blk { s32 w[6]; } K7Blk;
typedef struct K7Mem { s32 addr; } K7Mem;

extern s32 D_8011FECC;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_80153784;
extern s32 D_8015376C;
extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_8015378C;
extern s32 D_80153754;
extern K7Blk D_80153738;
extern K7Blk D_80153718;
extern s32 D_800D770C;
extern s32 D_800D7708;
extern s32 D_800D7700;
extern s32 D_800D7704;
extern s32 D_800D7784;
extern u8 *D_800D77FC;
extern s32 D_800E28B0;
extern s32 D_800E28B4;
extern s32 D_800E28B8;
extern s32 D_800E28BC;
extern u8 D_800E0D90[];
extern u8 D_8014561C[];
extern u8 D_0044F484[];
extern u8 D_0044F2F8[];
extern u8 D_0044F4A8[];
extern u8 D_0044F460[];
extern u8 D_0044F2D4[];
extern u8 D_0044FB68[];
extern u8 D_0044F100[];
extern u8 D_0044F0B8[];

s32 func_00406178();
s32 func_0040458C();
s32 func_00404F58();
s32 func_004057F8();
s32 func_004057BC();
void func_00405F48();
s32 func_002A1238();
s32 func_002A137C();
void func_002A125C();
void func_002538A8();
void func_002537D8();
K7Mem *func_002533DC();
void *memset();
void func_004426E4();

static inline s32 k7_chk(u8 *gc, u8 *cc) { if (func_002A1238(gc) == 4 && func_002A1238(cc) == 2 && func_002A137C(gc, D_800D770C) == 0 && func_002A137C(cc, D_800D7708) == 0) return 1; return 0; }
s32 func_00407748(s32 *arg0, K7Obj *arg1) {
    u8 sp20[8];
    u8 sp28[8];
    u8 sp30[8];
    u8 sp38[16];
    s32 sp48;
    s32 sp4C;
    s32 s0, s1, s2, s3, s4, s5, hs, s7, v1, v0;
    K7Mem *m;
    u8 *d;
    s32 i, ch;
    u8 *a1p;

    s2 = 0;
    s5 = *arg0 - 3;
    s7 = D_8011FECC + 0x610;
    if (D_8015375C != 0) {
        s4 = D_800E28C8;
    } else {
        s4 = arg1->f20->b4;
    }
    if (func_00406178(arg1, s4, 0) != 0) {
        D_80153784 = 1;
        return 1;
    }
    if (D_8015376C == 0) goto L00407BBC;
    s1 = func_0040458C(s4, s5, &sp48, sp38, sp20, &sp4C, sp28, sp30);
    __asm__("" : : "r"(s1));
    if (s1 == 0 && sp48 == 0) {
        arg1->state = 0x14;
        func_00405F48(arg1);
        return 0;
    }
    v1 = k7_chk(sp30, sp28);
    if (v1 != 0) {
        s3 = func_002A137C(sp38, D_800D7700) == 0;
        s0 = func_002A137C(sp38, D_800D7704) == 0;
    } else {
        s3 = 0;
        s0 = 0;
    }
    if (s1 != 0) goto L00407EE8;
    if (sp48 == 0) goto L00407EE8;
    __asm__("" : : "r"(s3));
    if (s3 == 0) goto L004079A0;
    if (func_00404F58(s4, s5, &D_80153738, 0x18) != 0) goto L0040799B;
    if (func_004057F8(&D_80153738, 0x14, 4) != D_80153738.w[5]) goto L0040799B;
    s3 = 0;
    D_80153718 = D_80153738;
    D_8015378C = s5;
    func_004426E4(D_8014561C, D_0044F484, arg1->f1C, arg1->f20, arg1->f14);
    return 1;
L0040799B:
    s3 = 0;
L0040799C:
    s2 = 1;
L004079A0:
    if (s0 == 0) goto L00407AD0;
    if (s2 != 0) goto L00407AD0;
    s0 = sp4C;
    if (D_800E28B4 != 0) {
        func_002538A8(0);
        func_002537D8(0, D_800E28B4);
    }
    if (s0 == 0) {
        s0 = D_8011FECC + 0x610;
    } else {
        s0 = s0 << 8;
    }
    m = func_002533DC(0, s0, 0x33, D_800E0D90);
    D_800E28B4 = (s32)m;
    D_800E28BC = m->addr;
    memset((void *)D_800E28BC, 0, s0);
    if (func_00404F58(s4, s5, D_800E28BC, sp4C << 8) != 0) goto L00407ACC;
    hs = *(s32 *)D_800E28BC;
    if (hs != s7) goto L00407ACC;
    if (func_004057F8(D_800E28BC, hs - 4, 0xB) != *(s32 *)(*(s32 *)D_800E28BC + D_800E28BC - 4)) goto L00407ACC;
    s0 = 0;
    if (D_8011FECC != *(s32 *)(D_800E28BC + 4)) { s2 = 1; goto L00407AD0; }
    D_8015378C = s5;
    func_004426E4(D_8014561C, D_0044F2F8, arg1->f1C, arg1->f20, arg1->f14);
    return 1;
L00407ACC:
    s0 = 0;
    s2 = 1;
L00407AD0:
    if (s3 != 0) goto L00407EE8;
    if (s0 != 0) goto L00407EE8;
    ch = 0;
    d = D_800D77FC;
    D_8015378C = s5;
    if (func_004057BC(sp38, 0x10) != 0) {
        func_002A125C(sp38, D_800D7784);
    }
    i = 1;
    v1 = 0;
    do {
        if (i != 0) ch = sp38[v1];
        if (ch == 0) { i = 0; ch = 0x20; }
        *d = ch;
        v1 += 1;
        d += 1;
    } while (v1 < 0x10);
    i = 1;
    d += i;
    v1 = 0;
    do {
        if (i != 0) ch = sp20[v1];
        if (ch == 0) { i = 0; ch = 0x20; }
        *d = ch;
        v1 += 1;
        d += 1;
    } while (v1 < 4);
    func_004426E4(D_8014561C, D_0044F4A8, arg1->f1C, arg1->f20, arg1->f14);
    return 1;
L00407BBC:
    if (D_80153760 == 0) goto L00407EE8;
    if (D_8015377C == 0) goto L00407CDC;
    if (s2 != 0) goto L00407CDC;
    if (func_0040458C(s4, s5, &sp48, sp38, sp20, &sp4C, sp28, sp30) != 0) goto L00407EE8;
    if (sp48 == 0) goto L00407EE8;
    if (func_002A137C(sp38, D_800D7700) != 0) goto L00407EE8;
    if (func_00404F58(s4, s5, &D_80153738, 0x18) != 0) goto L00407CD0;
    if (func_004057F8(&D_80153738, 0x14, 4) != D_80153738.w[5]) goto L00407CD0;
    D_80153718 = D_80153738;
    func_004426E4(D_8014561C, D_0044F460, arg1->f1C, arg1->f20, 0);
    return 1;
L00407CD0:
    s2 = 1;
    goto L00407EE8;
L00407CDC:
    if (D_80153760 == 0) goto L00407EE8;
    v0 = D_8015377C;
    if (v0 != 0) goto L00407EE8;
    if (s2 != 0) goto L00407EF8;
    if (func_0040458C(s4, s5, &sp48, sp38, sp20, &sp4C, sp28, sp30) != 0) goto L00407EE8;
    if (sp48 == 0) goto L00407EE8;
    if (func_002A137C(sp38, D_800D7704) != 0) goto L00407EE8;
    s0 = sp4C;
    if (D_800E28B4 != 0) {
        func_002538A8(0);
        func_002537D8(0, D_800E28B4);
    }
    if (s0 == 0) {
        s0 = D_8011FECC + 0x610;
    } else {
        s0 = s0 << 8;
    }
    m = func_002533DC(0, s0, 0x33, D_800E0D90);
    D_800E28B4 = (s32)m;
    D_800E28BC = m->addr;
    memset((void *)D_800E28BC, 0, s0);
    if (func_00404F58(s4, s5, D_800E28BC, sp4C << 8) != 0) goto L00407E70;
    hs = *(s32 *)D_800E28BC;
    if (hs != s7) goto L00407E70;
    if (func_004057F8(D_800E28BC, hs - 4, 0xB) != *(s32 *)(*(s32 *)D_800E28BC + D_800E28BC - 4)) goto L00407E70;
    if (D_8011FECC != *(s32 *)(D_800E28BC + 4)) goto L00407E70;
    func_004426E4(D_8014561C, D_0044F2D4, arg1->f1C, arg1->f20, 0);
    return 1;
L00407E70:
    s2 = 1;
    if (D_800E28B0 != 0 || D_800E28B4 != 0) {
        func_002538A8(0);
    }
    if (D_800E28B0 != 0) {
        func_002537D8(0, D_800E28B0);
    }
    if (D_800E28B4 != 0) {
        func_002537D8(0, D_800E28B4);
    }
    D_800E28B0 = 0;
    D_800E28B4 = 0;
    D_800E28B8 = 0;
    D_800E28BC = 0;
L00407EE8:
    if (s2 == 0) return 0;
    v0 = D_8015377C;
L00407EF8:
    a1p = D_0044F100;
    if (v0 != 0) a1p = D_0044F0B8;
    D_80153754 = s5;
    func_004426E4(D_8014561C, D_0044FB68, arg1->f1C, arg1->f20, a1p);
    return 1;
}
