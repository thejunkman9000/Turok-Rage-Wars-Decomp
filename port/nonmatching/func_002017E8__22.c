#include "b01_types.h"

void func_00200568(u32 addr, u32 val);
u32 func_002005A0(u32 addr);
void func_002005DC(s32 n);

/* program a bus transfer through the 0xB1FFFFxx registers and wait until idle */
void func_002017E8(u32 a0, u32 a1, u32 a2, u32 a3) {
    func_00200568(0xB1FFFFE4, a1);
    func_00200568(0xB1FFFFE8, a2);
    func_00200568(0xB1FFFFEC, a3);
    func_00200568(0xB1FFFFE0, a0);
    do {
        func_002005DC(1000);
        if (func_002005A0(0xB1FFFFF0) != 0) {
            __asm__ volatile("break 1");
        }
    } while (func_002005A0(0xB1FFFFE0) != 0);
    func_002005A0(0xB1FFFFDC);
}
