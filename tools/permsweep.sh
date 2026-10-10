#!/bin/bash
# list (and with KILL=<regex> kill) running decomp-permuter processes by the directory they run in
# usage: bash tools/permsweep.sh            -> counts per working directory
#        KILL='trw_(s401|s403)' bash tools/permsweep.sh
for p in $(pgrep -f permuter.py); do
  c=$(readlink /proc/$p/cwd 2>/dev/null)
  a=$(tr '\0' ' ' < /proc/$p/cmdline 2>/dev/null)
  key="$c $a"
  if [ -n "$KILL" ] && echo "$key" | grep -Eq "$KILL"; then kill $p 2>/dev/null; echo "killed $p ($c)"; else echo "$c"; fi
done | sed -E 's#(/trw_[a-z0-9]+).*#\1#' | sort | uniq -c | sort -rn | head -30
