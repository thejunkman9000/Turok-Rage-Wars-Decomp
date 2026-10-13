#include "o03_types.h"
extern O3Pm *D_800E4400;
extern O3Cfg D_801462C8[];
extern char *D_800D749C[];
extern char *D_800D74A0[];
void *func_00252FFC(s32 size);
O3Spr *func_0040ECB0(s32 p, s32 id);
s32 func_00419ED4(s32 a, s32 b);
s32 func_0041A300(s32 a, s32 b);
s32 func_0041AC40(s32 a, s32 b);
void func_0041AD90(s32 o, s32 i);
void func_0041ADB4(s32 o, char *s);
void func_0041B190(s32 id);
void func_004212A4();
s32 func_auto_00420E20(s32 root) {
    D_800E4400 = func_00252FFC(0x3C);
    D_800E4400->w8 = (O3Hdr *)root;
    D_800E4400->f38 = 0;
    func_0040ECB0(root, 0x3A2)->f1A = 0x86;
    D_800E4400->bar = (O3B60 *)func_0041A300(0x3A2, 0x3A3);
    func_0041B190(0x3B0);
    D_800E4400->fC = func_0041AC40(0x3AE, 0x3AF);
    func_0041ADB4(D_800E4400->fC, D_800D749C[0]);
    func_0041ADB4(D_800E4400->fC, D_800D74A0[0]);
    if (D_801462C8->flags & 0x08000000) {
        func_0041AD90(D_800E4400->fC, 1);
    } else {
        func_0041AD90(D_800E4400->fC, 0);
    }
    D_800E4400->f10 = func_0041AC40(0x3AB, 0x3AC);
    func_0041ADB4(D_800E4400->f10, D_800D749C[0]);
    func_0041ADB4(D_800E4400->f10, D_800D74A0[0]);
    if (D_801462C8->flags & 0x10000000) {
        func_0041AD90(D_800E4400->f10, 1);
    } else {
        func_0041AD90(D_800E4400->f10, 0);
    }
    D_800E4400->f14 = func_0041AC40(0x3A7, 0x3A8);
    func_0041ADB4(D_800E4400->f14, D_800D749C[0]);
    func_0041ADB4(D_800E4400->f14, D_800D74A0[0]);
    if (D_801462C8->flags & 8) {
        func_0041AD90(D_800E4400->f14, 1);
    } else {
        func_0041AD90(D_800E4400->f14, 0);
    }
    D_800E4400->f18 = func_0041AC40(0x3A9, 0x3AA);
    func_0041ADB4(D_800E4400->f18, D_800D749C[0]);
    func_0041ADB4(D_800E4400->f18, D_800D74A0[0]);
    if (D_801462C8->flags & 0x20000000) {
        func_0041AD90(D_800E4400->f18, 1);
    } else {
        func_0041AD90(D_800E4400->f18, 0);
    }
    func_0041B190(0x3A6);
    D_800E4400->item = (O3Spr *)func_0040ECB0(root, 0x3B1);
    D_800E4400->f28 = 0;
    D_800E4400->timer = 0;
    D_800E4400->f34 = 1;
    D_800E4400->f4 = func_00419ED4(0x3A4, 0x6E);
    func_004212A4();
    return 0;
}
