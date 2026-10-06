#!/usr/bin/env bash
# compact asm listing of hasm functions: tools/asmv.sh name [name...]
for n in "$@"; do
  echo "=== $n"
  f=$(ls src/libultra/$n.s src/ovl_a/$n.s 2>/dev/null | head -1)
  grep -E "^\s+/\*|^\s+\.L|^\s+[a-z]" "$f" | grep -v "^\s*\.\(set\|section\|include\)" | sed -E 's#/\* *[0-9A-F]+ *[0-9A-F]+ *[0-9A-F]+ *\*/ *##; s#^\s+##'
done
