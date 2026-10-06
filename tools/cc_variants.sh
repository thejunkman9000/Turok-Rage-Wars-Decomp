#!/usr/bin/env bash
# Try flag variants and report whether each reproduces the ROM bytes of test/f1.c (14 words from ROM 0x1100).
V=${1:-2.7.2}
want="27bdffe8 afbf0014 0c000000 afb00010 00408021 2404fffe 0c000000 02042024 32020001 8fbf0014 8fb00010 27bd0018 03e00008"
for flags in "" "-fno-delayed-branch" "-mips3" "-mcpu=r4000" "-mips1" "-O1" "-O3" "-O2 -fno-delayed-branch -mips3" "-mno-gpopt" "-mno-abicalls -mrnames"; do
  out=$(bash tools/cc_try.sh $V test/f1.c $flags 2>&1 | grep -E '^ +[0-9a-f]+:' | awk '{print $2}' | tr '\n' ' ')
  # relocations make jal targets 0c000000; compare
  if [ "$(echo $out)" == "$want" ]; then r="MATCH"; else r="differs"; fi
  printf "%-34s %s\n" "[${flags:-default}]" "$r"
  [ "$r" == differs ] && echo "    $(echo $out | cut -c1-140)"
done
