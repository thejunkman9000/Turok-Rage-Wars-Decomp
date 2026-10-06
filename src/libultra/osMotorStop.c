#include "common.h"

s32 osMotorStop(OSPfs *pfs) {
    int i;
    s32 ret;
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;

    ptr = (u8 *)&__osPfsPifRam;
    if (!__osMotorInitialized[pfs->channel]) {
        return PFS_ERR_INVALID;
    }

    __osSiGetAccess();
    __osContLastCmd = 3;
    __osSiRawStartDma(OS_WRITE, &__osMotorStopData[pfs->channel]);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);
    __osSiRawStartDma(OS_READ, &__osPfsPifRam);
    osRecvMesg(pfs->queue, NULL, OS_MESG_BLOCK);

    if (pfs->channel != 0) {
        for (i = 0; i < pfs->channel; i++) {
            ptr++;
        }
    }

    ramreadformat = *(__OSContRamReadFormat *)ptr;
    ret = CHNL_ERR(ramreadformat);
    if (ret == 0) {
        if (__osContDataCrc(__osMotorStopBuf) != ramreadformat.datacrc) {
            ret = PFS_ERR_CONTRFAIL;
        }
    }

    __osSiRelAccess();
    return ret;
}
