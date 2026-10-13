#include "common.h"

/* The ROM keeps two stray linker-padding bytes (ED 50) after the file-name string; the string is a fixed-size array
   (emitted after the literal pool, like the other assert strings) so the .rodata piece comes out byte-identical. */
extern const char SIRAWDMA_FILE[16];

s32 __osSiRawStartDma(s32 dir, void *dramAddr) {
    if ((u32)dramAddr & 3) {
        __assert("EX", SIRAWDMA_FILE, 55);
    }

    if (__osSiDeviceBusy()) {
        return -1;
    }

    if (dir == OS_WRITE) {
        osWritebackDCache(dramAddr, 0x40);
    }

    IO_WRITE(SI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));

    if (dir == OS_READ) {
        IO_WRITE(SI_PIF_ADDR_RD64B_REG, 0x1FC007C0);
    } else {
        IO_WRITE(SI_PIF_ADDR_WR64B_REG, 0x1FC007C0);
    }

    if (dir == OS_READ) {
        osInvalDCache(dramAddr, 0x40);
    }

    return 0;
}

const char SIRAWDMA_FILE[16] = "io/sirawdma.c\0\040\124";
