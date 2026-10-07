#include "o05_types.h"

typedef struct { u8 pad[0x24]; void *f24; u8 pad28[0x90 - 0x28]; s32 f90; u8 pad94[0x1C0 - 0x94]; s32 f1C0; } O05M30;
extern O05M30 *D_800E5830;
extern s32 D_800E28E0;
extern s32 D_80154024[];
extern s32 D_80146948;
void *func_0040ECB0(void *cfg, s32 id);
s32 func_0040EC50(void *w);
void func_0029A1D4(s32 a);
void func_002A3358(void);
void func_0040E958(void *w, s32 a);
void func_0029A73C(void);
void func_00299368(s32 a);

s32 func_00438E64(void *cfg) {
    s32 *g;
    s32 t;
    if (D_800E28E0 > 0) {
        return 0;
    }
    if (D_800E5830->f90 == 0) {
        D_800E5830->f90 = 1;
        if (func_0040EC50(func_0040ECB0(cfg, 0x273)) == 0) {
            func_0029A1D4(0x273);
        } else {
            func_0029A1D4(0x272);
        }
        if (D_80146948 == 0) {
            func_0029A1D4(0x272);
        }
        func_002A3358();
    }
    g = D_80154024;
    t = g[0];
    if (t != 1) {
        return 0;
    }
    g[0] = 0;
    if (g[-1] != -1) {
        func_0040E958(D_800E5830->f24, 0);
        D_800E5830->f1C0 = 0;
        func_0029A73C();
        func_00299368(g[-1]);
    } else {
        func_0040E958(D_800E5830->f24, 1);
        D_800E5830->f1C0 = t;
    }
    return 0;
}
