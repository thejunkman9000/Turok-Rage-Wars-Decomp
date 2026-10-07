#include "o03_types.h"
typedef struct O3Lv {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ s32 w24;
    /* 0x28 */ u8 pad28[0x54 - 0x28];
    /* 0x54 */ s32 *w54;
    /* 0x58 */ u8 pad58[0x94 - 0x58];
    /* 0x94 */ struct { s32 pad; s32 cnt; u16 ids[1]; } *tab;
} O3Lv;
typedef struct O3Rc { s32 f0; u8 pad4[8]; s16 fC; } O3Rc;
extern O3Lv D_8011FE88[];
extern u8 D_800E1490[];
extern u8 D_800E14A4[];
s32 func_0028FE08(s32 *a, s32 b, s32 i);
void *func_0028FE1C(s32 *tbl, s32 base, s32 idx, s32 *size);
void *func_0028FD94();
O3Rc *func_0028CF48(void *lv, u16 idx);
s32 *func_002518DC();
void func_002536F4(s32 a, void *n);
void func_00246BD8();
void func_0041C680(O3Act *a, s32 id, s32 p, s32 type) {
    s32 i;
    s32 found;
    s32 n;
    u16 *e;
    s32 *q;
    s32 *w;
    s32 h;
    s32 r;
    s32 sz;
    O3Rc *x;
    O3Body *b;
    O3Lv *lv;
    i = 0;
    found = 0;
    lv = D_8011FE88;
    b = (O3Body *)((u8 *)a + 0x190);
    n = lv->tab->cnt;
    if (n > 0) {
        e = lv->tab->ids;
        do {
            if (*e == id) {
                h = func_0028FE08(lv->w54, lv->w24, i);
                q = func_002518DC(0, h, h, 0x18, 0, 0, 0, D_800E1490, 1);
                if (q != 0) {
                    r = (s32)func_0028FE1C((s32 *)*q, h, 0, &sz);
                    w = func_002518DC(0, r, r, sz, 0, 0, 0, D_800E14A4, 1);
                    if (w != 0) {
                        x = func_0028CF48(lv, *(u16 *)((u8 *)func_0028FD94(*w, 0) + 0x1C));
                        if (x->fC == type && x->f0 == *(s32 *)a) {
                            *(s16 *)((u8 *)b + 4) = i;
                            *(u16 *)((u8 *)b + 0xE4) = p;
                            found = 1;
                            func_00246BD8(b, lv->w54, lv->w24, p);
                        }
                        func_002536F4(0, w);
                    }
                    func_002536F4(0, q);
                }
            }
            i++;
            e++;
        } while (i < n && found == 0);
    }
}
