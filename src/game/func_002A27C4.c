#include "b23_types.h"

extern s32 D_8014D2D0;

void func_002A2270(void);

void func_002A27C4(void) {
    D_8014D2D0 = 1 - D_8014D2D0;
    func_002A2270();
}
