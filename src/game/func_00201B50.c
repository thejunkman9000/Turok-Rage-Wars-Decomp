#include "b01_types.h"

extern s32 D_800CD394;
extern OSMesgQueue D_800F6F40;
extern OSMesgQueue D_800F7110;
s32 func_00200500(void);
void func_00200538(s32 mask);
void func_00200D18(u32 dst, u8 *src, u32 n);
s32 func_002016DC(u8 *s);
s32 func_002017E8(u32 a0, u32 a1, u32 a2, u32 a3);

/* send a block to the cartridge-side device (command 0x202) */
s32 func_00201B50(u8 *src, s32 arg) {
    B01IoReq req;
    s32 reply;
    s32 len;
    s32 mask;

    len = func_002016DC(src);
    if (D_800CD394 == 2) {
        req.w0 = (s32)src;
        req.w4 = len;
        req.w8 = 1;
        req.wC.i = 0x80000202;
        req.w10 = len;
        req.w14 = arg;
        req.w18 = 0;
        req.reply = &D_800F7110;
        osSendMesg(&D_800F6F40, &req, 1);
        osRecvMesg(&D_800F7110, (OSMesg *)&reply, 1);
        if (reply & 0x8000) {
            reply |= 0xFFFF0000;
        }
    } else {
        mask = func_00200500();
        len = func_002016DC(src);
        func_00200D18(0xB1FF0000, src, len);
        reply = func_002017E8(0x202, len, arg, 0);
        if (reply & 0x8000) {
            reply |= 0xFFFF0000;
        }
        func_00200538(mask);
    }
    return reply;
}
