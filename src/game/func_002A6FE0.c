#include "b24_types.h"

void func_002A6FE0(Emit *e) {
    if (e->owner != NULL) {
        if (e->flags & 1) {
            if (e->owner->unk13B != 0) {
                e->owner->unk13B--;
            }
        }
        if (e->flags & 2) {
            if (e->owner->unk1D9 != 0) {
                e->owner->unk1D9--;
            }
        }
    }
    e->owner = NULL;
    if (e->unk24 < *(f32 *)((u8 *)e->def + 4)) {
        e->unk24 = *(f32 *)((u8 *)e->def + 4);
    }
}
