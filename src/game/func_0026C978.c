#include "b15_types.h"
#include "p4_types.h"

typedef struct B15GfxCtx {
    u8 pad0[0x114];
    P4Gfx *start;
} B15GfxCtx;

void func_00253B5C(s32 a, void *p);
void func_00268CE0();
s32 func_00269A80(void *p, s32 a);
void *func_0028FD94(void *node, s32 idx);
extern s32 D_800E28A4;
extern P4Gfx *D_80110634;
extern B15GfxCtx *D_8011FE80;
extern u8 D_8013B2D8[];

void func_0026C978(void **a0, s32 mtx, s32 flag, B15Lights1 *lights, void *a4, s32 a5) {
    void *root;
    void *arr;
    void *part;
    void *dl;
    s32 n;
    s32 i;
    P4Gfx *g0;
    P4Gfx *g1;
    P4Gfx *g2;
    P4Gfx *l0;
    P4Gfx *l1;
    P4Gfx *l2;
    P4Gfx *g3;
    P4Gfx *g4;
    void *p;

    if ((u32)(D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->start) >> 3)) >= 0xBB8 && func_00269A80(D_8013B2D8, a5) != 0) {
        g0 = D_80110634++;
        g0->words.w0 = 0xE200001C;
        g0->words.w1 = 0x0C184F50;
        func_00268CE0(2);
        if (flag) {
            g1 = D_80110634++;
            g1->words.w0 = 0xDB060004;
            g1->words.w1 = mtx;
        } else {
            g2 = D_80110634++;
            g2->words.w0 = 0xDA380003;
            g2->words.w1 = mtx;
        }
        if (lights != NULL) {
            l0 = D_80110634++;
            l0->words.w0 = 0xDB020000;
            l0->words.w1 = 0x18;
            l1 = D_80110634++;
            l1->words.w0 = 0xDC08060A;
            l1->words.w1 = (u32)&lights->l[0];
            l2 = D_80110634++;
            l2->words.w0 = 0xDC08090A;
            l2->words.w1 = (u32)lights;
        }
        func_00253B5C(0, a0);
        p = a4;
        root = *a0;
        if (p == NULL) {
            p = func_0028FD94(root, 0);
        }
        g3 = D_80110634++;
        g3->words.w0 = 0xDB060008;
        g3->words.w1 = (u32)p;
        arr = func_0028FD94(root, 2);
        n = *(s32 *)arr;
        for (i = 0; i < n; i++) {
            part = func_0028FD94(arr, i);
            func_0028FD94(part, 0);
            dl = func_0028FD94(part, 1);
            g4 = D_80110634++;
            g4->words.w0 = 0xDE000000;
            g4->words.w1 = (u32)dl;
        }
    }
}
