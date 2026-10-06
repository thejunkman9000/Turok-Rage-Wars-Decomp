#include "b23_types.h"

extern char D_800CAF20[];

void func_002A1C08(char *buf, char *fmt, ...);

void func_002A2B24(AnimObj *o, s32 n) {
    o->unk58 = n;
    func_002A1C08(o->buf, D_800CAF20, n);
}
