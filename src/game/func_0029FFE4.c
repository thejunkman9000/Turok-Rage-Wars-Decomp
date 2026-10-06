#include "p4_types.h"
typedef struct { f32 x, y, z; } P4Vec3;
typedef struct { u8 pad[0x30]; P4Vec3 pos; } P4ObjPos;
void func_0029FFE4(P4ObjPos *o, P4Vec3 *out) {
    out->x = o->pos.x;
    out->y = o->pos.y;
    out->z = o->pos.z;
}
