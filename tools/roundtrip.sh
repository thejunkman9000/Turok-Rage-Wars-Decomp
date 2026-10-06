#!/usr/bin/env bash
# Round-trip check: assemble splat's output, link it, and compare against the base ROM.
# Run from the project root inside WSL:  bash tools/roundtrip.sh
set -euo pipefail

PFX=mips-linux-gnu
NAME=turok_ragewars
ROM=baserom.us.v11.z64
AS_FLAGS="-EB -march=vr4300 -mabi=32 -mno-pdr -W -I include"

rm -rf build
mkdir -p build/asm build/assets

for s in asm/*.s; do
  o=build/asm/$(basename "${s%.s}").o
  $PFX-as $AS_FLAGS -o "$o" "$s"
done

for b in assets/*.bin; do
  o=build/assets/$(basename "${b%.bin}").o
  $PFX-ld -r -b binary "$b" -o "$o"
done

$PFX-ld -nostdlib --no-check-sections \
  -T $NAME.ld -T hardware_regs.ld -T extra_syms.ld -T undefined_syms_auto.txt -T undefined_funcs_auto.txt \
  -Map build/$NAME.map -o build/$NAME.elf

$PFX-objcopy -O binary build/$NAME.elf build/$NAME.z64

echo "built:    $(stat -c %s build/$NAME.z64) bytes"
echo "original: $(stat -c %s $ROM) bytes"
if cmp -s build/$NAME.z64 $ROM; then
  echo "OK: byte-identical to $ROM"
else
  echo "MISMATCH:"; cmp build/$NAME.z64 $ROM | head -3
  echo "differing bytes: $(cmp -l build/$NAME.z64 $ROM | wc -l)"
fi
