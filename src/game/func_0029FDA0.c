#include "b23_types.h"

void func_0029D6A8(Mtx4f *m);
void func_0029DE3C(Mtx4f *a, Mtx4f *b, Mtx4f *dst);

void func_0029FDA0(Mtx4f *m) {
    Mtx4f tmp;

    func_0029D6A8(&tmp);
    func_0029DE3C(m, &tmp, m);
}
