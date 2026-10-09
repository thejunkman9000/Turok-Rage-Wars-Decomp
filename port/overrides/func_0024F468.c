#include "b11_types.h"

void func_0024D860(void *q, void *a, u32 a2, u32 a3);

/* port: func_0024D860(f32 *q, Obj *a) reads a0 and a1 (func_00216288 calls this as
 * func_0024F468(&sp70, o)); the 1-parameter decomp dropped the second register. */
void *func_0024F468(void *q, void *a, u32 a2, u32 a3) {
    func_0024D860(q, a, a2, a3);
    return q;
}
