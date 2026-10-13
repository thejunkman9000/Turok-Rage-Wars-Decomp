#include "o04_types.h"
extern O04ModeS53C0 *D_800E53C0;
extern s32 D_800E28E0;
extern s32 D_80154024;
void *func_0040ECB0(s32 a, s32 b);
s32 func_0040EC50(void *p);
void func_0029A1D4(s32 a);
void func_002A3358(void);
void func_0040E958(s32 a, s32 b);
void func_0029A73C(void);
void func_00299368(s32 a);
s32 func_auto_0042D690(s32 a) {
    s32 s1;
    s32 *p;
    if (D_800E28E0 > 0) {
        return 0;
    }
    if (D_800E53C0->unk320 == 0) {
        D_800E53C0->unk320 = 1;
        func_0029A1D4(func_0040EC50(func_0040ECB0(a, 0x234)) == 0 ? 0x234 : 0x233);
        func_002A3358();
    }
    p = &D_80154024;
    s1 = p[0];
    if (s1 == 1) {
        p[0] = 0;
        if (p[-1] != -1) {
            func_0040E958(D_800E53C0->unkE4, 0);
            D_800E53C0->unk328 = 0;
            func_0029A73C();
            func_00299368(p[-1]);
            return 0;
        }
        func_0040E958(D_800E53C0->unkE4, 1);
        D_800E53C0->unk328 = s1;
    }
    return 0;
}
