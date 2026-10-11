W=200 bash /mnt/d/Projects/ws/s905/tools/rg.sh ${1:-cse} '.' 200 | sed -n ${2:-28},${3:-60}p
