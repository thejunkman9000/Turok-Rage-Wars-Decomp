#include "b07_types.h"
void func_00265670(void *p, s32 a1);
void func_0022F54C(u8 *p, s32 kind)
{
    switch (kind) {
    case 0x10:
        func_00265670(p + 0x78, 0);
        break;
    case 0x11:
        func_00265670(p + 0x78, 1);
        break;
    default:
        func_00265670(p + 0x7B, kind);
        break;
    }
}
