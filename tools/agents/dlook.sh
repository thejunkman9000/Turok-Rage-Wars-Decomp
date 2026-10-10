#!/bin/bash
# dlook.sh pass pattern ctx
cd $HOME/dmp703
grep -n -B${3:-3} -A${3:-3} "$2" t.c.$1 | head -${4:-80}
