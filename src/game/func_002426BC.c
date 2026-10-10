#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"






extern f32 func_8024D398_de(void *);
extern f32 func_8024E464_de(Input_func_802426CC_de *);
extern f32 func_8024D284_de(Input_func_802426CC_de *);
extern f32 func_8024E420_de(void *);
extern f32 func_80241728_de(Query_func_80241BAC_de *, f32, f32);
extern s32 func_8024491C_de(Input_func_802426CC_de *, Vec3, Vec3, void *, f32, f32, f32, f32);
extern void *D_80103FCC;
extern char D_801000F0;


void func_802426CC_de(Actor_func_802426CC_de *actor, void *owner, Input_func_802426CC_de *input, Query_func_80241BAC_de *query) {
    u8 collision[0x108];
    Vec3 next;
    f32 hit_y;
    f32 extent0;
    f32 extent1;
    f32 extent2;
    f32 extent3;
    void *saved_collision;

    saved_collision = D_80103FCC;
    D_80103FCC = collision;
    hit_y = func_80241728_de(query, input->x, input->z);
    input->owner = owner;
    extent0 = func_8024E464_de(input);
    extent1 = func_8024D398_de(input);
    extent2 = func_8024D284_de(input);
    extent3 = func_8024E420_de(input);
    next.x = input->x;
    next.y = hit_y + D_800C3760_de;
    next.z = input->z;
    if (func_8024491C_de(input, *(Vec3 *)&input->x, next, &D_801000F0,
                      extent0, extent1, extent2, extent3)) {
        actor->saved_query = *query;
        actor->flags |= 8;
        input->flags38 |= 0x10;
    } else {
        input->y = next.y;
        if (input->floor < 0.0f) input->floor = 0.0f;
        {
            s32 flags = actor->flags;
            actor->flags = flags | 0x20;
            if (input->kind == 1 && (input->flags100 & 0x300000))
                actor->flags = flags | 0x60;
        }
        input->flags38 = (input->flags38 & ~3) | 2;
    }
    D_80103FCC = saved_collision;
}
