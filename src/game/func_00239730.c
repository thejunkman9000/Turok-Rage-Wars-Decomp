#include "b08_types.h"

typedef struct Obj20 {
    u8 pad0[0x20];
    s32 unk20;
} Obj20;

Obj20 *func_00237E70();

Obj20 *func_00239730(void) {
    Obj20 *o;

    o = func_00237E70();
    if (o != NULL) {
        o->unk20 = 1;
    }
    return o;
}
