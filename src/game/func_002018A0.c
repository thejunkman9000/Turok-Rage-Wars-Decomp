#include "b01_types.h"

extern s32 D_800CD390;
extern OSMesgQueue D_800F5C90;
extern OSMesgQueue D_800F6F40;
void func_00200568(u32 addr, u32 val);
u32 func_002005A0(u32 addr);
void func_0020095C(u32 dst, u8 *src, u32 n);
void func_00200E04(u32 dst, u8 *src, u32 n);

/* I/O thread: serve requests sent through D_800F6F40 (write block / program transfer / read block / reply) */
void func_002018A0(void *arg) {
    B01IoReq *req;
    u32 len;

    for (;;) {
        osRecvMesg(&D_800F6F40, (OSMesg *)&req, 1);
        if (req->w4 != 0 && req->w8 == 1) {
            if (req->wC.i & 0x80000000) {
                D_800CD390 = 0;
            }
            func_00200E04(0xB1FF0000, (u8 *)req->w0, req->w4);
            if (req->wC.i & 0x80000000) {
                D_800CD390 = 1;
            }
        }
        osRecvMesg(&D_800F5C90, 0, 0);
        func_00200568(0xB1FFFFE4, req->w10);
        func_00200568(0xB1FFFFE8, req->w14);
        func_00200568(0xB1FFFFEC, req->w18);
        func_00200568(0xB1FFFFD8, 0x1010101);
        func_00200568(0xB1FFFFE0, req->wC.h.cmd);
        osRecvMesg(&D_800F5C90, 0, 1);
        if (req->w4 != 0 && req->w8 == 0) {
            len = func_002005A0(0xB1FFFFDC);
            if (len != 0) {
                if (req->wC.i & 0x80000000) {
                    D_800CD390 = 0;
                }
                func_0020095C(0xB1FF0000, (u8 *)req->w0, len);
                if (req->wC.i & 0x80000000) {
                    D_800CD390 = 1;
                }
            }
        }
        if (req->reply != NULL) {
            osSendMesg(req->reply, (OSMesg)func_002005A0(0xB1FFFFDC), 1);
        }
    }
}
