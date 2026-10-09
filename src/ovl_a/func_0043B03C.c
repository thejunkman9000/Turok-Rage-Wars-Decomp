#include "o05_types.h"

extern O05L2 *D_800E59E0;
extern s32 D_800E5B4C[][4];
extern s32 D_801462C8;
extern O05Rec D_80102B00[];
s32 func_0022F4CC(void *p, s32 a);
void func_0043B67C(s32 k, s32 c, s32 v);

void func_0043B03C(s32 k, s32 step) {
    s32 s0;
    s32 s1;
    s32 s3;
    s32 s5;
    s32 s6;
    s32 c;
    unsigned char new_var;
    s32 a0;
    if (D_800E59E0->row[k].f4CC != 2) {
        return;
    }
    s3 = 0;
    s6 = s3;
    c = D_800E59E0->row[k].f4AC;
    s5 = s3;
    switch (c) {
    case 0:
    case 1:
        s3 = 4;
        s6 = 0;
        s5 = 1;
        break;
    case 2:
    case 3:
        s3 = 8;
        s6 = 2;
        s5 = 3;
        break;
    case 4:
        s3 = 3;
        s6 = 4;
        s5 = s6;
        break;
    case 5:
        return;
    }
    new_var = 1;
    s0 = D_800E59E0->row[k].tab4B0[c];
    s0 += step;
    do {
        if (!(s0 < s3)) {
            s0 = 0;
        }
        if (s0 < 0) {
            s0 = 1;
            s0 = s3 - s0;
        }
        s1 = 1;
        for (a0 = s6; a0 < s5 + 1; a0++) {
            if (s1 != new_var) {
                break;
            }
            if (D_800E59E0->row[k].tab4B0[a0] == s0) {
                s0 += step;
                s1 = 0;
            }
        }
        if (s1 == new_var && (u32)(c - 2) < 2) {
            if (D_800E5B4C[s0][0] == 15) {
                if (!(D_801462C8 & 0x10000000)) {
                    if (func_0022F4CC(&D_80102B00[k], 15) == 0) {
                        s0 += step;
                        s1 = 0;
                    }
                }
            }
        }
    } while (s1 == 0);
    func_0043B67C(k, c, s0);
    D_800E59E0->row[k].tab4B0[c] = s0;
}
