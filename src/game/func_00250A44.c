#include "b12_types.h"

extern u8 D_801462E5;
void func_0025021C(void);
void func_00250458(void);

void func_00250A44(void) {
    if (D_801462E5 != 0) {
        func_00250458();
    } else {
        func_0025021C();
    }
}
