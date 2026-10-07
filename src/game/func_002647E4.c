#include "b14_types.h"
extern u8 D_8010F30B;
void func_002647E4(void) {
    s32 i = 3;
    u8 *p = &D_8010F30B;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}
