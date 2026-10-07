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

u32 func_00257210(s32 a0, s32 a1) {
    B12DbBlk *b;
    B12DbBlk *last = 0;
    s32 s2 = a0 + D_8010B6A0;
    s32 s0;
    s32 d;
    for (b = D_8010BDF4.first; b; b = b->next) {
        if ((u32)s2 < (u32)b->addr) {
            break;
        }
        last = b;
        if (!(b->addr + 0x300 < s2 + a1)) {
            b->stamp = D_800D0940;
            return osVirtualToPhysical((void *)(b->data + s2 - b->addr));
        }
    }
    b = D_8010BDF4.last;
    D_8010BDF4.last = b->next;
    alUnlink((ALLink *)b);
    if (last) {
        alLink((ALLink *)b, (ALLink *)last);
        s0 = s2 & 1;
    } else {
        last = D_8010BDF4.first;
        if (last) {
            D_8010BDF4.first = b;
            b->next = last;
            b->prev = 0;
            last->prev = b;
        } else {
            D_8010BDF4.first = b;
            b->next = 0;
            b->prev = 0;
        }
        s0 = s2 & 1;
    }
    s2 -= s0;
    b->addr = s2;
    b->stamp = D_800D0940;
    d = b->data;
    D_800D0944++;
    func_002563F4(D_801051B8, s2, 0x300, d, &D_8010BDD8, 0, 1);
    return osVirtualToPhysical((void *)d) + s0;
}
