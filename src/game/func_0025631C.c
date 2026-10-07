#include "b12_types.h"

B12QNode *func_0025663C(B12Ctx *c);

void func_0025631C(B12Ctx *c, u32 src, u32 total, u32 dst) {
    OSMesgQueue q;
    OSMesg buf;
    OSMesg out;
    u32 rem;
    u32 chunk;
    B12QNode *n;
    osCreateMesgQueue(&q, &buf, 1);
    rem = total;
    do {
        n = func_0025663C(c);
        if (!n) {
            return;
        }
        n->src = src + (total - rem);
        n->dst = dst + (total - rem);
        chunk = 0x2000;
        if (rem <= 0x2000) {
            chunk = rem;
        }
        n->len = chunk;
        n->reply = &q;
        osJamMesg(&c->q, n, 1);
        osRecvMesg(&q, &out, 1);
        rem -= chunk;
    } while (rem != 0);
}
