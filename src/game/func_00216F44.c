#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "math_helpers.h"
/* Returns the signed angle between an actor's facing and the direction to a point on the ground plane:
   normalises the offset from the actor at 0x8 to the point, takes its dot product with the facing
   built from the sine and cosine of the yaw at 0x6C, clamps it to -1..1, converts it through the arc
   cosine func_802745D0_de and negates it when the point lies on the other side, or returns zero when the
   point is at the actor. Scheduler lever, disclosed: the sine read sits in a do-while(0) block. */
extern f32 func_802B72B0_de(f32);



f32 func_80216F44_de(void *actor, Vec3 point) {
    f32 dx;
    f32 dz;
    f32 dist;
    f32 s;
    f32 c;
    f32 dot;
    f32 angle;
    dx = point.x - ((func_80216F44_S1 *)(actor))->unk8;
    dz = point.z - ((func_80216F44_S1 *)(actor))->unk10;
    dist = func_802B72B0_de(dx * dx + dz * dz);
    if (dist == 0.0f) {
        return 0.0f;
    }
    do {
        s = func_802B7130_de(((func_80216F44_S1 *)(actor))->unk6C);
    } while (0);
    c = -func_802B6560_de(((func_80216F44_S1 *)(actor))->unk6C);
    dot = (dx * -s + dz * c) / dist;
    dot = ((RW_MIN(dot, 1.0f))<((-1.0f))?((-1.0f)):(RW_MIN(dot, 1.0f)));
    angle = func_802745D0_de(dot);
    if (dx * c + dz * s > 0.0f) {
        return angle;
    }
    return -angle;
}
