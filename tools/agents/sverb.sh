#!/bin/bash
# sverb.sh <file.c> <stage dump flag e.g. -dS|-dR> <suffix sched|sched2> : verbose scheduler log of first block
f=$1; fl=$2; suf=$3
rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s806/wip/ ~/trw_s806/wip/
cd ~/trw_s806
bash /mnt/d/Projects/ws/s806/tools/sndump.sh $f "$fl -fsched-verbose=5" >/dev/null 2>&1
cd ~/sndump_s806
awk '/^;; ready list initially/{c++} c<=1' s.c.$suf | grep -E 'ready list|blocking|greater potential|queue|launch' | cut -c1-${W:-200}
