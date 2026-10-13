#include "o04_types.h"
#include "q03_types.h"
typedef struct { char **p; s32 x; } Q03StrTbl;
extern Q03Cfg D_801462C8[];
extern char *D_auto_800E1664[];
extern char *D_auto_800E1564[];
extern Q03StrTbl D_800E3820[];
extern u8 D_auto_80152789;
s32 func_0042F074(void);
s32 func_00274544(void);
s32 func_0041F1B0(s32 a);
void func_002A125C(char *dst, char *src);
s32 func_auto_0042F0B0(u8 *a) {
    s32 i;
    s32 r;
    s32 t;
    char *s;
    Q03Ent *e;
    for (i = 7; i > 0; i--) {
        if (D_801462C8->ent[i].f78 != 1) {
            break;
        }
    }
    r = -1;
    if (i >= 0) {
        e = &D_801462C8->ent[i];
        e->f91 = 1;
        e->f78 = 1;
        e->f7F = i;
        t = a[0] - 1;
        if (t == 0x13) {
            e->f80 = func_0042F074();
        } else {
            e->f80 = t;
        }
        t = a[1];
        if (t == 3) {
            e->f93 = func_00274544() % 3;
        } else {
            e->f93 = t;
        }
        if (e->f93 >= 3) {
            e->f93 = 2;
        }
        e->f81 = e->f93;
        e->f92 = a[2];
        switch (e->f80) {
        case 0xF:
            s = D_auto_800E1664[D_auto_80152789];
            break;
        case 0x10:
            s = D_auto_800E1564[D_auto_80152789];
            break;
        default:
            s = D_800E3820[e->f93 * 0x11 + func_0041F1B0(e->f80)].p[D_auto_80152789];
            break;
        }
        func_002A125C(e->name, s);
        r = i;
    }
    return r;
}
