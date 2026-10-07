#include "b07_types.h"
s32 func_00274544(void);
s32 func_0022EAFC(Actor *actor, s32 i);
s32 func_00232AAC(Actor *actor)
{
    s32 i = AT(s16, actor, 0x62E);
    s32 n = func_00274544() % 22;
    if (n >= 0) {
        do {
            i++;
            if (i >= 16) {
                i = 0;
            }
            if (func_0022EAFC(actor, i) != 0) {
                n--;
            }
        } while (n >= 0);
    }
    return i;
}
