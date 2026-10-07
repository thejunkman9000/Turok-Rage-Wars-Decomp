#ifndef B13_TYPES_H
#define B13_TYPES_H

#include "p1_types.h"

typedef union { s32 i; f32 f; } IF32;

/* Types recovered in batch 13 (sound manager / voice pool code, ROM 0x57F80-0x5F500). Offsets verified against the asm. */

typedef struct SndEnv SndEnv;
typedef struct SndCore SndCore;
typedef struct SndSeq SndSeq;
typedef struct SndFx SndFx;
typedef struct SndInfo SndInfo;
typedef struct SndMgrQ SndMgrQ;
typedef struct SndLink SndLink;
typedef struct SndMgr SndMgr;
typedef struct SndVoice SndVoice;
typedef struct SndNode SndNode;
typedef struct SndQueue SndQueue;
typedef struct SndVoices SndVoices;
typedef struct SndLock SndLock;

/* doubly linked list node (prev at +0, next at +4) */
struct SndLink {
    /* 0x0000 */ SndLink* prev;
    /* 0x0004 */ SndLink* next;
};

/* 12 byte table entry copied into a voice */
struct SndEnv {
    /* 0x0000 */ u16 w0;
    /* 0x0002 */ u16 a;
    /* 0x0004 */ u16 b;
    /* 0x0006 */ s16 c;
    /* 0x0008 */ u16 w8;
    /* 0x000A */ u16 wA;
};

/* one sound voice / event record (0xCC bytes) */
struct SndVoice {
    /* 0x0000 */ s32 idx;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ s32 unk10;
    /* 0x0014 */ s32 unk14;
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s16 unk20;
    /* 0x0022 */ u8 pad22[0x2];
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s16 pan;
    /* 0x002A */ u8 pad2A[0x2];
    /* 0x002C */ f32 unk2C;
    /* 0x0030 */ u8 pad30[0x4];
    /* 0x0034 */ f32 unk34;
    /* 0x0038 */ s16 unk38;
    /* 0x003A */ s16 unk3A;
    /* 0x003C */ s16 unk3C;
    /* 0x003E */ u8 pad3E[0x2];
    /* 0x0040 */ s32 unk40;
    /* 0x0044 */ Vec3f pos;
    /* 0x0050 */ s32 unk50;
    /* 0x0054 */ u8 unk54;
    /* 0x0055 */ u8 pad55[0x3];
    /* 0x0058 */ s32 unk58;
    /* 0x005C */ s32 unk5C;
    /* 0x0060 */ u8 pad60[0x28];
    /* 0x0088 */ s32 unk88;
    /* 0x008C */ SndEnv env;
    /* 0x0098 */ f32 unk98;
    /* 0x009C */ f32 unk9C;
    /* 0x00A0 */ s32 unkA0;
    /* 0x00A4 */ s32 unkA4;
    /* 0x00A8 */ s32 tag;
    /* 0x00AC */ s32 unkAC;
    /* 0x00B0 */ SndMgr* mgr;
    /* 0x00B4 */ SndMgr* unkB4;
    /* 0x00B8 */ f32 unkB8;
    /* 0x00BC */ s32 unkBC;
    /* 0x00C0 */ s32 unkC0;
    /* 0x00C4 */ s32 unkC4;
    /* 0x00C8 */ u8 padC8[0x4];
};

/* list node: links + embedded voice record */
struct SndNode {
    /* 0x0000 */ SndLink link;
    /* 0x0008 */ SndVoice body;
};

/* pending event queue at SndMgr+0x138 (active list sentinel at +4, free list sentinel at +0xD8) */
struct SndQueue {
    /* 0x0000 */ SndMgr* owner;
    /* 0x0004 */ SndNode active;
    /* 0x00D8 */ SndNode free;
    /* 0x01AC */ SndNode nodes[32];
};

/* voice pool at SndMgr+0x1DB8 */
struct SndVoices {
    /* 0x0000 */ SndMgr* owner;
    /* 0x0004 */ SndVoice v[17];
};

/* counting mutex built on a message queue */
struct SndLock {
    /* 0x0000 */ OSMesgQueue q;
    /* 0x0018 */ u8 pad18[0x4];
    /* 0x001C */ s32 count;
};

/* view of the sound core embedded at SndMgr+0x7C (player at +8, snd id table at +0x60) */
struct SndCore {
    /* 0x0000 */ u8 pad0[0x60];
    /* 0x0060 */ s16 snd[16];
};

/* sequence player wrapper at SndMgr+0x1D64 */
struct SndSeq {
    /* 0x0000 */ SndMgr* owner;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ s32* unk8;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ void* unk10;
    /* 0x0014 */ void* csp;
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ s32 unk1C;
    /* 0x0020 */ s32 unk20;
    /* 0x0024 */ s32 unk24;
    /* 0x0028 */ s32 unk28;
    /* 0x002C */ f32 vol;
    /* 0x0030 */ f32 unk30;
    /* 0x0034 */ f32 unk34;
    /* 0x0038 */ s32 unk38;
    /* 0x003C */ f32 unk3C;
    /* 0x0040 */ IF32 unk40;
};

/* sound-effect channel object at SndMgr+0x2BC0 */
struct SndFx {
    /* 0x0000 */ SndMgr* owner;
    /* 0x0004 */ s32 unk4;
    /* 0x0008 */ s32 unk8;
    /* 0x000C */ s32 unkC;
    /* 0x0010 */ u8 pad10[0x4];
    /* 0x0014 */ s32 unk14;
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ s32 sndId;
    /* 0x0020 */ u8 pad20[0x20];
};

/* overlay view of SndMgr fields that fall inside voice slot 16 */
struct SndMgrQ {
    /* 0x0000 */ u8 pad0[0x2A84];
    /* 0x2A84 */ s32 unk2A84;
    /* 0x2A88 */ s32 unk2A88;
    /* 0x2A8C */ u8 pad2A8C[0x28];
    /* 0x2AB4 */ s16 unk2AB4;
    /* 0x2AB6 */ s16 unk2AB6;
};

struct SndMgr {
    /* 0x0000 */ u8 pad0[0x7C];
    /* 0x007C */ s32* unk7C;
    /* 0x0080 */ u8 pad80[0x4];
    /* 0x0084 */ u8 player[84];
    /* 0x00D8 */ u8 padD8[0x4];
    /* 0x00DC */ s16 snd[16];
    /* 0x00FC */ u8 padFC[0x6];
    /* 0x0102 */ s16 unk102;
    /* 0x0104 */ s32 unk104;
    /* 0x0108 */ s32 unk108;
    /* 0x010C */ s32 unk10C;
    /* 0x0110 */ SndLock lock;
    /* 0x0130 */ s32 unk130;
    /* 0x0134 */ s32 unk134;
    /* 0x0138 */ SndQueue q;
    /* 0x1D64 */ SndSeq seq;
    /* 0x1DA8 */ u8 heap[16];
    /* 0x1DB8 */ SndVoices pool;
    /* 0x2B48 */ void* root2B48;
    /* 0x2B4C */ void* tree2B4C;
    /* 0x2B50 */ void* node2B50;
    /* 0x2B54 */ s32 unk2B54;
    /* 0x2B58 */ void* unk2B58;
    /* 0x2B5C */ s32* unk2B5C;
    /* 0x2B60 */ void* unk2B60;
    /* 0x2B64 */ s32 unk2B64;
    /* 0x2B68 */ u8 pad2B68[0x8];
    /* 0x2B70 */ u8* tab70;
    /* 0x2B74 */ u8* tab74;
    /* 0x2B78 */ u8* tab78;
    /* 0x2B7C */ s32 unk2B7C;
    /* 0x2B80 */ s32 unk2B80;
    /* 0x2B84 */ s32 unk2B84;
    /* 0x2B88 */ void* unk2B88;
    /* 0x2B8C */ s16 unk2B8C;
    /* 0x2B8E */ u8 pad2B8E[0x2];
    /* 0x2B90 */ s32 unk2B90;
    /* 0x2B94 */ u8 unk2B94;
    /* 0x2B95 */ u8 pad2B95[0x3];
    /* 0x2B98 */ s32 unk2B98;
    /* 0x2B9C */ s32 unk2B9C;
    /* 0x2BA0 */ f32 unk2BA0;
    /* 0x2BA4 */ f32 unk2BA4;
    /* 0x2BA8 */ f32 unk2BA8;
    /* 0x2BAC */ s32 unk2BAC;
    /* 0x2BB0 */ s32 unk2BB0;
    /* 0x2BB4 */ s32 unk2BB4;
    /* 0x2BB8 */ s32 unk2BB8;
    /* 0x2BBC */ u8 pad2BBC[0x4];
    /* 0x2BC0 */ SndFx obj2BC0;
};

/* sound info record (accessor family func_0025E520..) */
struct SndInfo {
    /* 0x0000 */ s16 w0;
    /* 0x0002 */ s16 w2;
    /* 0x0004 */ s8 b4;
    /* 0x0005 */ s8 b5;
    /* 0x0006 */ u16 bits6;
    /* 0x0008 */ s16 w8;
    /* 0x000A */ s16 wA;
    /* 0x000C */ s16 wC;
    /* 0x000E */ s8 bE;
    /* 0x000F */ s8 bF;
    /* 0x0010 */ s16 w10;
    /* 0x0012 */ s16 w12;
    /* 0x0014 */ s16 w14;
};

/* lock / unlock of the counting mutex SndMgr.lock (inlined everywhere in the ROM); l = scratch local */
#define SND_LOCKP(l) do { \
    u32 _m = __osDisableInt(); \
    if (++(l)->count != 1) { __osRestoreInt(_m); osRecvMesg(&(l)->q, 0, 1); } \
    else __osRestoreInt(_m); \
} while (0)
#define SND_UNLOCKP(l) do { \
    u32 _m = __osDisableInt(); \
    if (--(l)->count != 0) { __osRestoreInt(_m); osSendMesg(&(l)->q, 0, 1); } \
    else __osRestoreInt(_m); \
} while (0)
#define SND_LOCK(l, m) (l) = &(m)->lock; SND_LOCKP(l)
#define SND_UNLOCK(l, m) (l) = &(m)->lock; SND_UNLOCKP(l)

/* voice slot address as the ROM computes it: (idx * 0xCC + pool) first, then +4 as a separate add */
#define SND_VOICE_AT(v, p, idx) \
    (v) = (SndVoice *)((idx) * 0xCC + (u32)(p)); \
    (v) = (SndVoice *)((u8 *)(v) + 4)
/* variants with the arms swapped in the source (used where gcc flips the polarity) */
#define SND_LOCKP2(l) do { \
    u32 _m = __osDisableInt(); \
    if (++(l)->count == 1) __osRestoreInt(_m); \
    else { __osRestoreInt(_m); osRecvMesg(&(l)->q, 0, 1); } \
} while (0)
#define SND_UNLOCKP2(l) do { \
    u32 _m = __osDisableInt(); \
    if (--(l)->count == 0) __osRestoreInt(_m); \
    else { __osRestoreInt(_m); osSendMesg(&(l)->q, 0, 1); } \
} while (0)

/* the ROM uses real inline functions for the mutex (macros give a different block layout when a function has several returns) */
static inline void SndMgr_Lock(SndMgr *m) {
    SndLock *l = &m->lock;
    u32 mask = __osDisableInt();
    if (++l->count != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&l->q, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}
static inline void SndMgr_Unlock(SndMgr *m) {
    SndLock *l = &m->lock;
    u32 mask = __osDisableInt();
    if (--l->count != 0) {
        __osRestoreInt(mask);
        osSendMesg(&l->q, 0, 1);
    } else {
        __osRestoreInt(mask);
    }
}

/* doubly linked list append (inlined helper: the head pointer becomes a pseudo, which gcc hoists out of loops) */
static inline void SndLink_AddTail(SndLink *head, SndLink *n) {
    n->prev = head->prev;
    n->next = head;
    head->prev->next = n;
    head->prev = n;
}

#endif
