/* func_00235AD0 (ROM 0x366D0) = per-view setup: reset scale, viewport + scissor + lookat display-list pushes, fog + fill-colour screen clear.
 * upstream name func_80235AE0_de(Racer *); S9View is the (partial) view/racer object, see include/s905_types.h.
 * Compile: @SN only (pmret gcc 2.8.1 cc1 -O2 -mcpu=VR4300 -mfp64 + asn64); chk EXACT incl. pool (ro=0xC8FA8:12 = 1.0f, 0.25f, 4.0f).
 * Source tricks that emit no code (details in wip/out/FINDINGS.txt):
 *  - yf is pinned to $f2: a hard-register set is never a sched1 "birthing" insn, so the load floats to the top of the block like the ROM's
 *    (without it the read-back of o->unkC cannot become `mov.s f0,f1`);
 *  - o->unkC / o->unk10 are READ BACK after the stores o->unkC = o->unk110 / o->unk10 = o->unk114 (cse invalidation makes a second load that
 *    reload_cse turns into mov.s / deletes);
 *  - c0/c1/c2 must be NON-struct fixed stack scalars (an array would be in-struct and conflict with the Gfx stores): one volatile store each
 *    makes them stack resident without any other code change (a volatile store cannot go in a delay slot, hence c2 is volatile in the col arm);
 *  - D_8011FE80 / D_801462C8 are declared as arrays so their loads are in-struct MEMs ordered against the Gfx stores like the ROM's. */
#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "s905_types.h"

extern Gfx *D_80110634;
extern s32 D_800D297C;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern char D_800D0F10;
extern char D_800D0F40;
extern u8 D_8011FAC0[];
extern S9View D_801450C8;
extern u32 D_801462C8[];
extern struct { u8 pad[0x110]; u32 unk110; } *D_8011FE80[];
void func_0026E330(s32 a);
void func_00297008(s32 a);
void func_0026D88C(void);
void func_00296FF8(void);
void func_0026925C(s32 a);
s32 func_002A33AC(void);
s32 func_0029A958(void);
s32 func_00245788(void);
u32 func_00245AE8(void);
void func_00291BF8(void *a, s16 b, s16 c, s16 d, s32 e, s32 f);
void func_0026D914(s32 a);
void func_00265A00(void *a);

#define gSPLookAtX(pkt, la) gSPMoveMem(pkt, G_MV_LIGHT, 0, 16, la)
#define gSPLookAtY(pkt, la) gSPMoveMem(pkt, G_MV_LIGHT, 0x18, 16, la)
#define gSPLookAt(pkt, la) { gSPLookAtX(pkt, la); gSPLookAtY(pkt, (char *)(la) + 16); }
#define GPACK_RGBA5551(r, g, b, a) ((((r) << 8) & 0xF800) | (((g) << 3) & 0x7C0) | (((b) >> 2) & 0x3E) | ((a) & 0x1))
#define gSPFogPosition(pkt, min, max) gSPMoveWord(pkt, G_MW_FOG, 0, (_SHIFTL((128000 / ((max) - (min))), 16, 16) | _SHIFTL(((500 - (min)) * 256 / ((max) - (min))), 0, 16)))

void func_00235AD0(S9View *o) {
    s16 y0, x0, x1, y1;
    s16 vs0, vs1, wm1, hm1;
    s32 idx;
    f32 xf;
    f32 wf;
    register f32 yf __asm__("$f2");
    s32 s0;
    u8 c0, c1, c2;
    u32 w;
    struct { u8 pad[0x110]; u32 unk110; } *fe;
    gDPPipeSync(D_80110634++);
    gSPDisplayList(D_80110634++, &D_800D0F10);
    gSPDisplayList(D_80110634++, &D_800D0F40);
    o->unkC = 1.0f;
    o->unk10 = 1.0f;
    o->unkC = o->unk110;
    o->unk10 = o->unk114;
    wf = o->width;
    yf = o->y;
    xf = o->x;
    vs0 = (s32)(2.0f * wf * o->unkC);
    x0 = (s32)xf;
    y0 = (s32)yf;
    x1 = (s32)(xf + wf);
    y1 = (s32)(yf + o->height);
    wm1 = D_800E28D0 - 1;
    hm1 = D_800E28D4 - 1;
    vs1 = (s32)(2.0f * o->height * o->unk10);
    if (D_800E28D0 - 1 < x1) x1 = wm1;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (y1 > D_800E28D4 - 1) y1 = hm1;
    fe = D_8011FE80[0];
    idx = D_800D297C;
    gSPMatrix(D_80110634++, (u8 *)o + (idx * 64 + 0x380), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMoveWord(D_80110634++, G_MW_PERSPNORM, 0, o->unk68);
    o->vp[idx].vscale[0] = vs0;
    o->vp[idx].vscale[1] = vs1;
    o->vp[idx].vtrans[0] = (s32)((vs0 * 0.25f + o->x) * 4.0f);
    o->vp[idx].vtrans[1] = (s32)((vs1 * 0.25f + o->y) * 4.0f);
    gSPMoveMem(D_80110634++, G_MV_VIEWPORT, 0, 16, (u8 *)o + (idx * 16 + 0x2B0));
    gDPSetScissor(D_80110634++, G_SC_NON_INTERLACE, x0, y0, x1, y1);
    gSPLookAt(D_80110634++, (u8 *)o + (idx * 32 + 0x400));
    func_0026E330(o->unk120);
    if (o != &D_801450C8) func_00297008(o->unk120);
    func_0026D88C();
    func_00296FF8();
    gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
    s0 = 0;
    if (func_002A33AC() != 0) s0 = func_0029A958() != 2;
    if (o != &D_801450C8 || ((s32 *)o)[-4] == 0 || s0 != 0) {
        func_0026925C(0x14);
        gDPPipeSync(D_80110634++);
        func_00291BF8(D_8011FAC0, x0, x1, y0, y1, o->unk120);
        gDPSetCycleType(D_80110634++, G_CYC_FILL);
        if (D_801462C8[0] & 0x4000) {
            *(volatile u8 *)&c0 = 0;
            *(volatile u8 *)&c1 = 0;
            c2 = 0;
        } else {
            c0 = o->col[0] & 0xF8;
            c1 = o->col[1] & 0xF8;
            *(volatile u8 *)&c2 = o->col[2] & 0xF8;
        }
        if (func_00245788() != 0) {
            w = func_00245AE8();
            if (w != 0xFF00) {
                c2 = w >> 16;
                c1 = w >> 8;
                c0 = w;
            }
        }
        gSPGeometryMode(D_80110634++, 0, 0x10000);
        if (o->unk120 != 0) {
            gDPSetFogColor(D_80110634++, 0, 0, 0, 0xFF);
            gSPFogPosition(D_80110634++, 995, 1000);
        } else {
            gDPSetFogColor(D_80110634++, c0, c1, c2, 0xFF);
            gSPFogPosition(D_80110634++, o->unk53E, 1000);
        }
        gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, fe->unk110);
        if (o->unk120 != 0) {
            gDPSetFillColor(D_80110634++, 0x10001);
        } else {
            gDPSetFillColor(D_80110634++, (GPACK_RGBA5551(c0, c1, c2, 1) << 16) | GPACK_RGBA5551(c0, c1, c2, 1));
        }
        if (o != &D_801450C8 || o->unk17B0 == 3) {
            gDPFillRectangle(D_80110634++, x0, y0, x1, y1);
        }
    }
    gDPPipeSync(D_80110634++);
    func_0026D914(0);
    gDPSetAlphaDither(D_80110634++, G_AD_NOTPATTERN);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    if (o != &D_801450C8) {
        func_00265A00(o);
    }
    gDPPipeSync(D_80110634++);
}
