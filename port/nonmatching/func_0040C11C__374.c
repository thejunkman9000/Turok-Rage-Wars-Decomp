#include "common.h"
typedef struct Q01Mode { s32 w; s32 h; s32 pad[5]; } Q01Mode;
extern s32 D_80000300;
extern Q01Mode D_800E28F8[][5];
extern s32 D_800E28F0[];
extern s32 D_800E28D8;
extern s32 D_800E28DC;
extern s32 D_800E28E4;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
s32 func_00265370(void *p);
void func_0040C11C(void) {
    s32 mode = 0;
    s32 *row;
    s32 lim;
    s32 a, b, c, d;
    switch (D_80000300) {
    case 0:
    case 2:
        mode = 1;
    case 1:
        break;
    }
    row = (s32 *)&D_800E28F8[mode][D_800E28D8];
    if (func_00265370(D_800E28F8) != 0x400000) lim = 0x2A300; else lim = 0xF660;
    if (D_800E28E4 == 0) {
        D_800E28D8 = (D_800E28D8 + 1) % D_800E28F0[mode];
        while (lim < row[0] * row[1]) {
            D_800E28D8 = (D_800E28D8 + 1) % D_800E28F0[mode];
        }
    } else {
        D_800E28E4 = 0;
    }
    a = D_800E28F8[mode][D_800E28D8].w;
    b = D_800E28F8[mode][D_800E28DC].w;
    if (a < b) a = b;
    D_800E28D0 = a;
    c = D_800E28F8[mode][D_800E28D8].h;
    d = D_800E28F8[mode][D_800E28DC].h;
    D_800E28D4 = c > d ? c : d;
}
