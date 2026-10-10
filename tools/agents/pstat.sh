#!/bin/bash
for f in "$@"; do echo "== $f"; wsl -d Ubuntu-24.04 -- bash -c "tr '\r' '\n' < ~/perm/s705_$f/run.log | grep -E 'base score|new best|Found|zero' | tail -4; tr '\r' '\n' < ~/perm/s705_$f/run.log | tail -1 | cut -c1-80; ls ~/perm/s705_$f | grep output"; done
