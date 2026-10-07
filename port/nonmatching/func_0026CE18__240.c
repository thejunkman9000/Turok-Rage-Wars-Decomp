#include "r06_types.h"

extern R06G468A0 D_801468A0[];
extern s32 D_80146918;
extern s32 D_801468F4;
extern u32 D_8013B2D8[];
extern f32 D_800C9790;
extern f32 D_800C9794;
extern s32 D_800D15E0;
extern R06Dl *D_80110634;
extern u32 D_800E28A4;
typedef struct R06GfxCtx { u8 pad0[0x114]; R06Dl *base; } R06GfxCtx;
extern R06GfxCtx *D_8011FE80;

void func_00253B5C();
void func_00268CE0();
s32 func_00269A80();
void func_0026B504();
void *func_0028FD94();

#define PUSH(a, b) { R06Dl *g = D_80110634++; g->w0 = (a); g->w1 = (b); }

void func_0026CE18(void **p, R06Player *pl, s32 seg, s32 flag, void *lights, s32 *node, s32 n) {
    s32 fp, s10, s14, i, count;
    s32 *root, *nn;
    u8 *e;
    s32 *c;
    f32 f, g;

    fp = 0;
    s10 = 0;
    s14 = 0;
    if (seg != 0) {
        if (D_801468A0->w98 != 0) {
            if (pl->blk->kind == 0xB && pl->blk->b94 != 0) {
                fp = fp < D_801468A0->wA0;
            }
        }
        if (pl->flags122C & 0x8000) {
            fp = 1;
        }
        if (0.0f < pl->f11EC) {
            s14 = 1;
        }
        if (D_80146918 != 0 && pl->blk->b8F == 1) {
            s10 = 1;
        }
        D_8013B2D8[0] |= 0x400;
        f = D_800C9790;
        g = D_800C9794;
        ((f32 *)&D_800D15E0)[1] = f;
        ((f32 *)&D_800D15E0)[2] = f;
        ((f32 *)&D_800D15E0)[3] = f;
        ((f32 *)&D_800D15E0)[4] = g;
        D_8013B2D8[0] |= 0x1402;
        D_800D15E0 = 3;
        if (D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->base) >> 3) >= 0xBB8) {
            if (func_00269A80(D_8013B2D8, n) != 0) {
                PUSH(0xE200001C, 0x0C184DD8);
                func_00268CE0(1);
                if (flag) { PUSH(0xDB060004, seg); } else { PUSH(0xDA380003, seg); }
                if (lights != 0) {
                    PUSH(0xDB020000, 0x18);
                    PUSH(0xDC08060A, (u32)lights + 8);
                    PUSH(0xDC08090A, (u32)lights);
                }
                func_00253B5C(0, p);
                root = *p;
                if (node == 0) {
                    node = func_0028FD94(root, 0);
                }
                PUSH(0xDB060008, (u32)node);
                nn = func_0028FD94(root, 2);
                count = nn[0];
                for (i = 0; i < count; i++) {
                    c = func_0028FD94(nn, i);
                    e = func_0028FD94(c, 0);
                    if (i == 0) {
                        func_0026B504(seg, lights, e);
                    }
                    if (pl->blk->kind == 0x12 && (D_801468F4 == 0 || pl->blk->b8F == 0)) {
                        switch (pl->blk->sub) {
                        case 0:
                            if ((e[6] & 0x38) != 0x28) goto next;
                            break;
                        case 1:
                            if ((e[6] & 0x38) != 0x20) goto next;
                            break;
                        case 2:
                            if ((e[6] & 0x38) != 0x18) goto next;
                            break;
                        default:
                            goto next;
                        }
                        if (func_00269A80(e, n) != 0) {
                            void *w = func_0028FD94(c, 1);
                            PUSH(0xDE000000, (u32)w);
                        }
                    } else {
                        s32 m = e[6] & 0x38;
                        if (m == 0x38 && fp == 0) goto next;
                        if (m == 0x30 && s10 == 0) goto next;
                        if (m == 0x10 && s14 == 0) goto next;
                        if (func_00269A80(e, n) != 0) {
                            void *w = func_0028FD94(c, 1);
                            PUSH(0xDE000000, (u32)w);
                        }
                    }
                next:;
                }
            }
            D_800D15E0 = 0;
        }
    }
}
