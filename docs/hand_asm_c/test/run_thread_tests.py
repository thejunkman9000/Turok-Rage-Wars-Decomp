#!/usr/bin/env python3
"""Differential test: original thread / watchpoint assembly (interpreted) vs docs/hand_asm_c/thread.c.

  py run_thread_tests.py [--count N] [--seed N]

Scenarios (random): priority queue insertion (__osEnqueueThread), pop (__osPopThread), the context
save of __osEnqueueAndYield with random register / CP0 / FPU state, dbgSetWatchpoint, and the
argument of the osDestroyThread call in __osCleanupThread.  The original code runs in mips_interp.py
on words taken from src/libultra/*.s; the C side is test_thread.c (includes ../thread.c).
"""
import os, random, struct, subprocess, sys, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, '..', '..', '..'))
sys.path.insert(0, HERE)
from mips_interp import Mem, Cpu, load_s  # noqa

CODE = {}
for u in ['__osEnqueueThread', '__osPopThread', '__osEnqueueAndYield', 'dbgSetWatchpoint', '__osCleanupThread']:
    load_s(os.path.join(REPO, 'src', 'libultra', u + '.s'), CODE)

ENQ, POP, YIELD, WATCH, CLEAN = 0x002C15F8, 0x002C1648, 0x002C145C, 0x002B29C4, 0x002C185C
DISPATCH = 0x002C1660
STOP = 0x00F00000
TB, QVAR = 0x80300000, 0x80380000
RUNNING_VAR, GMASK_VAR, MI_REG = 0x800D92A0, 0x800D9288, 0xA430000C
M = 0xFFFFFFFF


def taddr(i):
    return TB + i * 0x400


def init_threads(mem, n, prio, qlist):
    for i in range(n + 2):
        mem.put(taddr(i), b'\x5A' * 0x230)
        mem.w32(taddr(i) + 0, 0)
        mem.w32(taddr(i) + 8, 0)
        mem.w32(taddr(i) + 0xC, 0)
        p = -1 if i == n + 1 else (10 if i == n else prio[i])
        mem.w32(taddr(i) + 4, p & M)
    head = taddr(n + 1)
    for i in reversed(qlist):
        mem.w32(taddr(i), head)
        mem.w32(taddr(i) + 8, QVAR)
        head = taddr(i)
    mem.w32(QVAR, head)


def order(mem, n):
    out = []
    p = mem.r32(QVAR)
    steps = 0
    while p and steps < 64:
        out.append(idx(p, n))
        p = mem.r32(p)
        steps += 1
    return out


def idx(p, n):
    if p == 0:
        return -1
    for i in range(n + 2):
        if taddr(i) == p:
            return i
    return -2


def fmt_order(mem, n):
    s = 'order=' + ''.join('%d,' % i for i in order(mem, n))
    s += ' queuefield='
    for i in range(n + 1):
        q = mem.r32(taddr(i) + 8)
        s += '0' if q == 0 else ('1' if q == QVAR else '9')
    return s


def new_cpu(mem):
    c = Cpu(CODE, mem)
    c.r[31] = STOP
    c.r[29] = 0x807F0000
    return c


def main():
    argv = sys.argv[1:]
    count = int(argv[argv.index('--count') + 1]) if '--count' in argv else 400
    seed = int(argv[argv.index('--seed') + 1]) if '--seed' in argv else 7
    rng = random.Random(seed)
    scen, expect = [], []

    for _ in range(count):
        kind = rng.choice(['ENQ', 'ENQ', 'POP', 'YIELD', 'YIELD', 'WATCH'])
        n = rng.randint(1, 8)
        prios = [rng.choice([0, 1, 5, 10, 10, 20, 127, rng.randint(0, 127)]) for _ in range(n)]
        # queue must be sorted by priority descending (FIFO among equals) for a valid queue
        ordl = sorted(range(n), key=lambda i: -prios[i])
        k = rng.randint(0, n - 1) if kind in ('ENQ',) else n
        if kind == 'ENQ':
            # thread `which` is not in the queue
            which = rng.randrange(n)
            qlist = [i for i in ordl if i != which]
            mem = Mem()
            init_threads(mem, n, prios, qlist)
            c = new_cpu(mem)
            c.r[4], c.r[5] = QVAR, taddr(which)
            c.run(ENQ, STOP)
            scen.append('ENQ %d %s %d %s %d' % (n, ' '.join(map(str, prios)), len(qlist), ' '.join(map(str, qlist)), which))
            expect.append('ENQ ' + fmt_order(mem, n) + ' selfnext=%d' % idx(mem.r32(taddr(which)), n))
        elif kind == 'POP':
            qlist = list(ordl)
            mem = Mem()
            init_threads(mem, n, prios, qlist)
            c = new_cpu(mem)
            c.r[4] = QVAR
            c.run(POP, STOP)
            t = c.r[2]
            scen.append('POP %d %s %d %s 0' % (n, ' '.join(map(str, prios)), len(qlist), ' '.join(map(str, qlist))))
            expect.append('POP ret=%d retnext=%d ' % (idx(t, n), idx(mem.r32(t), n)) + fmt_order(mem, n))
        elif kind == 'YIELD':
            qlist = list(ordl)
            hasq = rng.randint(0, 1)
            fp = rng.choice([0, 0, 1, 1, 1, 0x1234])
            status = rng.getrandbits(32)
            if rng.random() < 0.3:
                status &= ~0x04000000
            elif rng.random() < 0.5:
                status |= 0x04000000
            if rng.random() < 0.2:
                status &= ~0xFF00
            fcsr = rng.getrandbits(32)
            regs = [rng.getrandbits(32) for _ in range(12)]
            fe = [rng.getrandbits(64) for _ in range(16)]
            fo = [rng.getrandbits(64) for _ in range(16)]
            gmask = rng.getrandbits(32)
            mi = rng.choice([0, rng.getrandbits(32), rng.getrandbits(6)])
            rcp = rng.getrandbits(32)
            mem = Mem()
            init_threads(mem, n, prios, qlist)
            mem.w32(taddr(n) + 0x18, fp)
            mem.w32(taddr(n) + 0x128, rcp)
            mem.w32(RUNNING_VAR, taddr(n))
            mem.w32(GMASK_VAR, gmask)
            mem.w32(MI_REG, mi)
            c = new_cpu(mem)
            for i in range(8):
                c.r[16 + i] = regs[i]
            c.r[28], c.r[29], c.r[30], c.r[31] = regs[8], regs[9], regs[10], regs[11]
            c.cp0[12] = status
            c.fcr31 = fcsr
            for i in range(16):
                c.fpr[2 * i] = fe[i]
                c.fpr[2 * i + 1] = fo[i]
            c.r[4] = QVAR if hasq else 0
            c.run(YIELD, DISPATCH)
            t = taddr(n)

            def u64(o):
                return (mem.r32(t + o) << 32) | mem.r32(t + o + 4)
            s = 'YIELD dispatched=1 ' + fmt_order(mem, n)
            s += ' sr=%08X pc=%08X rcp=%08X fpcsr=%08X' % (mem.r32(t + 0x118), mem.r32(t + 0x11C), mem.r32(t + 0x128), mem.r32(t + 0x12C))
            s += ' gpr=' + ','.join('%X' % u64(o) for o in [0x98 + 8 * k for k in range(8)] + [0xE8, 0xF0, 0xF8, 0x100])
            s += ' other=%X,%X,%X,%08X,%08X' % (u64(0x20), u64(0x58), u64(0x110), mem.r32(t + 0x120), mem.r32(t + 0x124))
            s += ' fe=' + ''.join('%X,' % u64(0x130 + 8 * k) for k in range(16))
            s += ' fo=' + ''.join('%X,' % u64(0x1B0 + 8 * k) for k in range(16))
            expect.append(s)
            scen.append('YIELD %d %s %d %s %d %d %X %X %s %s %s %X %X %X' % (
                n, ' '.join(map(str, prios)), len(qlist), ' '.join(map(str, qlist)), hasq, fp, status, fcsr,
                ' '.join('%X' % v for v in regs), ' '.join('%X' % v for v in fe), ' '.join('%X' % v for v in fo),
                gmask, mi, rcp))
        else:
            a0, a1 = rng.getrandbits(32), rng.getrandbits(32)
            mem = Mem()
            c = new_cpu(mem)
            c.r[4], c.r[5] = a0, a1
            c.run(WATCH, STOP)
            scen.append('WATCH %X %X' % (a0, a1))
            expect.append('WATCH %08X' % c.cp0[18])

    # __osCleanupThread: osDestroyThread(NULL)
    word = CODE[CLEAN]
    target = ((CLEAN + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
    mem = Mem()
    c = new_cpu(mem)
    c.r[4] = 0x1234
    c.run(CLEAN, target)
    scen.append('CLEANUP')
    expect.append('CLEANUP destroy_arg=%s' % ('NULL' if c.r[4] == 0 else 'other'))

    tmp = tempfile.mkdtemp(prefix='thr_test_')
    exe = os.path.join(tmp, 'test_thread.exe')
    r = subprocess.run([sys.executable, '-m', 'ziglang', 'cc', '-std=c99', '-O2', '-Wall', '-o', exe,
                        os.path.join(HERE, 'test_thread.c')], capture_output=True, text=True)
    if r.returncode:
        print(r.stdout, r.stderr)
        return 2
    sp = os.path.join(tmp, 'scen.txt')
    open(sp, 'w').write('\n'.join(scen) + '\n')
    r = subprocess.run([exe, sp], capture_output=True, text=True)
    got = r.stdout.strip().splitlines()
    bad = 0
    if len(got) != len(expect):
        print('line count mismatch', len(got), len(expect))
        bad += 1
    for i, (g, e) in enumerate(zip(got, expect)):
        if g != e:
            bad += 1
            if bad <= 5:
                print('MISMATCH scenario %d: %s\n  C:        %s\n  original: %s' % (i, scen[i][:80], g, e))
    kinds = {}
    for s in scen:
        kinds[s.split()[0]] = kinds.get(s.split()[0], 0) + 1
    print('scenarios: %d %s  mismatches: %d' % (len(scen), kinds, bad))
    print('RESULT:', 'ALL EQUIVALENT' if bad == 0 else 'MISMATCH')
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main())
