/* __osDevMgrMain (ROM 0xBED00, 230 insns + 2 junk pad words before osEPiRawStartDma at 0xBF0A0).
 * EXACT with `@SN -fforce-addr` (cc.sh: sn + -fforce-addr; also EXACT code under lu = -O3 -fforce-addr -fno-builtin).
 * Key: the 64DD retry loop is a backward `goto again`, not an inner while(TRUE): with a real loop gcc hoists the
 * PI_STATUS_REG address (0xA4600010) into an s-register; the ROM keeps `lui/ori/sw 0(v1)` in place and hoists the 1 instead. */
#include "common.h"

void __osDevMgrMain(void *args) {
    OSIoMesg *mb;
    OSMesg em;
    OSMesg dummy;
    s32 ret;
    OSMgrArgs *dm;
    s32 messageSend;

    messageSend = 0;
    mb = NULL;
    ret = 0;
    dm = (OSMgrArgs *)args;

    while (TRUE) {
        osRecvMesg(dm->cmdQueue, (OSMesg *)&mb, OS_MESG_BLOCK);

        if (mb->piHandle != NULL && mb->piHandle->type == 2 &&
            (mb->piHandle->transferInfo.cmdType == 0 || mb->piHandle->transferInfo.cmdType == 1)) {
            __OSBlockInfo *blockInfo;
            __OSTranxInfo *info;
            info = &mb->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];
            info->sectorNum = -1;
            if (info->transferMode != 3) {
                blockInfo->dramAddr = (void *)((u32)blockInfo->dramAddr - blockInfo->sectorSize);
            }
            if (info->transferMode == 2 && mb->piHandle->transferInfo.cmdType == 0) {
                messageSend = 1;
            } else {
                messageSend = 0;
            }
            osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
            __osResetGlobalIntMask(0x100401);
            osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x80000000);

        again:
                osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);
                info = &mb->piHandle->transferInfo;
                blockInfo = &info->block[info->blockNum];
                if (blockInfo->errStatus == 0x1D) {
                    u32 stat;
                    osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x10000000);
                    osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow);
                    osEPiRawReadIo(mb->piHandle, 0x05000508, &stat);
                    if (stat & 0x02000000) {
                        osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x01000000);
                    }
                    blockInfo->errStatus = 4;
                    IO_WRITE(PI_STATUS_REG, 2);
                    __osSetGlobalIntMask(0x100C01);
                }
                osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                if (messageSend == 1 && mb->piHandle->transferInfo.block[0].errStatus == 0) {
                    messageSend = 0;
                    goto again;
                }
            osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
            if (mb->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
        } else {
            switch (mb->hdr.type) {
                case 11:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->dma_func(OS_READ, mb->devAddr, mb->dramAddr, mb->size);
                    break;
                case 12:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->dma_func(OS_WRITE, mb->devAddr, mb->dramAddr, mb->size);
                    break;
                case 15:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->edma_func(mb->piHandle, OS_READ, mb->devAddr, mb->dramAddr, mb->size);
                    break;
                case 16:
                    osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
                    ret = dm->edma_func(mb->piHandle, OS_WRITE, mb->devAddr, mb->dramAddr, mb->size);
                    break;
                case 10:
                    osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                    ret = -1;
                    break;
                default:
                    ret = -1;
                    break;
            }
            if (ret == 0) {
                osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);
                osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
            }
        }
    }
}
