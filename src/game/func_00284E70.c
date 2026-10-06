#include "b19_types.h"
extern const f32 D_800C9F8C;
void func_00271FD8(B19Vec3 *, B19Vec3 *, B19Vec3 *);
void func_00281A70(void *, B19Obj *, B19Obj **, s32);
void func_00284E70(void *owner, B19Obj **arr, s32 n) {
    s32 i, j;
    B19Vec3 d;
    B19Obj *o;
    B19Obj *e;
    for (i = 0; i < n; i++) {
        o = arr[i];
        switch (o->id) {
        case 0xC:
            break;
        case 0x22:
            func_00281A70(owner, o, arr, n);
            break;
        case 0x57:
            for (j = 0; j < n; j++) {
                e = arr[j];
                if (e->id != 0x57) {
                    func_00271FD8(&d, &e->pos, &o->pos);
                    if (d.x * d.x + d.y * d.y + d.z * d.z <= D_800C9F8C) e->unk14C = 1;
                }
            }
            break;
        }
    }
}
