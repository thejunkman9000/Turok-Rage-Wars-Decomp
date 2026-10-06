#!/usr/bin/env bash
# Debug: what does gcc 2.7.2 + gas emit for osSendMesg.c?
G=/mnt/d/Projects/TurokRageWars/tools/gcc/2.7.2
mkdir -p /tmp/dbg && cd /tmp/dbg && cp ~/libreultra/lib/src/osSendMesg.c .
$G/gcc -B$G/ -meb -mips2 -mgp32 -mfp32 -G 0 -mno-abicalls -fno-pic -O2 -I ~/libreultra/include -I ~/libreultra/include/PR -I ~/libreultra/lib/src -D_LANGUAGE_C -DTARGET_N64 -D_FINALROM -DNDEBUG -S -o osSendMesg.s osSendMesg.c; echo "gcc rc=$?"
mips-linux-gnu-as -EB -march=vr4300 -mabi=32 -mno-pdr -W -o osSendMesg.o osSendMesg.s; echo "as rc=$?"
mips-linux-gnu-readelf -sW osSendMesg.o | head -20
mips-linux-gnu-objcopy -O binary -j .text osSendMesg.o o.bin; ls -l o.bin
