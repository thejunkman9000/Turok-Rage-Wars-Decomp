#include "o03_types.h"
extern O3Pj *D_800E42D0;
extern O3IdRow D_800E42D4[];
extern O3Cfg D_801462C8[];
extern u8 D_801462D5;
extern u8 D_80102B0F[];
void func_0040E958(void *it, s32 on);
O3Hdr *func_0040ECB0(s32 p, u16 id);
void func_0041B834();
void func_0041CE80(void *p, s32 v);
s32 func_0041F1FC(s32 key);
s32 func_0041F248(s32 key);
void func_00299368(s32 a);
void func_00420688(s32 idx, s32 val) {
    s32 i, n, a;
    s8 r;
    O3Cfg *cfg;
    D_800E42D0[idx].state = 3;
    func_0041B834(D_800E42D0->menu, idx, 1);
    *(s32 *)((u8 *)&D_800E42D0[idx] + 0x4C8) = 1;
    i = 0;
    do {
        func_0040E958(func_0040ECB0(D_800E42D0->f0, D_800E42D4[idx].e[6 + i].id), 1);
        i++;
    } while (i < 3);
    D_800E42D0[idx].f10 = val;
    func_0041F1FC(val);
    func_0041CE80(D_800E42D0[idx].sub, 0);
    n = 0;
    for (i = 0; i < 4; i++) {
        if ((u32)(D_800E42D0[i].state - 1) < 2) {
            n++;
        }
    }
    if (n == 0) {
        cfg = D_801462C8;
        for (i = 0; i < 8; i++) {
            cfg->pl[i].f78 = 0;
            if (D_800E42D0[i].state == 3) {
                cfg->pl[i].f91 = 0;
                cfg->pl[i].f78 = 1;
                cfg->pl[i].f7F = i;
                r = func_0041F248(D_800E42D0[i].f10);
                cfg->pl[i].f80 = r;
                if (cfg->f0D == 1) {
                    D_80102B0F[i * 0x190] = r;
                }
                cfg->pl[i].f81 = *((u8 *)&D_800E42D0[i] + 0x1B);
            }
        }
        a = 8;
        if (D_801462D5 == 1) {
            a = 0xA;
        }
        func_00299368(a);
    }
}
