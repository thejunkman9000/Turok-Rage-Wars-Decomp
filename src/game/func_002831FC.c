#include "b19_types.h"
s32 func_002831FC(u8 *a, s32 key) {
    B19Obj *o;
    s32 n = 0;
    for (o = *(B19Obj **)(a + 0xFC3C); o != 0; o = o->next) {
        if (o->id == 0x3EF || o->id == 0x41E) {
            if (o->unk12C == key) n++;
        }
    }
    return n;
}
