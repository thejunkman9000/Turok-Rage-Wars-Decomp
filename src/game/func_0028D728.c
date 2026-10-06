#include "b20_types.h"
s32 func_0028D728(Level *lv, Entity *e) {
    Entity *base;
    if (e->flags & 0x80000) {
        return -1;
    }
    base = lv->entities;
    if (e >= base && base + (lv->numEntities - 1) >= e) {
        return (u32)((u8 *)e - (u8 *)base) / 0x2E8;
    }
    return -1;
}
