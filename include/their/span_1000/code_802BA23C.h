#ifndef UNBAKE_SPAN_1000_CODE_802BA23C_H
#define UNBAKE_SPAN_1000_CODE_802BA23C_H
#include "acmd.h"
#include "../types.h"
/* unbake published declaration: published_14ac85407d47a435bfe7dd9d */
extern void func_802BA210_de(void);

struct __OSViScale;
/* unbake published declaration: published_2141d574c5007fec06210fd9 */
struct __OSViScale {
    f32 factor;
    u16 offset;
    u32 scale;
};

/* unbake published declaration: published_301251ef611b7187130e0478 */
extern float D_800C79D8_de;

struct __OSViContext_func_802BA6B0_de;
/* unbake published declaration: published_3a7b290c37d1cb6307eb3314 */
typedef struct __OSViContext_func_802BA6B0_de __OSViContext_func_802BA6B0_de;

struct OSIoMesgHdr_func_802BA350_de;
struct OSMesgQueue;
/* unbake published declaration: published_3b7f02bacc6efdc47674121f */
struct OSIoMesgHdr_func_802BA350_de {
    u16 type;
    u8 pri;
    u8 status;
    struct OSMesgQueue *retQueue;
};

struct OSDevMgr_func_802BA350_de;
struct OSMesgQueue;
struct OSThread;
/* unbake published declaration: published_40b74f57928bcda9e8ed14fc */
struct OSDevMgr_func_802BA350_de {
    u32 active;
    struct OSThread *thread;
    struct OSMesgQueue *cmdQueue;
    struct OSMesgQueue *evtQueue;
    struct OSMesgQueue *acsQueue;
    s32 (*dma)(s32, u32, void *, u32);
    s32 (*edma)(void *, s32, u32, void *, u32);
};

struct OSIoMesg_func_802BA350_de;
/* unbake published declaration: published_48645c8e2bd1dc108dc82a7b */
typedef struct OSIoMesg_func_802BA350_de OSIoMesg_func_802BA350_de;

/* unbake published declaration: published_49077aa82be10b1d44e1e26c */
extern void func_802BA700_de(s32 arg0);

/* unbake published declaration: published_58a595ea0132b629e097fd5c */
extern void *func_802BA310_de();

struct OSViCommonRegs;
/* unbake published declaration: published_5a5034b1d98bb6e67ce2ebfb */
struct OSViCommonRegs {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
};

struct Rec_func_802BA650_de;
/* unbake published declaration: published_6136ae06d0ed26218bbd1605 */
typedef struct Rec_func_802BA650_de Rec_func_802BA650_de;

/* unbake published declaration: published_61e98354201d75ab0bc4e4c2 */
extern double D_800C79D0_de;

struct OSIoMesgHdr_func_802BA350_de;
/* unbake published declaration: published_62c81cd232f080cc9cae81bc */
typedef struct OSIoMesgHdr_func_802BA350_de OSIoMesgHdr_func_802BA350_de;

struct OSViFieldRegs;
/* unbake published declaration: published_6efe59496245b2cecebd9740 */
typedef struct OSViFieldRegs OSViFieldRegs;

struct Rec_func_802BA650_de;
/* unbake published declaration: published_713c8f52bb58757b08faf62f */
struct Rec_func_802BA650_de {
    char pad0[2];
    s16 f2;
    char pad4[0xC];
    s32 f10;
    s32 f14;
};

struct ObjectState28;
/* unbake published declaration: published_791b6c36c2e3b71a3bd193aa */
struct ObjectState28 {
    u16 unk_0;
    unsigned char padding_2[34];
    f32 unk_24;
};

struct OSViMode;
/* unbake published declaration: published_c16b9e13ddca780e75c50a04 */
struct OSViMode {
    u8 type;
    Awords comRegs;
};

struct OSViMode;
struct __OSViContext_func_802BA6B0_de;
/* unbake published declaration: published_89290a24f195788db1672677 */
struct __OSViContext_func_802BA6B0_de {
    u16 state;
    u16 retraceCount;
    void *framep;
    struct OSViMode *modep;
    u32 control;
};

struct OSIoMesg_func_802BA350_de;
/* unbake published declaration: published_8e4210376321f1958af0b39c */
struct OSIoMesg_func_802BA350_de {
    OSIoMesgHdr_func_802BA350_de hdr;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    void *piHandle;
};

/* unbake published declaration: published_983e22238dda66d544ead2f9 */
extern void func_802BA910_de();

struct OSViCommonRegs;
/* unbake published declaration: published_9a6c8eeda473eabf0b638d47 */
typedef struct OSViCommonRegs OSViCommonRegs;

struct OSViFieldRegs;
/* unbake published declaration: published_cedd583b9291fdb02c6b5d1c */
struct OSViFieldRegs {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
};

struct OSViMode_func_802BA910_de;
/* unbake published declaration: published_9e0f543142b5a9fae85517e8 */
struct OSViMode_func_802BA910_de {
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
};

struct ObjectState28;
/* unbake published declaration: published_a0bbb2ecb6f57fabb47c1153 */
typedef struct ObjectState28 ObjectState28;

/* unbake published declaration: published_a548a3d63623f51de43886a6 */
extern void func_802BA870_de(f32 arg0);

struct OSViMode_func_802BA910_de;
/* unbake published declaration: published_a7d890346fba849e3a057d0d */
typedef struct OSViMode_func_802BA910_de OSViMode_func_802BA910_de;

struct OSViMode;
/* unbake published declaration: published_afe5e984aae8dedd502aea9b */
typedef struct OSViMode OSViMode;

struct __OSViScale;
/* unbake published declaration: published_b08d4313a47680055b0e75d0 */
typedef struct __OSViScale __OSViScale;

struct OSViMode_func_802BA910_de;
struct __OSViContext_func_802BA910_de;
/* unbake published declaration: published_bbd9379487d19881c33d00a2 */
struct __OSViContext_func_802BA910_de {
    u16 state;
    u16 retraceCount;
    void *framep;
    struct OSViMode_func_802BA910_de *modep;
    u32 control;
    void *msgq;
    void *msg;
    __OSViScale x;
    __OSViScale y;
};

struct State_func_802BA700_de;
/* unbake published declaration: published_c8e2b08e6d8cd1c3dd829876 */
typedef struct State_func_802BA700_de State_func_802BA700_de;

struct State_func_802BA700_de;
/* unbake published declaration: published_d205480b7a0be87a3601c3be */
struct State_func_802BA700_de {
    u16 status;
    u16 pad2;
    u32 word4;
    Awords *inner;
    u32 flags;
};

struct OSDevMgr_func_802BA350_de;
/* unbake published declaration: published_e24f743836ce4aee1b155c6e */
typedef struct OSDevMgr_func_802BA350_de OSDevMgr_func_802BA350_de;

struct __OSViContext_func_802BA910_de;
/* unbake published declaration: published_e4dcfdc4624a3580227eb5de */
typedef struct __OSViContext_func_802BA910_de __OSViContext_func_802BA910_de;

/* unbake published declaration: published_efaa7614cf4a6144cc155d43 */
extern void func_802BA350_de(s32 pri);

#endif
