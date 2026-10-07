#include "b12_types.h"

inline u32 func_00255ACC(B12Heap *h, u8 *ptr) {
    B12HBlk *blk = (B12HBlk *)(ptr - 0x20);
    B12HBlk *f = (B12HBlk *)blk->unk8;
    B12HBlk *a1;
    B12HBlk *p;
    if (f->size == 0) {
        a1 = blk->next;
        if (!a1) {
            for (a1 = f; a1; a1 = (B12HBlk *)a1->unk8) {
                if (a1->size != 0) {
                    break;
                }
            }
        }
        if (a1) {
            f->next = a1;
            p = a1->prev;
            f->prev = p;
            if (a1->prev) {
                p->next = f;
            }
            a1->prev = f;
            if (h->last == a1) {
                h->last = f;
            }
        } else {
            f->prev = h->first;
            if (h->first) {
                h->first->next = f;
            } else {
                h->last = f;
            }
            h->first = f;
        }
    }
    f->size = f->size + (blk->hdr + blk->size);
    if (blk->unkC) {
        ((B12HBlk *)blk->unkC)->unk8 = blk->unk8;
    }
    ((B12HBlk *)blk->unk8)->unkC = blk->unkC;
    if (blk->size) {
        if (blk->next) {
            blk->next->prev = blk->prev;
        }
        if (blk->prev) {
            blk->prev->next = blk->next;
        }
        if (h->last == blk) {
            h->last = blk->next;
        }
    }
    return f->size - 0x20;
}

void func_00255720(B12Heap *h) {
    while (h->cur->unkC != 0) {
        func_00255ACC(h, (u8 *)h->cur->unkC + 0x20);
    }
}
