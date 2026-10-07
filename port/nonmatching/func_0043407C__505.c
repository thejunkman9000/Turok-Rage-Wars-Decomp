#include "q04_types.h"
extern u8 *D_800E54A4;
extern char *D_800D727C;
extern char *D_800D7784;
s32 func_0040458C(s32 a, s32 i, s32 *p50, char *name, u8 *p38, s32 *p54, s32 *p40, s32 *p48);
s32 func_00405160(s32 a, s32 *out);
s32 func_004057BC(char *s, s32 n);
s32 func_004057EC(s32 a);
void *func_0040ECB0(s32 w, s32 id);
s32 func_00435600(void);
void func_00432488(s32 a, s32 b);
void func_0043442C(s32 a, s32 b);
void func_002A125C(char *dst, char *src);
s32 func_002A1C08(char *buf, char *fmt, ...);
void func_0043407C(s32 idx) {
    char name[24];
    u8 sp38;
    s32 sp40[2];
    s32 sp48[2];
    s32 sp50;
    s32 sp54;
    s32 i, ok, n, so, boff, r;
    ok = 0;
    i = 0;
    so = idx * 0xB68 + 0x58;
    n = 1;
    boff = 0x658;
    for (;;) {
        r = func_0040458C(idx, i, &sp50, name, &sp38, &sp54, sp40, sp48);
        if (r != 0) {
            ok = 1;
            goto blk9;
        }
        if (sp50 == 1) {
            if (func_004057BC(name, 0x10) == sp50) func_002A125C(name, D_800D7784);
            func_002A125C((char *)(D_800E54A4 + so + boff + 0x28), name);
            func_002A1C08((char *)(D_800E54A4 + so + boff + 0x3C), "%d", sp54);
            if (sp38 != 0) {
                func_002A1C08((char *)(D_800E54A4 + so + boff), "%d.%s.%s", n, (char *)(D_800E54A4 + so + boff + 0x28), &sp38);
                n++;
                goto next;
            }
            goto blk10;
        }
blk9:
        func_002A125C((char *)(D_800E54A4 + so + boff + 0x28), D_800D727C);
        func_002A1C08((char *)(D_800E54A4 + so + boff + 0x3C), "%d", 0);
blk10:
        func_002A1C08((char *)(D_800E54A4 + so + boff), "%d.%s", n, (char *)(D_800E54A4 + so + boff + 0x28));
        n++;
next:
        i++;
        boff += 0x46;
        if (i < 16 && ok == 0) continue;
        break;
    }
    if (ok == 0) {
        void *w;
        so = idx * 0xB68;
        w = func_0040ECB0(*(s32 *)(D_800E54A4 + so + 0x64), 0x2D8);
        if (func_00405160(idx, &sp54) != 0) {
            ok = 1;
        } else {
            void *w2;
            s32 base = so + 0x58;
            func_002A1C08((char *)(D_800E54A4 + base + 0xACC), "%d", sp54);
            *(s32 *)((u8 *)w + 0x38) = (s32)(D_800E54A4 + base + 0xACC);
            w2 = func_0040ECB0(*(s32 *)(D_800E54A4 + so + 0x64), 0x2D7);
            sp54 = func_00435600();
            func_002A1C08((char *)(D_800E54A4 + base + 0xAC2), "%d", func_004057EC(sp54));
            *(s32 *)((u8 *)w2 + 0x38) = (s32)(D_800E54A4 + base + 0xAC2);
        }
    }
    if (ok == 1) {
        *(s32 *)(D_800E54A4 + idx * 0xB68 + 0x58) = ok;
        func_00432488(idx, 0x2DB);
        return;
    }
    so = idx * 0xB68;
    *(s32 *)(D_800E54A4 + so + 0xB30) = -1;
    *(s32 *)(D_800E54A4 + so + 0xB34) = 0;
    *(s32 *)(D_800E54A4 + so + 0xB38) = (s32)func_0040ECB0(*(s32 *)(D_800E54A4 + so + 0x64), 0x2DB);
    *(s32 *)(D_800E54A4 + so + 0xB3C) = (s32)func_0040ECB0(*(s32 *)(D_800E54A4 + so + 0x64), 0x2DC);
    *(s32 *)(D_800E54A4 + so + 0xB40) = (s32)func_0040ECB0(*(s32 *)(D_800E54A4 + so + 0x64), 0x2DD);
    func_0043442C(idx, 1);
}
