
#include "b19_types.h"
B19Obj *func_0028469C(B19Owner *owner, s32 key, B19Parent *par) {
    B19Obj *o = (owner->slot + par->info38->idx)->head;
    if (par != 0) {
        for (; o != 0; o = o->next) {
            if (o->unk124 == key && o->parent == par) return o;
        }
    } else {
        for (; o != 0; o = o->next) {
            if (o->unk124 == key) return o;
        }
    }
    return 0;
}
