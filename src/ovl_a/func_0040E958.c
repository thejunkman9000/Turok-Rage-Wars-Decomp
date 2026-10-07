#include "o02_types.h"
typedef struct { u8 pad[0x12]; u16 flags; } O02Flags;
void func_0040E958(O02Flags *p, s32 on) {
    if (on) {
        p->flags |= 8;
    } else {
        p->flags &= ~8;
    }
}
