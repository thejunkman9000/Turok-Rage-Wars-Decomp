#include "b01_types.h"

u32 func_00200800(u32 addr);
void func_00200C28(u32 addr, u32 val);

/* byte copy between two bus-addressed buffers */
void func_00201064(u32 dst, u32 src, u32 n) {
    s32 i = n - 1;
    if (n != 0) {
        do {
            func_00200C28(dst++, func_00200800(src++) & 0xFF);
        } while (--i != -1);
    }
}
