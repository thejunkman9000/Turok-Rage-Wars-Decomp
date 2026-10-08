#include "o02_types.h"
extern int fprintf(void *, const char *, ...); extern void *__acrt_iob_func(unsigned); extern char *getenv(const char *);
typedef struct { s32 w[3]; f32 f3, f4; u8 col; u8 padc[3]; s32 w2[4]; } O02CtxF;
typedef struct { s8 pad[8]; struct { s8 a, b, c, d, e, f, g, h; } e[1]; } O02Font;
typedef struct {
    u8 pad0[0x12]; u16 flags;
    u8 pad14[0x2C - 0x14];
    u8 c2C, c2D, c2E, c2F, c30, c31;
    u16 align;
    s32 strIdx;
    u8 *str;
} O02Text;
extern s32 D_80153800;
extern s32 D_80153810, D_80153814, D_80153818, D_8015381C;
extern s32 D_801537F4, D_801537F8, D_801537FC;
extern O02Font *D_801537F0;
extern s32 D_801539A0, D_801539A4;
extern s32 D_800E2AB0;
extern O02Ent D_80153820[];
u8 *func_00411DF8(s32 i);
s32 func_0040E154(O02Rect *a, O02Rect *b, O02Text *n, s32 *c);
void func_002A2898(s32 *a, s32 *b, s32 *c, s32 *d);
void func_002A2870(s32 a, s32 b, s32 c, s32 d);
s32 func_0040F508(O02Rect *a, O02Rect *b);
s32 func_002A1238(u8 *s);
void func_0040CB30(void);
O02Font *func_0041208C(s32 f);
s16 func_00411CE0(s32 f);
s16 func_00411D50(s32 f);
s16 func_00411D18(s32 f);
s32 func_0040F1E0(s32 f, u8 *s, s32 n);
O02Item *func_002A25E4(s32 n);
void func_002A0E38(void *p, s32 n, s32 sz, s32 (*cmp)());
s32 func_0040F5F0();
#define SETUP_FONT() \
    func_002A2898(&D_80153810, &D_80153810 + 2, &D_80153810 + 1, &D_80153810 + 3); \
    D_801539A0 = (s8)ca; \
    D_801539A4 = (s8)cb; \
    D_801537F0 = func_0041208C((s8)ca); \
    D_801537F4 = func_00411CE0((s8)ca); \
    D_801537F8 = func_00411D50((s8)ca); \
    D_801537FC = func_00411D18((s8)ca);
void func_0040D350(O02Text *n, O02CtxF c) {
    O02Rect r10, r20, r30, r40, r50;
    u8 *s;
    s32 len, pushed, changed, width, i, vis, found;
    u8 ca, cb;
    f32 fy, fx;
    s32 t;
    O02Ent *e;
    O02Item *it;
    pushed = 0;
    if (n->str == 0) {
        if (n->strIdx == -1) return;
        s = func_00411DF8(n->strIdx);
    } else {
        s = n->str;
    }
    if (func_0040E154(&r40, &r10, n, &c.w[0]) == 0) return;
    if (n->flags & 0x200) {
        func_002A2898(&r20.w[0], &r20.w[2], &r20.w[1], &r20.w[3]);
        r30 = r20;
        if (func_0040F508(&r30, &r10) == 0) return;
        pushed = 1;
        func_002A2870(r30.w[0], r30.w[2], r30.w[1], r30.w[3]);
    }
    len = func_002A1238(s);
    if (c.w[2] & 0x100) {
        ca = n->c30;
        cb = n->c31;
    } else if (c.w[2] & 0x40) {
        ca = n->c2E;
        cb = n->c2F;
    } else {
        ca = n->c2C;
        cb = n->c2D;
    }
    if ((s8)ca == -1) ca = n->c2C;
    if ((s8)cb == -1) cb = n->c2D;
    if (D_80153800 != 0) {
        func_002A2898(&r50.w[0], &r50.w[2], &r50.w[1], &r50.w[3]);
        changed = (r50.w[0] != D_80153810) ? 1 : (r50.w[2] != D_80153818) ? 1 : (r50.w[1] != D_80153814) ? 1 : (r50.w[3] != D_8015381C);
        if (changed || D_801539A0 != (s8)ca || D_801539A4 != (s8)cb) {
            if (D_80153800 != 0) func_0040CB30();
            SETUP_FONT()
        }
    } else {
        SETUP_FONT()
    }
    width = (s32)((f32)func_0040F1E0((s8)ca, s, len) * c.f3);
    fx = 0.0f;
    switch (n->align & 3) {
    case 0:
        fx = (f32)r40.w[0];
        break;
    case 1:
        fx = (f32)(((r40.w[0] + r40.w[1]) / 2) - (width / 2));
        break;
    case 2:
        t = r40.w[1] + 1;
        fx = (f32)(t - width);
        break;
    }
    fy = 0.0f;
    switch (n->align & 0xC) {
    case 0:
        fy = (f32)r40.w[2] - ((f32)D_801537FC * c.f4);
        break;
    case 4:
        fy = (f32)((r40.w[2] + r40.w[3]) / 2) - ((f32)D_801537FC * c.f4) - ((f32)(D_801537F8 / 2) * c.f4);
        break;
    case 8:
        fy = (f32)r40.w[3] - ((f32)(D_801537F8 + D_801537FC) * c.f4);
        break;
    }
    e = &D_80153820[D_80153800];
    e->b[0] = (s32)fx;
    e->b[1] = e->b[0] + width;
    e->b[2] = (s32)fy + (s32)((f32)D_801537FC * c.f4);
    e->b[3] = e->b[2] + (s32)((f32)D_801537F8 * c.f4);
    if (e->b[0] >= e->b[1]) e->b[1] = e->b[0] + 1;
    if (e->b[2] >= e->b[3]) e->b[3] = e->b[2] + 1;
    found = 0;
    for (i = 0; i < D_80153800; i++) {
        if (e->b[1] < D_80153820[i].b[0]) continue;
        if (D_80153820[i].b[1] < e->b[0]) continue;
        if (e->b[3] < D_80153820[i].b[2]) continue;
        if (D_80153820[i].b[3] < e->b[2]) continue;
        found = 1;
        break;
    }
    if (found) {
        func_0040CB30();
        SETUP_FONT()
    }
    { static int nf; if (getenv("TUROK_FONT") && nf++ < 12) { int q; fprintf(__acrt_iob_func(2), "FONT font=%p gap=%d f3=%g f4=%g len=%d s=%.12s ca=%d metrics:", (void *)D_801537F0, (int)D_801537F4, (double)c.f3, (double)c.f4, len, s, (int)(s8)ca); for (q = 0x21; q < 0x28; q++) fprintf(__acrt_iob_func(2), " [a=%d b=%d d=%d]", (int)D_801537F0->e[q].a, (int)D_801537F0->e[q].b, (int)D_801537F0->e[q].d); fprintf(__acrt_iob_func(2), "%c", 10); } }
    it = func_002A25E4(len * 0x18);
    D_80153820[D_80153800].items = it;
    vis = 0;
    for (i = 0; i < len; i++) {
        s32 g = *s - 0x20;
        it->f16 = 0;
        it->f14 = g;
        it->w0 = (c.col << 24) | 0xFFFFFF;
        it->f4 = fx;
        it->f8 = fy + (f32)D_801537F0->e[g].d * c.f4;
        it->fC = (f32)D_801537F0->e[g].a * c.f3;
        s++;
        it->f10 = (f32)D_801537F0->e[g].b * c.f4;
        if (fx < (f32)D_800E2AB0 && 0.0f < fx + it->fC) {
            it++;
            vis++;
        }
        fx = fx + (f32)D_801537F0->e[g].a * c.f3 + (f32)D_801537F4 * c.f3;
    }
    if (pushed) {
        func_002A2870(r20.w[0], r20.w[2], r20.w[1], r20.w[3]);
    }
    if (vis > 0) {
        D_80153820[D_80153800].count = vis;
        func_002A0E38(D_80153820[D_80153800].items, vis, 0x18, func_0040F5F0);
        D_80153800++;
        if (D_80153800 >= 0x10) func_0040CB30();
    }
}
