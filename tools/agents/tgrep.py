import sys, json, re
p = '/mnt/c/Users/johns/.claude/projects/C--Users-johns-AppData-Roaming-Claude-scratch-workspaces-0886a519-e2d3-45d7-b74b-acfc0bf4a3d7-d7eb23db-7846-4b90-b626-9f4ade751457-scratch-2026-10-06-962eaa/71f0334f-8c7c-401b-a973-891ee9e937f0/subagents/agent-aa265a972161fbf0f.jsonl'
pat = re.compile(sys.argv[1])
ctx = int(sys.argv[2]) if len(sys.argv) > 2 else 300
maxn = int(sys.argv[3]) if len(sys.argv) > 3 else 10
n = 0
for ln, line in enumerate(open(p, encoding='utf-8')):
    try: d = json.loads(line)
    except Exception: continue
    def texts(o):
        if isinstance(o, str): yield o
        elif isinstance(o, list):
            for x in o: yield from texts(x)
        elif isinstance(o, dict):
            for k, v in o.items(): yield from texts(v)
    for t in texts(d):
        for m in pat.finditer(t):
            s = max(0, m.start() - ctx); e = min(len(t), m.end() + ctx)
            print(f'--- line {ln} pos {m.start()} ---')
            print(t[s:e])
            n += 1
            if n >= maxn: sys.exit()
