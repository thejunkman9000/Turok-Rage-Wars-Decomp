#include "o05_types.h"

typedef struct { void *f0; void *f4; void *f8; void *fC; void *f10; s32 f14; void *f18; } O05M94;
extern O05M94 *D_800E5694;
extern void *D_800D74D0[];
extern void *D_800D74DC[];
extern void *D_800D749C[];
extern void *D_800D74A0[];
extern void *D_800D74E0[];
extern void *D_800D74E4[];
extern void *D_800D74E8[];
void *func_00252FFC(s32 n);
void func_0041B190(s32 a);
void *func_0041AC40(s32 a, s32 b);
void func_0041ADB4(void *w, void *s);
void *func_0041A600(s32 a, s32 b, s32 c);
void *func_0040ECB0(void *cfg, s32 id);
s32 func_auto_00436E94(void *cfg) {
    D_800E5694 = func_00252FFC(0x50);
    func_0041B190(0x1C2);
    func_0041ADB4(D_800E5694->fC = func_0041AC40(0x1C5, 0x1C6), D_800D74D0[0]);
    func_0041ADB4(D_800E5694->fC, D_800D74DC[0]);
    func_0041ADB4(D_800E5694->f8 = func_0041AC40(0x1CD, 0x1CE), D_800D749C[0]);
    func_0041ADB4(D_800E5694->f8, D_800D74A0[0]);
    D_800E5694->f0 = func_0041A600(0x1CB, 0x1CC, 0xFF);
    D_800E5694->f4 = func_0041A600(0x1C9, 0x1CA, 0xFF);
    func_0041ADB4(D_800E5694->f10 = func_0041AC40(0x1C7, 0x1C8), D_800D74E0[0]);
    func_0041ADB4(D_800E5694->f10, D_800D74E4[0]);
    func_0041ADB4(D_800E5694->f10, D_800D74E8[0]);
    func_0041B190(0x1C4);
    D_800E5694->f18 = func_0040ECB0(cfg, 0x1C3);
    D_800E5694->f14 = 0;
    func_00436AD8(0);
    return 0;
}
