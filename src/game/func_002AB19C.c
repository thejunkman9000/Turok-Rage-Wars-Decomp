#include "b24_types.h"

extern DlCmd *D_80110634;

typedef struct AtlasCell {
    u32 w;
    u32 h;
} AtlasCell;

void func_002AACC0(u8 *, s32, s16, s32, s32);
void func_002AAED8(u8 *, f32, f32, u32, u32, f32, f32);
void func_002AA354(u8 *, u8 *, s32, s16, s32, s32);
void func_002AA724(u8 *, u8 *, f32, f32, u32, u32, f32, f32);
void func_002AB8DC(s32, s32, u16 **, u8 *);
void func_00253B5C(s32, s32);

static inline void func_002ABDBC(u16 *hdr, s32 x0, s16 y) {
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

static inline void func_002ABED4(u16 *hdr, f32 x0, f32 y, f32 sx, f32 sy) {
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

static inline void func_002AC0A0(u16 *hdr, s32 x0, s16 y) {
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

static inline void func_002AC1A0(u16 *hdr, f32 x0, f32 y, f32 sx, f32 sy) {
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
