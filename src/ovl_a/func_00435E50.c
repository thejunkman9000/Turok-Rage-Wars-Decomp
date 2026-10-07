#include "o05_types.h"

extern s32 D_80146894;
void func_002A3304(void);
void func_0025E3A4(void);

s32 func_00435E50(s32 a, s32 b, u32 c, s32 d) {
    if ((c >> 16) == 3) {
        if (d != 13) {
            return 0;
        }
        D_80146894 = 0;
        func_002A3304();
        func_0025E3A4();
    }
    return 0;
}
