
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
typedef struct O02Slider
{
  u8 pad0[0x44];
  s32 min;
  s32 max;
  s32 step;
  s32 val;
  u8 pad54[0x6C - 0x54];
  s32 unk6C;
} O02Slider;
typedef struct 
{
  s32 w[4];
} O02Rect;
typedef struct 
{
  s32 w[5];
  u8 col;
  u8 padc[3];
  s32 w2[4];
} O02Ctx;
typedef struct O02Item
{
  s32 w0;
  f32 f4;
  f32 f8;
  f32 fC;
  f32 f10;
  u16 f14;
  u16 f16;
} O02Item;
typedef struct 
{
  s32 b[4];
  O02Item *items;
  s32 count;
} O02Ent;
typedef struct 
{
  u8 pad[8];
  s16 v;
} S_func_00413BD4;
extern S_func_00413BD4 *D_80153D58;
extern s32 D_80153CAC;
extern s32 D_80153CA0;
extern s32 D_80153CA4;
extern s32 D_80153CA8;
extern s32 D_80153CC0;
extern s32 D_80153CC4;
extern s32 D_80153CC8;
extern s32 D_80153CCC;
extern s32 D_80153C6C;
extern s32 D_80153C74;
extern void (*D_80153CD4)(s32);
void func_00413BD4(s32 base, s32 n, u32 argb)
{
  u32 r = (argb >> 16) & 0xFF;
  u32 g = (argb & 0xFF00) >> 8;
  u32 b = argb & 0xFF;
  u32 a = argb >> 24;
  void (*fn)(s32);
  u32 v;
  s32 off;
  if (D_80153CAC == 0)
  {
    a = 0xFF;
  }
  do
  {
    r = (D_80153CC0 < 0) ? ((r >> (-D_80153CC0)) & D_80153CA0) : ((r << D_80153CC0) & D_80153CA0);
    g = (D_80153CC4 < 0) ? ((g >> (-D_80153CC4)) & D_80153CA4) : ((g << D_80153CC4) & D_80153CA4);
    b = (D_80153CC8 < 0) ? ((b >> (-D_80153CC8)) & D_80153CA8) : ((b << D_80153CC8) & D_80153CA8);
    a = (D_80153CCC < 0) ? ((a >> (-D_80153CCC)) & D_80153CAC) : ((a << D_80153CCC) & D_80153CAC);
    off = n * D_80153D58->v;
    v = ((r | g) | b) | a;
    D_80153C74 = v;
  }
  while (0);
  fn = D_80153CD4;
  D_80153C6C = base + off;
  fn(base);
}
