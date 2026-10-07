#include "b03_types.h"

extern s32 D_801468C4;
extern f32 D_800C7000;
Vec3f *func_0020993C(BrainB *b);
s32 func_00209A94(BrainB *b);
s32 func_0020F8F0(BrainB *b);
s32 func_0020F93C(BrainB *b);
s32 func_0020F984(BrainB *b);
f32 func_00272768(Vec3f *a, Vec3f *b);

s32 func_0020F6B8(BrainB *b) {
    Vec3f *from;
    ActorB *cur;
    ActorB *tgt;
    ActorB *sel;
    f32 curDist;
    f32 tgtDist;
    ActorB *v;
    ActorB *o1;
    ActorB *t;

    from = func_0020993C(b);
    t = b->unk64;
    if (t != NULL) {
        o1 = t->owner;
        if (o1->unk5E4 == 0) {
            b->unk64 = NULL;
        }
        if (o1->unk122C & 0x20) {
            b->unk64 = NULL;
        }
        if (D_801468C4 != 0 && b->actor->stats->unk92 == o1->stats->unk92) {
            b->unk64 = NULL;
        }
        t = b->unk64;
        if (t != NULL) {
            cur = t->owner;
            curDist = func_00272768(from, &cur->pos);
        } else {
            cur = NULL;
            curDist = 0.0f;
        }
    } else {
        cur = NULL;
        curDist = 0.0f;
    }
    if (b->target != NULL && (b->target->flags & 0x300000)) {
        tgt = b->target->owner;
        tgtDist = func_00272768(from, &tgt->pos);
    } else {
        tgt = NULL;
        tgtDist = 0.0f;
    }
    if (func_00209A94(b) == 0 || cur == NULL) {
        if (func_0020F93C(b) == 0) {
            b->unk64 = NULL;
            return 1;
        }
        if (tgt != NULL && func_0020F8F0(b) != 0) {
            b->unk64 = tgt;
            b->unk258 = tgt->pos.x;
            v = tgt;
        } else {
            v = b->actors[func_0020F984(b)];
            b->unk64 = v;
            b->unk258 = v->pos.x;
        }
    } else {
        if (tgt != NULL && tgtDist <= curDist) {
            b->unk64 = tgt;
            b->unk258 = tgt->pos.x;
            v = tgt;
        } else {
            s32 i = func_0020F984(b);
            if (i != -1 && (f32)b->value[i] < curDist) {
                v = b->actors[i];
                b->unk64 = v;
                b->unk258 = v->pos.x;
            } else if (b->state == 1 && D_800C7000 < curDist) {
                b->unk64 = NULL;
                return 1;
            } else {
                v = b->unk64;
                b->unk258 = v->pos.x;
            }
        }
    }
    b->unk25C = v->pos.y;
    b->unk260 = v->pos.z;
    return 1;
}
