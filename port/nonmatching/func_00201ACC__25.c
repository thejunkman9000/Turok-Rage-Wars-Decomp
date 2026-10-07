#include "b01_types.h"

extern s32 D_800CD394;
extern OSMesgQueue D_800F6F40;
extern OSMesgQueue D_800F7110;
void func_002016FC(s32 arg);

s32 func_00201ACC(void) {
    B01IoReq req;
    OSMesg reply;

    D_800CD394 = 2;
    func_002016FC(0xFF);
    req.w4 = 0;
    req.wC.i = 0x80000101;
    req.w10 = 0;
    req.w14 = 0;
    req.w18 = 0;
    req.reply = &D_800F7110;
    osSendMesg(&D_800F6F40, &req, 1);
    osRecvMesg(&D_800F7110, &reply, 1);
    return (s32)reply;
}
