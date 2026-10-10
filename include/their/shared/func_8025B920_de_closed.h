#ifndef FUNC_8025B920_DE_CLOSED_H
#define FUNC_8025B920_DE_CLOSED_H
#include "span_1000/code_8025A3EC.h"
#include "common/unused.h"
/* Finds and releases the first occupied nonlocal sound slot with matching value, identifier and flag 0x40, returning its index or -1. */
#include "types.h"









extern void func_802B2F00_de(void *sound, s16 sample);
extern s32 func_802B2620_de(void *sound);
extern void func_802B2F60_de(void *sound);

static __inline__ void release(SlotCC *slot) {
    Owner_func_8025B5F0_de *owner = slot->owner;
    void *sound;

    slot->active = 1;
    slot->flag = 0;
    if (slot->key != owner->key) {
        sound = owner->sound;
        func_802B2F00_de(sound, owner->samples[slot->index]);
        if (func_802B2620_de(sound) != 0) {
            func_802B2F60_de(sound);
        }
        slot->state = -1;
    }
}


#endif
