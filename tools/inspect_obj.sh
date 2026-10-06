#!/usr/bin/env bash
# Show how .L004002AC ended up in the assembled page object.
P=mips-linux-gnu
echo "== nm (local labels)"; $P-nm build/asm/160000.o | grep -i 'L004002AC' || echo "(no symbol .L004002AC in symtab)"
echo "== relocs referencing it"; $P-readelf -rW build/asm/160000.o | grep -i 'L004002AC' | head -3
echo "== reloc at +0x44"; $P-readelf -rW build/asm/160000.o | grep -E '^0*0*44 ' | head
echo "== entry.o: any .L symbols in reloc table?"; $P-readelf -rW build/asm/entry.o | grep -c '\.L00' || true
echo "== entry.o first 3 j-to-label relocs"; $P-readelf -rW build/asm/entry.o | grep 'R_MIPS_26' | head -3
