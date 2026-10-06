#include "common.h"

extern u8 D_8014D3E1;
extern u16 D_B2000004;

void dbgPortSetIntRxData(u8 v) {
    v |= (D_8014D3E1 & 0xFE);
    D_8014D3E1 = v;
    while (osPiGetStatus() & 3) {
    }
    D_B2000004 = v;
}
