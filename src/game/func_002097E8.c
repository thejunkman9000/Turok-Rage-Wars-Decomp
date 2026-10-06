#include "b02_types.h"

void func_00208000(B2Ctl *ctl);

void func_002097E8(B2Ctl *ctl, B2Actor *owner) {
    ctl->owner = owner;
    func_00208000(ctl);
}
