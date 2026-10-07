#include "b11_types.h"

void func_0024C8B4(f32 *out, f32 t, f32 *a, f32 *b) {
    out[0] = a[0] + t * (b[0] - a[0]);
    out[1] = a[1] + t * (b[1] - a[1]);
    out[2] = a[2] + t * (b[2] - a[2]);
    out[3] = a[3] + t * (b[3] - a[3]);
}
