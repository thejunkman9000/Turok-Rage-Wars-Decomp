#include "p2_types.h"

void func_002656A8(void *p, s32 a, s32 b);

void func_0022F504(u8 *p, s32 kind) {
    switch (kind) {
    case 0x10:
        func_002656A8(p + 0x78, 0, 1);
        break;
    case 0x11:
        func_002656A8(p + 0x78, 1, 1);
        break;
    default:
        func_002656A8(p + 0x7B, kind, 1);
        break;
    }
}