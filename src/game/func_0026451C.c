#include "b14_types.h"
s32 osGetThreadId(OSThread *t);
extern s32 D_800D0E5C;
extern OSMesgQueue D_8010FBC0;
s32 func_0026451C(s32 flag) {
    s32 r = osRecvMesg(&D_8010FBC0, 0, flag) == 0;
    if (r != 0) {
        D_800D0E5C = osGetThreadId(0);
    }
    return r;
}
