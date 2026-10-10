#!/bin/bash
# dumpall.sh <file.c rel to ~/trw_s806 or ws>  : sync ws wip/ to ~/trw_s806, dump all RTL stages to ~/sndump_s806
rsync -a --exclude='_v_*' /mnt/d/Projects/ws/s806/wip/ ~/trw_s806/wip/
rsync -a /mnt/d/Projects/ws/s806/include/ ~/trw_s806/include/
cd ~/trw_s806
bash /mnt/d/Projects/ws/s806/tools/sndump.sh $1 "-dr -dj -ds -dL -dt -dc -dS -dl -dg -dR -dJ -df ${DF:-}" >/dev/null 2>&1
