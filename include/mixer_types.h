#ifndef MIXER_TYPES_H
#define MIXER_TYPES_H

#include "libaudio.h"

/* ---- RSP audio ABI command encoders (N64 SDK abi.h, 2.0-style 32-bit word pairs) ---- */
#define A_CLEARBUFF 2
#define A_ENVMIXER 3
#define A_LOADBUFF 4
#define A_RESAMPLE 5
#define A_SAVEBUFF 6
#define A_SETBUFF 8
#define A_SETVOL 9
#define A_MIXER 12
#define A_INTERLEAVE 13
#define A_DMEMMOVE 10
#define A_LOADADPCM 11
#define A_POLEF 14

#define A_INIT 0x01
#define A_RATE 0x00
#define A_LEFT 0x02
#define A_RIGHT 0x00
#define A_VOL 0x04
#define A_AUX 0x08

#define _AS(v, s, w) ((((u32)(v)) & ((1U << (w)) - 1)) << (s))

#define aClearBuffer(pkt, d, c) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_CLEARBUFF, 24, 8) | _AS(d, 0, 24); \
    _a->w1 = (u32)(c); }

#define aLoadBuffer(pkt, s) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_LOADBUFF, 24, 8); \
    _a->w1 = (u32)(s); }

#define aSaveBuffer(pkt, s) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_SAVEBUFF, 24, 8); \
    _a->w1 = (u32)(s); }

#define aSetBuffer(pkt, f, i, o, c) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_SETBUFF, 24, 8) | _AS(f, 16, 8) | _AS(i, 0, 16); \
    _a->w1 = _AS(o, 16, 16) | _AS(c, 0, 16); }

#define aMix(pkt, f, g, i, o) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_MIXER, 24, 8) | _AS(f, 16, 8) | _AS(g, 0, 16); \
    _a->w1 = _AS(i, 16, 16) | _AS(o, 0, 16); }

#define aEnvMixer(pkt, f, s) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_ENVMIXER, 24, 8) | _AS(f, 16, 8); \
    _a->w1 = (u32)(s); }

#define aSetVol(pkt, f, v, t, r) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_SETVOL, 24, 8) | _AS(f, 16, 8) | _AS(v, 0, 16); \
    _a->w1 = _AS(t, 16, 16) | _AS(r, 0, 16); }

#define aDMEMMove(pkt, i, o, c) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_DMEMMOVE, 24, 8) | _AS(i, 0, 24); \
    _a->w1 = _AS(o, 16, 16) | _AS(c, 0, 16); }

#define aResample(pkt, f, p, s) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_RESAMPLE, 24, 8) | _AS(f, 16, 8) | _AS(p, 0, 16); \
    _a->w1 = (u32)(s); }

#define aLoadADPCM(pkt, c, d) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_LOADADPCM, 24, 8) | _AS(c, 0, 24); \
    _a->w1 = (u32)(d); }

#define aPoleFilter(pkt, f, g, s) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_POLEF, 24, 8) | _AS(f, 16, 8) | _AS(g, 0, 16); \
    _a->w1 = (u32)(s); }

#define aInterleave(pkt, l, r) { \
    Acmd *_a = (Acmd *)(pkt); \
    _a->w0 = _AS(A_INTERLEAVE, 24, 8); \
    _a->w1 = _AS(l, 16, 16) | _AS(r, 0, 16); }


/* ---- filter parameter ids (SDK synthInternals.h AL_FILTER_*) used by the mixer filters ---- */
#define AL_FILTER_FREE_VOICE 0
#define AL_FILTER_SET_SOURCE 1
#define AL_FILTER_ADD_SOURCE 2
#define AL_FILTER_ADD_UPDATE 3
#define AL_FILTER_RESET 4
#define AL_FILTER_SET_WAVETABLE 5
#define AL_FILTER_SET_PITCH 7
#define AL_FILTER_START 9
#define AL_FILTER_SET_UNITY_PITCH 8

/* envelope mixer filter (env.c): full layout of the 0x4C byte node */
typedef struct {
    ALFilter filter;      /* 0x00 */
    void *state;          /* 0x14 ENVMIX_STATE (0x50 bytes) */
    s16 pan;              /* 0x18 */
    s16 volume;           /* 0x1A */
    s16 cvolL;            /* 0x1C */
    s16 cvolR;            /* 0x1E */
    s16 dryamt;           /* 0x20 */
    s16 wetamt;           /* 0x22 */
    u16 lratl;            /* 0x24 */
    s16 lratm;            /* 0x26 */
    s16 ltgt;             /* 0x28 */
    u16 rratl;            /* 0x2A */
    s16 rratm;            /* 0x2C */
    s16 rtgt;             /* 0x2E */
    s32 delta;            /* 0x30 */
    s32 segEnd;           /* 0x34 */
    s32 first;            /* 0x38 */
    ALParam *ctrlList;    /* 0x3C */
    ALParam *ctrlTail;    /* 0x40 */
    s32 pad44;            /* 0x44 */
    s32 motion;           /* 0x48 */
} ALEnvMixerFull;

/* resampler filter (resample.c): full layout of the 0x34 byte node (delta is a float fraction) */
typedef struct {
    ALFilter filter;      /* 0x00 */
    void *state;          /* 0x14 RESAMPLE_STATE (0x20 bytes) */
    f32 ratio;            /* 0x18 */
    s32 upitch;           /* 0x1C unity-pitch flag */
    f32 delta;            /* 0x20 */
    s32 first;            /* 0x24 */
    void *ctrlList;       /* 0x28 */
    void *ctrlTail;       /* 0x2C */
    s32 motion;           /* 0x30 */
} ALResamplerFull;

/* ---- reverb (reverb.c) ---- */
typedef struct {
    s16 fc;               /* 0x00 cutoff parameter */
    s16 fgain;            /* 0x02 */
    s16 pad04[2];         /* 0x04 */
    s16 fcoef[16];        /* 0x08 codebook loaded with aLoadADPCM (0x20 bytes) */
    s16 *fstate;          /* 0x28 8 byte filter state allocated from the heap */
    s32 first;            /* 0x2C */
} ALLowPassFx;            /* 0x30 bytes */            /* 0x30 bytes (a further 8 byte block is allocated for state) */

typedef struct {
    u32 input;            /* 0x00 */
    u32 output;           /* 0x04 */
    s16 ffcoef;           /* 0x08 */
    s16 fbcoef;           /* 0x0A */
    s16 gain;             /* 0x0C */
    s16 pad0E;            /* 0x0E */
    f32 rsinc;            /* 0x10 */
    f32 rsval;            /* 0x14 */
    s32 rsdelta;          /* 0x18 */
    f32 rsgain;           /* 0x1C */
    ALLowPassFx *lp;      /* 0x20 */
    ALResamplerFull *rs;  /* 0x24 */
} ALDelayFx;              /* 0x28 bytes */

typedef struct {
    ALFilter filter;      /* 0x00 */
    s16 *base;            /* 0x14 start of the delay line buffer */
    s16 *input;           /* 0x18 current input position */
    u32 length;           /* 0x1C buffer length in samples */
    ALDelayFx *delay;     /* 0x20 */
    u8 sectionCount;      /* 0x24 */
    u8 pad25[3];
    s32 (*paramHdl)(void *filter, s32 paramID, void *param); /* 0x28 */
} ALFxFilter;

/* synthesizer configuration as read by alFxNew (libaudio.h ALSynConfig plus the custom reverb parameter pointer) */
typedef struct {
    s32 maxVVoices;       /* 0x00 */
    s32 maxPVoices;       /* 0x04 */
    s32 maxUpdates;       /* 0x08 */
    s32 maxFXbusses;      /* 0x0C */
    void *dmaproc;        /* 0x10 */
    void *heap;           /* 0x14 */
    s32 outputRate;       /* 0x18 */
    u8 fxType;            /* 0x1C */
    u8 pad1D[3];
    s32 *params;          /* 0x20 custom reverb parameter table */
} ALSynConfigFx;

#endif
