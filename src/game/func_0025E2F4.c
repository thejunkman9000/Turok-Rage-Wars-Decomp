#include "p3_types.h"

extern s32 D_80146890;
extern s32 D_8010DE0C[];
void func_0025E338(void);

void func_0025E2F4(s32 v) {
    if (D_80146890 == 0 && D_8010DE0C[0] != v) {
        D_8010DE0C[0] = v;
        if (v == 0) {
            func_0025E338();
        }
    }
}
