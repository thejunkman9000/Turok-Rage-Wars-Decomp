#include "b14_types.h"
extern u8 D_8010F30B;
void func_002647BC(void) {
    s32 v = 1;
    s32 i = 3;
    u8 *p = &D_8010F30B;
    while (i >= 0) {
        *p = v;
        i--;
        p--;
    }
}
