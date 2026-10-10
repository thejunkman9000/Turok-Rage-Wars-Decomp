/* Soft recovery of null-page faults in the game code.
 *
 * The N64 game dereferences NULL (or a small garbage value) in places the original hardware survives or never reaches (a widget lookup
 * that finds nothing, an object that is not set up yet, a stale table entry after a screen change).  On the PC that is an access violation
 * and the process dies.  The vectored handler in game_glue.c calls port_soft_fault() first: for an access below 64 KB made by an
 * instruction of the game image the faulting instruction is decoded and
 *   - a store (and every read-modify-write / compare) is skipped,
 *   - a load puts 0 into its destination (general register or xmm),
 *   - a call through a NULL function pointer returns 0 to the caller (cdecl),
 * and execution continues.  Every distinct faulting instruction is logged once (`SOFTFAULT ...` in run.log) so the cause can still be found;
 * TUROK_STRICT=1 turns the recovery off (the crash is reported as before).  An instruction this decoder does not know is not handled.
 * The decoder covers what clang/MSVC emit for the game code (integer moves, ALU with memory operands, movzx/movsx, SSE scalar moves and
 * arithmetic, cvt*, setcc, cmov); x87 memory operands are left alone (they would unbalance the FPU stack). */
#include <windows.h>
#include <stdio.h>
#include <string.h>

typedef struct { int len; int mem; int reg; int rm; int mod; } ModRM;

static void decode_modrm(const unsigned char *p, ModRM *m) {
    unsigned char b = p[0]; int mod = b >> 6, rm = b & 7, len = 1;
    m->mod = mod; m->reg = (b >> 3) & 7; m->rm = rm; m->mem = (mod != 3);
    if (mod != 3) {
        if (rm == 4) { unsigned char sib = p[1]; len++; if ((sib & 7) == 5 && mod == 0) len += 4; }
        else if (rm == 5 && mod == 0) len += 4;
        if (mod == 1) len += 1; else if (mod == 2) len += 4;
    }
    m->len = len;
}

enum { K_SKIP = 1, K_LOAD32, K_LOAD16, K_LOAD8, K_LOADX, K_PUSH0 };
typedef struct { int len; int kind; int reg; } Insn;

/* returns 1 when the instruction at p is recognised and accesses memory */
static int decode(const unsigned char *p, Insn *o) {
    int n = 0, op16 = 0, pf66 = 0, pfF3 = 0, pfF2 = 0; ModRM m; unsigned char op;
    for (;; n++) {
        unsigned char c = p[n];
        if (c == 0x66) { op16 = 1; pf66 = 1; }
        else if (c == 0xF3) pfF3 = 1;
        else if (c == 0xF2) pfF2 = 1;
        else if (c == 0x67 || c == 0xF0 || c == 0x2E || c == 0x36 || c == 0x3E || c == 0x26 || c == 0x64 || c == 0x65) { }
        else break;
    }
    op = p[n++];
    o->kind = 0; o->reg = 0;
#define MODRM() decode_modrm(p + n, &m); if (!m.mem) return 0
#define DONE(extra, k) do { o->len = n + m.len + (extra); o->kind = (k); o->reg = m.reg; return 1; } while (0)
    if (op == 0x0F) {
        unsigned char op2 = p[n++];
        switch (op2) {
        case 0xB6: case 0xB7: case 0xBE: case 0xBF: MODRM(); DONE(0, K_LOAD32);
        case 0xAF: case 0xA3: case 0xAB: case 0xB3: case 0xBB: case 0x1F: MODRM(); DONE(0, K_SKIP);
        case 0xBA: case 0xC6: case 0x70: case 0xA4: case 0xAC: MODRM(); DONE(1, K_SKIP);
        case 0x10: case 0x28: MODRM(); DONE(0, K_LOADX);
        case 0x11: case 0x29: case 0x13: case 0x17: case 0x2B: case 0xD6: case 0x7F: if (op2 == 0x7F && !pf66 && !pfF3) return 0; MODRM(); DONE(0, K_SKIP);
        case 0x12: case 0x16: case 0x14: case 0x15: MODRM(); DONE(0, K_SKIP);
        case 0x2A: MODRM(); DONE(0, K_LOADX);                      /* cvtsi2ss/sd xmm, r/m32 */
        case 0x2C: case 0x2D: MODRM(); DONE(0, K_LOAD32);          /* cvtt/cvt ss2si r32, xmm/m */
        case 0x2E: case 0x2F: MODRM(); DONE(0, K_SKIP);
        case 0x5A: case 0x5B: case 0xE6: MODRM(); DONE(0, K_LOADX);
        case 0x6E: if (!pf66) return 0; MODRM(); DONE(0, K_LOADX);
        case 0x7E: MODRM(); if (pfF3) { o->len = n + m.len; o->kind = K_LOADX; o->reg = m.reg; return 1; } DONE(0, K_SKIP);
        case 0x6F: if (!pf66 && !pfF3) return 0; MODRM(); DONE(0, K_LOADX);
        default:
            if (op2 >= 0x40 && op2 <= 0x4F) { MODRM(); DONE(0, K_SKIP); }          /* cmovcc */
            if (op2 >= 0x90 && op2 <= 0x9F) { MODRM(); DONE(0, K_SKIP); }          /* setcc m8 */
            if (op2 >= 0x51 && op2 <= 0x5F) { MODRM(); DONE(0, K_SKIP); }          /* SSE arithmetic: the destination keeps its value */
            if (op2 >= 0xD0 && op2 <= 0xFE) { MODRM(); DONE(0, K_SKIP); }          /* MMX/SSE2 integer ops */
            return 0;
        }
    }
    switch (op) {
    case 0x88: case 0x89: MODRM(); DONE(0, K_SKIP);
    case 0x8A: MODRM(); DONE(0, K_LOAD8);
    case 0x8B: MODRM(); DONE(0, op16 ? K_LOAD16 : K_LOAD32);
    case 0xC6: MODRM(); DONE(1, K_SKIP);
    case 0xC7: MODRM(); DONE(op16 ? 2 : 4, K_SKIP);
    case 0x80: case 0x83: case 0xC0: case 0xC1: MODRM(); DONE(1, K_SKIP);
    case 0x81: MODRM(); DONE(op16 ? 2 : 4, K_SKIP);
    case 0x69: MODRM(); DONE(op16 ? 2 : 4, K_SKIP);
    case 0x6B: MODRM(); DONE(1, K_SKIP);
    case 0x84: case 0x85: case 0x86: case 0x87: case 0xD0: case 0xD1: case 0xD2: case 0xD3: case 0xFE: MODRM(); DONE(0, K_SKIP);
    case 0xF6: MODRM(); DONE(m.reg < 2 ? 1 : 0, K_SKIP);
    case 0xF7: MODRM(); DONE(m.reg < 2 ? (op16 ? 2 : 4) : 0, K_SKIP);
    case 0xFF: MODRM(); if (m.reg == 6) DONE(0, K_PUSH0); if (m.reg <= 2) DONE(0, K_SKIP); return 0;      /* inc dec call; push m32 pushes 0 */
    default:
        if (op < 0x40 && (op & 7) < 4) { MODRM(); DONE(0, K_SKIP); }         /* add/or/adc/sbb/and/sub/xor/cmp r,r/m and r/m,r */
        return 0;
    }
#undef MODRM
#undef DONE
}

static void set_gpr(CONTEXT *c, int r, DWORD v, DWORD mask) {
    DWORD *p = 0;
    switch (r) { case 0: p = &c->Eax; break; case 1: p = &c->Ecx; break; case 2: p = &c->Edx; break; case 3: p = &c->Ebx; break;
                 case 4: p = &c->Esp; break; case 5: p = &c->Ebp; break; case 6: p = &c->Esi; break; default: p = &c->Edi; break; }
    *p = (*p & ~mask) | (v & mask);
}

static unsigned long imgsize;      /* SizeOfImage of the exe: the only range in which a word can be a return address (probing v - 5 outside it would fault inside the handler) */
static int strict_mode(void) { static int v = -1; if (v < 0) { char e[4]; v = GetEnvironmentVariableA("TUROK_STRICT", e, sizeof e) ? 1 : 0; } return v; }

static void log_once(HANDLE h, const char *what, EXCEPTION_POINTERS *ep, unsigned long eip_rva, unsigned long acc, unsigned long addr) {
    static unsigned long seen[256]; static int n; static volatile LONG total; int i; char b[200]; DWORD w; int l;
    InterlockedIncrement(&total);
    for (i = 0; i < n; i++) if (seen[i] == eip_rva + acc * 0x10000000ul) return;
    if (n >= 256) return;
    seen[n++] = eip_rva + acc * 0x10000000ul;
    if (h == INVALID_HANDLE_VALUE) return;
    l = wsprintfA(b, "SOFTFAULT %s acc=%lu addr=%08lX rva=%lX eax=%08lX ecx=%08lX edx=%08lX esi=%08lX edi=%08lX\r\n  stack rvas:", what, acc, addr, eip_rva,
                  ep->ContextRecord->Eax, ep->ContextRecord->Ecx, ep->ContextRecord->Edx, ep->ContextRecord->Esi, ep->ContextRecord->Edi);
    WriteFile(h, b, l, &w, NULL);
    {   /* return addresses (words right after a call instruction) on the thread's stack: who was running */
        unsigned long base = (unsigned long)GetModuleHandleA(NULL), *sp = (unsigned long *)ep->ContextRecord->Esp;
        unsigned long *top = (unsigned long *)((NT_TIB *)NtCurrentTeb())->StackBase; int k = 0;
        for (i = 0; i < 4096 && sp + i < top && k < 8; i++) {
            unsigned long v = sp[i];
            if (imgsize && v > base + 8 && v < base + imgsize && *(unsigned char *)(v - 5) == 0xE8) { l = wsprintfA(b, " %lX", v - base); WriteFile(h, b, l, &w, NULL); k++; }
        }
        WriteFile(h, "\r\n", 2, &w, NULL);
    }
}

/* 1 = fault repaired, execution may continue */
int port_soft_fault(EXCEPTION_POINTERS *ep, HANDLE log) {
    EXCEPTION_RECORD *er = ep->ExceptionRecord; CONTEXT *c = ep->ContextRecord;
    unsigned long acc, addr, base = (unsigned long)GetModuleHandleA(NULL);
    if (er->ExceptionCode != 0xC0000005 || er->NumberParameters < 2 || strict_mode()) return 0;
    acc = (unsigned long)er->ExceptionInformation[0]; addr = (unsigned long)er->ExceptionInformation[1];
    if (!imgsize) { const IMAGE_NT_HEADERS *nt = (const IMAGE_NT_HEADERS *)(base + ((const IMAGE_DOS_HEADER *)base)->e_lfanew); imgsize = nt->OptionalHeader.SizeOfImage; }
    if (acc == 8) {                                           /* call through a NULL function pointer: return 0 to the caller */
        unsigned long ip = (unsigned long)er->ExceptionAddress;
        if (ip >= 0x10000ul || c->Esp < 0x10000ul) return 0;
        log_once(log, "call", ep, ip, acc, addr);
        c->Eip = *(DWORD *)c->Esp; c->Esp += 4; c->Eax = 0;
        return 1;
    }
    if (addr >= 0x10000ul) return 0;
    {   unsigned long ip = (unsigned long)er->ExceptionAddress; Insn in; const unsigned char *p = (const unsigned char *)ip;
        if (ip < base || ip >= base + imgsize) return 0;      /* port glue or system code probing memory on purpose */
        if (!decode(p, &in)) return 0;
        switch (in.kind) {
        case K_LOAD32: set_gpr(c, in.reg, 0, 0xFFFFFFFFul); break;
        case K_LOAD16: set_gpr(c, in.reg, 0, 0xFFFFul); break;
        case K_LOAD8: if (in.reg < 4) set_gpr(c, in.reg, 0, 0xFFul); else set_gpr(c, in.reg - 4, 0, 0xFF00ul); break;
        case K_LOADX:
            if ((c->ContextFlags & CONTEXT_EXTENDED_REGISTERS) != CONTEXT_EXTENDED_REGISTERS) return 0;
            memset(&c->ExtendedRegisters[160 + 16 * in.reg], 0, 16); break;
        case K_PUSH0: c->Esp -= 4; *(DWORD *)c->Esp = 0; break;
        default: break;
        }
        log_once(log, in.kind >= K_LOAD32 && in.kind != K_PUSH0 ? "load" : "store", ep, ip - base, acc, addr);
        c->Eip = (DWORD)(ip + in.len);
        return 1;
    }
}
