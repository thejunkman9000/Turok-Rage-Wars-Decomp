#include "p1_types.h"

typedef struct { u8 pad0[0x14]; Vec3f pos; } Obj;
void func_002720EC(Vec3f *v);

void func_002909F4(Obj *o, Vec3f *src) {
    o->pos = *src;
    func_002720EC(&o->pos);
}
