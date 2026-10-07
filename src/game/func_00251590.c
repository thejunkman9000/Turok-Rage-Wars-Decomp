#include "b12_types.h"

extern B12Mgr D_80103F70;
extern u32 D_801051A8;
u32 func_002558C0(void *heap, u32 size);
void func_00255ACC(void *heap, u32 key);
void func_00255C40(B12List *l, s32 prevOff, s32 nextOff);
void func_00255CB4(B12List *l, B12Node *n);
void func_00255D10(B12List *l, B12Node *ref, B12Node *n);
void func_00255E78(B12List *l, B12Node *n);
void func_00255F10(B12List *l);
void func_00265398(u32 dst, u32 src, u32 len);

typedef struct B12Cache {
    B12Node *cur;
    u8 pad4[4];
    B12List l0;
    B12List l1;
} B12Cache;

void func_00251590(s32 unused, s32 flag) {
    B12List local;
    B12Node *n;
    B12Node *next;
    B12Node *p;
    u32 r;
    func_00255C40(&local, 0x20, 0x24);
    if ((flag == 0 && D_80103F70.cur != 0) || (D_80103F70.cur = (B12Node *)D_80103F70.lists[1].head, D_80103F70.lists[1].head != 0)) {
        B12Cache *c = (B12Cache *)&D_80103F70.cur;
        u32 *firstp = &D_801051A8;
        void *heap = (u8 *)firstp - 8;
        do {
            n = c->cur;
            c->cur = n->next;
            if (!(n->flags & 0x701) && *firstp + 0x20 < n->key) {
                func_00255ACC(heap, n->key);
                r = func_002558C0(heap, n->unk4);
                if (r < n->key) {
                    func_00265398(r, n->key, n->unk4);
                    n->key = r;
                    func_00255E78(&c->l1, n);
                    func_00255CB4(&local, n);
                }
                if (flag == 0) {
                    break;
                }
            }
        } while (D_80103F70.cur != 0);
    }
    n = (B12Node *)local.head;
    if (n) {
        do {
            next = n->next;
            func_00255F10(&local);
            p = (B12Node *)D_80103F70.lists[1].head;
            if (p) {
                do {
                    if (p->key > n->key) {
                        func_00255D10(&D_80103F70.lists[1], p, n);
                        break;
                    }
                    p = p->next;
                } while (p);
            }
            if (!p) {
                func_00255CB4(&D_80103F70.lists[1], n);
            }
            n->flags |= 0x1000;
            n = next;
        } while (n);
    }
}
