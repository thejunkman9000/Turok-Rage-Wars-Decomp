#include "o02_types.h"
typedef struct { u8 pad[0x12]; u16 flags; } S_func_0040E9D0;
void func_0040E9D0(S_func_0040E9D0 *p, s32 on) {
    if (on) {
        p->flags |= 0x100;
    } else {
        p->flags &= ~0x100;
    }
}
