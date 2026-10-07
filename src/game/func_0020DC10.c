#include "b02_types.h"

void func_0020DCA0(B2Ctl *ctl);
void func_0020DC60(B2Ctl *ctl);

s32 func_0020DC10(B2Ctl *ctl) {
    if (ctl->target == NULL) {
        return 1;
    }
    if (ctl->curId < 3 || ctl->curId > 5) {
        func_0020DC60(ctl);
        return 1;
    }
    func_0020DCA0(ctl);
    return 1;
}
