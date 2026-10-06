#ifndef B12_TYPES_H
#define B12_TYPES_H

#include "p1_types.h"
#include "p3_types.h"

/* Types recovered while matching batch 12 (main image 0x50CA4-0x57E10).  Padding arrays keep the offsets seen in the asm. */

/* class constants block (Obj.def) */
typedef struct B12Def {
    /* 0x00 */ u8 pad0[0xE];
    /* 0x0E */ s8 unkE;
    /* 0x0F */ s8 unkF;
    /* 0x10 */ u8 pad10[2];
    /* 0x12 */ s8 unk12;
    /* 0x13 */ u8 pad13[0x11];
    /* 0x24 */ u32 unk24;
} B12Def;

typedef struct B12Obj {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ B12Def *def;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ s32 *unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ u8 unk28[0x90];
    /* 0xB8 */ u8 unkB8[0x18];
    /* 0xD0 */ u32 unkD0;
    /* 0xD4 */ u8 padD4[4];
    /* 0xD8 */ u16 unkD8;
    /* 0xDA */ u8 unkDA;
    /* 0xDB */ u8 padDB;
    /* 0xDC */ u32 unkDC;
} B12Obj;

/* 0x28 byte node of the "package" tables: refcount at +8, flags at +0xC */
typedef struct B12Node B12Node;
struct B12Node {
    /* 0x00 */ u32 key;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 refs;
    /* 0x0C */ u32 flags;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ B12Node *link;
    /* 0x18 */ B12Node *link18;
    /* 0x1C */ u8 pad1C[0xC];
};

/* intrusive doubly linked list header (offsets of the link fields inside the elements) */
typedef struct B12List {
    /* 0x00 */ u8 *head;
    /* 0x04 */ u8 *tail;
    /* 0x08 */ s32 prevOff;
    /* 0x0C */ s32 nextOff;
    /* 0x10 */ s32 count;
} B12List;

/* node pool manager at D_80103F70: list of nodes at +0x600, running stamp at +0x1210 */
typedef struct B12Pool {
    /* 0x000 */ u8 pad0[0x600];
    /* 0x600 */ u8 list[0xC10];
    /* 0x1210 */ s32 stamp;
} B12Pool;

/* memory block node (list header has the first block at +8) */
typedef struct B12Blk B12Blk;
struct B12Blk {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ B12Blk *next;
    /* 0x08 */ u8 pad8[0xC];
    /* 0x14 */ u32 size;
};

typedef struct B12BlkList {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ B12Blk *first;
} B12BlkList;

/* task/port object: thread at +0, message queue at +0x230 (buffer at +0x248) */
typedef struct B12Port {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ u8 pad1B0[0x80];
    /* 0x230 */ OSMesgQueue q;
    /* 0x248 */ u8 pad248[0x1200];
    /* 0x1448 */ s32 unk1448;
} B12Port;

/* heap block header (0x20 bytes) and heap descriptor */
typedef struct B12HBlk B12HBlk;
struct B12HBlk {
    /* 0x00 */ B12HBlk *next;
    /* 0x04 */ B12HBlk *prev;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u32 hdr;
    /* 0x14 */ u32 size;
};

typedef struct B12Heap {
    /* 0x00 */ u32 start;
    /* 0x04 */ u32 end;
    /* 0x08 */ B12HBlk *first;
    /* 0x0C */ B12HBlk *last;
    /* 0x10 */ B12HBlk *cur;
} B12Heap;

/* hash bucket entry (16 bytes), chained through +0xC */
typedef struct B12Bucket B12Bucket;
struct B12Bucket {
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ s32 id;
    /* 0xC */ B12Bucket *next;
};

/* the module's global block: D_80103F70 (D_80104560, D_80104570, ... D_80105180 are all members) */
/*MGR_BEGIN*/
typedef struct B12Mgr {
    /* 0x000 */ u8 pad0[0x5F0];
    /* 0x5F0 */ B12Node * nodes;
    /* 0x5F4 */ B12Node ** stk;
    /* 0x5F8 */ B12Node * cur;
    /* 0x5FC */ u8 pad5FC[0x4];
    /* 0x600 */ B12List lists[2];
    /* 0x628 */ s32 tbl628[2];
    /* 0x630 */ s32 tbl630[2];
    /* 0x638 */ s32 f638;
    /* 0x63C */ u8 pad63C[0xB88];
    /* 0x11C4 */ s32 tbl11C4[2];
    /* 0x11CC */ s32 cnt;
    /* 0x11D0 */ u8 pad11D0[0x20];
    /* 0x11F0 */ OSMesgQueue q11F0;
    /* 0x1208 */ u8 pad1208[0x8];
    /* 0x1210 */ u32 stamp;
    /* 0x1214 */ u8 pad1214[0xC];
    /* 0x1220 */ u32 hashMask;
    /* 0x1224 */ B12Bucket * buckets;
} B12Mgr;
/*MGR_END*/

/* context with a free list (+0x5068) and a used list (+0x507C) of 0x18+ byte queue nodes */
typedef struct B12QNode {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ s32 state;
} B12QNode;

typedef struct B12Ctx {
    /* 0x0000 */ u8 pad0[0x5068];
    /* 0x5068 */ B12List freeList;
    /* 0x507C */ B12List usedList;
} B12Ctx;

/* request message sent to a port thread: callback at +0x14, its argument at +0x18, reply queue at +0x20 */
typedef struct B12Req B12Req;
struct B12Req {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ void (*fn)(void *arg, B12Req *r);
    /* 0x18 */ void *arg;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ OSMesgQueue *reply;
};

#endif
