#include "s703_types.h"

extern f32 D_800C94D0;
extern f32 D_800C94D4;
extern f32 D_800C94D8;
extern f32 D_800C94DC;
extern f32 D_800C94E0;
extern f32 D_800C94E4;
extern f32 D_800C94E8;
extern f32 D_800C94EC;
extern f32 D_800C94F0;
extern f32 D_800C94F4;
extern f32 D_800C94F8;
extern f32 D_800C94FC;
extern f32 D_800C9500;
extern f32 D_800C9504;
extern f32 D_800C9508;
extern f32 D_800C950C;
extern S7Ent *D_801041F0;
extern s32 D_80104204;
extern u8 D_80104208[];
extern u8 D_80110570[];
extern u8 D_801462E5;

typedef struct S7Src {
    u8 pad0[0x68];
    f32 f68;
} S7Src;

extern f32 sqrtf(f32);
extern void func_00216488(S7Vec3 *out, S7Ent *t, s32 dmg, f32 mult, s32 flags, void *src);
extern void func_002171FC(S7Ent *e, void *p170, S7Vec3 *v);
extern s32 func_0022ABF0(S7Ent *e);
extern s32 func_0024B05C(S7Ent *e, S7Vec3 v, void *buf);
extern f32 func_0024BECC(S7Ent *e);
extern f32 func_0024D274(S7Ent *e);
extern f32 func_0024D388(S7Ent *e);
extern s32 func_002661FC(S7Ent *a, S7Ent *t);
extern void func_0026643C(S7Ent *a, S7Ent *t, s32 flag, S7Vec3 pos, S7Vec3 dir, s32 arg9, void *src, s32 arg10);
extern f32 func_002672E8(S7Ent *e);
extern void func_00271FD8(S7Vec3 *out, void *a, void *b);
extern void func_0027200C(S7Vec3 *out, S7Vec3 *v, f32 s);
extern void func_00272038(S7Vec3 *out, f32 t, S7Vec3 *a, S7Vec3 *b);
extern void func_002720EC(S7Vec3 *v);
extern f32 func_00272768(S7Vec3 *a, S7Vec3 *b);
extern s32 func_00282C60(S7Ent *e);
extern s32 func_00282D0C(S7Ent *e);
extern s32 func_00282DC0(S7Ent *e);


static inline void padslots(void)
{
    u8 pad[0x50];
    __asm__("" : "=m"(pad));
}

static inline void knock(S7Vec3 *out, S7Ent *a, S7Ent *t, f32 r, S7Blk *bk)
{
    S7Vec3 d;
    f32 f0;
    func_00271FD8(&d, &a->pos, &t->pos);
    f0 = sqrtf(((d.x * d.x) + (d.y * d.y)) + (d.z * d.z));
    func_002720EC(&d);
    if (!(r <= f0))
    {
        func_0027200C(out, &d, ((f32) bk->c) * (((r - f0) / r) * D_800C94EC));
        padslots();
    }
}


static inline f32 calcMult(S7Ent *a, S7Ent *t, S7Vec3 *p, S7Vec3 *c, f32 m, f32 k, s32 arg10, s32 en8, void **psrc, s32 spec)
{
    register S7Ent *bp asm("$17");
    register s32 armor asm("$21");
    void *sv;
    s32 ok;
    f32 lo;
    f32 lim;
    f32 lim2;
    f32 dist;

    armor = 1;
    bp = (S7Ent *) spec;
    ok = 1;
    if (a->flags & 0x300000)
    {
        bp = a->pl;
    }
    if ((D_801462E5 != 0) && (arg10 & 0x200))
    {
        armor = 0;
    }
    if (t->type == 2)
    {
        if ((t->kind == 0x404) || (t->kind == 0x402))
        {
            spec = 1;
        }
        if ((t->type == 2) && (D_801041F0 == a) && (D_80104204 != -1) && (spec == 0))
        {
            sv = D_80104208;
            en8 = 0;
        }
        else
        {
            goto lookup;
        }
    }
    else
    {
lookup:
        if (func_0024B05C(a, *p, D_80110570) != 0)
        {
            sv = D_80110570;
        }
        else
        {
            sv = 0;
        }
    }
    *psrc = sv;
    if ((armor != 0) && (sv != 0))
    {
        m *= ((S7Src *) sv)->f68;
    }
    if (en8 == 0)
    {
        return m;
    }
    if ((bp != 0) && (bp->flags2 & 2) && (m == D_800C94E0) && (arg10 & 0x200))
    {
        m = 0.0f;
        __asm__("" : : "f"(m));
        return m;
    }
    *c = a->pos;
    lo = a->pos.y + a->h70;
    lim = lo + func_0024D274(a);
    if (lim < p->y)
    {
        c->y = lim;
    }
    else if (p->y < lo)
    {
        c->y = lo;
    }
    else
    {
        c->y = p->y;
    }
    lim2 = k + func_0024D388(a);
    dist = func_00272768(p, c);
    if (lim2 < dist)
    {
        return 0.0f;
    }
    if (ok)
    {
        m = m * (D_800C94E4 - (dist / lim2));
    }
    return m;
}


void func_auto_00266810(S7Ent *a, S7Ent *t, s32 adj, S7Vec3 pos, S7Blk blk, s32 arg8, s32 arg9, s32 arg10)
{
    register S7Ent *ap asm("$18");
    register S7Ent *tp asm("$16");
    register S7Ent *bp asm("$17");
    S7Ent *op;
    register S7Ent *bq asm("$6");
    S7Ent *tc;
    register S7Vec3 *vp asm("$16");
    S7Vec3 v30;
    S7Vec3 v40;
    u8 d50[8];
    union { S7Vec3 v; struct { u8 p[8]; S7Blk b; } x; } u58;
    union { S7Vec3 v; struct { u8 p[8]; S7Vec3 v; } x; u8 sz[24]; } u68;
    S7Vec3 v80;
    u8 d90[32];
#define v58 u58.v
#define b2 u58.x.b
#define v68 u68.v
#define v70 u68.x.v
    void *src;
    void **psrc;
    void *sv;
    s32 adj2;
    register s32 adjp asm("$6");
    register s32 spec asm("$4");
    s32 hasSrc;
    f32 k0;
    f32 k1;
    f32 mulA;
    f32 mulC;
    f32 dmg;
    f32 fm;
    f32 f0;
    f32 f1;
    f32 dist;
    f32 lim;
    f32 r;
    s32 h;
    s32 h2;
    s32 en8;
    s32 ok;

    ap = 0;
    if (a->flags & 0x300000)
    {
        ap = a->pl;
    }
    if (func_002661FC(a, t) == 0)
    {
        return;
    }
    adjp = 0;
    if ((t->type == 1) && (t->flags & 0x300000))
    {
        tp = t->pl;
        if ((t == (S7Ent *) (((u8 *) tp) + 0x2E8)) && ((tp->state == 0) || (tp->state == 0x11) || (tp->state == 0x10)))
        {
            v58 = pos;
            v68 = tp->pos;
            func_00272038(&pos, 0.75f, &v58, &v68);
            pos.y += func_0024D274(tp) * D_800C94D0;
            adjp = 1;
        }
    }
    k1 = ((f32) blk.a) * D_800C94D4;
    adj2 = adjp;
    if (t->type == 1)
    {
        mulA = func_0024BECC(t);
        spec = 0;
    }
    else
    {
        mulA = D_800C94D8;
        spec = 0;
    }
    k1 = k1 * mulA;
    dmg = (f32) blk.b;
    v80 = pos;
    dmg = dmg * calcMult(a, t, &v80, &v58, D_800C94DC, k1, arg10, arg8, &src, spec);
    if (!(dmg <= 0.0f))
    {
        b2 = blk;
        r = ((f32) b2.a) * D_800C94E8;
        mulC = func_002672E8(t);
        vp = &v30;
        vp->z = 0.0f;
        vp->y = 0.0f;
        v30.x = 0.0f;
        r = r * mulC;
        if (a->hp174 != 0 && t->type == 2)
        {
            knock(vp, a, t, r, &b2);
        }
        vp = &v40;
        func_00216488(vp, t, (s32) dmg, k1, arg10, src);
        if (t->type == 2)
        {
            op = t->owner;
            tc = t;
            if ((op != 0) && (op->type == 1))
            {
                if (op->flags & 0x300000)
                {
                    tp = op->pl;
                    if (ap != 0)
                    {
                        if (tp->flags2 & 0x40)
                        {
                            h = tp->hp + (s32) (dmg * D_800C94F0);
                            h2 = func_0022ABF0(tp);
                            if (h < h2)
                            {
                                h2 = h;
                            }
                            tp->hp = h2;
                            tp->hp174 = h2;
                            tp->hp45C = tp->hp;
                            __asm__("" : "+r"(ap));
                            if (ap != 0)
                            {
                                goto l61;
                            }
                        }
                        else
                        {
l61:
                            if (ap->flags2 & 0x10)
                            {
                                func_00216488(&v70, t, (s32) (2.0f * dmg), k1, arg10, src);
                                if ((dmg * D_800C94F4) > 0.0f)
                                {
                                    func_002171FC(tp, ((u8 *) tp) + 0x170, &v70);
                                }
                            }
                            if ((ap != 0) && (ap->flags2 & 0x1000) && (func_00282C60(tc) != 0))
                            {
                                h = ap->hp + (s32) dmg;
                                h2 = func_0022ABF0(tp);
                                if (h < h2)
                                {
                                    h2 = h;
                                }
                                dmg = 0.0f;
                                ap->hp = h2;
                                ap->hp174 = h2;
                                ap->hp45C = ap->hp;
                            }
                        }
                    }
                    if ((dmg > 0.0f) && (ap != 0) && (tp->flags2 & 8) && (tp != ap))
                    {
                        ap->flags2 = ap->flags2 | 0x4000;
                        ap->f11D8 = D_800C94F8;
                    }
                    if (tp->flags2 & 0x200)
                    {
                        dmg *= D_800C94FC;
                        func_00216488(&v40, t, (s32) dmg, k1, arg10, src);
                    }
                }
                else if (t->kind == 0x427)
                {
                    bq = 0;
                    if (op->unkE4 == 0x40C)
                    {
                        bq = op->pl;
                    }
                    if ((bq != 0) && (bq->flags2 & 0x200))
                    {
                        dmg *= D_800C94FC;
                        func_00216488(vp, t, (s32) dmg, k1, arg10, src);
                    }
                }
                if (ap != 0)
                {
                    if ((ap->flags2 & 0x800) && ((func_00282D0C(tc) != 0) || (func_00282DC0(tc) != 0)))
                    {
                        dmg = 0.0f;
                    }
                    if ((ap != 0) && (ap->flags2 & 0x400))
                    {
                        dmg = 0.0f;
                    }
                }
            }
        }
        else if (t->type == 1)
        {
            if (t->flags & 0x300000)
            {
                tp = t->pl;
                if (ap != 0)
                {
                    if (tp->flags2 & 0x40)
                    {
                        h = tp->hp + (s32) (dmg * D_800C9500);
                        h2 = func_0022ABF0(tp);
                        if (h < h2)
                        {
                            h2 = h;
                        }
                        tp->hp = h2;
                        tp->hp174 = h2;
                        tp->hp45C = tp->hp;
                        __asm__("" : "+r"(ap));
                        if (ap != 0)
                        {
                            goto l98;
                        }
                    }
                    else
                    {
l98:
                        if (ap->flags2 & 0x10)
                        {
                            f0 = dmg * D_800C9504;
                            func_00216488(&v70, t, (s32) f0, k1, arg10, src);
                            if (f0 > 0.0f)
                            {
                                func_002171FC(tp, ((u8 *) tp) + 0x170, &v70);
                            }
                        }
                    }
                }
                if ((dmg > 0.0f) && (ap != 0) && (ap != tp) && (tp->flags2 & 8))
                {
                    ap->flags2 = ap->flags2 | 0x4000;
                    ap->f11D8 = D_800C9508;
                }
                if (tp->flags2 & 0x200)
                {
                    dmg *= D_800C950C;
                    func_00216488(&v40, t, (s32) dmg, k1, arg10, src);
                }
            }
            if ((ap != 0) && (ap->flags2 & 0x400))
            {
                dmg = 0.0f;
            }
            if ((dmg > 0.0f) && (ap != 0))
            {
                ap->w1218 = (ap->w1218 == 0);
            }
        }
        if (dmg != 0.0f)
        {
            func_002171FC(a, ((u8 *) a) + 0x170, &v40);
            func_0026643C(a, t, adj2, pos, v30, arg9, src, arg10);
        }
    }
}
