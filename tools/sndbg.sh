#!/bin/bash
# sndbg.sh <their src file> <word index> <rom offset> : compile with the sn pipeline, show instruction + relocation near that word and the ROM words
SRC=$1; W=$2; ROMOFF=$3
cd $HOME/trw
tmp=$(mktemp -d)
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $SRC > $tmp/s.i
$HOME/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 $tmp/s.i -o $tmp/s.s
$HOME/sn/n64link asn64 --as mips-linux-gnu-as -march=vr4300 -mabi=32 -EB --no-pad-sections -mips3 $tmp/s.s -o $tmp/s.o 2>/dev/null
mips-linux-gnu-objdump -dr $tmp/s.o > $tmp/dis.txt 2>/dev/null
cat > $tmp/show.py <<'PY'
import re, sys
dis, w, romoff = sys.argv[1], int(sys.argv[2]) * 4, int(sys.argv[3], 0)
L = open(dis).read().split('\n')
for i, l in enumerate(L):
    m = re.match(r'\s*([0-9a-f]+):\s', l)
    if m and abs(int(m.group(1), 16) - w) <= 12:
        print(l)
        j = i + 1
        while j < len(L) and 'R_MIPS' in L[j]:
            print(L[j]); j += 1
d = open('/mnt/d/Projects/TurokRageWars/baserom.us.v11.z64', 'rb').read()
o = romoff + w
print('rom words', [d[o + k * 4:o + k * 4 + 4].hex() for k in range(-3, 4)])
PY
python3 $tmp/show.py $tmp/dis.txt $W $ROMOFF
