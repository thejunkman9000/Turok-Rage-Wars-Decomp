#include "r06_types.h"

extern s32 **D_8011064C;
extern s32 D_80110640;
extern s32 D_80110638;
extern s32 D_80110630;
extern u8 D_80110627;
extern R06Node *D_80110628;
extern R06Node *D_8011062C;
extern R06Node *D_8011063C;
extern R06Node *D_80110644;
extern R06Node D_801144D0[];
extern R06Sub D_80110650[];
extern R06Src D_801157D8[];

s32 *func_0028FD94();

static inline R06Node *find1(R06Node *n, u32 key) {
    R06Node *last = 0;
    while (n) {
        if (n->key == key) return n;
        last = n;
        if (key < n->key) n = n->l; else n = n->r;
    }
    return last;
}

static inline R06Node *find0(R06Node *n, u32 key) {
    R06Node *last = 0;
    u32 nk;
    while (n) {
        nk = n->key;
        if (nk == key) return n;
        last = n;
        if (key < nk) n = last->l; else n = last->r;
    }
    return last;
}

void func_0026BC60(void) {
    s32 *arr;
    s32 n, i, j, k1, cnt;
    void *part;
    R06Rec *rec;
    u32 key;
    R06Node *cur, *last, *near, *nd;
    void *data;

    if (D_80110640 != 0) {
        do {
        arr = func_0028FD94(*D_8011064C, 2);
        n = *arr;
        if (n > 0) {
        s32 *pc1;
        s32 *pc2;
        s32 lim;
        pc1 = &D_80110638; i = 0; lim = 0x1F4; pc2 = &D_80110630;
        top:
            part = func_0028FD94(arr, i);
            rec = func_0028FD94(part, 0);
            key = (rec->id << 8) | D_80110627;
            if (rec->flags & 0x700) {
                near = find1(D_8011063C, key);
            } else {
                near = find0(D_80110628, key);
            }
            if (near == 0 || near->key != key) {
                if (D_80110638 == 0x78) goto brk;
                k1 = *pc1;
                nd = &D_801144D0[k1];
                nd->key = key;
                nd->rec = rec;
                nd->tail = 0;
                nd->head = 0;
                *pc1 = k1 + 1;
                if (rec->flags & 0x700) {
                    if (near) {
                        if (nd->key < near->key) {
                            near->l = nd;
                            nd->r = 0;
                            nd->l = 0;
                            nd->prv = near;
                            nd->nxt = near->nxt;
                            if (near->nxt) near->nxt->prv = nd;
                            near->nxt = nd;
                            if (D_80110644 == near) D_80110644 = nd;
                        } else {
                            near->r = nd;
                            nd->r = 0;
                            nd->l = 0;
                            nd->prv = near->prv;
                            if (near->prv) near->prv->nxt = nd;
                            nd->nxt = near;
                            near->prv = nd;
                        }
                    } else {
                        D_8011063C = nd;
                        D_80110644 = nd;
                        nd->r = 0;
                        nd->l = 0;
                        nd->prv = 0;
                        nd->nxt = 0;
                    }
                } else {
                    if (near) {
                        if (nd->key < near->key) {
                            near->l = nd;
                            nd->r = 0;
                            nd->l = 0;
                            nd->prv = near;
                            nd->nxt = near->nxt;
                            if (near->nxt) near->nxt->prv = nd;
                            near->nxt = nd;
                            if (D_8011062C == near) D_8011062C = nd;
                        } else {
                            near->r = nd;
                            nd->r = 0;
                            nd->l = 0;
                            nd->prv = near->prv;
                            if (near->prv) near->prv->nxt = nd;
                            nd->nxt = near;
                            near->prv = nd;
                        }
                    } else {
                        D_80110628 = nd;
                        D_8011062C = nd;
                        nd->r = 0;
                        nd->l = 0;
                        nd->prv = 0;
                        nd->nxt = 0;
                    }
                }
            } else {
                nd = near;
            }
            data = func_0028FD94(part, 1);
            j = 0;
            cnt = D_80110640;
            if (cnt > 0) {
            R06Src *sr;
            R06Sub *pool;
            s32 cnt2;
            pool = D_80110650; cnt2 = cnt; sr = D_801157D8;
            inner:
                if (D_80110630 != lim) {
                    s32 k2 = *pc2;
                    R06Sub *p = (R06Sub *)(k2 * 32 + (u32)pool);
                    p->data = data;
                    p->a = sr->a;
                    p->b = sr->b;
                    p->c = sr->c;
                    p->h10 = rec->h18;
                    p->h12 = rec->h1A;
                    p->w14 = sr->d;
                    p->next = 0;
                    *pc2 = k2 + 1;
                    if (nd->tail) nd->tail->next = p; else nd->head = p;
                    nd->tail = p;
                }
                j++;
                sr++;
                if (j < cnt2) goto inner;
            }
        i++;
        if (i < n) goto top;
        }
        brk:
        D_80110640 = 0;
        } while (0);
    }
}