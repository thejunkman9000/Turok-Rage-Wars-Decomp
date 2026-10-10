#!/usr/bin/env python3
"""Directed random-input soak of the Windows port.

usage: python port/fuzz.py [--seed N] [--minutes M] [--speed S] [--pads P] [--strict] [--keep-going]
Boots the game, gets to the main menu (screen 3) and then plays random but player-like input for M game minutes (default 10) at S x speed
(TUROK_SPEED): menu screens get mostly A / D-pad / stick / B / Start, a level gets stick walks, Z / A fire buttons and C buttons.  The next
action depends on the last `screen id -> N` / `game state: st=N` lines of port/build/run.log, so the run reaches matches and menus alike.
Reports ok / CRASH / STALL (+ port/crashsum.py summary and the visited screens/states); the log of the run is kept as port/build/fuzz_<seed>.log.
--strict   TUROK_STRICT=1: no soft recovery of null-page faults (port/softfault.c), the first fault is the crash
--pads P   P pads (TUROK_PADS), pads 2..P play random input too (join / loadout / match in multiplayer screens)"""
import argparse, os, random, re, subprocess, sys, time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
BTN = {'A': 0x8000, 'B': 0x4000, 'Z': 0x2000, 'Start': 0x1000, 'DUp': 0x0800, 'DDown': 0x0400, 'DLeft': 0x0200, 'DRight': 0x0100,
       'L': 0x0020, 'R': 0x0010, 'CUp': 0x0008, 'CDown': 0x0004, 'CLeft': 0x0002, 'CRight': 0x0001}
LOG = 'port/build/run.log'

def frame():
    try: return int(open('port_frame.txt').read().strip())
    except (OSError, ValueError): return -1

def tail(path, n=12000):
    try:
        with open(path, 'rb') as f:
            f.seek(0, 2); size = f.tell(); f.seek(max(0, size - n)); return f.read().decode('latin-1')
    except OSError: return ''

def context(log):
    scr = re.findall(r'screen id -> (-?\d+) \(top=(-?\d+)\)', log)
    st = re.findall(r'game state: g=\w+ st=(\d+)', log)
    return (int(scr[-1][0]) if scr else None, int(scr[-1][1]) if scr else None, int(st[-1]) if st else None)

def choose(rnd, screen, top, state):
    """-> (buttons, x, y, hold seconds, wait seconds)"""
    in_level = (screen == 2 and top == 0)                  # the UI stack is empty: in a level (or between screens)
    r = rnd.random()
    if in_level:
        if r < 0.45: return 0, rnd.randint(-80, 80), rnd.randint(-80, 80), 0.3 + 2.2 * rnd.random(), 0.0
        if r < 0.65: return BTN['Z'], rnd.randint(-80, 80), rnd.randint(-80, 80), 0.1 + 1.0 * rnd.random(), 0.0
        if r < 0.78: return BTN[rnd.choice(['CUp', 'CDown', 'CLeft', 'CRight'])], rnd.randint(-80, 80), 0, 0.1 + 0.6 * rnd.random(), 0.0
        if r < 0.85: return BTN['A'], 0, 0, 0.1 + 0.2 * rnd.random(), 0.0
        if r < 0.90: return BTN[rnd.choice(['L', 'R'])], 0, 0, 0.1 + 0.3 * rnd.random(), 0.0
        if r < 0.94: return BTN['B'], 0, 0, 0.1 + 0.2 * rnd.random(), 0.0
        if r < 0.97: return BTN['Start'], 0, 0, 0.1 + 0.2 * rnd.random(), 0.5
        return 0, 0, 0, 0.0, 0.5 + 2.0 * rnd.random()
    if r < 0.40: return BTN['A'], 0, 0, 0.1 + 0.2 * rnd.random(), 0.3 + 1.0 * rnd.random()
    if r < 0.66: return BTN[rnd.choice(['DUp', 'DDown', 'DLeft', 'DRight'])], 0, 0, 0.1 + 0.2 * rnd.random(), 0.15 + 0.5 * rnd.random()
    if r < 0.76: return 0, rnd.choice([-80, 0, 80]), rnd.choice([-80, 0, 80]), 0.2 + 0.4 * rnd.random(), 0.2
    if r < 0.84: return BTN['B'], 0, 0, 0.1 + 0.2 * rnd.random(), 0.3
    if r < 0.91: return BTN['Start'], 0, 0, 0.1 + 0.2 * rnd.random(), 0.3
    if r < 0.97: return BTN[rnd.choice(['Z', 'L', 'R', 'CUp', 'CDown', 'CLeft', 'CRight'])], 0, 0, 0.1 + 0.3 * rnd.random(), 0.2
    return 0, 0, 0, 0.0, 0.5 + 1.5 * rnd.random()

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--seed', type=int, default=1); ap.add_argument('--minutes', type=float, default=10); ap.add_argument('--speed', type=int, default=10)
    ap.add_argument('--pads', type=int, default=1); ap.add_argument('--strict', action='store_true'); ap.add_argument('--keep-going', action='store_true')
    a = ap.parse_args()
    rnd = random.Random(a.seed)
    exe = open('port/build/latest_exe.txt').read().strip()
    env = dict(os.environ, TUROK_SKIPMENU='1', TUROK_LOG=os.path.join(ROOT, LOG), TUROK_SPEED=str(max(1, min(50, a.speed))))
    if a.pads > 1: env['TUROK_PADS'] = str(a.pads)
    if a.strict: env['TUROK_STRICT'] = '1'
    for f in ('port_input.txt', 'port_input2.txt', 'port_input3.txt', 'port_input4.txt', 'port_frame.txt', 'port_frame.tmp'):
        try: os.remove(f)
        except OSError: pass
    try: os.remove(LOG)
    except OSError: pass
    proc = subprocess.Popen([os.path.abspath(exe)], cwd=ROOT, env=env)
    t0 = time.time(); verdict = 'ok'; screens = set(); states = set(); last_frame = -1; last_move = time.time()

    def alive(): return proc.poll() is None
    def check():
        """returns a verdict string when the run is over"""
        nonlocal last_frame, last_move
        if not alive(): return 'EXIT %s' % proc.returncode
        t = tail(LOG)
        if 'CRASH(raw' in t or 'game thread exception' in t: return 'CRASH'
        f = frame()
        if f != last_frame: last_frame = f; last_move = time.time()
        elif time.time() - last_move > 25: return 'STALL'
        return None
    def hold(pad, b, x, y, sec):
        fn = 'port_input.txt' if pad == 1 else 'port_input%d.txt' % pad
        for _ in range(200):
            if not os.path.exists(fn): break
            time.sleep(0.01)
        try: open(fn, 'w').write('%X %d %d %d' % (b, x, y, max(1, int(sec * 60))))
        except OSError: return
        target = frame() + max(1, int(sec * 60)); t1 = time.time()
        while alive() and frame() < target and time.time() - t1 < 8 + sec * 4: time.sleep(0.01)
    def wait_frames(sec):
        f0 = frame(); target = f0 + int(sec * 60); t1 = time.time()
        while alive() and frame() < target and time.time() - t1 < 6 + sec * 4: time.sleep(0.01)

    # phase 1: Start taps until the main menu (screen 3) is up
    while time.time() - t0 < 120:
        time.sleep(0.4)
        v = check()
        if v: verdict = v; break
        if time.time() - t0 < 6: continue
        if re.search(r'-> 3 ', tail(LOG, 400000)): break
        hold(1, BTN['Start'], 0, 0, 0.4)
    else:
        verdict = 'NO-MENU'
    start_frame = frame(); steps = 0
    while verdict == 'ok' and (frame() - start_frame) < a.minutes * 3600:
        log = tail(LOG)
        scr, top, st = context(log)
        if scr is not None: screens.add(scr)
        if st is not None: states.add(st)
        b, x, y, hs, ws = choose(rnd, scr, top, st)
        if a.pads > 1 and rnd.random() < 0.25:
            p = rnd.randint(2, a.pads); hold(p, BTN[rnd.choice(['A', 'A', 'B', 'DLeft', 'DRight', 'DUp', 'DDown', 'Start', 'Z'])], 0, 0, 0.1 + 0.2 * rnd.random())
        if hs > 0: hold(1, b, x, y, hs)
        if ws > 0: wait_frames(ws)
        steps += 1
        v = check()
        if v: verdict = v; break
    wall = int(time.time() - t0)
    if alive(): proc.kill()
    time.sleep(0.5)
    for f in ('port_input.txt', 'port_input2.txt', 'port_input3.txt', 'port_input4.txt'):
        try: os.remove(f)
        except OSError: pass
    try: os.replace(LOG, 'port/build/fuzz_%d.log' % a.seed)
    except OSError:
        import shutil; shutil.copyfile(LOG, 'port/build/fuzz_%d.log' % a.seed)
    print('seed %d minutes %.1f speed %d pads %d%s: %s after %d steps, %d game s, %d wall s | screens %s states %s' % (
        a.seed, a.minutes, a.speed, a.pads, ' strict' if a.strict else '', verdict, steps, (frame() - start_frame) // 60, wall,
        ' '.join(map(str, sorted(screens))), ' '.join(map(str, sorted(states)))))
    r = subprocess.run([sys.executable, 'port/crashsum.py', 'port/build/fuzz_%d.log' % a.seed], capture_output=True, text=True)
    print(r.stdout.strip())
    sys.exit(0 if verdict == 'ok' else 1)

if __name__ == '__main__':
    main()
