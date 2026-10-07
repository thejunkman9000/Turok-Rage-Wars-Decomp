#include "b01_types.h"

u32 func_002005A0(u32 addr);
void func_00200568(u32 addr, u32 val);
void func_002005DC(s32 n);

/* copy a block word by word between bus addresses (src/len taken from the 0xB1FFFFF4/F8 registers) */
void func_002012D8(void) {
    u32 src = func_002005A0(0xB1FFFFF4) & 0xB1FFFFFC;
    u32 len = func_002005A0(0xB1FFFFF8) & 0x1FFFFFC;
    u32 i;
    func_00200568(0xB1FFFFFC, 0);
    while (func_002005A0(0xB0000010) == 0) {
        func_002005DC(500);
    }
    for (i = 0; i < (len >> 2); i++) {
        func_00200568((src & 0xB07FFFFF) + i * 4, func_002005A0(src + i * 4));
    }
    func_002005DC(2000);
    func_00200568(0xB1FFFFF4, 0);
}
