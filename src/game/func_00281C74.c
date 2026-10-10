#include "b18_types.h"

typedef struct B18Hnd {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
} B18Hnd;

typedef struct B18Ob B18Ob;
struct B18Ob {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ u16 type;
    /* 0x006 */ u8 pad6[2];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ u8 pad14[0x48];
    /* 0x05C */ u32 flags;
    /* 0x060 */ u8 pad60[0xB8];
    /* 0x118 */ B18Cfg *cfg;
    /* 0x11C */ u8 pad11C[0x14];
    /* 0x130 */ s32 *counter;
    /* 0x134 */ u8 pad134[4];
    /* 0x138 */ B18Hnd *handle;
    /* 0x13C */ u8 pad13C[4];
    /* 0x140 */ f32 unk140;
    /* 0x144 */ u8 pad144[8];
    /* 0x14C */ s16 unk14C;
    /* 0x14E */ u8 pad14E[0x4A];
    /* 0x198 */ f32 unk198;
    /* 0x19C */ u8 pad19C[0x34];
    /* 0x1D0 */ s8 unk1D0;
    /* 0x1D1 */ u8 pad1D1[8];
    /* 0x1D9 */ u8 unk1D9;
    /* 0x1DA */ u8 pad1DA[0xA];
    /* 0x1E4 */ void *list;
    /* 0x1E8 */ u8 pad1E8[4];
    /* 0x1EC */ B18Ob *next;
};

typedef struct B18Bnd {
    /* 0x00 */ Vec3f min;
    /* 0x0C */ Vec3f max;
} B18Bnd;

typedef struct B18W {
    /* 0x0000 */ u8 pad0[0xFC00];
    /* 0xFC00 */ u8 listA[0x14];
    /* 0xFC14 */ u8 listB[0x14];
    /* 0xFC28 */ u8 cells[0x3C];
} B18W;

extern f32 D_800D2988;
extern f32 D_800D2990;
extern s32 D_80146894;
extern s32 D_8013B29C;
extern B18Bnd D_801031F0;
extern u8 D_8013BA80[];
extern u8 D_8013B1A8[];

void func_00255C58(void *a, B18Ob *b);
void func_00255E78(void *a, B18Ob *b);
void func_0025DE74(s16 a, Vec3f b, s32 c, s32 d);
void func_00265E30(B18Ob *a, B18Ob *b, u16 c, s32 d, Vec3f e, B18Vec2 f);
void func_00268C7C(void *a, void *b);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
void func_00279A70(B18Ob *a);
void func_00279BB0(B18Ob *a, u16 b, s8 c, s32 d);
void func_0027B790(B18Ob *a);
void func_00281A70(B18W *w, B18Ob *o, B18Ob **list, s32 n);
s32 func_0028403C(B18Ob *a);
void func_0028414C(B18Ob *a);
void func_002A52E4(void *a, B18Ob *b);

#define DESTROY(o) \
    func_00279A70(o); \
    if ((o)->unk1D9 != 0) { \
        func_0028414C(o); \
        func_002A52E4(D_8013BA80, o); \
    } \
    if ((o)->handle != NULL) { \
        func_00268C7C(D_8013B1A8, (o)->handle); \
        (o)->handle = NULL; \
    } \
    if ((o)->counter != NULL) { \
        *(o)->counter -= 1; \
    } \
    (o)->flags &= 0xFDFFFEFF; \
    func_00255E78((o)->list, o); \
    (o)->list = NULL; \
    func_00255C58(w->listA, o); \
    if ((o)->flags & 0x1000000) { \
        func_00255E78(w->listB, o); \
    }

void func_00281C74(B18W *w) {
    B18Ob *list2[128];
    B18Ob *list[128];
    B18Vec2 sp428;
    Vec3f sp430;
    s32 n, n2, i;
    f32 old;

    n = 0;
    old = D_800D2988;
    {
        B18Ob *o;
        for (i = 0; i < 3; i++) {
            for (o = *(B18Ob **)((u8 *)w + i * 0x14 + 0xFC28); o != NULL; o = o->next) {
                o->flags = (o->flags & 0xFFEFFFFF) | 0x2000000;
                list[n++] = o;
            }
        }
    }
    if (D_80146894 == 0) {
        if (D_8013B29C == 0) {
            D_800D2988 = old;
            D_800D2988 = old * D_800D2990;
            {
            i = 0;
            n2 = 0;
            for (; i < n; i++) {
                s32 one = 1;
                B18Ob *o = list[i];
                if ((o->flags & 0x2000100) == 0x2000100) {
                    u32 f = o->flags;
                    B18Hnd *h = o->handle;
                    o->flags = f & 0xFFEFFF87;
                    if (h != NULL) h->unk16 = 0;
                    if (o->unk140 < (f32)o->unk14C && o->unk14C != one && !(o->flags & 0x1000)) {
                        if ((D_801031F0.max.x > o->pos.x && D_801031F0.max.y > o->pos.y && D_801031F0.max.z > o->pos.z &&
                             D_801031F0.min.x <= o->pos.x && D_801031F0.min.y <= o->pos.y && D_801031F0.min.z <= o->pos.z) ||
                            o->type == 0x41E) {
                            func_0027B790(o);
                            h = o->handle;
                            if (h != NULL) {
                                h->unk16 = one;
                                h->unk10 = (s32)o->pos.x;
                                h->unk12 = (s32)o->pos.y;
                                h->unk14 = (s32)o->pos.z;
                                h->unkC = o->unk198 * 0.003921568859f;
                            }
                            o->unk140 += D_800D2988;
                        } else {
                            if (o->flags & 0x100) {
                                if (!(o->flags & 0x800)) {
                                    DESTROY(o)
                                }
                            }
                        }
                    } else {
                        B18Cfg *c = o->cfg;
                        s32 idx, s2, s3, v1;
                        if (func_0028403C(o) != 0) idx = 0xC; else idx = 0xA;
                        s2 = c->tab->a70[idx];
                        v1 = c->tab->a8C[idx];
                        sp428 = c->tab->vec[idx];
                        s3 = c->tab->aA8[idx];
                        if (v1 != 0xFFFF) {
                            func_00265E30(o, o, v1, -1, o->pos, sp428);
                        }
                        if (s2 != 0xFFFF) {
                            func_00279BB0(o, s2, o->unk1D0, 1);
                        }
                        if (s3 != 0xFFFF) {
                            func_0025DE74(s3, o->pos, 0, -1);
                        }
                        if (o->flags & 0x100) {
                            if (!(o->flags & 0x800)) {
                                DESTROY(o)
                            }
                        }
                    }
                    if (o->flags & 0x100) {
                        switch (o->type) {
                        case 0x57:
                        case 0xC:
                        case 0x22:
                            list2[n2++] = o;
                            break;
                        }
                    }
                }
            }
            }
            {
            s32 i, j;
            B18Ob **lp;
            if (n2 != 0) { lp = list2; for (i = 0; i < n2; i++) {
                B18Ob *o = lp[i];
                switch (o->type) {
                case 0xC:
                    break;
                case 0x22:
                    func_00281A70(w, o, lp, n2);
                    break;
                case 0x57:
                    for (j = 0; j < n2; j++) {
                        B18Ob *p = lp[j];
                        if (p->type != 0x57) {
                            func_00271FD8(&sp430, &p->pos, &o->pos);
                            if (sp430.x * sp430.x + sp430.y * sp430.y + sp430.z * sp430.z <= 65536.0f) {
                                p->unk14C = 1;
                            }
                        }
                    }
                    break;
                }
            }
            }
            }
            D_800D2988 = old;
        }
    }
}