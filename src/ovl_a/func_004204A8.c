#include "o03_types.h"
extern O3Pj *D_800E42D0;
typedef struct { O3Id a[3]; O3Id b[3]; O3Id c[3]; } Q2IdRow;
extern Q2IdRow D_800E42D4[];
extern u8 D_80102B57[];
void func_0040E958(void *it, s32 on);
void func_0040E9A8(void *it, s32 on);
O3Hdr *func_0040ECB0(s32 p, u16 id);
s32 func_0041F248(s32 key);
static inline O3Pj *pj(s32 i) { return &D_800E42D0[i]; }
void func_004204A8(s32 idx) {
    s32 i;
    s32 a;
    s32 n;
    O3Hdr *it;
    i = 0;
    do {
        func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].c[i].id), 1);
        i++;
    } while (i < 3);
    it = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].b[pj(idx)->f18].id);
    func_0040E9A8(it, 0);
    it->alpha = 0x50;
    a = pj(idx)->f10;
    pj(idx)->f18 = 0;
    if (a != -1) {
        n = D_80102B57[func_0041F248(a) + idx * 0x190];
        if (n <= 0) {
            n = 1;
        }
        i = 0;
        if (n != 0) {
            do {
                func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].c[i].id), 0);
                i++;
            } while (i < n);
        }
        it = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].b[pj(idx)->f18].id);
        func_0040E9A8(it, 1);
        it->alpha = 0x96;
    }
}
