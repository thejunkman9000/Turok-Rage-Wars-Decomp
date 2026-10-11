#include "s903b_types.h"

extern CcGs D_801041F0;
extern u8 D_801462E5;
extern CcQ *D_80103FCC;
extern CcObj *D_801315F8;
extern B18T8 D_800D1384[];
extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];
extern u8 D_80121990[];



s32 func_00216108(void *a);
s32 func_0024E130(void *a);
s32 func_0024E2B4(void *a);
void func_00247F08(CcPar *p, void *a1, void *m, Vec3f pos, Vec3f v, s32 idx);
void func_0025DE74(s16 a, Vec3f b, s32 c, void *d);
void func_00265E30(void *a, void *b, u16 c, s32 d, Vec3f e, CcPr f);
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

static inline void attach_actor(CcObj *ob, s32 st, u8 *m)
{
    u8 spB8[0x40];
    Vec3f spF8;
    void *pp = D_801041F0.unk0;
    func_0026EFC8(spB8, m);
    func_00272908(spB8, &D_801041F0.pos, &ob->unk50);
    spF8 = D_801041F0.vD8;
    func_002720EC(&spF8);
    func_00272BA8(spB8, &spF8, &ob->unk1C);
    ob->flags |= 0x10000;
    ob->unk134 = pp;
    ob->unk1D1 = D_801041F0.idx;
    if (ob->type == 0x56 && st == 2) {
        ob->flags |= 0x4000000;
    }
}

void func_0027CCD0(CcObj *o) {
    CcPr sp28;
    CcPr sp30;
    u8 sp38[0x80];
    s32 sp108;
    s32 sp10C;
    s32 sp110;
    CcPar *P;
    CcPar *par;
    CcCfg *cfg;
    void *pp;
    s32 st;
    s32 f13;
    s32 v70, v8C, vA8;
    s32 ok;

    par = NULL;
    P = D_801041F0.unk0;
    sp10C = 1;
    f13 = 0;
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
                func_00270980(sp38, par->unkB8 + (D_801041F0.idx << 6));
                sp110 = 1;
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
                    if (o->type == 0x56 || o->type == 0x2 || o->type == 0x126 || o->type == 0xF || f13 != 0 ||
                        (o->type == 0xB && (D_801041F0.unk7D & 3) == 1)) {
                        attach_actor(o, st, sp38);
                        if (o->unk1D9 != 0) {
                            func_0028414C(o);
                            func_002A52E4(D_8013BA80, o);
                        }
                        if (o->unk138 != 0) {
                            func_00268C7C(D_8013B1A8, o->unk138);
                            o->unk138 = 0;
                        }
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
    sp28 = cfg->tab->vec[st];
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
                sp30 = *(CcPr *)(tb + 0x20);
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
            CcRoot *R, *R2;
            s32 rt;
            D_801315F8->unk180 = D_80103FCC->unkF0;
            if (sp110 == 0) {
                func_00270980(sp38, par->unkB8 + (D_801041F0.idx << 6));
            }
            func_00273860(sp38, 3.141593f);
            R = D_80103FCC->unk0;
            rt = R->type;
            if (rt == 1) {
                if (*R->tab18 == 2) {
                    func_00270980(sp38, par->unkB8 + (D_801041F0.idx << 6));
                }
                R2 = D_80103FCC->unk0;
                if (R2->type == rt && ((R2->flags100 & 0x300000) || *R2->tab18 == 2)) {
                    CcObj *tgt = D_801315F8;
                    attach_actor(tgt, st, sp38);
                }
            }
        }
        if (sp108 == 1 || (v8C != 0xFFFF && (D_800D1384[v8C].w0 & 1))) {
            func_00284544(D_80121990, o);
            func_00284408(o);
        }
    }
}
