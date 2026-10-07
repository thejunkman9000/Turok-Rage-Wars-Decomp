#include "b02_types.h"

void func_0044A37C(B2Actor *a, void *p);
extern s32 D_80146938;
extern B2GameFlags D_801468A0[];

void func_00209CD8(B2Ctl *ctl) {
    s32 lim;
    s32 st;
    B2Stats *stats;
    B2Actor *o;
    B2GameFlags *g;

    if (D_80146938 != 0) {
        st = ctl->owner->stats->unk80;
        if (st != 0xC) {
            lim = 0x1E;
            if (st == 0xF) lim = 0x384;
        } else {
            lim = 0x384;
        }
    } else {
        lim = 0x1E;
    }
    if (lim < ctl->owner->unk1340) {
        ctl->owner->unk1340 = 0;
        g = D_801468A0;
        if (g->unk98 != 0) {
            o = ctl->owner;
            stats = o->stats;
            if (stats->unk94 == 0) {
                if (stats->unk95 != 0 && g->unk9C != 3) {
                    return;
                }
            } else {
                st = stats->unk80;
                if (st != 0xC && st != 0xF) {
                    return;
                }
            }
        } else {
            o = ctl->owner;
        }
        func_0044A37C(o, g);
    }
}
