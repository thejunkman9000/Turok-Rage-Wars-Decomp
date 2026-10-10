#!/bin/bash
# stages.sh <file.c> <from> <to> stage...   : dump + show listed stages
f=$1; from=$2; to=$3; shift 3
bash /mnt/d/Projects/ws/s806/wip/sh/dumpall.sh $f
for s in "$@"; do echo "=== $s"; bash /mnt/d/Projects/ws/s806/wip/sh/show.sh $s $from $to; done
