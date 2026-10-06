#include "common.h"

extern u8 D_8014D3E0;
extern u8 D_8014D3E1;
extern u8 D_8014D3E2;
extern u8 D_8014D3E3;
extern s32 D_8014D3E8;
extern s32 D_800D3650;
extern u16 D_B2000000;
extern u16 D_B2000004;
extern u16 D_B2000008;
extern u16 D_B200000C;
extern u8 D_B2000011;
extern u8 D_B2000015;

void dbgPortSetFifoRxReset(s32 v) {
    u8 tmp = (D_8014D3E2 & 0xFD) | (v << 1);
    D_8014D3E2 = tmp;
    while (osPiGetStatus() & 3) {
    }
    D_B2000008 = tmp;
}
