/* func_0044E8B0 (ROM 0x1BC8B0, 21 insns + 3 linker pad words 0x1BC904..0x1BC90F; upstream func_8044DC60_de, no upstream source):
   sets a default light direction (-0.667424, 0.953462, -0.572078), normalises it through func_002720EC and enables the record.
   The three floats are the function's own literal pool (ROM 0xCB0A0..0xCB0AB, one pool entry per float). */
#include "s1007_types.h"

void func_002720EC(Vec3f *v);

void func_0044E8B0(S7Light *l) {
    l->dir.x = -0.667424f;
    l->dir.y = 0.953462f;
    l->dir.z = -0.572078f;
    func_002720EC(&l->dir);
    l->enabled = 1;
}
