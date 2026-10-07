#include "o03_types.h"
extern O3Pj *D_800E42D0;
typedef struct { O3Id a[3]; O3Id b[3]; O3Id c[3]; } Q2IdRow;
extern Q2IdRow D_800E42D4[];
extern u8 D_80102B57[];
void func_0040E9A8(void *it, s32 on);
O3Hdr *func_0040ECB0(s32 p, u16 id);
s32 func_0041F248(s32 key);
static inline O3Pj *pj(s32 i) { return &D_800E42D0[i]; }
void func_00420214(s32 idx) {
    s32 cur;
    s32 n;
    s32 nxt;
    O3Hdr *it;
    cur = pj(idx)->f18;
    it = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].b[cur].id);
    func_0040E9A8(it, 0);
    it->alpha = 0x50;
    n = D_80102B57[func_0041F248(pj(idx)->f10) + idx * 0x190];
    if (n <= 0) {
        n = 1;
    }
    cur = (cur + 1) % n;
    nxt = cur;
    it = func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].b[nxt].id);
    func_0040E9A8(it, 1);
    it->alpha = 0x96;
    pj(idx)->f18 = nxt;
}
