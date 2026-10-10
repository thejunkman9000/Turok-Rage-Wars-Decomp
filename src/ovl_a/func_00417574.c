#include "q02_tex.h"
#define Q_W (D_800E32A4->w)
#define Q_H (D_800E32A4->h)
extern Q2Tex *D_800E32A4;
extern s32 D_800E32A8;
extern s32 D_800E32AC;
extern s32 D_800E32B0;
extern s32 D_800E32B4;
extern s32 D_800E32B8;
extern s32 D_800E32BC;
s32 func_00413688(Q2Tex *t);
s32 func_00413758(Q2Tex *t);
s32 func_004173FC(s32 mode, s32 tex);
void func_00417574(Q2Tex *p) {
    Q2Tex *t = p;
    s32 r, a, b;
    if (p == NULL) {
        D_800E32A8 = 0;
        D_800E32AC = 0;
        D_800E32A4 = NULL;
        D_800E32B0 = 0;
        D_800E32B4 = 0;
        D_800E32BC = 0;
        return;
    }
    D_800E32A4 = t;
    D_800E32B4 = 0;
    D_800E32A8 = t->unk4;
    D_800E32AC = t->unk6;
    D_800E32B8 = func_00413688(t);
    D_800E32BC = func_00413758(D_800E32A4);
    a = t->unk10;
    b = t->unkC;
    D_800E32B0 = 0;
    if (a > 0 && b > 0x800) {
        D_800E32B0 = 1;
    }
    if (a == 0 && b > 0x1000) {
        D_800E32B0 = 1;
    }
    r = func_004173FC(D_800E32B8, D_800E32A4->unk14);
    if (D_800E32B0 == 0) {
        if (D_800E32B8 == 4) {
            Q_PUSH(0xFD500000, D_800E32A4->img);
            Q_PUSH(0xF5500000, 0x07080200);
            Q_PUSH(0xE6000000, 0);
            Q_PUSH(0xF3000000, Q_LOADBLK(Q_W, 16, (((Q_W * Q_H) + 3) >> 2) - 1));
            Q_PUSH(0xE7000000, 0);
            Q_PUSH(0xF5400000 | (((((s32)((u16)D_800E32A4->w << 16) >> 17) + 7) >> 3 & 0x1FF) << 9), 0x80200);
            Q_PUSH(0xF2000000, (((D_800E32A4->w - 1) * 4 & 0xFFF) << 12) | ((D_800E32A4->h - 1) * 4 & 0xFFF));
        } else if (D_800E32B8 == 8) {
            if (r == 0) {
                Q_PUSH(0xF5500000, 0x07080200);
                Q_PUSH(0xE7000000, 0);
            }
            Q_PUSH(0xE6000000, 0);
            Q_PUSH(0xF5480000 | (((D_800E32A4->w + 7) >> 3 & 0x1FF) << 9), 0x80200);
            Q_PUSH(0xF2000000, (((D_800E32A4->w - 1) * 4 & 0xFFF) << 12) | ((D_800E32A4->h - 1) * 4 & 0xFFF));
            Q_PUSH(0xFD500000, D_800E32A4->img);
            Q_PUSH(0xF3000000, Q_LOADBLK(Q_W, 8, (((Q_W * Q_H) + 1) >> 1) - 1));
        } else if (D_800E32B8 == 0x10) {
            Q_PUSH(0xFD100000, D_800E32A4->img);
            Q_PUSH(0xF5100000, 0x07080200);
            Q_PUSH(0xE6000000, 0);
            Q_PUSH(0xF3000000, Q_LOADBLK(Q_W, 4, (Q_W * Q_H) - 1));
            Q_PUSH(0xE7000000, 0);
            Q_PUSH(0xF5100000 | ((((D_800E32A4->w * 2) + 7) >> 3 & 0x1FF) << 9), 0x80200);
            Q_PUSH(0xF2000000, (((D_800E32A4->w - 1) * 4 & 0xFFF) << 12) | ((D_800E32A4->h - 1) * 4 & 0xFFF));
        }
    }
}
