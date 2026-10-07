/* PARTIAL (177 words): logic/layout match, but callee-saved register assignment of the loop (part/i/&D copy, hoisted constant 0x30 vs 0xDE000000) differs; struct param {pl, mtx} at a1/a2 */
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

typedef struct B15Stats {
    u8 pad0[0x80];
    s8 unk80;
    s8 unk81;
    u8 pad82[0xD];
    u8 unk8F;
    u8 pad90[4];
    u8 unk94;
} B15Stats;

typedef struct B15Pl {
    u8 pad0[0x5D8];
    B15Stats *stats;
    u8 pad5DC[0xC50];
    u32 unk122C;
} B15Pl;

typedef struct B15Pl2 {
    u8 pad0[0x11EC];
    f32 unk11EC;
} B15Pl2;

typedef struct B15PlArg {
    B15Pl *pl;
    s32 mtx;
} B15PlArg;

typedef struct B15Dbg {
    u8 pad0[0x98];
    s32 unk98;
    u8 pad9C[4];
    s32 unkA0;
} B15Dbg;

void func_00253B5C();
s32 func_00269A80(void *p, s32 a);
void func_0026B504(s32 a, B15Lights1 *lights, void *info);
void *func_0028FD94(void *node, s32 idx);
extern s32 D_800E28A4;
extern P4Gfx *D_80110634;
extern B15GfxCtx *D_8011FE80;
extern B15Dbg D_801468A0[];
extern s32 D_801468F4;
extern s32 D_80146918;

void func_0026B6A0(void **a0, B15PlArg k, s32 flag, B15Lights1 *lights, void *a5, s32 a6) {
    void *root;
    void *arr;
    void *part;
    B15Info *info;
    B15Stats *st;
    void *dl;
    s32 n;
    s32 i;
    s32 s6;
    s32 s7;
    s32 sp10;
    s32 m;
    s32 f;
    P4Gfx *g1;
    P4Gfx *g2;
    P4Gfx *g3;
    P4Gfx *g4;
    void *p;

    s6 = 0;
    sp10 = 0;
    s7 = 0;
    if ((u32)(D_800E28A4 - (((u32)D_80110634 - (u32)D_8011FE80->start) >> 3)) >= 0xBB8) {
        if (D_801468A0->unk98 != 0) {
            st = k.pl->stats;
            if (st->unk80 == 0xB && st->unk94 != 0) {
                s6 = s6 < D_801468A0->unkA0;
            }
        }
        if (k.pl->unk122C & 0x8000) {
            s6 = 1;
        }
        if (0.0f < ((B15Pl2 *)k.pl)->unk11EC) {
            sp10 = 1;
        }
        if (D_80146918 != 0) {
            if (k.pl->stats->unk8F == 1) {
                s7 = 1;
            }
        }
        root = *a0;
        func_00253B5C(0, a0);
        if (flag) {
            g1 = D_80110634++;
            g1->words.w0 = 0xDB060004;
            g1->words.w1 = k.mtx;
        } else {
            g2 = D_80110634++;
            g2->words.w0 = 0xDA380003;
            g2->words.w1 = k.mtx;
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
                func_0026B504(k.mtx, lights, info);
            }
            st = k.pl->stats;
            if (st->unk80 == 0x12 && (D_801468F4 == 0 || st->unk8F == 0)) {
                if (st->unk81 == 0) {
                    m = 0x28;
                } else if (st->unk81 == 1) {
                    m = 0x20;
                } else {
                    m = 0x18;
                }
                f = info->flags & 0x38;
                if (f == m || (f == 0x38 && s6 != 0) || (f == 0x30 && s7 != 0)) {
                    if (func_00269A80(info, a6)) {
                        dl = func_0028FD94(part, 1);
                        g4 = D_80110634++;
                        g4->words.w0 = 0xDE000000;
                        g4->words.w1 = (u32)dl;
                    }
                }
            } else {
                f = info->flags & 0x38;
                if (f == 0x38 && s6 == 0) {
                    continue;
                }
                if (f == 0x30 && s7 == 0) {
                    continue;
                }
                if (f == 0x10 && sp10 == 0) {
                    continue;
                }
                if (func_00269A80(info, a6)) {
                    dl = func_0028FD94(part, 1);
                    g4 = D_80110634++;
                    g4->words.w0 = 0xDE000000;
                    g4->words.w1 = (u32)dl;
                }
            }
        }
    }
}