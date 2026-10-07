#include "b01_types.h"

extern s32 D_800CD390;
extern OSMesgQueue D_800F6CC0;
extern OSIoMesg D_800F6CE0;
u32 func_002005A0(u32 addr);
u32 func_00200840(u32 addr);

/* copy from a bus-addressed buffer into RAM (PI DMA for large aligned blocks, else byte/word reads) */
void func_0020095C(u32 src, u8 *dst, u32 n) {
    s32 dmaOk = -(D_800CD390 == 0);
    u32 w;
    while (n != 0 && (src & 3) != 0) {
        *dst++ = func_00200840(src++);
        n--;
    }
    while (n >= 4) {
        if (n >= 16 && ((((u32)dst & 0xF) == 0) & (dmaOk != -1))) {
            dmaOk = osPiStartDma(&D_800F6CE0, 1, 0, src, dst, n, &D_800F6CC0);
            if (dmaOk != -1) {
                osRecvMesg(&D_800F6CC0, 0, 1);
                n = 0;
            }
        } else {
            w = func_002005A0(src);
            *dst++ = w >> 24;
            *dst++ = w >> 16;
            *dst++ = w >> 8;
            *dst++ = w;
            src += 4;
            n -= 4;
        }
    }
    while (n != 0) {
        *dst++ = func_00200840(src++);
        n--;
    }
}
