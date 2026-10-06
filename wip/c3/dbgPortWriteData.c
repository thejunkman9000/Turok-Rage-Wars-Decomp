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

void dbgPortWriteData(u8 data) {
    D_8014D3E0 = data;
    while (osPiGetStatus() & 3) {
    }
    D_B2000000 = data;
}
