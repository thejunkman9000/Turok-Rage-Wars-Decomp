#include "b16_types.h"

typedef struct B16Gfx {
    u8 pad0[0x114];
    DlCmd *base;
} B16Gfx;

extern B16Gfx *D_8011FE80;
extern DlCmd *D_80110634;
extern u32 D_800E28A4;

s32 *func_0028FD94(s32 *node, s32 idx);
void func_00253B5C(s32 a, s32 **p);
void func_0026B504(s32 a, s32 b, s32 *c);
s32 func_00269A80(s32 a, s32 b);
void func_0026925C(s32 a);

void func_0026DF7C(s32 a0, s32 id, s32 **p, s32 seg, s32 flag, s32 arg5, s32 *node, s32 arg7) {
    s32 *root;
    s32 *n;
    s32 *c;
    s32 *e;
    s32 i;
    s32 count;
    s32 *nd;

    if (D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->base) >> 3) >= 0xBB8 && func_00269A80(a0, arg7) != 0) {
        if (flag) {
            DlCmd *q = D_80110634++;
            q->w0 = 0xDB060004;
            q->w1 = seg;
        } else {
            DlCmd *q = D_80110634++;
            q->w0 = 0xDA380003;
            q->w1 = seg;
        }
        if (id != -1) {
            func_0026925C(id);
        }
        func_00253B5C(0, p);
        root = *p;
        nd = node;
        if (nd == NULL) {
            nd = func_0028FD94(root, 0);
        }
        {
            DlCmd *q = D_80110634++;
            q->w0 = 0xDB060008;
            q->w1 = (u32)nd;
        }
        n = func_0028FD94(root, 2);
        count = n[0];
        for (i = 0; i < count; i++) {
            c = func_0028FD94(n, i);
            e = func_0028FD94(c, 0);
            if (i == 0) {
                func_0026B504(seg, arg5, e);
            }
            {
                s32 *w = func_0028FD94(c, 1);
                DlCmd *q = D_80110634++;
                q->w1 = (u32)w;
                q->w0 = 0xDE000000;
            }
        }
    }
}
