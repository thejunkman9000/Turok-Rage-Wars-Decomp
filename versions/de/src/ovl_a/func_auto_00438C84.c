#include "o05_types.h"

typedef struct { u8 pad0[0x1C]; s32 f1C; u8 pad20[4]; void *f24; u8 pad28[0x90 - 0x28]; s32 f90; u8 pad94[0x1C0 - 0x94]; s32 f1C0; } O05M5830;
typedef struct { s32 a; s32 b; } O05Pair;
extern O05M5830 *D_800E5830;
extern s32 D_800E28E0;
extern s32 D_80146948;
extern O05Pair D_80154020;
void *func_0040ECB0(void *p, s32 a);
s32 func_0040EC50(void *p);
void func_0029A1D4(s32 a);
void func_002A3358(void);
void func_0040E958(void *p, s32 a);
void func_0029A73C(void);
void func_00299368(s32 a);

s32 func_auto_00438C84(void *w) {
    s32 t;
    if (D_800E28E0 > 0) {
        return 0;
    }
    if (D_800E5830->f90 == 0) {
        D_800E5830->f90 = 1;
        func_0029A1D4(func_0040EC50(func_0040ECB0(w, 0x26F)) == 0 ? 0x26F : 0x26E);
        if (D_80146948 == 0) {
            func_0029A1D4(0x26E);
        }
        func_002A3358();
    }
    t = D_80154020.b;
    if (t != 1) {
        return 0;
    }
    D_80154020.b = 0;
    if (D_80154020.a != -1) {
        func_0040E958(D_800E5830->f24, 0);
        D_800E5830->f1C0 = 0;
        func_0029A73C();
        func_00299368(D_80154020.a);
    } else {
        func_0040E958(D_800E5830->f24, 1);
        D_800E5830->f1C0 = t;
    }
    return 0;
}
