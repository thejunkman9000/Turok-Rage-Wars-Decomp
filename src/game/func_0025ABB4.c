#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025A3EC.h"
#include "types.h"
#include "common/unused.h"
#include "span_C76B0/data.h"
#include "packed_float.h"

/* Ramps a voice pitch toward its target, interpolates the pitch curve and applies its scaled value to the context channel. */

extern void func_8025AA2C_de(View_func_8025AB94_de *);

extern void func_802B2F00_de(char *, s32);
extern void func_802B2E80_de(char *, f32);

static inline char *selectChannel(Context_func_8025AB94_de *context, s32 slot) {
    func_802B2F00_de(context->channels, context->slots[slot]);
    return context->channels;
}

static inline void apply(Context_func_8025AB94_de *context, s32 slot, f32 value, View_func_8025AB94_de *view) {
    char *channel = context->channels;

    func_802B2F00_de(channel, context->slots[slot]);
    value *= view->motion.factor;
    value *= view->scale;
    func_802B2E80_de(channel, value);
}

void func_8025AB94_de(View_func_8025AB94_de *view) {
    Motion_func_8025AB94_de *motion;
    Angles_func_8025AB94_de *angles;
    s32 refreshed;
    s32 falling;
    f32 position;
    s32 truncated;
    s16 index;
    s16 next;
    f32 base;
    f32 result;
    char *channel;
    Context_func_8025AB94_de *context;

    refreshed = 0;
    motion = &view->motion;
    angles = &view->angles;
    context = view->context;
    if ((view->flags & 0x400) && !(context->frame & 3)) {
        func_8025AA2C_de(view);
        refreshed = 1;
    }
    if ((view->flags & 0xA) == 0xA) {
        if (view->angles.delay > 0) {
            view->angles.delay--;
        } else {
            falling = 0;
            if (view->pitchStep < 0.0f) {
                falling = 1;
            }
            if (falling ? view->pitch < RW_BITS_TO_FLOAT(angles->target) : RW_BITS_TO_FLOAT(angles->target) < view->pitch) {
                view->pitch -= view->pitchStep;
                if (falling) {
                    if (!(RW_BITS_TO_FLOAT(angles->target) < view->pitch)) goto clamp_done;
                } else {
                    if (!(view->pitch < RW_BITS_TO_FLOAT(angles->target))) goto clamp_done;
                }
                view->pitch = RW_BITS_TO_FLOAT(angles->target);
clamp_done:;

                position = (view->pitch + D_800C3F60_de) * D_800C3F64_de;
                truncated = position;
                index = (s16)truncated;
                if (index != position) {
                    next = truncated + 1;
                    base = D_800CB8EC[index];
                    result = base + (position - index) * (D_800CB8EC[next] - base);
                } else {
                    result = D_800CB8EC[index];
                }
                motion->heading = result;
                channel = selectChannel(view->context, view->slot);
                func_802B2E80_de(channel, result * view->motion.factor * view->scale);
                return;
            }
        }
    }
    if (refreshed) {
        apply(view->context, view->slot, motion->heading, view);
    }
}
