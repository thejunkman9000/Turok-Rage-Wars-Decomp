#!/bin/bash
# waitperm.sh <fn> <maxsecs> : wait until the permuter for <fn> finishes (or maxsecs), then print its best scores
fn=$1; mx=${2:-1500}; t=0
while pgrep -f "permuter.py.*s703_$fn" >/dev/null && [ $t -lt $mx ]; do sleep 20; t=$((t+20)); done
tr "\r" "\n" < $HOME/perm/s703_$fn/run.log | grep -a "new best" | tail -3
date
