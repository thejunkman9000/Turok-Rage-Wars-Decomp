

#include "m03_ldr.h"

extern M03Ldr D_80103230;
void osMapTLB(s32 index, s32 pm, void *vaddr, u32 evenpaddr, u32 oddpaddr, s32 asid);
void osUnmapTLBAll();
extern u8 D_16E000[];
extern u8 D_52860[];
extern u8 D_801051B8[];
u32 func_00265370(void);
void func_0023CB50(B09List *l, B09LNode *n);
void func_0023C914(void *);
void func_0025631C(u8 *, u8 *, u8 *, u32);

#ifdef _MSC_VER
static inline u32 K0(void) { return 0x80000000u; }
#else
static inline u32 K0(void) { u32 k; __asm__("" : "=r"(k) : "0"(0x80000000)); return k; }
#endif
void func_0023B9A0(void) {
    u32 s4;
    u8 *p;
    u8 c;
    s32 n;
    u32 i;
    OSMesgQueue *fq;
    s4 = func_00265370() + K0();
    if (s4 <= 0x80400000U) {
        s4 = 0;
    }
    p = (u8 *)&D_80103230;
    n = 0xD77;
    do { *p++ = 0; } while (n--);
    c = 0xFF;
    p = D_80103230.tlbfree;
    n = 0xFF;
    do { *p++ = c; } while (n--);
    c = 0xFF;
    p = (u8 *)D_80103230.slot;
    n = 0x17F;
    do { *p++ = c; } while (n--);
    osUnmapTLBAll();
    for (i = 0; i < 0x18; i++) {
        D_80103230.tlbslot[i].key = 0xFFFF;
        D_80103230.tlbslot[i].a = 0xFF;
        D_80103230.tlbslot[i].b = 0xFF;
    }
    D_80103230.list.tail = NULL;
    D_80103230.list.head = NULL;
    for (i = 0; i < 0x18; i++) {
        D_80103230.slot[i].next = NULL;
        D_80103230.slot[i].prev = NULL;
        func_0023CB50(&D_80103230.list, &D_80103230.slot[i]);
        D_80103230.slot[i].id = i;
    }
    osCreateMesgQueue(&D_80103230.loadq, D_80103230.loadbuf, 0x21);
    osCreateMesgQueue(&D_80103230.freeq, D_80103230.freebuf, 8);
    osCreateMesgQueue(&D_80103230.dmaq, D_80103230.dmabuf, 8);
    D_80103230.region.base = 0x400;
    D_80103230.region.size = 0x100;
    D_80103230.region.data = D_80103230.tlbfree;
    D_80103230.region.next = NULL;
    D_80103230.region.romAddr = (u32)D_16E000 | 0xB0000000;
    D_80103230.region.mappedB = 0;
    if (func_00265370() > 0x4FFFFFU) {
        func_0025631C(D_801051B8, D_16E000, D_52860, s4);
    }
    if (s4 != 0) {
        osMapTLB(0, 0x1FE000, (void *)0x400000, s4 + K0(), -1, 7);
        D_80103230.region.mapped = 1;
        D_80103230.region.mappedB = 1;
    }
    for (i = 0; i < 8; i++) {
        osSendMesg(&D_80103230.freeq, &D_80103230.req[i], 1);
    }
    D_80103230.evt = 0;
    osSetEventMesg(0xC, &D_80103230.loadq, &D_80103230.evt);
    memset(D_80103230.stack, 0x63, 0x200);
    osCreateThread(&D_80103230.thr, 0x63, func_0023C914, 0, D_80103230.stack + 0x200, 0x93);
    osStartThread(&D_80103230.thr);
}

