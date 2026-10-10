#!/bin/bash
# usage: tools/fc.sh listfile  (runs fchk with CHKSIDE) ; then python tools/sd.py <fn>
cd /d/Projects/ws/s703
MSYS_NO_PATHCONV=1 wsl -d Ubuntu-24.04 -- env CHKSIDE=1 bash /mnt/d/Projects/ws/s703/tools/fchk.sh $1 2>&1 | grep -v SyntaxWarning
