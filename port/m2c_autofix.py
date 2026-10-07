"""Iteratively repair common m2c output problems using clang's own diagnostics:
   - use of undeclared identifier X        -> declare 's32 X = 0;' at the top of the enclosing function
   - too few arguments, expected N have M  -> append zero arguments at the call
Returns the repaired text (or the last attempt)."""
import re, subprocess
DEF = re.compile(r'^[A-Za-z_][\w \t\*]*\([^;]*\)\s*\{\s*$')
def fix(text, compile_cmd, path, rounds=30):
    for _ in range(rounds):
        open(path, 'w', newline='\n').write(text)
        r = subprocess.run(compile_cmd, capture_output=True, text=True)
        if r.returncode == 0: return text, True
        lines = text.split('\n'); changed = False
        for m in re.finditer(r':(\d+):(\d+): error: (.*)', r.stderr):
            ln, col, msg = int(m.group(1)) - 1, int(m.group(2)) - 1, m.group(3)
            mu = re.match(r"use of undeclared identifier '(\w+)'", msg)
            if mu:
                name = mu.group(1)
                k = ln
                while k >= 0 and not DEF.match(lines[k]): k -= 1
                if k >= 0 and f' {name} ' not in ' '.join(lines[k:k + 3]) and f'{name} = 0;' not in lines[k + 1]:
                    lines[k] = lines[k] + f' s32 {name} = 0;'; changed = True
                continue
            if msg.startswith('indirection requires pointer operand') and ln < len(lines):
                s = lines[ln]; k = s.rfind('*', 0, col + 1)
                if k >= 0 and not s[k + 1:].startswith('(s32 *)'):
                    lines[ln] = s[:k + 1] + '(s32 *)' + s[k + 1:]; changed = True
                continue
            mf = re.match(r'too few arguments to function call, expected (\d+), have (\d+)', msg)
            if mf and ln < len(lines):
                need = int(mf.group(1)) - int(mf.group(2)); s = lines[ln]
                i = s.find('(', col)
                if i < 0: continue
                depth = 0; j = i
                while j < len(s):
                    if s[j] == '(': depth += 1
                    elif s[j] == ')':
                        depth -= 1
                        if depth == 0: break
                    j += 1
                if j < len(s):
                    inner = s[i + 1:j].strip()
                    s = s[:j] + (', ' if inner else '') + ', '.join(['0'] * need) + s[j:]
                    lines[ln] = s; changed = True
        if not changed: return text, False
        text = '\n'.join(lines)
    return text, False
