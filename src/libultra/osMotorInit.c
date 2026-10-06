#include "common.h"

static void __osMakeMotorData(int channel, u16 address, u8 *buf, OSPifRam *mdata) {
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;
    int i;

    ptr = (u8 *)mdata->ramarray;
    for (i = 0; i < 15; i++) {
        mdata->ramarray[i] = 0;
    }
    mdata->pifstatus = 1;

    ramreadformat.dummy = 0xFF;
    ramreadformat.txsize = 0x23;
    ramreadformat.rxsize = 1;
    ramreadformat.cmd = 3;
    ramreadformat.address = (address << 5) | __osContAddressCrc(address);
    ramreadformat.datacrc = 0xFF;

    for (i = 0; i < BLOCKSIZE; i++) {
        ramreadformat.data[i] = *buf++;
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

s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int channel) {
    s32 ret;
    u8 temp[BLOCKSIZE];
    int i;

    pfs->queue = mq;
    pfs->channel = channel;
    pfs->status = 0;
    pfs->activebank = 0x80;

    for (i = 0; i < BLOCKSIZE; i++) {
        temp[i] = 0xFE;
    }

    ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    }
    if (ret != 0) {
        return ret;
    }

    ret = __osContRamRead(mq, channel, 0x400, temp);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = PFS_ERR_CONTRFAIL;
    }
    if (ret != 0) {
        return ret;
    }

    if (temp[BLOCKSIZE - 1] == 0xFE) {
        return PFS_ERR_DEVICE;
    }

    for (i = 0; i < BLOCKSIZE; i++) {
        temp[i] = 0x80;
    }

    ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = __osContRamWrite(mq, channel, 0x400, temp, 0);
    }
    if (ret != 0) {
        return ret;
    }

    ret = __osContRamRead(mq, channel, 0x400, temp);
    if (ret == PFS_ERR_NEW_PACK) {
        ret = PFS_ERR_CONTRFAIL;
    }
    if (ret != 0) {
        return ret;
    }

    if (temp[BLOCKSIZE - 1] != 0x80) {
        return PFS_ERR_DEVICE;
    }

    if (!__osMotorInitialized[channel]) {
        for (i = 0; i < BLOCKSIZE; i++) {
            __osMotorStartBuf[i] = 1;
            __osMotorStopBuf[i] = 0;
        }
        __osMakeMotorData(channel, 0x600, __osMotorStartBuf, &__osMotorStartData[channel]);
        __osMakeMotorData(channel, 0x600, __osMotorStopBuf, &__osMotorStopData[channel]);
        __osMotorInitialized[channel] = 1;
    }

    return 0;
}
