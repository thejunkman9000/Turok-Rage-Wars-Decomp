#!/usr/bin/env bash
# permuter queue (WSL): bash tools/pq.sh <jobs> <secs> fn:file:rom:ninsn [...]   (runs strictly one permuter at a time)
jobs=$1; secs=$2; shift 2
for spec in "$@"; do
  IFS=: read fn file rom n <<< "$spec"
  bash /mnt/d/Projects/ws/s702/tools/psetup.sh $fn $file $rom $n > $HOME/perm_s702_setup_$fn.log 2>&1
  cp /mnt/d/Projects/ws/s702/tools/prun.sh $HOME/trw_s702/tools/
  bash $HOME/trw_s702/tools/prun.sh $fn $secs $jobs
  echo "done $fn" >> $HOME/perm_s702_queue.log
done
