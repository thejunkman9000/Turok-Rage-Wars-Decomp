#!/usr/bin/env bash
# Compile a C file with the project's pipeline (libultra mode) and print its disassembly.
# usage (from PowerShell): wsl -d Ubuntu-24.04 -- bash /mnt/d/Projects/TurokRageWars/tools/objdis.sh <file.c> [lu|game]
# The file may be anywhere (e.g. /tmp); it is compiled with ~/trw's include/ and tools/ (run wsl_build.sh first).
set -e
cd ~/trw
mode=${2:-lu}
bash tools/cc.sh "$mode" "$1" /tmp/objdis.o 2>&1 | grep -v 'Warning: float register' || true
mips-linux-gnu-objdump -dz -M no-aliases,reg-names=numeric /tmp/objdis.o | sed -n '/>:$/,$p' | cut -f1,3- | grep -v '^$'
