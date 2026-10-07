#include "b16_types.h"

typedef struct B16Gfx {
    u8 pad0[0x114];
    DlCmd *base;
} B16Gfx;

typedef struct B16Env {
    u32 flags;
    u8 pad4[0xC];
    u8 b[8];
} B16Env;

extern B16Env D_8013B2D8[];
extern s32 D_800D15E0;
extern B16Gfx *D_8011FE80;
extern DlCmd *D_80110634;
extern u32 D_800E28A4;

s32 *func_0028FD94(s32 *node, s32 idx);
void func_00253B5C(s32 a, s32 **p);
void func_0026B504(s32 a, s32 b, s32 *c);
s32 func_00269A80(void *a, s32 b);
void func_00268CE0(s32 a);

void func_0026D4F0(s32 **p, s32 unused, s32 seg, s32 flag, s32 arg4, s32 *node, s32 n, u8 r, u8 g, u8 b, u8 a) {
    s32 *root;
    s32 *nn;
    s32 *c;
    s32 *e;
    s32 i;
    s32 count;
    s32 *nd;

    D_800D15E0 = 3;
    D_8013B2D8->b[4] = 0;
    D_8013B2D8->b[5] = 0;
    D_8013B2D8->b[6] = 0;
    D_8013B2D8->flags |= 0x1402;
    ((f32 *)&D_800D15E0)[1] = r;
    ((f32 *)&D_800D15E0)[2] = g;
    ((f32 *)&D_800D15E0)[3] = b;
    ((f32 *)&D_800D15E0)[4] = a;
    D_8013B2D8->b[7] = a;
    n = (n + 1) % 18;
    if (D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->base) >> 3) >= 0xBB8) {
        if (func_00269A80(D_8013B2D8, n) != 0) {
            {
                DlCmd *q = D_80110634++;
                q->w0 = 0xE200001C;
                q->w1 = 0x0C184DD8;
            }
            func_00268CE0(1);
            root = *p;
            func_00253B5C(0, p);
            if (flag) {
                DlCmd *q = D_80110634++;
                q->w0 = 0xDB060004;
                q->w1 = seg;
            } else {
                DlCmd *q = D_80110634++;
                q->w0 = 0xDA380003;
                q->w1 = seg;
            }
            nd = node;
            if (nd == NULL) {
                nd = func_0028FD94(root, 0);
            }
            {
                DlCmd *q = D_80110634++;
                q->w0 = 0xDB060008;
                q->w1 = (u32)nd;
            }
            nn = func_0028FD94(root, 2);
            count = nn[0];
            for (i = 0; i < count; i++) {
                c = func_0028FD94(nn, i);
                e = func_0028FD94(c, 0);
                if (i == 0) {
                    func_0026B504(seg, arg4, e);
                }
                if ((((u8 *)e)[6] & 0x38) == 0x38 && func_00269A80(e, n) != 0) {
                    s32 *w = func_0028FD94(c, 1);
                    DlCmd *q = D_80110634++;
                    q->w0 = 0xDE000000;
                    q->w1 = (u32)w;
                }
            }
        }
        D_800D15E0 = 0;
    }
}
