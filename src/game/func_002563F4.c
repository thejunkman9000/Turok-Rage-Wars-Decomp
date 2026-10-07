#include "b12_types.h"

B12QNode *func_0025663C(B12Ctx *c);

void func_002563F4(B12Ctx *c, u32 src, u32 total, u32 dst, OSMesgQueue *reply, OSMesg replyMsg, s32 jam) {
    B12QNode *n;
    u32 rem;
    u32 chunk;
    if (jam) {
        n = func_0025663C(c);
        if (n) {
            n->src = src;
            n->dst = dst;
            n->len = total;
            n->reply = reply;
            n->replyMsg = replyMsg;
            osJamMesg(&c->q, n, 1);
        }
    } else {
        rem = total;
        do {
            n = func_0025663C(c);
            if (!n) {
                break;
            }
            n->src = src + (total - rem);
            n->dst = dst + (total - rem);
            chunk = 0x2000;
            if (rem <= 0x2000) {
                chunk = rem;
            }
            rem -= chunk;
            n->len = chunk;
            if (rem != 0) {
                n->reply = 0;
                n->replyMsg = 0;
            } else {
                n->reply = reply;
                n->replyMsg = replyMsg;
            }
            osSendMesg(&c->q, n, 1);
        } while (n && rem != 0);
    }
}
