
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
typedef union M1IF
{
  s32 i;
  f32 f;
} M1IF;
typedef union M1W4
{
  s32 i;
  f32 f;
  s16 h[2];
  u16 hu[2];
  u8 b[4];
  u32 u;
} M1W4;
typedef struct M1Vec4
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} M1Vec4;
typedef union M1B1
{
  s8 s;
  u8 u;
} M1B1;
typedef struct M1Info M1Info;
typedef struct M1Def M1Def;
typedef struct M1Actor M1Actor;
typedef struct M1State M1State;
typedef struct M1Ev M1Ev;
typedef struct M1Ref M1Ref;
typedef struct M1Stats M1Stats;
typedef struct M1Blk M1Blk;
typedef struct M1World M1World;
typedef struct M1Pad M1Pad;
typedef struct M1Ctl M1Ctl;
typedef struct M1CRef M1CRef;
typedef struct M1Out M1Out;
typedef struct M1Cam M1Cam;
typedef struct M1CamRec M1CamRec;
struct M1Info
{
  u32 flags;
  M1W4 unk4;
  s8 b8;
  u8 pad9[0x3];
  s32 unkC;
  u8 pad10[0x8];
  s32 unk18;
  s32 unk1C;
  M1W4 unk20;
  M1W4 unk24;
  M1W4 unk28;
  f32 f2C;
  f32 f30;
  f32 f34;
  u8 pad38[0x4];
  f32 f3C;
  M1W4 unk40;
  f32 f44;
  M1W4 unk48;
  M1W4 unk4C;
  u8 b50[4];
  f32 f54;
  f32 f58;
  f32 f5C;
  f32 f60;
  f32 f64;
  f32 f68;
  u8 pad6C[0x4];
  u8 b70;
  u8 b71;
};
struct M1Def
{
  s32 kind;
  u32 unk4;
  u8 pad8[0xC];
  M1Info info;
};
struct M1Actor
{
  u8 pad0[0x1];
  u8 unk1;
  u8 pad2[0x6];
  Vec3f pos;
  s32 unk14;
  M1Def *def;
  u8 pad1C[0x1C];
  u32 flags38;
  u8 pad3C[0x14];
  f32 f50;
  f32 f54;
  f32 f58;
  Vec3f v5C;
  u8 pad68[0x4];
  f32 f6C;
  f32 f70;
  u8 mtx74[0x40];
  u8 padB4[0x30];
  u16 unkE4;
  s8 unkE6;
  u8 padE7[0x19];
  u32 flags;
  f32 f104;
  s16 h108;
  s16 h10A;
  s16 h10C;
  u8 pad10E[0x1E];
  s16 h12C;
  u8 pad12E[0x6];
  f32 f134;
  u8 pad138[0x64];
  s32 unk19C;
  u8 pad1A0[0x38];
  M1Actor *owner;
  u8 pad1DC[0x104];
  u32 unk2E0;
  u8 pad2E4[0x2F4];
  M1Stats *stats;
  void *pawn;
  u8 pad5E0[0x4];
  s32 unk5E4;
  u8 pad5E8[0x2];
  s16 h5EA;
  u8 pad5EC[0x64];
  s16 h650;
  u8 pad652[0x46];
  M1Pad *pad;
  u8 pad69C[0xEC];
  s32 unk788;
  u8 pad78C[0x8];
  M1Actor *unk794;
  u8 pad798[0xF48];
  M1Actor *next;
};
struct M1State
{
  u8 pad0[0x4];
  s32 unk4;
  s32 unk8;
  u8 padC[0x28];
  s8 unk34;
  s8 unk35;
  s8 unk36;
  s8 unk37;
  u8 pad38[0x4];
  u32 flags3C;
  f32 f40;
  f32 f44;
  Vec3f v48;
  Vec3f v54;
  f32 f60;
  f32 f64;
  u8 pad68[0x18];
  M1Actor *unk80;
  u8 pad84[0x18];
  f32 f9C;
  Vec3f vA0;
  u8 padAC[0x1E];
  u8 unkCA;
  s8 unkCB;
  u8 padCC[0x1];
  u8 unkCD;
  u8 padCE[0x2E];
  M1Ref *unkFC;
  u8 pad100[0x8];
  void (*fn108)();
  u8 pad10C[0x18];
  M1IF unk124;
  M1IF unk128;
  M1IF unk12C;
  Vec3f vec130;
  f32 f13C;
};
struct M1Ev
{
  u8 pad0[0x4];
  s32 unk4;
  u8 pad8[0x4];
  u32 flags;
};
struct M1Ref
{
  u8 pad0[0xC];
  s32 unkC;
};
struct M1Stats
{
  u8 pad0[0x8];
  u16 h8;
  u8 padA[0x85];
  u8 b8F;
  u8 b90;
  u8 pad91[0x1];
  u8 b92;
};
struct M1Blk
{
  u8 pad0[0x68];
  s32 unk68;
  u8 pad6C[0x8];
  s32 unk74;
  u8 pad78[0x8];
  s32 unk80;
  s32 unk84;
};
struct M1World
{
  u8 pad0[0x1860];
  M1Blk blk;
};
struct M1Pad
{
  u8 pad0[0xC6];
  M1B1 stickX;
  M1B1 stickY;
};
struct M1Ctl
{
  u8 pad0[0x4];
  s32 unk4;
  u8 pad8[0x28];
  M1CRef *unk30;
  u8 pad34[0x3];
  s8 b37;
  u8 pad38[0x30];
  M1Actor *unk68;
  u8 pad6C[0xC];
  M1Actor *unk78;
  u8 pad7C[0x4];
  M1Actor *unk80;
  s32 unk84;
  u8 pad88[0x4];
  f32 f8C;
  f32 f90;
  s8 b94;
  u8 pad95[0x1B];
  Vec3f vB0;
  s32 unkBC;
};
struct M1CRef
{
  u8 pad0[0xC];
  s32 unkC;
};
struct M1Out
{
  u8 pad0[0x4];
  M1Actor *tgt;
  u8 pad8[0x38];
  f32 f40;
  u8 pad44[0x44];
};
struct M1Cam
{
  u8 pad0[0x54];
  Vec3f p54;
  u8 pad60[0x34];
  u8 h94[4];
  u8 pad98[0x9C];
  f32 f134;
  f32 f138;
  u8 pad13C[0x4];
  f32 f140;
  f32 f144;
  f32 f148;
  f32 f14C;
  f32 f150;
  f32 f154;
  f32 f158;
  f32 f15C;
  f32 f160;
  f32 f164;
  f32 f168;
  f32 f16C;
};
struct M1CamRec
{
  Vec3f pos;
  u8 padC[0x4];
  f32 f10;
  M1W4 fw;
  u8 pad18[0x4];
  f32 f1C;
  f32 f20;
  f32 f24;
  f32 f28;
  f32 f2C;
  f32 f30;
  f32 f34;
};
typedef struct Blk50
{
  s32 w[20];
} Blk50;
extern f32 D_800C7258;
extern u8 D_80104030[];
extern M1Actor *D_801041F0;
extern u8 D_80145040[];
s32 func_00214624(M1Actor *a, M1Ctl *c, M1Actor *t);
f32 func_00217224(M1Actor *t, Vec3f pos);
f32 func_00217290(M1Actor *t, Vec3f pos);
M1Actor *func_0022A470(u8 *w, Vec3f pos);
M1Actor *func_0022A4F4(u8 *w, Vec3f pos, M1Actor *o);
s32 func_00244494(M1Actor *a, Vec3f pos, Vec3f target, u8 *out);
s32 func_00245788();
s32 func_00245AFC(void);
f32 func_0024D274(M1Actor *a);
s32 func_0024DE5C(M1Actor *a);
f32 func_0024E560(M1Actor *a);
void func_0024E7CC(M1Actor *a);
M1Actor *func_002149C0(M1Actor *actor, M1Ctl *ctl, s32 arg2, s32 flag)
{
  f32 new_var;
  M1Actor *list[128];
  Blk50 saved;
  Vec3f tpos;
  f32 best;
  f32 d;
  f32 fs0;
  f32 fs0f;
  M1Actor *best_a;
  M1Actor *t;
  s32 n;
  s32 i;
  int new_var2;
  s32 ok;
  s32 r;
  register s32 one asm("$18");
  if (ctl->unk78 != ((void *) 0))
  {
    if (flag != 0)
    {
      func_00214624(actor, ctl, ctl->unk78);
    }
    return ctl->unk78;
  }
  n = 0;
  best_a = (void *) 0;
  new_var2 = 0;
  ok = 1;
  if (func_00245788() != 0)
  {
    ok = 0;
    if (func_00245AFC() >= 10)
    {
      ok = func_00245AFC() < 61;
    }
  }
  if (ok)
  {
    if (flag != 0)
    {
      t = ctl->unk68;
      if (t != ((void *) 0))
      {
        list[n] = t;
        n++;
      }
    }
    if (!(actor->def->unk4 & 0x400))
    {
      if (actor->flags & 0x300000)
      {
        t = func_0022A4F4(D_80145040, actor->pos, actor->owner);
      }
      else
      {
        t = func_0022A470(D_80145040, actor->pos);
      }
      if (((t != ((void *) 0)) && (t->h5EA != 0)) && (t->h650 != ({ one = 1; __asm__("" : "+r"(one)); one; })))
      {
        func_0024E7CC(t);
        if (t != ((void *) new_var2))
        {
          list[n] = t;
          n++;
        }
      }
    }
    best = D_800C7258;
    i = 0;
    best_a = (void *) 0;
    if (n > 0)
    {
      do
      {
        t = list[i];
        d = func_00217224(t, actor->pos);
        if (d < best)
        {
          if (flag != 0)
          {
            if ((actor->def->kind == 1) && (ctl->b37 == 0))
            {
              goto next;
            }
            if (func_0024DE5C(actor) != 0)
            {
              fs0f = func_00217290(t, ctl->vB0);
              new_var = func_0024E560(actor);
              fs0 = new_var;
              fs0 = fs0 * func_0024E560(actor);
              if (fs0 <= fs0f)
              {
                goto next;
              }
            }
            if (func_00214624(actor, ctl, t) == 0)
            {
              goto next;
            }
          }
          if (arg2 != 0)
          {
            saved = *((Blk50 *) actor);
            actor->pos.y = actor->pos.y + func_0024D274(actor);
            actor->pos.y = actor->pos.y + t->f70;
            tpos = t->pos;
            tpos.y = tpos.y + func_0024D274(t);
            tpos.y = tpos.y + t->f70;
            r = func_00244494(actor, actor->pos, tpos, D_80104030);
            if (D_801041F0 == t)
            {
              r = 0;
            }
            *((Blk50 *) actor) = saved;
            if (r != 0)
            {
              goto next;
            }
          }
          best = d;
          best_a = t;
        }
        next:
        i++;

      }
      while (i < n);
    }
  }
  if (((flag != 0) && (best_a == ((void *) 0))) && (func_00214624(actor, ctl, (void *) 0) == 0))
  {
    ctl->vB0 = actor->pos;
    ctl->unkBC = actor->unk14;
  }
  return best_a;
}
