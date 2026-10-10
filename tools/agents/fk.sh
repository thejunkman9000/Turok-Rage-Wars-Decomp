#!/usr/bin/env bash
# fast chk: copy only the files named in the list (+include/), then run chk.py.  usage (WSL): bash tools/fk.sh <listfile>
SRC=/mnt/d/Projects/ws/s702; DST=$HOME/trw_s702
mkdir -p $DST/wip
rsync -a $SRC/include/ $DST/include/
cd $SRC
grep -v '^\s*#' "$1" | awk 'NF>=3{print $1}' | sort -u | while read p; do [ -f "$p" ] && { mkdir -p "$DST/$(dirname $p)"; cp "$p" "$DST/$p"; }; done
python3 tools/chk.py "$1" 2>&1 | grep -v SyntaxWarning
