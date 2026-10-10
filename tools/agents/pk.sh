#!/bin/bash
# pk.sh fn : kill permuter runs for fn
for p in $(ps -eo pid,args | grep "[p]ermuter.py.*s703_$1 " | awk '{print $1}'); do kill $p; done
