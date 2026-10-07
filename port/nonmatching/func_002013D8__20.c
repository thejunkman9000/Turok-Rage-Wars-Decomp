#include "b01_types.h"
extern u32 D_800D05E0[];
extern u8 D_800F7450;
extern u8 D_800F7452;
s32 func_00200500(void);
void func_00200538(s32 mask);
void func_00200568(u32 addr, u32 val);
void func_002022E0(void);


void func_002013D8(void) {
    s32 mask = func_00200500();
    u32 mem;
    func_002022E0();
    func_00200568(0xB1FFFFF0, 0);
    func_00200568(0xB1FFFFFC, 0);
    mem = *(u32 *)0x80000318;
    D_800F7450 = 1;
    D_800F7452 = 0xFF;
    if (mem > 0x3FFFFF) {
        if (((mem & 0x1FFFF) == 0) & (mem <= 0x2000000)) {
            mem--;
            D_800D05E0[2] = mem - 0x80000000;
            D_800D05E0[6] = mem + 0xA0000000;
        }
    }
    func_00200538(mask);
}
