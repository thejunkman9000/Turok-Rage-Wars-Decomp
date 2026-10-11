#include "b01_types.h"

extern s32 D_800CD394;
extern OSMesgQueue D_800F6F40;
extern OSMesgQueue D_800F7110;
s32 func_00200500(void);
void func_00200538(s32 mask);
void func_00200880(u32 src, u8 *dst, u32 n);
s32 func_002017E8(u32 a0, u32 a1, u32 a2, u32 a3);

/* read n bytes from the device into RAM in chunks of at most 0x8000 (command 0x505); returns bytes read */
s32 func_00201E94(s32 arg, u8 *buf, u32 n) {
    B01IoReq req;
    s32 reply;
    s32 done = 0;
    s32 mask;
    u32 chunk;

    if (D_800CD394 == 2) {
        while (n != 0) {
            chunk = n;
            if (chunk > 0x8000) {
                chunk = 0x8000;
            }
            req.w0 = (s32)buf;
            req.w4 = 1;
            req.w8 = 0;
            req.wC.i = 0x80000505;
            req.w10 = arg;
            req.w14 = chunk;
            req.w18 = 0;
            req.reply = &D_800F7110;
            osSendMesg(&D_800F6F40, &req, 1);
            osRecvMesg(&D_800F7110, (OSMesg *)&reply, 1);
            if (reply == 0) {
                return done;
            }
            buf += reply;
            n -= reply;
            done += reply;
        }
    } else {
        mask = func_00200500();
        while (n != 0) {
            chunk = n;
            if (chunk > 0x8000) {
                chunk = 0x8000;
            }
            reply = func_002017E8(0x505, arg, chunk, 0);
            if (reply == 0) {
                break;
            }
            func_00200880(0xB1FF0000, buf, reply);
            buf += reply;
            n -= reply;
            done += reply;
        }
        func_00200538(mask);
    }
    return done;
}
