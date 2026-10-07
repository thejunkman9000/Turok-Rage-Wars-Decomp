#include "o04_types.h"
extern O04ModeF60 *D_800E4F60;
void func_0029A73C(void);
s32 func_0042BC34(void) {
    func_0029A73C();
    if (D_800E4F60->state != 3) {
        return 0;
    }
    D_800E4F60->state = 5;
    D_800E4F60->unk3E0 = 4;
    return 0;
}
