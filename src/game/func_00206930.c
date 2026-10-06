#include "b01_types.h"

typedef struct DefE10 {
    u8 pad0[0xE];
    u8 unkE;
    u8 padF;
    u8 unk10;
} DefE10;

typedef struct Obj206930 {
    u8 pad0[0x18];
    DefE10 *def;
} Obj206930;

void func_00206930(Obj206930 *obj, void *unused, u8 *arg2) {
    obj->def->unkE = arg2[7];
    obj->def->unk10 = arg2[7];
}
