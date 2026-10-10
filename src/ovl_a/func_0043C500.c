#include "common.h"
/* Overlay A, ROM 0x1AA500..0x1AB54C (VRAM 0x43C500..): "cheat code" / name-entry menu helpers (21 functions) that the symbol
 * splitter glued into func_0043C4F4.  Real entries are listed in results.txt. */
typedef s32 (*Q4Fn)();
typedef struct { u8 pad0[8]; u32 f8; u8 padC[8]; void *f14; } Q4Z;
typedef struct { u8 pad[0x2D8]; u32 f2D8; } Q4G2B;
typedef struct { u8 pad[0xC]; Q4G2B *f0C; } Q4G2A;
typedef struct { u8 pad[0x20]; s32 f20; } Q4O;
typedef struct { s16 id; u8 pad2[0x1E]; s32 f20; } Q4O9;
typedef struct { u8 pad[0x14]; u8 **f14; } Q4P;
typedef struct { s32 cur; f32 timer; s32 len; u8 text[24]; } Q4T;
typedef struct { u8 pad[4]; f32 f4; } Q4E;
typedef struct { u8 pad[0x14]; s32 f14; u8 pad18[8]; s32 f20; } Q4B;
typedef struct { u8 pad[0x30]; f32 f30; f32 f34; } Q4D;
typedef struct { u8 *name; u32 pad[3]; } Q4RowN;
typedef struct { u32 mask; u32 pad[3]; } Q4RowM;
typedef struct { s32 snd; u32 pad[3]; } Q4RowS;
typedef struct { s16 snd; s16 pad[7]; } Q4RowH;
typedef struct { void *text; u32 pad[3]; } Q4RowT;
extern Q4RowN D_0044FB90[];
extern Q4RowT D_0044FB94[];
extern Q4RowM D_0044FB98[];
extern Q4RowS D_0044FB9C[];
extern Q4RowH D_0044FB9E[];
extern Q4T D_800E5CA0;
extern u32 D_801462C8;
extern u32 D_801462CC;
extern u32 q4_g62C8[] __asm__("D_801462C8");
extern u32 q4_g62CC[] __asm__("D_801462CC");
extern u8 D_801462E5;
extern u8 D_801462E6;
extern s32 D_80154030;
extern s32 D_80154034;
extern u8 D_800E5CAC[];
extern u32 D_8013B2D4[];
extern s32 D_800E28D0;
extern s32 D_800E5E70;
extern f32 D_800D2988;
extern u8 D_800D7E14[];
extern u8 D_800D7BB8[], D_800D7BBC[], D_800D7BC0[], D_800D7BC4[], D_800D7BC8[], D_800D7BCC[], D_800D7BD0[], D_800D7BD4[], D_800D7BD8[], D_800D7BDC[], D_800D7BE0[];
extern u8 D_800D7B38[], D_800D7B3C[], D_800D7B40[], D_800D7B44[];
extern u8 D_8011FAC0[];
extern u8 D_8011FE88[];
extern s32 strlen(u8 *s);
extern s32 func_0026439C();
extern s32 func_002643A8();
extern s32 func_002643C0();
extern s32 func_002934DC();
extern void func_0043DEDC();
extern void func_00293808();
extern void func_00293268();
extern void func_0044E178();
extern Q4E *func_00442F4C();
extern void func_002AB9E4(void);
extern void func_002A8DD4(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void func_004421FC();
extern void func_0025DF54(s32 a);
extern s32 func_00435F70();
extern s32 func_0043630C();
extern s32 func_00436634();
extern s32 func_00420E00();
extern s32 func_0043C1D0();
extern s32 func_00429058();
extern s32 func_004290E8();
extern s32 func_00424528();
extern s32 func_0042359C();
extern s32 func_00439390();
extern s32 func_00436FE4();
extern s32 func_00423930();
extern s32 func_00437454();
extern s32 func_0043962C();
extern s32 func_0041DF24();
extern s32 func_0042DB38();
extern s32 func_0043905C();
extern s32 func_00437868();
extern s32 func_00437B98();
extern s32 func_0042BCB0();
extern s32 func_00429B74();
extern s32 func_0041F118();
extern s32 func_0042931C();
extern s32 func_00435C54();
extern s32 func_00423B88();
extern s32 func_00439938();
extern s32 func_0042247C();
extern s32 func_00421E00();
extern s32 func_0042DFF0();
extern s32 func_0041C5EC();
extern s32 func_00421A88();
extern s32 func_0043A014();
Q4Fn func_0043C500(s32 id) {
    switch (id) {
    case 1: return func_00435F70;
    case 31: return func_0043630C;
    case 32: return func_00436634;
    case 7: return func_00420E00;
    case 8: return func_0043C1D0;
    case 10: return func_00429058;
    case 15: return func_004290E8;
    case 3: return func_00424528;
    case 4: return func_0042359C;
    case 6: return func_00439390;
    case 5: return func_00436FE4;
    case 11: return func_00423930;
    case 12: return func_00437454;
    case 13: return func_0043962C;
    case 16: return func_0041DF24;
    case 17: return func_0042DB38;
    case 18: return func_0043905C;
    case 9: return func_00437868;
    case 30: return func_00437B98;
    case 20: return func_0042BCB0;
    case 21: return func_00429B74;
    case 23: return func_0041F118;
    case 14: return func_0042931C;
    case 19: return func_00435C54;
    case 22: return func_00423B88;
    case 24: return func_00439938;
    case 25: return func_0042247C;
    case 27: return func_00421E00;
    case 26: return func_0042DFF0;
    case 29: return func_0041C5EC;
    case 28: return func_00421A88;
    case 33: return func_0043A014;
    }
    return 0;
}
void func_0043C730(Q4G2A *a) {
    s32 i;
    s32 n;
    u32 flags;
    u32 m;
    i = 0;
    n = 0;
    flags = D_801462CC;
    do {
        switch (i) {
        default:
        case 0: m = 0x10000; break;
        case 1: m = 0x20000; break;
        case 2: m = 0x40000; break;
        case 3: m = 0x80000; break;
        case 4: m = 0x100000; break;
        case 5: m = 0x200000; break;
        case 6: m = 0x800000; break;
        case 7: m = 0x400000; break;
        case 8: m = 0x1000000; break;
        case 9: m = 0x2000000; break;
        case 10: m = 0x4000000; break;
        }
        if (D_801462CC & m) goto found;
        i++;
        if (i >= 11) i = 0;
        else if (i < 0) i = 10;
        n++;
    } while (n < 11);
    i = -1;
found:
    D_80154034 = i;
    if (i != -1) {
        a->f0C->f2D8 |= 0x1800000;
    } else {
        a->f0C->f2D8 &= 0xFE7FFFFF;
    }
    if (D_801462E5 != 0) {
        a->f0C->f2D8 &= 0xFE7FFFFF;
    }
}
s32 func_0043C868(s32 a, Q4O *o) {
    s32 code;
    s32 n;
    s32 i;
    s32 r;
    u32 m;
    u8 *g;
    switch (D_80154034) {
    default:
    case 0: code = 1000; break;
    case 1: code = 2000; break;
    case 2: code = 3000; break;
    case 3: code = 4000; break;
    case 4: code = 5000; break;
    case 5: code = 6000; break;
    case 6: code = 0x1CE9; break;
    case 7: code = 0x1D4D; break;
    case 8: code = 0x1DB1; break;
    case 9: code = 0x1DB2; break;
    case 10: code = 0x1F40; break;
    }
    if (func_0026439C(o->f20)) {
        if (code == 0x1F40) {
            D_801462E6 = 1;
            func_0043DEDC(o);
            func_00293808(D_8011FAC0, 0x11);
            return 1;
        }
        if (func_002934DC()) {
            func_0044E178(D_8011FE88, code, 2);
            return 0;
        }
        g = (u8 *)&D_801462C8;
        g[0x1D] = 0;
        g[0x1E] = 1;
        func_0043DEDC(o);
        func_00293268(D_8011FAC0, code);
        return 1;
    }
    if (func_002643A8(o->f20)) {
        i = D_80154034;
        for (n = 0; n < 11; n++) {
            i--;
            if (i >= 11) i = 0;
            else if (i < 0) i = 10;
            switch (i) {
            default:
            case 0: m = 0x10000; break;
            case 1: m = 0x20000; break;
            case 2: m = 0x40000; break;
            case 3: m = 0x80000; break;
            case 4: m = 0x100000; break;
            case 5: m = 0x200000; break;
            case 6: m = 0x800000; break;
            case 7: m = 0x400000; break;
            case 8: m = 0x1000000; break;
            case 9: m = 0x2000000; break;
            case 10: m = 0x4000000; break;
            }
            if (D_801462CC & m) {
                goto found;
            }
        }
        r = -1;
        goto done;
    found:
        r = i;
        goto done;
    }
    if (func_002643C0(o->f20)) {
        i = D_80154034;
        for (n = 0; n < 11; n++) {
            i++;
            if (i >= 11) i = 0;
            else if (i < 0) i = 10;
            switch (i) {
            default:
            case 0: m = 0x10000; break;
            case 1: m = 0x20000; break;
            case 2: m = 0x40000; break;
            case 3: m = 0x80000; break;
            case 4: m = 0x100000; break;
            case 5: m = 0x200000; break;
            case 6: m = 0x800000; break;
            case 7: m = 0x400000; break;
            case 8: m = 0x1000000; break;
            case 9: m = 0x2000000; break;
            case 10: m = 0x4000000; break;
            }
            if (D_801462CC & m) {
                goto found;
            }
        }
        r = -1;
        goto done;
    }
    return 0;
done:
    D_80154034 = r;
    return 0;
}
void func_0043CB78(void) {
    D_80154030 = -1;
}
void func_0043CB8C(void *a0, Q4B *a1, void *a2, Q4D *a3) {
    f32 w;
    f32 t;
    f32 x;
    f32 t2;
    f32 alpha;
    s32 xi;
    f32 pa, pb;
    if (D_800E5CA0.timer <= 6.0f) {
        w = func_00442F4C(a0, 0)->f4;
        w = w * (f32)D_800E28D0;
        w = w * 0.0035211267f;
        t = a3->f34 * 128.0f;
        pa = (f32)D_800E5CA0.cur; pa = pa * w; pb = (f32)a1->f14; x = pb + pa;
        D_800E5E70 = -1;
        alpha = a3->f30 * t;
        xi = (s32)x;
        func_002AB9E4();
        func_002A8DD4(xi, a1->f20, (s32)((f32)xi + w), a1->f20 + 2, 0, 0, 0xFF, 0xFF, 0xFF, (u32)alpha & 0xFF);
    }
    func_004421FC(a0, a1, a2, a3);
}
s32 func_0043CD10(s32 a, Q4O9 *o) {
    f32 t;
    t = D_800E5CA0.timer + D_800D2988;
    D_800E5CA0.timer = t;
    if (15.0f <= t) {
        D_800E5CA0.timer = t - 15.0f;
    }
    if (o->id == 2) {
        if (func_002643A8(o->f20) != 0 && D_800E5CA0.cur > 0) {
            D_800E5CA0.cur--;
            *(s32 *)&D_800E5CA0.timer = 0;
        } else if (func_002643C0(o->f20) != 0) {
            if (D_800E5CA0.cur < D_800E5CA0.len) {
                D_800E5CA0.cur++;
                *(s32 *)&D_800E5CA0.timer = 0;
            }
        }
    }
    return 0;
}
s32 func_0043CDE8() {
    return 0;
}
s32 func_0043CDF0(Q4P *p) {
    s32 i;
    D_80154030 = -1;
    *(s32 *)&D_800E5CA0.timer = 0;
    if (D_800E5CA0.len == 22) return 0;
    i = 22;
    if (D_800E5CA0.cur < i) {
        do {
            D_800E5CA0.text[i] = D_800E5CA0.text[i - 1];
            i--;
        } while (D_800E5CA0.cur < i);
    }
    D_800E5CA0.text[D_800E5CA0.cur] = **p->f14;
    D_800E5CA0.cur++;
    D_800E5CA0.len++;
    D_800E5CA0.text[D_800E5CA0.len] = 0;
    return 0;
}
s32 func_0043CEB0() {
    s32 i;
    s32 v;
    D_80154030 = -1;
    *(s32 *)&D_800E5CA0.timer = 0;
    if (D_800E5CA0.len == 0) return 0;
    if (D_800E5CA0.cur == 0) return 0;
    i = D_800E5CA0.cur - 1;
    if (i < 23) {
        do {
            D_800E5CA0.text[i] = D_800E5CA0.text[i + 1];
            i++;
        } while (i < 23);
    }
    D_800E5CA0.cur--;
    D_800E5CA0.len--;
    return 0;
}
s32 func_0043CF44(u8 *s) {
    s32 i;
    s32 len;
    i = 0;
    len = strlen(s);
    if (len != strlen(D_800E5CAC)) {
        return 0;
    }
    while (i < strlen(s)) {
        if ((s[i] ^ i) != D_800E5CAC[i]) return 0;
        i++;
    }
    return 1;
}
s32 func_0043CFD8() {
    u32 k;
    s32 i;
    s32 ok;
    u8 *s;
    s32 len;
    u32 *g, *h;
    D_80154030 = -1;
    k = 0;
    h = q4_g62CC;
    g = h - 1;
    for (; k < 12; k++) {
        s = D_0044FB90[k].name;
        i = 0;
        len = strlen(s);
        if (len == strlen(D_800E5CAC)) goto loop;
    nomatch:
        ok = 0;
        goto test;
    loop:
        for (;;) {
            if (!(i < strlen(s))) goto match;
            if ((s[i] ^ i) != D_800E5CAC[i]) goto nomatch;
            i++;
        }
    match:
        ok = 1;
    test:
        if (ok) {
            h[0] |= D_0044FB98[k].mask;
            D_8013B2D4[0] = g[1];
            D_80154030 = k;
            if (D_0044FB9C[k].snd != 0) {
                func_0025DF54(D_0044FB9E[k].snd);
            }
        }
    }
    return 0;
}
s32 func_0043D124(Q4Z *o) {
    u32 k = D_80154030;
    if (k < 12) {
        o->f14 = D_0044FB94[k].text;
    } else {
        o->f14 = D_800D7E14;
    }
    return 0;
}
s32 func_0043D164(s32 i, s32 step, s32 stay) {
    s32 n;
    u32 m;
    n = 0;
    do {
        if (stay == 0) {
            i += step;
            if (i >= 11) i = 0;
            else if (i < 0) i = 10;
        }
        switch (i) {
        default:
        case 0: m = 0x10000; break;
        case 1: m = 0x20000; break;
        case 2: m = 0x40000; break;
        case 3: m = 0x80000; break;
        case 4: m = 0x100000; break;
        case 5: m = 0x200000; break;
        case 6: m = 0x800000; break;
        case 7: m = 0x400000; break;
        case 8: m = 0x1000000; break;
        case 9: m = 0x2000000; break;
        case 10: m = 0x4000000; break;
        }
        if (q4_g62CC[0] & m) return i;
        if (stay != 0) {
            i += step;
            if (i >= 11) i = 0;
            else if (i < 0) i = 10;
        }
        n++;
    } while (n < 11);
    return -1;
}
s32 func_0043D260(Q4Z *o, u32 m, void *a2, void *a3) {
    if (D_801462CC & m) {
        o->f8 |= 0x1000000;
    } else {
        o->f8 &= 0xFEFFFFFF;
    }
    if (D_801462C8 & m) {
        o->f14 = a2;
    } else {
        o->f14 = a3;
    }
    return 0;
}
s32 func_0043D2B4(s32 a, u32 m) {
    q4_g62C8[0] ^= m;
    return 0;
}
s32 func_0043D2D0(Q4Z *o) {
    switch (D_80154034) {
    default: o->f14 = D_800D7E14; break;
    case 0: o->f14 = D_800D7BB8; break;
    case 1: o->f14 = D_800D7BBC; break;
    case 2: o->f14 = D_800D7BC0; break;
    case 3: o->f14 = D_800D7BC4; break;
    case 4: o->f14 = D_800D7BC8; break;
    case 5: o->f14 = D_800D7BCC; break;
    case 6: o->f14 = D_800D7BD4; break;
    case 7: o->f14 = D_800D7BD0; break;
    case 8: o->f14 = D_800D7BD8; break;
    case 9: o->f14 = D_800D7BDC; break;
    case 10: o->f14 = D_800D7BE0; break;
    }
    return 0;
}
s32 func_0043D3BC() {
    switch (D_80154034) {
    default:
    case 0: return 1000;
    case 1: return 2000;
    case 2: return 3000;
    case 3: return 4000;
    case 4: return 5000;
    case 5: return 6000;
    case 6: return 0x1CE9;
    case 7: return 0x1D4D;
    case 8: return 0x1DB1;
    case 9: return 0x1DB2;
    case 10: return 0x1F40;
    }
}
s32 func_0043D43C() {
    D_801462C8 ^= 1;
    return 0;
}
s32 func_0043D458(Q4Z *o) {
    if (D_801462CC & 1) {
        o->f8 |= 0x1000000;
    } else {
        o->f8 &= 0xFEFFFFFF;
    }
    if (D_801462C8 & 1) {
        o->f14 = D_800D7B38;
    } else {
        o->f14 = D_800D7B3C;
    }
    return 0;
}
s32 func_0043D4C4() {
    D_801462C8 ^= 2;
    return 0;
}
s32 func_0043D4E0(Q4Z *o) {
    if (D_801462CC & 2) {
        o->f8 |= 0x1000000;
    } else {
        o->f8 &= 0xFEFFFFFF;
    }
    if (D_801462C8 & 2) {
        o->f14 = D_800D7B40;
    } else {
        o->f14 = D_800D7B44;
    }
    return 0;
}
