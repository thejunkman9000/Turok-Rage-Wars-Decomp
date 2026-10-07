#!/usr/bin/env python3
"""Run a 32-bit exe under a minimal debugger and report the first access violation (module, RVA, registers, stack).
usage: python port/dbg.py <exe> [seconds]"""
import ctypes, ctypes.wintypes as wt, sys, time, os
k32 = ctypes.windll.kernel32
DEBUG_ONLY_THIS_PROCESS = 2
EXCEPTION_DEBUG_EVENT, CREATE_PROCESS_DEBUG_EVENT, EXIT_PROCESS_DEBUG_EVENT, LOAD_DLL_DEBUG_EVENT = 1, 3, 5, 6
DBG_CONTINUE, DBG_EXCEPTION_NOT_HANDLED = 0x00010002, 0x80010001
class EXC_REC(ctypes.Structure):
    _fields_ = [('Code', wt.DWORD), ('Flags', wt.DWORD), ('Rec', ctypes.c_void_p), ('Addr', ctypes.c_void_p), ('NParams', wt.DWORD),
                ('Info', ctypes.c_void_p * 15)]
class DEBUG_EVENT(ctypes.Structure):
    class U(ctypes.Union):
        _fields_ = [('Exception', ctypes.c_byte * 160), ('raw', ctypes.c_byte * 200)]
    _fields_ = [('Code', wt.DWORD), ('Pid', wt.DWORD), ('Tid', wt.DWORD), ('u', U)]
class WOW64_CONTEXT(ctypes.Structure):
    _fields_ = [('ContextFlags', wt.DWORD)] + [(n, wt.DWORD) for n in ('Dr0', 'Dr1', 'Dr2', 'Dr3', 'Dr6', 'Dr7')] + \
        [('ControlWord', wt.DWORD), ('StatusWord', wt.DWORD), ('TagWord', wt.DWORD), ('ErrorOffset', wt.DWORD), ('ErrorSelector', wt.DWORD),
         ('DataOffset', wt.DWORD), ('DataSelector', wt.DWORD), ('RegisterArea', ctypes.c_byte * 80), ('Cr0NpxState', wt.DWORD)] + \
        [(n, wt.DWORD) for n in ('SegGs', 'SegFs', 'SegEs', 'SegDs', 'Edi', 'Esi', 'Ebx', 'Edx', 'Ecx', 'Eax', 'Ebp', 'Eip', 'SegCs', 'EFlags', 'Esp', 'SegSs')] + \
        [('Ext', ctypes.c_byte * 512)]
exe = os.path.abspath(sys.argv[1]); secs = float(sys.argv[2]) if len(sys.argv) > 2 else 20
si = ctypes.create_string_buffer(68); ctypes.c_uint.from_buffer(si).value = 68
pi = ctypes.create_string_buffer(16)
if not k32.CreateProcessW(exe, None, None, None, False, DEBUG_ONLY_THIS_PROCESS, None, os.getcwd(), si, pi):
    print('CreateProcess failed', ctypes.GetLastError()); sys.exit(1)
hproc = ctypes.c_void_p.from_buffer(pi, 0).value
dlls = {}; base = None; t0 = time.time(); ev = DEBUG_EVENT(); first = True
while time.time() - t0 < secs:
    if not k32.WaitForDebugEvent(ctypes.byref(ev), 200): continue
    cont = DBG_CONTINUE
    if '-v' in sys.argv: print(f'[{time.time()-t0:5.2f}] event {ev.Code} tid={ev.Tid}')
    if ev.Code == CREATE_PROCESS_DEBUG_EVENT:
        base = ctypes.c_void_p.from_buffer(ev.u.raw, 8 + 0).value  # hFile at 0, hProcess, hThread, lpBaseOfImage...
    elif ev.Code == EXCEPTION_DEBUG_EVENT:
        rec = EXC_REC.from_buffer(ev.u.Exception)
        first_chance = ctypes.c_uint.from_buffer(ev.u.Exception, ctypes.sizeof(EXC_REC)).value
        if rec.Code in (0xC0000005, 0xC000001D, 0xC0000094, 0xC00000FD) and first_chance:
            th = k32.OpenThread(0x1FFFFF, False, ev.Tid)
            ctx = WOW64_CONTEXT(); ctx.ContextFlags = 0x10007
            k32.Wow64GetThreadContext(th, ctypes.byref(ctx))
            print(f'EXCEPTION 0x{rec.Code:08X} at 0x{(rec.Addr or 0):08X} access={rec.Info[0]} addr=0x{(rec.Info[1] or 0):08X}')
            print(f'  eip={ctx.Eip:08X} esp={ctx.Esp:08X} eax={ctx.Eax:08X} ecx={ctx.Ecx:08X} edx={ctx.Edx:08X} ebx={ctx.Ebx:08X} ebp={ctx.Ebp:08X} esi={ctx.Esi:08X} edi={ctx.Edi:08X}')
            buf = (ctypes.c_uint * 16)(); n = ctypes.c_size_t()
            k32.ReadProcessMemory(hproc, ctypes.c_void_p(ctx.Esp), buf, 64, ctypes.byref(n))
            print('  stack:', ' '.join(f'{v:08X}' for v in buf))
            print('  image base:', hex(base or 0), ' rva:', hex((ctx.Eip - (base or 0)) & 0xFFFFFFFF))
            k32.TerminateProcess(hproc, 1); break
        cont = DBG_EXCEPTION_NOT_HANDLED
    elif ev.Code == EXIT_PROCESS_DEBUG_EVENT:
        print('process exited', ctypes.c_uint.from_buffer(ev.u.raw, 0).value); break
    k32.ContinueDebugEvent(ev.Pid, ev.Tid, cont)
else:
    print('time limit reached (process still running)'); k32.TerminateProcess(hproc, 0)
