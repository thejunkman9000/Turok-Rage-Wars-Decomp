#include "b09_types.h"

extern B09Region D_80103F88;
extern B09LNode D_80103B50[];
void func_0023C074(B09LNode *);

void func_0023CCC4(B09FreeReq *req) {
    B09Region *r;
    B09Region *prev;
    u8 *p;
    s32 i;
    u32 page;

    r = &D_80103F88;
    page = (u32)req->addr >> 12;
    prev = NULL;
    for (; r != NULL; r = r->next) {
        if (r->base == page) {
            break;
        }
        prev = r;
    }
    prev->next = r->next;
    p = r->data;
    for (i = 0; i < r->size; i++) {
        if (*p != 0xFF) {
            func_0023C074(&D_80103B50[*p]);
            D_80103B50[*p].slot = 0xFFFF;
        }
        p++;
    }
    osSendMesg(req->reply, (OSMesg)r, 1);
}
