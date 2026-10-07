#include "o04_types.h"
typedef struct { char **p; s32 x; } O04StrTbl;
extern O04StrTbl D_800E3820[];
extern s32 D_8014694C;
extern s32 D_80154028[];
s32 func_00274544(void);
s32 func_0041F1B0(s32 a);
void func_002A125C(char *dst, char *src);
extern O04Cfg D_801462C8[];
void func_0042E7CC(void) {
    s32 tbl1[4];
    s32 tbl2[4];
    s32 i;
    s32 s4;
    s32 off;
    s32 b;
    s32 a;
    s32 s6;
    s32 t;
    u8 *c;
    u8 *e;
    tbl1[0] = 0;
    tbl1[1] = 3;
    tbl1[2] = 8;
    tbl1[3] = 5;
    tbl2[0] = 0;
    tbl2[1] = 3;
    tbl2[2] = 0x1B;
    tbl2[3] = 1;
    for (i = 0; i < 100; i++) {
        a = func_00274544() % 4;
        b = func_00274544() % 4;
        t = tbl1[a];
        tbl1[a] = tbl1[b];
        tbl1[b] = t;
    }
    s6 = func_00274544() % 3 + 2;
    s4 = func_00274544() % s6 + 1;
    if (s4 == 3) {
        s4 = 2;
    }
    c = (u8 *)D_801462C8;
    off = 0xD0;
    for (i = 0; i < 8; i++) {
        e = c + off;
        off += 0x96;
        e[0x94] = 0;
        e[0x95] = 0;
        e[0x78] = 0;
        e[0x91] = 0;
    }
    for (i = 0; i < s4; i++) {
        e = c + 0x328 + i * 0x96;
        e[0x78] = 1;
        e[0x80] = tbl1[i];
        e[0x91] = 0;
        e[0x93] = 2;
        e[0x81] = func_00274544() % 3;
        func_002A125C((char *)e + 0x84, *D_800E3820[(s8)e[0x81] * 0x11 + func_0041F1B0((s8)e[0x80])].p);
    }
    for (i = 0; i < s6 - s4; i++) {
        e = c + (s4 + i + 4) * 0x96 + 0xD0;
        e[0x78] = 1;
        e[0x80] = tbl1[s4 + i];
        e[0x91] = 1;
        e[0x93] = 2;
        e[0x81] = func_00274544() % 3;
        func_002A125C((char *)e + 0x84, *D_800E3820[(s8)e[0x81] * 0x11 + func_0041F1B0((s8)e[0x80])].p);
    }
    off = 0xD0;
    for (i = 0; i < 8; i++) {
        e = c + off;
        off += 0x96;
    }
    D_8014694C = 1;
    c[0x1D] = 1;
    c[0x1E] = 8;
    c[0xD] = 0;
    c[0x24] = 0;
    c[0x25] = 0;
    D_80154028[0] = 2;
    D_80154028[1] = tbl2[func_00274544() % 4];
}
