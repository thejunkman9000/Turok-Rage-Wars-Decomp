#include "span_1000/code_802609CC.h"
#include "types.h"
/* Switches an animation track to its pending clip when asked and the clip differs: keeps a copy of the track, loads the pending clip's resource and, when it is ready, reads its frame count and length, hands the old state to the previous track slot, restarts the track on the new clip and reports the switch; otherwise, or when not switching, it reloads the current clip and reports no switch. */



extern char D_0025F56C;
extern char D_800C41B0_de;

extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);
extern void *func_8025193C_de(s32, s32, s32, s32, s32, Anim *, void *, void *, s32);
extern s32 func_802624D8_de(Anim *);
extern void *func_8026049C_de(Anim *);
extern void *func_8028FDB4_de(void *, s32);

static inline s32 load(Anim *anim, s32 table, s32 key, s32 id) {
    s32 size;
    s32 clip;
    void *header;

    if (id == -1) {
        anim->resource = 0;
        return 0;
    }
    clip = func_8028FE3C_de(table, key, id, &size);
    anim->resource = func_8025193C_de(0, clip, clip, size, 4, anim, &D_0025F56C, &D_800C41B0_de, 0);
    if (func_802624D8_de(anim) == 0) {
        return 0;
    }
    header = func_8026049C_de(anim);
    anim->frames = ((u16 *)func_8028FDB4_de(header, 0))[3];
    anim->current = id;
    anim->length = ((u16 *)func_8028FDB4_de(func_8028FDB4_de(header, 3), 0))[1];
    return 1;
}

void func_80261670_de(Anim *anim, s32 table, s32 key, s32 blend, s32 *switched, Anim *previous) {
    s32 current;
    s32 next;
    Anim saved;

    current = anim->current;
    next = anim->next;
    if (next != current && blend != 0) {
        anim->active = 1;
        saved = *anim;
        if (load(anim, table, key, next)) {
            if (previous != 0) {
                *previous = saved;
                previous->current = current;
                previous->next = current;
                previous->active = 1;
            }
            anim->current = next;
            anim->next = next;
            anim->time = 0;
            anim->blending = 0;
            anim->active = 1;
            if (switched != 0) {
                *switched = 1;
            }
            return;
        }
        if (switched != 0) {
            *switched = 0;
        }
        load(anim, table, key, current);
        return;
    }
    if (switched != 0) {
        *switched = 0;
    }
    load(anim, table, key, current);
}
