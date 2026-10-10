import re, difflib
def struct(ours, rom):
    a = [re.sub(r'<[^>]*>', '', x[1]).split(';')[0].split()[0] if x[1].split() else '' for x in ours]
    b = [re.sub(r'<[^>]*>', '', x[1]).split(';')[0].split()[0] if x[1].split() else '' for x in rom]
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    return sum(max(i2 - i1, j2 - j1) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != 'equal')
