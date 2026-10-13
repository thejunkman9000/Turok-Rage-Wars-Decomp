#include "o03_types.h"
extern O3Plr D_auto_8015DCF0[3];
extern O3Chr D_auto_800EFE3C[][17];
extern s32 D_auto_800EFDD8[][5];
extern u8 D_801462C8[];
s32 func_00274544(void);
void func_002A125C(void *d, void *s);
void func_auto_0041ECB4(s32 n, s32 diff) {
    s32 pts[3];
    s32 i, total, r, v, k, t;
    s32 *p;
    u8 *g;
    char *dst;
    if (n > 0) {
        for (i = 2; i >= 0; i--) {
            pts[i] = 0;
        }
        k = n - 1;
        if (n <= 0) {
            total = 0;
        } else {
            total = D_auto_800EFDD8[diff][k];
        }
        for (i = 0; i < n; i++) {
            pts[i] = 5;
            total -= 5;
        }
        i = 0;
        if (total > 0) {
            do {
                p = &pts[func_00274544() % n];
                v = *p;
                if (v < 20 && total >= v) {
                    *p = v * 2;
                    total -= v;
                }
                i++;
            } while (i <= 10000 && total > 0);
        }
        for (i = 0; i < n; i++) {
            t = pts[i] / 10;
            D_auto_8015DCF0[i].f8 = 4;
            D_auto_8015DCF0[i].type = t;
            D_auto_8015DCF0[i].fC = t;
            do {
                r = func_00274544() % 17;
                dst = D_auto_8015DCF0[i].name;
                g = D_801462C8;
                D_auto_8015DCF0[i].id = D_auto_800EFE3C[t][r].ch;
                func_002A125C(dst, D_auto_800EFE3C[t][r].s[g[0x581]]);
            } while (D_auto_8015DCF0[i].id == -1);
        }
    }
}
