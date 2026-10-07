#include "b02_types.h"

void func_002095F8(B2Ctl *ctl);
void func_00209CD8(B2Ctl *ctl);
void func_002227D0(B2Actor *a, B2Actor *b, s32 n);
s32 func_0022ABF0(B2Actor *a);
void func_002636D0(void *p);
void func_002AB784(void *p, s32 v);
void func_002AB78C(void *p, s32 v);
extern B2GameFlags D_801468A0[];
extern u8 D_8013B7B8[];
extern s32 D_8014693C;
extern f32 D_800C6CA0;
extern f32 D_800C6CA4;

void func_00208158(B2Ctl *ctl) {
    f32 fs;
    s32 s0;
    s32 v;
    s32 w;
    s32 t;
    B2Actor *o;
    B2GameFlags *g;

    if (ctl->owner->unk1450 != 0) {
        if (ctl->unk8 == -1) {
            if (ctl) {
                ctl->unk8 = ctl->unk4;
            } else {
                ctl->unk8 = ctl->unk4;
            }
        }
        func_002095F8(ctl);
        if (ctl->cur->upd != NULL) {
            ctl->cur->upd(ctl->owner, 0);
        }
        if (ctl->unk324 > 0) {
            ctl->unk324--;
        }
        if (ctl->owner->stats->unk94 != 0) {
            t = ctl->owner->stats->unk80;
            s0 = ctl->owner->unk5E4 >> 8;
            if (t == 11) {
                goto big;
            }
            if (t == 12) {
big:
                v = 0x190;
            } else if (t == 14) {
                v = 0x12C;
            } else if (t == 13) {
                v = 0x12C;
            } else {
                v = func_0022ABF0(ctl->owner) >> 8;
            }
            fs = ((f32)s0 / (f32)v) * D_800C6CA0;
            if (ctl->owner->stats->unk80 == 14) {
                if (fs == 0.0f) {
                    fs = (f32)((3 - D_8014693C) * 0x21);
                } else {
                    fs *= D_800C6CA4;
                    fs += (f32)((2 - D_8014693C) * 0x21);
                }
                if (fs < 0.0f) {
                    fs = 0.0f;
                }
            }
            g = D_801468A0;
            if (g->unk98 != 0) {
                if (ctl->owner->stats->unk80 == 11) {
                    func_002AB784(D_8013B7B8, (s32)(f32)g->unkA0);
                    if (g->unkA4 > 0) {
                        g->unkA4--;
                        func_002636D0((u8 *)ctl->owner + 0x688);
                        ctl->unk23C = 0;
                        ctl->unk240 = 0;
                    }
                    if (g->unkA4 == 0 && ctl->owner->unk5E4 > 0) {
                        g->unkA0 = 100;
                        g->unkA4 = -1;
                        func_002227D0(ctl->owner, ctl->owner, 2);
                    }
                }
                if (ctl->owner->stats->unk94 == 1) {
                    func_002AB784(D_8013B7B8, (s32)fs);
                } else {
                    func_002AB78C(D_8013B7B8, (s32)fs);
                }
            }
        }
        o = ctl->owner;
        if (o->unk650 == 0x12) {
            o->unk1340++;
            func_00209CD8(ctl);
        }
    }
}
