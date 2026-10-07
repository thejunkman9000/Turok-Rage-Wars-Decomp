#include "r07_types.h"

extern u64 D_80146960;
extern s32 D_80154048;
extern u32 D_80146CF4;
extern u32 D_80146D64;
extern u32 D_8011FAB8;
extern u32 D_8014696C;
extern s32 D_80146968;
extern f32 D_80146CFC;
extern f32 D_800D2988;
extern s32 D_800E28D4;
extern s32 D_80146928;
extern u8 D_8014561C[];
extern R07Slot *D_8011FE80;
extern R07Slot *D_8014AD98;

s32 func_002A33AC(void);
s32 func_002934DC(void);
s32 func_442B98(void *p);
s32 func_00245788(void);
void func_002532E4(s32 a);
void func_00292318(B21Game *g);
void func_00293C20(B21Game *g);
s32 func_00245AFC(void);
s32 func_00245840(void);
void func_4037D4(void);

#define MAXV ({ u32 _m = a; if (_m < d) _m = d; if (_m < c) _m = c; if (_m < b) _m = b; _m; })
#define EXPRL ((sum - ({ u32 _t = MAXV; _t - 2; })) / 3)

static inline u32 calc(u32 lim) {
    u32 a = D_80146CF4;
    u32 b = D_80146D64;
    u32 c = D_8011FAB8;
    u32 d = D_8014696C;
    u32 sum = b + c + d + a;
    return EXPRL < lim ? lim : EXPRL;
}

void func_00292910(B21Game *g) {
    u64 now;
    f32 fs;
    s32 ok;

    now = osGetTime();
    fs = (f32)((now - D_80146960) * 64 / 3000) * 0.000001f * 15.0f;
    D_80146960 = now;
    if (func_002A33AC() == 0) {
        if (func_002934DC() == 0) {
            g->unk26DD4 = 0;
        } else {
            g->unk26DD4 = func_442B98((u8 *)g + 0x25B5C);
        }
    }
    if (D_80154048 != 0 && g->unk26DB8 == 0xB) {
        g->unk26DD4 = 1;
    }
    switch ((u32)g->unk26DB8) {
    case 1:
    case 3:
    case 4:
        D_80146968 = calc(2);
        break;
    default:
        D_80146968 = calc(2);
        if (func_00245788() != 0) {
            if ((u32)(g->unk26DB8 - 0x10) < 2 && D_800E28D4 < 0xDF) {
                D_80146968 = calc(2);
            } else {
                D_80146968 = calc(4);
            }
        }
        break;
    }
    D_800D2988 = (f32)(D_80146968 * 15) / D_80146CFC;
    if (func_00245788() != 0) {
        D_800D2988 = fs;
    }
    func_002532E4(0);
    D_8014AD98 = D_8011FE80;
    func_00292318(g);
    g->unk26DB0 += D_800D2988;
    func_00293C20(g);
    if (func_442B98(D_8014561C) == 0 && func_00245788() != 0 && func_00245AFC() == 0x78) {
        if (D_80146928 == 0 && g->unk26DD4 == 0) {
            D_80146928 = 1;
            func_4037D4();
        }
    }
    if (D_80146928 != 0 && func_00245840() != 0) ok = 1; else ok = 0;
    if (ok && g->unk26DB8 != 0x10 && g->unk26DBC != 0x10) {
        g->unk26DC1 = 2;
        g->unk26DBC = 0x10;
    }
}
