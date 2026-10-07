#include "o04_types.h"
typedef struct { s32 k; u8 pad4[8]; s32 v; } O04E16b;
extern s32 D_80154010;
extern s32 D_80154014[];
extern u8 D_80154018[];
extern s32 D_800E51E4[];
extern s32 D_800E51F8[];
extern s32 D_800E5214[];
extern s32 D_800E5240[];
extern O04E16b D_800E4F64[];
s32 func_0042B11C(void);
s32 func_00274544(void);
s32 func_00265670(void *p, s32 a);
void func_002656A8(void *p, s32 a, s32 b);
void func_0042EB80(s32 a, s32 b);
static inline s32 o04_cnt(s32 a) {
    switch (a) {
    case 0:
        return 5;
    case 1:
        return 7;
    case 3:
        return 0xB;
    case 2:
        return 0x11;
    default:
        return 0;
    }
}
static inline s32 o04_look(s32 a, s32 b) {
    s32 *tbl;
    s32 key;
    s32 i;
    s32 found;
    s32 r;
    r = 0;
    if (b == 0) {
        b = 1;
    }
    switch (a) {
    case 0:
        tbl = D_800E51E4;
        break;
    case 1:
        tbl = D_800E51F8;
        break;
    case 3:
        tbl = D_800E5214;
        break;
    case 2:
        tbl = D_800E5240;
        break;
    default:
        return 0;
    }
    key = tbl[b];
    found = 0;
    i = 0;
    do {
        if (key == D_800E4F64[i].k) {
            found = 1;
            r = D_800E4F64[i].v;
        }
        i++;
    } while (i < 0x28 && found == 0);
    return r;
}
s32 func_0042AEB8(void) {
    s32 s5 = 0;
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s3;
    if (func_0042B11C() == 0) {
        s5 = 1;
        s1 = 0;
        s3 = 0;
        s0 = 0;
        s2 = o04_cnt(D_80154010) - 1;
        if (s0 == 0) {
            do {
                s1 = func_00274544() % s2 + 1;
                if (func_00265670(D_80154018, s1) == 0) {
                    s0 = 1;
                    func_002656A8(D_80154018, s1, s0);
                }
                s3++;
                if (s3 >= 0x3A99) {
                    s0 = 1;
                }
            } while (s0 == 0);
        }
        D_80154014[0] = D_80154014[0] + 1;
        func_0042EB80(D_80154010, o04_look(D_80154010, s1));
    }
    return s5;
}
