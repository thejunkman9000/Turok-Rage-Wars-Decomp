#include "q01_types.h"
typedef struct Q01Rec { s32 w0; s32 flags; s16 bits; s16 w; s16 h; s16 n; s32 pad10; s32 off14; s32 off18; } Q01Rec;
typedef struct Q01H { s32 h; u8 pad[0x244]; s32 f248; } Q01H;
typedef struct Q01E8 { s32 f0; u16 f4; u16 f6; } Q01E8;
extern Q01Rec *D_80153C10;
extern s32 *D_80153C14;
extern Q01E8 *D_80153C18;
extern Q01H D_801539B0;
extern u8 D_801539B4[];
extern char D_800E10E0[];
void *func_00252FFC(s32 n);
s32 func_002A1E8C(void *obj, char *name);
void func_002A1EB0(s32 h);
void func_002A1ED4(void *buf, s32 n, s32 c, s32 h);
void func_002A1F60(s32 h, s32 off, s32 z);
void func_002A28CC();
s32 func_002A2934();
void func_00413464(s32 a);
void func_004137A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, void *i, s32 j, s32 k, void *l, s32 m);
void func_004196C0(s32 a, s32 b);
#define MODEBLK switch (mode) { case 1: if (D_80153C18[idx].f0 != -1) D_80153C18[idx].f0 = func_002A2934() + 10; break; case 2: D_80153C18[idx].f0 = -1; break; case 3: D_80153C18[idx].f4++; break; }
s32 func_004106F4(s32 idx, s32 mode) {
    Q01Rec *r, *e;
    u16 *pal;
    s32 s2, s3, s4, s7;
    struct { s32 sp38; s32 sp3C; void *fp; } L;
    s32 a1, a0, n2, t;
    e = (Q01Rec *)(idx * 0x1C + (s32)D_80153C10);
    if (e->flags & 1) {
        MODEBLK
        return ((s32 *)D_80153C10)[idx * 7];
    }
    pal = 0;
    s7 = (s32)pal;
    L.sp38 = e->w0;
    s2 = (s32)pal;
    func_002A28CC(L.sp38);
    *(s32 *)(D_801539B4 - 4) = func_002A1E8C(D_801539B4, D_800E10E0);
    r = (Q01Rec *)(*(u8 **)(D_801539B4 + 0x25C) + idx * 0x1C);
    s3 = (s32)pal;
    if (r->bits == 8) {
        s2 = (r->w + 7) & -8;
    } else if (r->bits == 4) {
        s2 = (r->w + 0xF) & -0x10;
    } else if (0) {
found:
        s3 = 1;
        D_80153C14[idx] = pal[a0];
        goto L84;
    } else if (r->bits == 16) {
        s2 = (r->w + 3) & -4;
    }
    func_00413464(L.sp38);
    t = s2 * r->h * r->bits;
    L.sp3C = L.sp38;
    if (t < 0) t += 7;
    s4 = t >> 3;
    L.fp = func_00252FFC(s4);
    func_002A1F60(D_801539B0.h, D_801539B0.f248 + r->off14, 0);
    func_002A1ED4(L.fp, s4, 1, D_801539B0.h);
    if (r->n > 0) {
        s7 = r->n * 2;
        pal = func_00252FFC(s7);
        func_002A1F60(D_801539B0.h, D_801539B0.f248 + r->off18, 0);
        func_002A1ED4(pal, s7, 1, D_801539B0.h);
        t = r->n;
        a0 = 0;
        if (t > 0) {
            n2 = t;
            do {
                if ((pal[a0] & 1) == 0) goto found;
                a0++;
            } while (a0 < n2);
        }
L84:
        if (a0 == r->n) {
            s3 = 0;
            D_80153C14[idx] = 0xFF000000;
        }
    }
    a1 = -1;
    if (r->n > 0) {
        if (r->bits == 8) {
            a1 = 0x20;
            if (s3 != 0) a1 = 0x1E;
        } else {
            a1 = 0x16;
            if (s3 != 0) a1 = 0x14;
        }
    } else {
        if (r->bits == 16) a1 = 5;
        else if (r->bits == 24) a1 = 8;
        else if (r->bits == 32) a1 = 0xC;
    }
    func_004137A0(L.sp38, a1, r->w, r->h, s2, r->h, 1, s4, L.fp, 1, s7, pal, r->n);
    func_004196C0(L.sp3C, L.sp38);
    ((Q01Rec *)(idx * 0x1C + (s32)D_80153C10))->flags |= 1;
    func_002A1EB0(D_801539B0.h);
    D_801539B0.h = 0;
    func_002A28CC();
    MODEBLK
    return ((s32 *)D_80153C10)[idx * 7];
}
