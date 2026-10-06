#ifndef DBGLINK_TYPES_H
#define DBGLINK_TYPES_H
#include "common.h"

/* dev-cart serial port (16550-style UART behind the PI bus) */
extern u8 D_8014D3E0;   /* shadow THR */
extern u8 D_8014D3E1;   /* shadow IER */
extern u8 D_8014D3E2;   /* shadow FCR */
extern u8 D_8014D3E3;   /* shadow LCR */
extern s32 D_8014D3E8;  /* timeout flag */
extern s32 D_800D3650;  /* outer timeout count */
extern u16 D_B2000000;
extern u16 D_B2000004;
extern u16 D_B2000008;
extern u16 D_B200000C;
extern u8 D_B2000001;
extern u16 D_B2000014;
extern u16 D_B2000018;
extern u16 D_B2000020;
extern u8 D_B2000011;
extern u8 D_B2000015;

/* Port helpers that the original compiled inline into the link functions
   (static inline copies of the out-of-line dbgPort* functions). */
static inline void dbgPortSetLineFormat_i(u8 v) {
    v |= (D_8014D3E3 & 0xF8);
    D_8014D3E3 = v;
    while (osPiGetStatus() & 3) {
    }
    D_B200000C = v;
}

static inline void dbgPortSetParityEnable_i(s32 v) {
    u8 tmp = (D_8014D3E3 & 0xF7) | (v << 3);
    D_8014D3E3 = tmp;
    while (osPiGetStatus() & 3) {
    }
    D_B200000C = tmp;
}

static inline void dbgPortSetIntRxData_i(u8 v) {
    v |= (D_8014D3E1 & 0xFE);
    D_8014D3E1 = v;
    while (osPiGetStatus() & 3) {
    }
    D_B2000004 = v;
}

static inline void dbgPortWriteData_i(u8 data) {
    D_8014D3E0 = data;
    while (osPiGetStatus() & 3) {
    }
    D_B2000000 = data;
}

static inline u8 dbgPortReadData_i(void) {
    while (osPiGetStatus() & 3) {
    }
    return D_B2000001;
}

/* poll a UART register byte until (reg & mask) == want, with timeout */
static inline s32 dbgPortWaitRegMask_i(u8 *reg, u8 mask, u8 want, s32 cnt) {
    s32 ret = 0;
    s32 outer = D_800D3650;
    s32 c = cnt;
    for (;;) {
        while (osPiGetStatus() & 3) {
        }
        if (((*reg) & mask) == want) {
            ret = 1;
            goto done;
        }
        if (c-- == 0) {
            outer--;
            c = cnt;
        }
        if (outer <= 0) break;
    }
    D_8014D3E8 = 1;
done:
    return ret;
}

static inline s32 dbgPortWaitDataReady_i(u8 v) {
    return dbgPortWaitRegMask_i(&D_B2000015, 1, v, 0x4E20);
}

static inline void dbgPortSetIntModemStatus_i(s32 v) {
    u8 tmp = (D_8014D3E1 & 0xF7) | (v << 3);
    D_8014D3E1 = tmp;
    while (osPiGetStatus() & 3) {
    }
    D_B2000004 = tmp;
}

static inline void dbgPortSetFifoRxReset_i(s32 v) {
    u8 tmp = (D_8014D3E2 & 0xFD) | (v << 1);
    D_8014D3E2 = tmp;
    while (osPiGetStatus() & 3) {
    }
    D_B2000008 = tmp;
}

static inline void dbgPortWriteReg_i(u16 *reg, u8 val) {
    while (osPiGetStatus() & 3) {
    }
    *reg = val & 0xFF;
}

static inline u8 dbgPortReadReg_i(u16 *reg) {
    u8 r;
    while (osPiGetStatus() & 3) {
    }
    r = ((u8 *)reg)[1];
    return r;
}

static inline s32 dbgPortWaitTxEmpty_i(u8 v) {
    return dbgPortWaitRegMask_i(&D_B2000015, 0x40, v << 6, 0x4E20);
}

static inline s32 dbgPortWaitModemBit6_i(u8 v) {
    return dbgPortWaitRegMask_i(&D_B2000011, 0x40, v << 6, 0x4E20);
}

/* byte-level link primitives */
extern s32 dbgLinkRecvByte(u8 *out);
extern s32 dbgLinkSendByte(u8 b);
extern s32 dbgLinkSendBlock(u8 *buf, s32 len);
extern s32 dbgLinkRecvBlock(u8 *buf, s32 len, u32 *sum);

/* call hook invoked by server cmd 0x23 */
extern s32 (*D_800D364C)(u32 arg);

/* the half/word helpers were also compiled inline into the command handlers */
static inline s32 dbgLinkRecvHalf_i(u16 *out) {
    u8 b;
    u16 v;
    s32 ret = 0;
    dbgLinkRecvByte(&b);
    if (D_8014D3E8 == 0) {
        v = b << 8;
        dbgLinkRecvByte(&b);
        if (D_8014D3E8 == 0) {
            v |= b;
            ret = 1;
            *out = v;
        }
    }
    return ret;
}

static inline s32 dbgLinkRecvWord_i(u32 *out) {
    u8 b;
    u32 v;
    s32 ret = 0;
    dbgLinkRecvByte(&b);
    if (D_8014D3E8 == 0) {
        v = b << 8;
        dbgLinkRecvByte(&b);
        if (D_8014D3E8 == 0) {
            v |= b;
            v <<= 8;
            dbgLinkRecvByte(&b);
            if (D_8014D3E8 == 0) {
                v |= b;
                v <<= 8;
                dbgLinkRecvByte(&b);
                if (D_8014D3E8 == 0) {
                    v |= b;
                    ret = 1;
                    *out = v;
                }
            }
        }
    }
    return ret;
}

static inline s32 dbgLinkSendHalf_i(u16 v) {
    s32 ret = 0;
    dbgLinkSendByte((v >> 8) & 0xFF);
    if (D_8014D3E8 == 0) {
        dbgLinkSendByte(v & 0xFF);
        ret = D_8014D3E8 == 0;
    }
    return ret;
}

static inline s32 dbgLinkSendWord_i(u32 v) {
    s32 ret = 0;
    dbgLinkSendByte(v >> 24);
    if (D_8014D3E8 == 0) {
        dbgLinkSendByte((v >> 16) & 0xFF);
        if (D_8014D3E8 == 0) {
            dbgLinkSendByte((v >> 8) & 0xFF);
            if (D_8014D3E8 == 0) {
                dbgLinkSendByte(v & 0xFF);
                ret = D_8014D3E8 == 0;
            }
        }
    }
    return ret;
}

static inline void dbgPortSetIntLineStatus_i(s32 v) {
    u8 tmp = (D_8014D3E1 & 0xFB) | (v << 2);
    D_8014D3E1 = tmp;
    while (osPiGetStatus() & 3) {
    }
    D_B2000004 = tmp;
}

static inline s32 dbgPortWaitOverrun_i(u8 v) {
    return dbgPortWaitRegMask_i(&D_B2000015, 2, v << 1, 0x4E20);
}

/* client side of the link handshake: send 0x10, expect 0x11 */
static inline s32 dbgLinkHandshake_i(void) {
    u8 b;
    s32 ret = 0;
    dbgLinkSendByte(0x10);
    if (D_8014D3E8 == 0) {
        dbgLinkRecvByte(&b);
        if (D_8014D3E8 == 0) {
            ret = b == 0x11;
        }
    }
    return ret;
}

static inline s32 dbgLinkSendString_i(u8 *s) {
    s32 ret = 0;
    u8 c;
    do {
        c = *s++;
        dbgLinkSendByte(c);
        if (D_8014D3E8 != 0) goto end;
    } while (c != 0);
    ret = 1;
end:
    return ret;
}

static inline void dbgPortSetFifoTrigger_i(s32 v) {
    u8 tmp = (D_8014D3E2 & 0xBF) | (v << 6);
    D_8014D3E2 = tmp;
    while (osPiGetStatus() & 3) {
    }
    D_B2000008 = tmp;
}

#endif
