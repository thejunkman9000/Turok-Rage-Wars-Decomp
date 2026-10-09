#include "b01_types.h"

extern u8 D_8011FE88[];
void func_002671B0(B01Actor *a, B01Actor *b, s32 kind, Vec3f pos, B01Pair extra);
void func_00285D80(void *mgr, B01Actor *actor, s32 flag);

static inline s32 r01_check(B01Actor *actor, B01State *state, f32 scale) {
    if (actor->unkE6 == 1) return 1;
    if (actor->unk108 != (s8)state->unkCA || actor->unk10A != (s8)state->unkCA) return 0;
    if (state->unkCB != 0 && !(actor->flags & 0x400)) return 1;
    if (actor->unk10C < 3 && (actor->flags & 0x400)) {
        return (f32)actor->unk12C * scale <= actor->unk134;
    } else {
        return (f32)actor->unk10C * scale <= actor->unk104;
    }
}

void func_00204A68(B01Actor *actor, B01State *state) {
    s32 idx = *(s8 *)((u8 *)actor->def + 0x1D);
    B01Pair extra;

    if (idx != -1) {
        if (r01_check(actor, state, (f32)idx * 0.007874016f)) {
            extra.a = 0;
            func_002671B0(actor, actor, 7, actor->pos, extra);
            func_00285D80(D_8011FE88, actor, 0);
        }
    }
}
