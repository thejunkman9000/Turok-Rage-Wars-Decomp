#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802106E0.h"
#include "types.h"
/* Probes one of a vehicle's eight wheel rays: casts from the vehicle position to its scaled wheel offset
 * through func_8024491C_de and stores the wheel's reach as the XZ distance to whatever was hit (diagonals
 * scaled by 1/sqrt 2, components tested against the zeroed y), or the full ray length on a miss. */
extern Vec3 D_800C88A0_de[8];
extern Hit_func_802106E0_de *D_80103FCC;
extern char D_80103FD0[];
extern f32 func_8024E464_de(Vehicle *);
extern f32 func_8024D398_de(Vehicle *);
extern f32 func_8024D284_de(Vehicle *);
extern f32 func_8024E420_de(Vehicle *);
extern s32 func_8024491C_de(Vehicle *, Vec3, Vec3, char *, f32, f32, f32, f32);
void func_802106E0_de(Vehicle *vehicle, s32 wheel) {
    Vec3 from;
    Vec3 to;
    Vec3 delta;
    f32 a;
    f32 b;
    f32 c;
    from = vehicle->pos;
    to = D_800C88A0_de[wheel];
    to.x *= vehicle->wheels->length;
    to.y *= vehicle->wheels->length;
    to.z *= vehicle->wheels->length;
    to.x += from.x;
    to.y += from.y;
    to.z += from.z;
    from.y += 61.44f;
    a = func_8024E464_de(vehicle);
    b = func_8024D398_de(vehicle);
    c = func_8024D284_de(vehicle);
    if (func_8024491C_de(vehicle, from, to, D_80103FD0, a, b, c, func_8024E420_de(vehicle))) {
        delta = D_80103FCC->pos;
        delta.x -= from.x;
        delta.y = 0.0f;
        delta.z -= from.z;
        if (delta.x != delta.y) {
            if (delta.z == delta.y) {
                vehicle->wheels->reach[wheel] = ((delta.x) < (delta.y) ? -(delta.x) : (delta.x));
            } else {
                vehicle->wheels->reach[wheel] = (((delta.x) < (delta.y) ? -(delta.x) : (delta.x)) + ((delta.z) < (delta.y) ? -(delta.z) : (delta.z))) * 0.70710677f;
            }
        } else if (delta.z != delta.y) {
            vehicle->wheels->reach[wheel] = ((delta.z) < (delta.y) ? -(delta.z) : (delta.z));
        }
    } else {
        vehicle->wheels->reach[wheel] = vehicle->wheels->length;
    }
}
