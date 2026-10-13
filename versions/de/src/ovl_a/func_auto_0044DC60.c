/* unit of the Germany release at ROM 0x1B3C60 (VRAM 0x44DC60; c_syms.ld knows it as func_0044E8B0, 1.1 ROM 0x1BC8B0); one pad word 0x1B3C5C precedes it.  Same code as the Europe func_auto_0044EF30 (S7Light default direction). */
#include "s1007_types.h"

void func_002720EC(Vec3f *v);

void func_auto_0044DC60(S7Light *l) {
    l->dir.x = -0.667424f;
    l->dir.y = 0.953462f;
    l->dir.z = -0.572078f;
    func_002720EC(&l->dir);
    l->enabled = 1;
}
