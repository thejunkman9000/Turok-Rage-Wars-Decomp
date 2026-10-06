#include "p2_types.h"

s32 func_0022E630(Player *p) {
    if (p->state == 3 && (p->f86C == 0x5E29 || p->f86C == 0x5E59)) {
        return 1;
    }
    return p->state == 3 && p->f86C >= 0x7DA && p->f86C < 0x7DF;
}