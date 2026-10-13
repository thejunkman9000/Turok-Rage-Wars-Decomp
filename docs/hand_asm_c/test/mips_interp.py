"""Minimal big-endian MIPS interpreter used as the ORACLE for the hand_asm_c differential tests.

It executes the *encoded words* that sit in the comments of the project's hand-written `.s` units
(`/* ROM VRAM WORD */  mnemonic ...`), so what is run is exactly what the ROM contains - no
re-assembly, no recompilation.  Only the integer subset the units use is implemented, plus the few
extra opcodes of the thread units (sd/ld, mfc0/mtc0 as a plain register file, cfc1/sdc1/ldc1 as a
fake FPU register file).  `add`/`addi`/`sub` raise Overflow like the real CPU (hand-written code in
this ROM uses them everywhere).
"""
import re

M32 = 0xFFFFFFFF
WORD_RE = re.compile(r'/\*\s*([0-9A-Fa-f]{5,8})\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s*\*/')


class Overflow(Exception):
    pass


class BadOpcode(Exception):
    pass


class StepLimit(Exception):
    pass


def sx16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def s32(v):
    v &= M32
    return v - (1 << 32) if v & 0x80000000 else v


def load_s(path, words=None):
    """Return {vram: word} for every `/* rom vram word */` line of an assembler file."""
    words = {} if words is None else words
    with open(path, 'r', encoding='utf-8', errors='replace') as f:
        for line in f:
            m = WORD_RE.search(line)
            if m:
                words[int(m.group(2), 16)] = int(m.group(3), 16)
    return words


class Mem:
    """Flat big-endian memory, 8 MiB window; any address is masked with 0x7FFFFF (KSEG0/KSEG1 alias)."""
    SIZE = 0x800000

    def __init__(self):
        self.b = bytearray(self.SIZE)
        self.on_read = None   # callback(addr, size)
        self.on_write = None

    def _i(self, a):
        return a & 0x7FFFFF

    def r8(self, a):
        if self.on_read: self.on_read(a, 1)
        return self.b[a & 0x7FFFFF]

    def r16(self, a):
        if self.on_read: self.on_read(a, 2)
        i = a & 0x7FFFFF
        return (self.b[i] << 8) | self.b[i + 1]

    def r32(self, a):
        if self.on_read: self.on_read(a, 4)
        i = a & 0x7FFFFF
        return (self.b[i] << 24) | (self.b[i + 1] << 16) | (self.b[i + 2] << 8) | self.b[i + 3]

    def w8(self, a, v):
        if self.on_write: self.on_write(a, 1)
        self.b[a & 0x7FFFFF] = v & 0xFF

    def w16(self, a, v):
        if self.on_write: self.on_write(a, 2)
        i = a & 0x7FFFFF
        self.b[i] = (v >> 8) & 0xFF
        self.b[i + 1] = v & 0xFF

    def w32(self, a, v):
        if self.on_write: self.on_write(a, 4)
        i = a & 0x7FFFFF
        v &= M32
        self.b[i] = v >> 24
        self.b[i + 1] = (v >> 16) & 0xFF
        self.b[i + 2] = (v >> 8) & 0xFF
        self.b[i + 3] = v & 0xFF

    def put(self, a, data):
        i = a & 0x7FFFFF
        self.b[i:i + len(data)] = data

    def get(self, a, n):
        i = a & 0x7FFFFF
        return bytes(self.b[i:i + n])


class Cpu:
    def __init__(self, code, mem):
        self.code = code            # {vram: word}
        self.mem = mem
        self.r = [0] * 32           # 32-bit unsigned views of the GPRs
        self.cp0 = [0] * 32
        self.fcr31 = 0
        self.fpr = [0] * 32         # 64-bit FPU registers (FR=1 model)
        self.pc = 0
        self.steps = 0
        self.calls = []             # list of (target) for jal/jalr, for tracing
        self.stop = None
        self.hooks = {}             # pc -> python callable(cpu), replaces the instruction fetch (used to stub callees)

    # -- helpers
    def fetch(self, pc):
        try:
            return self.code[pc]
        except KeyError:
            raise BadOpcode('fetch outside known code at %08X' % pc)

    def setr(self, n, v):
        if n:
            self.r[n] = v & M32

    def run(self, entry, stop, max_steps=50_000_000):
        self.pc = entry
        self.stop = stop
        steps = 0
        pc = entry
        r = self.r
        while pc != stop:
            h = self.hooks.get(pc)
            if h:
                h(self)
                pc = self.pc
                continue
            steps += 1
            if steps > max_steps:
                self.steps = steps
                raise StepLimit()
            w = self.fetch(pc)
            # branch delay slot handling: execute `pc`, and if it is a branch also the slot
            npc = self.exec_one(w, pc)
            if npc is None:
                pc = (pc + 4) & M32
            else:
                # npc is (target, taken) -> run delay slot first
                tgt, link = npc
                slot = self.fetch((pc + 4) & M32)
                if link is not None:
                    pass
                self.exec_one(slot, (pc + 4) & M32, in_slot=True)
                steps += 1
                pc = tgt if tgt is not None else (pc + 8) & M32
        self.steps = steps
        self.pc = pc

    def exec_one(self, w, pc, in_slot=False):
        """Execute one instruction.  Returns None for sequential flow, or (target_or_None, _) for a branch/jump
        (None target = branch not taken: fall through after the delay slot)."""
        m = self.mem
        r = self.r
        op = w >> 26
        rs = (w >> 21) & 31
        rt = (w >> 16) & 31
        rd = (w >> 11) & 31
        sa = (w >> 6) & 31
        fn = w & 63
        imm = w & 0xFFFF
        simm = sx16(imm)
        if op == 0:
            if w == 0:
                return None
            if fn == 0x00:   # sll
                self.setr(rd, r[rt] << sa)
            elif fn == 0x02:  # srl
                self.setr(rd, r[rt] >> sa)
            elif fn == 0x03:  # sra
                self.setr(rd, s32(r[rt]) >> sa)
            elif fn == 0x04:  # sllv
                self.setr(rd, r[rt] << (r[rs] & 31))
            elif fn == 0x06:  # srlv
                self.setr(rd, r[rt] >> (r[rs] & 31))
            elif fn == 0x07:  # srav
                self.setr(rd, s32(r[rt]) >> (r[rs] & 31))
            elif fn == 0x08:  # jr
                return (r[rs], None)
            elif fn == 0x09:  # jalr
                t = r[rs]
                self.setr(rd, pc + 8)
                self.calls.append(t)
                return (t, 1)
            elif fn == 0x20:  # add
                v = s32(r[rs]) + s32(r[rt])
                if not -0x80000000 <= v <= 0x7FFFFFFF:
                    raise Overflow('add at %08X' % pc)
                self.setr(rd, v)
            elif fn == 0x21:  # addu
                self.setr(rd, r[rs] + r[rt])
            elif fn == 0x22:  # sub
                v = s32(r[rs]) - s32(r[rt])
                if not -0x80000000 <= v <= 0x7FFFFFFF:
                    raise Overflow('sub at %08X' % pc)
                self.setr(rd, v)
            elif fn == 0x23:  # subu
                self.setr(rd, r[rs] - r[rt])
            elif fn == 0x24:
                self.setr(rd, r[rs] & r[rt])
            elif fn == 0x25:
                self.setr(rd, r[rs] | r[rt])
            elif fn == 0x26:
                self.setr(rd, r[rs] ^ r[rt])
            elif fn == 0x27:
                self.setr(rd, ~(r[rs] | r[rt]))
            elif fn == 0x2A:  # slt
                self.setr(rd, 1 if s32(r[rs]) < s32(r[rt]) else 0)
            elif fn == 0x2B:  # sltu
                self.setr(rd, 1 if r[rs] < r[rt] else 0)
            else:
                raise BadOpcode('special fn %02X at %08X' % (fn, pc))
            return None
        if op == 1:  # regimm
            if rt == 0:      # bltz
                return (pc + 4 + (simm << 2), 1) if s32(r[rs]) < 0 else (None, 1)
            if rt == 1:      # bgez
                return (pc + 4 + (simm << 2), 1) if s32(r[rs]) >= 0 else (None, 1)
            raise BadOpcode('regimm at %08X' % pc)
        if op == 2:  # j
            return (((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2), 1)
        if op == 3:  # jal
            self.setr(31, pc + 8)
            t = ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            self.calls.append(t)
            return (t, 1)
        if op == 4:
            return (pc + 4 + (simm << 2), 1) if r[rs] == r[rt] else (None, 1)
        if op == 5:
            return (pc + 4 + (simm << 2), 1) if r[rs] != r[rt] else (None, 1)
        if op == 6:
            return (pc + 4 + (simm << 2), 1) if s32(r[rs]) <= 0 else (None, 1)
        if op == 7:
            return (pc + 4 + (simm << 2), 1) if s32(r[rs]) > 0 else (None, 1)
        if op == 8:  # addi
            v = s32(r[rs]) + simm
            if not -0x80000000 <= v <= 0x7FFFFFFF:
                raise Overflow('addi at %08X' % pc)
            self.setr(rt, v)
        elif op == 9:
            self.setr(rt, r[rs] + simm)
        elif op == 0xA:
            self.setr(rt, 1 if s32(r[rs]) < simm else 0)
        elif op == 0xB:
            self.setr(rt, 1 if r[rs] < (simm & M32) else 0)
        elif op == 0xC:
            self.setr(rt, r[rs] & imm)
        elif op == 0xD:
            self.setr(rt, r[rs] | imm)
        elif op == 0xE:
            self.setr(rt, r[rs] ^ imm)
        elif op == 0xF:
            self.setr(rt, imm << 16)
        elif op == 0x10:  # cop0
            if rs == 0:      # mfc0
                self.setr(rt, self.cp0[rd])
            elif rs == 4:    # mtc0
                self.cp0[rd] = r[rt]
            else:
                raise BadOpcode('cop0 at %08X' % pc)
        elif op == 0x11:  # cop1
            if rs == 2:      # cfc1
                self.setr(rt, self.fcr31)
            elif rs == 6:    # ctc1
                self.fcr31 = r[rt]
            else:
                raise BadOpcode('cop1 at %08X' % pc)
        elif op == 0x20:  # lb
            v = m.r8((r[rs] + simm) & M32)
            self.setr(rt, v - 256 if v & 0x80 else v)
        elif op == 0x21:
            self.setr(rt, sx16(m.r16((r[rs] + simm) & M32)))
        elif op == 0x23:
            self.setr(rt, m.r32((r[rs] + simm) & M32))
        elif op == 0x24:
            self.setr(rt, m.r8((r[rs] + simm) & M32))
        elif op == 0x25:
            self.setr(rt, m.r16((r[rs] + simm) & M32))
        elif op == 0x28:
            m.w8((r[rs] + simm) & M32, r[rt])
        elif op == 0x29:
            m.w16((r[rs] + simm) & M32, r[rt])
        elif op == 0x2B:
            m.w32((r[rs] + simm) & M32, r[rt])
        elif op == 0x37:  # ld  (register file is 32 bit: keep the low word)
            a = (r[rs] + simm) & M32
            self.setr(rt, m.r32(a + 4))
        elif op == 0x3F:  # sd  (high word = sign extension of the 32 bit view)
            a = (r[rs] + simm) & M32
            m.w32(a, 0xFFFFFFFF if r[rt] & 0x80000000 else 0)
            m.w32(a + 4, r[rt])
        elif op == 0x3D:  # sdc1
            a = (r[rs] + simm) & M32
            m.w32(a, self.fpr[rt] >> 32)
            m.w32(a + 4, self.fpr[rt] & M32)
        elif op == 0x35:  # ldc1
            a = (r[rs] + simm) & M32
            self.fpr[rt] = (m.r32(a) << 32) | m.r32(a + 4)
        else:
            raise BadOpcode('opcode %02X (word %08X) at %08X' % (op, w, pc))
        return None
