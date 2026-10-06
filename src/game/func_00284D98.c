#include "b19_types.h"
void func_00271FD8(B19Vec3 *, B19Vec3 *, B19Vec3 *);
extern const f32 D_800C9F88;
void func_00284D98(void *owner, B19Obj *ref, B19Obj **arr, s32 n) {
    s32 i;
    B19Vec3 d;
    for (i = 0; i < n; i++) {
        B19Obj *o = arr[i];
        if (o->id != 0x57) {
            func_00271FD8(&d, &o->pos, &ref->pos);
            if (d.x * d.x + d.y * d.y + d.z * d.z <= D_800C9F88) o->unk14C = 1;
        }
    }
}
