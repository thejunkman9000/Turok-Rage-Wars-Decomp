#include "b09_types.h"

extern B09Obj2 *D_80103FCC;
extern u8 D_801041F0[];
extern u8 D_44B4A0[];
void func_0023EE50(u8 *);

void func_0023EDF0(void) {
    D_80103FCC = (B09Obj2 *)D_801041F0;
    func_0023EE50(D_44B4A0);
}
