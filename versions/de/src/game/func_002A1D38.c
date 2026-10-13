#include "b23_types.h"
extern s32 D_800D2B80;
extern s32 D_800D2B84;
extern s32 D_800D2BB0;
extern s32 D_800D2BB8;
extern s32 D_800D2BBC;
extern s32 D_800D2BC0;
extern u8 D_801051B8[];
s32 func_00252FFC(s32 n);
void func_0025631C(void *a, s32 b, s32 c, s32 d);
void func_002A2050(void *a, void *b, void *c, void *d, void *e, void *f, void *g);
void func_002A2158();
void func_002A2188();
void func_002A2198();
void func_002A21EC();
void func_002A21F4();
void func_002A2220();
void func_002A2230();
void func_002A1D38(void) {
    s32 *p;
    if (D_800D2B80++ == 0) {
        D_800D2B84 = 0x12345678;
        if (D_800D2BC0 != 1) {
            p = &D_800D2BB8;
            *p = 0x8BB01;
            D_800D2BB0 = func_00252FFC(D_800D2BB8);
            func_0025631C(D_801051B8, 0x200000, D_800D2BB8, D_800D2BB0);
            D_800D2BBC = 0;
            p[2] = 1;
        }
        func_002A2050(func_002A2158, func_002A2188, func_002A2198, func_002A21EC, func_002A21F4,
                      func_002A2220, func_002A2230);
    }

}
