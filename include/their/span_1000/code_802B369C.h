#ifndef UNBAKE_SPAN_1000_CODE_802B369C_H
#define UNBAKE_SPAN_1000_CODE_802B369C_H
#include "acmd.h"
#include "audio_callbacks.h"
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct ALAuxBus_s;
/* unbake published declaration: published_03cc47049a59a055b0c0f154 */
typedef struct ALAuxBus_s ALAuxBus_s;

struct ALLoadFilter;
/* unbake published declaration: published_0f876469c3cb93ae49907dbd */
typedef struct ALLoadFilter ALLoadFilter;

struct ALParam_s1C;
/* unbake published declaration: published_26aeff4edc7b172c5cc415ca */
struct ALParam_s1C {
    struct ALParam_s1C *next;
    s32 delta;
    s16 type;
    s32 data;
    s32 moredata;
    s32 stillmoredata;
    s32 yetstillmoredata;
};

/* unbake published declaration: published_2927a19d519a4d162cd64152 */
extern void func_802B36F0_de(void *arg0, void *arg1);

struct ALResampler;
/* unbake published declaration: published_2ea823768aa1e3093873b950 */
typedef struct ALResampler ALResampler;

struct func_802B8CC8_S1;
/* unbake published declaration: published_359c5f9122fe948ed2591757 */
struct func_802B8CC8_S1 {
    char pad0[0x2C];
    void * unk2C;
};

struct ALParam_s1C;
/* unbake published declaration: published_3c4c186d8e198db4fe1adf41 */
typedef struct ALParam_s1C ALParam_s1C;

struct ALLoadFilter;
/* unbake published declaration: published_3c6fda96ed4bb9fb0df6bba5 */
struct ALLoadFilter {
    char pad[0x48];
};

struct ALFilter_sC;
/* unbake published declaration: published_5c2ac85bfc4fd0442dbda747 */
struct ALFilter_sC {
    struct ALFilter_sC *source;
    ALCmdHandler handler;
    ALSetParam setParam;
};

struct ALFilter_sC;
/* unbake published declaration: published_f2bee59fb22512be98a0d6ba */
typedef struct ALFilter_sC ALFilter_sC;

struct ALSynth4C;
/* unbake published declaration: published_3d158af4ae93f1615c099aeb */
struct ALSynth4C {
    ALPlayer_s14 *head;
    Link_func_802596B4_de pFreeList;
    Link_func_802596B4_de pAllocList;
    Link_func_802596B4_de pLameList;
    s32 paramSamples;
    s32 curSamples;
    void *dma;
    void *heap;
    void *paramList;
    void *mainBus;
    void *auxBus;
    ALFilter_sC *outputFilter;
    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;
};

/* unbake published declaration: published_47c26a89c97621b8e4d625be */
typedef void ( *Shared_func_802B36F0_de_FuncPtr)(void *, signed int, void *);

struct ALEnvMixer4C;
/* unbake published declaration: published_4913ac804a3d7ae0b8bba1a2 */
struct ALEnvMixer4C {
    char pad[0x4C];
};

struct ALSynth;
/* unbake published declaration: published_55e7132d1b0c07d2f3dfa81a */
typedef struct ALSynth ALSynth;

struct ALAuxBus_s;
/* unbake published declaration: published_594e88f190c636d7310804a5 */
struct ALAuxBus_s {
    ALFilter_s14 filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter_s14 **sources;
    char fx[0x4C - 0x20];
};

struct ALResampler;
/* unbake published declaration: published_601b503e2286628dba6e7fce */
struct ALResampler {
    char pad[0x34];
};

struct func_802B8CC8_S1;
/* unbake published declaration: published_60d17ef0e1e7c0f7a13fafa6 */
typedef struct func_802B8CC8_S1 func_802B8CC8_S1;

struct ALSynConfig;
/* unbake published declaration: published_75c1eeb559d2d06f7fae9461 */
typedef struct ALSynConfig ALSynConfig;

/* unbake published declaration: published_7a44c8d974ca80c93e886b94 */
typedef void *( *ALDMANew)(void *);

struct ALSave;
/* unbake published declaration: published_7aecc9c2a33ebc8bdb0d8fc1 */
typedef struct ALSave ALSave;

struct ALMainBus_s;
/* unbake published declaration: published_80538a407ee54023b0bcfd0c */
struct ALMainBus_s {
    ALFilter_s14 filter;
    s32 sourceCount;
    s32 maxSources;
    ALFilter_s14 **sources;
};

struct func_802B9474_S1;
/* unbake published declaration: published_83a62d722a9db69cc42c9fa7 */
struct func_802B9474_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x30 - 0x18 - sizeof(s32)];
    s32 unk30;
    char pad30[0x3C - 0x30 - sizeof(s32)];
    s32 unk3C;
    char pad3C[0x40 - 0x3C - sizeof(s32)];
    s32 unk40;
    char pad40[0x44 - 0x40 - sizeof(s32)];
    s32 unk44;
};

struct ALSynth4C;
/* unbake published declaration: published_875df75582fc829dba76a39d */
typedef struct ALSynth4C ALSynth4C;

struct ALSynConfig;
/* unbake published declaration: published_92c5cb40d105bb01ac37672e */
struct ALSynConfig {
    s32 maxVVoices;
    s32 maxPVoices;
    s32 maxUpdates;
    s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    s32 outputRate;
    u8 fxType;
    s32 *params;
};

struct ALGlobals;
/* unbake published declaration: published_92cd3e13c5bed37f1cdc2551 */
struct ALGlobals {
    ALSynth4C drvr;
};

struct PVoice_s;
/* unbake published declaration: published_9fe77916c4b8c8b2d68fe568 */
typedef struct PVoice_s PVoice_s;

struct ALEnvMixer4C;
/* unbake published declaration: published_c74d525cff5833c9cdcf05e8 */
typedef struct ALEnvMixer4C ALEnvMixer4C;

struct Opaque_ALVoice_s;
struct PVoice_s;
/* unbake published declaration: published_a95b8f251a6b019bbc127f8c */
struct PVoice_s {
    Link_func_802596B4_de node;
    struct Opaque_ALVoice_s *vvoice;
    ALFilter_s14 *channelKnob;
    ALLoadFilter decoder;
    ALResampler resampler;
    ALEnvMixer4C envmixer;
    s32 offset;
};

struct ALMainBus_s;
/* unbake published declaration: published_b4e0d50107330fc19ae907db */
typedef struct ALMainBus_s ALMainBus_s;

struct ObjectStateC_3;
/* unbake published declaration: published_b6612fef452673fbc3bceb5c */
typedef struct ObjectStateC_3 ObjectStateC_3;

struct func_802B9474_S1;
/* unbake published declaration: published_c9798f575ed78a685961a346 */
typedef struct func_802B9474_S1 func_802B9474_S1;

struct ObjectStateC_3;
/* unbake published declaration: published_cc594b0f3f0d2a4137d40181 */
struct ObjectStateC_3 {
    s32 unk_0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk_4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    s16 unk_8;
};

struct ALGlobals;
/* unbake published declaration: published_db3c8b050cb86564c6a1f8fb */
typedef struct ALGlobals ALGlobals;

struct ALSynth;
/* unbake published declaration: published_df87c353e238278de0f9eb4c */
struct ALSynth {
    void *head;
    Link_func_802596B4_de pFreeList;
    Link_func_802596B4_de pAllocList;
    Link_func_802596B4_de pLameList;
    s32 paramSamples;
    s32 curSamples;
    ALDMANew dma;
    ALHeap *heap;
    ALParam_s1C *paramList;
    ALMainBus_s *mainBus;
    ALAuxBus_s *auxBus;
    ALFilter_s14 *outputFilter;
    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;
};

struct ALSave;
/* unbake published declaration: published_fb6865ea01ae291621e12718 */
struct ALSave {
    ALFilter_s14 filter;
    s32 dramout;
    s32 first;
};

extern s32 func_802B3D10_de(ALSynth4C *drvr, ALPlayer_s14 **client);
#endif
