#include "b12_types.h"

extern s32 D_auto_800CE308;

void func_auto_00255240(B12Port *p) {
    B12Req *r;
    while (1) {
        osRecvMesg(&p->q, (OSMesg *)&r, 1);
        p->unk1448 = D_auto_800CE308;
        r->fn(r->arg, r);
        osSendMesg(r->reply, r, 1);
    }
}
