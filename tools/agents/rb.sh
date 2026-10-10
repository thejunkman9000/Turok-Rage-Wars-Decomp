#!/bin/bash
# usage (WSL): bash tools/rb.sh <suffix> [lines]  -> compact RTL of /tmp/s706dump/s.c.<suffix>
python3 /mnt/d/Projects/ws/s706/tools/rtlbrief.py /tmp/s706dump/s.c.$1 | head -${2:-40} | cut -c1-130
