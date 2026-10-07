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
extern B16Gfx *D_8011FE80;
extern DlCmd *D_80110634;
extern u32 D_800E28A4;
extern f32 D_800D15F0;
extern s32 D_800D15E0;

s32 *func_0028FD94(s32 *node, s32 idx);
void func_00253B5C(s32 a, s32 **p);
void func_0026B504(s32 a, s32 b, s32 *c);
s32 func_00269A80(void *a, s32 b);
void func_002A11E8(void);
void func_00268CE0(s32 a);

void func_0026D27C(s32 **p, s32 seg, s32 flag, s32 arg3, s32 *node, s32 arg5) {
    s32 *root;
    s32 *n;
    s32 *c;
    s32 *e;
    s32 i;
    s32 count;
    s32 *nd;

    B16Env *env;
    u32 space;
    if (seg != 0) {
        func_002A11E8();
        env = D_8013B2D8;
        env->b[4] = 0x80;
        env->b[5] = 0x5F;
        env->b[6] = 0x22;
        env->b[7] = 0xF0;
        env->b[0] = 0xDB;
        env->b[1] = 0xB8;
        env->b[2] = 0x77;
        env->b[3] = 0x40;
        env->flags |= 0x400;
        ((f32 *)&D_800D15E0)[4] = 80.0f;
        env->flags |= 0x1402;
        space = D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->base) >> 3);
        D_800D15E0 = 1;
        if (space >= 0xBB8 && func_00269A80(env, arg5) != 0) {
            {
                DlCmd *q = D_80110634++;
                q->w0 = 0xE200001C;
                q->w1 = 0x0C184DD8;
            }
            func_00268CE0(1);
            if (flag) {
                DlCmd *q = D_80110634++;
                q->w0 = 0xDB060004;
                q->w1 = seg;
            } else {
                DlCmd *q = D_80110634++;
                q->w0 = 0xDA380003;
                q->w1 = seg;
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
                    func_0026B504(seg, arg3, e);
                }
                {
                    s32 *w = func_0028FD94(c, 1);
                    DlCmd *q = D_80110634++;
                    q->w0 = 0xDE000000;
                    q->w1 = (u32)w;
                }
            }
        }
    }
}