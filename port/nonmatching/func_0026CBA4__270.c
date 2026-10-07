/* PARTIAL (13 words): schedule order of the first block (D_8013B348 RMW vs check loads vs D_800D15E0 store); everything else matches */
#include "b15_types.h"
#include "p4_types.h"

typedef struct B15GfxCtx {
    u8 pad0[0x114];
    P4Gfx *start;
} B15GfxCtx;

typedef struct B15Info {
    u8 pad0[6];
    u8 flags;
} B15Info;

typedef struct B15Pad {
    u8 pad0[0x122C];
    u32 unk122C;
} B15Pad;

void func_002A11E8();
void func_00253B5C();
s32 func_00269A80(void *p, s32 a);
void *func_0028FD94(void *node, s32 idx);
extern s32 D_800D15E0;
extern s32 D_800E28A4;
extern P4Gfx *D_80110634;
extern B15GfxCtx *D_8011FE80;
extern s32 D_8013B348;

void func_0026CBA4(void **a0, B15Pad *pad, s32 mtx, s32 flag, B15Lights1 *lights, void *a5, s32 a6) {
    void *root;
    void *arr;
    void *part;
    B15Info *info;
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
    s32 *fp;

    func_002A11E8();
    fp = &D_8013B348;
    *fp |= 0x20;
    D_800D15E0 = 1;
    if ((u32)(D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->start) >> 3)) >= 0xBB8 && func_00269A80(fp, a6) != 0) {
        g0 = D_80110634++;
        g0->words.w0 = 0xE200001C;
        g0->words.w1 = 0x0C184DD8;
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
        p = a5;
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
            info = func_0028FD94(part, 0);
            if ((info->flags & 0x38) != 0x38 || (pad->unk122C & 0x400)) {
                dl = func_0028FD94(part, 1);
                g4 = D_80110634++;
                g4->words.w0 = 0xDE000000;
                g4->words.w1 = (u32)dl;
            }
        }
    }
}
