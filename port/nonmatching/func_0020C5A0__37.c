#include "b02_types.h"

f32 func_0020C2E8(B2Mgr *m, B2Node *n);
f32 func_00272768(void *a, void *b);
extern const f32 D_800C6E70;
extern f32 D_800C6E74;
extern f32 D_800C6E78;

static inline void *getRec0(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool0;

    return &pool->data[idx * pool->elemSize];
}

static inline B2Edge *getEdge(B2Mgr *m, s32 idx) {
    B2Pool *pool = m->pool8;

    return (B2Edge *)&pool->data[idx * pool->elemSize];
}

static inline s32 isBi(u8 kind) {
    switch (kind) {
    case 1:
    case 4:
    case 7:
        return 1;
    default:
        return 0;
    }
}

static inline B2Node *find(B2Mgr *m, s32 key) {
    B2Node *n;

    for (n = m->head; n != NULL; n = n->next) {
        if (n->id == key) {
            return n;
        }
    }
    return NULL;
}

static inline s32 adj(B2Mgr *m, s32 key, s32 *nb, s32 *ei) {
    s32 k;
    s32 cnt;
    B2Edge *e;

    cnt = k = 0;
    for (; k < m->count; k++) {
        e = getEdge(m, k);
        if (e->a == key) {
            nb[cnt] = e->b;
            ei[cnt] = k;
            cnt++;
        }
        if (e->b == key) {
            nb[cnt] = e->a;
            ei[cnt] = k;
            cnt++;
        }
    }
    return cnt;
}

static inline s32 hasOpen(B2Mgr *m) {
    B2Node *n;

    for (n = m->head; n != NULL; n = n->next) {
        if (n->unk28 == 1) {
            return 1;
        }
    }
    return 0;
}

void func_0020C5A0(B2Mgr *m, B2Node *start) {
    s32 nb[64];
    s32 ei[64];
    B2Node *n;
    B2Node *cur;
    B2Node *sel;
    B2Node *nbr;
    B2Edge *e;
    u8 *rec;
    u8 *rec2;
    f32 bestf;
    f32 d;
    f32 g;
    s32 i;
    s32 cnt;
    s32 key;

    start->unk1C = 0;
    start->unk20 = func_0020C2E8(m, start);
    start->link30 = NULL;
    start->unk28 = 1;
    start->unk24 = start->unk1C + start->unk20;
    while (hasOpen(m)) {
        bestf = D_800C6E74;
        sel = NULL;
        for (n = m->head; n != NULL; n = n->next) {
            if (n->unk28 == 1 && (n->unk24 < bestf || bestf == D_800C6E70)) {
                sel = n;
                bestf = n->unk24;
            }
        }
        if (sel != NULL) {
            sel->unk28 = 0;
        }
        cur = sel;
        rec = getRec0(m, cur->id);
        if (cur->unk2C != 0) {
            m->unk18 = cur->id;
            return;
        }
        for (i = 0; i < 64; i++) {
            nb[i] = -1;
            ei[i] = -1;
        }
        key = cur->id;
        cnt = adj(m, key, nb, ei);
        for (i = 0; i < cnt; i++) {
            rec2 = getRec0(m, nb[i]);
            nbr = find(m, nb[i]);
            e = getEdge(m, ei[i]);
            if (isBi(e->kind) || e->a == cur->id) {
                if (e->kind == 10) {
                    goto skip;
                }
                if (e->kind != 11) {
                    if (e->kind == 9) {
                        d = 0.0f;
                    } else {
                        d = func_00272768(rec2, rec);
                    }
                    d += nbr->unk18;
                    if (*(u16 *)(rec2 + 0xC) & 0x400) {
                        d += D_800C6E78;
                    }
                    if (d < 0.0f) {
                        d = 0.0f;
                    }
                    g = cur->unk1C + d;
                    if (!((nbr->unk28 == 2 || nbr->unk28 == 1) && nbr->unk1C <= g)) {
                        nbr->link30 = cur;
                        nbr->unk1C = g;
                        nbr->unk20 = func_0020C2E8(m, nbr);
                        nbr->unk24 = nbr->unk1C + nbr->unk20;
                        if (nbr->unk28 == 2) {
                            nbr->unk28 = 0;
                        }
                        if (nbr->unk28 != 1) {
                            nbr->unk28 = 1;
                        }
                    }
                }
            }
skip:
            ;
        }
        cur->unk28 = 2;
    }
}
