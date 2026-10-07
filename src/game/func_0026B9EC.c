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
    u8 pad0[0x102];
    u16 buttons;
} B15Pad;

void func_00253B5C(s32 a, void *p);
s32 func_00269A80(void *info, s32 arg);
void func_0026B504(s32 a, B15Lights1 *lights, void *info);
void *func_0028FD94(void *node, s32 idx);
extern s32 D_800E28A4;
extern P4Gfx *D_80110634;
extern B15GfxCtx *D_8011FE80;

void func_0026B9EC(void **a0, B15Pad *pad, s32 mtx, s32 flag, B15Lights1 *lights, void *a5, s32 a6) {
    void *root;
    void *arr;
    void *part;
    B15Info *info;
    void *dl;
    s32 n;
    s32 i;
    s32 ok;
    u16 v;
    P4Gfx *g1;
    P4Gfx *g2;
    P4Gfx *g3;
    P4Gfx *g4;
    void *p;

    if ((u32)(D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->start) >> 3)) < 0xBB8) {
        return;
    }
    root = *a0;
    func_00253B5C(0, a0);
    if (flag) {
        g1 = D_80110634++;
        g1->words.w0 = 0xDB060004;
        g1->words.w1 = mtx;
    } else {
        g2 = D_80110634++;
        g2->words.w0 = 0xDA380003;
        g2->words.w1 = mtx;
    }
    p = a5;
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
        if (i == 0) {
            func_0026B504(mtx, lights, info);
        }
        ok = 1;
        switch (info->flags & 3) {
        case 2:
            if (!(info->flags & 4)) {
                v = pad->buttons & 8;
            } else {
                v = pad->buttons & 2;
            }
            goto test;
        case 3:
            if (!(info->flags & 4)) {
                v = pad->buttons & 0x80;
            } else {
                v = pad->buttons & 0x20;
            }
            goto test;
        case 1:
            v = pad->buttons & 0x100;
        test:
            if (v == 0) {
                ok = 0;
            }
            break;
        }
        if (ok && func_00269A80(info, a6)) {
            dl = func_0028FD94(part, 1);
            g4 = D_80110634++;
            g4->words.w0 = 0xDE000000;
            g4->words.w1 = (u32)dl;
        }
    }
}
