#!/bin/bash
# regstat.sh <dumpdir> <pseudo>... : local-alloc stats lines for the given pseudos
d=$1; shift
for r in "$@"; do grep -E "^Register $r used" $d/a.i.lreg; done
