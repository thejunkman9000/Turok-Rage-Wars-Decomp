#include "o04_types.h"
#include "q03_types.h"
extern O04GFlags D_801468A0[];
extern Q03Cfg D_801462C8[];
extern u8 *D_800E4680;
s32 func_0042E640(u8 *a);
void func_0042E3D0(void) {
    s32 s7 = 0;
    s32 s6 = 0;
    s32 i = 0;
    s32 off;
    s32 idx;
    u8 t;
    Q03Ent *e;
    Q03Cfg *g;
    O04GFlags *G;
    G = D_801468A0;
    e = (Q03Ent *)((u8 *)G - 0x508);
    for (; i < 8; i++, e++) {
        if (e->f78 == 1 && e->f91 == e->f78) {
            e->f78 = 0;
            e->f91 = 0;
        }
    }
    g = D_801462C8;
    off = 5;
    for (i = 0; i < 7; i++, off += 4) {
        t = D_800E4680[i * 4 + 5];
        if (t == 0) {
            continue;
        }
        switch (t - 0xC) {
        case 0:
            G->unk98 = 1;
            idx = func_0042E640(D_800E4680 + off);
            g->ent[idx].f94 = 2;
            G->unkA0 = 0x64;
            G->unkA4 = -1;
            break;
        case 1:
            G->unk98 = 1;
            idx = func_0042E640(D_800E4680 + off);
            g->ent[idx].f94 = 1;
            break;
        case 4:
            idx = func_0042E640(D_800E4680 + off);
            g->ent[idx].f94 = 2;
            break;
        case 2:
            idx = func_0042E640(D_800E4680 + off);
            if (s7 == 0) {
                s7 = 1;
                G->unk98 = 1;
                g->ent[idx].f94 = 1;
            } else {
                g->ent[idx].f94 = 0;
            }
            break;
        case 3:
            s6 = 1;
            G->unk98 = 1;
            G->unk9C = 0;
            idx = func_0042E640(D_800E4680 + off);
            g->ent[idx].f94 = 1;
            break;
        default:
            idx = func_0042E640(D_800E4680 + off);
            g->ent[idx].f94 = 0;
            if (s6 != 0) {
                g->ent[idx].f95 = 1;
            }
            break;
        }
    }
}
