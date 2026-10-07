#include "o04_types.h"
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x7F - 0x79]; u8 unk7F; s8 unk80; u8 unk81; u8 pad82[0x84 - 0x82]; char unk84[0x1C]; } O04EntA;
typedef struct { char **p; s32 x; } O04StrTbl;
extern O04Cfg D_801462C8[];
extern char *D_800D7330;
extern char *D_800D72F0;
extern O04StrTbl D_800E3820[];
s32 func_0042F074(void);
s32 func_00274544(void);
s32 func_0041F1B0(s32 a);
void func_002A125C(char *dst, char *src);
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x7F - 0x79]; u8 unk7F; s8 unk80; u8 unk81; u8 pad82[0x84 - 0x82]; char unk84[0x0C]; } O04EntB;
typedef struct { u8 pad0[0x78]; u8 unk78; u8 pad79[0x7F - 0x79]; u8 unk7F; s8 unk80; u8 unk81; u8 pad82[0x91 - 0x82]; u8 unk91; u8 unk92; u8 unk93; u8 pad94[2]; } O04EntC;
s32 func_0042E640(u8 *a) {
    s32 i;
    s32 r;
    s32 t;
    char *s;
    O04EntC *e;
    u8 *c = (u8 *)D_801462C8;
    for (i = 7; i > 0; i--) {
        if (c[i * 0x96 + 0x148] != 1) {
            break;
        }
    }
    r = -1;
    if (i >= 0) {
        e = (O04EntC *)(c + 0xD0) + i;
        e->unk91 = 1;
        e->unk78 = 1;
        e->unk7F = i;
        t = a[0] - 1;
        if (t == 0x13) {
            e->unk80 = func_0042F074();
        } else {
            e->unk80 = t;
        }
        t = a[1];
        if (t == 3) {
            e->unk93 = func_00274544() % 3;
        } else {
            e->unk93 = t;
        }
        if (e->unk93 >= 3) {
            e->unk93 = 2;
        }
        e->unk81 = e->unk93;
        e->unk92 = a[2];
        switch (e->unk80) {
        case 0xF:
            s = D_800D7330;
            break;
        case 0x10:
            s = D_800D72F0;
            break;
        default:
            s = *D_800E3820[e->unk93 * 0x11 + func_0041F1B0(e->unk80)].p;
            break;
        }
        func_002A125C((char *)e + 0x84, s);
        r = i;
    }
    return r;
}
