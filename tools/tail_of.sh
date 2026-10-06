#!/usr/bin/env bash
# Compile a C file (libultra flags) and print the last N instructions of each function.
# usage: bash tools/tail_of.sh <file.c> [N]    (needs ~/trw synced: tools/wsl_sync.sh)
cd ~/trw; N=${2:-12}
cp "$1" /tmp/tail_in.c
bash tools/cc.sh lu /tmp/tail_in.c /tmp/tail_out.o 2>&1 | grep -v 'Warning: float' || true
mips-linux-gnu-objdump -dz -M no-aliases,reg-names=numeric /tmp/tail_out.o | awk -v N=$N '
  function flush(  i, s) { printf "== %s\n", name; s = (cnt > N) ? cnt - N : 0; for (i = s; i < cnt; i++) if (buf[i] !~ /^sll \$0,\$0,0x0/) print "   " buf[i] }
  /^[0-9a-f]+ <.*>:/ { if (name != "") flush(); name = $2; cnt = 0; next }
  NF >= 3 && $1 ~ /:$/ { buf[cnt++] = $3 " " $4 " " $5 }
  END { flush() }'
