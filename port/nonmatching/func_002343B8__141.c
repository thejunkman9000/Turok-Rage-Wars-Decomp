#include "r03_types.h"

extern R3G D_8011FE88;
extern R3Pl *D_80145060;
extern u32 D_800D2980;
extern f32 D_800D2988;
void *func_0028FD94(s32 a, s32 b);
R3Item *func_0028B2D4(R3G *g, u16 *p);

static inline s32 busy(R3Pl *q, s32 r) {
    if ((q->unk664 & 0x40) || (q->unk38 & 0x1000)) {
        r = 1;
    }
    return r;
}

void func_002343B8(R3HudObj *o) {
    u8 sp[4];
    u16 *src;
    R3Item *it;
    R3Pl *pl;
    R3Pl *p;
    u32 a2;
    u32 a3;
    u32 t1;
    u32 t0;
    u32 u;
    u32 fl;
    u32 r;
    f32 f1;
    f32 f2;
    f32 tt;
    f32 k;
    f32 pv;
    f32 nv;
    f32 ka;
    f32 kb;
    f32 yv;
    u32 c8;
    s32 i;

    src = o->unk58;
    if (src == NULL) {
        if (&D_8011FE88 == NULL || D_8011FE88.unk0 == 0) {
            return;
        }
        it = (R3Item *)((u8 *)func_0028FD94(D_8011FE88.unk6C, 0) + 8);
    } else {
        it = func_0028B2D4(&D_8011FE88, src);
        if (it == NULL) {
            return;
        }
    }
    a2 = 0;
    t1 = 0;
    t0 = 0;
    a3 = 0;
    p = D_80145060;
    while (p != NULL) {
        if (p->unk5DC == o) {
            goto found;
        }
        p = p->next;
    }
    p = NULL;
found:
    if (p != NULL) {
        a2 = busy(p, 0);
        fl = p->unk38;
        a3 = fl & 0x20000;
        t1 = 0;
        if (fl & 0x8000) {
            t1 = a2 > 0;
        }
        t0 = 0;
        if (fl & 0x10000) {
            t0 = a2 > 0;
        }
    }
    if (src != NULL && (*src != o->unk518 || a2 != 0 || a3 != 0)) {
        if (o->unk518 == -1 || a2 != 0 || a3 != 0) {
            o->unk51C = 1.0f;
        } else {
            o->unk51C = 0.0f;
        }
        o->unk518 = *src;
        for (i = 0; i < 4; i++) {
            o->prev[i] = o->col[i];
        }
        o->unk52C = o->unk528;
        o->unk540 = o->unk53C;
        o->unk534 = o->unk530;
    }
    i = 0;
    if (a2 != 0 || a3 != 0 || t1 != 0 || t0 != 0) {
        do {
            sp[i] = it->b[i];
            i++;
        } while (i < 4);
        u = it->uCx;
        f1 = it->f18;
        f2 = it->f1C;
    } else {
        do {
            sp[i] = it->a[i];
            i++;
        } while (i < 3);
        sp[3] = 0;
        u = it->u8x;
        f1 = it->f10;
        f2 = it->f14;
    }
    if (D_800D2980 == 0 || it->f24 == 0.0f) {
        o->unk51C = 1.0f;
    } else {
        tt = o->unk51C + D_800D2988 / (it->f24 * 15.0f);
        if (1.0f < tt) {
            tt = 1.0f;
        }
        o->unk51C = tt;
    }
    tt = o->unk51C;
    k = tt * (tt * -2.0f) * tt + tt * (tt * 3.0f);
    for (i = 0; i < 4; i++) {
        pv = (f32)o->prev[i];
        nv = pv + k * ((f32)sp[i] - pv);
        if (nv > 255.0f) {
            c8 = 255;
        } else if (nv < 0.0f) {
            c8 = 0;
        } else if (nv > 255.0f) {
            c8 = 255;
        } else {
            c8 = (u32)nv;
        }
        o->col[i] = c8;
    }
    if (!(995.0f < (f32)o->unk540 + k * ((f32)u - (f32)o->unk540))) {
        if ((f32)o->unk540 + k * ((f32)u - (f32)o->unk540) < 0.0f) {
            r = 0;
            goto done;
        }
    }
    if (995.0f < (f32)o->unk540 + k * ((f32)u - (f32)o->unk540)) {
        r = 995;
        goto done;
    }
    r = (u32)((f32)o->unk540 + k * ((f32)u - (f32)o->unk540));
done:
    o->unk53C = r;
    if (o->unk5C > 0.0f) {
        f2 = f2 + o->unk5C * 1024.0f;
    }
    o->unk528 = o->unk52C + k * (f1 - o->unk52C);
    o->unk530 = o->unk534 + k * (f2 - o->unk534);
}
