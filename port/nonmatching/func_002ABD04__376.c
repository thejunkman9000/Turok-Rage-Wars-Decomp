#include "b24_types.h"
/* ---- func_002AB19C ---- */
extern DlCmd *D_80110634;

typedef struct AtlasCell {
    u32 w;
    u32 h;
} AtlasCell;

void func_002AACC0(u8 *, s32, s16, s32, s32);
void func_002AAED8(u8 *, f32, f32, u32, u32, f32, f32);
void func_002AA354(u8 *, u8 *, s32, s16, s32, s32);
void func_002AA724(u8 *, u8 *, f32, f32, u32, u32, f32, f32);
void func_002AB8DC(s16 **a0, s32 idx, void **out, u8 *out2);
void func_00253B5C(s32, s32);

inline void func_002ABDBC(u16 *hdr, s32 x0, s16 y) {
    s32 r, c;
    s32 x;
    s32 w, h;
    u8 *p;
    s32 n;
    p = (u8 *)hdr + 8;
    h = 0;
    r = hdr[1];
    r--;
    for (; r != -1; r--) {
        x = (s16)x0;
        c = hdr[0];
        c--;
        for (; c != -1; c--) {
            h = ((AtlasCell *)p)->h;
            w = ((AtlasCell *)p)->w;
            n = w * h;
            func_002AA354(p + 8, p + (n * 2 + 8), x, y, w, h);
            x += w;
            p += (n * 2) + ((u32)n >> 1);
            p += 8;
        }
        y += h;
    }
}

inline void func_002ABED4(u16 *hdr, f32 x0, f32 y, f32 sx, f32 sy) {
    f32 rows, cols, x;
    u32 w, h;
    u8 *p;
    p = (u8 *)hdr + 8;
    h = 0;
    rows = hdr[1];
    while (rows-- != 0.0f) {
        cols = hdr[0];
        x = x0;
        while (cols-- != 0.0f) {
            h = ((AtlasCell *)p)->h;
            w = ((AtlasCell *)p)->w;
            func_002AA724(p + 8, p + (w * h * 2 + 8), x, y, w, h, sx, sy);
            x += (f32)w * sx;
            p += (w * h * 2) + ((w * h) >> 1);
            p += 8;
        }
        y += (f32)h * sy;
    }
}

inline void func_002AC0A0(u16 *hdr, s32 x0, s16 y) {
    s32 r, c;
    s32 x;
    s32 w, h;
    u8 *p;
    u16 rows;
    p = (u8 *)hdr + 8;
    h = 0;
    r = hdr[1];
    r--;
    for (; r != -1; r--) {
        x = (s16)x0;
        c = hdr[0];
        c--;
        for (; c != -1; c--) {
            h = ((AtlasCell *)p)->h;
            w = ((AtlasCell *)p)->w;
            func_002AACC0(p + 8, x, y, w, h);
            x += w;
            p += (u32)(w * h) >> 1;
            p += 8;
        }
        y += h;
    }
}

inline void func_002AC1A0(u16 *hdr, f32 x0, f32 y, f32 sx, f32 sy) {
    f32 rows, cols, x;
    u32 w, h;
    u8 *p;
    p = (u8 *)hdr + 8;
    h = 0;
    rows = hdr[1];
    while (rows-- != 0.0f) {
        cols = hdr[0];
        x = x0;
        while (cols-- != 0.0f) {
            h = ((AtlasCell *)p)->h;
            w = ((AtlasCell *)p)->w;
            func_002AAED8(p + 8, x, y, w, h, sx, sy);
            x += (f32)w * sx;
            p += (w * h) >> 1;
            p += 8;
        }
        y += (f32)h * sy;
    }
}

void func_002AB19C(s32 h, s32 idx, s32 x, s16 y, f32 sx, f32 sy, s32 flt) {
    u16 *tab;
    u8 kind;
    DlCmd *g;
    g = D_80110634++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    if (h != 0) {
        func_002AB8DC(h, idx, &tab, &kind);
        if (tab != NULL) {
            if (kind != 0) {
                if (flt != 0) {
                    func_002AC1A0(tab, (f32)(s16)x, (f32)y, sx, sy);
                } else {
                    func_002AC0A0(tab, x, y);
                }
            } else if (flt != 0) {
                func_002ABED4(tab, (f32)(s16)x, (f32)y, sx, sy);
            } else {
                func_002ABDBC(tab, x, y);
            }
            func_00253B5C(0, h);
        }
    }
}
/* ---- func_002AB6C0 ---- */
typedef struct Sprt {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[0x20];
    /* 0x38 */ s32 unk38;
} Sprt;

void func_002AB6C0(Sprt *s, s16 a, s16 b) {
    s->unk38 = -1;
    s->unk10 = a;
    s->unk0 = 0;
    s->unk8 = 0;
    s->unk14 = b;
}
/* ---- func_002AB6FC ---- */
typedef struct ScriptCtx {
    u8 pad0[4];
    s32 *pc;
    s32 state;
    u8 padC[0x30];
    s32 unk3C;
    s32 unk40;
    s32 unk44;
} ScriptCtx;

void func_002A8A94(ScriptCtx *);

void func_002AB6FC(ScriptCtx *c, s32 *pc) {
    c->pc = pc;
    c->state = 2;
    func_002A8A94(c);
}
/* ---- func_002AB720 ---- */
extern s32 D_800D318C[];
void func_002AB6FC(ScriptCtx *c, s32 *pc);

void func_002AB720(ScriptCtx *c, s32 a, s32 b) {
    c->unk40 = a;
    c->unk3C = b;
    c->unk44 = 100;
    func_002AB6FC(c, D_800D318C);
}
/* ---- func_002AB750 ---- */
typedef struct ScriptHolder {
    u8 pad0[0x48];
    ScriptCtx s;
} ScriptHolder;

extern s32 D_800D31A0[];


void func_002AB750(ScriptHolder *h, s32 a, s32 b) {
    h->s.unk40 = a;
    h->s.unk3C = b;
    h->s.unk44 = 100;
    func_002AB6FC(&h->s, D_800D31A0);
}
/* ---- func_002AB784 ---- */
void func_002AB784(s32 *p, s32 v) {
    p[0x44 / 4] = v;
}
/* ---- func_002AB78C ---- */
void func_002AB78C(s32 *p, s32 v) {
    p[0x8C / 4] = v;
}
/* ---- func_002AB794 ---- */
typedef struct Scn {
    u8 pad0[0x40];
    s32 unk40;
    u8 pad44[0x44];
    s32 unk88;
} Scn;

extern u8 D_801462DE;
s32 func_002A33AC(void);
void func_002A3090(void);
void func_0026D8F8(void);
void func_00296FF8(void);
void func_002A94E8(void);
void func_002A9700(void);
void func_002ABB58(f32 a, f32 b);
void func_002ABB2C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_002AA224(s32);
void func_002A8650(Scn *, s32);

void func_002AB794(Scn *s) {
    u8 buf[0x100];
    if (func_002A33AC() == 1) {
        func_002A3090();
        func_0026D8F8();
        func_00296FF8();
    }
    func_002A94E8();
    func_002A9700();
    func_002ABB58(0.7f, 0.7f);
    func_002ABB2C(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    func_002AA224(D_801462DE);
    if (s->unk40 != 0) {
        func_002A8650(s, 1);
    }
    if (s->unk88 != 0) {
        func_002A8650(s, 2);
    }
}
/* ---- func_002AB854 ---- */
extern u32 D_8014D3D0;

f32 func_002AB854(void) {
    switch (D_8014D3D0) {
    case 0:
        return 24.0f;
    case 1:
        return 12.0f;
    case 2:
    case 6:
        return 8.0f;
    case 3:
        return 6.0f;
    case 4:
    case 5:
        return 16.0f;
    default:
        return 1.0f;
    }
}
/* ---- func_002AB8DC ---- */
typedef struct TabEnt {
    s32 off;
    u8 unk4;
    u8 pad5[3];
} TabEnt;

void func_002AB8DC(s16 **a0, s32 idx, void **out, u8 *out2) {
    s16 *t;
    TabEnt *e;
    u8 *p;
    s32 i;
    u8 b;
    s32 off;

    *out = NULL;
    if (a0 != NULL) {
        t = *a0;
        i = idx % *t;
        p = (u8 *)t + 8;
        e = (TabEnt *)(i * 8 + (u32)p);
        b = e->unk4;
        off = e->off;
        *out2 = b;
        *out = (u8 *)t + off;
    }
}
/* ---- func_002AB940 ---- */
typedef struct TabInfo {
    u8 pad0[4];
    u16 unk4;
    u16 unk6;
} TabInfo;
extern s32 D_800D29B4;
extern u8 D_8011FE88[];
s32 func_0028BE88(u8 *, s32, s32, s32);
void func_002AB8DC(s16 **a0, s32 idx, void **out, u8 *out2);
void func_002536F4(s32, s32);
void func_002AB940(s32 id, s32 idx, s32 *out1, s32 *out2) {
    TabInfo *info;
    u8 b;
    s32 h;
    TabInfo *q;
    if (D_800D29B4 != 0) {
        h = func_0028BE88(D_8011FE88, id, 0, 1);
        if (h != 0) {
            func_002AB8DC(h, idx, (void **)&info, &b);
            q = info;
            *out1 = q->unk4;
            *out2 = q->unk6;
            func_002536F4(0, h);
        }
    }
}
/* ---- func_002AB9E4 ---- */
s32 func_0026925C(s32);
s32 func_00268CE0(s32);

void func_002AB9E4(void) {
    DlCmd *g;
    g = D_80110634++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_80110634++;
    g->w0 = 0xE3000A01;
    g->w1 = 0;
    func_0026925C(0x15);
    func_00268CE0(0x19);
}
/* ---- func_002ABA44 ---- */
#define SHIFTL(v, s, w) (((u32)(v) & ((0x01 << (w)) - 1)) << (s))
#define GFX(a, b) { DlCmd *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void func_002ABA44(s32 x0, s32 y0, s32 x1, s32 y1, u8 r, u8 g, u8 b, u8 a) {
    GFX(0xE7000000, 0)
    GFX(0xFA00FFFF, SHIFTL(r, 24, 8) | SHIFTL(g, 16, 8) | SHIFTL(b, 8, 8) | SHIFTL(a, 0, 8))
    GFX(0xF6000000 | SHIFTL(MAX(x1, 0), 14, 10) | SHIFTL(MAX(y1, 0), 2, 10), SHIFTL(MAX(x0, 0), 14, 10) | SHIFTL(MAX(y0, 0), 2, 10))
}
/* ---- func_002ABB2C ---- */
extern s32 D_8013B858[];

void func_002ABB2C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    D_8013B858[0] = a;
    D_8013B858[1] = b;
    D_8013B858[2] = c;
    D_8013B858[3] = d;
    D_8013B858[4] = e;
    D_8013B858[5] = f;
}
/* ---- func_002ABB58 ---- */
extern f32 D_8013B870[];

void func_002ABB58(f32 a, f32 b) {
    D_8013B870[0] = a;
    D_8013B870[1] = b;
}
/* ---- func_002ABB6C ---- */
void func_002A98E0(s32, f32, f32, f32, f32, s32, s32, s32);

void func_002ABB6C(s32 a, f32 b, f32 c, f32 d, f32 e, s32 f, s32 g, s32 h) {
    if (f != 0) {
        func_002A98E0(a, b, c, d, e, 1, g, h);
    }
    func_002A98E0(a, b, c, d, e, 0, g, h);
}
/* ---- func_002ABC18 ---- */
typedef struct DlOwner {
    u8 pad0[0x114];
    u32 unk114;
} DlOwner;

extern DlOwner *D_8011FE80;

extern s32 D_800E28A4;



void func_002AB19C(s32 h, s32 idx, s32 x, s16 y, f32 sx, f32 sy, s32 flt);


s32 func_002ABC18(s32 id, s32 b, s16 c, s16 d, f32 e, f32 f, s32 g) {
    s32 h;
    if ((u32)(D_800E28A4 - (((u32)D_80110634 - D_8011FE80->unk114) >> 3)) < 0x3E8 ||
        D_800D29B4 == 0 ||
        (h = func_0028BE88(D_8011FE88, id, 0, 1)) == 0) {
        return 0;
    }
    func_002AB19C(h, b, c, d, e, f, g);
    func_002536F4(0, h);
    return 1;
}
/* ---- func_002ABD04 ---- */
extern void *D_800D2F90;

extern u8 D_8014D340[];
void *memcpy(void *, const void *, u32);



static inline void lookup(s16 **a0, s32 idx, void **out, u8 *out2) {
    s16 *t;
    TabEnt *e;
    u8 *p;
    s32 i;
    u8 b;
    s32 off;

    if (a0 != NULL) {
        t = *a0;
        *out = NULL;
        i = idx % *t;
        p = (u8 *)t + 8;
        e = (TabEnt *)(i * 8 + (u32)p);
        off = e->off;
        b = e->unk4;
        *out2 = b;
        *out = (u8 *)t + off;
    } else {
        *out = NULL;
    }
}
void func_002ABD04(void) {
    struct { void *p; u8 b; } r;
    s16 **h;
    D_800D2F90 = NULL;
    h = func_0028BE88(D_8011FE88, 2, 0, 1);
    if (h != NULL) {
        { s32 z = 0; lookup(h, z, &r.p, &r.b); }
        if (r.p != NULL) {
            r.p = (u8 *)r.p + 0x10;
        }
        memcpy(D_8014D340, r.p, 0x90);
        func_002536F4(0, h);
        D_800D2F90 = D_8014D340;
    }
}




/* ---- func_002ABDAC ---- */
extern s32 D_800D2F90_002ABDAC __asm__("D_800D2F90");

s32 func_002ABDAC(void) {
    return D_800D2F90_002ABDAC;
}
