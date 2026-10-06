#include "p4_types.h"
typedef struct { u8 pad0[0x88]; s32 f88; u8 pad8c[0xF8 - 0x8C]; s32 fF8; } P4Rsrc;
s32 *func_0028FD94(s32 a, s32 b);
void func_002536F4(s32 a, s32 b);
void func_002537D8(s32 a, s32 b);
void func_0028D578(P4Rsrc *o) {
    if (o->fF8 != 0) {
        s32 *p = func_0028FD94(o->f88, 0);
        while (*p != 0) {
            func_002536F4(0, *p++);
        }
        func_002537D8(0, o->fF8);
        o->fF8 = 0;
        o->f88 = 0;
    }
}
