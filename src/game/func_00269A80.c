/* func_00269A80 (ROM 0x6A680, 1134 insns): material / texture state setup that emits the RDP display list words.  chk (flags @SN): EXACT, ro=0xCA2B4:164.
 *
 * What it took (round 9 s901 got to 5 words; the lead finished it):
 *  - the n1 temp of the default arm of switch (idx) is `lw a1,44(sp)` in the ROM.  It must be its OWN pseudo (a variable shared with the later c1 gives v1),
 *    and a temp that dies in the div/mod insn inherits the preference of that insn's result v (a3) and merges the arm's tail with case -1's.  Copying it to a
 *    local register variable pinned to $5 and consuming that with an empty volatile asm after the division gives it a copy preference for a1 that wins
 *    (the move becomes a no-op and disappears), without emitting any code.
 *  - the later c1 (8th argument of func_00295FB4) is v1 in the ROM and c0 is t0: the c1 pseudo lost its extra priority when it stopped being shared with the arm,
 *    so it is pinned to $3 (the pin only matters while c1 is live).
 *  - older lessons (wip/out/FINDINGS.txt of s901): s32 zero (the jump.c store-flag blocker), the rand arm copies inside the condition, a dead `c0 = zero;`
 *    before the final return keeps both ORs of c0/c1.
 * The pins and the empty asm emit no code; build_clang strips the `register ... asm("$N")` pins for the PC build and the empty asm is harmless there.
 */
#include "s901_types.h"

s32 func_00296EC4(void *, s32);
void func_00296F7C(s32, S9Info *);
void func_00295FB4(void *, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_00274544(void);
void func_00268CE0(u32);
void func_002536F4(s32, s32);
s32 func_0026925C(u32);

extern s32 D_80110620;
extern s32 D_801462C8;
extern u32 D_800D2980;
extern P4Gfx *D_80110634;
extern s32 D_800D15E0;
extern S9Col D_800D15E4;
extern u8 D_800D15F8;
extern u8 D_800D15F9;
extern u8 D_800D15FA;
extern u8 D_800D15FB;
extern u8 D_800D15FC;
extern u8 D_800D15FD;
extern s32 D_800D15C8;
extern s32 D_800D15CC;
extern u32 D_800D15D4;

#define F2B(f) ((u32)(f) & 0xFF)
#define GREY(a, b, c) (((((u32)((a) + (b) + (c)) / 3) << 8)) & 0xFF00)

s32 func_00269A80(S9Obj *o, s32 idx) {
    u32 flags;
    s32 mode;
    s32 zero;
    s32 tex;
    S9Info info;
    s32 u, v;
    s32 w, h;
    s32 c0;
    register s32 c1 __asm__("$3");
    s32 n1;
    u32 alpha;
    u32 t1, t2, t3;
    s32 t5;
    u32 k1, k2;
    u32 a1v;
    u32 a3v;
    P4Gfx *g0;
    P4Gfx *g1;
    P4Gfx *g2;
    P4Gfx *g3;
    P4Gfx *g4;
    P4Gfx *g5;
    P4Gfx *g6;
    P4Gfx *g7;
    P4Gfx *g8;
    P4Gfx *g9;
    P4Gfx *g10;
    P4Gfx *g11;
    P4Gfx *g12;
    P4Gfx *g13;
    P4Gfx *g14;
    P4Gfx *g15;
    P4Gfx *g16;
    P4Gfx *g17;
    P4Gfx *g18;
    P4Gfx *g19;
    P4Gfx *g20;
    P4Gfx *g21;
    P4Gfx *g22;
    P4Gfx *g23;
    P4Gfx *g24;
    P4Gfx *g25;

    zero = 0;
    flags = o->flags;
    if (D_80110620 != 0 && (flags & 0x8040) != 0x8000) {
        flags |= 2;
    }
    if ((flags & 0x100) && o->unk13 == 0) {
        return 0;
    }
    mode = -1;
    if (o->unk8 != 0 && !(D_801462C8 & 0x400) && (D_80110620 == 0 || !(flags & 0x8000))) {
        tex = func_00296EC4((u8 *)o + 8, idx);
        if (tex == 0) {
            return 0;
        }
        func_00296F7C(tex, &info);
        switch (idx) {
        case -2:
            if (info.n0 < 2) {
                u = 0;
                v = 0;
                break;
            }
            idx = (D_800D2980 / info.hdr->unk1) & 0xFF;
            if (o->unk7 != idx) {
                u = func_00274544() % info.n0;
                t2 = info.n1;
                if (t2 == 0 || (v = u) >= (s32)t2) {
                    v = 0;
                    o->unk7 = idx;
                } else {
                    o->unk7 = idx;
                }
                break;
            }
            u = idx % info.n0;
            if (info.n1 == 0) {
                v = 0;
            } else {
                v = idx % info.n1;
            }
            break;
        case -1:
            idx = D_800D2980 / info.hdr->unk1;
            u = idx % info.n0;
            if (info.n1 != 0) {
                v = idx % info.n1;
            } else {
                v = 0;
            }
            break;
        default: {
            register s32 p5 __asm__("$5");
            u = idx % info.n0;
            n1 = info.n1;
            if (n1 != 0) {
                v = idx % n1;
                p5 = n1;
                __asm__ volatile ("" : : "r"(p5));
            } else {
                v = 0;
            }
            break;
        }
        }
        if (flags & 0x10) {
            w = 1 << (info.hdr->unk2 + 6);
            h = 1 << (info.hdr->unk3 + 6);
        } else {
            w = o->unk18;
            h = o->unk1A;
        }
        c0 = zero;
        if (flags & 0x20) {
            c0 = 2;
        }
        c1 = c0;
        if (flags & 0x800) {
            c0 |= 1;
            c1 |= 1;
        }
        func_00295FB4((u8 *)o + 8, tex, u, v, w, h, c0, c1, 0);
        if (flags & 0x2000) {
            g0 = D_80110634++;
            g0->words.w0 = 0xE3000F00;
            g0->words.w1 = 0x10000;
        }
        if (D_80110620 != 0) {
            t1 = GREY(o->unk10, o->unk11, o->unk12);
            g1 = D_80110634++;
            g1->words.w0 = 0xFA000000 | (info.hdr->unk4 << 8);
            g1->words.w1 = t1 | o->unk13;
        } else {
            g2 = D_80110634++;
            g2->words.w0 = 0xFA000000 | (info.hdr->unk4 << 8);
            g2->words.w1 = (o->unk10 << 24) | (o->unk11 << 16) | (o->unk12 << 8) | o->unk13;
        }
        if (flags & 0x400) {
            if (D_80110620 != 0) {
                t2 = GREY(o->unk14, o->unk15, o->unk16);
                g3 = D_80110634++;
                g3->words.w0 = 0xFB000000;
                g3->words.w1 = t2 | (D_800D15E0 == 0 ? F2B((f32)o->unk13) : F2B(D_800D15E4.c3));
            } else {
                g4 = D_80110634++;
                g4->words.w0 = 0xFB000000;
                g4->words.w1 = (o->unk14 << 24) | (o->unk15 << 16) | (o->unk16 << 8) | (D_800D15E0 == 0 ? F2B((f32)o->unk13) : F2B(D_800D15E4.c3));
            }
            if (flags & 2) {
                if (flags & 0x1000) {
                    if (D_800D15E0 == 0) {
                        func_00268CE0(0);
                    } else {
                        func_00268CE0(1);
                    }
                } else {
                    func_00268CE0(2);
                }
            } else if (flags & 0x1000) {
                func_00268CE0(3);
            } else {
                func_00268CE0(4);
            }
        } else if (flags & 2) {
            if (flags & 0x2000) {
                t5 = info.hdr->unk5;
                if (t5 < 6) {
                    if (t5 >= 4) {
                        g5 = D_80110634++;
                        g5->words.w0 = 0xFB000000;
                        g5->words.w1 = (o->unk14 << 24) | (o->unk15 << 16) | (o->unk16 << 8) | o->unk17;
                        func_00268CE0(0x23);
                    } else {
                        func_00268CE0(5);
                    }
                } else {
                    func_00268CE0(5);
                }
            } else if (D_800D15E0 == 0) {
                func_00268CE0(6);
            } else {
                g6 = D_80110634++;
                g6->words.w0 = 0xFB000000;
                g6->words.w1 = (F2B(D_800D15E4.c0) << 24) | (F2B(D_800D15E4.c1) << 16) | (F2B(D_800D15E4.c2) << 8) | F2B(D_800D15E4.c3);
                switch (D_800D15E0) {
                case 1:
                case 2:
                    func_00268CE0(7);
                    break;
                case 3:
                    func_00268CE0(8);
                    break;
                case 7:
                    func_00268CE0(9);
                    break;
                case 4:
                case 5:
                    func_00268CE0(0xA);
                    break;
                case 6:
                    g7 = D_80110634++;
                    g7->words.w0 = 0xFA000000;
                    g7->words.w1 = (o->unk10 << 24) | (o->unk11 << 16) | (o->unk12 << 8) | F2B(D_800D15E4.c4);
                    func_00268CE0(0xB);
                    break;
                }
            }
        } else {
            if (flags & 0x2000) {
                switch (info.hdr->unk5) {
                default:
                    func_00268CE0(0xC);
                    break;
                case 4:
                    g8 = D_80110634++;
                    g8->words.w0 = 0xFB000000;
                    g8->words.w1 = (o->unk14 << 24) | (o->unk15 << 16) | (o->unk16 << 8) | o->unk17;
                    func_00268CE0(0x25);
                    break;
                case 5:
                    g9 = D_80110634++;
                    g9->words.w0 = 0xFB000000;
                    g9->words.w1 = (o->unk14 << 24) | (o->unk15 << 16) | (o->unk16 << 8) | o->unk17;
                    func_00268CE0(0x24);
                    break;
                }
            } else if (D_800D15E0 == 0) {
                func_00268CE0(0xD);
            } else {
                g10 = D_80110634++;
                g10->words.w0 = 0xFB000000;
                g10->words.w1 = (F2B(D_800D15E4.c0) << 24) | (F2B(D_800D15E4.c1) << 16) | (F2B(D_800D15E4.c2) << 8) | F2B(D_800D15E4.c3);
                switch (D_800D15E0) {
                case 1:
                case 2:
                    func_00268CE0(0xE);
                    break;
                case 3:
                    func_00268CE0(0xF);
                    break;
                case 7:
                    func_00268CE0(9);
                    break;
                case 4:
                case 5:
                    func_00268CE0(0x10);
                    break;
                case 6:
                    g11 = D_80110634++;
                    g11->words.w0 = 0xFA000000;
                    g11->words.w1 = (o->unk10 << 24) | (o->unk11 << 16) | (o->unk12 << 8) | F2B(D_800D15E4.c4);
                    func_00268CE0(0x11);
                    break;
                }
            }
        }
        func_002536F4(0, tex);
    } else {
        g12 = D_80110634++;
        g12->words.w0 = 0xE7000000;
        g12->words.w1 = 0;
        if (D_800D15F8 != 0) {
            if (D_800D15FC != 0) {
                g13 = D_80110634++;
                g13->words.w0 = 0xFA000000;
                g13->words.w1 = (D_800D15F9 << 24) | (D_800D15FA << 16) | (D_800D15FB << 8) | D_800D15FD;
            } else {
                g14 = D_80110634++;
                g14->words.w0 = 0xFA000000;
                g14->words.w1 = (D_800D15F9 << 24) | (D_800D15FA << 16) | (D_800D15FB << 8) | o->unk13;
            }
        } else if (D_800D15FC != 0) {
            g15 = D_80110634++;
            g15->words.w0 = 0xFA000000;
            g15->words.w1 = (o->unk10 << 24) | (o->unk11 << 16) | (o->unk12 << 8) | D_800D15FD;
        } else if (flags & 0x8000) {
            if (flags & 0x40) {
                g16 = D_80110634++;
                g16->words.w0 = 0xFA000000;
                g16->words.w1 = o->unk13 | 0xFF000000;
            } else {
                g17 = D_80110634++;
                g17->words.w0 = 0xFA000000;
                g17->words.w1 = o->unk13 | 0xFFFF0000;
            }
        } else {
            g18 = D_80110634++;
            g18->words.w0 = 0xFA000000;
            g18->words.w1 = (o->unk10 << 24) | (o->unk11 << 16) | (o->unk12 << 8) | o->unk13;
        }
        g19 = D_80110634++;
        g19->words.w0 = 0xD7000000;
        g19->words.w1 = 0;
        if (flags & 2) {
            func_00268CE0(0x12);
        } else if (D_800D15E0 == 0) {
            func_00268CE0(0x13);
        } else {
            g20 = D_80110634++;
            g20->words.w0 = 0xFB000000;
            g20->words.w1 = (F2B(D_800D15E4.c0) << 24) | (F2B(D_800D15E4.c1) << 16) | (F2B(D_800D15E4.c2) << 8) | F2B(D_800D15E4.c3);
            switch (D_800D15E0) {
            case 1:
            case 2:
                func_00268CE0(0x14);
                break;
            case 3:
                func_00268CE0(0x15);
                break;
            case 7:
                func_00268CE0(0x16);
                break;
            case 4:
            case 5:
                func_00268CE0(0x17);
                break;
            case 6:
                g21 = D_80110634++;
                g21->words.w0 = 0xFA000000;
                g21->words.w1 = (o->unk10 << 24) | (o->unk11 << 16) | (o->unk12 << 8) | F2B(D_800D15E4.c4);
                func_00268CE0(0x11);
                break;
            }
        }
    }
    if ((flags & 0x100) || D_800D15E0 == 1 || D_800D15E0 == 4 || D_800D15E0 == 6) {
        if (D_800D15E0 == 0) {
            if (flags & 0x1000) {
                mode = 3;
            } else if (flags & 0x200) {
                mode = 4;
            } else {
                mode = 1;
            }
        } else if (flags & 0x1000) {
            mode = 3;
        } else {
            mode = 5;
        }
    } else if (flags & 0x80) {
        func_0026925C(6);
    } else if (flags & 0x200) {
        mode = 7;
    } else if (D_800D15C8 != 0) {
        if (D_800D15CC != 0) {
            mode = 8;
        } else {
            mode = 9;
        }
    } else if (D_800D15CC != 0) {
        mode = 0xA;
    } else {
        mode = 0xB;
    }
    if (mode != -1) {
        func_0026925C(mode);
    }
    a1v = 0x260404;
    a3v = flags & 0x1000;
    if (a3v != 0) {
        a1v |= D_800D15D4;
    }
    g22 = D_80110634++;
    g22->words.w0 = 0xD9000000 | (~a1v & 0xFFFFFF);
    g22->words.w1 = 0;
    a1v = 0;
    if (a3v == 0) {
        a1v = D_800D15D4;
    }
    if (D_800D15E0 == 7) {
        a1v |= 0x20000;
    }
    if ((flags & 0x42) == 0) {
        a1v |= 0x20000;
    }
    a1v |= 0x200004;
    if (!(flags & 4)) {
        a1v |= 0x400;
    }
    if (flags & 0x10) {
        a1v |= 0x60000;
    }
    g23 = D_80110634++;
    g23->words.w0 = 0xD9FFFFFF;
    g23->words.w1 = a1v;
    c0 = zero;
    return 1;
}
