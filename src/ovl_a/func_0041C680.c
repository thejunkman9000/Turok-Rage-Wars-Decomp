#include "o03_types.h"
typedef struct O3Rc { s32 f0; u8 pad4[8]; s16 fC; } O3Rc;
typedef struct O3LvTab { s32 pad; s32 cnt; u16 ids[1]; } O3LvTab;
typedef struct O3Lv {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ s32 w24;
    /* 0x28 */ u8 pad28[0x54 - 0x28];
    /* 0x54 */ s32 w54;
    /* 0x58 */ u8 pad58[0x94 - 0x58];
    /* 0x94 */ O3LvTab *tab;
} O3Lv;
extern O3Lv D_8011FE88[];
extern u8 D_800E1490[];
extern u8 D_800E14A4[];
s32 func_0028FE08();
s32 func_0028FE1C();
s32 func_0028FD94();
O3Rc *func_0028CF48();
s32 *func_002518DC();
void func_002536F4();
void func_00246BD8();
void func_0041C680(O3Act *a, s32 id, s32 p, s32 type) {
    s32 i;
    s32 found;
    O3Lv *lv;
    O3Body *b;
    s32 n;
    int new_var2;
    u16 *e;
    u16 *t2;
    s32 h, r, sz;
    u8 *new_var;
    s32 one;
    s32 *q, *w;
    O3Rc *x;
    found = i = 0;
    n = D_8011FE88->tab->cnt;
    b = (O3Body *)((u8 *)a + 0x190);
    new_var2 = 1;
    t2 = D_8011FE88->tab->ids;
    if (n > 0) {
        lv = D_8011FE88;
        one = new_var2;
        e = t2;
        do {
            if (*e == id) {
                h = func_0028FE08(lv->w54, lv->w24, i);
                q = func_002518DC(0, h, h, 0x18, 0, 0, 0, D_800E1490, one);
                if (q != 0) {
                    r = func_0028FE1C(*q, h, 0, &sz);
                    w = func_002518DC(0, r, r, sz, 0, 0, 0, D_800E14A4, one);
                    new_var = (u8 *)b;
                    if (w != 0) {
                        x = func_0028CF48(lv, *(u16 *)(func_0028FD94(*w, 0) + 0x1C));
                        if (x->fC == type && x->f0 == *(s32 *)a) {
                            *(s16 *)(new_var + 4) = i;
                            *(u16 *)((u8 *)b + 0xE4) = id;
                            func_00246BD8(b, lv->w54, lv->w24, p);
                            found = new_var2;
                        }
                        func_002536F4(0, w);
                    }
                    func_002536F4(0, q);
                    do { } while (0);
                }
            }
            i++;
            e++;
        } while (i < n && found == 0);
    }
}



