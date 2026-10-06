#!/usr/bin/env bash
# Print per-function match status for the libultra source set with the project's libultra flags.
cd /mnt/d/Projects/TurokRageWars
SRCS="osSendMesg.c osRecvMesg.c osJamMesg.c osCreateMesgQueue.c osSetThreadPri.c osStartThread.c osCreateThread.c osDestroyThread.c osSetEventMesg.c osVirtualToPhysical.c osTimer.c osSetTimer.c osGetThreadPri.c osViSwapBuffer.c osViSetMode.c osViBlack.c osSpTaskYield.c __osViSwapContext.c osAiSetFrequency.c osViSetEvent.c osGetTime.c osPiStartDma.c osPiRawStartDma.c osSpTaskLoadGo.c osSetTime.c osAiGetLength.c osCreateViManager.c osCreatePiManager.c osContInit.c osEepromRead.c osInitialize.c osDestroyThread.c osStartThread.c osViSetSpecialFeatures.c osPiGetCmdQueue.c osGetThreadId.c osViData.c __osDequeueThread.c"
python3 tools/lu_match.py 2.8.1 ${FLAGS:--O2 -fforce-addr -fno-builtin} -- $SRCS 2>&1 | grep -v ' D_' | grep -v '^--'
