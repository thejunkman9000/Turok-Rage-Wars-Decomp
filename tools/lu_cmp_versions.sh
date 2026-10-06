#!/usr/bin/env bash
# Compare gcc versions on libultra after assembler-compat fixes. Prints exact counts (>=8 insns) and which functions.
cd /mnt/d/Projects/TurokRageWars
SRCS="osSendMesg.c osRecvMesg.c osJamMesg.c osCreateMesgQueue.c osSetThreadPri.c osStartThread.c osCreateThread.c osDestroyThread.c osSetEventMesg.c osVirtualToPhysical.c osTimer.c osSetTimer.c osGetThreadPri.c osViSwapBuffer.c osViSetMode.c osViBlack.c osSpTaskYield.c __osViSwapContext.c osAiSetFrequency.c osViSetEvent.c osGetTime.c osPiStartDma.c osPiRawStartDma.c osSpTaskLoadGo.c osSetTime.c osAiGetLength.c"
for v in ${VERSIONS:-2.7.2 2.7.2.3 2.8.1 2.91.66 2.95.2}; do
  python3 tools/lu_match.py $v ${FLAGS:--O3 -fforce-addr -fno-builtin -mcpu=r4300} -- $SRCS > /tmp/c_$v.txt 2>&1
  ex=$(awk '$2+0>=8 && $1 !~ /^D_/' /tmp/c_$v.txt | grep -c EXACT)
  tot=$(awk '$2+0>=8 && $1 !~ /^D_/' /tmp/c_$v.txt | grep -c insns)
  printf "gcc %-8s exact(>=8 insns): %2s/%-2s : %s\n" "$v" "$ex" "$tot" "$(awk '$2+0>=8 && $1 !~ /^D_/ && /EXACT/{printf "%s ", $1}' /tmp/c_$v.txt)"
done
