#include "o03_types.h"
extern O3Pm *D_auto_800E03B0;
void func_auto_0040E8D8(void *it, s32 on);
void *func_auto_0040EC30(void *p, s32 id);

void func_auto_0042177C(void) {
    func_auto_0040E8D8(D_auto_800E03B0->item, 0);
    func_auto_0040E8D8(func_auto_0040EC30(D_auto_800E03B0->w8, 0x3A5), 1);
    D_auto_800E03B0->f34 = 1;
}
