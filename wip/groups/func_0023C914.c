#include "b09_types.h"

extern B09LoaderCtl D_80103720;
extern B09IoQ D_80103254;
extern u8 D_801051B8[];
extern u8 D_80156000[];
void func_0023CA14(void *);
void func_0023C1E0(B09LoadReq *);
void func_0023CE8C(B09LoadReq *);
void func_0023CCC4(B09LoadReq *);
void func_0023CDC4(B09LoadReq *);
void func_0025631C(u8 *, s32, s32, u8 *);

void func_0023C914(void) {
    B09LoadReq *req;
    memset(D_80103720.stack, 0x62, 0x200);
    osCreateThread(&D_80103720.thr, 0x62, func_0023CA14, 0, D_80103720.stack + 0x200, 0x94);
    osStartThread(&D_80103720.thr);
    for (;;) {
        osRecvMesg(&D_80103254.loadq, (OSMesg *)&req, 1);
        switch (req->type) {
        case 0:
            func_0023C1E0(req);
            break;
        case 1:
            func_0023CE8C(req);
            break;
        case 3:
            func_0023CDC4(req);
            break;
        case 2:
            func_0023CCC4(req);
            break;
        }
    }
}

void func_0023CA14(void *arg) {
    OSMesgQueue q;
    OSMesg buf[1];
    B09LoadReq *req;
    osCreateMesgQueue(&q, buf, 1);
    for (;;) {
        osRecvMesg(&D_80103254.dmaq, (OSMesg *)&req, 1);
        if (*req->data == 0xFF) {
            func_0025631C(D_801051B8, req->src, (req->len + 1) & ~1, D_80156000 + (req->node->id << 12));
            osInvalDCache(D_80156000 + (req->node->id << 12), 0x1000);
            osInvalICache(D_80156000 + (req->node->id << 12), 0x1000);
        }
        req->type = 1;
        osSendMesg(&D_80103254.loadq, (OSMesg)req, 1);
    }
}

void func_0023CAFC(B09List *l, B09LNode *n) {
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        l->head = n->next;
        n->next->prev = NULL;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    } else {
        l->tail = n->prev;
        n->prev->next = NULL;
    }
}
