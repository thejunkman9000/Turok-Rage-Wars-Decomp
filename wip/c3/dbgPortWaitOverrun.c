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

s32 dbgPortWaitOverrun(s32 v) {
    s32 ret = 0;
    s32 outer = D_800D3650;
    s32 cnt = 0x4E20;
    u8 want = (v << 1) & 0xFF;
    for (;;) {
        while (osPiGetStatus() & 3) {
        }
        if ((D_B2000015 & 2) == want) {
            ret = 1;
            break;
        }
        if (cnt-- == 0) {
            outer--;
            cnt = 0x4E20;
        }
        if (outer <= 0) {
            D_8014D3E8 = 1;
            break;
        }
    }
    return ret;
}
