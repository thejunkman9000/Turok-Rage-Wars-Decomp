#include "o04_types.h"
#include "q03_types.h"
extern Q03S53 *D_800E53C0;
extern Q03Cfg D_801462C8[];
typedef struct { u8 pad[0xD0]; Q03Ent e; } Q03EntAt;

extern Q03Ent D_80146398[];
#define ENTAT(q) ((Q03EntAt *)((q) * 150 + (s32)D_801462C8))
#define GA ((O04GFlags *)((u8 *)D_801462C8 + 0x5D8))
extern s32 D_80154028[];
s32 func_0042D240(void);
void func_0042C8AC(void) {
    s32 arr[5];
    s32 i;
    register s32 cc __asm__("$2");
    Q03Cfg *cfg2;
    Q03Cfg *cfg3;
    register s32 kk __asm__("$14");
    s32 i3;
    s32 j;
    s32 k;
    register s32 x __asm__("$4");
    register s32 *ap __asm__("$2");
    s32 q1;
    s32 q2;
    register s32 a4 __asm__("$7");
    s32 b4;
    register s32 y __asm__("$5");
    s32 mode;
    s32 *pa;
    s32 *pb;
    s32 *pj;
    s32 ka;
    s32 kb;
    s32 n;
    s32 k2;
    Q03Ent *e1;
    Q03Ent *e2;
    Q03EntAt *ea;
    Q03EntAt *eb;
    Q03S53 *d;
    D_800E53C0->unkE8 = 0;
    D_800E53C0->unkEC = 0;
    d = D_800E53C0;
    for (i = 0; i < 8; i++) {
        d->unkF0[i] = -1;
        e1 = &D_80146398[i];
        if (e1->f78 == 1) {
            d->unkF0[d->unkEC] = i;
            d->unkEC = d->unkEC + 1;
        }
    }
    mode = func_0042D240();
    if (mode == 0) {
        switch (D_80154028[0]) {
        case 1: mode = 2; break;
        case 0: mode = 3; break;
        case 2:
        default: mode = 1; break;
        }
    }
    if (D_80154028[0] == 3 || D_80154028[0] == 0) {
        for (i = 4; i >= 0; i--) {
            arr[i] = i;
        }
        for (i3 = 0; i3 < 5; i3++) {
            for (j = 0; j < 4; j++) {
                x = arr[j];
                if (D_80154028[0] == 0) {
                    ap = (s32 *)((u8 *)GA + x * 4);
                    ka = ap[16];
                } else {
                    ap = (s32 *)((u8 *)GA + x * 4);
                    ka = ap[11];
                }
                y = arr[j + 1];
                if (D_80154028[0] == 0) {
                    ap = (s32 *)((u8 *)GA + y * 4);
                    kb = ap[16];
                } else {
                    ap = (s32 *)((u8 *)GA + y * 4);
                    kb = ap[11];
                }
                if (ka < kb) {
                    k = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = k;
                }
            }
        }
            for (j = 0; j < D_800E53C0->unkEC; j++) {
                    for (n = 0; n < D_800E53C0->unkEC - 1; n++) {
                        register s32 q1 __asm__("$4");
                        register s32 q2 __asm__("$5");
                        s32 r2;
                        s32 bka;
                        s32 bkb;
                        q1 = D_800E53C0->unkF0[n];
                        bka = D_801462C8->ent[q1].f92;
                        if (bka >= 5) {
                            bka = -1;
                        } else if (D_80154028[0] == 0) {
                            bka = GA->unk40[bka];
                        } else {
                            bka = GA->unk2C[bka];
                        }
                        q2 = D_800E53C0->unkF0[n + 1];
                        r2 = D_801462C8->ent[q2].f92;
                        if (r2 >= 5) {
                            bkb = -1;
                        } else if (D_80154028[0] == 0) {
                            bkb = GA->unk40[r2];
                        } else {
                            bkb = GA->unk2C[r2];
                        }
                        if (bka < bkb) {
                            k = D_800E53C0->unkF0[n];
                            D_800E53C0->unkF0[n] = D_800E53C0->unkF0[n + 1];
                            D_800E53C0->unkF0[n + 1] = k;
                        }
                    }
            }
        for (i = 0; i < 5; i++) {
            kk = arr[i];
                for (j = 0; j < D_800E53C0->unkEC; j++) {
                        for (n = 0; n < D_800E53C0->unkEC - 1; n++) {
                            q1 = D_800E53C0->unkF0[n];
                            q2 = D_800E53C0->unkF0[n + 1];
                            ea = (Q03EntAt *)(q1 * 150 + (s32)D_801462C8);
                            eb = (Q03EntAt *)(q2 * 150 + (s32)D_801462C8);
                            a4 = ea->e.f4;
                            b4 = eb->e.f4;
                            if (ea->e.f92 != kk || eb->e.f92 != kk) {
                                continue;
                            }
                            if (mode == 1) goto m4a;
                            if (mode != 3) goto m4a;
                            ka = ea->e.f8;
                            kb = eb->e.f8;
                            goto mcmpa;
                          m4a:
                            ka = a4;
                            kb = b4;
                          mcmpa:
                            if (ka < kb || (ka == kb && (cc = a4 < b4))) {
                                k2 = D_800E53C0->unkF0[n];
                                D_800E53C0->unkF0[n] = D_800E53C0->unkF0[n + 1];
                                D_800E53C0->unkF0[n + 1] = k2;
                            }
                        }
                            }
        }
    } else {
            for (i = 0; i < D_800E53C0->unkEC; i++) {
                    cfg3 = D_801462C8;
                    for (j = 0; j < D_800E53C0->unkEC - 1; j++) {
                        q1 = D_800E53C0->unkF0[j];
                        q2 = D_800E53C0->unkF0[j + 1];
                        a4 = (*(&cfg3->ent[q1])).f4;
                        b4 = (*(&cfg3->ent[q2])).f4;
                        if (mode == 2) goto m6b;
                        if (mode < 3) goto m4b;
                        if (mode != 3) goto m4b;
                        ka = cfg3->ent[q1].f8;
                        kb = cfg3->ent[q2].f8;
                        goto mcmpb;
                      m6b:
                        ka = cfg3->ent[q1].f6;
                        kb = cfg3->ent[q2].f6;
                        goto mcmpb;
                      m4b:
                        ka = a4;
                        kb = b4;
                      mcmpb:
                        if (ka < kb || (ka == kb && (cc = a4 < b4))) {
                            k2 = D_800E53C0->unkF0[j];
                            D_800E53C0->unkF0[j] = D_800E53C0->unkF0[j + 1];
                            D_800E53C0->unkF0[j + 1] = k2;
                        }
                    }
                    }
    }
}
















