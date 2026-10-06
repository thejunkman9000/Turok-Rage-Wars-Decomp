#include "b19_types.h"
void func_00255D10(void *, B19Obj *, B19Obj *);
void func_00255C58(void *, B19Obj *);
void func_00255CB4(void *, B19Obj *);
void func_0028472C(B19Owner *owner, B19Obj *obj) {
    B19Obj *p = owner->lb.head;
    if (p != 0) {
        for (; p != 0; p = p->next2) {
            if (p->parent == obj->parent) break;
        }
    }
    if (p != 0) {
        func_00255D10(&owner->lb, p, obj);
    } else if (obj->parent->flags & 0x2000) {
        func_00255C58(&owner->lb, obj);
    } else {
        func_00255CB4(&owner->lb, obj);
    }
    obj->flags |= 0x1000000;
}
