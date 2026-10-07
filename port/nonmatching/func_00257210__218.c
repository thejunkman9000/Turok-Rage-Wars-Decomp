#include "b12_types.h"
#include "libaudio.h"

typedef struct B12DbBlk B12DbBlk;
struct B12DbBlk {
    /* 0x00 */ B12DbBlk *next;
    /* 0x04 */ B12DbBlk *prev;
    /* 0x08 */ s32 addr;
    /* 0x0C */ s32 stamp;
    /* 0x10 */ s32 data;
};

typedef struct B12DbList {
    B12DbBlk *first;
    B12DbBlk *last;
} B12DbList;

extern s32 D_8010B6A0;
extern B12DbList D_8010BDF4;
extern s32 D_800D0940;
extern s32 D_800D0944;
extern u8 D_801051B8[];
extern OSMesgQueue D_8010BDD8;
void func_002563F4(void *c, s32 src, s32 total, s32 dst, OSMesgQueue *reply, OSMesg replyMsg, s32 jam);

u32 func_00257210(s32 addr0, s32 len) {
    B12DbBlk *lastDmaPtr;
    B12DbBlk *dmaPtr;
    s32 addr;
    s32 addrEnd;
    s32 buffEnd;
    s32 delta;
    s32 freeBuffer;
    lastDmaPtr = 0;
    addr = addr0 + D_8010B6A0;
    dmaPtr = D_8010BDF4.first;
    addrEnd = addr + len;
    while (dmaPtr) {
        buffEnd = dmaPtr->addr + 0x300;
        if ((u32)addr < (u32)dmaPtr->addr) {
            break;
        } else if (addrEnd <= buffEnd) {
            dmaPtr->stamp = D_800D0940;
            return osVirtualToPhysical((void *)(dmaPtr->data + addr - dmaPtr->addr));
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = dmaPtr->next;
    }
    dmaPtr = D_8010BDF4.last;
    D_8010BDF4.last = dmaPtr->next;
    alUnlink((ALLink *)dmaPtr);
    if (lastDmaPtr) {
        alLink((ALLink *)dmaPtr, (ALLink *)lastDmaPtr);
    } else if (D_8010BDF4.first) {
        lastDmaPtr = D_8010BDF4.first;
        D_8010BDF4.first = dmaPtr;
        dmaPtr->next = lastDmaPtr;
        dmaPtr->prev = 0;
        lastDmaPtr->prev = dmaPtr;
    } else {
        D_8010BDF4.first = dmaPtr;
        dmaPtr->next = 0;
        dmaPtr->prev = 0;
    }
    do {
        delta = addr & 1;
    } while (0);
    addr -= delta;
    dmaPtr->addr = addr;
    dmaPtr->stamp = D_800D0940;
    freeBuffer = dmaPtr->data;
    D_800D0944++;
    func_002563F4(D_801051B8, addr, 0x300, freeBuffer, &D_8010BDD8, 0, 1);
    return osVirtualToPhysical((void *)freeBuffer) + delta;

}