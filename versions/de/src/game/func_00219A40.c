#include "common.h"

#define W(o, off) (*(s32 *)((u8 *)(o) + (off)))
#define F(o, off) (*(f32 *)((u8 *)(o) + (off)))
#define U8(o, off) (*(u8 *)((u8 *)(o) + (off)))
#define U16(o, off) (*(u16 *)((u8 *)(o) + (off)))
#define P(o, off, T) (*(T *)((u8 *)(o) + (off)))

extern f32 D_800C73C0[];
extern f32 D_800C73C8;
extern f32 D_800C73CC;
extern f32 D_800C73D0;
extern s32 D_80102AE0[];
extern u8 D_8011FE88[];
extern u8 D_80121990[];
extern u8 D_8013B364[];
extern u8 D_80145040[];
extern s32 D_801462C8;
typedef struct { s32 pad[21]; s32 f54; s32 pad2[8]; s32 f78; } G68A0;
extern G68A0 D_801468A0[];
extern s32 D_801468C4;
extern s32 D_801468CC[];
extern s32 D_801468F4;
extern s32 D_80146918;

f32 sinf(f32);
f32 cosf(f32);
void *func_0020CFE0(void *, s32);
void func_00219688(void *, void *, void *);
void func_0021BFBC(void *, void *, s32, s32, s32);
void func_002297F0(void *, f32);
void func_00229F74(void *, void *);
s32 func_0022A590(void *, void *);
s32 func_0022ABF0(void *);
s32 func_0022B168(void *, void *, s32);
s32 func_00245774();
s32 func_00245788();
void func_00282A18(void *, void *);
void func_002830A0(void *, void *);
void *func_0028B2D4(void *, s32);
s32 func_002A11E8();

void func_00219A40(void *arg0, void *arg1, void *arg2) {
    void *s1;
    void *s2;
    void *s0;
    s32 s3;
    s32 s5;
    s32 s6;
    void *a0;
    register void *e12 asm("$3");
    void *a1;
    void *obj;
    s32 v;
    s32 t;
    f32 fs0;
    f32 fv1;
    f32 fc;
    s32 one;
    s32 *pp;
    void *st0;
    f32 fx;
    void *ev;
    void *ev2;

    s2 = NULL;
    s3 = -1;
    if (func_00245788() == 0 && func_00245774() == 0 && !(D_801462C8 & 1)) {
        s1 = P(arg0, 0x1D8, void *);
        a1 = P(s1, 0x14, void *);
        s6 = W(s1, 0x5E4) > 0;
        if (a1 != NULL && (obj = func_0028B2D4(D_8011FE88, (s32)a1)) != NULL && (U16(obj, 0x52) & 0x40) != 0) {
            v = 1;
        } else {
            v = 0;
        }
        if (v != 0) {
            s3 = 0x17;
        }
        if (*(s16 *)((u8 *)s1 + 0x650) == 0x20) {
            s3 = 0x20;
        }
        if (arg2 != NULL) {
            ev = P(arg2, 0, void *);
            if (ev != NULL && U8(ev, 0) == 2) {
                t = U16(ev, 4);
                switch (t) {
                case 0x41B:
                case 0x41C:
                case 0x41D:
                case 0x4DD:
                case 0x4DE:
                case 0x4DF:
                    if (W(s1, 0x5E4) > 0) {
                        func_002297F0(s1, 2.5f);
                    }
                    return;
                case 0x405:
                case 0x4DA:
                    if (W(s1, 0x5E4) > 0) {
                        fx = F(s1, 0x11E0) + D_800C73C0[1];
                        F(s1, 0x11E0) = (fx < D_800C73C8) ? D_800C73C8 : fx;
                    }
                    W(arg2, 4) = 0x100;
                    break;
                case 0x402:
                case 0x404:
                case 0x43C:
                    if (W(s1, 0x122C) & 0x1000) {
                        if (W(s1, 0x5E4) <= 0) {
                            W(arg2, 4) = 0;
                        } else {
                            s32 sum = W(s1, 0x5E4) + W(arg2, 4);
                            s32 m = func_0022ABF0(s1);
                            if (sum < m) {
                                m = sum;
                            }
                            W(s1, 0x5E4) = m;
                            W(arg2, 4) = 0;
                        }
                    }
                    break;
                case 0x432:
                case 0x4E3:
                    W(arg2, 4) = 0;
                    break;
                default:
                    break;
                }
            }
        }
        func_00229F74(s1, arg2);
        func_0021BFBC(s1, arg0, W(arg2, 4), W(arg2, 0xC), s3);
        ev = P(arg2, 0, void *);
        one = 1;
        if (ev != NULL) {
            switch (U8(ev, 0)) {
            case 2:
                s0 = ev;
                a1 = P(ev, 0x12C, void *);
                if (a1 != NULL) {
                    if (U8(a1, 0) == one) {
                        if (W(a1, 0x100) & 0x300000) {
                            s2 = a1;
                        } else if (U16(a1, 0xE4) == 0x40C) {
                            s2 = P(a1, 0x1D8, void *);
                        }
                    }
                    t = U16(s0, 4);
                    if ((t == 0x3EB || t == 0x416) && s6 != 0 && func_0022B168(s1, a1, one) != 0) {
                        void *st = P(s2, 0x5D8, void *);
                        U16(st, 0xA) = U16(st, 0xA) + 1;
                    }
                    fs0 = sinf(F(arg0, 0x6C));
                    fc = cosf(F(arg0, 0x6C));
                    fv1 = (F(s1, 8) - F(s0, 8)) * -fs0 + (F(s1, 0x10) - F(s0, 0x10)) * -fc;
                    if (fv1 < D_800C73CC) {
                        U8(s1, 0x13C4) = 1;
                    } else if (D_800C73D0 < fv1) {
                        U8(s1, 0x13C4) = 2;
                    } else {
                        U8(s1, 0x13C4) = 0;
                    }
                }
                break;
            case 1:
                if (W(ev, 0x100) & 0x300000) {
                    s2 = P(ev, 0x1D8, void *);
                }
                U8(s1, 0x13C4) = 0;
                break;
            }
        } else {
            s2 = s1;
        }
        if (s2 == NULL) goto done;
        if (arg2 != NULL) {
            ev = P(arg2, 0, void *);
            ev2 = ev;
            if (ev != NULL && U8(ev, 0) == 2) {
                switch (U16(ev, 4)) {
                case 0x404:
                case 0x40F:
                    goto e9c;
                case 0x402:
                case 0x427:
                    goto e94;
                }
                if (!(W(arg2, 0xC) & 0x100000)) {
                    D_80102AE0[W(s2, 0x5D4)] = D_80102AE0[W(s2, 0x5D4)] + 1;
                }
            } else if (({ __asm__(""); ev2; }) != NULL && U8(ev2, 0) == 1 && (W(ev2, 0x100) & 0x300000)) {
                void *tg = P(ev2, 0x1D8, void *);
                if (!(W(arg2, 0xC) & 0x100000)) {
                    D_80102AE0[W(tg, 0x5D4)] = D_80102AE0[W(tg, 0x5D4)] + 1;
                }
            }
        }
e94:
        if (s2 == NULL) goto done;
e9c:
        if (s2 != s1 && W(s1, 0x1450) != 0) {
            W(P(s1, 0x1454, void *), 0x328) = (s32)s2;
            W(P(s1, 0x1454, void *), 0x324) = 0x1F4;
        }
        if (s2 != NULL && W(s1, 0x5E4) == 0) {
            st0 = P(s1, 0x5D8, void *);
            if (U8(st0, 0x8D) == 0) {
                U8(st0, 0x8D) = 1;
                s5 = func_0022A590(D_80145040, s2);
                a0 = P(s1, 0x5D8, void *);
                if (U8(a0, 0x8F) == 1 && W(D_80145040, 0x18B4) != 0) {
                    s32 j2 = s5 * 2;
                    U16((u8 *)a0 + j2, 0xC) = U16((u8 *)a0 + j2, 0xC) + 1;
                } else {
                    { s32 i2 = s5 * 2; void *st = P(s1, 0x5D8, void *); U16((u8 *)st + i2, 0x2C) = U16((u8 *)st + i2, 0x2C) + 1; }
                }
                s3 = func_0022A590(D_80145040, s1);
                if (U8(P(s1, 0x5D8, void *), 0x8F) == 1 && W(D_80145040, 0x18B4) != 0) {
                    { s32 i2 = s3 * 2; void *st = P(s2, 0x5D8, void *); U16((u8 *)st + i2, 0x1C) = U16((u8 *)st + i2, 0x1C) + 1; }
                } else {
                    { s32 i2 = s3 * 2; void *st = P(s2, 0x5D8, void *); U16((u8 *)st + i2, 0x3C) = U16((u8 *)st + i2, 0x3C) + 1; }
                }
                func_00219688(s1, s2, arg2);
                if (s2 != NULL) {
                    s32 n = W(s2, 0x1338) + 1;
                    W(s2, 0x1338) = n % 8;
                    { s32 *q = (s32 *)s2 + 0x4B3; q[n % 8] = (s32)s1; }
                    { s32 *q = (s32 *)s2 + 0x4BD; q[W(s2, 0x1338)] = 0xFF; }
                }
                if (s1 != NULL) {
                    W(s1, 0x12EC) = (s32)s2;
                    W(s1, 0x12F0) = func_002A11E8() % 7;
                }
                if (s5 == s3) {
                    { void *st = P(s1, 0x5D8, void *); U16(st, 0) = U16(st, 0) + 1; }
                    { void *st = P(s1, 0x5D8, void *); U16(st, 4) = U16(st, 4) - 1; }
                    if (D_801468C4 != 0) {
                        v = U8(P(s1, 0x5D8, void *), 0x92);
                        if (v >= 0) {
                            if (v < 5) {
                                pp = &D_801468CC[v];
                                if (D_80146918 == 0) {
                                    if (D_801468F4 == 0) goto dec;
                                }
                            }
                        }
                    }
                } else {
                    { void *st = P(s1, 0x5D8, void *); U16(st, 2) = U16(st, 2) + 1; }
                    e12 = func_0020CFE0(D_8013B364, W(P(s1, 0x1454, void *), 4));
                    W(e12, 0x38) = W(e12, 0x38) + 1;
                    e12 = func_0020CFE0(D_8013B364, W(P(s2, 0x1454, void *), 4));
                    W(e12, 0x3C) = W(e12, 0x3C) + 1;
                    if (U8(P(s1, 0x5D8, void *), 0x8F) == 1) {
                        if (D_801468A0->f54 != 0) {
                            void *e3 = P(s2, 0x5D8, void *);
                            W(s2, 0x12C4) = (s32)s1;
                            U16(e3, 6) = U16(e3, 6) + 1;
                            { void *st = P(s2, 0x5D8, void *); U16(st, 4) = U16(st, 4) + 1; }
                            if (D_801468C4 != 0) {
                                s32 c0 = U8(P(s2, 0x5D8, void *), 0x92);
                                s32 c1 = U8(P(s1, 0x5D8, void *), 0x92);
                                if (c0 >= 0) {
                                    if (c0 < 5) {
                                        pp = &D_801468CC[c0];
                                        if (c1 != c0) {
                                            *pp = *pp + 1;
                                        }
                                    }
                                }
                            }
                            goto fin;
                        } else if (D_801468A0->f78 != 0) {
                            W(s2, 0x12C8) = (s32)s1;
                            goto fin;
                        }
                    }
                    if (D_801468C4 != 0) {
                        a0 = P(s2, 0x5D8, void *);
                        if (U8(a0, 0x92) == U8(P(s1, 0x5D8, void *), 0x92)) {
                            U16(a0, 4) = U16(a0, 4) - 1;
                        } else {
                            U16(a0, 4) = U16(a0, 4) + 1;
                        }
                    } else {
                        { void *st = P(s2, 0x5D8, void *); U16(st, 4) = U16(st, 4) + 1; }
                    }
                    if (D_801468C4 != 0) {
                        s32 c0 = U8(P(s2, 0x5D8, void *), 0x92);
                        s32 c1 = U8(P(s1, 0x5D8, void *), 0x92);
                        if (c0 >= 0) {
                            if (c0 < 5) {
                                pp = &D_801468CC[c0];
                                if (c1 != c0) {
                                    *pp = *pp + 1;
                                } else {
dec:
                                    *pp = *pp - 1;
                                }
                            }
                        }
                    }
                }
fin:
                func_00282A18(D_80121990, s1);
                func_002830A0(D_80121990, s1);
            }
        }
    }
done:
    return;
}
