#include "o05_types.h"

extern void *D_800E5558;
extern s32 D_80146894[];
extern u8 D_8011FE88[];
s32 func_0043C4E8(void *p);
void func_0043C260(void *p);
void func_0043C484(void *p);
void func_0040C4A8(s32 a);
void func_0029A73C(void);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
s32 func_0025471C(void);
void func_0025470C(s32 a);
void func_0025E3A4(void);
void func_0042E080(void);

s32 func_00436488(s32 a, s32 b, s32 ev) {
    if (ev == 1) {
        if (func_0043C4E8(D_800E5558) != ev) {
            return 0;
        }
        func_0043C260(D_800E5558);
        func_0043C484(D_800E5558);
        if (func_0043C4E8(D_800E5558) != 2) {
            return 0;
        }
        func_0029A73C();
        D_80146894[0] = 0;
        func_0044AFC0(D_80146894 - 0x603, 0);
        func_0044A600(D_80146894 - 0x615, 0, 0);
        func_00286A78(D_8011FE88, 0x24, 0);
        if (func_0025471C() == 0) {
            func_0025470C(1);
        }
        func_0025E3A4();
        func_0042E080();
    }
    return 0;
}
