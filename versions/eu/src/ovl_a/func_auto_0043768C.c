#include "o05_types.h"
typedef struct { void *f0; void *f4; void *f8; void *fC; void *f10; s32 f14; void *f18; } O05M94N;
extern O05M94N *D_auto_800F1CB4;
extern void *D_auto_800E1CE4[];
extern void *D_auto_800E1D14[];
extern void *D_auto_800E1C14[];
extern void *D_auto_800E1C24[];
extern void *D_auto_800E1D24[];
extern void *D_auto_800E1D34[];
extern void *D_auto_800E1D44[];
void *func_00252FFC(s32 n);
void func_auto_0041B550(s32 a);
void *func_auto_0041B000(s32 a, s32 b);
void func_auto_0041B174(void *w, void *s);
void *func_auto_0041A9C0(s32 a, s32 b, s32 c);
void *func_auto_0040F070(void *cfg, s32 id);
void func_auto_00437878(s32 i);
extern u8 D_801462C8[];
typedef struct { u8 reserved[0x581]; u8 language; } LocState;

s32 func_auto_0043768C(void *cfg) {
    LocState *settings = (LocState *)D_801462C8;
    D_auto_800F1CB4 = func_00252FFC(0x50);
    func_auto_0041B550(0x1C6);
    func_auto_0041B174(D_auto_800F1CB4->fC = func_auto_0041B000(0x1C9, 0x1CA), D_auto_800E1CE4[settings->language]);
    func_auto_0041B174(D_auto_800F1CB4->fC, D_auto_800E1D14[settings->language]);
    func_auto_0041B174(D_auto_800F1CB4->f8 = func_auto_0041B000(0x1D1, 0x1D2), D_auto_800E1C14[settings->language]);
    func_auto_0041B174(D_auto_800F1CB4->f8, D_auto_800E1C24[settings->language]);
    D_auto_800F1CB4->f0 = func_auto_0041A9C0(0x1CF, 0x1D0, 0xFF);
    D_auto_800F1CB4->f4 = func_auto_0041A9C0(0x1CD, 0x1CE, 0xFF);
    func_auto_0041B174(D_auto_800F1CB4->f10 = func_auto_0041B000(0x1CB, 0x1CC), D_auto_800E1D24[settings->language]);
    func_auto_0041B174(D_auto_800F1CB4->f10, D_auto_800E1D34[settings->language]);
    func_auto_0041B174(D_auto_800F1CB4->f10, D_auto_800E1D44[settings->language]);
    func_auto_0041B550(0x1C8);
    D_auto_800F1CB4->f18 = func_auto_0040F070(cfg, 0x1C7);
    D_auto_800F1CB4->f14 = 0;
    func_auto_00437878(0);
    return 0;
}
