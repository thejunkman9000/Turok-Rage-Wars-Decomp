#include "p3_types.h"

typedef struct {
    u8 pad0[0x5C];
    u32 flags;             /* 0x5C */
    u8 pad60[0x118 - 0x60];
    u32 *info;             /* 0x118 */
} P3Ent2;

extern u8 D_801462E3;

void func_00283038(P3Ent2 *e, u32 *out) {
    u32 v = 0;
    if (*e->info & 0x2000000) {
        if (e->flags & 2) {
            v = 2;
        } else if (D_801462E3 == 2) {
            v = 1;
        }
    }
    *out |= v << 30;
}
