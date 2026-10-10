#include "b01_types.h"

extern s32 D_800CD390;
extern OSMesgQueue D_800F6CC0;
extern OSIoMesg D_800F6CE0;
void func_00200568(u32 addr, u32 val);
void func_00200CA0(u32 addr, u32 val);

/* copy from RAM into a bus-addressed buffer (PI DMA for large aligned blocks, else byte/word writes) */
void func_00200E04(u32 dst, u8 *src, u32 n) {
    s32 dmaOk = -(D_800CD390 == 0);
    while (n != 0 && (dst & 3) != 0) {
        func_00200CA0(dst++, *src++);
        n--;
    }
    while (n >= 4) {
        if (n >= 16 && ((((u32)src & 0xF) == 0) & (dmaOk != -1))) {
            dmaOk = osPiStartDma(&D_800F6CE0, 1, 1, dst, src, n, &D_800F6CC0);
            if (dmaOk != -1) {
                osRecvMesg(&D_800F6CC0, 0, 1);
                n = 0;
            }
        } else {
            func_00200568(dst, (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | src[3]);
            dst += 4;
            src += 4;
            n -= 4;
        }
    }
    while (n != 0) {
        func_00200CA0(dst++, *src++);
        n--;
    }
}
