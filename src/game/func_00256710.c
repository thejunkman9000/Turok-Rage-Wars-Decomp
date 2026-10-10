#include "types.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"
struct SharedDirectionState {
    u32 unknown0[5];
    Vec3 direction;
    s32 ready;
};
struct NestingQueue {
    u32 unknown0[7];
    s32 depth;
};
struct ResourceFlagRecord {
    u32 unknown0[3];
    u32 flags;
    u32 unknown10[6];
};

/* Steps an object's nesting count at 0x1C up and back down while it is nonzero, each step bracketed by func_802BCF30_de and func_802BCF50_de: going up past one calls func_802BB2A0_de, and coming down to anything but zero calls func_802BB420_de. */

extern s32 func_802BCF30_de(void);
extern void func_802BCF50_de(s32);
extern void func_802BB2A0_de(struct NestingQueue *, s32, s32);
extern void func_802BB420_de(struct NestingQueue *, s32, s32);

void func_802566E8_de(struct NestingQueue *obj) {
    s32 mask;
    s32 mask2;

    if (obj->depth == 0) {
        return;
    }
    mask = func_802BCF30_de();
    if (++obj->depth != 1) {
        func_802BCF50_de(mask);
        func_802BB2A0_de(obj, 0, 1);
    } else {
        func_802BCF50_de(mask);
    }
    mask2 = func_802BCF30_de();
    if (--obj->depth != 0) {
        func_802BCF50_de(mask2);
        func_802BB420_de(obj, 0, 1);
        return;
    }
    func_802BCF50_de(mask2);
}
