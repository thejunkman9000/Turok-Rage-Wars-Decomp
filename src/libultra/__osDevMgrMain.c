#include "common.h"

#ifdef NON_MATCHING
#define STATUS_WRITE() (*(u32 *)PHYS_TO_K1(PI_STATUS_REG) = 2)

void __osDevMgrMain(void *args) {
    OSIoMesg *mb;
    OSMesg em;
    OSMesg dummy;
    s32 ret;
    OSMgrArgs *dm;
    s32 messageSend;
    OSPiHandle *handle;
    __OSTranxInfo *info;
    __OSBlockInfo *blockInfo;
    u32 stat;

    dm = (OSMgrArgs *)args;
    mb = NULL;
    ret = 0;

    while (TRUE) {
        osRecvMesg(dm->cmdQueue, (OSMesg *)&mb, OS_MESG_BLOCK);

        handle = mb->piHandle;
        if (handle != NULL && handle->type == 2 &&
            (handle->transferInfo.cmdType == 0 || handle->transferInfo.cmdType == 1)) {
            info = &handle->transferInfo;
            blockInfo = &info->block[info->blockNum];
            info->sectorNum = -1;
            if (info->transferMode != 3) {
                blockInfo->dramAddr = (void *)((u32)blockInfo->dramAddr - blockInfo->sectorSize);
            }
            messageSend = 0;
            if (info->transferMode == 2) {
                messageSend = mb->piHandle->transferInfo.cmdType == 0;
            }
            osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
            __osResetGlobalIntMask(0x100401);
            osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x80000000);

            while (TRUE) {
                osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);
                handle = mb->piHandle;
                info = &handle->transferInfo;
                blockInfo = &info->block[info->blockNum];
                if (blockInfo->errStatus == 0x1D) {
                    osEPiRawWriteIo(handle, 0x05000510, info->bmCtlShadow | 0x10000000);
                    osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow);
                    osEPiRawReadIo(mb->piHandle, 0x05000508, &stat);
                    if (stat & 0x02000000) {
                        osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x01000000);
                    }
                    blockInfo->errStatus = 4;
                    STATUS_WRITE();
                    __osSetGlobalIntMask(0x100C01);
                }
                osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                if (messageSend == 1) {
                    messageSend = 0;
                    if (mb->piHandle->transferInfo.block[0].errStatus == 0) {
                        continue;
                    }
                }
                break;
            }

            osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
            if (mb->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
            continue;
        }

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
#else
INCLUDE_ASM("asm/nonmatchings/libultra/__osDevMgrMain", __osDevMgrMain);
#endif
