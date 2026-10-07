#include "b01_types.h"

typedef struct B01Word0C {
    u8 pad0[0xC];
    u32 unkC;
} B01Word0C;

u32 func_00205700(B01Word0C *obj) {
    return obj->unkC & 0x200;
}
