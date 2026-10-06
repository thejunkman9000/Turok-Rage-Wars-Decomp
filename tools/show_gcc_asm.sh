#!/usr/bin/env bash
# Show the raw gcc output (.s) for a libultra file around a pattern. usage: show_gcc_asm.sh <file.c> <grep-pattern> [ctx]
G=/mnt/d/Projects/TurokRageWars/tools/gcc/${GCC_VER:-2.8.1}
mkdir -p /tmp/sg && cd /tmp/sg && cp ~/libreultra/lib/src/*.h . 2>/dev/null; cp ~/libreultra/lib/src/$1 t.c
$G/gcc -B$G/ -meb -mips2 -mgp32 -mfp32 -G 0 -mno-abicalls -fno-pic ${FLAGS:--O2} -I ~/libreultra/include -I ~/libreultra/include/PR -I ~/libreultra/lib/src -D_LANGUAGE_C -DTARGET_N64 -D_FINALROM -DNDEBUG -S -o t.s t.c
grep -n -B${3:-4} -A${3:-4} -E "$2" t.s | head -${4:-60}
