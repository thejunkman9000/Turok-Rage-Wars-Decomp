#!/usr/bin/env python3
"""one-off: per-thread save/restore of the shared FPU register file g_fpr in port/os_shim.c"""
p = 'port/os_shim.c'
s = open(p, newline='').read()
if 'g_fpr' not in s:
    s = s.replace('    DWORD tid;\n} HThread;', '    DWORD tid;\n    float fpr[32];               /* the guest FPU registers of this thread (statically recompiled code keeps them in g_fpr) */\n} HThread;', 1)
    s = s.replace('static void reschedule(HThread *self) {\n    for (;;) {',
                  'extern float g_fpr[32];\nstatic void reschedule(HThread *self) {\n    for (;;) {', 1)
    s = s.replace('        LeaveCriticalSection(&g_lock);\n        WaitForSingleObject(self->evt, INFINITE);\n        EnterCriticalSection(&g_lock);\n        if (g_current == self) { self->state = 3; return; }',
                  '        memcpy(self->fpr, g_fpr, sizeof g_fpr);\n        LeaveCriticalSection(&g_lock);\n        WaitForSingleObject(self->evt, INFINITE);\n        EnterCriticalSection(&g_lock);\n        if (g_current == self) { self->state = 3; memcpy(g_fpr, self->fpr, sizeof g_fpr); return; }', 1)
    open(p, 'w', newline='').write(s)
    print('patched os_shim')
g = open('port/game_glue.c', newline='').read()
if 'float g_fpr' not in g:
    g += '\n/* the guest FPU register file shared by all statically recompiled code (saved/restored per thread by the OS shim) */\nfloat g_fpr[32];\n'
    open('port/game_glue.c', 'w', newline='').write(g)
    print('patched glue')
