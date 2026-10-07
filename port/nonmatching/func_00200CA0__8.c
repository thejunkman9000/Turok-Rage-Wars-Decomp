#include "b01_types.h"
void func_00200568(u32 addr, u32 val);
u32 func_002005A0(u32 addr);


void func_00200CA0(u32 addr, u32 val) {
    s32 sh = (~addr & 3) * 8;
    addr &= ~3;
    func_00200568(addr, (func_002005A0(addr) & ~(0xFF << sh)) | ((val & 0xFF) << sh));
}
