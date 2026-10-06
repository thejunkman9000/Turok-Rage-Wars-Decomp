#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"

/* Minimal libultra-compatible types. Layouts follow the public libultra headers. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef void *OSMesg;

struct OSThread_s;
typedef struct OSThread_s OSThread;

typedef struct OSMesgQueue_s {
    /* 0x00 */ OSThread *mtqueue;   /* threads blocked on an empty queue (receive) */
    /* 0x04 */ OSThread *fullqueue; /* threads blocked on a full queue (send) */
    /* 0x08 */ s32 validCount;
    /* 0x0C */ s32 first;
    /* 0x10 */ s32 msgCount;
    /* 0x14 */ OSMesg *msg;
} OSMesgQueue;

typedef struct {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;

typedef struct {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;

typedef struct {
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;

/* The VI manager's pending context (__osViNext). */
typedef struct {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ void *buffer;
    /* 0x08 */ OSViMode *modep;
    /* 0x0C */ u32 features;
    /* 0x10 */ OSMesgQueue *mq;
    /* 0x14 */ OSMesg *msg;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1c;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u16 unk28;
    /* 0x2C */ u32 unk2c;
} OSViContext;

typedef struct OSTask_s OSTask;

/* RSP status register write bits */
#define SPSTATUS_CLEAR_HALT          0x00000001
#define SPSTATUS_CLEAR_BROKE         0x00000004
#define SPSTATUS_CLEAR_SSTEP         0x00000020
#define SPSTATUS_SET_INTR_ON_BREAK   0x00000100

#define UNUSED __attribute__((unused))

/* libultra globals */
extern OSThread *__osThreadTail;
extern OSViContext *__osViNext;

/* libultra asm helpers */
u32 __osDisableInt(void);
void __osRestoreInt(u32 mask);
s32 __osSpDeviceBusy(void);
void __osSpSetStatus(u32 value);

#endif /* COMMON_H */
