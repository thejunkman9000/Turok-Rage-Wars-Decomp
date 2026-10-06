#include "common.h"

extern u8 D_8014D3E3;
extern u16 D_B200000C;

void dbgPortSetLineFormat(u8 v) {
    v |= (D_8014D3E3 & 0xF8);
    D_8014D3E3 = v;
    while (osPiGetStatus() & 3) {
    }
    D_B200000C = v;
}
