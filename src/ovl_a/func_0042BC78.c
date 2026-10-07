#include "o04_types.h"
extern O04ModeF60 *D_800E4F60;
void func_0042ACB0(void);
s32 func_0042BC78(void) {
    if (D_800E4F60->state != 3) {
        return 0;
    }
    func_0042ACB0();
    return 0;
}
