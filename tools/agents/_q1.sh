for p in rtl cse; do echo "== $p"; W=200 bash /mnt/d/Projects/ws/s905/tools/rg.sh $p 'mem \(plus:SI r80 (12|16)\)' 30; done
