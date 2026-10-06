#include "b01_types.h"

typedef struct Obj203A94 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ B01Def *def;
} Obj203A94;

s32 func_00203A94(Obj203A94 *obj) {
    s32 v = obj->def->unk1C;
    if (v != 0) {
        return v;
    }
    return 0x2F44;
}
