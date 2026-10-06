#include "p3_types.h"

extern s32 D_8010C1B4;
void func_0025E3EC(void);
void func_0025E3C8(void);

void func_0025E280(s32 on) {
    D_8010C1B4 = on;
    if (on) {
        func_0025E3EC();
    } else {
        func_0025E3C8();
    }
}
