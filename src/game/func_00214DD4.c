#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "math_helpers.h"
extern s32 D_8011CD20;
extern s32 D_8013B290;
extern s32 func_80214624_de(Actor_func_80214DD4_de *arg0, Tracker *arg1, Actor_func_80214DD4_de *target);
extern Actor_func_80214DD4_de *func_802149C0_de(Actor_func_80214DD4_de *arg0, Tracker *arg1, s32 arg2, s32 arg3);
extern f32 func_80215868_de(Actor_func_80214DD4_de *arg0, Vec3 pos, Actor_func_80214DD4_de *target, f32 arg3);
extern f32 func_80216F44_de(Actor_func_80214DD4_de *arg0, Vec3 pos);
extern Location *func_80219408_de(s8 *slot);
extern f32 func_8024D284_de(Actor_func_80214DD4_de *arg0);
extern f32 func_8024D398_de(Actor_func_80214DD4_de *arg0);
extern f32 func_8024E464_de(Actor_func_80214DD4_de *arg0);
extern void func_8024E79C_de(Actor_func_80214DD4_de *arg0, Vec3 pos, Vec3 *outPos, s32 *outRoom, s32 arg4, s32 arg5);
extern f32 func_8024E80C_de(Actor_func_80214DD4_de *arg0);
extern f32 func_80271AA8_de(Vec3 *arg0);
extern void func_80271F34_de(Vec3 *result, Vec3 *left, Vec3 *right);
extern void func_80271F68_de(Vec3 *result, Vec3 *left, Vec3 *right);
extern void func_80271F9C_de(Vec3 *result, Vec3 *vec, f32 scale);
extern void func_8027207C_de(Vec3 *arg0);


extern f32 func_802B72B0_de(f32 value);
/* Places the goal beside kind-7 targets: pushed away from the anchor by both extents. */
static inline void func_80214DD4_place_beside(Actor_func_80214DD4_de *arg0, Actor_func_80214DD4_de *target, Actor_func_80214DD4_de *anchor, Vec3 *outPos, s32 *outRoom) {
    Vec3 dir;
    Vec3 goal;
    if (anchor != 0) {
        func_80271F68_de(&dir, &target->pos, &anchor->pos);
        dir.y = 0.0f;
        func_8027207C_de(&dir);
    } else {
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = 0.0f;
    }
    func_80271F9C_de(&dir, &dir, func_8024D398_de(target) + func_8024D398_de(arg0) + D_800C216C_de);
    func_80271F34_de(&goal, &target->pos, &dir);
    func_8024E79C_de(target, goal, outPos, outRoom, 0, 0);
}
/** Picks what the tracker aims at (its target, itself, a slot or home point, or the actor) and
    fills out with the kind, target, reach, goal position and its offset from the actor, both in 3D
    and flattened to the ground plane. The third parameter is reused as the boost flag. */
void func_80214DD4_de(Actor_func_80214DD4_de *arg0, Tracker *arg1, s32 boost, TrackResult *out) {
    Vec3 pos;
    Vec3 probe;
    Vec3 away;
    Vec3 delta;
    s32 room;
    Actor_func_80214DD4_de *target;
    s32 kind;
    s32 mode;
    f32 range;
    f32 gap;
    f32 angle;
    f32 reach;
    Location *loc;
    boost = 0; /* FAKEMATCH: reuses the third parameter as the boost flag; a separate local gives the right code but not the target register numbering. Owner-accepted 2026-09-28; clean draft 395/399. */
    if (*arg0->kind != 1) {
        mode = -1;
    }
    if (arg1->team == D_8011CD20) {
        if ((arg1->flags & 0x40000) && arg1->unk78 == 0) {
            if (func_80214624_de(arg0, arg1, arg1->target) == 0) {
                arg1->flags &= ~0x40000;
            }
        } else {
            arg1->target = func_802149C0_de(arg0, arg1, 0, 1);
        }
    }
    target = arg1->target;
    kind = 6;
    if (arg1->active != 0) {
        if (target == 0) {
            kind = 3;
            if (arg1->slot != 0) {
                kind = 4;
            }
        } else if (target == arg1->self) {
            kind = 2;
        } else if (*target->kind == 5) {
            kind = 5;
        } else if (target->id == 0x64F) {
            kind = 7;
        } else if (D_8013B290 != 0) {
            kind = 0;
        } else if (((target->flags100 & 0x300000) && target->controller->owner == arg0 &&
                    target->controller->state == 2) ||
                   ((arg0->flags2E0 & 2) && arg0->id != 0xCA)) {
            kind = 1;
        } else {
            kind = 0;
        }
    }
    if (target != 0) {
        if (kind == 7) {
            func_80214DD4_place_beside(arg0, target, arg1->anchor, &pos, &room);
        } else {
            pos = target->pos;
            room = target->room;
            if (mode == 1) {
                pos.y += target->height + func_8024D284_de(target) * D_800C2170_de;
            }
        }
        gap = func_8024D398_de(target) + func_8024D398_de(arg0);
        switch (kind) {
            case 2:
                gap += D_800C2174_de;
            default:
                boost = 1;
                break;
            case 5:
            case 7:
                boost = 1;
                gap = 0.0f;
                break;
        }
    } else {
        gap = func_8024D398_de(arg0);
        switch (kind) {
            case 4:
                loc = func_80219408_de(&arg1->slot);
                pos = loc->pos;
                gap = 0.0f;
                room = loc->room;
                if (arg1->slot == 2 || arg1->slot == kind) {
                    boost = 1;
                }
                break;
            case 3:
                pos = arg1->homePos;
                room = arg1->homeRoom;
                boost = 1;
                break;
            case 6:
                pos = arg0->pos;
                room = arg0->room;
                if (mode == 2) {
                    pos.y = func_8024E80C_de(arg0);
                }
                break;
        }
    }
    func_80271F34_de(&pos, &pos, &arg1->offset);
    if (gap > 0.0f) {
        func_80271F68_de(&away, &arg0->pos, &pos);
        angle = func_80271AA8_de(&away);
        pos.x -= gap * func_802B7130_de(angle);
        pos.z -= gap * func_802B6560_de(angle);
    }
    if (mode == 2) {
        pos.y = RW_MIN_LT(pos.y, func_8024E80C_de(arg0));
    }
    if (boost) {
        reach = func_8024E464_de(arg0);
        probe.x = arg0->pos.x + reach * func_802B7130_de(arg1->angle);
        probe.y = arg1->height;
        probe.z = arg0->pos.z + reach * func_802B6560_de(arg1->angle);
        range = func_80215868_de(arg0, probe, target, D_800C2178_de);
        pos.y = arg1->height;
    } else {
        range = func_80216F44_de(arg0, pos);
    }
    func_80271F68_de(&delta, &pos, &arg0->pos);
    out->kind = kind;
    out->target = target;
    out->range = range;
    out->pos = pos;
    out->delta = delta;
    out->dist = func_802B72B0_de(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
    delta.y = 0.0f;
    pos.y = 0.0f;
    out->flatPos = pos;
    out->flatDelta = delta;
    out->flatDist = func_802B72B0_de(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
}
