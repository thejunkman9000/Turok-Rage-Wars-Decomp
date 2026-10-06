#include "b20_types.h"
void func_00271FD8(Vec3f *out, Vec3f *a, Vec3f *b);
s32 func_0028E768(Entity *e, Vec3f *target) {
    Vec3f d;
    f32 dist;
    u32 t;
    func_00271FD8(&d, &e->pos, target);
    dist = d.x * d.x + d.y * d.y + d.z * d.z;
    if (e->def->type == 1) {
        t = e->unkE4;
        if (t == 0x44E || t == 0x453 || t == 0x451 || t == 0x450 || t == 0x454 || t == 0x455 || t == 0x456) {
            return 0;
        }
        if (e->unk174 != 0) {
            if (e->unk1A4 != 0x3D) {
                if (dist <= 6553600.0f) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
