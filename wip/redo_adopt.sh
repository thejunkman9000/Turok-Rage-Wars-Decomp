#!/bin/bash
cd /d/Projects/TurokRageWars
v=$1
sed -i '/^hasm_/d' versions/$v/manifest.txt
rm -f versions/$v/src/*/hasm_*.s
wip/full_adopt.sh $v $2
