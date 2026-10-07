#include "b14_types.h"
typedef struct { s8 a; s8 b; s8 c; s8 d; } B14SEnt;
typedef struct {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 pad4[4];
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ s32 f1C;
    /* 0x20 */ s32 f20;
    /* 0x24 */ s32 f24;
    /* 0x28 */ s32 f28;
    /* 0x2C */ B14SEnt ent[32];
    /* 0xAC */ u8 padAC[0x18];
    /* 0xC4 */ s8 fC4;
    /* 0xC5 */ s8 fC5;
} B14CtlS;
extern f32 D_800C93E4;
extern f32 D_800C93E8;
extern f32 D_800C93EC;
extern f32 D_800C93F0;
extern f32 D_800C93F4;
void func_00263E1C(B14CtlS *c, s8 x, s8 y, s32 btn) {
    u32 b;
    f32 fx, fy;
    s32 prev;
    s32 pressed;
    s32 m;
    s32 i;
    u8 old;
    B14SEnt *e;
    if (c->f0 != 0) {
        b = btn & 0xFFFF;
        if (x < -30) {
            b |= 0x20000;
        } else if (x >= 31) {
            b |= 0x40000;
        }
        if (y < -30) {
            b |= 0x80000;
        } else if (y >= 31) {
            b |= 0x10000;
        }
        if (x > 0) {
            x = x - 3;
            if (x < 0) {
                x = 0;
            }
        } else {
            x = x + 3;
            if (x > 0) {
                x = 0;
            }
        }
        if (y > 0) {
            y = y - 3;
            if (y < 0) {
                y = 0;
            }
        } else {
            y = y + 3;
            if (y > 0) {
                y = 0;
            }
        }
        fx = x;
        fy = y;
        if (fx == D_800C93E4) {
            fx = D_800C93E8;
        }
        if (fy == D_800C93E4) {
            fy = D_800C93EC;
        }
        if (fx < D_800C93F0) {
            fx = D_800C93F0;
        }
        if (D_800C93F4 < fx) {
            fx = D_800C93F4;
        }
        if (fy < D_800C93F0) {
            fy = D_800C93F0;
        }
        if (D_800C93F4 < fy) {
            fy = D_800C93F4;
        }
        prev = c->f18;
        c->fC4 = (s32)fx;
        c->fC5 = (s32)fy;
        c->f18 = b;
        c->f14 = prev;
        pressed = (prev ^ b) & b;
        c->f1C |= pressed;
        c->f28 |= pressed;
        m = 1;
        e = c->ent;
        i = 0x13;
        do {
            if (pressed & m) {
                if (e->b < 0x1E) {
                    e->b = 0;
                    e->a++;
                    if (e->a >= 2) {
                        c->f24 |= m;
                        e->a = 0;
                    }
                } else {
                    e->a = 1;
                    e->b = 0;
                }
            }
            e->b++;
            if (e->b >= 0x1F) {
                e->b = 0x1E;
            }
            if (b & m) {
                if (e->d >= 0) {
                    e->d += 2;
                }
                old = e->c;
                e->c = old - 1;
                if (e->c < 0) {
                    e->c = old + 4;
                    c->f28 |= m;
                }
            } else {
                if ((u8)e->d < 0x11 && (c->f14 & m)) {
                    c->f20 |= m;
                }
                e->d = 0;
                c->f28 &= ~m;
                e->c = 0x30;
            }
            e++;
            m <<= 1;
        } while (i-- != 0);
    }
}
