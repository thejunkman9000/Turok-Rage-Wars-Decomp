#include "o03_types.h"
extern O3Plr D_80153F80[3];
extern O3Chr D_800E381C[][17];
extern s32 D_800E37B8[][5];
s32 func_00274544(void);
void func_002A125C(void *d, void *s);
void func_0041E88C(s32 n, s32 diff) {
    s32 pts[3];
    s32 i, total, r, v, k, t;
    s32 *p;
    if (n > 0) {
        for (i = 2; i >= 0; i--) {
            pts[i] = 0;
        }
        k = n - 1;
        if (n <= 0) {
            total = 0;
        } else {
            total = D_800E37B8[diff][k];
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
            D_80153F80[i].f8 = 4;
            D_80153F80[i].type = t;
            D_80153F80[i].fC = t;
            do {
                r = func_00274544() % 17;
                D_80153F80[i].id = D_800E381C[t][r].ch;
                func_002A125C(D_80153F80[i].name, *D_800E381C[t][r].s);
            } while (D_80153F80[i].id == -1);
        }
    }
}
