#include "s1005_types.h"

extern char D_800C83C0[];
extern char D_800C83CC[];

extern void func_0044ADC0(void *part);
extern void func_00255C40(S5List *l, s32 prevOff, s32 nextOff);
extern void func_00255CB4(S5List *l, void *node);
extern void func_0025E410(void *p);
extern void func_002538A8(s32 a);
extern void func_002537D8(s32 a, void *h);
extern void **func_002533DC(s32 a, s32 size, s32 tag, void *name);
extern void *memset(void *p, int c, u32 n);

void func_0044AFC0(S5Cams *m, s32 n) {
    s32 i;
    s32 size;

    if (n >= 5) {
        n = 4;
    }
    m->f34 = 0;
    m->f38 = 0;
    m->part48 = 0;
    func_0044ADC0(m->part);
    m->f38 = 2;
    func_00255C40(&m->recList, 0, 4);
    func_00255C40(&m->list11EC, 0, 4);
    for (i = 0; i < 8; i++) {
        S5Rec *r;
        S5Sub *sa;
        S5Sub *sb;
        S5Sub *sc;

        r = (S5Rec *)(i * 0x54 + (s32)m);
        r = (S5Rec *)((u8 *)r + 0xF38);
        r->w8 = 0;
        r->wC = 0;
        r->w10 = 0;
        r->scale = 1.0f;
        sa = &r->a;
        sa->w4 = 0;
        sa->w8 = 0;
        sa->wC = 0;
        sa->w10 = 0;
        sb = &r->b;
        sb->w4 = 0;
        sb->w8 = 0;
        sb->wC = 0;
        sb->w10 = 0;
        sc = &r->c;
        sc->w4 = 0;
        sc->w8 = 0;
        sc->wC = 0;
        sc->w10 = 0;
        func_00255CB4(&m->recList, &m->rec[i]);
    }
    func_00255C40(&m->camList, 0, 4);
    func_00255C40(&m->list20, 0, 4);
    func_00255C40(&m->txtList, 0, 4);
    m->f1200 = 1;
    func_0025E410(m->part);
    func_002538A8(0);
    if (m->h != 0) {
        func_002537D8(0, m->h);
        m->h = 0;
        m->data = 0;
        m->cnt = 0;
    }
    func_002538A8(0);
    if (m->h2 != 0) {
        func_002537D8(0, m->h2);
        m->h2 = 0;
        m->data2 = 0;
        m->cnt2 = 0;
    }
    if (n != 0) {
        size = n * 0xED8;
        m->cnt = n;
        m->h = func_002533DC(0, size, 0x23, D_800C83C0 + 4);
        m->data = *m->h;
        memset(m->data, 0, size);
        for (i = 0; i < m->cnt; i++) {
            m->data[i].id = i;
            func_00255CB4(&m->camList, &m->data[i]);
        }
        func_0025E410(m->data);
        m->f1200 = 0;
    }
    m->cnt2 = 0x10;
    m->h2 = func_002533DC(0, 0x400, 0x23, D_800C83CC);
    m->data2 = *m->h2;
    memset(m->data2, 0, 0x400);
    for (i = 0; i < m->cnt2; i++) {
        func_00255CB4(&m->txtList, m->data2 + i * 0x40);
    }
}
