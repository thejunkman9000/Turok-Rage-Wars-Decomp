#include "types.h"
#ifndef UNBAKE_SPAN_1000_CODE_802B2614_H
#define UNBAKE_SPAN_1000_CODE_802B2614_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct Slot_func_802B2ED0_de;
/* unbake published declaration: published_123d1b5a03c1dfceeb84f88c */
typedef struct Slot_func_802B2ED0_de Slot_func_802B2ED0_de;

struct Params_func_802B2E80_de;
/* unbake published declaration: published_334b959b32db9338895cd62b */
struct Params_func_802B2E80_de {
    s16 f0;
    s32 f4;
    s32 f8;
};

union ALSndpEvent;
/* unbake published declaration: published_7b732901d8cd6e11d7dfe7cd */
union ALSndpEvent {
    Message_func_802AF150_de msg;
    struct {
        s16 type;
        void *state;
    } common;
};

struct ALSndPlayer;
/* unbake published declaration: published_830d079a175337e4934d14c7 */
struct ALSndPlayer {
    ALPlayer_s node;
    ALEventQueue evtq;
    Message_func_802AF150_de nextEvent;
    void *drvr;
    s32 target;
    void *sndState;
    s32 maxSounds;
    s32 frameTime;
    s32 nextDelta;
    s32 curTime;
};

struct ALSndPlayer;
union ALSndpEvent;
/* unbake published declaration: published_6310f48f2b9f93b1b0859969 */
extern void func_802B2780_de(struct ALSndPlayer * arg0, union ALSndpEvent * arg1);

struct func_802B7D18_S2;
/* unbake published declaration: published_736d229dcfda7b3bdbe9c878 */
struct func_802B7D18_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0x10 - 0x8 - sizeof(s32)];
    s32 unk10;
};

struct func_802B7FA0_S1;
/* unbake published declaration: published_75c0883e4a096c542bed939f */
struct func_802B7FA0_S1 {
    char pad0[0x40];
    void * unk40;
};

struct func_802B7D18_S2;
/* unbake published declaration: published_83c46c2826b33eb158db4db0 */
typedef struct func_802B7D18_S2 func_802B7D18_S2;

struct Params_func_802B2DE0_de;
/* unbake published declaration: published_a49238fd478bc156ee7cd022 */
typedef struct Params_func_802B2DE0_de Params_func_802B2DE0_de;

struct ALSndPlayer;
/* unbake published declaration: published_c229aed23d3a5d7a1c9c3298 */
typedef struct ALSndPlayer ALSndPlayer;

struct func_802B7FA0_S1;
/* unbake published declaration: published_d36daa9f6311af98606decda */
typedef struct func_802B7FA0_S1 func_802B7FA0_S1;

union ALSndpEvent;
/* unbake published declaration: published_d63fcb4627128074d381324c */
typedef union ALSndpEvent ALSndpEvent;

struct Slot_func_802B2ED0_de;
/* unbake published declaration: published_ee6459405e18f61715936434 */
struct Slot_func_802B2ED0_de {
    char pad0[0x20];
    short value;
    char pad22[0xE];
};

/* unbake published declaration: published_f07c536711e68b114281ed73 */
extern s32 func_802B2BBC_de(void *node);

struct Params_func_802B2DE0_de;
/* unbake published declaration: published_f19135c176771cddb5e171f0 */
struct Params_func_802B2DE0_de {
    s16 f0;
    s32 f4;
    s8 f8;
};

struct Params_func_802B2E80_de;
/* unbake published declaration: published_f86324d04b445bb9b7abdc74 */
typedef struct Params_func_802B2E80_de Params_func_802B2E80_de;

s32 func_802B2CF0_de(s32 val, f32 div);
#endif
