#include "b10_types.h"

extern B10Ctl *D_800E2830;
extern void *D_80145060[];
extern u8 D_8010EC90[];
extern u8 D_8011FE88[];
extern s32 D_8013B294;
extern u8 D_8013B2A8[];
extern s32 D_8013B2A4;
extern s32 D_8013B2BC;
s32 func_40332C(void);
s32 func_44E038(u8 *a, s32 *loc, s32 id, u8 *b);
void func_0022E280(B10Pl *p);
void func_00239B54(void *p);
void func_00285D00(u8 *p);
void func_00286A78(u8 *a, s32 id, s32 flag);

void func_00244E48(void) {
    s32 id;
    s32 loc[3];
    s32 r;
    B10Pl *pl;
    u8 *snd;
    B10Tgt *tgt;
    id = D_800E2830->fD8;
    if (D_800E2830->f40 == 0) {
        if (D_800E2830->f54) {
            pl = D_80145060[0];
            if (pl) {
                func_0022E280(pl);
                pl->f57C = 0;
                pl->f580 = 0;
                pl->f590 = 0;
            }
            func_00239B54(&D_80145060[10]);
            func_00285D00(D_8010EC90);
        }
        if (id != -1) {
            snd = D_8011FE88;
            if (D_8013B294 != id) {
                loc[0] = 0;
                loc[1] = 0;
                loc[2] = 0;
                r = func_44E038(snd, loc, id, D_8013B2A8);
                D_8013B2BC = r;
                D_8013B2A4 = r != 0;
                func_00286A78(snd, id, r != 0);
            }
        }
        D_800E2830->f5C = func_40332C();
        D_800E2830->f50 = 1;
        D_800E2830->fD8 = -1;
        D_800E2830->f40 = 1;
        tgt = D_80145060[18];
        if (tgt) {
            tgt->f29C = D_800E2830->f108;
            tgt->f2A0 = D_800E2830->f10C;
            tgt->f2A4 = D_800E2830->f110;
            tgt->f2A8 = D_800E2830->f114;
        }
    }
}
