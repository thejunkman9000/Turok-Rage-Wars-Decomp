#!/bin/bash
# vbrun.sh <glob-pattern relative to wip/v418> [jobs]: rank variants with the aligned metric
cd /mnt/d/Projects/ws/s902 && rsync -a wip/ ~/trw_s902/wip/ --exclude='_v_*' >/dev/null
cd ~/trw_s902
python3 tools/vb.py func_00418224 0x186224 --flags '@SN' --top ${3:-12} --jobs ${2:-3} $(ls wip/v418/$1) 2>&1 | grep -v SyntaxWarning | tail -${3:-14}
