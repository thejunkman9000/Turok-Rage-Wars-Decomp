#!/bin/bash
for d in $HOME/perm/s703_func_*; do f=$(basename $d); [ -f $d/run.log ] || continue
 echo "$f: $(tr '\r' '\n' < $d/run.log | grep -E 'base score|new best' | tail -2 | sed 's/\x1b\[[0-9;]*m//g' | tr '\n' ' ') | $(tr '\r' '\n' < $d/run.log | tail -1 | cut -c1-60)"; done
