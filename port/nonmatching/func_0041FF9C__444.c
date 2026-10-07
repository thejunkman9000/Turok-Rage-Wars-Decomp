#include "o03_types.h"
extern O3Pj *D_800E42D0;
extern O3Row D_800E3A50[];
extern O3Cfg D_801462C8[];
extern s8 D_80102B0D[];
extern u8 D_80102B00[];
extern u8 D_80102B54[];
s32 func_0022F5B4();
s32 func_00265670(void *b, s32 i);
void func_002656A8(void *b, s32 i, s32 v);
O3Hdr *func_0040ECB0(void *p, u16 id);
void func_0040E958(void *it, s32 on);
void func_0040E9D0(void *it, s32 on);
void func_0041FF9C(void) {
    u8 bits[8];
    s32 i, j, found, r, t;
    O3Hdr *it;
    O3Hdr *it2;
    u8 *pp;
    i = 0;
    do {
        found = 0;
        j = 0;
        pp = D_80102B00;
        do {
            if (D_80102B0D[j * 0x190] >= 0) {
                r = 0;
                if (found != 0 || func_0022F5B4(pp, D_800E3A50[i].f4) != 0) {
                    r = 1;
                }
                found = r;
            }
            pp += 0x190;
            j++;
        } while (j < 4 && found == 0);
        if (D_801462C8->f0D == 0 || D_801462C8->f0D - 2 == 0) {
            if (D_801462C8->flags & 0x08000000) {
                found = 1;
            }
        }
        func_002656A8(bits, i, found);
        i++;
    } while (i < 0x11);
    if (D_801462C8->f0D == 1) {
        func_002656A8(bits, 0xB, 0);
        func_002656A8(bits, 0xC, 0);
        func_002656A8(bits, 0xD, 0);
        func_002656A8(bits, 0xE, 0);
    }
    if (D_801462C8->f0D == 0 || D_801462C8->f0D == 2) {
        func_002656A8(bits, 1, 1);
    }
    i = 0;
    do {
        it = func_0040ECB0(D_800E42D0->f0, (u16)D_800E3A50[i].f0);
        func_0040E9D0(it, 0);
        if (func_00265670(bits, i) == 0) {
            if (it != 0) {
                func_0040E9D0(it, 1);
                func_0040E958(it, 0);
            }
        } else {
            t = D_801462C8->f0D;
            if (t == 1 && func_00265670(D_80102B54, D_800E3A50[i].f4) == 1) {
                it2 = func_0040ECB0(it, 0x83);
                func_0040E958(it2, 1);
                it2->alpha = 0x32;
            }
        }
        i++;
    } while (i < 0x11);
}
