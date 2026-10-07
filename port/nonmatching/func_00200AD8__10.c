#include "b01_types.h"


void func_00200AD8(u32 addr, u32 val) {
    s32 sh = (~addr & 3) * 8;
    u32 *p = (u32 *)(addr & ~3);
    *p = (*p & ~(0xFF << sh)) | ((val & 0xFF) << sh);
}
