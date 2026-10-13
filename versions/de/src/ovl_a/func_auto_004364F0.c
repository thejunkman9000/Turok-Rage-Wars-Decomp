#include "o05_types.h"
typedef struct { void *f0; void *f4; void *f8; void *fC; void *f10; void *f14; void *f18; s32 f1C; s32 f20; s32 f24; s32 f28; void *f2C; } O05M90;
extern O05M90 *D_800E5690;
extern void *D_800D74D0[];
extern void *D_800D74DC[];
extern void *D_800D749C[];
extern void *D_800D74A0[];
extern void *D_800D74E0[];
extern void *D_800D74E4[];
extern void *D_800D74E8[];
void *func_00252FFC(s32 n);
void *func_0041A300(s32 a, s32 b);
void func_0041B190(s32 a);
void *func_0041AC40(s32 a, s32 b);
void func_0041ADB4(void *w, void *s);
void *func_0041A600(s32 a, s32 b, s32 c);
void *func_00419ED4(s32 a, s32 b);
void *func_0040ECB0(void *cfg, s32 id);
void func_00436898(s32 i);

s32 func_auto_004364F0(void *cfg) {
    void *w;
    D_800E5690 = func_00252FFC(0x64);
    D_800E5690->f0 = func_0041A300(0x59, 0x5A);
    func_0041B190(0x5C);
    w = func_0041AC40(0x62, 0x63);
    D_800E5690->f14 = w;
    func_0041ADB4(w, D_800D74D0[0]);
    func_0041ADB4(D_800E5690->f14, D_800D74DC[0]);
    w = func_0041AC40(0x5F, 0x61);
    D_800E5690->f10 = w;
    func_0041ADB4(w, D_800D749C[0]);
    func_0041ADB4(D_800E5690->f10, D_800D74A0[0]);
    D_800E5690->f8 = func_0041A600(0x64, 0x65, 0xF8);
    D_800E5690->fC = func_0041A600(0x68, 0x69, 0xF8);
    w = func_0041AC40(0x66, 0x67);
    D_800E5690->f18 = w;
    func_0041ADB4(w, D_800D74E0[0]);
    func_0041ADB4(D_800E5690->f18, D_800D74E4[0]);
    func_0041ADB4(D_800E5690->f18, D_800D74E8[0]);
    func_0041B190(0x5E);
    D_800E5690->f4 = func_00419ED4(0x5B, 0x6E);
    D_800E5690->f24 = 3;
    D_800E5690->f20 = -1;
    D_800E5690->f2C = func_0040ECB0(cfg, 0x5D);
    D_800E5690->f28 = 0;
    func_00436898(0);
    return 0;
}
