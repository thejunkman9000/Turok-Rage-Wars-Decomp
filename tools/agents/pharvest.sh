#!/usr/bin/env bash
# pharvest.sh <fn> <work.c> <rom> [flags]  (WSL): splice each permuter output (best first) into work.c, aligned-diff it; leaves wip/_rv/ph<k>.c
fn=$1; work=$2; rom=$3; shift 3
cd /mnt/d/Projects/ws/s702
mkdir -p wip/_rv
i=0
: > wip/_rv/phlist.txt
for d in $(ls -d $HOME/perm/s702_$fn/output-* 2>/dev/null | sort -t- -k2 -n | head -${PH_N:-5}); do
  cp $d/source.c wip/_rv/ph_src_$i.c
  python3 tools/splice.py $work wip/_rv/ph_src_$i.c $fn wip/_rv/ph$i.c 2>/dev/null || { echo "splice fail $d"; i=$((i+1)); continue; }
  echo "wip/_rv/ph$i.c $fn $rom ${*:-@SN}" >> wip/_rv/phlist.txt
  echo "ph$i = $d"
  i=$((i+1))
done
bash tools/fk.sh wip/_rv/phlist.txt 2>&1 | grep -v Warn
