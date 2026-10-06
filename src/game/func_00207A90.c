#include "b01_types.h"

typedef struct Obj207A90 {
    u8 pad0[0x18];
    struct { u8 pad0[0x38]; u32 flags38; } *def;
} Obj207A90;

void func_00207A90(Obj207A90 *obj, u32 *flags) {
    if (!(obj->def->flags38 & 0x40)) {
        *flags &= 0xFFFEFFFF;
    }
}
