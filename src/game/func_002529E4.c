#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "s904_types.h"

extern Gfx *D_80110634;
extern char D_80105140;
extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);
extern s32 osRecvMesg(void *, void *, s32);
extern s32 osSendMesg(void *, void *, s32);
extern s32 D_8010515C;
extern u32 D_80105180[];
extern S904Seg *D_801051B0[];
extern S904Node *D_80104584[];
void func_00268CE0(s32 a);
void func_0026925C(s32 a);

/* gDPFillRectangle with the left edge x written as ((x << 22) >> 22): the shift pair is the same value as (x & 0x3FF) after combine, but at loop.c time it is TWO
 * movables, which uses up the "already moved" budget so that the shifted x0 stays in the pass loop (see FINDINGS s904 no. 12). */
#define RECTA(pkt, ulx, uly, lrx, lry) { Gfx *_gbi = (Gfx *)(pkt); _gbi->words.w0 = _SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL(lrx, 14, 10) | _SHIFTL(lry, 2, 10); _gbi->words.w1 = ((((unsigned int)(ulx) << 22) >> 22) << 14) | _SHIFTL(uly, 2, 10); }
/* gDPSetPrimColor with the colour word given as one expression */
#define PRIMC(pkt, wd) { Gfx *_gbi = (Gfx *)(pkt); _gbi->words.w0 = _SHIFTL(G_SETPRIMCOLOR, 24, 8); _gbi->words.w1 = (wd); }
/* halved colour component, clamped to 0xFF */
#define HALF(c) ((((s32) ((c) >> 1)) < 0x100) ? ((s32) ((c) >> 1)) : 0xFF)

/* Debug memory map: takes the pool lock, then draws into the display list at D_80110634 a framed panel (x0,y0)-(x1,y1) in which the heap segment list D_801051B0 is
 * measured (total bytes) and every node of the pool list D_80104584 is drawn as a vertical bar (two passes: nodes with (flags & 0x101) == 0x100 last), coloured by its flags
 * (red = bit 0, dark = bit 8, blue = bits 9/10, else green) with a half-bright edge line, and nodes whose stamp is 5 or more behind D_80105180[0] get a white overlay. */
void func_002529E4(s32 unused, s32 x0, s32 y0, s32 x1, s32 y1)
{
    u32 mask;
    u32 m2;
    S904Seg *s;
    S904Node *p;
    u32 total;
    s32 h;
    s32 top;
    s32 bot;
    s32 pass;
    u32 r;
    u32 gc;
    u32 b;
    u32 base;
    register s32 hb asm("$9"); /* highlight blue: pinned to $t1 (ROM register; also keeps t0/t1 apart from the pre-loop mflo temp) */
    u32 hi;
    s32 ok;

    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    func_00268CE0(0x19);
    func_0026925C(0x15);
    gDPSetPrimColor(D_80110634++, 0, 0, 0xA0, 0xA0, 0xA0, 0x00);
    gDPFillRectangle(D_80110634++, x0 - 1, y0 - 1, x1 + 1, y1 + 1);
    func_0026925C(0x1B);
    gDPSetPrimColor(D_80110634++, 0, 0, 0xA0, 0xA0, 0xA0, 0xFF);
    gDPFillRectangle(D_80110634++, x0, y0, x1, y1);
    mask = __osDisableInt();
    if ((++D_8010515C) != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
    base = 0x80000000;
    s = D_801051B0[0];
    total = ((u32) s) - base;
    for (; s; s = s->next) {
        total += s->hdr + s->size;
    }
    gDPSetPrimColor(D_80110634++, 0, 0, 0x64, 0x64, 0x00, 0xFF);
    top = (y1 - (((u32) ((((u32) D_801051B0[0]) - base) * (y1 - y0))) / total)) - 1;
    h = y1 - y0;
    RECTA(D_80110634++, x0, top, x1, y1 + 1);
    for (pass = 0; pass < 2; pass++) {
        for (p = D_80104584[0]; p; p = p->next) {
            ok = (pass) ? (((p->flags & 0x101) ^ 0x100) == 0) : (((p->flags & 0x101) ^ 0x100) != 0);
            if (ok) {
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
                /* empty asm: three extra references of r and one of b raise their register-allocation priority (r -> $t0, b -> $t1, g -> $t2 as in the ROM) */
                __asm__("" : : "r"(r), "r"(r), "r"(r), "r"(b));
                gDPSetPrimColor(D_80110634++, 0, 0, r, gc, b, 0xFF);
                top = (y1 - (((u32) (((p->key + p->size) - base) * h)) / total)) - 1;
                bot = (y1 - (((u32) (((p->key - base) - 0x20) * h)) / total)) - 1;
                if (top < bot) {
                    RECTA(D_80110634++, x0, top, x1, bot);
                }
                gDPSetPrimColor(D_80110634++, 0, 0, HALF(r), HALF(gc), HALF(b), 0xFF);
                RECTA(D_80110634++, x0, bot - 1, x1, bot);
                if ((!(p->flags & 0x702)) && ((D_80105180[0] - p->stamp) >= 5)) {
                    hb = 0xFF;
                    gDPSetPrimColor(D_80110634++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
                    if (top < bot) {
                        gDPFillRectangle(D_80110634++, x0 + 8, top, x1, bot);
                    }
                    {
                        /* opaque to cse (which would fold hb * 3 >> 1 across the skip block); the edge colour is white */
                        __asm__("" : "+r"(hb));
                        hi = 0xFFFF0000;
                        PRIMC(D_80110634++, ({ s32 tt = (hb * 3) >> 1; (tt < 0x100) ? ((hi | ((tt & 0xFF) << 8)) | 0xFF) : 0xFFFFFFFF; }));
                    }
                    do { } while (0); /* sched barrier: keeps the colour store before the next macro's gfx pointer load */
                    gDPFillRectangle(D_80110634++, x0 + 8, bot - 1, x1, bot);
                }
            }
        }
    }
    m2 = __osDisableInt();
    if ((--D_8010515C) != 0) {
        __osRestoreInt(m2);
        osSendMesg(&D_80105140, 0, 1);
    } else {
        __osRestoreInt(m2);
    }
}
