#include "b16_types.h"

void func_00274090(f32 *p) {
    while (*p < -3.14159265f) {
        *p += 6.28318531f;
    }
    while (*p >= 3.14159265f) {
        *p -= 6.28318531f;
    }
}
