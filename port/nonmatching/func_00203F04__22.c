#include "b01_types.h"

extern B01Actor **D_80103FCC;
extern u8 D_80103FD0[];
void func_00271FD8(Vec3f *dst, Vec3f *a, Vec3f *b);
f32 func_0024D274(B01Actor *actor);
s32 func_00244494(B01Actor *actor, Vec3f from, Vec3f to, void *hit);

typedef struct { s32 a, b, c; } IV3;

s32 func_00203F04(B01Actor *actor, B01State *state, B01Actor *target) {
    Vec3f from;
    Vec3f to;
    func_00271FD8(&to, &target->pos, &actor->pos);
    from.x = state->vec130.x;
    from.y = state->vec130.y;
    from.z = state->vec130.z;
    *(IV3 *)&from = *(IV3 *)&actor->pos;
    from.y += func_0024D274(actor) * 0.5f;
    *(IV3 *)&to = *(IV3 *)&target->pos;
    to.y += func_0024D274(target) * 0.5f;
    if (func_00244494(actor, from, to, D_80103FD0) == 0 || *D_80103FCC == target) {
        return 1;
    }
    return 0;
}
