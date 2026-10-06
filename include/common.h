#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"

/* Minimal libultra-compatible types. Layouts follow the public libultra headers. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef float f32;
typedef void *OSMesg;
typedef u64 OSTime;
typedef s32 OSPri;
typedef s32 OSId;

#define NULL ((void *)0)
#define UNUSED __attribute__((unused))

#define OS_MESG_NOBLOCK 0
#define OS_MESG_BLOCK 1

#define OS_STATE_STOPPED 1
#define OS_STATE_RUNNABLE 2
#define OS_STATE_RUNNING 4
#define OS_STATE_WAITING 8

typedef union {
    struct { f32 f_odd; f32 f_even; } f;
} __OSfp;

typedef struct {
    /* 0x20 */ u64 at, v0, v1, a0, a1, a2, a3;
    /* 0x58 */ u64 t0, t1, t2, t3, t4, t5, t6, t7;
    /* 0x98 */ u64 s0, s1, s2, s3, s4, s5, s6, s7;
    /* 0xD8 */ u64 t8, t9, gp, sp, s8, ra;
    /* 0x108 */ u64 lo, hi;
    /* 0x118 */ u32 sr, pc, cause, badvaddr, rcp;
    /* 0x12C */ u32 fpcsr;
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;

typedef struct {
    u32 flag;
    u32 count;
    u64 time;
} __OSThreadprofile_s;

typedef struct OSThread_s {
    /* 0x00 */ struct OSThread_s *next;
    /* 0x04 */ OSPri priority;
    /* 0x08 */ struct OSThread_s **queue;
    /* 0x0C */ struct OSThread_s *tlnext;
    /* 0x10 */ u16 state;
    /* 0x12 */ u16 flags;
    /* 0x14 */ OSId id;
    /* 0x18 */ int fp;
    /* 0x1C */ __OSThreadprofile_s *thprof;
    /* 0x20 */ __OSThreadContext context;
} OSThread;

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

/* Controller packets (PIF command/response layout) */
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u16 button;
    s8 rawStickX;
    s8 rawStickY;
} OSContPackedRead;

typedef struct {
    u8 unk00, unk01, unk02, unk03, unk04, unk05, unk06, unk07;
} OSContPackedRequest;

typedef union {
    OSContPackedRead read;
    OSContPackedRequest request;
} OSContPackedStruct;

typedef struct {
    u16 button;
    s8 stick_x;
    s8 stick_y;
    u8 errno;
} OSContPad;

/* Device manager state (PI manager: __osPiDevMgr) */
typedef struct {
    /* 0x00 */ u32 initialized;
    /* 0x04 */ OSThread *thread;
    /* 0x08 */ OSMesgQueue *cmdQueue;
    /* 0x0C */ OSMesgQueue *evtQueue;
    /* 0x10 */ OSMesgQueue *acsQueue;
    /* 0x14 */ s32 (*dma_func)(s32, u32, void *, u32);
    u64 force_align;
} OSMgrArgs;

typedef struct OSTimer_s {
    /* 0x00 */ struct OSTimer_s *next;
    /* 0x04 */ struct OSTimer_s *prev;
    /* 0x08 */ u64 interval;
    /* 0x10 */ u64 remaining;
    /* 0x18 */ OSMesgQueue *mq;
    /* 0x1C */ OSMesg *msg;
} OSTimer;

typedef struct {
    /* 0x00 */ u32 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ u64 *ucode_boot;
    /* 0x0C */ u32 ucode_boot_size;
    /* 0x10 */ u64 *ucode;
    /* 0x14 */ u32 ucode_size;
    /* 0x18 */ u64 *ucode_data;
    /* 0x1C */ u32 ucode_data_size;
    /* 0x20 */ u64 *dram_stack;
    /* 0x24 */ u32 dram_stack_size;
    /* 0x28 */ u64 *output_buff;
    /* 0x2C */ u64 *output_buff_size;
    /* 0x30 */ u64 *data_ptr;
    /* 0x34 */ u32 data_size;
    /* 0x38 */ u64 *yield_data_ptr;
    /* 0x3C */ u32 yield_data_size;
} OSTask_t;

typedef union {
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;

#define OS_TASK_YIELDED 0x0001
#define OS_TASK_LOADABLE 0x0004
#define OS_YIELD_DATA_SIZE 0x0C00

#define SP_IMEM_START 0x04001000
#define PHYS_TO_K1(x) ((u32)(x) | 0xA0000000)
#define IO_READ(addr) (*(volatile u32 *)PHYS_TO_K1(addr))

/* VI special features */
#define OS_VI_GAMMA_ON 0x0001
#define OS_VI_GAMMA_OFF 0x0002
#define OS_VI_GAMMA_DITHER_ON 0x0004
#define OS_VI_GAMMA_DITHER_OFF 0x0008
#define OS_VI_DIVOT_ON 0x0010
#define OS_VI_DIVOT_OFF 0x0020
#define OS_VI_DITHER_FILTER_ON 0x0040
#define OS_VI_DITHER_FILTER_OFF 0x0080
#define OS_VI_GAMMA 0x08
#define OS_VI_GAMMA_DITHER 0x04
#define OS_VI_DIVOT 0x10
#define OS_VI_DITHER_FILTER 0x10000
#define OS_VI_UNK200 0x200
#define OS_VI_UNK100 0x100

/* hardware registers (physical addresses) */
#define HW_REG(reg, type) (*(volatile type *)((reg) | 0xA0000000))
#define SP_STATUS_REG 0x04040010
#define AI_STATUS_REG 0x0450000C
#define SI_STATUS_REG 0x04800018
#define AI_STATUS_AI_FULL (1 << 31)
#define SI_STATUS_DMA_BUSY 0x1
#define SI_STATUS_IO_READ_BUSY 0x2

/* RSP status register write bits */
#define SPSTATUS_CLEAR_HALT          0x00000001
#define SPSTATUS_CLEAR_BROKE         0x00000004
#define SPSTATUS_CLEAR_SSTEP         0x00000020
#define SPSTATUS_SET_INTR_ON_BREAK   0x00000100
#define SPSTATUS_SET_SIGNAL0         0x00000400
#define SPSTATUS_CLEAR_SIGNAL0       0x00000200
#define SPSTATUS_CLEAR_SIGNAL1       0x00000800
#define SPSTATUS_CLEAR_SIGNAL2       0x00002000

/* libultra globals */
extern OSThread *__osThreadTail;
extern OSThread *__osRunningThread;
extern OSThread *__osRunQueue;
extern OSThread *__osActiveQueue;
extern OSViContext *__osViNext;
extern OSTimer *__osTimerList;
extern OSTime _osCurrentTime;
extern u32 __osTimerCounter;
extern OSContPackedStruct __osContBuffer[7];
extern u8 __osContNumControllers;
extern OSMgrArgs __osPiDevMgr;
extern OSMesgQueue __osPiAccessQueue;
extern OSTask __osTmpTask; /* static task buffer used by _VirtualToPhysicalTask */

/* libultra functions (asm or C) */
u32 __osDisableInt(void);
void __osRestoreInt(u32 mask);
s32 __osSpDeviceBusy(void);
void __osSpSetStatus(u32 value);
void __osEnqueueAndYield(OSThread **queue);
OSThread *__osPopThread(OSThread **queue);
void osStartThread(OSThread *thread);
void __osDequeueThread(OSThread **queue, OSThread *thread);
void __osEnqueueThread(OSThread **queue, OSThread *thread);
void __osDispatchThread(void);
void __osCleanupThread(void);
u32 osVirtualToPhysical(void *addr);
u32 __osProbeTLB(void *addr);
u32 osGetCount(void);
void osWritebackDCache(void *addr, s32 size);
s32 __osSpSetPc(u32 pc);
s32 __osSpRawStartDma(s32 dir, u32 devAddr, void *dramAddr, u32 size);
void *memcpy(void *dst, const void *src, u32 n);
u32 strlen(const u8 *str);
const u8 *strchr(const u8 *str, u32 ch);
void osContGetReadData(OSContPad *pad);
void osViSetSpecialFeatures(u32 func);
OSMesgQueue *osPiGetCmdQueue(void);
s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag);
void __osPiRelAccess(void);
s32 __osAiDeviceBusy(void);
s32 __osSiDeviceBusy(void);
u32 __osSpGetStatus(void);

#endif /* COMMON_H */
