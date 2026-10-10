#!/bin/bash
# objfuncs.sh <mode> <src.c> ... : compile with tools/cc.sh in ~/trw and list the global function symbols (offset, size) of each object
cd ~/trw
mode=$1; shift
for f in "$@"; do
  bash tools/cc.sh $mode $f /tmp/objfuncs.o || continue
  echo "== $f"
  mips-linux-gnu-readelf -sW /tmp/objfuncs.o | awk '$4=="FUNC" || ($4=="NOTYPE" && $7!="UND" && $5=="GLOBAL") {print $2, $3, $8}' | sort | head -30
done
