#!/usr/bin/env bash
# usage (WSL): bash tools/psetup.sh <fn> <wip/c/x.c> <rom hex> <ninsns> [cc1 flags]
cd /mnt/d/Projects/ws/s702
echo "wip/c/dummy $1 $3" > /dev/null
bash tools/fk.sh <(echo "$2 $1 $3 @SN") >/dev/null 2>&1
cd $HOME/trw_s702
cp /mnt/d/Projects/ws/s702/tools/{perm_sn.sh,permsn_cc.sh,permsn_link.py,perm_strip.py,sn_expand.py} tools/
fn=$1; c=$2; rom=$3; n=$4; shift 4
bash tools/perm_sn.sh $fn $c $rom $n "$@"
