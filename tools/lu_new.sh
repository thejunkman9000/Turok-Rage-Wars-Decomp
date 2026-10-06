#!/usr/bin/env bash
SRCS="osSendMesg.c osRecvMesg.c osJamMesg.c osCreateMesgQueue.c osSetThreadPri.c osStartThread.c osCreateThread.c osDestroyThread.c osSetEventMesg.c osVirtualToPhysical.c osTimer.c osSetTimer.c osGetThreadPri.c osViSwapBuffer.c osViSetMode.c osViBlack.c osSpTaskYield.c __osViSwapContext.c osAiSetFrequency.c osViSetEvent.c osGetTime.c osPiStartDma.c osPiRawStartDma.c osSpTaskLoadGo.c"
for v in 2.8.1 2.91.66 2.95.2; do
  for f in "-O2" "-O1"; do
    python3 tools/lu_match.py $v $f -- $SRCS > /tmp/n_$v.txt 2>&1
    fails=$(grep -c 'COMPILE FAIL' /tmp/n_$v.txt)
    ex=$(awk '$2+0>=8 && $1 !~ /^D_/' /tmp/n_$v.txt | grep -c EXACT)
    tot=$(awk '$2+0>=8 && $1 !~ /^D_/' /tmp/n_$v.txt | grep -c insns)
    s=$(awk '$1=="osSendMesg"{print $4}' /tmp/n_$v.txt); r=$(awk '$1=="osRecvMesg"{print $4}' /tmp/n_$v.txt)
    printf "gcc %-7s %-4s exact>=8: %2s/%-2s  compile-fails: %s  Send=%s Recv=%s\n" $v "$f" $ex $tot $fails "${s:--}" "${r:--}"
    [ "$f" == "-O2" ] && cp /tmp/n_$v.txt /tmp/best_$v.txt
  done
done
echo; echo "first compile error (2.95.2):"; grep -m2 'COMPILE FAIL' /tmp/best_2.95.2.txt | cut -c1-160
