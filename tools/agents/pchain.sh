#!/usr/bin/env bash
# pchain.sh mins jobs fn1 fn2 ... : run permuters sequentially (setup must exist) in the background
mins=$1; j=$2; shift 2
cd $HOME/permuter
for fn in "$@"; do
  timeout $((mins*60)) python3 permuter.py $HOME/perm/s704_$fn -j $j --stop-on-zero > $HOME/perm/s704_$fn/run2.log 2>&1 < /dev/null
done
