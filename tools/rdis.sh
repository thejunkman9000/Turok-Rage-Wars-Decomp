#!/usr/bin/env bash
# disassemble N instructions of the US v1.1 ROM at ROM offset $1 (hex); shown address = $3 (hex, optional, default = ROM offset)
ROMF=${ROM:-baserom.us.v11.z64}      # run from the workspace root
off=$(( $1 )); n=$2; vma=$(( ${3:-$1} ))
mips-linux-gnu-objdump -D -b binary -m mips:4300 -EB --adjust-vma=$(( vma - off )) --start-address=$(( vma )) --stop-address=$(( vma + 4*n )) -M no-aliases,reg-names=32 "$ROMF" 2>&1 | sed -n '7,$p'
