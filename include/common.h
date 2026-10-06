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

typedef struct {
    /* 0x0 */ f32 factor;
    /* 0x4 */ u16 offset;
    /* 0x8 */ u32 scale;
} __OSViScale;

/* The VI manager's pending context (__osViNext). */
typedef struct {
    /* 0x00 */ u16 state;
    /* 0x02 */ u16 retraceCount;
    /* 0x04 */ void *buffer;
    /* 0x08 */ OSViMode *modep;
    /* 0x0C */ u32 features;
    /* 0x10 */ OSMesgQueue *mq;
    /* 0x14 */ OSMesg *msg;
    /* 0x18 */ __OSViScale x;
    /* 0x24 */ __OSViScale y;
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
    u32 ramarray[15];
    u32 pifstatus;
} OSPifRam;

typedef struct {
    u16 type;
    u8 status;
    u8 errno;
} OSContStatus;

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

typedef struct {
    /* 0x00 */ u16 type;
    /* 0x02 */ u8 pri;
    /* 0x03 */ u8 status;
    /* 0x04 */ OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct {
    /* 0x00 */ OSIoMesgHdr hdr;
    /* 0x08 */ void *dramAddr;
    /* 0x0C */ u32 devAddr;
    /* 0x10 */ u32 size;
    /* 0x14 */ void *piHandle;
} OSIoMesg;

typedef union {
    s32 m[4][4];
    long long int force_structure_alignment;
} Mtx;

typedef u32 OSEvent;

typedef struct {
    OSMesgQueue *messageQueue;
    OSMesg message;
} __OSEventState;

/* Controller Pak / Rumble Pak support */
#define BLOCKSIZE 32
#define CONT_BLOCK_DETECT 0x400
#define PFS_ERR_NOPACK 1
#define PFS_ERR_NEW_PACK 2
#define PFS_ERR_CONTRFAIL 4
#define PFS_ERR_INVALID 5
#define PFS_ERR_DEVICE 11
#define CHNL_ERR(format) (((format).rxsize & 0xC0) >> 4)

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 address;
    u8 data[BLOCKSIZE];
    u8 datacrc;
} __OSContRamReadFormat;

typedef __OSContRamReadFormat __OSContRamWriteFormat;

typedef struct {
    /* 0x00 */ s32 status;
    /* 0x04 */ OSMesgQueue *queue;
    /* 0x08 */ s32 channel;
    /* 0x0C */ u8 id[32];
    /* 0x2C */ u8 label[32];
    /* 0x4C */ s32 version;
    /* 0x50 */ s32 dir_size;
    /* 0x54 */ s32 inode_table;
    /* 0x58 */ s32 minode_table;
    /* 0x5C */ s32 dir_table;
    /* 0x60 */ s32 inode_start_page;
    /* 0x64 */ u8 banks;
    /* 0x65 */ u8 activebank;
} OSPfs;

/* PI device handles */
typedef struct {
    u32 errStatus;
    void *dramAddr;
    void *C2Addr;
    u32 sectorSize;
    u32 C1ErrNum;
    u32 C1ErrSector[4];
} __OSBlockInfo;

typedef struct {
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 devAddr;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    __OSBlockInfo block[2];
} __OSTranxInfo;

typedef struct OSPiHandle_s {
    /* 0x00 */ struct OSPiHandle_s *next;
    /* 0x04 */ u8 type;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 relDuration;
    /* 0x08 */ u8 pulse;
    /* 0x09 */ u8 domain;
    /* 0x0C */ u32 baseAddress;
    /* 0x10 */ u32 speed;
    /* 0x14 */ __OSTranxInfo transferInfo;
} OSPiHandle;

#define PI_BSD_DOM1_LAT_REG 0x04600014
#define PI_BSD_DOM1_PWD_REG 0x04600018
#define PI_BSD_DOM1_PGS_REG 0x0460001C
#define PI_BSD_DOM1_RLS_REG 0x04600020
#define PI_BSD_DOM2_LAT_REG 0x04600024
#define PI_BSD_DOM2_LWD_REG 0x04600028
#define PI_BSD_DOM2_PGS_REG 0x0460002C
#define PI_BSD_DOM2_RLS_REG 0x04600030
#define IO_WRITE(addr, data) (*(volatile u32 *)PHYS_TO_K1(addr) = (u32)(data))

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
#define VI_CONTROL_REG 0x04400000
#define VI_ORIGIN_REG 0x04400004
#define VI_WIDTH_REG 0x04400008
#define VI_INTR_REG 0x0440000C
#define VI_V_CURRENT_LINE_REG 0x04400010
#define VI_BURST_REG 0x04400014
#define VI_V_SYNC_REG 0x04400018
#define VI_H_SYNC_REG 0x0440001C
#define VI_LEAP_REG 0x04400020
#define VI_H_START_REG 0x04400024
#define VI_V_START_REG 0x04400028
#define VI_V_BURST_REG 0x0440002C
#define VI_X_SCALE_REG 0x04400030
#define VI_Y_SCALE_REG 0x04400034
#define AI_LEN_REG 0x04500004
#define AI_CONTROL_REG 0x04500008
#define AI_DACRATE_REG 0x04500010
#define AI_BITRATE_REG 0x04500014
#define PI_DRAM_ADDR_REG 0x04600000
#define PI_CART_ADDR_REG 0x04600004
#define PI_RD_LEN_REG 0x04600008
#define PI_WR_LEN_REG 0x0460000C
#define PI_STATUS_REG 0x04600010
#define PI_STATUS_BUSY 0x1
#define PI_STATUS_IOBUSY 0x2
#define PI_STATUS_ERROR 0x4
#define AI_STATUS_REG 0x0450000C
#define SI_STATUS_REG 0x04800018
#define AI_STATUS_AI_FULL (1 << 31)
#define SI_STATUS_DMA_BUSY 0x1
#define SI_STATUS_IO_READ_BUSY 0x2

/* RSP status register read bits */
#define SPSTATUS_DMA_BUSY 0x00000004
#define SPSTATUS_DMA_FULL 0x00000008
#define SPSTATUS_IO_FULL 0x00000010
#define SPSTATUS_SIGNAL0_SET 0x00000080
#define SPSTATUS_SIGNAL1_SET 0x00000100

#define OS_READ 0
#define OS_WRITE 1
#define OS_MESG_PRI_NORMAL 0
#define OS_MESG_PRI_HIGH 1
#define OS_TASK_DP_WAIT 0x0002

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
extern s32 osViClock;
extern OSViContext *__osViNext;
extern OSViContext *__osViCurr;
extern OSTimer *__osTimerList;
extern OSTime _osCurrentTime;
extern u32 __osBaseCounter;
extern u32 __osViIntrCount;
extern u32 __osTimerCounter;
extern OSContPackedStruct __osContBuffer[7];
#define __osContPifRam (*(OSPifRam *)&__osContBuffer) /* same storage as __osContBuffer */
extern u32 __osContPifStatus; /* word 15 of the 64-byte PIF RAM image */
extern u8 __osContLastCmd;
extern u8 __osContNumControllers;
extern OSMgrArgs __osPiDevMgr;
extern OSPifRam __osPfsPifRam;
extern OSPiHandle *__osCurrentHandle[2];
extern OSPiHandle *__osPiTable;
extern u32 __osSiAccessQueueEnabled;
extern OSMesgQueue __osSiAccessQueue;
extern OSMesg __osSiAccessBuf[1];
extern s32 __osMotorInitialized[4];
extern OSPifRam __osMotorStartData[4];
extern u8 __osMotorStartBuf[BLOCKSIZE];
extern OSPifRam __osMotorStopData[4];
extern u8 __osMotorStopBuf[BLOCKSIZE];
extern s32 __osContinitialized;
extern OSMesgQueue __osContMesgQueue;
extern OSMesg __osContMesgBuff[4];
extern OSMesgQueue __osPiAccessQueue;
extern __OSEventState __osEventStateTab[16];
#define OS_ROM_BASE (*(u32 *)0x80000308) /* ROM base address passed in by the boot code */
extern u32 __osPiAccessQueueEnabled;
extern OSMesg __osPiAccessBuf[1];
extern OSTask __osTmpTask; /* static task buffer used by _VirtualToPhysicalTask */

/* libultra functions (asm or C) */
u32 __osDisableInt(void);
void __osRestoreInt(u32 mask);
s32 __osSpDeviceBusy(void);
void __osViSwapContext(void);
void osSetEventMesg(OSEvent e, OSMesgQueue *mq, OSMesg msg);
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
void __osSetCompare(u32 value);
void __osSetTimerIntr(u64 time);
u64 __osInsertTimer(OSTimer *timer);
void osWritebackDCache(void *addr, s32 size);
s32 __osSpSetPc(u32 pc);
s32 __osSpRawStartDma(s32 dir, u32 devAddr, void *dramAddr, u32 size);
void *memcpy(void *dst, const void *src, u32 n);
u32 strlen(const u8 *str);
const u8 *strchr(const u8 *str, u32 ch);
void osContGetReadData(OSContPad *pad);
s32 osContStartReadData(OSMesgQueue *mq);
void __osPackReadData(void);
s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int channel);
s32 osMotorStart(OSPfs *pfs);
s32 osMotorStop(OSPfs *pfs);
s32 __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer);
s32 __osContRamWrite(OSMesgQueue *mq, int channel, u16 address, u8 *buffer, int force);
void __osPackRamReadData(int channel, u16 address);
void __osPackRamWriteData(int channel, u16 address, u8 *buffer);
u8 __osContAddressCrc(u32 addr);
u8 __osContDataCrc(u8 *data);
s32 __osPfsGetStatus(OSMesgQueue *queue, int channel);
void __osPackResetData(void);
s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *data);
s32 osContReset(OSMesgQueue *mq, OSContStatus *data);
s32 osContStartQuery(OSMesgQueue *mq);
void osContGetQuery(OSContStatus *data);
u32 osSetTimer(OSTimer *timer, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg);
OSTime osGetTime(void);
void __osSiCreateAccessQueue(void);
void guMtxIdentF(f32 mf[4][4]);
void guMtxF2L(f32 mf[4][4], Mtx *m);
void guMtxL2F(f32 mf[4][4], Mtx *m);
void guMtxIdent(Mtx *m);
void __osPackRequestData(u8 cmd);
void __osContGetInitData(u8 *pattern, OSContStatus *status);
void __osSiGetAccess(void);
void __osSiRelAccess(void);
s32 __osSiRawStartDma(s32 dir, void *dramAddr);
void osViSetSpecialFeatures(u32 func);
OSMesgQueue *osPiGetCmdQueue(void);
s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag);
void __osPiCreateAccessQueue(void);
void __osSiGetAccess(void);
void __osSiRelAccess(void);
void __assert(const char *exp, const char *file, s32 line);
void bzero(void *ptr, u32 n);
void *memset(void *s, int c, u32 n);
s32 osEPiRawReadIo(OSPiHandle *pihandle, u32 devAddr, u32 *data);
s32 osEPiRawWriteIo(OSPiHandle *pihandle, u32 devAddr, u32 data);
s32 osPiRawReadIo(u32 devAddr, u32 *data);
u32 osPiGetStatus(void);
OSPiHandle *osCartRomInit(void);
OSPiHandle *osDriveRomInit(void);
void __osPiGetAccess(void);
void __osPiRelAccess(void);
void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, s32 count);
s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flag);
s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flag);
s32 osPiStartDma(OSIoMesg *mb, s32 priority, s32 direction, u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *mq);
s32 osPiRawStartDma(s32 dir, u32 cart_addr, void *dram_addr, u32 size);
s32 osSpTaskYielded(OSTask *task);
s32 __osAiDeviceBusy(void);
s32 osAiSetFrequency(u32 freq);
s32 __osSiDeviceBusy(void);
u32 __osSpGetStatus(void);

#endif /* COMMON_H */
