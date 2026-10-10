#!/usr/bin/env bash
# psn_sync.sh fn file [xf] : sync wip/include to ~/trw_s703 then set up the permuter dir
SRC=/mnt/d/Projects/ws/s703; DST=$HOME/trw_s703
rsync -a $SRC/include/ $DST/include/; rsync -a $SRC/src/ $DST/src/ ; rsync -a --exclude='_v_*' $SRC/wip/ $DST/wip/
rsync -a $SRC/tools/ $DST/tools/
cd $DST && bash tools/psn.sh "$@"
