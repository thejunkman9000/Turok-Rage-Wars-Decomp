#include "s1007_types.h"

void func_002720EC(Vec3f *v);

void func_auto_0044EF30(S7Light *l) {
    l->dir.x = -0.667424f;
    l->dir.y = 0.953462f;
    l->dir.z = -0.572078f;
    func_002720EC(&l->dir);
    l->enabled = 1;
}
