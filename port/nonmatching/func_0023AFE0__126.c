#include "m03_types.h"

extern f32 D_800D2988;
extern f32 D_800D2994;
extern u8 D_8011FE88[];
extern M03EClass *D_8013B188;
extern s32 D_8013B18C;
extern s32 D_8013B29C;
void func_002390C0(M03V3 *dst, M03EOwner *o);
void func_00255C58(void *list, void *n);
void func_00255CB4(void *list, void *n);
void func_00255E78(void *list, void *n);
f32 func_00275E44(s32 id, s32 x, s32 z);
M03ERec *func_0028B2D4(void *w, s32 id);
void func_00296DDC(void *m, s16 v);

void func_0023AFE0(M03EScene *sc, M03EOwner *o) {
    M03V3 v;
    M03V3 v2;
    M03ERec *rec;
    M03EClass *c;
    M03Emit *e;
    M03Emit *next;
    s32 id;
    s32 inside;
    s32 n;
    s32 bit;
    u16 mask;
    f32 hh;
    f32 k;
    f32 off;
    f32 val;
    f32 t;
    f32 acc;
    f32 y;
    s32 remove;

    if (D_8013B29C == 0) {
        id = o->id;
        if (id != 0) {
            rec = func_0028B2D4(D_8011FE88, id);
            if (rec != 0) {
                off = 0.0f;
                inside = 0;
                hh = func_00275E44(id, o->w38, o->w40);
                if (rec->flags44 & 1) {
                    func_002390C0(&v, o);
                    k = 0.5f;
                    if (20.48f < (rec->f20 - v.y) * k) {
                        k = 20.48f;
                    } else {
                        func_002390C0(&v2, o);
                        k = (rec->f20 - v2.y) * k;
                    }
                    func_002390C0(&v, o);
                    inside = 1;
                    if (!(v.y < rec->f20)) {
                        inside = 0;
                    }
                    off = rec->f20 - k;
                }
                c = D_8013B188;
                mask = rec->mask;
                n = D_8013B18C - 1;
                bit = 1;
                if (n != -1) {
                    val = 1.0f;
                    do {
                        if ((mask & bit) && c->id != 0 && !(sc->used & bit)) {
                            e = sc->freeHead;
                            if (e != 0) {
                                func_00255E78(&sc->freeHead, e);
                                func_00255CB4(&sc->actHead, e);
                            }
                            if (e != 0) {
                                e->cls = c;
                                e->mask = bit;
                                func_00296DDC(e->mtx, c->id);
                                e->f1C = 0;
                                e->f20 = 0;
                                e->f208 = 0;
                                e->f20C = 0;
                                e->f214 = val;
                                e->f218 = val;
                                e->f21C = 0;
                                e->f220 = val;
                                sc->used |= bit;
                            }
                        }
                        c++;
                        n--;
                        bit <<= 1;
                    } while (n != -1);
                }
                if (mask & 0xFFFF) {
                    e = sc->actHead;
                    if (e != 0) {
                        k = 1.0f;
                        do {
                            next = e->next;
                            c = e->cls;
                            if (e->mask & mask) {
                                t = e->f208 + c->f20 * D_800D2988;
                                if (k < t) {
                                    t = k;
                                    goto store;
                                }
                                e->f208 = t;
                                goto common;
                            }
                            t = e->f208;
                            remove = 1;
                            if (t != 0.0f) {
                                t = t - c->f20 * D_800D2988;
                                if (t < 0.0f) {
                                    t = 0.0f;
                                }
store:
                                e->f208 = t;
common:
                                e->f20C = e->f20C + D_800D2988 * c->f10 * e->f214;
                                acc = D_800D2988 * D_800D2994 * c->f8;
                                t = e->f1C + acc * 1.536f;
                                e->f1C = t;
                                if (20480.0f < t) {
                                    e->f1C = t - 20480.0f;
                                }
                                t = e->f20 + acc * 3.072f;
                                e->f20 = t;
                                if (20480.0f < t) {
                                    e->f20 = t - 20480.0f;
                                }
                                y = c->f14 + e->f21C;
                                if (inside != 0 && o->f24 == 0) {
                                    y += off;
                                } else {
                                    if (c->flags29 & 1) {
                                        y += o->f12C * c->f1C;
                                    } else if (c->flags29 & 2) {
                                        y += hh;
                                    }
                                }
                                e->f210 = y;
                                remove = 0;
                            }
                            if (remove != 0) {
                                sc->used &= ~e->mask;
                                func_00255E78(&sc->actHead, e);
                                func_00255C58(&sc->freeHead, e);
                            }
                            e = next;
                        } while (e != 0);
                    }
                }
            }
        }
    }
}
