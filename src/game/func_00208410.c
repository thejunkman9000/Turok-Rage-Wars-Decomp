
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef signed long long s64;
typedef void *OSMesg;
typedef u64 OSTime;
typedef s32 OSPri;
typedef s32 OSId;
typedef char *va_list;
typedef union 
{
  struct 
  {
    f32 f_odd;
    f32 f_even;
  } f;
} __OSfp;
typedef struct 
{
  u64 at;
  u64 v0;
  u64 v1;
  u64 a0;
  u64 a1;
  u64 a2;
  u64 a3;
  u64 t0;
  u64 t1;
  u64 t2;
  u64 t3;
  u64 t4;
  u64 t5;
  u64 t6;
  u64 t7;
  u64 s0;
  u64 s1;
  u64 s2;
  u64 s3;
  u64 s4;
  u64 s5;
  u64 s6;
  u64 s7;
  u64 t8;
  u64 t9;
  u64 gp;
  u64 sp;
  u64 s8;
  u64 ra;
  u64 lo;
  u64 hi;
  u32 sr;
  u32 pc;
  u32 cause;
  u32 badvaddr;
  u32 rcp;
  u32 fpcsr;
  __OSfp fp0;
  __OSfp fp2;
  __OSfp fp4;
  __OSfp fp6;
  __OSfp fp8;
  __OSfp fp10;
  __OSfp fp12;
  __OSfp fp14;
  __OSfp fp16;
  __OSfp fp18;
  __OSfp fp20;
  __OSfp fp22;
  __OSfp fp24;
  __OSfp fp26;
  __OSfp fp28;
  __OSfp fp30;
} __OSThreadContext;
typedef struct 
{
  u32 flag;
  u32 count;
  u64 time;
} __OSThreadprofile_s;
typedef struct OSThread_s
{
  struct OSThread_s *next;
  OSPri priority;
  struct OSThread_s **queue;
  struct OSThread_s *tlnext;
  u16 state;
  u16 flags;
  OSId id;
  int fp;
  __OSThreadprofile_s *thprof;
  __OSThreadContext context;
} OSThread;
typedef struct OSMesgQueue_s
{
  OSThread *mtqueue;
  OSThread *fullqueue;
  s32 validCount;
  s32 first;
  s32 msgCount;
  OSMesg *msg;
} OSMesgQueue;
typedef struct 
{
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
typedef struct 
{
  u32 origin;
  u32 yScale;
  u32 vStart;
  u32 vBurst;
  u32 vIntr;
} OSViFieldRegs;
typedef struct 
{
  u8 type;
  OSViCommonRegs comRegs;
  OSViFieldRegs fldRegs[2];
} OSViMode;
typedef struct 
{
  f32 factor;
  u16 offset;
  u32 scale;
} __OSViScale;
typedef struct 
{
  u16 state;
  u16 retraceCount;
  void *buffer;
  OSViMode *modep;
  u32 features;
  OSMesgQueue *mq;
  OSMesg *msg;
  __OSViScale x;
  __OSViScale y;
} OSViContext;
typedef struct 
{
  u8 unk00;
  u8 unk01;
  u8 unk02;
  u8 unk03;
  u16 button;
  s8 rawStickX;
  s8 rawStickY;
} OSContPackedRead;
typedef struct 
{
  u8 unk00;
  u8 unk01;
  u8 unk02;
  u8 unk03;
  u8 unk04;
  u8 unk05;
  u8 unk06;
  u8 unk07;
} OSContPackedRequest;
typedef union 
{
  OSContPackedRead read;
  OSContPackedRequest request;
} OSContPackedStruct;
typedef struct 
{
  u32 ramarray[15];
  u32 pifstatus;
} OSPifRam;
typedef struct 
{
  u16 type;
  u8 status;
  u8 errno;
} OSContStatus;
typedef struct 
{
  u16 button;
  s8 stick_x;
  s8 stick_y;
  u8 errno;
} OSContPad;
struct OSPiHandle_s;
typedef struct 
{
  u32 initialized;
  OSThread *thread;
  OSMesgQueue *cmdQueue;
  OSMesgQueue *evtQueue;
  OSMesgQueue *acsQueue;
  s32 (*dma_func)(s32, u32, void *, u32);
  s32 (*edma_func)(struct OSPiHandle_s *, s32, u32, void *, u32);
} OSMgrArgs;
typedef struct 
{
  u16 type;
  u8 pri;
  u8 status;
  OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct 
{
  OSIoMesgHdr hdr;
  void *dramAddr;
  u32 devAddr;
  u32 size;
  struct OSPiHandle_s *piHandle;
} OSIoMesg;
typedef union 
{
  s32 m[4][4];
  long long int force_structure_alignment;
} Mtx;
typedef u32 OSEvent;
typedef struct 
{
  OSMesgQueue *messageQueue;
  OSMesg message;
} __OSEventState;
typedef struct 
{
  u8 dummy;
  u8 txsize;
  u8 rxsize;
  u8 cmd;
  u16 address;
  u8 data[32];
  u8 datacrc;
} __OSContRamReadFormat;
typedef __OSContRamReadFormat __OSContRamWriteFormat;
typedef struct 
{
  s32 status;
  OSMesgQueue *queue;
  s32 channel;
  u8 id[32];
  u8 label[32];
  s32 version;
  s32 dir_size;
  s32 inode_table;
  s32 minode_table;
  s32 dir_table;
  s32 inode_start_page;
  u8 banks;
  u8 activebank;
} OSPfs;
typedef struct 
{
  u32 errStatus;
  void *dramAddr;
  void *C2Addr;
  u32 sectorSize;
  u32 C1ErrNum;
  u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct 
{
  u32 cmdType;
  u16 transferMode;
  u16 blockNum;
  s32 sectorNum;
  u32 devAddr;
  u32 bmCtlShadow;
  u32 seqCtlShadow;
  __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle_s
{
  struct OSPiHandle_s *next;
  u8 type;
  u8 latency;
  u8 pageSize;
  u8 relDuration;
  u8 pulse;
  u8 domain;
  u32 baseAddress;
  u32 speed;
  __OSTranxInfo transferInfo;
} OSPiHandle;
typedef struct OSTimer_s
{
  struct OSTimer_s *next;
  struct OSTimer_s *prev;
  u64 interval;
  u64 remaining;
  OSMesgQueue *mq;
  OSMesg msg;
} OSTimer;
typedef struct 
{
  u32 type;
  u32 flags;
  u64 *ucode_boot;
  u32 ucode_boot_size;
  u64 *ucode;
  u32 ucode_size;
  u64 *ucode_data;
  u32 ucode_data_size;
  u64 *dram_stack;
  u32 dram_stack_size;
  u64 *output_buff;
  u64 *output_buff_size;
  u64 *data_ptr;
  u32 data_size;
  u64 *yield_data_ptr;
  u32 yield_data_size;
} OSTask_t;
typedef union 
{
  OSTask_t t;
  long long int force_structure_alignment;
} OSTask;
extern OSThread *__osThreadTail;
extern OSThread *__osRunningThread;
extern OSThread *__osRunQueue;
extern OSThread *__osActiveQueue;
extern s32 osViClock;
extern OSViContext *__osViNext;
extern OSViContext __osViContexts[2];
extern OSViMode osViModeNtscLan1;
extern OSViMode osViModePalLan1;
extern OSViMode osViModeMpalLan1;
extern OSMgrArgs __osViDevMgr;
extern OSThread __osViThread;
extern u8 __osViThreadStack[4096];
extern OSMesgQueue __osViEventQueue;
extern OSMesg __osViEventBuf[5];
extern OSIoMesg __osViRetraceMsg;
extern OSIoMesg __osViCounterMsg;
extern u16 __osViRetraceCount;
extern OSViContext *__osViCurr;
extern OSTimer *__osTimerList;
extern OSTime _osCurrentTime;
extern u32 __OSGlobalIntMask;
extern OSTime osClockRate;
extern u32 __osInitialized;
extern u8 osAppNMIBuffer[0x40];
typedef struct 
{
  u32 inst1;
  u32 inst2;
  u32 inst3;
  u32 inst4;
} __osExceptionVector;
extern u32 __osExceptionPreamble[];
extern OSThread *__osFaultedThread;
extern u32 __osBaseCounter;
extern u32 __osViIntrCount;
extern u32 __osTimerCounter;
extern OSContPackedStruct __osContBuffer[7];
extern u32 __osContPifStatus;
extern u8 __osContLastCmd;
extern u8 __osContNumControllers;
extern OSMgrArgs __osPiDevMgr;
extern OSThread __osPiThread;
extern u8 __osPiThreadStack[4096];
extern OSMesgQueue __osPiEventQueue;
extern OSMesg __osPiEventBuf[1];
extern OSPifRam __osPfsPifRam;
extern OSPiHandle *__osCurrentHandle[2];
extern OSPiHandle *__osPiTable;
extern u32 __osSiAccessQueueEnabled;
extern OSMesgQueue __osSiAccessQueue;
extern OSMesg __osSiAccessBuf[1];
extern s32 __osMotorInitialized[4];
extern u8 hdwrBugFlag;
extern OSPifRam __osMotorStartData[4];
extern u8 __osMotorStartBuf[32];
extern OSPifRam __osMotorStopData[4];
extern u8 __osMotorStopBuf[32];
extern s32 __osContinitialized;
extern OSMesgQueue __osContMesgQueue;
extern OSMesg __osContMesgBuff[4];
extern OSMesgQueue __osPiAccessQueue;
extern __OSEventState __osEventStateTab[16];
extern u32 __osPiAccessQueueEnabled;
extern OSMesg __osPiAccessBuf[1];
extern OSTask __osTmpTask;
typedef struct 
{
  union 
  {
    s64 ll;
    f64 ld;
  } v;
  u8 *s;
  s32 n0;
  s32 nz0;
  s32 n1;
  s32 nz1;
  s32 n2;
  s32 nz2;
  s32 prec;
  s32 width;
  u32 nchar;
  u32 flags;
  u8 qual;
} _Pft;
void _Litob(_Pft *x, u8 type);
typedef struct 
{
  s64 quot;
  s64 rem;
} lldiv_t;
void lldiv(lldiv_t *ans, s64 num, s64 den);
void _Ldtob(_Pft *x, u8 type);
u32 __osDisableInt(void);
void __osRestoreInt(u32 mask);
s32 __osSpDeviceBusy(void);
void __osViSwapContext(void);
void __osViInit(void);
void *osViGetCurrentFramebuffer(void);
void __osTimerInterrupt(void);
void __osTimerServicesInit(void);
void osCreateViManager(OSPri pri);
OSViContext *__osViGetCurrentContext(void);
void osViSetYScale(f32 value);
s32 __osSiRawStartDma(s32 dir, void *dramAddr);
s32 __osSpRawStartDma(s32 dir, u32 devAddr, void *dramAddr, u32 size);
s32 __osSpSetPc(u32 pc);
void osInvalDCache(void *vaddr, s32 nbytes);
void osInvalICache(void *vaddr, s32 nbytes);
void osMapMainTLB(void);
void osInitialize(void);
void osYieldThread(void);
u32 __osGetSR(void);
void __osSetSR(u32 value);
u32 __osSetFpcCsr(u32 value);
void __osSetGlobalIntMask(u32 mask);
void __osResetGlobalIntMask(u32 mask);
s32 __osSiRawReadIo(u32 devAddr, u32 *data);
s32 __osSiRawWriteIo(u32 devAddr, u32 data);
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
s32 osAiSetNextBuffer(void *bufPtr, u32 size);
s32 osDpSetNextBuffer(void *bufPtr, u64 size);
s32 __osDpDeviceBusy(void);
s32 __osAiDeviceBusy(void);
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
s32 osSetTimer(OSTimer *timer, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg);
OSTime osGetTime(void);
void __osSiCreateAccessQueue(void);
void guLookAt(Mtx *m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void guLookAtF(f32 mf[4][4], f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
void guPerspective(Mtx *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void guPerspectiveF(f32 mf[4][4], u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
f32 sinf(f32 x);
f32 cosf(f32 x);
f32 sqrtf(f32 x);
u32 osAiGetStatus(void);
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
s32 sprintf(char *dst, const char *fmt, ...);
s32 _Printf(char *(*prout)(char *, const char *, u32), char *arg, const char *fmt, va_list args);
s32 osEPiRawReadIo(OSPiHandle *pihandle, u32 devAddr, u32 *data);
s32 osEPiRawWriteIo(OSPiHandle *pihandle, u32 devAddr, u32 data);
s32 osEPiRawStartDma(OSPiHandle *pihandle, s32 dir, u32 cart_addr, void *dram_addr, u32 size);
void __osDevMgrMain(void *args);
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt);
OSPri osGetThreadPri(OSThread *thread);
void osSetThreadPri(OSThread *thread, OSPri pri);
void osCreateThread(OSThread *thread, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri);
void __osResetGlobalIntMask(u32 mask);
void __osSetGlobalIntMask(u32 mask);
void osYieldThread(void);
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
typedef struct ActorInfo
{
  u32 flags;
  s32 unk4;
  u8 pad8[4];
  s16 unkC;
  u8 padE[6];
  f32 unk14;
  u8 pad18[0xC];
  u32 flags24;
  u8 pad28[0x28];
  f32 unk50;
} ActorInfo;
typedef struct ActorDef
{
  s32 type;
  u8 pad4[0x10];
  ActorInfo info;
} ActorDef;
typedef struct ActorStats
{
  u8 pad0[0x80];
  s8 unk80;
  u8 pad81[0xD];
  u8 unk8E;
  u8 unk8F;
  u8 pad90[2];
  u8 unk92;
  u8 unk93;
  u8 unk94;
} ActorStats;
typedef struct Brain
{
  u8 pad0[0xC];
  s32 unkC;
  u8 pad10[0x210];
  s32 unk220;
  u8 pad224[0x18];
  s32 unk23C;
  s32 unk240;
  u8 pad244[0x94];
  s32 unk2D8;
  s32 unk2DC;
  u8 pad2E0[0xC];
  s32 unk2EC;
  u8 pad2F0[0xC];
  s32 unk2FC;
} Brain;
typedef struct Actor Actor;
struct Actor
{
  u8 pad0[0x18];
  ActorDef *def;
  u8 pad1C[0x1C];
  u32 flags38;
  u8 pad3C[0xA8];
  u16 unkE4;
  u8 padE6[0x1A];
  u32 flags;
  u8 pad104[0xD4];
  Actor *owner;
  u8 pad1DC[0x110];
  Actor *next2EC;
  u8 pad2F0[0x2E4];
  s32 unk5D4;
  ActorStats *stats;
  u8 pad5DC[8];
  s32 unk5E4;
  u8 pad5E8[0x88];
  f32 unk670;
  u8 pad674[0x1CC];
  f32 unk840;
  u8 pad844[4];
  s32 unk848;
  u8 pad84C[0x974];
  s32 unk11C0;
  u8 pad11C4[0x28C];
  s32 unk1450;
  Brain *brain;
  u8 pad1458[0x280];
  u16 unk16D8;
  u8 pad16DA[6];
  Actor *next;
};
typedef struct ActorGroup
{
  u8 pad0[0x20];
  Actor *head;
} ActorGroup;
typedef struct ActorLink
{
  u8 pad0[8];
  void (*cb)();
} ActorLink;
typedef struct ActorState
{
  u32 flags;
  s32 unk4;
  u8 pad8[0x24];
  void *table;
  ActorLink *link;
  u8 pad34;
  s8 unk35;
  u8 pad36[0xA];
  f32 unk40;
  u8 pad44[0x87];
  s8 unkCB;
  u8 padCC[0x30];
  void *unkFC;
  u8 pad100[8];
  void (*fn108)();
  void (*fn10C)();
  void (*fn110)();
  u8 pad114[0x10];
  s32 unk124;
  union 
  {
    s32 i;
    f32 f;
  } unk128;
  union 
  {
    s32 i;
    f32 f;
  } unk12C;
  u8 pad130[0xC];
  f32 unk13C;
} ActorState;
typedef struct Vec3f
{
  f32 x;
  f32 y;
  f32 z;
} Vec3f;
typedef struct AiCfg
{
  u8 pad0[0x10];
  s32 unk10;
  s32 unk14;
  s32 unk18;
} AiCfg;
typedef struct GameFlags
{
  u8 pad0[0x1C];
  s32 unk1C;
  s32 unk20;
  u8 pad24[0x30];
  s32 unk54;
  u8 pad58[0x10];
  s32 unk68;
} GameFlags;
typedef struct TimedNode TimedNode;
struct TimedNode
{
  u8 pad0[0x10];
  TimedNode *next;
  u8 pad14[0x10];
  f32 unk24;
  s32 unk28;
};
typedef struct TimedList
{
  u8 pad0[0x24];
  TimedNode *head;
} TimedList;
typedef struct ActorRef
{
  Actor *actor;
} ActorRef;
typedef struct SndSrc
{
  u8 type;
  u8 pad1[7];
  Vec3f pos;
  u8 pad14[0xBC];
  void *unkD0;
} SndSrc;
typedef struct DlCmd
{
  u32 w0;
  u32 w1;
} DlCmd;
typedef struct IoReq
{
  s32 unk0;
  s32 unk4;
  s32 unk8;
  u32 cmd;
  s32 a0;
  s32 a1;
  s32 a2;
  OSMesgQueue *reply;
} IoReq;
typedef struct VecSrc
{
  u8 pad0[8];
  Vec3f v;
} VecSrc;
typedef struct VecDst
{
  s32 unk0;
  s32 unk4;
  s32 unk8;
  Vec3f a;
  Vec3f b;
  s32 unk24;
  Vec3f c;
  Vec3f d;
  s32 unk40;
} VecDst;
typedef struct SndHandle
{
  u8 pad0[0xC];
  s32 unkC;
} SndHandle;
typedef struct SndOwner
{
  u8 pad0[0xFC];
  SndHandle *unkFC;
} SndOwner;
typedef struct ActorRow400
{
  s32 unk0;
  u8 pad4[0x18C];
} ActorRow400;
typedef struct B2Info
{
  u32 flags;
  u16 unk4;
  u8 pad6[0x6];
  s16 unkC;
  u8 padE[0x6];
  s16 unk14;
  u8 pad16[0x2];
  f32 unk18;
  f32 unk1C;
  f32 unk20;
  u32 flags24;
  u8 pad28[0x4];
  f32 unk2C;
  f32 unk30;
  f32 unk34;
  f32 unk38;
  u8 pad3C[0x14];
  f32 unk50;
  u8 pad54[0xC];
} B2Info;
typedef struct B2Stats
{
  u8 pad0[0x80];
  s8 unk80;
  u8 pad81[0xE];
  u8 unk8F;
  u8 pad90[0x3];
  u8 unk93;
  u8 unk94;
  u8 unk95;
} B2Stats;
typedef struct B2Brain
{
  u8 pad0[0x4];
  s32 key;
} B2Brain;
typedef struct B2Def
{
  s32 type;
  u8 pad4[0x10];
  B2Info info;
} B2Def;
typedef struct B2Evt
{
  u8 pad0[0x4];
  u16 unk4;
  u8 pad6[0x4];
  u16 unkA;
} B2Evt;
typedef struct B2Pawn
{
  u8 pad0[0x12C];
  f32 f12C;
} B2Pawn;
typedef struct B2Sub
{
  u8 pad0[0x34];
  s8 unk34;
  u8 pad35[0x60];
  u8 unk95;
  u8 pad96[0x2];
} B2Sub;
typedef struct B2Obj
{
  u8 pad0[0x8];
  Vec3f pos;
  u8 pad14[0x4];
  B2Def *def;
  u8 pad1C[0xC8];
  u16 unkE4;
  u8 padE6[0x8A];
  B2Sub sub;
  u8 pad208[0x8];
  Vec3f pos210;
  u8 pad21C[0xCC];
} B2Obj;
typedef struct B2Actor B2Actor;
struct B2Actor
{
  u8 kind;
  u8 pad1[0x3];
  u16 type;
  u8 pad6[0x2];
  Vec3f pos;
  u8 pad14[0x4];
  B2Def *def;
  u8 pad1C[0x1C];
  u32 flags38;
  u8 pad3C[0x30];
  f32 unk6C;
  u8 pad70[0x74];
  u16 unkE4;
  u8 padE6[0x1A];
  u32 flags;
  u8 pad104[0x28];
  B2Actor *unk12C;
  u8 pad130[0xA8];
  B2Actor *owner;
  u8 pad1DC[0x10];
  B2Actor *next1EC;
  u8 pad1F0[0x20];
  Vec3f pos210;
  u8 pad21C[0x378];
  s32 unk594;
  u8 pad598[0x40];
  B2Stats *stats;
  B2Pawn *pawn;
  u8 pad5E0[0x4];
  s32 unk5E4;
  u8 pad5E8[0x46];
  s16 unk62E;
  u8 pad630[0x20];
  s16 unk650;
  u8 pad652[0x4A];
  f32 unk69C;
  f32 unk6A0;
  f32 unk6A4;
  f32 unk6A8;
  u32 unk6AC;
  u32 unk6B0;
  u8 pad6B4[0xB24];
  f32 unk11D8;
  u8 pad11DC[0x164];
  s32 unk1340;
  u8 pad1344[0x10C];
  s32 unk1450;
  B2Brain *brain;
};
typedef struct B2ActMgr
{
  u8 pad0[0x138];
  B2Obj *actors;
  u8 pad13C[0x4];
  s32 count;
} B2ActMgr;
typedef struct B2Row
{
  B2Actor *head;
  u8 pad4[0x10];
} B2Row;
typedef struct B2State B2State;
struct B2State
{
  u32 flags;
  u8 pad4[0x60];
  f32 unk64;
  u8 pad68[0x104];
  s32 unk16C;
};
typedef struct B2AnimEnt
{
  s32 id;
  void (*cb)();
  void (*upd)();
  u8 padC[0x14];
} B2AnimEnt;
typedef struct B2AnimTbl B2AnimTbl;
struct B2AnimTbl
{
  B2AnimTbl *next;
  u8 pad4[0x1C];
  B2AnimEnt ent[1];
};
typedef struct B2Ent
{
  s32 a;
  s32 b;
  f32 w;
} B2Ent;
typedef struct B2Ctl
{
  B2Actor *owner;
  s32 unk4;
  s32 unk8;
  s32 unkC;
  s32 unk10;
  s32 q[4];
  u8 pad24[0x4];
  s32 unk28;
  Vec3f v2C;
  s32 unk38;
  B2Actor *a3C[10];
  B2Actor *target;
  B2Actor *unk68;
  s32 a6C[10];
  s32 a94[10];
  s32 unkBC;
  B2Ent ent[10];
  Vec3f v138[1];
  u8 pad144[0x6C];
  Vec3f dst1B0;
  s32 unk1BC;
  s32 unk1C0;
  s32 nodeId;
  s32 unk1C8;
  u8 pad1CC[0x48];
  B2AnimTbl *tbl;
  B2AnimEnt *cur;
  s32 curId;
  s32 unk220;
  s32 unk224;
  s32 unk228;
  u8 pad22C[0x4];
  s32 unk230;
  u8 pad234[0x4];
  s32 unk238;
  s32 unk23C;
  s32 unk240;
  f32 unk244;
  f32 unk248;
  f32 unk24C;
  f32 unk250;
  f32 unk254;
  Vec3f v258;
  f32 unk264;
  u8 pad268[0x10];
  f32 unk278;
  u8 pad27C[0x10];
  s32 unk28C;
  u8 pad290[0x48];
  s32 unk2D8;
  s32 unk2DC;
  s32 unk2E0;
  s32 unk2E4;
  s32 unk2E8;
  s32 unk2EC;
  u8 pad2F0[0x4];
  s32 unk2F4;
  s32 unk2F8;
  s32 unk2FC;
  s32 unk300;
  s32 unk304;
  s32 unk308;
  s32 unk30C;
  s32 unk310;
  s32 unk314;
  s32 unk318;
  s32 unk31C;
  s32 unk320;
  s32 unk324;
  s32 unk328;
  s32 unk32C;
} B2Ctl;
typedef struct B2Pool
{
  s32 elemSize;
  u8 pad4[0x4];
  u8 data[1];
} B2Pool;
typedef struct B2Node B2Node;
struct B2Node
{
  s32 id;
  f32 unk4;
  s32 unk8;
  s32 unkC;
  B2Node *next;
  f32 unk14;
  f32 unk18;
  f32 unk1C;
  f32 unk20;
  f32 unk24;
  s32 unk28;
  s32 unk2C;
  B2Node *link30;
  B2Obj *unk34;
  s32 unk38;
  s32 unk3C;
  B2Obj *unk40;
  Vec3f v44;
};
typedef struct B2Edge
{
  u16 a;
  u16 b;
  u8 kind;
  u8 pad5[0x3];
} B2Edge;
typedef struct B2Mgr
{
  B2Pool *pool0;
  s32 unk4;
  B2Pool *pool8;
  s32 count;
  B2Pool *unk10;
  u8 pad14[0x4];
  s32 unk18;
  f32 unk1C;
  s32 unk20;
  B2Node *head;
  u8 pad28[0x10];
  s32 slots[64];
} B2Mgr;
typedef struct B2Edge2
{
  s32 id0;
  s32 src;
  u8 pad8[0x4];
  s32 unkC;
  s32 dst;
} B2Edge2;
typedef struct B2Cfg
{
  s32 unk0;
  s32 unk4;
  s32 unk8;
  s32 unkC;
  s32 unk10;
  s32 unk14;
  s32 unk18;
} B2Cfg;
typedef struct B2Rec
{
  u8 pad0[0xC];
  u16 flags;
  u16 id;
} B2Rec;
typedef struct B2GameFlags
{
  u8 pad0[0x1C];
  s32 unk1C;
  s32 unk20;
  u8 pad24[0x30];
  s32 unk54;
  u8 pad58[0x10];
  s32 unk68;
  u8 pad6C[0xC];
  s32 unk78;
  u8 pad7C[0x1C];
  s32 unk98;
  s32 unk9C;
  s32 unkA0;
  s32 unkA4;
} B2GameFlags;
typedef struct B2World
{
  u8 pad0[0x1860];
  B2GameFlags flags;
} B2World;
typedef struct B2Opts
{
  s32 w0;
  s32 w[6];
} B2Opts;
typedef struct B2Blk80
{
  s32 w[20];
} B2Blk80;
typedef struct B2Hit
{
  u8 pad0[0xFC];
  s32 type;
} B2Hit;
f32 func_00209308(B2Ctl *ctl, Vec3f *target, f32 a2, f32 a3);
s32 func_00209828(B2Ctl *ctl);
Vec3f *func_0020C994(B2Mgr *m, s32 idx);
B2Edge *func_0020C9B0(B2Mgr *m, s32 idx);
s32 func_0020CC0C(B2Mgr *m, s32 x, s32 y);
B2Node *func_0020CFE0(B2Mgr *m, s32 key);
typedef struct B2T
{
  u8 pad[0x18];
  s32 *p18;
} B2T;
B2T *func_0024E690(B2Actor *a);
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
f32 func_00272768(Vec3f *a, Vec3f *b);
extern B2Mgr D_8013B364;
extern f32 D_800C6CA8;
extern f32 D_800C6CAC;
extern f32 D_800C6CB0;
extern f32 D_800C6CB4;
extern f32 D_800C6CB8;
extern f32 D_800C6CBC;
extern f32 D_800C6CC0;
extern f32 D_800C6CC4;
extern f32 D_800C6CC8;
void func_00208410(B2Ctl *ctl)
{
  Vec3f d;
  Vec3f *self;
  Vec3f *cur;
  Vec3f *tgt;
  Vec3f *p;
  Vec3f *cur2;
  B2Actor *o;
  B2Edge *e;
  B2Node *n;
  f32 dist;
  f32 lim;
  f32 len;
  f32 w;
  s32 edge;
  s32 from;
  s32 st;
  s32 v;
  s32 flag;
  s32 nx;
  s32 f2;
  s32 f1;
  s32 fl;
  B2T *t;
  B2Mgr *m = &D_8013B364;
  o = ctl->owner;
  if ((ctl->unkC != (-1)) && ((ctl->unk300 = 0, ctl->unk310 = 0, ctl->unk304 = 0, ctl->unk308 = 0, ctl->unk30C = 0, ctl->q[0] != (-1))))
  {
    cur = func_0020C994(m, ctl->q[0]);
    self = &ctl->owner->pos;
    dist = func_00272768(self, cur);
    ctl->unk304 = ((*((u32 *) (((u8 *) cur) + 0xC))) & 0x300000) != 0;
    from = ctl->q[0];
    v = ctl->unk4;
    if (from == v)
    {
      edge = func_0020CC0C(m, ctl->unk8, from);
    }
    else
    {
      edge = func_0020CC0C(m, v, from);
    }
    if (edge > 0)
    {
      e = func_0020C9B0(m, edge);
      if (e->kind == 4)
      {
        ctl->unk30C = 1;
      }
      if (e->kind == 8)
      {
        func_00272768(self, func_0020C994(m, ctl->unk4));
        tgt = func_0020C994(m, ctl->q[0]);
        ctl->unk308 = 1;
        if (edge != ctl->unk32C)
        {
          ctl->unk314 = 0;
          ctl->unk32C = edge;
        }
        if (ctl->unk314 == 0)
        {
          cur2 = func_0020C994(m, ctl->unk4);
          func_00271FD8(&d, self, cur2);
          ;
          if (sqrtf((d.x * d.x) + (d.z * d.z)) < D_800C6CA8)
          {
            ctl->unk314 = 1;
          }
          else
          {
            ctl->v2C = *cur2;
            return;
          }
        }
        if (ctl->unk314 == 1)
        {
          ctl->v2C = *tgt;
          w = func_00209308(ctl, &ctl->v2C, 2.0f, 0.0f);
          if ((w < 0.0f) ? (D_800C6CAC < (-w)) : (D_800C6CB0 < w))
          {
            ctl->unk310 = 1;
            return;
          }
          ctl->unk314 = 2;
        }
        if (ctl->unk314 == 2)
        {
          ctl->v2C = *tgt;
          ctl->unk314 = 3;
          return;
        }
        if (ctl->unk314 == 3)
        {
          ctl->v2C = *tgt;
          ctl->unk314 = 4;
          return;
        }
        if (ctl->unk314 == 4)
        {
          ctl->v2C = *tgt;
          ctl->unk314 = 5;
          return;
        }
        if (ctl->unk314 == 5)
        {
          ctl->v2C = *tgt;
          o->unk6B0 |= 0x10;
          ctl->unk314 = 6;
          return;
        }
        if (ctl->unk314 == 6)
        {
          fl = ctl->owner->flags38;
          f1 = fl & 0x2000;
          f2 = fl & 0x1000;
          if (f1 || f2)
          {
            ctl->unk314 = 2;
          }
          ctl->v2C = *tgt;
        }
      }
      else
        if (e->kind == 5)
      {
        if (ctl->unk314 == 0)
        {
          p = func_0020C994(m, ctl->unk4);
          if (func_00272768(self, p) < D_800C6CB4)
          {
            ctl->unk314 = 1;
          }
          else
          {
            ctl->v2C = *p;
            return;
          }
        }
        st = ctl->unk314;
        if (st == 1)
        {
          n = func_0020CFE0(m, ctl->unk4);
          if (func_00272768(&n->unk40->pos, &n->v44) < D_800C6CB8)
          {
            ctl->v2C = n->unk40->pos;
            o->unk6B0 |= 0x10;
            ctl->unk314 = 2;
            return;
          }
          ctl->v2C = n->v44;
          ctl->unk310 = st;
        }
        if (ctl->unk314 == 2)
        {
          flag = 0;
          t = func_0024E690(ctl->owner);
          if (t != ((void *) 0))
          {
            flag = (*t->p18) == 2;
          }
          func_00271FD8(&d, self, &func_0020CFE0(m, ctl->unk4)->unk40->pos);
          len = sqrtf((d.x * d.x) + (d.z * d.z));
          if ((flag != 0) && (len < D_800C6CBC))
          {
            ctl->unk314 = 3;
          }
          else
          {
            ctl->v2C = func_0020CFE0(m, ctl->unk4)->unk40->pos;
            return;
          }
        }
        if (ctl->unk314 == 3)
        {
          flag = 0;
          t = func_0024E690(ctl->owner);
          if (t != ((void *) 0))
          {
            flag = (*t->p18) == 2;
          }
          if (flag == 0)
          {
            ctl->unk314 = 0;
          }
          cur = func_0020C994(m, ctl->q[0]);
          n = func_0020CFE0(m, ctl->q[0]);
          if (func_00272768(&n->unk40->pos, &n->v44) < D_800C6CC0)
          {
            ctl->v2C = *cur;
            o->unk6B0 |= 0x10;
          }
          else
          {
            ctl->v2C = *cur;
            ctl->unk310 = 1;
            return;
          }
        }
      }
      else
      {
        ctl->unk314 = 0;
      }
    }
    else
    {
      ctl->unk314 = 0;
    }
    if (ctl->q[1] == (-1))
    {
      lim = D_800C6CC8;
    }
    else
    {
      lim = D_800C6CC4;
      if (((*((u16 *) (((u8 *) cur) + 0xC))) & 0x100) != 0)
      {
        lim = D_800C6CC8;
      }
    }
    if ((dist < lim) && (ctl->unk4 == ctl->q[0]))
    {
      if (func_00209828(ctl) == 0)
      {
        return;
      }
    }
  }
  else
  {
    ctl->unk300 = 1;
    return;
  }
  if (ctl->q[0] != (-1))
  {
    cur = func_0020C994(m, ctl->q[0]);
    if ((*((u16 *) (((u8 *) cur) + 0xC))) & 2)
    {
      ctl->v2C = ctl->dst1B0;
      return;
    }
    ctl->v2C = *cur;
  }
}
