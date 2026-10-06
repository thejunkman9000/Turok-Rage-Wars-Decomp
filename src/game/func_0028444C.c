#include "b19_types.h"
void func_00284544(B19Owner *, B19Obj *);
void func_00255E78(void *, void *);
void func_00255C58(void *, void *);
B19Obj *func_0028444C(B19Owner *owner, s32 a) {
    B19Obj *o;
    B19List *l;
    B19List *m;
    s32 i;
    if (owner->la.head == 0) {
        for (i = 0; i <= (a & 0xFF); i++) {
            l = (B19List *)((u8 *)owner + i * 0x14 + 0xFC28);
            if (l->tail != 0) {
                func_00284544(owner, l->tail);
                break;
            }
        }
    }
    o = owner->la.head;
    if (o == 0) return 0;
    func_00255E78(&owner->la, o);
    m = &owner->slot[a & 0xFF];
    func_00255C58(m, o);
    o->slotp = m;
    o->next2 = 0;
    o->unk1F0 = 0;
    o->flags = 0x100;
    return o;
}
