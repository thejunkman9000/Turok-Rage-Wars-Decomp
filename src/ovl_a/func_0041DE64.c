#include "o03_types.h"
extern O3Pk *D_800E3590;
void func_0029A73C();
void func_0041DBA0(s32 *p);
void func_0041DACC(s32 a);
void func_0041D718(void);
void func_0041D9D0(void);
s32 func_0041DE64(s32 a0, s32 a1, u32 a2, s32 a3) {
    if ((a2 >> 16) == 3 && a3 == 0) {
        func_0029A73C();
        func_0041DBA0(&D_800E3590->slot);
        func_0041DACC(0x6E);
        func_0041D718();
        func_0041D9D0();
        D_800E3590->cur = 0;
    }
    return 0;
}
