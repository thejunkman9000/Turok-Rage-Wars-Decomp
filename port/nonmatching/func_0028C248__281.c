#include "b20_types.h"
s32 func_00265570(s32 a, s32 b, s32 c, s32 *lo, s32 *hi);
void func_0028C248(Level *lv, Entity *e, Rec14 **outRecs, s32 *outCount) {
    s32 lo;
    s32 hi;
    s32 idx;
    Entity *base;
    if (!(e->flags & 0x80000)) {
        base = lv->entities;
        idx = -1;
        if (e >= base) {
            if (base + (lv->numEntities - 1) >= e) {
                idx = (u32)((u8 *)e - (u8 *)base) / 0x2E8;
            }
        }
    } else {
        idx = -1;
    }
    if (idx == -1) {
        *outCount = 0;
        return;
    }
    if (func_00265570(lv->unk11C8, lv->cnt11C0, idx, &lo, &hi) != 0) {
        *outRecs = lv->recA + lo;
        *outCount = hi - lo + 1;
    } else {
        *outRecs = 0;
        *outCount = 0;
    }
}
