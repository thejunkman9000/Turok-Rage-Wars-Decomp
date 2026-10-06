#!/usr/bin/env bash
# Compare gcc versions/flags on a set of libultra sources. Prints only non-trivial functions (>=8 insns).
SRCS="osSendMesg.c osRecvMesg.c osJamMesg.c osCreateMesgQueue.c osSetThreadPri.c osStartThread.c osCreateThread.c osDestroyThread.c osSetEventMesg.c __osDequeueThread.c osVirtualToPhysical.c osTimer.c osSetTimer.c osGetThreadPri.c osViSwapBuffer.c osViSetMode.c osViBlack.c osSpTaskYield.c __osViSwapContext.c osAiSetFrequency.c osViSetEvent.c osSetTime.c osGetTime.c osAiGetLength.c osPiStartDma.c osPiRawStartDma.c osSpTaskLoadGo.c"
for cfg in "2.7.2|-O2" "2.7.2.3|-O2" "2.8.1|-O2" "2.8.1|-O2 -fno-delayed-branch" "2.7.2|-O1" "2.7.2|-O3"; do
  v=${cfg%%|*}; f=${cfg#*|}
  python3 tools/lu_match.py $v $f -- $SRCS > /tmp/lu_$$.txt 2>&1
  big=$(awk '$2+0>=8 && $1 !~ /^D_/' /tmp/lu_$$.txt | grep -c EXACT)
  tot=$(awk '$2+0>=8 && $1 !~ /^D_/' /tmp/lu_$$.txt | grep -c insns)
  printf "gcc %-8s %-28s exact (>=8 insns): %s/%s\n" "$v" "$f" "$big" "$tot"
done
