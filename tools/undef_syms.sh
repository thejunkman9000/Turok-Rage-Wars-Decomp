#!/usr/bin/env bash
# List distinct undefined symbols from the last link log (/tmp/rt.log).
grep -o "undefined reference to \`[A-Za-z0-9_]*'" /tmp/rt.log | sed "s/.*\`//; s/'//" | sort -u | tr '\n' ' '
echo
echo "total undefined-reference lines: $(grep -c 'undefined reference' /tmp/rt.log)"
