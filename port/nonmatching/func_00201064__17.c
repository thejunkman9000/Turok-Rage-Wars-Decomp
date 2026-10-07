#include "b01_types.h"

u32 func_00200800(u32 addr);
void func_00200C28(u32 addr, u32 val);

void func_00201064(u32 dst, u32 src, u32 n) {
    while (n--) {
        func_00200C28(dst++, func_00200800(src++) & 0xFF);
    }
}