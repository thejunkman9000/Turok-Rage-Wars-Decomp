#!/usr/bin/env bash
# Per-function results (>=8 insns) for two gcc versions, side by side.
SRCS="osSendMesg.c osRecvMesg.c osJamMesg.c osCreateMesgQueue.c osSetThreadPri.c osStartThread.c osCreateThread.c osDestroyThread.c osSetEventMesg.c __osDequeueThread.c osVirtualToPhysical.c osTimer.c osSetTimer.c osGetThreadPri.c osViSwapBuffer.c osViSetMode.c osViBlack.c osSpTaskYield.c __osViSwapContext.c osAiSetFrequency.c osViSetEvent.c osSetTime.c osGetTime.c osAiGetLength.c osPiStartDma.c osPiRawStartDma.c osSpTaskLoadGo.c"
python3 tools/lu_match.py 2.7.2 -O2 -- $SRCS | awk '$2+0>=8 && $1 !~ /^D_/ {print $1, $2, $4}' | sort > /tmp/a.txt
python3 tools/lu_match.py 2.8.1 -O2 -- $SRCS | awk '$2+0>=8 && $1 !~ /^D_/ {print $1, $2, $4}' | sort > /tmp/b.txt
join -a1 -a2 -e '-' -o 0,1.2,1.3,2.2,2.3 /tmp/a.txt /tmp/b.txt | awk 'BEGIN{printf "%-26s %5s %-8s %-8s\n","function","insns","2.7.2","2.8.1"} {printf "%-26s %5s %-8s %-8s\n",$1,($2=="-"?$4:$2),$3,$5}'
