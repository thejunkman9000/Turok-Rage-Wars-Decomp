#include "q04_types.h"
typedef struct { s32 mode; u8 pad4[8]; f32 fC; f32 f10; u8 b14; u8 b15, b16, b17, b18, b19, b1A; u8 pad1B; } Q04Ent;
typedef struct { u16 w0; u8 pad2[0x2E]; f32 f30; f32 f34; s32 f38; s32 f3C; } Q04W;
typedef struct { s32 x0; u8 pad4[0x10]; s32 x; u8 pad18[4]; s32 y; } Q04B;
typedef struct { s32 f0; s32 f1[2]; } Q04Pair;
extern Q04Ent D_auto_800F24E4[];
extern s32 D_auto_800F24E0;
extern u8 D_auto_80152225;
extern s32 D_auto_80157150;
extern s32 D_auto_800EEEF0;
extern s32 D_auto_800EEEF4;
extern u8 D_auto_80152789;
extern s32 D_auto_801477B8[];
extern s32 func_002934DC();
extern s32 func_00265370();
extern void func_auto_00442AD8(Q04W *w, Q04Item *it, s32 c);
extern void func_002A94E8();
extern void func_002A9700(void);
extern void func_002A97F0(void);
extern void func_002ABB2C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_002ABB58(f32 a, f32 b);
extern void func_002A9F18(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g, f32 h);
static inline Q04Ent *Q04TypeEnt(Q04Item *it) {
    s32 i;
    i = 0;
    switch (it->flags & 0x3FE0) {
    case 0x20: i = 0; break;
    case 0x40: i = 1; break;
    case 0x80: i = 2; break;
    case 0x100: i = 3; break;
    case 0x200: i = 4; break;
    case 0x400: i = 5; break;
    case 0x800: i = 6; break;
    case 0x1000: i = 7; break;
    case 0x2000: i = 8; break;
    default: i = 0; break;
    }
    i += D_auto_80152789 * 9;
    return &D_auto_800F24E4[i];
}
void func_auto_00440D10(Q04Item *it, Q04B *b, void *c, Q04W *w, s32 e, s32 f) {
    u8 en;
    Q04Ent *E;
    s32 m;
    f32 k;
    s32 r, g, bl, a, t, t2;
    en = 1;
    if ((func_002934DC() != 0 && (it->flags & 0x40000000) != 0) ||
        (D_auto_80152225 != 0 && (s32)it->flags < 0 && func_00265370() == 0x400000)) {
        w->f38 = 0;
    }
    if (it->flags & 0x08000000) {
        if (w->f3C != 0) w->f38 = 0;
        func_auto_00442AD8(w, it, 1);
        func_auto_00442AD8(w, it, 0);
        en = 0;
    }
    if (w->f38 == 0) en = 0;
    E = Q04TypeEnt(it);
    m = E->mode;
    if (f != 0) m = 6;
    if (D_auto_800F24E0 != m) {
        switch (m) {
        case 0: func_002A94E8(); break;
        case 1: func_002A94E8(); func_002A9700(); break;
        case 2: func_002A94E8(); func_002A97F0(); break;
        case 6: func_002A94E8(); func_002A9700(); D_auto_80157150 = 1; break;
        }
        D_auto_800F24E0 = m;
    }
    if (b->x0 == (s16)w->w0) k = 1.25f;
    else k = !(it->flags & 0x01000000) ? 0.25f : 0.9f;
    t = (s32)((f32)E->b15 * k); r = 0xFF; if (t < 0x100) r = t;
    t = (s32)((f32)E->b16 * k); g = 0xFF; if (t < 0x100) g = t;
    t = (s32)((f32)E->b17 * k); bl = 0xFF; if (t < 0x100) bl = t;
    t = (s32)((f32)E->b18 * k); a = 0xFF; if (t < 0x100) a = t;
    func_002ABB2C(r, g, bl, a, (t = (s32)((f32)E->b19 * k)) < 0x100 ? t : 0xFF, (t2 = (s32)((f32)E->b1A * k)) < 0x100 ? t2 : 0xFF);
    D_auto_801477B8[0] = E->b14;
    D_auto_801477B8[1] = E->b14;
    func_002ABB58(E->fC * (f32)D_auto_800EEEF0 * 0.0035211267f, E->f10 * (f32)D_auto_800EEEF4 * 0.0045045046f);
    if (en != 0) en = E->b14;
    func_002A9F18(e, b->x, b->y, (s32)(w->f30 * (w->f34 * 255.0f)), 0, en, 1.0f, 1.0f);
}
