#include "o05_types.h"
typedef struct { void *f0; void *f4; void *f8; void *fC; void *f10; void *f14; void *f18; s32 f1C; s32 f20; s32 f24; s32 f28; void *f2C; } O05M90;
extern O05M90 *D_auto_800F1CB0;
extern void *D_auto_800E1CE4[];
extern void *D_auto_800E1D14[];
extern void *D_auto_800E1C14[];
extern void *D_auto_800E1C24[];
extern void *D_auto_800E1D24[];
extern void *D_auto_800E1D34[];
extern void *D_auto_800E1D44[];
void *func_00252FFC(s32 n);
void *func_0041A300(s32 a, s32 b);
void func_0041B190(s32 a);
void *func_0041AC40(s32 a, s32 b);
void func_0041ADB4(void *w, void *s);
void *func_0041A600(s32 a, s32 b, s32 c);
void *func_00419ED4(s32 a, s32 b);
void *func_0040ECB0(void *cfg, s32 id);
void func_auto_0043744C(s32 i);
extern u8 D_801462C8[];
typedef struct { u8 reserved[0x581]; u8 language; } LocState;

s32 func_auto_00437220(void *cfg) {
    void *w;
    LocState *settings = (LocState *)D_801462C8;
    D_auto_800F1CB0 = func_00252FFC(0x64);
    D_auto_800F1CB0->f0 = func_0041A300(0x5B, 0x5C);
    func_0041B190(0x5E);
    func_0041ADB4(D_auto_800F1CB0->f14 = func_0041AC40(0x64, 0x65), D_auto_800E1CE4[settings->language]);
    func_0041ADB4(D_auto_800F1CB0->f14, D_auto_800E1D14[settings->language]);
    func_0041ADB4(D_auto_800F1CB0->f10 = func_0041AC40(0x61, 0x63), D_auto_800E1C14[settings->language]);
    func_0041ADB4(D_auto_800F1CB0->f10, D_auto_800E1C24[settings->language]);
    D_auto_800F1CB0->f8 = func_0041A600(0x66, 0x67, 0xF8);
    D_auto_800F1CB0->fC = func_0041A600(0x6A, 0x6B, 0xF8);
    func_0041ADB4(D_auto_800F1CB0->f18 = func_0041AC40(0x68, 0x69), D_auto_800E1D24[settings->language]);
    func_0041ADB4(D_auto_800F1CB0->f18, D_auto_800E1D34[settings->language]);
    func_0041ADB4(D_auto_800F1CB0->f18, D_auto_800E1D44[settings->language]);
    func_0041B190(0x60);
    D_auto_800F1CB0->f4 = func_00419ED4(0x5D, 0x6E);
    D_auto_800F1CB0->f24 = 3;
    D_auto_800F1CB0->f20 = -1;
    D_auto_800F1CB0->f2C = func_0040ECB0(cfg, 0x5F);
    D_auto_800F1CB0->f28 = 0;
    func_auto_0043744C(0);
    return 0;
}
