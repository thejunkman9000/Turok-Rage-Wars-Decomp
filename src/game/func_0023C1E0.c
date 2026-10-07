#include "m03_ldr.h"

extern M03Ldr D_80103230;
extern B09List D_80103E20;
extern s32 D_800D0638;
OSThread *__osGetCurrFaultedThread(void);
OSTime osGetTime(void);
void osWritebackDCacheAll(void);
u32 osSetIntMask(u32 m);
void func_0023BD24(s16 slot, B09LNode *n, s32 a2, u8 *pair);
void func_0023C074(B09LNode *n);
M03Region *func_0023CBB0(u16 slot);

static inline void m03_unlink(B09LNode *n) {
    if (n->prev != NULL) {
        n->prev->next = n->next;
    } else {
        D_80103E20.head = n->next;
        n->next->prev = NULL;
    }
    if (n->next != NULL) {
        n->next->prev = n->prev;
    } else {
        D_80103E20.tail = n->prev;
        n->prev->next = NULL;
    }
}

static inline void m03_push(B09LNode *n) {
    n->next = NULL;
    n->prev = D_80103E20.tail;
    if (D_80103E20.tail != NULL) {
        D_80103E20.tail->next = n;
    }
    D_80103E20.tail = n;
    if (D_80103E20.head == NULL) {
        D_80103E20.head = n;
    }
}

void func_0023C1E0(void) {
    OSThread *t;
    M03Region *r;
    B09LNode *n;
    B09LoadReq *req;
    M03Region *rr;
    u8 *pair;
    u32 page;
    s32 cause;
    OSTime t0;
    f32 us;
    M03Region *found;

    t = __osGetCurrFaultedThread();
    cause = t->context.cause & 0x7C;
    if (cause == 4 || cause == 8) {
        D_80103230.faults += 1;
        page = t->context.badvaddr >> 12;
        for (r = &D_80103230.region; r != NULL; r = r->next) {
            if (!(page < r->base) && page < (u32)(r->base + r->size)) {
                break;
            }
        }
        found = r;
        if (found != NULL) {
            D_80103230.lastAddr = t->context.badvaddr;
            pair = found->data + (page - found->base);
            if (*pair != 0xFF) {
                n = &D_80103230.slot[*pair];
                if (n->tlb == 0xFF) {
                    m03_unlink(n);
                    func_0023BD24(page, n, *((u8 *)t + 0x17), pair);
                    m03_push(n);
                }
                t->flags = 2;
                osStartThread(t);
                return;
            }
            osRecvMesg(&D_80103230.freeq, (OSMesg *)&req, 1);
            D_80103230.loads = D_80103230.loads + 1;
            req->src = found->romAddr + ((page - found->base) << 12);
            req->len = 0x1000;
            n = D_80103E20.head;
            m03_unlink(n);
            func_0023C074(n);
            if (n->slot != 0xFFFF) {
                rr = func_0023CBB0(n->slot);
                rr->data[n->slot - rr->base] = 0xFF;
                n->slot = 0xFFFF;
            }
            n->unkC = 0;
            req->node = n;
            req->slot = page;
            req->data = pair;
            req->task = (B09TaskBlk *)t;
            osSendMesg(&D_80103230.dmaq, req, 1);
            return;
        }
        t0 = osGetTime();
        do {
            us = (f32)(u64)(((osGetTime() - t0) << 6) / 3000);
        } while (us * 1e-6f < 2.0f);
    } else {
        t0 = osGetTime();
        do {
            us = (f32)(u64)(((osGetTime() - t0) << 6) / 3000);
        } while (us * 1e-6f < 2.0f);
    }
    osWritebackDCacheAll();
    osSetIntMask(1);
    ((void (*)())0x80000400)();
    D_800D0638 = -1;
    t->flags = 2;
    osStartThread(t);
}


