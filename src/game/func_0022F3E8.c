#include "b07_types.h"
void func_0022F3E8(u8 *p, s32 idx)
{
    switch (idx) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        (p + idx)[0x18]++;
        break;
    case 0x11:
        idx = 0xB;
        goto store;
    case 0x12:
        idx = 0xC;
store:
        (p + idx)[0x18]++;
        break;
    }
}
