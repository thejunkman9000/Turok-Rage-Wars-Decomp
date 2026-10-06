#include "common.h"

s32 osPiRawStartDma(s32 dir, u32 cart_addr, void *dram_addr, u32 size) {
    register int status;

    status = HW_REG(PI_STATUS_REG, u32);
    while (status & (PI_STATUS_BUSY | PI_STATUS_IOBUSY)) {
        status = HW_REG(PI_STATUS_REG, u32);
    }

    HW_REG(PI_DRAM_ADDR_REG, u32) = osVirtualToPhysical(dram_addr);

    HW_REG(PI_CART_ADDR_REG, u32) = (OS_ROM_BASE | cart_addr) & 0x1FFFFFFF;

    switch (dir) {
        case 0:
            HW_REG(PI_WR_LEN_REG, u32) = size - 1;
            break;
        case 1:
            HW_REG(PI_RD_LEN_REG, u32) = size - 1;
            break;
        default:
            return -1;
            break;
    }

    return 0;
}
