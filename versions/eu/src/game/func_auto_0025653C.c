#include "b12_types.h"
#include "libaudio.h"

void func_002566A8(B12Ctx *c, B12QNode *n);

void func_auto_0025653C(B12Ctx *c) {
    B12QNode *n;
    OSMesg out;
    while (1) {
        osRecvMesg(&c->q, (OSMesg *)&n, 1);
        osWritebackDCache((void *)n->dst, n->len);
        osPiRawStartDma(0, n->src, (void *)n->dst, n->len);
        osRecvMesg(&c->q2, &out, 1);
        osInvalDCache((void *)n->dst, n->len);
        if (n->reply) {
            osSendMesg(n->reply, n->replyMsg, 1);
        }
        func_002566A8(c, n);
    }
}
