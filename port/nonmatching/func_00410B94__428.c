#include "q01_types.h"
typedef struct Q01Rec { s32 w0; s32 flags; s16 bits; s16 w; s16 h; s16 n; s32 pad10; s32 off14; s32 off18; } Q01Rec;
typedef struct Q01H { s32 h; u8 pad[0x244]; s32 f248; } Q01H;
extern Q01Rec *D_80153C10;
extern s32 *D_80153C14;
extern Q01H D_801539B0;
extern u8 D_801539B4[];
extern char D_800E10E0[];
void *func_00252FFC(s32 n);
s32 func_002A1E8C(void *obj, char *name);
void func_002A1EB0(s32 h);
void func_002A1ED4(void *buf, s32 n, s32 c, s32 h);
void func_002A1F60(s32 h, s32 off, s32 z);
void func_00413500(s32 a, s32 b);
void func_004137A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, void *i, s32 j, s32 k, void *l, s32 m);
void func_00410B94(s32 idx, s32 arg1) {
    Q01Rec *r;
    s32 *pal;
    s32 s2, s3, s4, s6;
    void *fp;
    s32 a1, a0, n2, t;
    if (((Q01Rec *)((u8 *)D_80153C10 + idx * 0x1C))->flags & 1) {
        func_00413500(arg1, ((Q01Rec *)((u8 *)D_80153C10 + idx * 0x1C))->w0);
        return;
    }
    pal = 0;
    s6 = (s32)pal;
    s2 = (s32)pal;
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
        D_80153C14[idx] = a1;
        goto L84;
    } else if (r->bits == 16) {
        s2 = (r->w + 3) & -4;
    }
    s4 = s2 * r->h * r->bits / 8;
    fp = func_00252FFC(s4);
    func_002A1F60(D_801539B0.h, D_801539B0.f248 + r->off14, 0);
    func_002A1ED4(fp, s4, 1, D_801539B0.h);
    if (r->n > 0) {
        s6 = r->n * 2;
        pal = func_00252FFC(s6);
        func_002A1F60(D_801539B0.h, D_801539B0.f248 + r->off18, 0);
        func_002A1ED4(pal, s6, 1, D_801539B0.h);
        t = r->n;
        a0 = 0;
        if (t > 0) {
            s32 *v1 = pal;
            n2 = t;
            do {
                a1 = *v1;
                if ((a1 & 0xFF000000) == 0) goto found;
                a0++;
                v1 += 1;
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
        if (r->bits == 16) a1 = 0x1C;
        else if (r->bits == 24) a1 = 8;
        else if (r->bits == 32) a1 = 0xC;
    }
    func_004137A0(arg1, a1, r->w, r->h, s2, r->h, 1, s4, fp, 1, s6, pal, r->n);
    func_002A1EB0(D_801539B0.h);
    D_801539B0.h = 0;
}
