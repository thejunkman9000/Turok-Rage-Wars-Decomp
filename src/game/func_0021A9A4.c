#include "r02_types.h"

typedef struct R2Hit {
    /* 0x0 */ s16 idx;
    u8 pad2[2];
    /* 0x4 */ s16 id;
    /* 0x6 */ u16 cost;
} R2Hit;

typedef struct R2Ent {
    u8 pad0[4];
    /* 0x4 */ s16 id;
} R2Ent;

typedef struct R2Def {
    u8 pad0[0x20];
    /* 0x20 */ R2Ent *alt[3];
    /* 0x2C */ R2Ent *tab[3];
} R2Def;

typedef struct R2Sub {
    u8 pad0[0x24];
    /* 0x24 */ s32 unk24;
    u8 pad28[0x100];
    /* 0x128 */ R2Vec3 v128;
} R2Sub;

typedef struct R2Plr {
    u8 pad0[0x1C];
    /* 0x01C */ R2Vec3 pos;
    u8 pad28[0x10];
    /* 0x038 */ u32 flags38;
    u8 pad3C[0xC8];
    /* 0x104 */ f32 f104;
    u8 pad108[6];
    /* 0x10E */ u8 b10E;
    u8 pad10F[0x37D];
    /* 0x48C */ s8 b48C;
    u8 pad48D[0x107];
    /* 0x594 */ s32 mode;
    u8 pad598[4];
    /* 0x59C */ s32 unk59C;
    u8 pad5A0[0x34];
    /* 0x5D4 */ s32 unk5D4;
    u8 pad5D8[4];
    /* 0x5DC */ R2Sub *sub;
    /* 0x5E0 */ s32 unk5E0;
    u8 pad5E4[0x10];
    /* 0x5F4 */ u16 tab5F4[7];
    /* 0x602 */ u8 b602[2];
    u8 pad604[0x2A];
    /* 0x62E */ s16 s62E;
    u8 pad630[0x20];
    /* 0x650 */ u16 state;
    u8 pad652[0x136];
    /* 0x788 */ s32 unk788;
    u8 pad78C[8];
    /* 0x794 */ void *unk794;
    u8 pad798[0x40];
    /* 0x7D8 */ R2Quat q7D8;
    u8 pad7E8[0x84];
    /* 0x86C */ s32 unk86C;
    u8 pad870[0xBE0];
    /* 0x1450 */ s32 unk1450;
    u8 pad1454[4];
    /* 0x1458 */ u8 blk1458[4];
} R2Plr;

extern f32 D_800C7408[2];
extern f32 D_800C7410[2];
extern f32 D_800C7418[2];
extern f32 D_800C7420[2];
extern R2Def *D_800D052C[];
extern s32 D_80103140[];
extern u8 D_80121990[];
extern s32 D_801450B8;

void func_0024795C(R2Quat *, R2Plr *);
R2Hit *func_0022AA8C(R2Plr *, s16);
void func_0022B134(R2Plr *, R2Vec3 *);
void func_00280094(void *, R2Plr *, R2Plr *, s32, void *, s32, R2Vec3, R2Quat, R2Vec3, void *, s32, s32);

static inline s32 r2_has(R2Ent **arr, s32 id) {
    s32 j;
    for (j = 0; j < 3; j++) {
        R2Ent *e = arr[j];
        if (e != NULL) {
            if (e->id == id) return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

void func_0021A9A4(R2Plr *a, s32 id) {
    R2Vec3 sp50;
    R2Vec3 sp60;
    R2Quat sp70;
    u16 st;
    R2Sub *s2;
    R2Hit *skill;
    R2Def *d;
    R2Ent **arr;
    R2Ent **pe;
    f32 fc;
    u8 *q;
    s32 j, found, v, k;
    s32 s;
    u16 *pp;
    s16 t16;
    s8 b;
    f32 val;
    void *tgt;
    s32 cnt;

    st = a->state;
    s2 = a->sub;
    if (st >= 2 && (s16)st != 0x10 && (s16)st != 0x11) {
        func_0024795C(&sp70, a);
        if (id == 0x439 || id == 0x4C4 || id == 0x432 || id == 0x4E3 ||
            id == 0x419 || id == 0x4D3 || id == 0x425 || id == 0x4CA) {
            a->mode = 2;
        }
        skill = func_0022AA8C(a, a->s62E);
        if (id == 0x439 || id == 0x4C4 || id == 0x432 || id == 0x4E3 ||
            id == 0x419 || id == 0x4D3 || id == 0x425 || id == 0x4CA) {
            a->mode = 1;
        }
        if (skill != NULL) {
            v = a->unk1450;
            d = D_800D052C[a->s62E];
            if (a->unk1450 == 0 && D_801450B8 == 1) {
                arr = d->alt;
            } else {
                arr = d->tab;
            }
            if (r2_has(arr, id)) goto L36;
        }
        if (a->s62E == 0 || a->s62E == 0x10) {
L36:
            if (s2 != NULL) {
                sp70 = a->q7D8;
            }
            if (a->s62E != 0 && a->s62E != 0x10) {
                pp = &a->tab5F4[skill->idx];
                *pp = *pp - skill->cost;
                if ((s16)*pp < 0) {
                    *pp = 0;
                }
                t16 = *pp;
                if (t16 == 0) {
                    q = (u8 *)a + a->s62E * 2;
                    b = ((s8 *)q)[0x603];
                    if (b == 3 || b == 7) {
                        q[0x602] = 0;
                        { s8 *r = (s8 *)a + a->s62E * 2; r[0x603] = -1; }
                    }
                }
            }
            if (a->unk5E0 == 0x11) {
                s32 v2 = a->unk86C;
                if (v2 == 0x1004) {
                    fc = a->f104;
                    val = D_800C7408[0];
                    goto apply;
                }
                if (v2 == 0xFA0) {
                    fc = a->f104;
                    val = D_800C7408[1];
                    goto apply;
                }
                if (a->b48C == 8) {
                    a->unk86C = 0x1004;
                } else {
                    a->unk86C = 0xFA0;
                }
            } else {
                v = a->unk86C;
                if (v == 1) {
                    a->unk86C = 0x1130;
                } else if (v == 0x1130) {
                    fc = a->f104;
                    val = D_800C7410[0];
                    goto apply;
                } else if (v == 0xA28) {
                    a->unk86C = 0x1135;
                } else if (v == 0x1135) {
                    fc = a->f104;
                    val = D_800C7410[1];
                    goto apply;
                } else if (v == 0x14) {
                    a->unk86C = 0x1144;
                } else if (v == 0x1144) {
                    fc = a->f104;
                    val = D_800C7418[0];
                    goto apply;
                } else if (a->s62E == 0 && a->b48C == 8) {
                    a->unk86C = 0x5E5E;
                } else {
                    v = a->unk86C;
                    if (v == 0x5E5E) {
                        fc = a->f104;
                    val = D_800C7418[1];
                        goto apply;
                    }
                    if ((u32)(v - 0x5E24) < 3) {
                        a->unk86C = 0x5E56;
                    } else if (v == 0x5E56) {
                        goto apply1;
                    } else if (v == 0x5E29) {
                        a->unk86C = 0x5E59;
                    } else if (v == 0x5E59) {
                        goto apply1;
                    } else if (v == 0x5E2A) {
                        a->unk86C = 0x5E5A;
                    } else if (v == 0x5E5A) {
                        fc = a->f104;
                    val = D_800C7420[0];
                        goto apply;
                    } else if (v == 0x5E2B) {
                        a->unk86C = 0x5E5B;
                    } else if (v == 0x5E5B) {
                        goto apply1;
                    } else if (v == 0x5E2C) {
                        a->unk86C = 0x5E5C;
                    } else {
                        k = 0x5E5C;
                        __asm__ volatile("" ::: "memory");
                        v = a->unk86C;
                        if (v == k) goto apply1;
                        if (v == 0x5E2D) {
                            a->unk86C = 0x5E5D;
                        } else if (v == 0x5E5D) {
apply1:
                            fc = a->f104;
                    val = D_800C7420[1];
apply:
                            if (val <= fc) {
                                a->f104 = fc - val;
                            }
                        }
                    }
                }
            }
            a->b10E = 0;
        }
        if (s2 != NULL && s2->unk24 != 1) {
            sp50 = s2->v128;
            tgt = 0;
        } else {
            func_0022B134(a, &sp50);
            tgt = 0;
        }
        sp60 = a->pos;
        if (a->unk788 == 2) {
            tgt = a->unk794;
        }
        func_00280094(D_80121990, a, a, 0, tgt, id, sp60, sp70, sp50, a->blk1458, -1,
                      (a->flags38 & 0x1000) ? 5 : 1);
        if (id == 0x414 || id == 0x42D) {
            cnt = a->unk59C - 1;
            if (cnt < 0) cnt = 0;
            a->unk59C = cnt;
        }
        if (a->s62E != 9 && a->s62E != 0x15 && a->s62E != 0x14) {
            D_80103140[a->unk5D4] = D_80103140[a->unk5D4] + 1;
        }
    }
}
