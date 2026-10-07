#include "b05_types.h"

typedef struct B05P11 {
    u8 pad0[0xE4];
    /* 0x0E4 */ u16 unkE4;
    u8 padE6[0x1E];
    /* 0x104 */ f32 f104;
    u8 pad108[0x6];
    /* 0x10E */ s8 b10E;
    u8 pad10F[0x595];
    /* 0x6A4 */ f32 f6A4;
    /* 0x6A8 */ f32 f6A8;
    u8 pad6AC[0x4];
    /* 0x6B0 */ u32 flags6B0;
    u8 pad6B4[0x30];
    /* 0x6E4 */ f32 f6E4;
    u8 pad6E8[0x30];
    /* 0x718 */ f32 f718;
    u8 pad71C[0xCC];
    /* 0x7E8 */ s32 unk7E8;
    u8 pad7EC[0x80];
    /* 0x86C */ s32 st;
    u8 pad870[0x968];
    /* 0x11D8 */ f32 f11D8;
    u8 pad11DC[0x1D8];
    /* 0x13B4 */ void* tab13B4;
} B05P11;

typedef struct B05A11 {
    u8 pad0[0x18];
    /* 0x018 */ void* def;
    u8 pad1C[0x1C];
    /* 0x038 */ u32 flags38;
    u8 pad3C[0x30];
    /* 0x06C */ f32 ang;
} B05A11;

typedef struct B05Def11 { u8 pad0[0x14]; u32 flags14; } B05Def11;

extern f32 D_800C7A90;
extern f32 D_800C7A94;
extern f32 D_800C7A98;
extern f32 D_800C7A9C;
extern f32 D_800C7AA0;
extern f32 D_800C7AA4;
extern f32 D_800C7AA8;
extern f32 D_800C7AAC;
extern s32 D_800CE47C;
extern u8 D_800CE7E4[];
extern u8 D_800CE7FC[];
extern u8 D_800CED30[];

void func_00223E10(B05P11 *, B05A11 *);
void func_002231B0(B05P11 *, B05A11 *, void *);
s32 func_002227D0(B05P11 *, B05A11 *, s32);

void func_002243E4(B05P11 *p, B05A11 *a) {
    f32 ang0;
    f32 dang;
    s32 high;
    s32 ok;
    s32 ok2;
    s32 v;

    func_00223E10(p, a);
    ang0 = a->ang;
    high = p->f718 > D_800C7A90;
    if (high) {
        func_002231B0(p, a, D_800CE7FC);
    } else {
        func_002231B0(p, a, D_800CE7E4);
    }
    dang = a->ang - ang0;
    if (p->unk7E8 == 0 && !(p->f6E4 > D_800C7A94) && !(a->flags38 & 0xC0000) &&
        (((B05Def11 *)a->def)->flags14 & 2) && (p->flags6B0 & 0x10) && p->f11D8 <= 0.0f) {
        func_002227D0(p, a, 5);
        ok2 = 1;
    } else {
        ok2 = 0;
    }
    if (ok2 == 0) {
        if (p->f6A4 != 0.0f || (p->unk7E8 != 2 && p->f6A8 != 0.0f)) {
            func_002227D0(p, a, 3);
        }
        ok = 1;
        if (p->st == 0x1130 || p->st == 0x1135) {
            if (p->b10E == 0) {
                ok = 0;
            }
        }
        if (p->st == 0x5E56 || p->st == 0x5E5E) {
            if (p->b10E == 0) {
                ok = 0;
            }
        }
        if (p->st == 0xFA0 || p->st == 0x1004) {
            if (p->b10E == 0) {
                ok = 0;
            }
        }
        if (ok) {
            if (p->unkE4 == D_800CE47C) {
                if (p->st == 1 && p->f104 >= D_800C7A98) {
                    p->st = 2;
                } else if (p->st == 2 && p->f104 >= D_800C7A9C) {
                    p->st = 1;
                } else if ((u32)(p->st - 1) >= 2) {
                    p->st = 1;
                }
            } else if (p->tab13B4 == D_800CED30) {
                if (a->flags38 & 0xC0000) {
                    p->st = 0xA28;
                } else if (D_800C7AA0 < dang) {
                    p->st = 0x5E26;
                } else if (dang < D_800C7AA4) {
                    p->st = 0x5E25;
                } else {
                    p->st = 0x5E24;
                }
            } else {
                if (a->flags38 & 0xC0000) {
                    p->st = 0xA28;
                } else if (D_800C7AA8 < dang) {
                    p->st = 0xB5E;
                } else if (dang < D_800C7AAC) {
                    p->st = 0xB54;
                } else {
                    p->st = 1;
                }
            }
        }
    }
}
