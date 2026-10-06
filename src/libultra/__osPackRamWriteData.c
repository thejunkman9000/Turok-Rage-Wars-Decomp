#include "common.h"

void __osPackRamWriteData(int channel, u16 address, u8 *buffer) {
    u8 *ptr;
    __OSContRamWriteFormat ramwriteformat;
    int i;

    ptr = (u8 *)__osPfsPifRam.ramarray;

    __osPfsPifRam.pifstatus = 1;

    ramwriteformat.dummy = 0xFF;
    ramwriteformat.txsize = 0x23;
    ramwriteformat.rxsize = 1;
    ramwriteformat.cmd = 3;
    ramwriteformat.address = (address << 5) | __osContAddressCrc(address);
    ramwriteformat.datacrc = 0xFF;

    for (i = 0; i < BLOCKSIZE; i++) {
        ramwriteformat.data[i] = *buffer++;
    }

    if (channel != 0) {
        for (i = 0; i < channel; i++) {
            *ptr++ = 0;
        }
    }

    *(__OSContRamWriteFormat *)ptr = ramwriteformat;
    ptr += sizeof(__OSContRamWriteFormat);
    *ptr = 0xFE;
}
