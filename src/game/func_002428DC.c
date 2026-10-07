#include "b10_types.h"

void func_00271FA4(f32 *a, f32 *b, f32 *c);

void func_002428DC(B10A *a, B10A *b) {
    a->f3C |= 8;
    func_00271FA4(b->v1C, b->v1C, &a->f5C);
}
