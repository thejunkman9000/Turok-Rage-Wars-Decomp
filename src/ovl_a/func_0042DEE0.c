#include "o04_types.h"
extern O04ModeS5430 *D_800E5430;
extern char D_800E1B60[];
void func_0029A73C(void);
s32 func_00264634(s32 a);
s32 func_002646B0(void);
void func_002A1C08(char *dst, char *fmt, s32 n);
void func_0025DF54(s32 a);
s32 func_0042DEE0(s32 a, s32 b, s32 c, s32 d) {
    if (d != 1) {
        return 0;
    }
    func_0029A73C();
    if (func_00264634(D_800E5430->unk20) == d) {
        if (D_800E5430->unk20 < func_002646B0()) {
            D_800E5430->unk20 = D_800E5430->unk20 + 1;
        }
    }
    func_002A1C08(D_800E5430->unk14, D_800E1B60, D_800E5430->unk20);
    func_0025DF54(0xE81);
    return 0;
}
