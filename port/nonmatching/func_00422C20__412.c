#include "o03_types.h"
extern O3Words *D_800E4518;
extern O3Scr *D_800E2830;
extern O3Cfg D_801462C8[];
extern s32 D_80146894;
extern s32 D_8015402C;
extern u8 D_80145088[];
extern u8 D_8011FE88[];
s32 func_0043C4E8(void *p);
void func_0043C260(void *p);
void func_0043C484(void *p);
void func_0040C4A8(s32 a);
void func_0040E958(s32 it, s32 on);
s32 func_004030E0(s32 a);
void func_0029A73C();
s32 func_0025E2E4();
s32 func_00274544();
void func_0025E2F4(s32 a);
void func_0044AFC0(void *p, s32 a);
void func_0044A600(void *p, s32 a, s32 b);
void func_00286A78(void *p, s32 a, s32 b);
void func_0042E080();
void func_002A3304();
typedef struct O3Scr3C { u8 pad[0x3C]; s32 f3C; } O3Scr3C;
s32 func_00422C20(s32 a0, s32 a1, s32 a2) {
    s32 st, n, i, r, t, m, q;
    if (a2 == 1) {
        st = func_0043C4E8(D_800E4518);
        if (st != a2) return 0;
        func_0043C260(D_800E4518);
        func_0043C484(D_800E4518);
        if (func_0043C4E8(D_800E4518) != 2) return 0;
        switch (D_800E4518->w[7]) {
        case 0:
            func_0040C4A8(0);
            func_0040E958(a0, 1);
            func_004030E0(D_8015402C + 0x259);
            *(s32 *)((u8 *)D_800E2830 + 0xD8) = -1;
            ((O3Scr3C *)D_800E2830)->f3C = st;
            return 0;
        case 1:
            func_0029A73C();
            if (D_800E4518->w[0x19] == 0 && func_0025E2E4() != 0) {
                r = func_00274544();
                q = r;
                if (q < 0) {
                    q += 3;
                }
                t = (r - ((q >> 2) << 2)) + 0x38;
            } else {
                t = D_800E4518->w[0x19];
            }
            func_0025E2F4(t);
            D_80146894 = 0;
            if (D_800E4518->w[0x18] == -1) {
                n = 0;
                for (i = 0; i < 4; i++) {
                    if (D_801462C8->pl[i].f91 == 0 && D_801462C8->pl[i].f78 == 1) {
                        n++;
                    }
                }
                if (D_801462C8->f580 == 2 && n >= 2) {
                    m = 1;
                } else {
                    m = D_801462C8->f580;
                }
                func_0040C4A8(m);
                func_002A3304();
                return 0;
            }
            func_0044AFC0(D_80145088, 0);
            func_0044A600(D_80145088 - 0x48, 0, 0);
            func_00286A78(D_8011FE88, 0, 0);
            func_0042E080();
            break;
        default:
            return 0;
        }
    }
    return 0;
}
