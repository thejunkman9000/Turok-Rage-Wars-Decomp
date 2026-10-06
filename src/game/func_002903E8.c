#include "p4_types.h"
extern u8 D_8011F448[];
typedef struct { u8 kind; u8 pad1[0x17]; void *p18; u8 pad1c[0x1D0 - 0x1C]; s32 f1D0; } P4Obj3;
void func_002903E8(P4Obj3 *o) {
    o->p18 = D_8011F448;
    o->kind = 3;
    o->f1D0 = 0;
}
