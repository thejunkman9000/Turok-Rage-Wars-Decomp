#!/usr/bin/env bash
# Clone libreultra (public libultra decomp, headers + C sources) into ~/libreultra and test-compile one file.
set -e
cd ~
[ -d libreultra ] || git clone --depth 1 https://github.com/mountainflaw/libreultra.git
cd libreultra
git log --oneline | head -1
ls include | head -20
echo "--- test compile osSendMesg.c with gcc 2.7.2"
G=/mnt/d/Projects/TurokRageWars/tools/gcc/2.7.2
cd /tmp && $G/gcc -B$G/ -meb -mips2 -mgp32 -mfp32 -G 0 -O2 -mno-abicalls -fno-pic \
   -I ~/libreultra/include -I ~/libreultra/include/PR -D_LANGUAGE_C -DTARGET_N64 -D_FINALROM -DNDEBUG \
   -S -o /tmp/sendmesg.s ~/libreultra/lib/src/osSendMesg.c 2>&1 | head -20
wc -l /tmp/sendmesg.s
