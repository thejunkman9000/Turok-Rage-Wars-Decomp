#!/usr/bin/env bash
# pgo2.sh <fn> <rounds> <secs per round> <jobs> : iterated permuter (restart from the best output each round); run in WSL
fn=$1; rounds=$2; secs=$3; j=${4:-4}
d=s705_$fn
cd ~/permuter
for r in $(seq 1 $rounds); do
  timeout $secs python3 permuter.py ~/perm/$d -j $j --stop-on-zero >/dev/null 2>&1
  best=$(ls ~/perm/$d | grep '^output-' | sed 's/output-\([0-9]*\)-.*/\1 &/' | sort -n | head -1 | cut -d' ' -f2)
  [ -z "$best" ] && { echo "round $r no output" >> ~/perm/$d.pgo.log; continue; }
  sc=${best#output-}; sc=${sc%%-*}
  echo "round $r best $best" >> ~/perm/$d.pgo.log
  mkdir -p ~/perm/$d/best; cp ~/perm/$d/$best/source.c ~/perm/$d/best/r${r}_$sc.c
  if [ "$sc" = "0" ]; then cp ~/perm/$d/$best/source.c ~/perm/$d/EXACT.c; break; fi
  cp ~/perm/$d/$best/source.c ~/perm/$d/base.c
  mkdir -p ~/perm/$d/old; mv ~/perm/$d/output-* ~/perm/$d/old/ 2>/dev/null
done
echo finished >> ~/perm/$d.pgo.log
