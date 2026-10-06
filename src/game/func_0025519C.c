#include "b12_types.h"

s32 func_0025519C(B12Port *p, B12Req *msg, OSMesgQueue *reply) {
    msg->reply = reply;
    return osSendMesg(&p->q, msg, 0) != -1;
}
