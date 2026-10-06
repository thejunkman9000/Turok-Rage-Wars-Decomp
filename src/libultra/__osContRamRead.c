#include "common.h"

#ifdef NON_MATCHING
s32 __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer) {
    s32 ret;
    int i;
    u8 *ptr;
    __OSContRamReadFormat ramreadformat;
    int retry = 2;

    __osSiGetAccess();
    __osContLastCmd = 2;
    __osPackRamReadData(channel, address);
    ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);

    do {
        ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);

        ptr = (u8 *)&__osPfsPifRam;
        if (channel != 0) {
            for (i = 0; i < channel; i++) {
                ptr++;
            }
        }

        ramreadformat = *(__OSContRamReadFormat *)ptr;
        ret = CHNL_ERR(ramreadformat);

        if (ret == 0) {
            if (__osContDataCrc(ramreadformat.data) != ramreadformat.datacrc) {
                ret = __osPfsGetStatus(mq, channel);
                if (ret != 0) {
                    break;
                }
                ret = PFS_ERR_CONTRFAIL;
            } else {
                for (i = 0; i < BLOCKSIZE; i++) {
                    *buffer++ = ramreadformat.data[i];
                }
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while (ret == PFS_ERR_CONTRFAIL && retry-- >= 0);

    __osSiRelAccess();

    return ret;
}
#else
INCLUDE_ASM("asm/nonmatchings/libultra/__osContRamRead", __osContRamRead);
#endif
