#include "p2_types.h"

/* PARTIAL: identical except s0/s1 swapped (pages vs n callee-saved register assignment) */
extern char D_800C86F0[];
extern OSMesgQueue D_80103254;
MemBlk *func_002533DC(s32 a, s32 size, s32 b, char *name);

OSMesg func_0023C77C(u32 size, s32 unused, s32 a2) {
    OSMesgQueue mq;
    AllocMsg msg;
    OSMesg buf;
    OSMesg reply;
    MemBlk *blk;
    u32 pages = (size + 0xFFF) >> 12;
    u32 n = (pages + 1) & ~1;
    u32 hdr = n + 0x18;

    osCreateMesgQueue(&mq, &buf, 1);
    msg.type = 3;
    msg.size = size;
    msg.mq = &mq;
    blk = func_002533DC(0, (pages << 2) + hdr, 3, D_800C86F0);
    msg.hdr = blk->data;
    msg.hdr->blk = blk;
    msg.hdr->f8 = a2;
    osSendMesg(&D_80103254, &msg, 1);
    osRecvMesg(&mq, &reply, 1);
    return reply;
}