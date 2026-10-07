#include "b15_types.h"
#include "p4_types.h"

typedef struct B15GfxCtx {
    u8 pad0[0x114];
    P4Gfx *start;
} B15GfxCtx;

void func_00253B5C();
void *func_0028FD94(void *node, s32 idx);
extern s32 D_800D15B0;
extern s32 D_800D15B4;
extern s32 D_800D15D4;
extern s32 D_800D15DC;
extern s32 D_800E28A4;
extern P4Gfx *D_80110634;
extern B15GfxCtx *D_8011FE80;

void func_0026C6D8(u8 color, void **a1, s32 mtx, s32 flag, void *a4unused, void *a4) {
    void *root;
    void *arr;
    void *part;
    void *dl;
    s32 n;
    s32 i;
    P4Gfx *g0;
    P4Gfx *g1;
    P4Gfx *g2;
    P4Gfx *g3;
    P4Gfx *g4;
    P4Gfx *g5;
    P4Gfx *g6;
    P4Gfx *g7;
    P4Gfx *g8;
    P4Gfx *g9;
    P4Gfx *g10;
    P4Gfx *gl;
    u32 t;
    void *p;

    if ((u32)(D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->start) >> 3)) < 0xBB8) {
        return;
    }
    root = *a1;
    func_00253B5C(0, a1);
    if (flag) {
        g0 = D_80110634++;
        g0->words.w0 = 0xDB060004;
        g0->words.w1 = mtx;
    } else {
        g1 = D_80110634++;
        g1->words.w0 = 0xDA380003;
        g1->words.w1 = mtx;
    }
    p = a4;
    if (p == NULL) {
        p = func_0028FD94(root, 0);
    }
    g2 = D_80110634++;
    g2->words.w0 = 0xDB060008;
    g2->words.w1 = (u32)p;
    i = 0;
    arr = func_0028FD94(root, 2);
    g3 = D_80110634++;
    t = D_800D15D4;
    D_800D15B0 = -1;
    D_800D15B4 = -1;
    t |= 0x400;
    n = *(s32 *)arr;
    g3->words.w0 = 0xE7000000;
    g3->words.w1 = 0;
    g4 = D_80110634++;
    g4->words.w0 = 0xE3001001;
    g4->words.w1 = 0;
    g5 = D_80110634++;
    g5->words.w0 = 0xD7FF0002;
    g5->words.w1 = 0x80008000;
    g6 = D_80110634++;
    g6->words.w0 = 0xFA000000;
    g6->words.w1 = color;
    g7 = D_80110634++;
    g7->words.w0 = 0xFCFFFFFF;
    g7->words.w1 = 0xFFFDF6FB;
    g8 = D_80110634++;
    g8->words.w0 = 0xE200001C;
    g8->words.w1 = D_800D15DC | 0x104E50;
    g9 = D_80110634++;
    g9->words.w0 = 0xD9D8FBFB;
    g9->words.w1 = 0;
    g10 = D_80110634++;
    g10->words.w0 = 0xD9FFFFFF;
    g10->words.w1 = t;
    for (i = 0; i < n; i++) {
        part = func_0028FD94(arr, i);
        func_0028FD94(part, 0);
        dl = func_0028FD94(part, 1);
        gl = D_80110634++;
        gl->words.w0 = 0xDE000000;
        gl->words.w1 = (u32)dl;
    }
    D_800D15B4 = -1;
    D_800D15B0 = -1;
}