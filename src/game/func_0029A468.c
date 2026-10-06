#include "b22_types.h"
extern SndMgr *D_8014D080;
void func_00299ECC(void);
void func_00254784(void *);
void func_0029BAAC(void);
void func_0040F5E8(void);
void func_00411FA8(void);
void func_0029A468(void)
{
    s32 t = D_8014D080->unk8;
    while (D_8014D080->top >= t) {
        D_8014D080->unk530 = 1;
        func_00299ECC();
    }
    if (D_8014D080->fn0) {
        D_8014D080->fn0(0xE05, 0, 0, 0);
    }
    if (D_8014D080->unk53C) {
        func_00254784(D_8014D080->unk53C);
    }
    func_00254784(D_8014D080->stk);
    func_00254784(D_8014D080);
    D_8014D080 = 0;
    func_0029BAAC();
    func_0040F5E8();
    func_00411FA8();
}
