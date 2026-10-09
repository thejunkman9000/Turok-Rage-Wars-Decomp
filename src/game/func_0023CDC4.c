#include "b09_types.h"

extern B09Region D_80103F88;

void func_0023CDC4(B09RegReq *req) {
    B09Region *r;
    B09Region *last;
    B09Region *n;
    u32 base;
    s32 pages;
    s32 cnt;
    u8 *p;
    s32 i;

    base = 0;
    pages = (req->bytes + 0xFFF) / 0x1000;
    r = &D_80103F88;
    last = NULL;
    n = req->node;
    n->data = (u8 *)n + 0x18;
    cnt = (pages + 1) & ~1;
    while (r != NULL) {
        last = r;
        r = last->next;
        base = last->base + last->size;
    }
    if (base & 1) {
        base++;
    }
    if (base < 0x800) {
        base = 0x800;
    }
    i = cnt - 1;
    __asm__ ("" : "+r"(i));
    n->base = base;
    n->size = pages;
    n->next = NULL;
    last->next = n;
    p = n->data;
    if (cnt != 0) {
        do {
            *p++ = 0xFF;
        } while (i--);
    }
    osSendMesg(req->reply, (OSMesg)(base << 12), 1);
}
