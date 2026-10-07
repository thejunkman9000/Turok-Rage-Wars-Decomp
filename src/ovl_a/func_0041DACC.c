#include "o03_types.h"
extern O3Pk *D_800E3590;
extern O3Tbl D_800E3594[];
extern u8 D_80102B4A[];
s32 func_00265670(void *p, s32 i);
O3Hdr *func_0040ECB0(s32 p, s32 id);
void func_0040E958(O3Hdr *it, s32 on);
void func_0041DACC(s32 alpha) {
    s32 i;
    O3Hdr *it;
    i = 0;
    do {
        it = func_0040ECB0(D_800E3590->parent, (u16)D_800E3594[i].key);
        if (func_00265670(D_80102B4A + D_800E3590->slot * 0x190, i) == 1) {
            func_0040E958(it, 1);
            it->alpha = alpha;
        } else {
            func_0040E958(it, 0);
        }
        i++;
    } while (i < 0x32);
}
