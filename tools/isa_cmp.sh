#!/usr/bin/env bash
# Compare exact-match counts of the libreultra scan for different ISA option sets (via LU_ISA).
cd /mnt/d/Projects/TurokRageWars
for isa in "-mips2 -mgp32 -mfp32" "-mips3 -mgp32"; do
  LU_ISA="$isa" bash tools/lu_scan_all.sh > /tmp/isa_scan.txt 2>&1
  ex=$(grep -c EXACT /tmp/isa_scan.txt)
  big=$(awk '$2+0>=8 && /EXACT/' /tmp/isa_scan.txt | grep -vc ' D_')
  printf "ISA [%s]: exact=%s  exact(>=8 insns)=%s\n" "$isa" "$ex" "$big"
  cp /tmp/isa_scan.txt "/tmp/isa_scan_$(echo $isa | tr -d ' -').txt"
done
echo "--- functions exact (>=8 insns) only with -mips3:"
diff <(awk '$2+0>=8 && /EXACT/ {print $1}' /tmp/isa_scan_mips2mgp32mfp32.txt | sort) <(awk '$2+0>=8 && /EXACT/ {print $1}' /tmp/isa_scan_mips3mgp32.txt | sort)
