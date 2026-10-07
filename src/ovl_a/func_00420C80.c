#include "o03_types.h"
extern O3Pj *D_800E42D0;
extern u8 D_801462D5;
void func_0029A73C();
void func_0041B834();
void func_0041CE80(void *p, s32 v);
void func_004204A8(s32 idx);
s32 func_00420C80(s32 a0, s32 a1, u32 a2) {
    s32 idx;
    O3Pj *e;
    func_0029A73C();
    idx = a2 & 0xFFFF;
    e = &D_800E42D0[idx];
    switch (e->state) {
    case 1:
        if (D_801462D5 != 1) {
            D_800E42D0[4].f18 = 5;
            D_800E42D0[4].f1C = 4;
            *(s32 *)((u8 *)&D_800E42D0[4] + 0x34) = 3;
        }
        break;
    case 3:
        e->state = 1;
        func_0041B834(D_800E42D0->menu, idx, 0);
        func_0041CE80((void *)(idx * 0x4C8 + (s32)D_800E42D0 + 0x20), 1);
        func_004204A8(idx);
        break;
    }
    return 0;
}
