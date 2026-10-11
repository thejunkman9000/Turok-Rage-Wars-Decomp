#!/bin/bash
# cse1.sh file.c : cpp + cc1 -ds only; print RTL mem(o+12) / mem(o+276) references after cse1
D=~/dd_c1; rm -rf $D; mkdir -p $D
rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s905/wip/ ~/trw_s905/wip/ 2>/dev/null
rsync -a /mnt/d/Projects/ws/s905/include/ ~/trw_s905/include/
cd ~/trw_s905 && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I include -I include/their $1 > $D/a.i
cd $D && ~/sn/cc1_281 -quiet -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mgp32 -mfp64 -mno-fix4300 -ds a.i -o a.s 2>&1 | grep -v warning | head -3
python3 /mnt/d/Projects/ws/s905/tools/rtlc.py $D/a.i.cse 0 100000 | cut -c1-170 | grep -E 'plus:SI r80 (12|16|272|276)\)' 
