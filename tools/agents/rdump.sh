#!/bin/bash
# rdump.sh <file.c> <pseudo...> : dump all RTL stages of <file.c> into a fresh dir and run regdump.py on the given pseudos
f=$1; shift
cd /mnt/d/Projects/ws/s902 && bash tools/dumpall.sh $f >/dev/null 2>&1
d=$HOME/dmp902/cur; rm -rf $d; mkdir -p $d
cp ~/sndump_s902/s.c.lreg $d/x.lreg; cp ~/sndump_s902/s.c.greg $d/x.greg
python3 /mnt/d/Projects/ws/s902/tools/regdump.py $d "$@"
