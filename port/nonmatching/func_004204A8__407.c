#include "o03_types.h"
extern O3Pj *D_800E42D0;
extern O3IdRow D_800E42D4[];
extern u8 D_80102B57[];
void func_0040E958(void *it, s32 on);
void func_0040E9A8(void *it, s32 on);
O3Hdr *func_0040ECB0(s32 p, u16 id);
s32 func_0041F248(s32 key);
void func_004204A8(s32 idx) {
    s32 i;
    s32 a;
    u8 n;
    O3Hdr *it;
    i = 0;
    do {
        func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[6 + i].id), 1);
        i++;
    } while (i < 3);
    it = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[3 + D_800E42D0[idx].f18].id);
    func_0040E9A8(it, 0);
    it->alpha = 0x50;
    a = D_800E42D0[idx].f10;
    D_800E42D0[idx].f18 = 0;
    if (a != -1) {
        n = D_80102B57[func_0041F248(a) + idx * 0x190];
        if (n <= 0) {
            n = 1;
        }
        i = 0;
        if (n != 0) {
            do {
                func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[6 + i].id), 0);
                i++;
            } while (i < n);
        }
        it = func_0040ECB0(D_800E42D0->f0, ((O3Id *)D_800E42D4)[idx * 9 + 3 + D_800E42D0[idx].f18].id);
        func_0040E9A8(it, 1);
        it->alpha = 0x96;
    }
}
