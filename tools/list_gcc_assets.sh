#!/usr/bin/env bash
# List assets of the latest decompals/old-gcc release (name, size, URL).
curl -fsSL https://api.github.com/repos/decompals/old-gcc/releases/latest -o /tmp/oldgcc.json || { echo "curl failed"; exit 1; }
python3 - <<'EOF'
import json
r = json.load(open('/tmp/oldgcc.json'))
print("release:", r.get("tag_name"), r.get("published_at"))
for a in r["assets"]:
    print(f'{a["size"]/1e6:6.2f} MB  {a["name"]}')
EOF
