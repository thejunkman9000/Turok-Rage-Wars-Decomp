build/turok_ragewars.elf: \
    build/asm/header.o \
    build/assets/ipl3.o \
    build/asm/entry.o \
    build/src/libultra/guMtxIdent.o \
    build/src/libultra/guMtxIdentF.o \
    build/src/libultra/guMtxF2L.o \
    build/src/libultra/guMtxL2F.o \
    build/asm/BCABC.o \
    build/src/libultra/osAiSetFrequency.o \
    build/asm/BD0C8.o \
    build/src/libultra/osAiSetNextBuffer.o \
    build/asm/BD15C.o \
    build/src/libultra/__osAiDeviceBusy.o \
    build/asm/BD174.o \
    build/src/libultra/osContStartQuery.o \
    build/src/libultra/osContGetQuery.o \
    build/asm/BD228.o \
    build/src/libultra/osContStartReadData.o \
    build/src/libultra/osContGetReadData.o \
    build/src/libultra/__osPackReadData.o \
    build/src/libultra/osContReset.o \
    build/src/libultra/__osPackResetData.o \
    build/src/libultra/osContInit.o \
    build/src/libultra/__osPackRequestData.o \
    build/src/libultra/__osContGetInitData.o \
    build/asm/BD85C.o \
    build/src/libultra/osDpSetNextBuffer.o \
    build/asm/BD8FC.o \
    build/src/libultra/__osDpDeviceBusy.o \
    build/asm/BD918.o \
    build/src/libultra/osMotorStop.o \
    build/src/libultra/osMotorStart.o \
    build/src/libultra/osMotorInit.o \
    build/asm/BE184.o \
    build/src/libultra/__osContRamRead.o \
    build/src/libultra/__osPackRamReadData.o \
    build/asm/BE548.o \
    build/src/libultra/__osContRamWrite.o \
    build/src/libultra/__osPackRamWriteData.o \
    build/asm/BE908.o \
    build/src/libultra/__osContAddressCrc.o \
    build/src/libultra/__osContDataCrc.o \
    build/asm/BE9B8.o \
    build/src/libultra/osPiStartDma.o \
    build/asm/BEA6C.o \
    build/src/libultra/osPiGetCmdQueue.o \
    build/asm/BEA98.o \
    build/src/libultra/osPiGetStatus.o \
    build/asm/BEAB4.o \
    build/src/libultra/osCreatePiManager.o \
    build/asm/BEC38.o \
    build/src/libultra/osCartRomInit.o \
    build/src/libultra/__osDevMgrMain.o \
    build/src/libultra/osEPiRawStartDma.o \
    build/asm/BF274.o \
    build/src/libultra/osEPiRawReadIo.o \
    build/asm/BF414.o \
    build/src/libultra/osEPiRawWriteIo.o \
    build/src/libultra/osDriveRomInit.o \
    build/asm/BF634.o \
    build/src/libultra/piacs.o \
    build/asm/BF728.o \
    build/src/libultra/osPiRawStartDma.o \
    build/asm/BF804.o \
    build/src/libultra/osPiRawReadIo.o \
    build/asm/BF8A4.o \
    build/src/libultra/siacs.o \
    build/asm/BF998.o \
    build/src/libultra/__osSiRawStartDma.o \
    build/asm/BFA58.o \
    build/src/libultra/__osSiDeviceBusy.o \
    build/asm/BFA78.o \
    build/src/libultra/_VirtualToPhysicalTask.o \
    build/src/libultra/osSpTaskLoad.o \
    build/src/libultra/osSpTaskStartGo.o \
    build/asm/BFC98.o \
    build/src/libultra/__osSpDeviceBusy.o \
    build/asm/BFCB8.o \
    build/src/libultra/__osSpRawStartDma.o \
    build/asm/BFDBC.o \
    build/src/libultra/__osSpSetPc.o \
    build/asm/BFDEC.o \
    build/src/libultra/__osSpSetStatus.o \
    build/asm/BFE04.o \
    build/src/libultra/osSpTaskYield.o \
    build/asm/BFE2C.o \
    build/src/libultra/osSpTaskYielded.o \
    build/asm/BFE7C.o \
    build/src/libultra/__osSpGetStatus.o \
    build/asm/BFE94.o \
    build/src/libultra/osViBlack.o \
    build/asm/BFEFC.o \
    build/src/libultra/__osViInit.o \
    build/asm/BFFFC.o \
    build/src/libultra/osViGetCurrentFramebuffer.o \
    build/asm/C0038.o \
    build/src/libultra/osCreateViManager.o \
    build/src/libultra/__osViGetCurrentContext.o \
    build/src/libultra/osViSetEvent.o \
    build/asm/C0398.o \
    build/src/libultra/osViSetMode.o \
    build/asm/C03EC.o \
    build/src/libultra/osViSetSpecialFeatures.o \
    build/asm/C0554.o \
    build/src/libultra/osViSetYScale.o \
    build/asm/C05A4.o \
    build/src/libultra/osViSwapBuffer.o \
    build/asm/C05F4.o \
    build/src/libultra/__osViSwapContext.o \
    build/asm/C093C.o \
    build/src/libultra/osCreateMesgQueue.o \
    build/asm/C0974.o \
    build/src/libultra/osCreateThread.o \
    build/asm/C0A58.o \
    build/src/libultra/osGetThreadId.o \
    build/asm/C0A8C.o \
    build/src/libultra/osGetThreadPri.o \
    build/asm/C0AAC.o \
    build/src/libultra/osGetTime.o \
    build/asm/C0B2C.o \
    build/src/libultra/osJamMesg.o \
    build/asm/C0F84.o \
    build/src/libultra/osRecvMesg.o \
    build/asm/C10B4.o \
    build/src/libultra/osSendMesg.o \
    build/src/libultra/osSetEventMesg.o \
    build/asm/C129C.o \
    build/src/libultra/osSetThreadPri.o \
    build/asm/C13A4.o \
    build/src/libultra/osStartThread.o \
    build/asm/C1554.o \
    build/src/libultra/__osDequeueThread.o \
    build/asm/C1594.o \
    build/src/libultra/__osTimerInterrupt.o \
    build/src/libultra/__osTimerServicesInit.o \
    build/src/libultra/__osSetTimerIntr.o \
    build/src/libultra/__osInsertTimer.o \
    build/asm/C18A4.o \
    build/src/libultra/osVirtualToPhysical.o \
    build/asm/C1910.o \
    build/src/libultra/exceptasm.o \
    build/src/libultra/__osEnqueueAndYield.o \
    build/src/libultra/__osEnqueueThread.o \
    build/src/libultra/__osPopThread.o \
    build/src/libultra/__osDispatchThread.o \
    build/src/libultra/__osCleanupThread.o \
    build/src/libultra/__osLeoInterrupt.o \
    build/src/libultra/__osLeoAbnormalResume.o \
    build/src/libultra/__osLeoResume.o \
    build/src/libultra/osDestroyThread.o \
    build/asm/C2BE8.o \
    build/src/libultra/osGetCount.o \
    build/src/libultra/__osGetFpcCsr.o \
    build/src/libultra/__osGetSR.o \
    build/src/libultra/__osDisableInt.o \
    build/src/libultra/__osRestoreInt.o \
    build/src/libultra/osInvalDCache.o \
    build/src/libultra/osInvalICache.o \
    build/src/libultra/__osProbeTLB.o \
    build/src/libultra/__osSetCompare.o \
    build/src/libultra/__osSetFpcCsr.o \
    build/src/libultra/osSetIntMask.o \
    build/src/libultra/__osSetSR.o \
    build/src/libultra/osUnmapTLBAll.o \
    build/src/libultra/osWritebackDCache.o \
    build/src/libultra/osWritebackDCacheAll.o \
    build/asm/C3010.o \
    build/src/libultra/string.o \
    build/asm/C3114.o \
    build/assets/rsp_and_data_0.o \
    build/assets/data_1.o \
    build/assets/data_2.o \
    build/assets/data_3.o \
    build/assets/data_4.o \
    build/assets/data_5.o \
    build/assets/data_6.o \
    build/assets/data_7.o \
    build/assets/ovl_unresolved_160000.o \
    build/asm/16E000.o \
    build/assets/ovl_a_tail.o
build/asm/header.o:
build/assets/ipl3.o:
build/asm/entry.o:
build/src/libultra/guMtxIdent.o:
build/src/libultra/guMtxIdentF.o:
build/src/libultra/guMtxF2L.o:
build/src/libultra/guMtxL2F.o:
build/asm/BCABC.o:
build/src/libultra/osAiSetFrequency.o:
build/asm/BD0C8.o:
build/src/libultra/osAiSetNextBuffer.o:
build/asm/BD15C.o:
build/src/libultra/__osAiDeviceBusy.o:
build/asm/BD174.o:
build/src/libultra/osContStartQuery.o:
build/src/libultra/osContGetQuery.o:
build/asm/BD228.o:
build/src/libultra/osContStartReadData.o:
build/src/libultra/osContGetReadData.o:
build/src/libultra/__osPackReadData.o:
build/src/libultra/osContReset.o:
build/src/libultra/__osPackResetData.o:
build/src/libultra/osContInit.o:
build/src/libultra/__osPackRequestData.o:
build/src/libultra/__osContGetInitData.o:
build/asm/BD85C.o:
build/src/libultra/osDpSetNextBuffer.o:
build/asm/BD8FC.o:
build/src/libultra/__osDpDeviceBusy.o:
build/asm/BD918.o:
build/src/libultra/osMotorStop.o:
build/src/libultra/osMotorStart.o:
build/src/libultra/osMotorInit.o:
build/asm/BE184.o:
build/src/libultra/__osContRamRead.o:
build/src/libultra/__osPackRamReadData.o:
build/asm/BE548.o:
build/src/libultra/__osContRamWrite.o:
build/src/libultra/__osPackRamWriteData.o:
build/asm/BE908.o:
build/src/libultra/__osContAddressCrc.o:
build/src/libultra/__osContDataCrc.o:
build/asm/BE9B8.o:
build/src/libultra/osPiStartDma.o:
build/asm/BEA6C.o:
build/src/libultra/osPiGetCmdQueue.o:
build/asm/BEA98.o:
build/src/libultra/osPiGetStatus.o:
build/asm/BEAB4.o:
build/src/libultra/osCreatePiManager.o:
build/asm/BEC38.o:
build/src/libultra/osCartRomInit.o:
build/src/libultra/__osDevMgrMain.o:
build/src/libultra/osEPiRawStartDma.o:
build/asm/BF274.o:
build/src/libultra/osEPiRawReadIo.o:
build/asm/BF414.o:
build/src/libultra/osEPiRawWriteIo.o:
build/src/libultra/osDriveRomInit.o:
build/asm/BF634.o:
build/src/libultra/piacs.o:
build/asm/BF728.o:
build/src/libultra/osPiRawStartDma.o:
build/asm/BF804.o:
build/src/libultra/osPiRawReadIo.o:
build/asm/BF8A4.o:
build/src/libultra/siacs.o:
build/asm/BF998.o:
build/src/libultra/__osSiRawStartDma.o:
build/asm/BFA58.o:
build/src/libultra/__osSiDeviceBusy.o:
build/asm/BFA78.o:
build/src/libultra/_VirtualToPhysicalTask.o:
build/src/libultra/osSpTaskLoad.o:
build/src/libultra/osSpTaskStartGo.o:
build/asm/BFC98.o:
build/src/libultra/__osSpDeviceBusy.o:
build/asm/BFCB8.o:
build/src/libultra/__osSpRawStartDma.o:
build/asm/BFDBC.o:
build/src/libultra/__osSpSetPc.o:
build/asm/BFDEC.o:
build/src/libultra/__osSpSetStatus.o:
build/asm/BFE04.o:
build/src/libultra/osSpTaskYield.o:
build/asm/BFE2C.o:
build/src/libultra/osSpTaskYielded.o:
build/asm/BFE7C.o:
build/src/libultra/__osSpGetStatus.o:
build/asm/BFE94.o:
build/src/libultra/osViBlack.o:
build/asm/BFEFC.o:
build/src/libultra/__osViInit.o:
build/asm/BFFFC.o:
build/src/libultra/osViGetCurrentFramebuffer.o:
build/asm/C0038.o:
build/src/libultra/osCreateViManager.o:
build/src/libultra/__osViGetCurrentContext.o:
build/src/libultra/osViSetEvent.o:
build/asm/C0398.o:
build/src/libultra/osViSetMode.o:
build/asm/C03EC.o:
build/src/libultra/osViSetSpecialFeatures.o:
build/asm/C0554.o:
build/src/libultra/osViSetYScale.o:
build/asm/C05A4.o:
build/src/libultra/osViSwapBuffer.o:
build/asm/C05F4.o:
build/src/libultra/__osViSwapContext.o:
build/asm/C093C.o:
build/src/libultra/osCreateMesgQueue.o:
build/asm/C0974.o:
build/src/libultra/osCreateThread.o:
build/asm/C0A58.o:
build/src/libultra/osGetThreadId.o:
build/asm/C0A8C.o:
build/src/libultra/osGetThreadPri.o:
build/asm/C0AAC.o:
build/src/libultra/osGetTime.o:
build/asm/C0B2C.o:
build/src/libultra/osJamMesg.o:
build/asm/C0F84.o:
build/src/libultra/osRecvMesg.o:
build/asm/C10B4.o:
build/src/libultra/osSendMesg.o:
build/src/libultra/osSetEventMesg.o:
build/asm/C129C.o:
build/src/libultra/osSetThreadPri.o:
build/asm/C13A4.o:
build/src/libultra/osStartThread.o:
build/asm/C1554.o:
build/src/libultra/__osDequeueThread.o:
build/asm/C1594.o:
build/src/libultra/__osTimerInterrupt.o:
build/src/libultra/__osTimerServicesInit.o:
build/src/libultra/__osSetTimerIntr.o:
build/src/libultra/__osInsertTimer.o:
build/asm/C18A4.o:
build/src/libultra/osVirtualToPhysical.o:
build/asm/C1910.o:
build/src/libultra/exceptasm.o:
build/src/libultra/__osEnqueueAndYield.o:
build/src/libultra/__osEnqueueThread.o:
build/src/libultra/__osPopThread.o:
build/src/libultra/__osDispatchThread.o:
build/src/libultra/__osCleanupThread.o:
build/src/libultra/__osLeoInterrupt.o:
build/src/libultra/__osLeoAbnormalResume.o:
build/src/libultra/__osLeoResume.o:
build/src/libultra/osDestroyThread.o:
build/asm/C2BE8.o:
build/src/libultra/osGetCount.o:
build/src/libultra/__osGetFpcCsr.o:
build/src/libultra/__osGetSR.o:
build/src/libultra/__osDisableInt.o:
build/src/libultra/__osRestoreInt.o:
build/src/libultra/osInvalDCache.o:
build/src/libultra/osInvalICache.o:
build/src/libultra/__osProbeTLB.o:
build/src/libultra/__osSetCompare.o:
build/src/libultra/__osSetFpcCsr.o:
build/src/libultra/osSetIntMask.o:
build/src/libultra/__osSetSR.o:
build/src/libultra/osUnmapTLBAll.o:
build/src/libultra/osWritebackDCache.o:
build/src/libultra/osWritebackDCacheAll.o:
build/asm/C3010.o:
build/src/libultra/string.o:
build/asm/C3114.o:
build/assets/rsp_and_data_0.o:
build/assets/data_1.o:
build/assets/data_2.o:
build/assets/data_3.o:
build/assets/data_4.o:
build/assets/data_5.o:
build/assets/data_6.o:
build/assets/data_7.o:
build/assets/ovl_unresolved_160000.o:
build/asm/16E000.o:
build/assets/ovl_a_tail.o:
-include build/asm/header.d build/assets/ipl3.d build/asm/entry.d build/src/libultra/guMtxIdent.d build/src/libultra/guMtxIdentF.d build/src/libultra/guMtxF2L.d build/src/libultra/guMtxL2F.d build/asm/BCABC.d build/src/libultra/osAiSetFrequency.d build/asm/BD0C8.d build/src/libultra/osAiSetNextBuffer.d build/asm/BD15C.d build/src/libultra/__osAiDeviceBusy.d build/asm/BD174.d build/src/libultra/osContStartQuery.d build/src/libultra/osContGetQuery.d build/asm/BD228.d build/src/libultra/osContStartReadData.d build/src/libultra/osContGetReadData.d build/src/libultra/__osPackReadData.d build/src/libultra/osContReset.d build/src/libultra/__osPackResetData.d build/src/libultra/osContInit.d build/src/libultra/__osPackRequestData.d build/src/libultra/__osContGetInitData.d build/asm/BD85C.d build/src/libultra/osDpSetNextBuffer.d build/asm/BD8FC.d build/src/libultra/__osDpDeviceBusy.d build/asm/BD918.d build/src/libultra/osMotorStop.d build/src/libultra/osMotorStart.d build/src/libultra/osMotorInit.d build/asm/BE184.d build/src/libultra/__osContRamRead.d build/src/libultra/__osPackRamReadData.d build/asm/BE548.d build/src/libultra/__osContRamWrite.d build/src/libultra/__osPackRamWriteData.d build/asm/BE908.d build/src/libultra/__osContAddressCrc.d build/src/libultra/__osContDataCrc.d build/asm/BE9B8.d build/src/libultra/osPiStartDma.d build/asm/BEA6C.d build/src/libultra/osPiGetCmdQueue.d build/asm/BEA98.d build/src/libultra/osPiGetStatus.d build/asm/BEAB4.d build/src/libultra/osCreatePiManager.d build/asm/BEC38.d build/src/libultra/osCartRomInit.d build/src/libultra/__osDevMgrMain.d build/src/libultra/osEPiRawStartDma.d build/asm/BF274.d build/src/libultra/osEPiRawReadIo.d build/asm/BF414.d build/src/libultra/osEPiRawWriteIo.d build/src/libultra/osDriveRomInit.d build/asm/BF634.d build/src/libultra/piacs.d build/asm/BF728.d build/src/libultra/osPiRawStartDma.d build/asm/BF804.d build/src/libultra/osPiRawReadIo.d build/asm/BF8A4.d build/src/libultra/siacs.d build/asm/BF998.d build/src/libultra/__osSiRawStartDma.d build/asm/BFA58.d build/src/libultra/__osSiDeviceBusy.d build/asm/BFA78.d build/src/libultra/_VirtualToPhysicalTask.d build/src/libultra/osSpTaskLoad.d build/src/libultra/osSpTaskStartGo.d build/asm/BFC98.d build/src/libultra/__osSpDeviceBusy.d build/asm/BFCB8.d build/src/libultra/__osSpRawStartDma.d build/asm/BFDBC.d build/src/libultra/__osSpSetPc.d build/asm/BFDEC.d build/src/libultra/__osSpSetStatus.d build/asm/BFE04.d build/src/libultra/osSpTaskYield.d build/asm/BFE2C.d build/src/libultra/osSpTaskYielded.d build/asm/BFE7C.d build/src/libultra/__osSpGetStatus.d build/asm/BFE94.d build/src/libultra/osViBlack.d build/asm/BFEFC.d build/src/libultra/__osViInit.d build/asm/BFFFC.d build/src/libultra/osViGetCurrentFramebuffer.d build/asm/C0038.d build/src/libultra/osCreateViManager.d build/src/libultra/__osViGetCurrentContext.d build/src/libultra/osViSetEvent.d build/asm/C0398.d build/src/libultra/osViSetMode.d build/asm/C03EC.d build/src/libultra/osViSetSpecialFeatures.d build/asm/C0554.d build/src/libultra/osViSetYScale.d build/asm/C05A4.d build/src/libultra/osViSwapBuffer.d build/asm/C05F4.d build/src/libultra/__osViSwapContext.d build/asm/C093C.d build/src/libultra/osCreateMesgQueue.d build/asm/C0974.d build/src/libultra/osCreateThread.d build/asm/C0A58.d build/src/libultra/osGetThreadId.d build/asm/C0A8C.d build/src/libultra/osGetThreadPri.d build/asm/C0AAC.d build/src/libultra/osGetTime.d build/asm/C0B2C.d build/src/libultra/osJamMesg.d build/asm/C0F84.d build/src/libultra/osRecvMesg.d build/asm/C10B4.d build/src/libultra/osSendMesg.d build/src/libultra/osSetEventMesg.d build/asm/C129C.d build/src/libultra/osSetThreadPri.d build/asm/C13A4.d build/src/libultra/osStartThread.d build/asm/C1554.d build/src/libultra/__osDequeueThread.d build/asm/C1594.d build/src/libultra/__osTimerInterrupt.d build/src/libultra/__osTimerServicesInit.d build/src/libultra/__osSetTimerIntr.d build/src/libultra/__osInsertTimer.d build/asm/C18A4.d build/src/libultra/osVirtualToPhysical.d build/asm/C1910.d build/src/libultra/exceptasm.d build/src/libultra/__osEnqueueAndYield.d build/src/libultra/__osEnqueueThread.d build/src/libultra/__osPopThread.d build/src/libultra/__osDispatchThread.d build/src/libultra/__osCleanupThread.d build/src/libultra/__osLeoInterrupt.d build/src/libultra/__osLeoAbnormalResume.d build/src/libultra/__osLeoResume.d build/src/libultra/osDestroyThread.d build/asm/C2BE8.d build/src/libultra/osGetCount.d build/src/libultra/__osGetFpcCsr.d build/src/libultra/__osGetSR.d build/src/libultra/__osDisableInt.d build/src/libultra/__osRestoreInt.d build/src/libultra/osInvalDCache.d build/src/libultra/osInvalICache.d build/src/libultra/__osProbeTLB.d build/src/libultra/__osSetCompare.d build/src/libultra/__osSetFpcCsr.d build/src/libultra/osSetIntMask.d build/src/libultra/__osSetSR.d build/src/libultra/osUnmapTLBAll.d build/src/libultra/osWritebackDCache.d build/src/libultra/osWritebackDCacheAll.d build/asm/C3010.d build/src/libultra/string.d build/asm/C3114.d build/assets/rsp_and_data_0.d build/assets/data_1.d build/assets/data_2.d build/assets/data_3.d build/assets/data_4.d build/assets/data_5.d build/assets/data_6.d build/assets/data_7.d build/assets/ovl_unresolved_160000.d build/asm/16E000.d build/assets/ovl_a_tail.d
