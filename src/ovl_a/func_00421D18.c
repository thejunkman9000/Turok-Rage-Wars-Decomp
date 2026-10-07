#include "o03_types.h"
typedef struct O3Pn { O3B60 *bar; O3A *fx; O3Hdr *w8; s32 fC; s32 f10; } O3Pn;
extern O3Pn *D_800E4450;
void func_0029A73C();
s32 func_0029AA08(void);
void func_00435190(s32 a);
void func_0041A4B0(O3B60 *o, s32 v);
s32 func_00421D18(void) {
    s32 n;
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x3A4: n = 0; goto go;
    case 0x3A5: n = 1; goto go;
    case 0x3A3: n = 3; goto go;
    case 0x3A2: n = 4; goto go;
    case 0x3A7: n = 2;
go:
        func_00435190(n);
        D_800E4450->f10 = 0x13;
        goto fin;
    case 0x3A6:
        D_800E4450->f10 = -1;
fin:
        func_0041A4B0(D_800E4450->bar, 2);
        break;
    default:
        return 0;
    }
    return 0;
}