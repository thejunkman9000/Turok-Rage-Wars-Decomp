#include "b01_types.h"

extern u8 D_8011FE88[];
void func_002671B0(B01Actor *a, B01Actor *b, s32 kind, Vec3f pos, B01Pair extra);
void func_00285D80(void *mgr, B01Actor *actor, s32 flag);

void func_00204A68(B01Actor *actor, B01State *state) {
    s32 idx = *(s8 *)((u8 *)actor->def + 0x1D);
    f32 scale;
    f32 a;
    f32 b;
    s32 r;
    B01Pair extra;
    s8 t;

    if (idx != -1) {
        scale = (f32)idx * 0.007874016f;
        r = actor->unkE6 == 1 ||
            (actor->unk108 == (s8)state->unkCA && actor->unk10A == (s8)state->unkCA &&
             ((state->unkCB != 0 && !(actor->flags & 0x400)) ||
              ((actor->unk10C < 3 && (actor->flags & 0x400)
                    ? (a = (f32)actor->unk12C * scale, b = actor->unk134)
                    : (a = (f32)actor->unk10C * scale, b = actor->unk104)),
               a <= b)));
        if (r != 0) {
            extra.a = 0;
            func_002671B0(actor, actor, 7, actor->pos, extra);
            func_00285D80(D_8011FE88, actor, 0);
        }
    }
}
