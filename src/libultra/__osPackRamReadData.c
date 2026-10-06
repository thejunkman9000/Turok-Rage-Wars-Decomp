#include "common.h"

void __osPackRamReadData(int channel, u16 address) {
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;
    int i;

    ptr = (u8 *)__osPfsPifRam.ramarray;

    __osPfsPifRam.pifstatus = 1;

    ramreadformat.dummy = 0xFF;
    ramreadformat.txsize = 3;
    ramreadformat.rxsize = 0x21;
    ramreadformat.cmd = 2;
    ramreadformat.address = (address << 5) | __osContAddressCrc(address);
    ramreadformat.datacrc = 0xFF;

    for (i = 0; i < BLOCKSIZE; i++) {
        ramreadformat.data[i] = 0xFF;
    }

    if (channel != 0) {
        for (i = 0; i < channel; i++) {
            *ptr++ = 0;
        }
    }

    *(__OSContRamReadFormat *)ptr = ramreadformat;
    ptr += sizeof(__OSContRamReadFormat);
    *ptr = 0xFE;
}
