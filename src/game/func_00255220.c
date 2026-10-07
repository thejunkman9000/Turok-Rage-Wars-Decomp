#include "b12_types.h"

extern s32 D_800D2978;

void func_00255220(B12Port *p) {
    B12Req *r;
    while (1) {
        osRecvMesg(&p->q, (OSMesg *)&r, 1);
        p->unk1448 = D_800D2978;
        r->fn(r->arg, r);
        osSendMesg(r->reply, r, 1);
    }
}
