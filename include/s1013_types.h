#ifndef S1013_TYPES_H
#define S1013_TYPES_H

#include "libaudio.h"

/* ---- libaudio synthesizer drivers: reverb.c / resample.c / save.c / load.c (adpcm.c, raw16.c, adec) ----
   Types for the filters whose handlers are matched by worker s1013 (offsets recovered from the ROM code).
   Only libaudio.h (shared, read-only) is included; everything else is declared here so that each matched
   source file is self-contained (one #include). */

/* ---- RSP audio ABI command builders (SDK abi.h, 2.0 style word pairs) ---- */
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define K0_TO_PHYS(x) ((u32)(x) & 0x1FFFFFFF)

#define A_ADPCM 1
#define A_CLEARBUFF 2
#define A_LOADBUFF 4
#define A_RESAMPLE 5
#define A_SAVEBUFF 6
#define A_SETBUFF 8
#define A_DMEMMOVE 10
#define A_LOADADPCM 11
#define A_MIXER 12
#define A_INTERLEAVE 13
#define A_POLEF 14
#define A_SETLOOP 15

#define aClearBuffer(pkt, d, c) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = (_SHIFTL(A_CLEARBUFF, 24, 8) | _SHIFTL(d, 0, 24)); \
        _a->w1 = (u32)(c); \
    }

#define aLoadBuffer(pkt, s) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_LOADBUFF, 24, 8); \
        _a->w1 = (u32)(s); \
    }

#define aSaveBuffer(pkt, s) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_SAVEBUFF, 24, 8); \
        _a->w1 = (u32)(s); \
    }

#define aSetBuffer(pkt, f, i, o, c) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(i, 0, 16)); \
        _a->w1 = (_SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16)); \
    }

#define aMix(pkt, f, g, i, o) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = (_SHIFTL(A_MIXER, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16)); \
        _a->w1 = (_SHIFTL(i, 16, 16) | _SHIFTL(o, 0, 16)); \
    }

#define aDMEMMove(pkt, i, o, c) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_DMEMMOVE, 24, 8) | _SHIFTL(i, 0, 24); \
        _a->w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16); \
    }

#define aResample(pkt, f, p, s) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(p, 0, 16)); \
        _a->w1 = (u32)(s); \
    }

#define aLoadADPCM(pkt, c, d) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24); \
        _a->w1 = (u32)(d); \
    }

#define aPoleFilter(pkt, f, g, s) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = (_SHIFTL(A_POLEF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16)); \
        _a->w1 = (u32)(s); \
    }

#define aInterleave(pkt, l, r) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_INTERLEAVE, 24, 8); \
        _a->w1 = _SHIFTL(l, 16, 16) | _SHIFTL(r, 0, 16); \
    }

#define aSetLoop(pkt, a) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_SETLOOP, 24, 8); \
        _a->w1 = (u32)(a); \
    }

#define aADPCMdec(pkt, f, s) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(f, 16, 8); \
        _a->w1 = (u32)(s); \
    }

/* ---- filter parameter ids (SDK synthInternals.h) ---- */
#define AL_FILTER_FREE_VOICE 0
#define AL_FILTER_SET_SOURCE 1
#define AL_FILTER_ADD_SOURCE 2
#define AL_FILTER_ADD_UPDATE 3
#define AL_FILTER_RESET 4
#define AL_FILTER_SET_WAVETABLE 5
#define AL_FILTER_SET_PITCH 7
#define AL_FILTER_SET_UNITY_PITCH 8
#define AL_FILTER_START 9

/* ---- resampler filter (resample.c): the 0x34 byte node (delta is a float fraction) ---- */
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
} S13Resampler;

/* ---- reverb (reverb.c) ---- */
typedef struct {
    s16 fc;               /* 0x00 cutoff parameter */
    s16 fgain;            /* 0x02 */
    s16 pad04[2];         /* 0x04 */
    s16 fcoef[16];        /* 0x08 codebook loaded with aLoadADPCM (0x20 bytes) */
    s16 *fstate;          /* 0x28 8 byte filter state allocated from the heap */
    s32 first;            /* 0x2C */
} S13LowPass;             /* 0x30 bytes */

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
    S13LowPass *lp;       /* 0x20 */
    S13Resampler *rs;     /* 0x24 */
} S13Delay;               /* 0x28 bytes */

typedef struct {
    ALFilter filter;      /* 0x00 */
    s16 *base;            /* 0x14 start of the delay line buffer */
    s16 *input;           /* 0x18 current input position */
    u32 length;           /* 0x1C buffer length in samples */
    S13Delay *delay;      /* 0x20 */
    u8 sectionCount;      /* 0x24 */
    u8 pad25[3];
    s32 (*paramHdl)(void *filter, s32 paramID, void *param); /* 0x28 */
} S13Fx;

/* ---- loader filter (load.c): wave table types, 0x48 byte node ---- */
#define AL_ADPCM_WAVE 0
#define AL_RAW16_WAVE 1
#define AL_ADEC_WAVE 2 /* Acclaim compressed-audio wavetable */

typedef struct {
    u32 start;
    u32 end;
    u32 count;
    s16 state[16];
} S13AdpcmLoop;

typedef struct {
    u32 start;
    u32 end;
    u32 count;
} S13RawLoop;

typedef struct {
    s32 order;
    s32 npredictors;
    s16 book[1]; /* order*npredictors*8 coefficients */
} S13AdpcmBook;

typedef struct {
    u8 *base;
    s32 len;
    u8 type;
    u8 flags;
    union {
        struct {
            S13AdpcmLoop *loop;
            S13AdpcmBook *book;
        } adpcmWave;
        struct {
            S13RawLoop *loop;
        } rawWave;
    } waveInfo;
} S13WaveTable;

typedef s32 (*S13DMAproc)(s32 addr, s32 len, void *state);

typedef struct {
    ALFilter filter;      /* 0x00 */
    s16 *state;           /* 0x14 ADPCM decoder state in DMEM-side RAM */
    s16 *lstate;          /* 0x18 saved loop state */
    S13RawLoop loop;      /* 0x1C start/end/count */
    S13WaveTable *table;  /* 0x28 */
    s32 bookSize;         /* 0x2C bytes of codebook */
    S13DMAproc dma;       /* 0x30 */
    void *dmaState;       /* 0x34 */
    s32 sample;           /* 0x38 */
    s32 lastsam;          /* 0x3C */
    s32 first;            /* 0x40 */
    s32 memin;            /* 0x44 */
} S13Loader;

#endif
