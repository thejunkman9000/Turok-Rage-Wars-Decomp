#include "b10_types.h"

extern B10Te D_80121390[];
extern u8 D_800D1620[];
extern const f32 D_800C8860;
s32 func_0023DDB4(B10Sq *s, f32 *box, f32 *t);
s32 func_0023DA90(B10Sq *s, f32 *box, f32 *t);
B10Sn *func_0028FD94(s32 *n, s32 i);
void func_0026F3D8(B10Mt *m, Vec3f *a, Vec3f *b, u8 *c);
void func_00243804(void);
void func_00243840(void);
void func_00285290(B10Hit *base, s32 n, s32 size, void (*cmp)(void), void (*swap)(void));
s32 func_00216108(void *p);
void func_00243864(B10Qc *q);

void func_00242BE0(B10Sq *self) {
    f32 b6[6];
    f32 b4[4];
    B10Qc q;
    B10Hit hits[128];
    f32 tval;
    Vec3f *p44;
    Vec3f *p50;
    B10Hit *h;
    B10Te *e;
    B10Ie *ent;
    f32 *bp;
    B10Sn *node;
    s32 i;
    s32 j;
    s32 cnt;
    s32 n;
    s32 n2;
    s32 m;
    s32 t0;
    s32 lim = 2;
    p44 = &self->v44;
    q.p44 = p44;
    p50 = &self->v50;
    q.self = self;
    q.p50 = p50;
    q.f4C = self->f80 * self->f17C + self->f18;
    if (self->f8 != 0.0f) {
        m = 2;
        t0 = (s32)(self->f10 / self->f8) + 1;
        if (!(t0 < m)) {
            m = t0;
        }
        q.i50 = m;
        q.f54 = (self->f10 - 2.0f * self->f8) / (f32)(m - 1);
    } else {
        q.i50 = 1;
        q.f54 = D_800C8860;
    }
    h = hits;
    i = 0;
    cnt = *((s32 *)D_80121390 - 1);
    n = 0;
    if (cnt > 0) {
        e = D_80121390;
        do {
            b4[0] = e->p4->f0 - self->f18;
            b4[1] = e->p4->f4 - self->f18;
            b4[2] = e->p4->f8 + self->f18;
            b4[3] = e->p4->fC + self->f18;
            if (self->f9C < b4[2] && b4[0] < self->fA4 && self->fA0 < b4[3] && b4[1] < self->fA8 && func_0023DDB4(self, b4, &tval)) {
                node = func_0028FD94(*e->p0, 0);
                n2 = node->cnt - 1;
                ent = &node->ie;
                bp = &ent->b5;
                while (n2 != -1) {
                    if (n >= 0x80) {
                        break;
                    }
                    if (!(*(u16 *)(bp + 3) & 0x10)) {
                        b6[0] = bp[-5] - self->f18;
                        b6[1] = bp[-4] - self->f18;
                        b6[2] = bp[-3] - self->f18;
                        b6[3] = bp[-2] + self->f18;
                        b6[4] = bp[-1] + self->f18;
                        b6[5] = bp[0] + self->f18;
                        if (b6[0] < self->f90 && self->f84 < b6[3] && b6[2] < self->f98 && self->f8C < b6[5] && b6[1] < self->f94 && self->f88 < b6[4] && func_0023DA90(self, b6, &tval)) {
                            n++;
                            h->ptr = ent;
                            h->t = tval;
                            h++;
                        }
                    }
                    n2--;
                    ent++;
                    bp += 58;
                }
            }
            i++;
            e++;
        } while (i < cnt);
    }
    if (n != 0) {
        func_0026F3D8(&q.m, p44, p50, D_800D1620);
        func_00285290(hits, n, 8, func_00243840, func_00243804);
        h = hits;
        for (j = 0; j < n; j++, h++) {
            if (!(h->t < self->f17C)) {
                break;
            }
            q.p58 = h->ptr;
            q.k = func_00216108(h->ptr);
            if (q.k == 9) {
                q.flag = 1;
            } else {
                q.flag = 0;
            }
            func_00243864(&q);
        }
    }
}

