#ifndef ADEC_TYPES_H
#define ADEC_TYPES_H

#include "libaudio.h"

/* ---- wavetable / loader structures (libultra libaudio, load.c / adpcm.c / raw.c) ---- */
#define AL_ADPCM_WAVE 0
#define AL_RAW16_WAVE 1
#define AL_ADEC_WAVE 2 /* Acclaim compressed-audio wavetable */

typedef struct {
    u32 start;
    u32 end;
    u32 count;
    s16 state[16];
} ALADPCMloop;

typedef struct {
    u32 start;
    u32 end;
    u32 count;
} ALRawLoop;

typedef struct {
    s32 order;
    s32 npredictors;
    s16 book[1]; /* order*npredictors*8 coefficients */
} ALADPCMBook;

typedef struct {
    u8 *base;
    s32 len;
    u8 type;
    u8 flags;
    union {
        struct {
            ALADPCMloop *loop;
            ALADPCMBook *book;
        } adpcmWave;
        struct {
            ALRawLoop *loop;
        } rawWave;
    } waveInfo;
} ALWaveTable;

typedef s32 (*ALDMAproc)(s32 addr, s32 len, void *state);

/* the loader filter node as used by alLoadParam and the pull handlers */
typedef struct {
    ALFilter filter;
    s16 *state;   /* 0x14 ADPCM decoder state in DMEM-side RAM */
    s16 *lstate;  /* 0x18 saved loop state */
    ALRawLoop loop; /* 0x1C start/end/count */
    ALWaveTable *table; /* 0x28 */
    s32 bookSize; /* 0x2C bytes of codebook */
    ALDMAproc dma; /* 0x30 */
    void *dmaState; /* 0x34 */
    s32 sample; /* 0x38 */
    s32 lastsam; /* 0x3C */
    s32 first; /* 0x40 */
    s32 memin; /* 0x44 */
} ALLoader;


/* RSP audio command builders (gbi-style macros; the packet is advanced by the caller's ptr++) */
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define A_ADPCM 1
#define A_CLEARBUFF 2
#define A_LOADBUFF 4
#define A_SETBUFF 8
#define A_DMEMMOVE 10
#define A_LOADADPCM 11
#define A_SETLOOP 15
#define aSetBuffer(pkt, f, i, o, c) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(i, 0, 16)); \
        _a->w1 = (_SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16)); \
    }
#define aLoadBuffer(pkt, s) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_LOADBUFF, 24, 8); \
        _a->w1 = (u32)(s); \
    }
#define aClearBuffer(pkt, d, c) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_CLEARBUFF, 24, 8) | _SHIFTL(d, 0, 24); \
        _a->w1 = (u32)(c); \
    }
#define aDMEMMove(pkt, i, o, c) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_DMEMMOVE, 24, 8) | _SHIFTL(i, 0, 24); \
        _a->w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16); \
    }
#define aLoadADPCM(pkt, c, d) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24); \
        _a->w1 = (u32)(d); \
    }
#define aSetLoop(pkt, a) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_SETLOOP, 24, 8); \
        _a->w1 = (u32)(a) & 0x1FFFFFFF; \
    }
#define aADPCMdec(pkt, f, s) \
    { \
        Acmd *_a = (Acmd *)(pkt); \
        _a->w0 = _SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(f, 16, 8); \
        _a->w1 = (u32)(s) & 0x1FFFFFFF; \
    }

/* ---- Acclaim compressed-audio codec (MDCT + Huffman; 256 samples per frame) ---- */
typedef struct {
    f32 re;
    f32 im;
} AdecCpx;

/* FFT tables: n complex points */
typedef struct {
    f32 *cos;
    f32 *sin;
    s32 *bitrev;
    s32 n;
} MdctCtx;

/* stream decoder state (one global instance, D_80151CC8) */
typedef struct {
    u32 hdr0;          /* 0x00 first header word (returned to the caller of adecStreamOpen) */
    u32 hdr2;          /* 0x04 third header word */
    u32 *hdr;          /* 0x08 header / stream start */
    u32 nframes;       /* 0x0C total frames */
    u32 remaining;     /* 0x10 frames left (0 = stopped; polled through adecGetStopFlag) */
    u16 *rd;           /* 0x14 bitstream read pointer */
    s16 band[16];      /* 0x18 per-band scale indices of the current frame */
    u8 pad38[0xB8 - 0x38];
    s16 coef[256];     /* 0xB8 quantized coefficients of the current frame */
} AdecStream;

/* Huffman decoding tables */

/* an escape codebook: a run of up to 64 literal values */
typedef struct {
    s16 pad;
    u16 val;
} AdecCodeEnt;

typedef struct {
    u8 pad00[0xA0];
    AdecCodeEnt ent[64]; /* 0xA0 */
    s32 count;           /* 0x1A0 number of valid entries */
    u8 pad1A4[0x1B8 - 0x1A4];
} AdecCodebook;

typedef struct {
    u8 pad00[0x0E];
    u16 escBits;       /* 0x0E bit width of an escape value */
    u8 pad10[0x1C - 0x10];
    AdecCodebook *codebooks; /* 0x1C escape codebooks (0x1B8 bytes each) */
    u16 (*nodes)[2];   /* 0x20 binary tree nodes: {child for bit 0, child for bit 1}; 0x800 marks a leaf */
} AdecHuffTree;

/* one entry of the segment table (D_800D9594), stride 0x14 */
typedef struct {
    s32 kind;          /* 0x00 0 terminates the table */
    s32 start;         /* 0x04 */
    s32 len;           /* 0x08 segment covers start .. start + len */
    s32 pos;           /* 0x0C */
    AdecHuffTree *tree; /* 0x10 */
} AdecHuffSeg;

#endif
