#include "dbglink_types.h"

extern void func_002AE260(void);
extern u32 osSetIntMask(u32 mask);
extern void osWritebackDCacheAll(void);
extern s32 dbgLinkCmdSendVersion(void);
extern s32 dbgLinkCmdWriteBlock(void);
extern s32 dbgLinkCmdReadBlock(void);
extern s32 dbgLinkCmdReadHalf(void);
extern s32 dbgLinkCmdReadWord(void);
extern s32 dbgLinkCmdWriteHalf(void);
extern s32 dbgLinkCmdWriteWord(void);
extern s32 dbgLinkCmdLoadProgram(void);
extern s32 dbgLinkCmdCallHook(void);

void dbgLinkServerLoop(void) {
    u8 cmd;
    u32 addr1;
    u8 b1;
    u32 addr2;
    u8 b2;
    u32 addr3;
    u8 b3;
    u8 b4;
    u32 *p;
    u32 v;
    void (*fn)(void);
    func_002AE260();
    dbgPortSetFifoTrigger_i(1);
    while (dbgLinkRecvByte(&cmd)) {
        if (cmd != 0x10) continue;
        if (!dbgLinkSendByte(0x11)) continue;
        if (!dbgLinkRecvByte(&cmd)) continue;
        switch (cmd) {
        case 0x20:
            dbgLinkCmdSendVersion();
            break;
        case 0x43:
            dbgLinkCmdWriteBlock();
            break;
        case 0x47:
            dbgLinkCmdReadBlock();
            break;
        case 0x44:
            p = &addr1;
            dbgLinkRecvByte(&b1);
            if (D_8014D3E8 == 0) {
                v = b1 << 8;
                dbgLinkRecvByte(&b1);
                if (D_8014D3E8 == 0) {
                    v |= b1;
                    v <<= 8;
                    dbgLinkRecvByte(&b1);
                    if (D_8014D3E8 == 0) {
                        v |= b1;
                        v <<= 8;
                        dbgLinkRecvByte(&b1);
                        if (D_8014D3E8 == 0) {
                            v |= b1;
                            *p = v;
                            dbgLinkSendByte(*(u8 *)addr1);
                        }
                    }
                }
            }
            break;
        case 0x45:
            dbgLinkCmdReadHalf();
            break;
        case 0x46:
            dbgLinkCmdReadWord();
            break;
        case 0x22:
            p = &addr2;
            dbgLinkRecvByte(&b2);
            if (D_8014D3E8 == 0) {
                v = b2 << 8;
                dbgLinkRecvByte(&b2);
                if (D_8014D3E8 == 0) {
                    v |= b2;
                    v <<= 8;
                    dbgLinkRecvByte(&b2);
                    if (D_8014D3E8 == 0) {
                        v |= b2;
                        v <<= 8;
                        dbgLinkRecvByte(&b2);
                        if (D_8014D3E8 == 0) {
                            v |= b2;
                            *p = v;
                            fn = (void (*)(void))addr2;
                            if (fn != 0) {
                                osSetIntMask(1);
                                osWritebackDCacheAll();
                                osInvalICache((void *)0x80000000, 0x800000);
                                fn();
                            }
                        }
                    }
                }
            }
            break;
        case 0x40:
            p = &addr3;
            dbgLinkRecvByte(&b3);
            if (D_8014D3E8 == 0) {
                v = b3 << 8;
                dbgLinkRecvByte(&b3);
                if (D_8014D3E8 == 0) {
                    v |= b3;
                    v <<= 8;
                    dbgLinkRecvByte(&b3);
                    if (D_8014D3E8 == 0) {
                        v |= b3;
                        v <<= 8;
                        dbgLinkRecvByte(&b3);
                        if (D_8014D3E8 == 0) {
                            v |= b3;
                            *p = v;
                            dbgLinkRecvByte(&b4);
                            if (D_8014D3E8 == 0) {
                                *(u8 *)addr3 = b4;
                            }
                        }
                    }
                }
            }
            break;
        case 0x41:
            dbgLinkCmdWriteHalf();
            break;
        case 0x42:
            dbgLinkCmdWriteWord();
            break;
        case 0x18:
            dbgLinkCmdLoadProgram();
            break;
        case 0x23:
            dbgLinkCmdCallHook();
            break;
        }
    }
}
