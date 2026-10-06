#include "p2_types.h"

void func_002227D0(Player *p, ObjDef *o, s32 a);

static inline s32 isBusy(Player *p) {
    if (p->state == 0x15 || p->state == 0x13 || p->state == 0x14) {
        return 1;
    }
    return 0;
}

s32 func_0022C6D4(Player *p, ObjDef *o) {
    if (isBusy(p)) {
        return 0;
    }
    if (o->f38 & 0x20000) {
        if (p->state == 0xD) {
            return 0;
        }
        if (p->state == 0xE) {
            return 0;
        }
        func_002227D0(p, o, 0xD);
        return 1;
    }
    return 0;
}