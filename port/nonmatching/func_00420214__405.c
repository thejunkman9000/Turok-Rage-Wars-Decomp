#include "o03_types.h"
extern O3Pj *D_800E42D0;
extern O3IdRow D_800E42D4[];
extern u8 D_80102B57[];
void func_0040E9A8(void *it, s32 on);
O3Hdr *func_0040ECB0(s32 p, s32 id);
s32 func_0041F248(s32 key);
void func_00420214(s32 idx) {
    s32 cur;
    s32 n;
    s32 nxt;
    O3Hdr *it;
    cur = D_800E42D0[idx].f18;
    it = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[3 + cur].id);
    func_0040E9A8(it, 0);
    it->alpha = 0x50;
    n = D_80102B57[func_0041F248(D_800E42D0[idx].f10) + idx * 0x190];
    if (n <= 0) {
        n = 1;
    }
    nxt = (cur + 1) % n;
    it = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[3 + nxt].id);
    func_0040E9A8(it, 1);
    it->alpha = 0x96;
    D_800E42D0[idx].f18 = nxt;
}
