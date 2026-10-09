#include "b12_types.h"
#include "libaudio.h"

void dbgLinkServerLoop();
s32 func_002955C8(void);
void func_002566A8(B12Ctx *c, B12QNode *n);

void func_0025651C(B12Ctx *c) {
    OSMesgQueue *q = &c->q;
    OSTimer timer;
    B12QNode *n;
    OSMesg out;
    u32 mA = 0xBEEFDEAD;
    u32 mB = 0xDEADBEEF;
again:
    {
        osRecvMesg(q, (OSMesg *)&n, 1);
        if ((u32)n == mA) {
            do {
                osSetTimer(&timer, 0, 0x393870, q, (OSMesg)mB);
            } while (0);
        } else if ((u32)n == mB) {
            if (func_002955C8()) {
                dbgLinkServerLoop();
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
    goto again;
}