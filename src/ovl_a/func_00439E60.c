#include "o05_types.h"

typedef struct { s32 f0; u8 pad[0x30]; s32 f34; } S;
extern u8 D_8011FE88[];
s32 func_0028B1F8(void *p);

s32 func_00439E60(S *o, s32 n) {
    o->f0 = n;
    o->f34 = -1;
    if (n > 0) {
        o->f34 = func_0028B1F8(D_8011FE88);
    }
    return o->f34;
}
