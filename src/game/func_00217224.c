#include "b04_types.h"
void func_00271FD8(Vec3f *, Vec3f *, Vec3f *);
typedef struct { u8 pad0[8]; Vec3f pos; u8 pad14[0x5C]; f32 unk70; } B04Obj;
f32 func_00217224(B04Obj *o, Vec3f v) {
    func_00271FD8(&v, &v, &o->pos);
    v.y = v.y - o->unk70;
    return v.x * v.x + v.y * v.y + v.z * v.z;
}
