#include "b05_types.h"

typedef struct B05P16 {
    u8 pad0[0xE4];
    /* 0x0E4 */ u16 unkE4;
    u8 padE6[0x1E];
    /* 0x104 */ f32 f104;
    u8 pad108[0x5A8];
    /* 0x6B0 */ u32 flags6B0;
    u8 pad6B4[0xC];
    /* 0x6C0 */ f32 f6C0;
    /* 0x6C4 */ f32 f6C4;
    /* 0x6C8 */ f32 f6C8;
    u8 pad6CC[0x4];
    /* 0x6D0 */ s32 unk6D0;
    u8 pad6D4[0x10];
    /* 0x6E4 */ f32 f6E4;
    u8 pad6E8[0x30];
    /* 0x718 */ f32 f718;
    u8 pad71C[0x10];
    /* 0x72C */ f32 f72C;
    u8 pad730[0xB8];
    /* 0x7E8 */ s32 unk7E8;
    u8 pad7EC[0x80];
    /* 0x86C */ s32 st;
    u8 pad870[0x954];
    /* 0x11C4 */ f32 f11C4;
    u8 pad11C8[0x10];
    /* 0x11D8 */ f32 f11D8;
    u8 pad11DC[0x1D8];
    /* 0x13B4 */ void* tab13B4;
} B05P16;

typedef struct B05A16 { u8 pad0[0x18]; void *def; u8 pad1C[0x1C]; u32 flags38; } B05A16;
typedef struct B05Def16 { u8 pad0[0x14]; u32 flags14; } B05Def16;

extern f32 D_800C7AB0;
extern f32 D_800C7AB4;
extern f32 D_800C7AB8;
extern f32 D_800C7ABC;
extern f32 D_800C7AC0;
extern f32 D_800C7AC4;
extern f32 D_800C7AC8;
extern f32 D_800C7ACC;
extern f32 D_800C7AD0;
extern f32 D_800C7AD4;
extern f32 D_800C7AD8;
extern f32 D_800C7ADC;
extern f32 D_800C7AE0;
extern f32 D_800C7AE4;
extern f32 D_800C7AE8;
extern f32 D_800C7AEC;
extern s32 D_800CE47C[];
extern u8 D_800CE730[];
extern u8 D_800CE7C0[];
extern u8 D_800CE7E4[];
extern u8 D_800CE7FC[];
extern u8 D_800CED30[];
extern f32 D_800D2988;

void func_00224028(B05P16 *, B05A16 *);
void func_002231B0(B05P16 *, B05A16 *, void *);
void func_002233CC(B05P16 *, B05A16 *, void *);
s32 func_002227D0(B05P16 *, B05A16 *, s32);
void func_002748E0(void *, f32, f32);

void func_002246E8(B05P16 *p, B05A16 *a) {
    f32 t;
    f32 av;
    f32 bv;
    s32 high;
    s32 ok;
    s32 s;
    s32 *tb;

    func_00224028(p, a);
    func_002748E0(&p->f72C, 0.0f, 0.25f);
    high = p->f718 > D_800C7AB0;
    if (high) {
        func_002231B0(p, a, D_800CE7FC);
    } else {
        func_002231B0(p, a, D_800CE7E4);
    }
    high = p->f718 > D_800C7AB4;
    if (high) {
        func_002233CC(p, a, D_800CE7C0);
    } else {
        func_002233CC(p, a, D_800CE730);
    }
    if (p->unk7E8 == 0 && !(p->f6E4 > D_800C7AB8) && !(a->flags38 & 0xC0000) &&
        (((B05Def16 *)a->def)->flags14 & 2) && (p->flags6B0 & 0x10) && p->f11D8 <= 0.0f) {
        func_002227D0(p, a, 5);
        ok = 1;
    } else {
        ok = 0;
    }
    if (ok == 0) {
        if (p->f6C0 == 0.0f && p->f6C4 == 0.0f) {
            func_002227D0(p, a, 2);
        }
        if ((a->flags38 & 0x5000) == 0x4000 && p->unk6D0 != 0) {
            t = p->f11C4 + D_800D2988;
            p->f11C4 = t;
            if (p->f6C8 > D_800C7ABC && t >= D_800C7AC0) {
                p->f11C4 = t - D_800C7AC0;
            }
        }
        tb = D_800CE47C;
        if (p->unkE4 == tb[0]) {
            if (p->st != 0x7DA) {
                p->st = 0x7DA;
            } else if (p->f104 >= D_800C7AC4) {
                p->st = 0x7DB;
            } else {
                p->st = 0x7DA;
            }
        } else if (p->unkE4 != tb[-2] ||
                   ((p->st != 0xFA0 || !(p->f104 < D_800C7AC8)) &&
                    (p->st != 0x1004 || !(p->f104 < D_800C7ACC)))) {
            if (a->flags38 & 0xC0000) {
                if (p->f6C0 >= 0.0f) {
                    p->st = 0xA32;
                } else {
                    p->st = 0xA37;
                }
            } else {
                av = p->f6C0;
                if (av < 0.0f) {
                    av = -av;
                }
                bv = p->f6C4;
                if (bv < 0.0f ? av < -bv : av < bv) {
                    if (p->f6C4 < 0.0f) {
                        if (p->tab13B4 == D_800CED30) {
                            s = p->st;
                            if ((u32)(s - 0x5E56) < 7) {
                                if (p->f104 >= D_800C7AD0) {
                                    p->st = 0x5E2B;
                                }
                            } else if (s == 0x5E5E) {
                                if (p->f104 >= D_800C7AD4) {
                                    p->st = 0x5E2B;
                                }
                            } else {
                                p->st = 0x5E2B;
                            }
                        } else {
                            p->st = 0x802;
                        }
                    } else {
                        if (p->tab13B4 == D_800CED30) {
                            s = p->st;
                            if ((u32)(s - 0x5E56) < 7) {
                                if (p->f104 >= D_800C7AD8) {
                                    p->st = 0x5E2C;
                                }
                            } else if (s == 0x5E5E) {
                                if (p->f104 >= D_800C7ADC) {
                                    p->st = 0x5E2C;
                                }
                            } else {
                                p->st = 0x5E2C;
                            }
                        } else {
                            p->st = 0x80C;
                        }
                    }
                } else {
                    if (p->f6C0 >= 0.0f) {
                        if (p->tab13B4 == D_800CED30) {
                            s = p->st;
                            if ((u32)(s - 0x5E56) < 9) {
                                if (p->f104 >= D_800C7AE0) {
                                    p->st = 0x5E29;
                                }
                            } else if (s == 0x5E5E) {
                                if (p->f104 >= D_800C7AE4) {
                                    p->st = 0x5E29;
                                }
                            } else {
                                p->st = 0x5E29;
                            }
                        } else {
                            p->st = 0x7DA;
                        }
                    } else {
                        if (p->tab13B4 == D_800CED30) {
                            s = p->st;
                            if ((u32)(s - 0x5E56) < 7) {
                                if (p->f104 >= D_800C7AE8) {
                                    p->st = 0x5E2A;
                                }
                            } else if (s != 0x5E5E || p->f104 >= D_800C7AEC) {
                                p->st = 0x5E2A;
                            }
                        } else {
                            p->st = 0x7DF;
                        }
                    }
                }
            }
        }
    }
}
