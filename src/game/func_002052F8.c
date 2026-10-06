#include "b01_types.h"

typedef struct Obj2052F8 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ B01Def *def;
} Obj2052F8;

s32 func_002052F8(Obj2052F8 *obj) {
    s32 v = obj->def->unk24;
    if (v != 0) {
        return v;
    }
    return 0x5334;
}
