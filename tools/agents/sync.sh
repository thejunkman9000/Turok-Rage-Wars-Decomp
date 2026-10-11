#!/usr/bin/env bash
# sync.sh : refresh include/, wip/, tools/ into the WSL build tree ~/trw_s906 (fast)
SRC=/mnt/d/Projects/ws/s906; R=$HOME/trw_s906
mkdir -p $R/wip
rsync -a $SRC/include/ $R/include/
rsync -a --exclude='_v_*' --exclude='vb/' $SRC/wip/ $R/wip/
rsync -a $SRC/tools/ $R/tools/ --exclude=gcc
