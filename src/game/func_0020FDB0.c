#include "b03_types.h"

extern WpnDesc *D_800D052C[];
extern u8 D_80121990[];
void func_002100E0(CtlB *c);
s32 func_0022EAFC(ActorB *a, s32 w);
s32 func_00274544(void);
s32 func_002831FC(void *p, ActorB *a);

void func_0020FDB0(CtlB *c, s32 *tbl0) {
    s32 cand[8];
    s32 *tbl;
    u32 i;
    u32 n;
    s32 cur;
    s32 w;
    s32 pick;
    s32 t;

    if (c->actor->unk1450 == 0) {
        return;
    }
    if (c->actor->unk5E0 == 0xE) {
        func_002100E0(c);
        return;
    }
    n = 0;
    cur = 0;
    for (i = 0; i < 8; i++) {
        w = *(s32 *)((u8 *)c->actor->def + (i << 2) + 0x4C);
        w -= 0x4C3;
        if (w < 0) {
            continue;
        }
        if (tbl0[i] == 0) {
            continue;
        }
        if (func_0022EAFC(c->actor, w) == 0) {
            continue;
        }
        if ((u32)w >= 2) {
            t = c->actor->stats->unk93;
            if (t == 1) {
                goto b17;
            }
            if (t < 2) {
                if (t == 0) {
                    goto b14;
                }
            } else if (t == 2) {
                goto add;
            }
            c->actor->stats->unk93 = 0;
b14:
            if (D_800D052C[w]->info->type == 1) {
                continue;
            }
            if (w == 6) {
                w = 5;
            }
b17:
            if (D_800D052C[w]->info->type == 2) {
                continue;
            }
        }
add:
        cand[n] = w;
        n++;
        if (w == c->actor->unk62E) {
            cur = 1;
        }
    }
    if (cur != 0) {
        if (c->actor->unk62E == 4 && c->actor->unk594 == 2) {
            return;
        }
        if (func_002831FC(D_80121990, c->actor) > 0) {
            return;
        }
        if (func_00274544() % 100 >= 21) {
            return;
        }
    }
    if (n != 0) {
        pick = cand[func_00274544() % n];
        c->actor->unk770 = pick;
        if (pick != c->actor->unk62E) {
            c->unk2E4 = 0;
        }
    }
}
