#include "b12_types.h"
#include "libaudio.h"

void dbgLinkServerLoop(OSMesgQueue *q);
s32 func_002955C8(void);
void func_002566A8(B12Ctx *c, B12QNode *n);

void func_0025651C(B12Ctx *c) {
    OSMesgQueue *q = &c->q;
    OSTimer timer;
    B12QNode *n;
    OSMesg out;
    while (1) {
        osRecvMesg(q, (OSMesg *)&n, 1);
        if ((u32)n == 0xBEEFDEAD) {
            osSetTimer(&timer, 0, 0x393870, q, (OSMesg)0xDEADBEEF);
        } else if ((u32)n == 0xDEADBEEF) {
            if (func_002955C8()) {
                dbgLinkServerLoop(q);
            }
        } else {
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
}
