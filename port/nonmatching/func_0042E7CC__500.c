#include "o04_types.h"
#include "q03_types.h"
typedef struct { char **p; s32 x; } Q03StrTbl;
extern Q03StrTbl D_800E3820[];
extern s32 D_8014694C;
extern s32 D_80154028[];
extern Q03Cfg D_801462C8[];
s32 func_00274544(void);
s32 func_0041F1B0(s32 a);
void func_002A125C(char *dst, char *src);
void func_0042E7CC(void) {
    s32 tbl1[4];
    s32 tbl2[4];
    s32 i;
    s32 s4;
    s32 s6;
    s32 a;
    s32 b;
    s32 t;
    Q03Ent *e;
    Q03Cfg *c;
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
    c = D_801462C8;
    for (i = 0; i < 8; i++) {
        e = &c->ent[i];
        e->f94 = 0;
        e->f95 = 0;
        e->f78 = 0;
        e->f91 = 0;
    }
    for (i = 0; i < s4; i++) {
        e = &c->ent[4 + i];
        e->f78 = 1;
        e->f80 = tbl1[i];
        e->f91 = 0;
        e->f93 = 2;
        e->f81 = func_00274544() % 3;
        func_002A125C(e->name, *D_800E3820[e->f81 * 0x11 + func_0041F1B0(e->f80)].p);
    }
    for (i = 0; i < s6 - s4; i++) {
        t = i + 4;
        e = &c->ent[s4 + t];
        e->f78 = 1;
        e->f80 = tbl1[i + s4];
        e->f91 = 1;
        e->f93 = 2;
        e->f81 = func_00274544() % 3;
        func_002A125C(e->name, *D_800E3820[e->f81 * 0x11 + func_0041F1B0(e->f80)].p);
    }
    for (i = 0; i < 8; i++) {
        e = &c->ent[i];
    }
    D_8014694C = 1;
    c->unk1D = 1;
    c->unk1E = 8;
    c->unkD = 0;
    c->s24 = 0;
    c->s25 = 0;
    D_80154028[0] = 2;
    D_80154028[1] = tbl2[func_00274544() % 4];
}
