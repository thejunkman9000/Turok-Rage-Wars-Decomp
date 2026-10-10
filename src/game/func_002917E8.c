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

void func_002917E8(void)
{
  f32 new_var;
  s32 new_var2;
  s32 new_var3;
  DlCmd *d1;
  DlCmd *d2;
  DlCmd *d3;
  DlCmd *d4;
  DlCmd *d5;
  DlCmd *d6;
  B21Vp *vp;
  D_80110634 = D_8011FE80->unk114;
  d1 = D_80110634++;
  d1->w0 = 0xDB060000;
  d1->w1 = 0;
  d2 = D_80110634++;
  d2->w0 = 0xDE000000;
  d2->w1 = (u32) D_800D0F10;
  d3 = D_80110634++;
  d3->w0 = 0xDE000000;
  d3->w1 = (u32) D_800D0F40;
  d4 = D_80110634++;
  d4->w0 = 0xFE000000;
  vp = &D_80146D00[D_800D297C];
  d4->w1 = D_801536E8;
  vp->vscale[1] = D_800E28D4 * 2;
  vp->vscale[0] = D_800E28D0 * 2;
  vp->vscale[2] = 0x3FF;
  vp->vtrans[1] = D_800E28D4 * 2;
  vp->vscale[2] = 0x3FF;
  vp->vscale[3] = 0;
  vp->vtrans[0] = D_800E28D0 * 2;
  vp->vtrans[2] = 0;
  vp->vtrans[3] = 0;
  new_var = (f32) (D_800E28D0 - 1);
  d5 = D_80110634++;
  d5->w0 = 0xDC080008;
  d5->w1 = (u32) vp;
  d6 = D_80110634++;
  d6->w0 = 0xED000000;
  d6->w1 = ((((s32) (new_var * 4.0f)) & 0xFFF) << 12) | (((s32) (((f32) (D_800E28D4 - 1)) * 4.0f)) & 0xFFF);
}
