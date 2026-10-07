#include "b12_types.h"

B12HBlk *func_002559D4(B12Heap *h, u32 size) {
    B12HBlk *f;
    B12HBlk *b;
    B12HBlk *nx;
    u32 need = (size + 0x2F) & ~0xF;
    f = h->last;
    if (f) {
        do {
            if (f->size >= need) {
                b = (B12HBlk *)((u8 *)f + f->hdr + f->size - need);
                b->hdr = need;
                b->size = 0;
                f->size -= need;
                b->prev = 0;
                b->next = 0;
                if (f->size == 0) {
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
                }
                b->unk8 = (s32)f;
                nx = (B12HBlk *)f->unkC;
                b->unkC = (s32)nx;
                if (f->unkC) {
                    nx->unk8 = (s32)b;
                }
                f->unkC = (s32)b;
                return (B12HBlk *)((u8 *)b + 0x20);
            }
            f = f->next;
        } while (f);
    }
    return 0;
}
