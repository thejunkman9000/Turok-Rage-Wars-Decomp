#include "b20_types.h"
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
s32 func_0028E83C(Entity *e, Vec3f *target) {
    Vec3f d;
    f32 dist;
    u32 t;
    if (*(u8 *)e == 1 && e->def->type == 7) {
        func_00271FD8(&d, &e->pos, target);
        dist = d.x * d.x + d.z * d.z;
        d.y = 0;
        if (262144.0f < dist) {
            return 0;
        }
        return 0xFF;
    }
    if (e->def->type == 1) {
        t = e->unkE4;
        if (t == 0x44E || t == 0x453 || t == 0x451 || t == 0x450 || t == 0x454 || t == 0x455 || t == 0x456) {
            return 0xFF;
        }
    }
    return 0;
}
