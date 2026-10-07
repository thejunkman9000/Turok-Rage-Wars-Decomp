#include "o05_types.h"

extern O05Lobby *D_800E54A4;
extern s32 D_800D7700;
extern s32 D_800D770C;
s32 func_00404BE8(s32 a, s32 idx, s32 *out);
s32 func_00404858(s32 idx, s32 a);
s32 func_00405160(s32 idx, s32 *out);
s32 func_004050CC(s32 idx, s32 *out);
s32 func_00435600(void);
s32 func_004057EC(s32 a);
s32 func_00405454(s32 idx, s32 *out);
void func_002A1724(void *dst, void *src, s32 n);
s32 func_004057F8(void *p, s32 a, s32 b);
void func_002A125C(char *dst, s32 src);
s32 func_00404958(s32 idx, s32 n, void *buf, char *name, s32 *p, s32 q);
void func_00432488(s32 a);

s32 func_00434604(s32 idx) {
    s32 ok;
    s32 r;
    s32 x;
    s32 i;
    s32 v[4];
    s32 w[2];
    char name[16];
    ok = 0;
    r = func_00404BE8(D_800D7700, idx, &v[0]);
    if (r == 1) {
        ok = func_00404858(idx, v[0]) == 0;
    } else {
        v[1] = 0;
        r = func_00405160(idx, &v[2]);
        if (r == 0) {
            r = func_004050CC(idx, &v[3]);
            if (r == 0) {
                x = func_004057EC(func_00435600());
                if (v[3] == 0 || v[2] < x) {
                    v[1] = 0;
                } else {
                    v[1] = 1;
                }
            }
        }
        if (r == 0) {
            if (v[1] == 1) {
                ok = 1;
            }
        }
    }
    if (ok == 1) {
        ok = 0;
        if (func_00405454(idx, w) == 0) {
            func_002A1724(D_800E54A4->recs, D_800E54A4->plr[idx].rec, 0x640);
            D_800E54A4->f3468 = D_800E54A4->plr[idx].fB64;
            D_800E54A4->f346C = func_004057F8(D_800E54A4->recs, 0x640, 7);
            for (i = 0; i < 16; i++) {
                name[i] = 0;
            }
            func_002A125C(name, D_800D7700);
            if (func_00404958(idx, 0x648, D_800E54A4->recs, name, w, D_800D770C) == 0) {
                ok = 1;
            }
        }
    }
    if (ok == 0) {
        D_800E54A4->plr[idx].f14 = 2;
        D_800E54A4->plr[idx].state = 2;
        func_00432488(idx);
    }
    return ok;
}
