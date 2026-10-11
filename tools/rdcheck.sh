#!/bin/bash
# rdcheck.sh [func ...] : run the rodata doctor (tools/rodoc.py) on the wip/rd/<func>.c files listed in wip/rd/list.txt (or only on the named functions),
# with the flags and ro= piece of the list line / the worker's results line.  Run in WSL.
SRC=/mnt/d/Projects/TurokRageWars; DST=$HOME/trw
mkdir -p "$DST/wip/rd"
rsync -a "$SRC/include/" "$DST/include/"
rsync -a "$SRC/wip/rd/" "$DST/wip/rd/"
cp "$SRC/tools/rodoc.py" "$DST/tools/rodoc.py"
cd "$DST" || exit 1
want="$*"
while read -r src fn rom flags; do
  [ -z "$fn" ] && continue
  if [ -n "$want" ] && ! echo " $want " | grep -q " $fn "; then continue; fi
  res=""
  for r in /mnt/d/Projects/ws/*/wip/out/results.txt; do grep -q "^$fn .*EXACT" "$r" 2>/dev/null && res=$r; done
  ro=$(grep -h "^$fn .*EXACT" "$res" 2>/dev/null | tail -1 | grep -o 'ro=0x[0-9A-Fa-f]*:[0-9]*' | head -1)
  mode=sn
  case " $flags " in *" -fno-builtin "*) mode=$mode+nb;; esac
  case " $flags " in *" @SN272 "*) mode=sn272;; esac
  echo "== $fn mode=$mode ${ro:-ro=-}"
  if [ -n "$ro" ]; then
    off=${ro#ro=}; size=${off#*:}; off=${off%%:*}
    python3 tools/rodoc.py "$src" "$mode" "$off" "$size"
  else
    python3 tools/rodoc.py "$src" "$mode" 0x0 0 | head -3
  fi
done < "$SRC/wip/rd/list.txt"
