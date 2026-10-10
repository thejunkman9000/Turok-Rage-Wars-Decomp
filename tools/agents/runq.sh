#!/usr/bin/env bash
# runq.sh <fn:rounds:secs:jobs> ...   run pgo2 sequentially (after any running s705 permuter finishes)
while pgrep -f "permuter.py /home/johns/perm/s705" >/dev/null; do sleep 10; done
for spec in "$@"; do
  IFS=: read fn rounds secs jobs <<< "$spec"
  bash /mnt/d/Projects/ws/s705/tools/pgo2.sh $fn $rounds $secs $jobs
done
