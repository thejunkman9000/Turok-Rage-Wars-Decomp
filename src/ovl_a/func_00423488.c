#include "o03_types.h"
extern O3Words *D_800E4510;
s32 func_0029AA08(void);
void func_0029A73C();
void func_00423280(void);
void func_0041A4B0(s32 o, s32 v);
s32 func_00423488(void) {
    s32 ok;
    s32 id;
    func_0029A73C();
    ok = 1;
    id = func_0029AA08();
    switch (id) {
    case 0x50:
        D_800E4510->w[8] = -1;
        break;
    case 0x57:
        D_800E4510->w[8] = 6;
        break;
    case 0x58:
        D_800E4510->w[8] = 5;
        break;
    default:
        ok = 0;
        break;
    }
    if (ok == 1) {
        func_00423280();
        func_0041A4B0(D_800E4510->w[0], 2);
    }
    return 0;
}
