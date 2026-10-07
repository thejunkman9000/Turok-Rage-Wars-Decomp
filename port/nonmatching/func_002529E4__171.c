#include "b12_types.h"

extern DlCmd *D_80110634;
extern OSMesgQueue D_80105140;
extern s32 D_8010515C;
extern u32 D_80105180;
typedef struct B12Seg B12Seg;
struct B12Seg {
    /* 0x00 */ u32 addr;
    /* 0x04 */ u32 len;
    /* 0x08 */ u8 pad8[4];
    /* 0x0C */ B12Seg *next;
    /* 0x10 */ u32 hdr;
    /* 0x14 */ u32 size;
};
extern B12Seg *D_801051B0;
extern B12Mgr D_80103F70;
void func_00268CE0(s32 a);
void func_0026925C(s32 a);

void func_002529E4(s32 x0, s32 y0, s32 x1, s32 y1) {
    u32 mask;
    u32 m2;
    DlCmd *g;
    B12Seg *s;
    B12Node *p;
    u32 total;
    s32 h;
    s32 top;
    s32 bot;
    s32 pass;
    u32 r;
    u32 gc;
    u32 b;
    u32 c;
    u32 t;
    g = D_80110634++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_80110634++;
    g->w0 = 0xE3000A01;
    g->w1 = 0;
    func_00268CE0(0x19);
    func_0026925C(0x15);
    g = D_80110634++;
    g->w0 = 0xFA000000;
    g->w1 = 0xA0A0A000;
    g = D_80110634++;
    g->w0 = 0xF6000000 | (((y1 + 1) & 0x3FF) << 2) | (((x1 + 1) & 0x3FF) << 14);
    g->w1 = (((x0 - 1) & 0x3FF) << 14) | (((y0 - 1) & 0x3FF) << 2);
    func_0026925C(0x1B);
    g = D_80110634++;
    g->w0 = 0xFA000000;
    g->w1 = 0xA0A0A0FF;
    g = D_80110634++;
    g->w0 = 0xF6000000 | ((y1 & 0x3FF) << 2) | ((x1 & 0x3FF) << 14);
    g->w1 = ((x0 & 0x3FF) << 14) | ((y0 & 0x3FF) << 2);
    mask = __osDisableInt();
    if (++D_8010515C != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    s = D_801051B0;
    total = (u32)s - 0x80000000;
    for (; s; s = s->next) {
        total += s->hdr + s->size;
    }
    g = D_80110634;
    g->w0 = 0xFA000000;
    g->w1 = 0x646400FF;
    h = y1 - y0;
    top = y1 - (u32)(((u32)D_801051B0 - 0x80000000) * h) / total - 1;
    D_80110634 = g + 1;
    g = D_80110634++;
    g->w0 = 0xF6000000 | (((y1 + 1) & 0x3FF) << 2) | ((x1 & 0x3FF) << 14);
    g->w1 = ((x0 & 0x3FF) << 14) | ((top & 0x3FF) << 2);
    for (pass = 0; pass < 2; pass++) {
        for (p = (B12Node *)D_80103F70.lists[1].head; p; p = p->next) {
            if (pass ? (p->flags & 0x101) == 0x100 : (p->flags & 0x101) != 0x100) {
                r = 0xFF;
                if (p->flags & 1) {
                    gc = 0xFF;
                    b = 0;
                } else if (p->flags & 0x100) {
                    gc = 0;
                    b = 0;
                } else {
                    r = 0;
                    if (p->flags & 0x600) {
                        gc = 0;
                        b = 0xFF;
                    } else {
                        gc = 0xFF;
                        b = 0;
                    }
                }
                g = D_80110634++;
                g->w0 = 0xFA000000;
                g->w1 = (r << 24) | (gc << 16) | (b << 8) | 0xFF;
                top = y1 - (u32)(((p->key + p->unk4 - 0x80000000)) * h) / total - 1;
                bot = y1 - (u32)(((p->key - 0x80000000) - 0x20) * h) / total - 1;
                if (top < bot) {
                    g = D_80110634++;
                    g->w0 = 0xF6000000 | ((bot & 0x3FF) << 2) | ((x1 & 0x3FF) << 14);
                    g->w1 = ((x0 & 0x3FF) << 14) | ((top & 0x3FF) << 2);
                }
                g = D_80110634++;
                g->w0 = 0xFA000000;
                t = r >> 1;
                c = (t < 0x100) ? (t << 24) : 0xFF000000;
                t = gc >> 1;
                c |= (t < 0x100) ? (t << 16) : 0xFF0000;
                t = b >> 1;
                if (t < 0x100) {
                    c = c | (t << 8) | 0xFF;
                } else {
                    c = c | 0xFFFF;
                }
                g->w1 = c;
                g = D_80110634++;
                g->w0 = 0xF6000000 | ((bot & 0x3FF) << 2) | ((x1 & 0x3FF) << 14);
                g->w1 = ((x0 & 0x3FF) << 14) | (((bot - 1) & 0x3FF) << 2);
                if (!(p->flags & 0x702) && (D_80105180 - p->unk10) >= 5) {
                    b = 0xFF;
                    g = D_80110634++;
                    g->w0 = 0xFA000000;
                    g->w1 = 0xFFFFFFFF;
                    if (top < bot) {
                        g = D_80110634++;
                        g->w0 = 0xF6000000 | ((bot & 0x3FF) << 2) | ((x1 & 0x3FF) << 14);
                        g->w1 = (((x0 + 8) & 0x3FF) << 14) | ((top & 0x3FF) << 2);
                    }
                    g = D_80110634++;
                    g->w0 = 0xFA000000;
                    t = (b * 3) >> 1;
                    if (t < 0x100) {
                        c = ((t & 0xFF) << 8) | 0xFFFF00FF;
                    } else {
                        c = -1;
                    }
                    g->w1 = c;
                    g = D_80110634++;
                    g->w0 = 0xF6000000 | ((bot & 0x3FF) << 2) | ((x1 & 0x3FF) << 14);
                    g->w1 = (((x0 + 8) & 0x3FF) << 14) | (((bot - 1) & 0x3FF) << 2);
                }
            }
        }
    }
    m2 = __osDisableInt();
    if (--D_8010515C != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
