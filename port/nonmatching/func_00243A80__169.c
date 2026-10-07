#include "r04_types.h"

typedef struct R4Gs { u8 pad0[0xD8]; Vec3f v; } R4Gs;

extern R4Gs *D_80103FCC;
extern f32 D_800C8880;
extern f32 D_800C8884;
extern f32 D_800C8888;
extern f32 D_800C888C;
extern f32 D_800C8890;
extern f32 D_800C8894;
extern f32 D_800C8898;
extern s32 D_800D0650;
extern s32 D_800D0654;
extern u32 D_80103FD0[];
extern u32 D_80104170[];
extern u32 D_801041D0[];
extern u32 D_80104338[];
extern R4Fl7 D_801040F0;
f32 sinf(f32);
f32 cosf(f32);
void func_0023EBC4(R4Mc *c);
void func_0023CFD0(R4Mc *c);
s32 func_0023D148(R4Mc *c);
s32 func_0023D370(R4Mc *c);
void func_0023E44C(R4Mc *c);
void func_0023E680(R4Mc *c, f32 a, f32 b, f32 d, f32 e);
void func_0023E6DC(R4Mc *c, R4Hit *h);
void func_0023E828(R4Mc *c);
void func_0023EBEC(R4Mc *c, s32 *k);
void func_0023EC44(R4Mc *c, s32 *k);
void func_0023ECAC(R4Mc *c, R4Hh *h);
f32 func_002417B4(s32 *k);
f32 func_0024D274(R4Ob *o);
f32 func_0024D388(R4Ob *o);
f32 func_0024E410(R4Ob *o);
f32 func_0024E454(R4Ob *o, s32 g);
f32 func_00274004(f32 a, f32 b);
void func_002748E0(f32 *a, f32 b, s32 c);
f32 func_002752CC(R4Hh *h, f32 x, f32 z);
f32 func_00275E44(R4Hh *h, f32 x, f32 z);
R4Hh *func_0028C02C(void *a, Vec3f *p);

s32 func_00243A80(R4Ob *o, Vec3f to, u32 *fl) {
    R4Mc c;
    R4Hit hit;
    R4Fl7 cp;
    f32 ang;
    f32 sn;
    f32 cs;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 y;
    s32 n;
    s32 k;
    s32 g;
    s32 r;
    R4Hh *h;

    func_0023EBC4(&c);
    D_80103FCC->v = o->vel;
    o->flags38 &= ~0x18;
    c.o = o;
    g = 0;
    if (o->type == 1) {
        g = (o->flags100 & 0x300000) > 0;
    }
    c.ground = g;
    f1 = func_0024E454(o, g);
    f2 = func_0024D388(o);
    f3 = func_0024D274(o);
    func_0023E680(&c, f1, f2, f3, func_0024E410(o));
    c.p44 = o->pos;
    c.p50 = to;
    c.p74 = o->vel;
    c.fAC = o->p14;
    g = 0;
    if ((*fl & 0x200) && o->vel.y <= 0.0f) {
        g = 1;
    }
    c.w24 = g;
    c.w20 = (*fl >> 1) & 1;
    c.w2C = 1;
    c.w28 = ((o->flags38 >> 2) ^ 1) & 1;
    c.flags = o->flags38;
    c.f1C = c.f10 * D_800C8880;
    c.fp = fl;
    c.w38 = (*fl >> 19) & 1;
    func_0023CFD0(&c);
    if (c.w24 != 0 && (c.flags & 7) && !(c.flags & 0x2000)) {
        hit.b = o->v44;
        hit.a.x = o->pos.x;
        hit.a.y = o->f40;
        hit.a.z = o->pos.z;
        func_0023E6DC(&c, &hit);
    }
    r = 0;
    if (c.ground != 0 || c.p44.x != c.p50.x || c.p44.y != c.p50.y || c.p44.z != c.p50.z) {
        D_800D0650++;
        if (D_800D0650 < D_800D0654) {
            D_800D0650 = D_800D0654;
        }
        D_800D0654 = D_800D0650;
        if (fl != D_80104338 && fl != D_801041D0 && fl != D_80103FD0 && fl != D_80104170) {
            o->p34 = 0;
            c.flags &= ~0x7B;
        }
        c.flags &= ~0x80;
        if (o->type != 1) {
            ang = 0.0f;
        } else {
            ang = o->f6C;
        }
        sn = sinf(ang);
        cs = cosf(ang);
        c.flags &= ~0x2000;
        if (*fl & 4) {
            k = 1;
        } else if (*fl & 0x800) {
            k = 3;
        } else {
            k = 1;
            if (o->type == 1) {
                k = 4;
            }
        }
        c.w30 = (k >= 3) ? 2 : k;
        c.w34 = (k + 1 >= 4) ? 3 : k + 1;
        func_0023E828(&c);
        n = 0;
        do {
            if (*fl & 0x80000) {
                c.fAC = func_0028C02C(c.fAC, &c.p50);
            }
            g = 0;
            if (func_0023D148(&c) != 0) {
                if (c.kind != 1) {
                    if (c.kind == 4) {
                        if (c.nrm.x * -sn + c.nrm.z * -cs < D_800C8884) {
                            c.flags |= 0x80;
                            func_0023EBEC(&c, &c.kind);
                        }
                    } else {
                        c.flags &= ~0x80;
                    }
                } else {
                    c.w20 = 0;
                    c.flags &= ~0x80;
                }
                func_0023E44C(&c);
                n++;
                g = func_0023D370(&c);
                c.p44 = c.p180;
                c.p50 = c.p198;
                c.p74 = c.p1A4;
            } else {
                c.p44 = c.p50;
            }
            k--;
        } while (g != 0 && k != 0);
        o->pos = c.p44;
        o->vel = c.p74;
        c.flags &= ~4;
        if (*fl & 0x40000) {
            c.p50 = c.p44;
            c.p50.y = c.p50.y - D_800C8888;
            c.w2C = 0;
            c.w30 = 0;
            c.w34 = 0;
            cp = D_801040F0;
            c.fp = cp.w;
            cp.w[0] &= 0xFFE7FFF7;
            c.w38 = 0;
            cp.w[0] |= *fl & 0x180008;
            func_0023E828(&c);
            o->v44.x = 0.0f;
            o->v44.z = 0.0f;
            o->v44.y = D_800C888C;
            o->f40 = o->pos.y - D_800C8888;
            do {
                if (func_0023D148(&c) != 0) {
                    if (c.kindB == 7) {
                        c.w24 = 0;
                    }
                    func_0023D370(&c);
                    g = 0;
                    o->f40 = c.p180.y;
                    o->v44 = c.nrm;
                    y = o->pos.y - c.p180.y;
                    if (c.w24 != 0 && y < D_800C8890) {
                        c.w24 = 0;
                        o->vel.y = 0.0f;
                        y = o->vel.y;
                        o->pos.y = c.p180.y;
                    }
                    if (o->vel.y <= 0.0f && y < D_800C8894) {
                        if (c.kind == 5) {
                            c.flags |= 0x2004;
                            func_0023EC44(&c, &c.kind);
                            g = 1;
                            *c.fp &= ~8;
                        } else {
                            if (c.kind >= 5 && c.kind < 10 && c.kind >= 7 && c.hitobj->type == 1) {
                                o->p34 = c.hitobj;
                                k = c.hitobj->flags38;
                                c.hitobj->flags38 = k | 0x20;
                                if (c.ground != 0) {
                                    c.hitobj->flags38 = k | 0x60;
                                }
                                c.flags = (c.flags & ~3) | 2;
                            } else {
                                c.flags |= 4;
                            }
                        }
                    }
                    if (g != 0) {
                        c.p44 = c.p180;
                    }
                } else {
                    g = 0;
                }
            } while (g != 0);
        }
        g = c.flags;
        c.flags = g & ~0x100;
        if (c.w20 != 0 || (g & 0x80)) {
            c.p44 = o->pos;
            c.p50 = o->pos;
            c.w2C = 0;
            c.w30 = 0;
            c.w34 = 0;
            c.fp = D_801040F0.w;
            c.p50.x = c.p50.x - sn * D_800C8898;
            c.p50.z = c.p50.z - cs * D_800C8898;
            func_0023E828(&c);
            if (func_0023D148(&c) != 0 && c.kind == 4) {
                if (c.w20 != 0) {
                    func_0023D370(&c);
                    o->pos.x = c.p180.x;
                    o->pos.z = c.p180.z;
                    c.flags |= 0x100;
                    func_0023EBEC(&c, &c.kind);
                    if (o->type == 1) {
                        func_002748E0(&ang, ang - func_00274004(ang, func_002417B4(&c.kind)), 0x3F666666);
                        o->f6C = ang;
                    }
                }
            } else {
                c.flags &= ~0x80;
            }
        }
        if (*fl & 0x80000) {
            h = func_0028C02C(c.fAC, &o->pos);
            c.flags &= ~0x5000;
            if (h != 0) {
                if ((h->h2 & 0x41) == 0x41 && func_00275E44(h, o->pos.x, o->pos.z) <= o->pos.y) {
                    f1 = func_002752CC(h, o->pos.x, o->pos.z);
                    if (o->pos.y <= f1) {
                        c.flags |= 0x4000;
                    }
                    if (o->pos.y <= f1 + c.f1C) {
                        c.flags |= 0x1000;
                    }
                    func_0023ECAC(&c, h);
                }
            }
            o->p14 = h;
        }
        r = n;
        o->flags38 = c.flags;
    }
    return r;
}
