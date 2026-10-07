#include "o03_types.h"
/* PARTIAL: ROM starts with a stray `addiu v0,zero,1` (1 word) before the prologue; the body matches from 0x42250C+4 (rom 0x190510). */
extern O3Words *D_800E4510;
extern O3Cfg D_801462C8[];
extern char *D_800D749C[];
extern char *D_800D74A4[];
extern char *D_800D74A8[];
extern char *D_800D74AC[];
extern char *D_800D74B0[];
extern char *D_800D74B4[];
extern char *D_800D74B8[];
extern char *D_800D74BC[];
void *func_00252FFC(s32 size);
s32 func_00265370();
s32 func_00419ED4(s32 a, s32 b);
s32 func_0041A300(s32 a, s32 b);
s32 func_0041A600(s32 a, s32 b, s32 c);
s32 func_0041AC40(s32 a, s32 b);
void func_0041A76C(s32 o, s32 v);
void func_0041AD90(s32 o, s32 i);
void func_0041ADB4(s32 o, char *s);
void func_0041B190(s32 id);
s32 func_0042250C(void) {
    s32 t;
    D_800E4510 = func_00252FFC(0x28);
    D_800E4510->w[0] = func_0041A300(0x4D, 0x4E);
    func_0041B190(0x57);
    func_0041B190(0x58);
    D_800E4510->w[3] = func_0041AC40(0x59, 0x5A);
    func_0041ADB4(D_800E4510->w[3], D_800D749C[0]);
    func_0041ADB4(D_800E4510->w[3], D_800D74A4[0]);
    func_0041ADB4(D_800E4510->w[3], D_800D74A8[0]);
    func_0041AD90(D_800E4510->w[3], D_801462C8->f1B);
    D_800E4510->w[4] = func_0041AC40(0x55, 0x56);
    func_0041ADB4(D_800E4510->w[4], D_800D74AC[0]);
    func_0041ADB4(D_800E4510->w[4], D_800D74B0[0]);
    func_0041AD90(D_800E4510->w[4], D_801462C8->f1F);
    D_800E4510->w[5] = func_0041AC40(0x51, 0x52);
    func_0041ADB4(D_800E4510->w[5], D_800D74B4[0]);
    if (func_00265370() != 0x400000) {
        func_0041ADB4(D_800E4510->w[5], D_800D74B8[0]);
        func_0041ADB4(D_800E4510->w[5], D_800D74BC[0]);
    }
    func_0041AD90(D_800E4510->w[5], D_801462C8->f580);
    D_800E4510->w[2] = func_0041A600(0x53, 0x54, 0x80);
    func_0041A76C(D_800E4510->w[2], D_801462C8->f10);
    func_0041B190(0x50);
    t = func_00419ED4(0x4F, 0x6E);
    D_800E4510->w[9] = 3;
    D_800E4510->w[1] = t;
    D_800E4510->w[8] = -1;
    return 0;
}
