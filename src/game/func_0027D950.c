#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"

extern char D_8011AD70;
extern char D_8011AF38;
extern f32 D_800C4C64_de;
extern void func_80273198_de(void *arg0, void *arg1);
extern f32 func_80275DD4_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_80275410_de(void *arg0, s32 arg1);
extern void func_80275688_de(void *arg0, s32 arg1);
extern void func_80274244_de(void *arg0, void *arg1);
extern void func_8026F620_de(void *arg0, void *arg1, void *arg2);
extern f32 func_802760BC_de(s32 arg0, s32 arg1);
extern void func_802736D4_de(void *arg0, f32 arg1);








/** Resolve the shared effect object selected by the actor state. */
void *func_8027D97C_de(void *arg0, void *arg1) {
    char output[0x40];
    char state[0x10];
    void *shared;
    f32 value;

    {
        s32 sw_state_value = (s8)(((func_8027D950_S1 *)(arg0))->unk1D0.v0 + 8);
        if ((unsigned int)sw_state_value > 10) {
            goto sw_state_default;
        }
        switch (sw_state_value) {
        case 0: goto sw_state_neg_8;
        case 1: goto sw_state_default;
        case 2: goto sw_state_neg_6;
        case 3: goto sw_state_neg_5;
        case 4: goto sw_state_neg_4;
        case 5: goto sw_state_neg_3;
        case 6: goto sw_state_neg_2;
        case 7: goto sw_state_neg_4;
        case 8: goto sw_state_0;
        case 9: goto sw_state_0;
        case 10: goto sw_state_0;
        }
    }
    do {
    sw_state_neg_8:
        shared = &D_8011AD70;
        func_80273198_de(shared, (char *)arg0 + 0x174);
        return shared;
    sw_state_neg_6:
        if (arg1 == 0) {
            return 0;
        }
        return &((func_8027D950_S2 *)(arg1))->unkE94;
    sw_state_neg_4:
    sw_state_neg_1:
        if (arg1 == 0) {
            return 0;
        }
        return &((func_8027D950_S2 *)(arg1))->unkE54;
    sw_state_neg_3:
        value = func_80275DD4_de(0, ((func_8027D950_S1 *)(arg0))->unk8,
            ((func_8027D950_S1 *)(arg0))->unk10);
        if (((func_8027D950_S1 *)(arg0))->unkC - value <= D_800C4C64_de) {
            func_80275410_de(state, 0);
            func_80274244_de(state, output);
            shared = &D_8011AD70;
            func_8026F620_de(shared, &D_8011AF38, output);
            return shared;
        }
    sw_state_neg_5:
        return &D_8011AF38;
    sw_state_neg_2:
        func_80275688_de(state, 0);
        func_80274244_de(state, output);
        shared = &D_8011AD70;
        func_8026F620_de(shared, &D_8011AF38, output);
        return shared;
    sw_state_0:
    sw_state_1:
    sw_state_2:
        value = func_802760BC_de(0, ((func_8027D950_S1 *)(arg0))->unk1D0.v1);
        func_802736D4_de(&D_8011AD70, value);
        return &D_8011AD70;
    sw_state_default:
        return 0;
    
    } while (0);
}

/* Refreshes an attached actor's placement and returns its position and heading through optional pointers: an actor flagged 0x10000 of one of the bone-mounted types takes its position and heading from its parent's bone matrix (or just the parent's position when the parent has no skeleton) and clears its field 0x14, and an actor flagged 0x400000 places its local offset through its owner's transform (the owner's model matrix for owners flagged 0x300000, built through func_80226DD0_de when missing). */









extern void func_80270910_de(f32 *out, void *in);
extern void func_80272898_de(void *matrix, Vec3 *in, Vec3 *out);
extern void func_80272B38_de(void *matrix, Vec3 *in, Vec3 *out);
extern void func_80226DD0_de(func_80228774_S5 *model, f32 *out);




void func_8027DAD0_de(Actor_func_8027DAD0_de *actor, Vec3 *outPosition, Vec3 *outHeading) {
    f32 matrix[16];
    Vec3 position;
    Vec3 heading;
    f32 built[16];
    Parent *parent;
    Parent *owner;
    void *transform;
    void *skeleton;

    position = actor->position;
    heading = actor->heading;
    if (actor->flags & 0x10000) {
        parent = actor->parent;
        switch (actor->type) {
            case 2:
            case 0xB:
            case 0xF:
            case 0x2D:
            case 0x4F:
            case 0x56:
            case 0x126:
            case 0x12A:
            case 0x132:
            case 0x41E:
                skeleton = parent->skeleton;
                if (skeleton != 0) {
                    func_80270910_de(matrix, (char *)skeleton + actor->bone * 64);
                    func_80272898_de(matrix, &actor->offset, &position);
                    func_80272B38_de(matrix, &actor->heading, &heading);
                    actor->position = position;
                    actor->facing = heading;
                } else {
                    position = parent->position;
                    actor->position = position;
                }
                break;
        }
        actor->unk14 = 0;
    }
    if (actor->flags & 0x400000) {
        owner = actor->owner;
        if (owner->flags & 0x300000) {
            if (owner->model->unk5DC != 0) {
                transform = &((func_8027DAA4_S1 *)(owner->model->unk5DC))->unk160;
            } else {
                func_80226DD0_de(owner->model, built);
                transform = built;
            }
        } else {
            transform = owner->transform;
        }
        func_80272898_de(transform, &actor->offset, &position);
        actor->position = position;
    }
    if (outPosition != 0) {
        *outPosition = position;
    }
    if (outHeading != 0) {
        *outHeading = heading;
    }
}
