#!/usr/bin/env bash
d=$HOME/perm/s704_$1
tr '\r' '\n' < $d/run.log | grep -a 'base score\|new best' | tail -3 | cut -c1-150
tr '\r' '\n' < $d/run.log | tail -1 | cut -c1-120
ls $d | grep output
