#include "o04_types.h"
#include "q03_types.h"
extern Q03S53 *D_800E53C0;
extern Q03Cfg D_801462C8[];
extern Q03Ent D_80146398[];
extern O04GFlags D_801468A0[];
extern s32 D_80154028;
s32 func_0042D240(void);
void func_0042C8AC(void) {
    s32 arr[5];
    s32 i;
    s32 j;
    s32 k;
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
    Q03S53 *d;
    D_800E53C0->unkE8 = 0;
    D_800E53C0->unkEC = 0;
    d = D_800E53C0;
    for (i = 0; i < 8; i++) {
        d->unkF0[i] = -1;
        if (D_80146398[i].f78 == 1) {
            d->unkF0[d->unkEC] = i;
            d->unkEC = d->unkEC + 1;
        }
    }
    mode = func_0042D240();
    if (mode == 0) {
        if (D_80154028 == 1) {
            mode = 2;
        } else if (D_80154028 >= 2) {
            mode = 1;
        } else if (D_80154028 == 0) {
            mode = 3;
        }
    }
    if (D_80154028 == 3 || D_80154028 == 0) {
        for (i = 4; i >= 0; i--) {
            arr[i] = i;
        }
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 4; j++) {
                if (D_80154028 == 0) {
                    ka = D_801468A0->unk40[arr[j]];
                } else {
                    ka = D_801468A0->unk2C[arr[j]];
                }
                if (D_80154028 == 0) {
                    kb = D_801468A0->unk40[arr[j + 1]];
                } else {
                    kb = D_801468A0->unk2C[arr[j + 1]];
                }
                if (ka < kb) {
                    k = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = k;
                }
            }
        }
        d = D_800E53C0;
        if (d->unkEC > 0) {
            for (i = 0; i < d->unkEC; i++) {
                if (d->unkEC - 1 > 0) {
                    for (j = 0; j < d->unkEC - 1; j++) {
                        s32 q1 = D_800E53C0->unkF0[j];
                        s32 q2 = D_800E53C0->unkF0[j + 1];
                        s32 r1 = D_801462C8->ent[q1].f92;
                        s32 r2 = D_801462C8->ent[q2].f92;
                        if (r1 < 5) {
                            if (D_80154028 == 0) {
                                ka = D_801468A0->unk40[r1];
                            } else {
                                ka = D_801468A0->unk2C[r1];
                            }
                        } else {
                            ka = -1;
                        }
                        if (r2 < 5) {
                            if (D_80154028 == 0) {
                                kb = D_801468A0->unk40[r2];
                            } else {
                                kb = D_801468A0->unk2C[r2];
                            }
                        } else {
                            kb = -1;
                        }
                        if (ka < kb) {
                            k = D_800E53C0->unkF0[j];
                            D_800E53C0->unkF0[j] = D_800E53C0->unkF0[j + 1];
                            D_800E53C0->unkF0[j + 1] = k;
                        }
                    }
                }
            }
        }
        for (i = 0; i < 5; i++) {
            k = arr[i];
            d = D_800E53C0;
            if (d->unkEC > 0) {
                for (j = 0; j < d->unkEC; j++) {
                    if (d->unkEC - 1 > 0) {
                        for (n = 0; n < d->unkEC - 1; n++) {
                            e1 = &D_801462C8->ent[D_800E53C0->unkF0[n]];
                            e2 = &D_801462C8->ent[D_800E53C0->unkF0[n + 1]];
                            if (e1->f92 != k || e2->f92 != k) {
                                continue;
                            }
                            if (mode == 1 || mode != 3) {
                                ka = e1->f4;
                                kb = e2->f4;
                            } else {
                                ka = e1->f8;
                                kb = e2->f8;
                            }
                            if (ka < kb || (ka == kb && e1->f4 < e2->f4)) {
                                k2 = D_800E53C0->unkF0[n];
                                D_800E53C0->unkF0[n] = D_800E53C0->unkF0[n + 1];
                                D_800E53C0->unkF0[n + 1] = k2;
                            }
                        }
                    }
                    d = D_800E53C0;
                }
            }
        }
    } else {
        d = D_800E53C0;
        if (d->unkEC > 0) {
            for (i = 0; i < d->unkEC; i++) {
                if (d->unkEC - 1 > 0) {
                    for (n = 0; n < d->unkEC - 1; n++) {
                        e1 = &D_801462C8->ent[D_800E53C0->unkF0[n]];
                        e2 = &D_801462C8->ent[D_800E53C0->unkF0[n + 1]];
                        if (mode == 2) {
                            ka = e1->f6;
                            kb = e2->f6;
                        } else if (mode < 3 || mode != 3) {
                            ka = e1->f4;
                            kb = e2->f4;
                        } else {
                            ka = e1->f8;
                            kb = e2->f8;
                        }
                        if (ka < kb || (ka == kb && e1->f4 < e2->f4)) {
                            k2 = D_800E53C0->unkF0[n];
                            D_800E53C0->unkF0[n] = D_800E53C0->unkF0[n + 1];
                            D_800E53C0->unkF0[n + 1] = k2;
                        }
                    }
                }
                d = D_800E53C0;
            }
        }
    }
}
