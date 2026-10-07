#include "p2_types.h"
extern char D_800C86F0[];
extern OSMesgQueue D_80103254;
MemBlk *func_002533DC(s32 a, s32 size, s32 b, char *name);
OSMesg func_0023C77C(u32 size, s32 unused, s32 a2) {
    OSMesgQueue mq;
    AllocMsg msg;
    OSMesg buf;
    OSMesg reply;
    MemBlk *blk;
    u32 pages;
    u32 new_var;
    u32 n;
    u32 hdr;
    pages = (size + 0xFFF) >> 12;
    n = (pages + 1) & ~1;
    osCreateMesgQueue(&mq, &buf, 1);
    new_var = pages << 2;
    hdr = n + 0x18;
    msg.type = 3;
    msg.size = size;
    msg.mq = &mq;
    blk = func_002533DC(0, new_var + hdr, 3, D_800C86F0);
    msg.hdr = blk->data;
    msg.hdr->blk = blk;
    msg.hdr->f8 = a2;
    osSendMesg(&D_80103254, &msg, 1);
    osRecvMesg(&mq, &reply, 1);
    return reply;
}
