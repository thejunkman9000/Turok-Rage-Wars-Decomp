#!/usr/bin/env bash
# pdiff.sh <fn> : show diffs of permuter outputs
for d in ~/perm/s904_$1/output-*; do echo "=== $d"; head -${N:-60} $d/diff.txt; done
