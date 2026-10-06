#!/usr/bin/env bash
# Sweep gcc versions/flags on the message-queue functions; print exact counts + best score for osSendMesg.
SRCS="osSendMesg.c osRecvMesg.c osJamMesg.c osViSetMode.c osPiStartDma.c osSetEventMesg.c osCreateMesgQueue.c osViBlack.c osViSwapBuffer.c osViSetEvent.c"
for v in 2.7.2 2.8.1; do
 for f in "-O2" "-O1" "-O3" "-O2 -fno-schedule-insns" "-O2 -fno-schedule-insns2" "-O2 -mcpu=r4000" "-O2 -fno-strength-reduce" "-O2 -fno-delayed-branch" "-O2 -fno-rerun-cse-after-loop" "-O2 -fno-gcse"; do
   out=$(python3 tools/lu_match.py $v $f -- $SRCS 2>&1)
   ex=$(echo "$out" | awk '$2+0>=8' | grep -c EXACT)
   send=$(echo "$out" | awk '$1=="osSendMesg"{print $4}')
   recv=$(echo "$out" | awk '$1=="osRecvMesg"{print $4}')
   printf "gcc %-6s %-30s exact>=8: %s   osSendMesg=%s osRecvMesg=%s\n" "$v" "$f" "$ex" "${send:--}" "${recv:--}"
 done
done
