#!/usr/bin/env python3
"""Collect the lessons and helper tools of finished worker workspaces into the repository.

usage: python tools/collect_round.py <round title> <workspace dir> [<workspace dir> ...] [--dry]
  - appends each workspace's wip/out/FINDINGS.txt (and wip/FINDINGS*.txt) to docs/FINDINGS_all.txt under a "ROUND ..." heading
  - copies tools/*.py|*.sh|*.ps1 and wip/sh/* of the workspace that the repository does not have yet to tools/agents/
    (a file whose name exists with other content gets the suffix _<workspace name>), and lists them in tools/agents/INDEX.txt
    as "<name> (from <ws>) <first comment line>"
Run it once per workspace only (it skips workspaces already named in docs/FINDINGS_all.txt)."""
import os, re, shutil, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
EXT = ('.py', '.sh', '.ps1')
CRLF, LF = bytes([13, 10]), bytes([10])

def first_comment(path):
    try:
        for l in open(path, encoding='utf-8', errors='replace').read().split('\n')[:12]:
            s = l.strip()
            if s.startswith('#!'): continue
            s = re.sub(r'^(#+|"""|\'\'\'|//|;)\s*', '', s).strip()
            if s: return s[:160]
    except OSError:
        pass
    return ''

def same(a, b):                                           # equal up to line endings
    try: return open(a, 'rb').read().replace(CRLF, LF) == open(b, 'rb').read().replace(CRLF, LF)
    except OSError: return False

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    dry = '--dry' in sys.argv
    title, wss = args[0], args[1:]
    allf = open('docs/FINDINGS_all.txt', encoding='utf-8', errors='replace').read() if os.path.exists('docs/FINDINGS_all.txt') else ''
    index = open('tools/agents/INDEX.txt', encoding='utf-8').read() if os.path.exists('tools/agents/INDEX.txt') else ''
    new_find, new_index, copied = [], [], 0
    for ws in wss:
        name = os.path.basename(os.path.normpath(ws))
        if ('(workspace %s)' % name) in allf or ('(from %s)' % name) in index:
            print('skip', name, '(already collected)'); continue
        texts = []
        for f in ('wip/out/FINDINGS.txt', 'wip/FINDINGS.txt', 'wip/out/findings.txt'):
            p = os.path.join(ws, f)
            if os.path.exists(p): texts.append(open(p, encoding='utf-8', errors='replace').read().rstrip())
        if texts:
            new_find.append('\n=== %s (workspace %s) ===\n%s\n' % (title, name, '\n\n'.join(texts)))
        mentioned = ' '.join(texts)
        cands = [os.path.join(ws, 'tools', f) for f in sorted(os.listdir(os.path.join(ws, 'tools')))] if os.path.isdir(os.path.join(ws, 'tools')) else []
        shd = os.path.join(ws, 'wip', 'sh')
        if os.path.isdir(shd): cands += [os.path.join(shd, f) for f in sorted(os.listdir(shd)) if f in mentioned]      # scratch experiment scripts only when the report names them
        edited = 0
        for p in cands:
            f = os.path.basename(p)
            if not f.endswith(EXT) or not os.path.isfile(p): continue
            if os.path.exists('tools/' + f):                      # the repository's own tool: a workspace copy is the same or an older/edited one
                if not same(p, 'tools/' + f): print('  differs from tools/%s: %s' % (f, p))
                continue
            if os.path.exists('tools/agents/' + f):             # a tool of an earlier round (workers only adapt its paths to their workspace)
                edited += not same(p, 'tools/agents/' + f)
                continue
            if not dry: shutil.copyfile(p, 'tools/agents/' + f)
            new_index.append('%-24s (from %s) %s' % (f, name, first_comment(p)))
            copied += 1
        if edited: print('  %s: %d earlier-round tools edited in place (not collected)' % (name, edited))
    print('findings sections:', len(new_find), ' tools copied:', copied)
    if dry: return
    if new_find: open('docs/FINDINGS_all.txt', 'a', encoding='utf-8', newline='\n').write(''.join(new_find))
    if new_index:
        lines = [l for l in index.split('\n') if l.strip()]
        head, body = [l for l in lines if l.startswith('#')], sorted(l for l in lines if not l.startswith('#'))
        open('tools/agents/INDEX.txt', 'w', encoding='utf-8', newline='\n').write('\n'.join(head + body + new_index) + '\n')

if __name__ == '__main__':
    main()
