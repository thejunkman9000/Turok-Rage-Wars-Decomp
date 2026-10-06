#!/usr/bin/env bash
# Report which decomp build tools are present in this WSL distro.
for t in mips-linux-gnu-as mips-linux-gnu-ld mips-linux-gnu-objdump mips-linux-gnu-gcc gcc python3 pip3 git ninja cmake clang make unzip; do
  printf "%-26s %s\n" "$t" "$(command -v "$t" || echo MISSING)"
done
echo
uname -r
python3 --version
mips-linux-gnu-as --version 2>/dev/null | head -1
