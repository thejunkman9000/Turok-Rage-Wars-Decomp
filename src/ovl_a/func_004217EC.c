#include "o03_types.h"
extern O3Pm *D_800E4400;
void func_0040E958(void *it, s32 on);
void *func_0040ECB0(void *p, s32 id);
void func_004217EC(void) {
    func_0040E958(D_800E4400->item, 0);
    func_0040E958(func_0040ECB0(D_800E4400->w8, 0x3AB), 1);
    D_800E4400->f34 = 1;
}
