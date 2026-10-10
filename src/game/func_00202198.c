#include "p1_types.h"
extern s32 D_800CD394;
extern OSMesgQueue D_800F6F40;
extern OSMesgQueue D_800F7110;
s32 func_00200500();
void func_00200538(s32 mask);
s32 func_002017E8(s32 a, s32 b, s32 c, s32 d);
s32 func_00202198(s32 a0, s32 a1, s32 a2) {
    IoReq req;
    s32 result;
    s32 mask;
    if (D_800CD394 == 2) {
        req.unk4 = 0;
        req.cmd = 0x80000707;
        req.a0 = a0;
        req.a1 = a1;
        req.a2 = a2;
        req.reply = &D_800F7110;
        osSendMesg(&D_800F6F40, &req, 1);
        osRecvMesg(&D_800F7110, (OSMesg *)&result, 1);
    } else {
        mask = func_00200500();
        result = func_002017E8(0x707, a0, a1, a2);
        func_00200538(mask);
    }
    return result;
}
