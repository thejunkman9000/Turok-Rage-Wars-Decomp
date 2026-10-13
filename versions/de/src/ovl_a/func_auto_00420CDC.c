#include "o03_types.h"
extern O3Pj *D_800E42D0;
s32 func_0040EC50(s32 a);
s32 func_0041B87C(s32 m, s32 i);
s32 func_0041B890(s32 m, s32 i);
void func_0029A73C();
void func_00420688(s32 idx, s32 v);
s32 func_auto_00420CDC(s32 a0, s32 a1, u32 a2) {
    s32 idx;
    s32 v;
    O3Pj *e;
    idx = a2 & 0xFFFF;
    v = func_0041B890(D_800E42D0->menu, idx);
    func_0029A73C();
    e = &D_800E42D0[idx];
    if (e->state == 1) {
        if (v == 0x7F) {
            func_00420688(idx, e->f10);
        } else if (func_0040EC50(func_0041B87C(D_800E42D0->menu, idx)) == 0) {
            func_00420688(idx, v);
        }
    }
    return 0;
}
