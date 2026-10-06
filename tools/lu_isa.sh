#!/usr/bin/env bash
# Try ISA/CPU variants (via LU_ISA) for gcc 2.8.1 / 2.7.2 on osSendMesg/osRecvMesg/osJamMesg.
for v in 2.8.1 2.7.2; do
 for isa in "-mips2 -mgp32 -mfp32" "-mips3 -mgp32 -mfp32" "-mips3 -mgp32 -mfp32 -mcpu=r4000" "-mips2 -mgp32 -mfp32 -mcpu=r4000" "-mips1 -mgp32 -mfp32" "-mips3 -mgp32 -mfp32 -mtune=r4300"; do
   out=$(LU_ISA="$isa" python3 tools/lu_match.py $v -O2 -- osSendMesg.c osRecvMesg.c osJamMesg.c 2>&1)
   if echo "$out" | grep -q 'COMPILE FAIL'; then printf "gcc %-6s %-44s COMPILE FAIL: %s\n" "$v" "$isa" "$(echo "$out" | grep -m1 -o "cc1:[^']*" | cut -c1-60)"; continue; fi
   s=$(echo "$out" | awk '$1=="osSendMesg"{print $4}'); r=$(echo "$out" | awk '$1=="osRecvMesg"{print $4}'); j=$(echo "$out" | awk '$1=="osJamMesg"{print $4}')
   printf "gcc %-6s %-44s Send=%s Recv=%s Jam=%s\n" "$v" "$isa" "${s:--}" "${r:--}" "${j:--}"
 done
done
