#include "b20_types.h"
s32 func_00265570(s32 a, s32 b, s32 c, s32 *lo, s32 *hi);
void func_0028D7A0(Level *lv, s32 which, s32 id, Rec14 **outRecs, s32 *outCount) {
    s32 lo;
    s32 hi;
    s32 a;
    s32 b;
    s32 off;
    if (which != 0) {
        a = lv->unk11CC;
        b = lv->cnt11C4;
    } else {
        a = lv->unk11C8;
        b = lv->cnt11C0;
    }
    if (func_00265570(a, b, id, &lo, &hi) != 0) {
        off = lo * 0x14;
        if (which != 0) {
            *outRecs = (Rec14 *)((u8 *)lv->recB + off);
        } else {
            *outRecs = (Rec14 *)((u8 *)lv->recA + off);
        }
        *outCount = hi - lo + 1;
    } else {
        *outRecs = 0;
        *outCount = 0;
    }
}
