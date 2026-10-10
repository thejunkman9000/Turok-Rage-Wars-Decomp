#!/usr/bin/env bash
# ad.sh <file rel ws> <fn> <rom> <n> [xflags] [-v]  (WSL)
SRC=/mnt/d/Projects/ws/s704; R=$HOME/trw_s704
rsync -a $SRC/include/ $R/include/; rsync -a --exclude='_v_*' $SRC/wip/ $R/wip/; rsync -a $SRC/tools/ $R/tools/
cd $R && python3 $SRC/tools/ad.py "$@"
