#ifndef M03_LDR_H
#define M03_LDR_H
#include "common.h"
#include "b09_types.h"
/* loader state block (func_0023B9A0 initialises it): starts at D_80103230, 0xD78 bytes */
typedef struct M03Region {
    /* 0x00 */ struct M03Region *next;
    /* 0x04 */ u16 base;
    /* 0x06 */ u16 size;
    /* 0x08 */ u32 romAddr;
    /* 0x0C */ u8 padC[4];
    /* 0x10 */ u8 *data;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ u16 mapped;
    /* 0x1A */ u16 mappedB;
} M03Region;
typedef struct M03Ldr {
    /* 0x000 */ u32 faults;
    /* 0x004 */ u32 loads;
    /* 0x008 */ u32 lastAddr;
    /* 0x00C */ u8 pad0C[0x14];
    /* 0x020 */ u16 evt;
    /* 0x022 */ u8 pad22[2];
    /* 0x024 */ OSMesgQueue loadq;
    /* 0x03C */ OSMesg loadbuf[0x21];
    /* 0x0C0 */ OSThread thr;
    /* 0x270 */ u8 pad270[0x80];
    /* 0x2F0 */ u8 stack[0x200];
    /* 0x4F0 */ B09LoaderCtl ctl;
    /* 0x920 */ B09LNode slot[24];
    /* 0xAA0 */ OSMesgQueue freeq;
    /* 0xAB8 */ OSMesg freebuf[8];
    /* 0xAD8 */ OSMesgQueue dmaq;
    /* 0xAF0 */ OSMesg dmabuf[8];
    /* 0xB10 */ B09LoadReq req[8];
    /* 0xBF0 */ B09List list;
    /* 0xBF8 */ u8 tlbfree[0x100];
    /* 0xCF8 */ B09SlotA tlbslot[24];
    /* 0xD58 */ M03Region region;
    /* 0xD74 */ u8 padD74[4];
} M03Ldr;
#endif
