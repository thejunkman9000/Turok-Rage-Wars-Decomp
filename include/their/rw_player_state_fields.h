#ifndef RW_PLAYER_STATE_FIELDS_H
#define RW_PLAYER_STATE_FIELDS_H
#include "types.h"
/* Two consumed subrecords of the native 24-byte player state descriptor.
 * func_802227F4_de reads enter+0, timer+12 and parameter+16.
 * func_80220ED4_de reads update+4. Both call void callbacks with
 * player and actor/context in a0/a1. The flags pointer+8 and word+20
 * are excluded from these objects. No full descriptor/provider changes. */
typedef void (*RwPlayerStateCallback)(void *, void *);
typedef struct RwPlayerStateCallbacks {
    RwPlayerStateCallback enter;
    RwPlayerStateCallback update;
} RwPlayerStateCallbacks;
typedef struct RwPlayerStateTiming {
    s32 timer;
    s32 parameter;
} RwPlayerStateTiming;
#endif
