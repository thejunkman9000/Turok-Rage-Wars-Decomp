#ifndef UNBAKE_SPAN_1000_CODE_802BE0D0_H
#define UNBAKE_SPAN_1000_CODE_802BE0D0_H
#include "acmd.h"
#include "audio_callbacks.h"
#include "../types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
/* unbake published declaration: published_166e25c35a8d8f44d88e93e0 */
extern float D_801514C0[];

/* unbake published declaration: published_21ed2113d5f3eb8200f5cf26 */
extern void func_802C021C_de();

/* unbake published declaration: published_23e6a98e66b3dd82a8f65a45 */
extern float D_800C7CEC_de;

/* unbake published declaration: published_36619738b7f37eb8a797d59b */
extern void func_802BFF90_de(float *arg0, float *arg1, float *arg2);

/* unbake published declaration: published_69b4734d5341cf571bd38b0a */
extern s32 func_802BF804_de(f32 *out, s16 *in);

struct ALLoadFilter48_2;
/* unbake published declaration: published_6ae6088d918fc2b997930e06 */
typedef struct ALLoadFilter48_2 ALLoadFilter48_2;

/* unbake published declaration: published_6fc643b0fbfcd17c71981fa3 */
extern void func_802BFF30_de(float *arg0, float *arg1);

/* unbake published declaration: published_7f9acce266186da280a616f7 */
extern void func_802BF514_de();

/* unbake published declaration: published_80f6e9abb07bc8f984152106 */
extern float D_800CCF10;

/* unbake published declaration: published_82e002e86302c921492159c8 */
extern float D_801512C0[];

/* unbake published declaration: published_8568150b229a4366bf4e3cfb */
extern u32 func_802BFE3C_de(void);

/* unbake published declaration: published_87507d630c6f9604eaf2c16e */
extern float D_801510C0[];

/* unbake published declaration: published_877df7ddce48ecbef14f80d5 */
extern s16 func_802C0044_de(f32 arg0);

struct ALRawLoop;
/* unbake published declaration: published_8d0f7fd1b90d36d270b144e0 */
typedef struct ALRawLoop ALRawLoop;

struct ALRawLoop;
/* unbake published declaration: published_a228d6b426fc9bfe7887f559 */
struct ALRawLoop {
    u32 start;
    u32 end;
    u32 count;
};

struct ALADPCMWaveInfo_func_802BE514_de;
typedef struct ALADPCMWaveInfo_func_802BE514_de ALADPCMWaveInfo_func_802BE514_de;

struct ALADPCMBook;
typedef struct ALADPCMBook ALADPCMBook;

struct ALADPCMBook;
struct ALADPCMBook {
    s32 order;
    s32 npredictors;
    s16 book[1];
};
struct ALADPCMWaveInfo_func_802BE514_de;
struct ALADPCMWaveInfo_func_802BE514_de {
    void *loop;
    ALADPCMBook *book;
};
struct ALWaveTable_s_func_802BE514_de;
struct ALWaveTable_s_func_802BE514_de {
    u8 *base;
    s32 len;
    u8 type;
    u8 flags;
    union {
        ALADPCMWaveInfo_func_802BE514_de adpcmWave;
    } waveInfo;
};
struct ALLoadFilter_func_802BE514_de;
struct ALWaveTable_s_func_802BE514_de;
/* unbake published declaration: published_9e9f89e46c0929b5c5fa7bd5 */
struct ALLoadFilter_func_802BE514_de {
    ALFilter_s14 filter;
    void *state;
    void *lstate;
    ALRawLoop loop;
    struct ALWaveTable_s_func_802BE514_de *table;
    s32 bookSize;
    ALDMAproc dma;
    void *dmaState;
    s32 sample;
    s32 lastsam;
    s32 first;
    s32 memin;
};

/* unbake published declaration: published_a9f964099149b4ce92825535 */
extern FftTables *func_802BF67C_de(s32 n);

struct Shape_typemap_165;
/* unbake published declaration: published_b367515874d47009fcf43bb5 */
extern void func_802C000C_de(s32 unused0, struct Shape_typemap_165 *arg1, s32 unused2);

/* unbake published declaration: published_b82a5a5f4a091448543f678f */
extern void func_802BFE68_de(s32 *arg0, s32 arg1);

struct ALLoadFilter_func_802BE514_de;
/* unbake published declaration: published_c2bc3c6418bebef42f204974 */
typedef struct ALLoadFilter_func_802BE514_de ALLoadFilter_func_802BE514_de;

struct ALLoadFilter48_2;
/* unbake published declaration: published_ca4d7f68fd3ec7374576b675 */
struct ALLoadFilter48_2 {
    ALFilter_s14 filter;
    void *state;
    void *lstate;
    ALRawLoop loop;
    void *table;
    s32 bookSize;
    ALDMAproc dma;
    void *dmaState;
    s32 sample;
    s32 lastsam;
    s32 first;
    s32 memin;
};

/* unbake published declaration: published_ce82aadae53deccb1969b496 */
extern float D_801516C0[];

/* unbake published declaration: published_d4e5c5c3bcda2f502c7797d3 */
extern float D_800C7CF0_de;

/* unbake published declaration: published_da36c91f0a5b64b87565d508 */
extern float D_800C7CF4_de;

/* unbake published declaration: published_e09d227d11c165327e280b9c */
extern float D_800CCF18;

/* unbake published declaration: published_e27d56c63c90d27ab582c0dd */
extern Acmd *func_802C3988(void *filter, s16 *outp, s32 byteCount, s32 sampleOffset, Acmd *p);

/* unbake published declaration: published_e2f46e253305334af1a7fd59 */
extern float D_800CCF24;

/* unbake published declaration: published_f2ddcff8c8b2479a6520374b */
extern float D_800CCF20;

/* unbake published declaration: published_fb723e935329b226225dab07 */
extern float D_800C7CE8_de;

/* unbake published declaration: published_fc8ee64f5ea99e0e61f1731c */
extern Acmd *func_802BE514_de(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);

typedef struct DecodeState {
    s32 first;
    s32 third;
    void *source;
    s32 second;
    s32 count;
    void *cursor;
} DecodeState;
extern unsigned short D_800D54B8;
extern unsigned short D_800D54BA;
extern unsigned short D_800D54BC;
extern unsigned short D_800D54BE;
extern unsigned short D_800D54C0_de;

#endif
