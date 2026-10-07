#include "o03_types.h"
extern s8 D_80102B0D[];
void func_0041DBA0(s32 *p) {
    s32 n = 0;
    while (1) {
        *p = *p + 1;
        if (*p >= 4) {
            *p = 0;
        }
        n++;
        if (n >= 6) {
            *p = -1;
            return;
        }
        if (D_80102B0D[*p * 0x190] >= 0) {
            return;
        }
    }
}
