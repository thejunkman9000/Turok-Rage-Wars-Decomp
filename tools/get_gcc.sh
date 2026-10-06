#!/usr/bin/env bash
# Download selected old-gcc builds (decompals/old-gcc release 0.17) into tools/gcc/<version>/
set -euo pipefail
REL=0.17
mkdir -p tools/gcc
for v in 2.7.2 2.7.2.3 2.8.1; do
  d=tools/gcc/$v
  if [ -x "$d/cc1" ]; then echo "$v already present"; continue; fi
  mkdir -p "$d"
  curl -fsSL "https://github.com/decompals/old-gcc/releases/download/$REL/gcc-$v.tar.gz" -o "/tmp/gcc-$v.tar.gz"
  tar -xzmf "/tmp/gcc-$v.tar.gz" -C "$d"
  echo "== $v: $(du -sh "$d" | cut -f1)"; ls "$d"
done
sha256sum /tmp/gcc-*.tar.gz
