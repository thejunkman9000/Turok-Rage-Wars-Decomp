#ifndef UNBAKE_SPAN_1000_CODE_802B7488_H
#define UNBAKE_SPAN_1000_CODE_802B7488_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
struct ContReadFormat;
/* unbake published declaration: published_02145343262f53a6ab912fb4 */
typedef struct ContReadFormat ContReadFormat;

struct ALSynth_func_802B2650_de;
/* unbake published declaration: published_3083ecc7343691ab15111d1c */
struct ALSynth_func_802B2650_de {
    ALPlayer_s14 *head;
};

struct ALSndPlayer_func_802B2650_de;
struct ALSynth_func_802B2650_de;
/* unbake published declaration: published_072b60a8e388d5b94ded38cc */
struct ALSndPlayer_func_802B2650_de {
    ALPlayer_s14 node;
    ALEventQueue evtq;
    Message_func_802AF150_de nextEvent;
    struct ALSynth_func_802B2650_de *drvr;
    s32 target;
    void *sndState;
    s32 maxSounds;
    s32 frameTime;
    s32 nextDelta;
    s32 curTime;
};

struct ALGlobals_func_802B2650_de;
/* unbake published declaration: published_109e3929286a1c2ff4851b4d */
typedef struct ALGlobals_func_802B2650_de ALGlobals_func_802B2650_de;

/* unbake published declaration: published_1f01728af6c9a63ff54aca55 */
extern int D_800D4340;

struct ALSndpConfig;
/* unbake published declaration: published_346110b89397e4a2f0cdc23f */
struct ALSndpConfig {
    s32 maxSounds;
    s32 maxEvents;
    ALHeap *heap;
};

struct ALSoundState;
/* unbake published declaration: published_4c93c6ad0c714c042d8fe38a */
typedef struct ALSoundState ALSoundState;

struct ALSndPlayer_func_802B2650_de;
/* unbake published declaration: published_68bdf3ae277fe9d07cc58741 */
typedef struct ALSndPlayer_func_802B2650_de ALSndPlayer_func_802B2650_de;

struct ALSndpConfig;
/* unbake published declaration: published_79075396efc756f6fe369944 */
typedef struct ALSndpConfig ALSndpConfig;

struct ALSynth_func_802B2650_de;
/* unbake published declaration: published_d53e87258771e903d56f7c98 */
typedef struct ALSynth_func_802B2650_de ALSynth_func_802B2650_de;

struct ALGlobals_func_802B2650_de;
/* unbake published declaration: published_7954617def76a7abe3d49a7e */
struct ALGlobals_func_802B2650_de {
    ALSynth_func_802B2650_de drvr;
};

struct ContReadFormat;
/* unbake published declaration: published_90736ec596d7ec70b5adbfd2 */
struct ContReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 button;
    s8 stick_x;
    s8 stick_y;
};

struct ContPad;
/* unbake published declaration: published_98aa50367f586d028df72c53 */
struct ContPad {
    u16 button;
    s8 stick_x;
    s8 stick_y;
    u8 error;
};

/* unbake published declaration: published_a8cffba62b7b976e332d7fb5 */
extern int func_802B7C30_de();

struct ALSoundState;
/* unbake published declaration: published_c22be230ddd8491e68ed98e2 */
struct ALSoundState {
    ALVoice_s voice;
    void *sound;
    s16 priority;
    f32 pitch;
    s32 state;
    s16 vol;
    u8 pan;
    u8 fxMix;
};

/* unbake published declaration: published_c7ba6040ea00345902e05f52 */
extern void func_802B784C_de();

struct ContPad;
/* unbake published declaration: published_d878d47cb3ed10f26615b3bd */
typedef struct ContPad ContPad;

/* unbake published declaration: published_ee186fbc242b04d3bee21f7f */
extern void func_802B75F4_de(ContPad *data);

/* unbake published declaration: published_f51098e94aaf51bc98688c4f */
extern void func_802B768C_de();

#endif
