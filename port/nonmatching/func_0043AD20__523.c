#include "o05_types.h"

extern O05L2 *D_800E59E0;
extern u8 D_80146398[];
typedef struct { u16 w[38]; } O05Row;
extern O05Row D_800E59EE[];
void func_0029A73C(void);
void func_0041B834(void *p, s32 a, s32 b);
void *func_0040ECB0(void *p, s32 id);
void func_0040E958(void *w, s32 a);
s32 func_0041F1B0(s32 a);
void func_0041CE80(void *p, s32 a);
s32 func_0043BC04(void);
void func_0043BA34(void);

s32 func_0043AD20(s32 a, s32 b, u32 c, s32 d) {
    s32 idx = c & 0xFFFF;
    s32 i;
    s32 val;
    O05L2 *l;
    O05L2 *l2;
    u8 *g;
    func_0029A73C();
    l = D_800E59E0;
    if (l->row[idx].f4A8 != 1) {
        return 0;
    }
    if (l->row[idx].f4AC != 5) {
        return 0;
    }
    l->row[idx].f4A8 = 2;
    func_0041B834(l->f4, idx, 1);
    for (i = 0; i < 6; i++) {
        func_0040E958(func_0040ECB0(D_800E59E0->f0, D_800E59EE[idx].w[i * 2]), 1);
    }
    g = D_80146398;
    func_0041F1B0(((s8 *)D_80146398)[idx * 150 + 0x80]);
    g = D_80146398;
    func_0041CE80(&D_800E59E0->row[idx], 0);
    if (func_0043BC04() != 0) {
        return 0;
    }
    func_0043BA34();
    l2 = D_800E59E0;
    l2->f1358 = 5;
    l2->f135C = 4;
    switch (g[-0xC3]) {
    case 0:
        val = 0x14;
        break;
    case 3:
        val = 0xA;
        break;
    case 2:
        val = 0xF;
        break;
    default:
        return 0;
    }
    l2->f1368 = val;
    return 0;
}
