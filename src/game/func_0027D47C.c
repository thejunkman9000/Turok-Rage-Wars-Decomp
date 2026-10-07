#include "b18_types.h"

typedef struct B18Par {
    /* 0x000 */ u8 type;
    /* 0x001 */ u8 pad1[0xFF];
    /* 0x100 */ u32 flags100;
    /* 0x104 */ u8 pad104[0xD4];
    /* 0x1D8 */ void *owner;
} B18Par;

typedef struct B18Fy B18Fy;
struct B18Fy {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[8];
    /* 0x01C */ Vec3f unk1C;
    /* 0x028 */ u8 pad28[0x34];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ B18Cfg *cfg;
    /* 0x11C */ u8 pad11C[0x10];
    /* 0x12C */ B18Par *unk12C;
    /* 0x130 */ u8 pad130[8];
    /* 0x138 */ s32 unk138;
    /* 0x13C */ u8 pad13C[0x10];
    /* 0x14C */ s16 unk14C;
    /* 0x14E */ u8 pad14E[0x6B];
    /* 0x1B9 */ s8 unk1B9;
    /* 0x1BA */ s8 unk1BA;
    /* 0x1BB */ u8 pad1BB[0x15];
    /* 0x1D0 */ s8 unk1D0;
    /* 0x1D1 */ u8 pad1D1[8];
    /* 0x1D9 */ u8 unk1D9;
};

typedef struct B18GPos {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ u8 pad0C[0xDC];
    /* 0xE8 */ Vec3f vF0;
} B18GPos;

extern void *D_801041F0;
extern B18GPos D_801041F8;
extern Vec3f D_801042C8;
extern u8 D_801462E5;
extern u32 D_801042F0;
extern B18T8 D_800D1384[];
extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];
extern u8 D_80121990[];

s32 func_00216108(void *a);
s32 func_0028403C(void *a);
void func_00265E30(void *a, void *b, u16 c, s32 d, Vec3f e, B18Vec2 f);
void func_00279BB0(void *a, u16 b, s8 c, s32 d);
void func_0025DE74(s16 a, Vec3f b, s32 c, void *d);
void func_002A6BD4(void *a, Vec3f b, Vec3f c, s32 d, s32 e);
void func_0022B054(void *a, void *b);
void func_0028414C(void *a);
void func_002A52E4(void *a, void *b);
void func_00268C7C(void *a, s32 b);
void func_002720EC(Vec3f *a);
void func_0027200C(Vec3f *a, Vec3f *b, f32 c);
void func_00271FA4(Vec3f *a, Vec3f *b, Vec3f *c);
void func_00284544(void *a, void *b);
void func_00284408(void *a);

void func_0027D47C(B18Fy *o) {
    B18Vec2 sp28;
    Vec3f sp30;
    B18Vec2 sp40;
    void *cam;
    B18Cfg *cfg;
    s32 st;

    cam = D_801041F0;
    cfg = o->cfg;
    st = func_00216108(cam);
    if (st == 5) {
        st = 4;
        o->flags |= 2;
    }
    if (D_801462E5 != 0 && func_0028403C(o) != 0) {
        B18Cfg *c = o->cfg;
        s32 idx, s2, s3, v1;
        if (func_0028403C(o) != 0) idx = 0xC; else idx = 0xA;
        s2 = c->tab->a70[idx];
        v1 = c->tab->a8C[idx];
        sp40 = c->tab->vec[idx];
        s3 = c->tab->aA8[idx];
        if (v1 != 0xFFFF) {
            func_00265E30(o, o, v1, -1, o->pos, sp40);
        }
        if (s2 != 0xFFFF) {
            func_00279BB0(o, s2, o->unk1D0, 1);
        }
        if (s3 != 0xFFFF) {
            func_0025DE74(s3, o->pos, 0, (void *)-1);
        }
        goto tail;
    }
    switch (st) {
    case 0:
    case 2:
    case 3:
        if (cfg->flags & 0x800000) {
            func_002A6BD4(D_8013BA80, D_801041F8.pos, D_801041F8.vF0, st, 0);
        }
        break;
    }
    if (o->unk1B9 == 8 || o->unk1BA == 8) {
        if (D_801042F0 & 0x1000000) {
            B18Par *p = o->unk12C;
            if (p != NULL && p->type == 1 && (p->flags100 & 0x300000)) {
                o->flags |= 0x20000;
                o->pos = D_801041F8.pos;
                o->unk1C = D_801042C8;
                func_0022B054(o->unk12C->owner, &o->pos);
            } else {
                o->unk14C = 1;
            }
        } else {
            o->unk14C = 1;
        }
    }
    if (o->type == 0x56 || o->type == 0x126 || o->type == 0xCD || o->type == 0xF) {
        o->flags |= 0x20000;
        o->pos = D_801041F8.pos;
        o->unk1C = D_801042C8;
        if (o->unk1D9 != 0) {
            func_0028414C(o);
            func_002A52E4(D_8013BA80, o);
        }
        if (o->unk138 != 0) {
            func_00268C7C(D_8013B1A8, o->unk138);
            o->unk138 = 0;
        }
    }
    sp30 = D_801041F8.vF0;
    func_002720EC(&sp30);
    func_0027200C(&sp30, &sp30, 1.024f);
    func_00271FA4(&o->pos, &o->pos, &sp30);
    {
    s32 s2, s3, v1;
    s2 = cfg->tab->a70[st];
    v1 = cfg->tab->a8C[st];
    sp28 = cfg->tab->vec[st];
    s3 = cfg->tab->aA8[st];
    if (v1 != 0xFFFF) {
        void *a0 = cam;
        if (D_800D1384[v1].w0 & 2) a0 = o;
        func_00265E30(a0, o, v1, -1, D_801041F8.pos, sp28);
    }
    if (s2 != 0xFFFF) {
        func_00279BB0(o, s2, -8, 1);
    }
    if (s3 != 0xFFFF) {
        func_0025DE74(s3, D_801041F8.pos, 0, o);
    }
    }
    if (!(o->flags & 0x30000) && o->unk1B9 == 1) {
tail:
        func_00284544(D_80121990, o);
        func_00284408(o);
    }
}
