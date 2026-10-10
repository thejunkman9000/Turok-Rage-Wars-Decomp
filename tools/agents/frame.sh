#!/bin/bash
# frame.sh file.c [xflags] : compile with the @SN toolchain; print frame size and the sp-relative offsets used
f=$1; shift
R=$HOME/trw_s703; SN=$HOME/sn
rsync -a /mnt/d/Projects/ws/s703/include/ $R/include/; rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s703/wip/ $R/wip/
mkdir -p $HOME/dmp703; cd $R
cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $f > $HOME/dmp703/f.c
cd $HOME/dmp703
$SN/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 "$@" f.c -o f.s
python3 - <<'PY'
import re,collections
s=open('f.s').read()
m=re.search(r'addiu\s+\$sp,\$sp,-(\d+)',s)
print('frame',m.group(1) if m else '?')
c=collections.Counter()
for o in re.findall(r'(-?\d+)\(\$sp\)',s): c[int(o)]+=1
for o in re.findall(r'addiu\s+\$\w+,\$sp,(\d+)',s): c[int(o)]+=1000
print(' '.join('%X%s'%(k,'*' if v>=1000 else '') for k,v in sorted(c.items())))
PY
