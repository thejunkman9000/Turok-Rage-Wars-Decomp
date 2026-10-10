import sys, json
p = '/mnt/c/Users/johns/.claude/projects/C--Users-johns-AppData-Roaming-Claude-scratch-workspaces-0886a519-e2d3-45d7-b74b-acfc0bf4a3d7-d7eb23db-7846-4b90-b626-9f4ade751457-scratch-2026-10-06-962eaa/71f0334f-8c7c-401b-a973-891ee9e937f0/subagents/agent-aa265a972161fbf0f.jsonl'
lo, hi = int(sys.argv[1]), int(sys.argv[2])
maxc = int(sys.argv[3]) if len(sys.argv) > 3 else 6000
for ln, line in enumerate(open(p, encoding='utf-8')):
    if ln < lo or ln > hi: continue
    try: d = json.loads(line)
    except Exception: continue
    msg = d.get('message', {})
    c = msg.get('content')
    role = msg.get('role')
    if isinstance(c, str):
        print(f'--- [{ln}] {role} text: {c[:maxc]}'); continue
    for part in c or []:
        t = part.get('type')
        if t == 'text': print(f'--- [{ln}] {role} text: {part["text"][:maxc]}')
        elif t == 'tool_use': print(f'--- [{ln}] tool_use: {json.dumps(part["input"])[:maxc]}')
        elif t == 'tool_result':
            cc = part.get('content')
            if isinstance(cc, list): cc = '\n'.join(x.get('text', '') for x in cc if isinstance(x, dict))
            print(f'--- [{ln}] tool_result: {str(cc)[:maxc]}')
