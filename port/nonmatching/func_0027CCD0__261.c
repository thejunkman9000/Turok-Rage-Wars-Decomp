#include "b18_types.h"

typedef struct B18Tb0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ u8 pad4[0x8C];
    /* 0x90 */ u8 pad90[4];
    /* 0x94 */ u16 unk94;
    /* 0x96 */ u8 pad96[0xA];
    /* 0xA0 */ u8 padA0[0x1C];
    /* 0xBC */ u8 padBC[4];
} B18Tb0;

typedef struct B18Pa B18Pa;
struct B18Pa {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[0x17];
    /* 0x018 */ s32 *tab18;
    /* 0x01C */ u8 pad1C[0x9C];
    /* 0x0B8 */ u8 *unkB8;
    /* 0x0BC */ u8 padBC[0x44];
    /* 0x100 */ u32 flags100;
    /* 0x104 */ u8 pad104[0x6C];
    /* 0x170 */ u32 unk170;
    /* 0x174 */ u8 pad174[0x114];
    /* 0x288 */ void (*unk288)(B18Pa *, void *, void *);
    /* 0x28C */ u8 pad28C[0x1158];
    /* 0x13E4 */ s32 unk13E4;
};

typedef struct B18Oz B18Oz;
struct B18Oz {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ u8 pad18[4];
    /* 0x01C */ Vec3f unk1C;
    /* 0x028 */ u8 pad28[0x28];
    /* 0x050 */ Vec3f unk50;
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ B18Cfg *cfg;
    /* 0x11C */ u8 pad11C[0x18];
    /* 0x134 */ void *unk134;
    /* 0x138 */ s32 unk138;
    /* 0x13C */ u8 pad13C[0x44];
    /* 0x180 */ Vec3f unk180;
    /* 0x18C */ u8 pad18C[0x2C];
    /* 0x1B8 */ s8 unk1B8;
    /* 0x1B9 */ s8 unk1B9;
    /* 0x1BA */ u8 pad1BA[0x17];
    /* 0x1D1 */ u8 unk1D1;
    /* 0x1D2 */ u8 pad1D2[7];
    /* 0x1D9 */ u8 unk1D9;
    /* 0x1DA */ u8 pad1DA[6];
    /* 0x1E0 */ f32 unk1E0;
};

typedef struct B18R {
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 pad1[0x17];
    /* 0x18 */ s32 *tab18;
    /* 0x1C */ u8 pad1C[0xE4];
    /* 0x100 */ u32 flags100;
} B18R;

typedef struct B18Q {
    /* 0x00 */ B18R *unk0;
    /* 0x04 */ u8 pad4[0xEC];
    /* 0xF0 */ Vec3f unkF0;
} B18Q;

typedef struct B18Tgt {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
} B18Tgt;

typedef struct B18Gs {
    /* 0x00 */ B18Pa *unk0;
    /* 0x04 */ u8 pad4[4];
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ s32 idx;
    /* 0x18 */ u8 pad18[0x65];
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 unk7E;
    /* 0x7F */ u8 pad7F[0x59];
    /* 0xD8 */ Vec3f vD8;
} B18Gs;

extern B18Gs D_801041F0;
extern u8 D_80104207;
extern u8 D_801462E5;
extern B18Q *D_80103FCC;
extern B18Oz *D_801315F8;
extern B18T8 D_800D1384[];
extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];
extern u8 D_80121990[];

typedef struct B18Pr {
    s16 a;
    s16 b;
    s32 c;
} B18Pr;

s32 func_00216108(void *a);
s32 func_0024E130(void *a);
s32 func_0024E2B4(void *a);
void func_00247F08(B18Pa *p, void *a1, void *m, Vec3f pos, Vec3f v, s32 idx);
void func_0025DE74(s16 a, Vec3f b, s32 c, void *d);
void func_00265E30(void *a, void *b, u16 c, s32 d, Vec3f e, B18Pr f);
void func_00268C7C(void *a, s32 b);
void func_0026EFC8(void *a, void *b);
void func_00270980(void *a, u8 *b);
void func_002720EC(Vec3f *a);
void func_00272908(void *a, Vec3f *b, Vec3f *c);
void func_00272BA8(void *a, Vec3f *b, Vec3f *c);
void func_00273860(void *a, f32 b);
void func_00279BB0(void *a, u16 b, s8 c, s32 d);
s32 func_0028403C(void *a);
void func_0028414C(void *a);
void func_00284408(void *a);
void func_00284544(void *a, void *b);
void func_002A52E4(void *a, void *b);

#define ATTACH(ob, st)     func_0026EFC8(spB8, sp38);     func_00272908(spB8, &D_801041F0.pos, &(ob)->unk50);     spF8 = D_801041F0.vD8;     func_002720EC(&spF8);     func_00272BA8(spB8, &spF8, &(ob)->unk1C);     (ob)->flags |= 0x10000;     (ob)->unk134 = pp;     (ob)->unk1D1 = D_80104207;     if ((ob)->type == 0x56 && (st) == 2) {         (ob)->flags |= 0x4000000;     }

void func_0027CCD0(B18Oz *o) {
    B18Pr sp28;
    B18Pr sp30;
    u8 sp38[0x80];
    u8 spB8[0x40];
    Vec3f spF8;
    s32 sp108;
    s32 sp10C;
    s32 sp110;
    B18Pa *P;
    B18Pa *par;
    B18Cfg *cfg;
    void *pp;
    s32 st;
    s32 f13;
    s32 v70, v8C, vA8;
    s32 ok;

    par = NULL;
    P = D_801041F0.unk0;
    f13 = 0;
    sp10C = 1;
    sp110 = 0;
    cfg = o->cfg;
    if (func_0024E2B4(P) != 0) {
        sp108 = o->unk1B9;
    } else {
        sp108 = o->unk1B8;
    }
    if (o->unk14 == 0) {
        o->unk14 = 0;
    }
    if (D_801041F0.idx != -1) {
        st = func_00216108(P);
        if (st != 9) {
            st = D_801041F0.unk7E;
            if (o->type == 0xD) {
                st = 4;
            }
            par = D_801041F0.unk0;
            if (par->flags100 & 0x03000000) {
                sp110 = 1;
                func_00270980(sp38, par->unkB8 + (D_801041F0.idx << 6));
                if (par->flags100 & 0x01000000) {
                    func_00247F08(par, (u8 *)par + 0x170, sp38, D_801041F0.pos, D_801041F0.vD8, D_801041F0.idx);
                }
                if (par->flags100 & 0x02000000) {
                    if (o->type == 0x12A || o->type == 0x132) {
                        if (*par->tab18 == 0xB) {
                            s32 v = par->unk13E4;
                            f13 = v < 1;
                            if (f13 != 0) {
                                par->unk13E4 = v + 1;
                            }
                        }
                    }
                    switch (o->type) {
                    default:
                        if (f13 == 0) {
                            if (o->type == 0xB && (D_801041F0.unk7D & 3) == 1) {
                    case 0x56:
                    case 0x2:
                    case 0x126:
                                goto block27;
                            }
                        } else {
                    case 0xF:
                    block27:
                            pp = D_801041F0.unk0;
                            ATTACH(o, st)
                            if (o->unk1D9 != 0) {
                                func_0028414C(o);
                                func_002A52E4(D_8013BA80, o);
                            }
                            if (o->unk138 != 0) {
                                func_00268C7C(D_8013B1A8, o->unk138);
                                o->unk138 = 0;
                            }
                        }
                        break;
                    }
                }
            }
        }
    } else {
        st = func_00216108(P);
    }
    if (st == 5) {
        st = 4;
        o->flags |= 2;
    }
    if (func_0028403C(o) != 0 && st < 6 && st >= 4) {
        st = 6;
    }
    v70 = cfg->tab->a70[st];
    v8C = cfg->tab->a8C[st];
    sp28 = *(B18Pr *)&cfg->tab->vec[st];
    vA8 = cfg->tab->aA8[st];
    if (P->type == 1) {
        par = P;
        if (par->unk288 != NULL) {
            par->unk288(par, (u8 *)par + 0x170, o);
        }
        if (func_0024E130(par) != 0) {
            sp10C = 0;
        }
        if (par->unk170 & 2) {
            sp10C = 0;
        }
    }
    if (v8C != 0xFFFF) {
        void *a0;
        if (D_800D1384[v8C].w0 & 4) {
            if (o->type == 0x56) {
                sp28.b = (s32)((f32)sp28.b * o->unk1E0);
            }
        }
        a0 = P;
        if (D_800D1384[v8C].w0 & 2) a0 = o;
        func_00265E30(a0, o, v8C, -1, D_801041F0.pos, sp28);
    }
    if (st != 4) {
        ok = 1;
        if (D_801462E5 != 0) {
            ok = *P->tab18 != 0xB;
            if (sp108 == o->unk1B9) ok = 0;
        }
        if (ok != 0) {
            u8 *tb = (u8 *)cfg->tab;
            s32 a2 = *(u16 *)(tb + 0x94);
            if (a2 != 0xFFFF) {
                s32 fl = D_800D1384[a2].w0;
                sp30 = *(B18Pr *)(tb + 0x20);
                if (fl & 4) {
                    void *a0 = P;
                    if (fl & 2) a0 = o;
                    func_00265E30(a0, o, a2, -1, D_801041F0.pos, sp30);
                }
            }
        }
    }
    if (v70 != 0xFFFF) {
        func_00279BB0(o, v70, -8, sp10C);
    }
    if (vA8 != 0xFFFF) {
        func_0025DE74(vA8, D_801041F0.pos, 0, o);
    }
    if (!(o->flags & 0x30000)) {
        if (o->type == 0x3EF && D_801315F8 != NULL && par->unkB8 != 0 && D_801315F8->type == 0x41E && st != 9) {
            B18R *R;
            s32 rt;
            D_801315F8->unk180 = D_80103FCC->unkF0;
            if (sp110 == 0) {
                func_00270980(sp38, par->unkB8 + (D_801041F0.idx << 6));
            }
            func_00273860(sp38, 3.1415927f);
            R = D_80103FCC->unk0;
            rt = R->type;
            if (rt == 1) {
                if (*R->tab18 == 2) {
                    func_00270980(sp38, par->unkB8 + (D_801041F0.idx << 6));
                }
                R = D_80103FCC->unk0;
                if (R->type == rt && ((R->flags100 & 0x300000) || *R->tab18 == 2)) {
                    B18Oz *tgt = D_801315F8;
                    pp = D_801041F0.unk0;
                    ATTACH(tgt, st)
                }
            }
        }
        if (sp108 == 1 || (v8C != 0xFFFF && (D_800D1384[v8C].w0 & 1))) {
            func_00284544(D_80121990, o);
            func_00284408(o);
        }
    }
}
