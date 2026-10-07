#include "o03_types.h"
extern void *D_800E44A0;
s32 func_0043C4E8(void *p);
void func_0043C260(void *p);
void func_0043C484(void *p);
void func_00422050(void);
void func_0042E080();
void func_00264874(s32 a);
s32 func_004222D8(s32 a0, s32 a1, s32 a2) {
    if (a2 != 1) return 0;
    if (func_0043C4E8(D_800E44A0) != a2) return 0;
    func_0043C260(D_800E44A0);
    func_0043C484(D_800E44A0);
    if (func_0043C4E8(D_800E44A0) != 2) return 0;
    func_00422050();
    func_0042E080();
    func_00264874(1);
    return 0;
}
