#include "b03_types.h"

extern f32 D_800C7040;
extern f32 D_800C7044;
extern f32 D_800C7048;
extern f32 D_800C704C;
extern f32 D_800C7050;
extern f32 D_800C7054;
extern f32 D_800C7058;
extern f32 D_800C705C;
extern f32 D_800C7060;
extern f32 D_800C7064;
extern f32 D_800C7068;
extern f32 D_800C706C;
extern f32 D_800C7070;
extern EntList D_8013B364[];
extern s32 D_801468F4;
extern s32 D_80146938;
f32 func_00209B64(BrainB *b);
f32 func_00209C5C(BrainB *b);
s32 func_0020D1CC(EntList *list, s32 a, s32 b);
f32 func_00216F44(ActorB *a, f32 x, f32 y, f32 z);

s32 func_0021035C(BrainB *b, s32 idx) {
    ActorB *t;
    f32 f;
    f32 d;
    s32 th1;
    s32 th2;
    s32 th3;
    s32 hit;
    s32 zone;
    s32 v;
    f32 k;

    t = b->actors[idx]->owner;
    hit = 0;
    if (t->unk122C & 0x20) {
        return 0;
    }
    f = func_00209C5C(b);
    th1 = (s32)(f * D_800C7040);
    th2 = (s32)(f * D_800C7044);
    th3 = (s32)(f * D_800C7048);
    if (func_00216F44(b->actor, t->pos.x, t->pos.y, t->pos.z) < 0.0f) {
        d = -func_00216F44(b->actor, t->pos.x, t->pos.y, t->pos.z);
    } else {
        d = func_00216F44(b->actor, t->pos.x, t->pos.y, t->pos.z);
    }
    if (d <= D_800C704C) {
        if (b->value[idx] < th1) {
            hit = 1;
        }
        zone = 0;
    } else if (D_800C704C < d && d <= D_800C7050) {
        v = b->value[idx];
        zone = 1;
        if (v < th2) {
            b->value[idx] = (s32)((f32)v * D_800C7054);
            hit = 1;
        }
    } else {
        v = b->value[idx];
        if (v < th3) {
            hit = 1;
            b->value[idx] = (s32)((f32)v * D_800C7058);
        }
        zone = 2;
    }
    if (D_80146938 != 0) {
        if (b->actor->stats->unk94 != 0 && b->actor->stats->unk80 == 0xC) {
            hit = 1;
        }
    }
    if (hit != 0) {
        if (D_801468F4 != 0 && t->stats->unk8F != 0) {
            b->value[idx] = (s32)((f32)b->value[idx] * D_800C705C);
        }
        if (t->unk1450 == 0) {
            b->value[idx] = (s32)((f32)b->value[idx] * D_800C7060);
        }
        if (func_0020D1CC(D_8013B364, b->unk4, t->brain->unk4) != 0) {
            return 1;
        }
    }
    if (b->unk328 != t) {
        return 0;
    }
    if (b->unk324 < 0x1C3) {
        return 0;
    }
    v = b->value[idx];
    if (v < th1 * 2) {
        switch (zone) {
        case 0:
            break;
        case 1:
            k = D_800C7064;
            b->value[idx] = (s32)((f32)v * k);
            break;
        case 2:
            k = D_800C7068;
            b->value[idx] = (s32)((f32)v * k);
            break;
        }
        b->value[idx] = (s32)((f32)b->value[idx] * ((D_800C706C - func_00209B64(b)) * D_800C7070 + D_800C7070));
        return 1;
    }
    return 0;
}
