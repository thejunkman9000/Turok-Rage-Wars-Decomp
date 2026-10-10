#include "b20_types.h"
s32 func_00265570(s32 a, s32 b, s32 c, s32 *lo, s32 *hi);
void func_0028C1B0(Level *lv, u16 *idp, Rec14 **outRecs, s32 *outCount) {
    s32 hi;
    s32 lo;
    s32 r; s32 a; s32 b; s32 id;
    id = *idp; a = lv->unk11CC; b = lv->cnt11C4;
    r = func_00265570(a, b, id, &lo, &hi);

    if (r != 0) {
        *outRecs = lv->recB + lo;
        *outCount = hi - lo + 1;
    } else {
        *outRecs = 0;
        *outCount = 0;
    }
}
