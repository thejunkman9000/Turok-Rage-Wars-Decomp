/* semantics right (viewport/scissor display list); ~75 words differ: instruction scheduling / register choice only */
#include "b21_types.h"

typedef struct B21Vp {
    s16 vscale[4];
    s16 vtrans[4];
} B21Vp;

typedef struct B21Hdr {
    u8 pad0[0x114];
    DlCmd *unk114;
} B21Hdr;

extern DlCmd *D_80110634;
extern B21Hdr *D_8011FE80;
extern u8 D_800D0F10[];
extern u8 D_800D0F40[];
extern s32 D_801536E8;
extern B21Vp D_80146D00[];
extern s32 D_800D297C;
extern s32 D_800E28D0;
extern s32 D_800E28D4;

void func_002917E8(void) {
    DlCmd *d;
    B21Vp *vp;
    D_80110634 = D_8011FE80->unk114;
    d = D_80110634++;
    d->w0 = 0xDB060000;
    d->w1 = 0;
    d = D_80110634++;
    d->w0 = 0xDE000000;
    d->w1 = (u32)D_800D0F10;
    d = D_80110634++;
    d->w0 = 0xDE000000;
    d->w1 = (u32)D_800D0F40;
    d = D_80110634++;
    d->w0 = 0xFE000000;
    d->w1 = D_801536E8;
    vp = &D_80146D00[D_800D297C];
    vp->vscale[1] = D_800E28D4 * 2;
    vp->vtrans[1] = D_800E28D4 * 2;
    vp->vscale[2] = 0x3FF;
    vp->vscale[3] = 0;
    vp->vtrans[2] = 0;
    vp->vtrans[3] = 0;
    vp->vscale[0] = D_800E28D0 * 2;
    vp->vtrans[0] = D_800E28D0 * 2;
    d = D_80110634++;
    d->w0 = 0xDC080008;
    d->w1 = (u32)vp;
    d = D_80110634++;
    d->w0 = 0xED000000;
    d->w1 = (((s32)((f32)(D_800E28D0 - 1) * 4.0f) & 0xFFF) << 12) | ((s32)((f32)(D_800E28D4 - 1) * 4.0f) & 0xFFF);
}
