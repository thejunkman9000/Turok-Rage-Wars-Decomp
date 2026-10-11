#include "o02_types.h"
void osViBlack(u8 b);
void func_auto_00416060(s32 n) {
    s32 i = 0;
    u32 m;
    while (n != 5) {
        m = i++ & 0x100000;
        osViBlack(m != 0);
    }
}
