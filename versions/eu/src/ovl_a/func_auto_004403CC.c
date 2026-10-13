#include "q04_types.h"
typedef struct { s32 mode; f32 f4; f32 f8; f32 fC; f32 f10; u8 b14; u8 b15, b16, b17, b18, b19, b1A; u8 pad1B; } Q04Ent;
typedef struct { u8 pad[0x44]; void *ctx; } Q04Pan;
typedef struct { u8 pad[0x29C]; f32 f29C; f32 f2A0; } Q04Cam;
typedef struct { u8 pad[0x24]; s32 f24; s32 f28; } Q04Sub;
extern Q04Ent D_auto_800F24E4[];
extern u8 D_auto_80152225;
extern u8 D_auto_80152789;
extern s32 D_auto_800EEEF0[];
extern s32 D_auto_800EEEF4;
extern s32 func_002934DC();
extern s32 func_00265370();
extern Q04Cam *func_auto_00443980();
extern u8 *func_auto_0043FFC0();
extern f32 func_auto_00443218(u8 *s, f32 a, f32 b);
extern void func_002AB940(void *a, s32 b, s32 *c, s32 *d);
void func_auto_004403CC(Q04Item *it, Q04Info *o);
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
void func_auto_004403CC(Q04Item *it, Q04Info *o) {
    Q04Cam *cam;
    Q04Ent *E;
    Q04Item cp;
    Q04Info a, b, c;
    u8 *p;
    Q04Sub *sub;
    s32 n, n2;
    f32 fs, v, k, fa, fb, vt, vt2, hh;
    cam = func_auto_00443980(((Q04Pan *)it->owner)->ctx);
    o->f10 = 1.0f;
    o->fC = 1.0f;
    switch (it->w4) {
    case 0:
    case 5:
        E = Q04TypeEnt(it);
        if (E->mode == 0) {
            fs = E->f4;
            if (it->w4 == 5) p = func_auto_0043FFC0(it);
            else p = ((u8 **)it->f14)[D_auto_80152789];
            v = func_auto_00443218(p, fs, fs);
        } else {
            n = 0;
            p = (it->w4 == 5 ? func_auto_0043FFC0(it) : ((u8 **)it->f14)[D_auto_80152789]);
            for (; p != 0 && *p != 0 && *p != 10; p++) n++;
            v = (f32)n * E->f4;
        }
        o->f4 = (s32)v;
        if (it->flags & 0x08000000) {
            k = 0.10810811f;
            hh = (f32)D_auto_800EEEF4;
            v = hh;
        } else {
            if (E->mode == 2 && D_auto_800EEEF4 >= 0xDF) {
                hh = (f32)D_auto_800EEEF4;
                v = (E->f8 + 0.5f) * hh;
            } else {
                hh = (f32)D_auto_800EEEF4;
                v = E->f8 * hh;
            }
            k = 0.0045045046f;
        }
        o->f8 = (s32)(v * k);
        do { o->f4 = (o->f4 * D_auto_800EEEF0[0]) / 284; } while (0);
        break;
    case 4:
        E = Q04TypeEnt(it);
        o->f4 = (s32)E->f4;
        o->f8 = (s32)(E->f8 * (f32)D_auto_800EEEF4 * 0.0045045046f);
        break;
    case 1:
        if ((func_002934DC() != 0 && (it->flags & 0x40000000) != 0) ||
            (D_auto_80152225 != 0 && (s32)it->flags < 0 && func_00265370() == 0x400000)) {
            o->f4 = 0x11C;
            o->f8 = 0xDE;
        } else {
            func_002AB940((void *)it->f14, 0, &o->f4, &o->f8);
        }
        if ((it->flags & 0x10000000) && (f32)o->f4 != 0.0f && (f32)o->f8 != 0.0f) {
            fa = cam->f29C / (f32)o->f4;
            fb = cam->f2A0 / (f32)o->f8;
        } else {
            fa = (f32)D_auto_800EEEF0[0] * 0.0035211267f;
            fb = (f32)D_auto_800EEEF4 * 0.0045045046f;
        }
        o->fC = fa;
        o->f10 = fb;
        break;
    case 2:
        a = *o;
        cp = *it;
        cp.w4 = 0;
        func_auto_004403CC(&cp, &a);
        b = *o;
        cp = *it;
        cp.w4 = 1;
        cp.f14 = 0;
        func_auto_004403CC(&cp, &b);
        c = *o;
        cp = *it;
        cp.w4 = 1;
        cp.f14 = 0;
        func_auto_004403CC(&cp, &c);
        n2 = b.f4 + c.f4;
        if (n2 < a.f4) n2 = a.f4;
        o->f4 = n2;
        o->f8 = a.f8 + b.f8 + ((c.f8 - b.f8) / 2);
        break;
    case 3:
        sub = (Q04Sub *)it->f14;
        o->f4 = (s32)(((f32)sub->f24 * cam->f29C) / (f32)D_auto_800EEEF0[0]);
        o->f8 = (s32)(((f32)sub->f28 * cam->f2A0) / (f32)D_auto_800EEEF4);
        break;
    default:
        o->f4 = 1;
        o->f8 = 1;
        break;
    }
    vt = (f32)(((s16)it->wC * D_auto_800EEEF0[0]) / 284);
    if (!(it->flags & 0x8000)) {
        if (it->flags & 0x4000) o->x0 = (s32)((f32)o->x1 + vt);
        else o->x0 = (s32)vt;
    }
    o->x1 = (s32)((f32)o->x0 + (f32)o->f4 * o->fC);
    vt2 = (f32)(((s16)it->wE * D_auto_800EEEF4) / 222);
    if (!(it->flags & 0x20000)) {
        if (it->flags & 0x10000) o->y0 = (s32)((f32)o->y1 + vt2);
        else o->y0 = (s32)vt2;
    }
    o->y1 = (s32)((f32)o->y0 + (f32)o->f8 * o->f10);
}
