#!/usr/bin/env bash
# List libreultra source files (path + size) to find libultra os*.c sources.
curl -fsSL "https://api.github.com/repos/mountainflaw/libreultra/git/trees/HEAD?recursive=1" -o /tmp/lu_tree.json || { echo "curl failed"; exit 1; }
python3 - <<'EOF'
import json
t = json.load(open('/tmp/lu_tree.json'))
files = [x for x in t["tree"] if x["type"] == "blob" and x["path"].startswith("lib/") and x["path"].endswith((".c", ".s", ".S"))]
print(len(files), "source files; truncated:", t.get("truncated"))
for x in files: print(f'{x["size"]:6d}  {x["path"]}')
EOF
