#ifndef UNBAKE_SPAN_1000_CODE_802B243C_H
#define UNBAKE_SPAN_1000_CODE_802B243C_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct ALEndEvent;
/* unbake published declaration: published_1d14c643be691ee3464d4c45 */
struct ALEndEvent {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
};

struct MidiState802B70B8;
/* unbake published declaration: published_2684026ea0a7bcd24772efbc */
struct MidiState802B70B8 {
    s32 start;
    s32 track_start;
    s32 current;
    s32 unkC;
    s32 end;
    f32 tick_scale;
    s16 division;
    s16 unk1A;
};

struct ALTempoEvent;
/* unbake published declaration: published_2ba3a692a75a9d0f5f53916c */
struct ALTempoEvent {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
    u8 byte1;
    u8 byte2;
    u8 byte3;
};

struct Obj_func_802B20D4_de;
/* unbake published declaration: published_cd42cc2c5846af002e1dfbc4 */
typedef struct Obj_func_802B20D4_de Obj_func_802B20D4_de;

/* unbake published declaration: published_350b3ffa1ac6927ca1934a7c */
extern u32 func_802B2120_de(Obj_func_802B20D4_de *seq, f32 sec, u32 tempo);

/* unbake published declaration: published_37974970f253290d6f34d2d5 */
extern double D_800C74E8_de;

struct ALEndEvent;
/* unbake published declaration: published_4632634aef88952dfdb82e5a */
typedef struct ALEndEvent ALEndEvent;

struct ALTempoEvent;
/* unbake published declaration: published_d414c3e1d13b24097a797156 */
typedef struct ALTempoEvent ALTempoEvent;

struct ALEvent;
/* unbake published declaration: published_38cf99f88a5bef95905e54e8 */
struct ALEvent {
    s16 type;
    union {
        ALMIDIEvent midi;
        ALTempoEvent tempo;
        ALEndEvent end;
    } msg;
};

struct func_802B742C_S1;
/* unbake published declaration: published_3dd1c90099c354e376c9df73 */
typedef struct func_802B742C_S1 func_802B742C_S1;

struct ALEvent;
/* unbake published declaration: published_68efc8293b52b54a96c64861 */
typedef struct ALEvent ALEvent;

struct func_802B73C4_S1;
/* unbake published declaration: published_6bd908afc281ae267e76ab23 */
typedef struct func_802B73C4_S1 func_802B73C4_S1;

struct func_802B742C_S1;
/* unbake published declaration: published_845a73efc7f2f25b09120cea */
struct func_802B742C_S1 {
    char pad0[0x8];
    u8 * unk8;
};

struct func_802B73C4_S1;
/* unbake published declaration: published_8e84d628ccc570c3993c7358 */
struct func_802B73C4_S1 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    u32 unk8;
    char pad8[0x10 - 0x8 - sizeof(u32)];
    s32 unk10;
};

struct ALSeq_s;
/* unbake published declaration: published_a63f4149d8e6db81bd0e248c */
typedef struct ALSeq_s ALSeq_s;

struct MidiState802B70B8;
/* unbake published declaration: published_aefdc6643065ef6f3b7826d3 */
typedef struct MidiState802B70B8 MidiState802B70B8;

/* unbake published declaration: published_b07dcd294aa14da2f44c6064 */
extern float D_800C74E0_de;

/* unbake published declaration: published_bb44b8847a6d52efdb47c4ac */
extern f32 func_802B20D4_de(Obj_func_802B20D4_de *arg0, s32 arg1, s32 arg2);

struct func_802B738C_S2;
/* unbake published declaration: published_c16c33178363f633b17dea7d */
struct func_802B738C_S2 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    int unk4;
    char pad4[0xC - 0x4 - sizeof(int)];
    unsigned short unkC;
};

struct ALSeqMarker;
/* unbake published declaration: published_c6e7a01376f3449fb2434321 */
struct ALSeqMarker {
    u8 *curPtr;
    s32 lastTicks;
    s32 curTicks;
    s16 lastStatus;
};

struct func_802B738C_S1;
/* unbake published declaration: published_c88b50c1e62d1ffe3e466d82 */
typedef struct func_802B738C_S1 func_802B738C_S1;

struct ALSeq_s;
/* unbake published declaration: published_dcc71bb413f6fd4037e4c451 */
struct ALSeq_s {
    u8 *base;
    u8 *trackStart;
    u8 *curPtr;
    s32 lastTicks;
    s32 len;
    f32 qnpt;
    s16 division;
    s16 lastStatus;
};

struct ALSeqMarker;
/* unbake published declaration: published_e6799bd2e63234e25f78b000 */
typedef struct ALSeqMarker ALSeqMarker;

/* unbake published declaration: published_e7ade63c39c454d668254290 */
extern void func_802B22D8_de(void *arg0, void *arg1);

struct func_802B738C_S2;
/* unbake published declaration: published_f3654e7e1d661e1ff815f2a1 */
typedef struct func_802B738C_S2 func_802B738C_S2;

struct func_802B738C_S1;
/* unbake published declaration: published_f6d61d3867fe4d83f81fcb24 */
struct func_802B738C_S1 {
    char pad0[0x8];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x1A - 0xC - sizeof(int)];
    unsigned short unk1A;
};

#endif
