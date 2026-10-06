#include "b07_types.h"

extern Actor *D_80102A48;

void func_00245608(s32 a0, s32 a1, void *fn);
void func_0022ED14(void);

void func_0022D53C(Actor *actor)
{
    D_80102A48 = actor;
    func_00245608(0x50, 0, func_0022ED14);
}
