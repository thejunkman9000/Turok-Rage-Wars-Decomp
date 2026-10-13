#include "o03_types.h"
extern O3Pm *D_800E4400;
extern s8 D_80102B0D[];
void func_0040E9D0(void *it, s32 on);
void *func_0040ECB0(void *p, s32 id);
s32 func_004261E4(s32 slot);
void func_auto_00421234(void) {
    s32 i, n;
    n = 0;
    for (i = 0; i < 4; i++) {
        if (D_80102B0D[i * 0x190] >= 0) {
            n += func_004261E4(i);
        }
    }
    if (D_800E4400->f38 == 1) {
        n = 0x28;
    }
    func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3AE), 1);
    func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3AB), 1);
    func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3A7), 1);
    func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3A9), 1);
    if (n >= 10) {
        func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3AB), 0);
    }
    if (n >= 6) {
        func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3AE), 0);
    }
    if (n >= 12) {
        func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3A7), 0);
    }
    if (n >= 14) {
        func_0040E9D0(func_0040ECB0(D_800E4400->w8, 0x3A9), 0);
    }
}
