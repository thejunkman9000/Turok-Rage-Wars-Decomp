#include "b01_types.h"

/* request block sent to the I/O thread (same layout as in func_00201ACC) */
typedef struct B01IoReq {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    OSMesgQueue *reply;
} B01IoReq;

extern s32 D_800CD394;
extern OSMesgQueue D_800F6F40;
extern OSMesgQueue D_800F7110;
s32 func_00200500(void);
void func_00200538(s32 mask);
s32 func_002017E8(u32 a0, u32 a1, u32 a2, u32 a3);

s32 func_00201DB0(s32 arg) {
    B01IoReq req;
    s32 reply;
    s32 mask;

    if (D_800CD394 == 2) {
        req.w4 = 0;
        req.wC = 0x80000404;
        req.w10 = arg;
        req.w14 = 0;
        req.w18 = 0;
        req.reply = &D_800F7110;
        osSendMesg(&D_800F6F40, &req, 1);
        osRecvMesg(&D_800F7110, (OSMesg *)&reply, 1);
        if (reply & 0x8000) {
            reply |= 0xFFFF0000;
        }
    } else {
        mask = func_00200500();
        reply = func_002017E8(0x404, arg, 0, 0);
        if (reply & 0x8000) {
            reply |= 0xFFFF0000;
        }
        func_00200538(mask);
    }
    return reply;
}
