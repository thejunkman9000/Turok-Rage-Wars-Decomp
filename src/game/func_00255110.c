#include "b12_types.h"

extern s32 D_800D2B28;
extern s32 D_800D2954;

s32 func_00255110(B12Port *p, B12Req *m) {
    OSMesgQueue q;
    OSMesg buf;
    OSMesg out;
    osCreateMesgQueue(&q, &buf, 1);
    m->reply = &q;
    D_800D2954 = 2;
    osSetThreadPri(&p->thread, D_800D2B28);
    osJamMesg(&p->q, m, 1);
    osRecvMesg(&q, &out, 1);
    return 1;
}
