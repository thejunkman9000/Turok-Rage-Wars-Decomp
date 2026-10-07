#include "b01_types.h"
void func_00200568(u32 addr, u32 val);
void func_00200C28(u32 addr, u32 val);


void func_00200F98(u32 dst, u8 val, u32 n) {
    u32 w;
    while (n != 0 && (dst & 3) != 0) {
        func_00200C28(dst++, val);
        n--;
    }
    if (n >= 4) {
        w = ((val) << 24) | ((val) << 16) | ((val) << 8) | (val);
        do {
            func_00200568(dst, w);
            n -= 4;
            dst += 4;
        } while (n >= 4);
    }
    while (n != 0) {
        func_00200C28(dst++, val);
        n--;
    }
}
