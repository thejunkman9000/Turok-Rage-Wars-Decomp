#include "b24_types.h"

extern s8 D_8014D3E0;
extern s8 D_8014D3E1;
extern u8 D_8014D3E2;
extern s8 D_8014D3E3;
extern s8 D_8014D3E4;
extern s32 D_8014D3E8;
extern s16 D_B2000000;
extern s16 D_B2000004;
extern s16 D_B2000008;
extern s16 D_B200000C;
extern s16 D_B2000010;

s32 func_002AE260(void) {
    u8 v;
    D_8014D3E0 = 0;
    D_8014D3E1 = 0;
    D_8014D3E2 = 0;
    D_8014D3E3 = 0;
    D_8014D3E4 = 0;
    while (osPiGetStatus() & 3) {}
    D_B2000000 = 0;
    while (osPiGetStatus() & 3) {}
    D_B2000004 = 0;
    while (osPiGetStatus() & 3) {}
    D_B2000008 = 0;
    while (osPiGetStatus() & 3) {}
    D_B200000C = 0;
    while (osPiGetStatus() & 3) {}
    D_B2000010 = 0;
    while (osPiGetStatus() & 3) {}
    v = D_8014D3E2 | 0x40;
    D_8014D3E2 = v;
    while (osPiGetStatus() & 3) {}
    D_B2000008 = v;
    D_8014D3E8 = 0;
    return 1;
}
