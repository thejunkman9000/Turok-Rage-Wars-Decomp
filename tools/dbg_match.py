import sys, os
sys.argv = ['lu_match.py', '2.7.2', '-O2', '--', 'osSendMesg.c']
src = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(src, 'lu_match', 'exec'))
res, err = compile_funcs(f'{LU}/lib/src/osSendMesg.c')
print('err:', err)
if res:
    text, syms, relocs = res
    print('text bytes:', len(text), 'syms:', syms, 'relocs:', {hex(k): hex(v) for k, v in list(relocs.items())[:6]})
