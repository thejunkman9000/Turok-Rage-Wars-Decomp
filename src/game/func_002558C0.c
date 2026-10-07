#include "b12_types.h"

B12HBlk *func_002558C0(B12Heap *h, u32 size) {
    B12HBlk *f;
    B12HBlk *b;
    B12HBlk *p;
    B12HBlk *nx;
    u32 need = (size + 0x2F) & ~0xF;
    f = h->first;
    if (f) {
        do {
            if (f->size >= need) {
                b = (B12HBlk *)((u8 *)f + f->hdr);
                b->hdr = need;
                b->size = f->size - need;
                if (b->size != 0) {
                    b->next = f;
                    p = f->prev;
                    b->prev = p;
                    if (f->prev) {
                        p->next = b;
                    }
                    f->prev = b;
                    if (h->last == f) {
                        h->last = b;
                    }
                } else {
                    b->next = 0;
                    b->prev = 0;
                }
                f->size = 0;
                if (f->next) {
                    f->next->prev = f->prev;
                }
                if (f->prev) {
                    f->prev->next = f->next;
                }
                if (h->first == f) {
                    h->first = f->prev;
                }
                if (h->last == f) {
                    if (f->prev) {
                        h->last = f->prev;
                    } else {
                        h->last = f->next;
                    }
                }
                f->next = 0;
                f->prev = 0;
                b->unk8 = (s32)f;
                nx = (B12HBlk *)f->unkC;
                b->unkC = (s32)nx;
                if (f->unkC) {
                    nx->unk8 = (s32)b;
                }
                f->unkC = (s32)b;
                return (B12HBlk *)((u8 *)b + 0x20);
            }
            f = f->prev;
        } while (f);
    }
    return 0;
}
