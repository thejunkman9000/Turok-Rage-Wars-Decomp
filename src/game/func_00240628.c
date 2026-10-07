#include "b09_types.h"

typedef struct B09Key4 {
    u8 pad0[4];
    f32 key;
} B09Key4;

s32 func_00240628(B09Key4 *a, B09Key4 *b) {
    s32 r = 1;
    if (a->key < b->key) {
        r = -1;
    }
    return r;
}
