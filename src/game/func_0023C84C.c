#include "b09_types.h"

extern OSMesgQueue D_80103254;
void func_002537D8(s32, s32);

typedef struct B09Req {
    /* 0x00 */ s16 type;
    /* 0x02 */ u8 pad2[2];
    /* 0x04 */ s32 arg;
    /* 0x08 */ OSMesgQueue *reply;
} B09Req;

typedef struct B09Reply {
    u8 pad0[0xC];
    s32 unkC;
} B09Reply;

void func_0023C84C(s32 arg) {
    OSMesgQueue mq;
    OSMesg buf[1];
    B09Req req;
    B09Reply *reply;
    osCreateMesgQueue(&mq, buf, 1);
    req.arg = arg;
    req.type = 2;
    req.reply = &mq;
    osSendMesg(&D_80103254, (OSMesg)&req, 1);
    osRecvMesg(&mq, (OSMesg *)&reply, 1);
    func_002537D8(0, reply->unkC);
}
