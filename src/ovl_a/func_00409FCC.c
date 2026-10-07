#include "o01_types.h"

s32 func_00405338(s32 pad, s32 idx, u8 **out);
void func_00405648(u8 *src, u8 *dst, s32 n);
s32 func_002A137C(char *a, char *b);

s32 func_00409FCC(s32 unused, char *name, s32 pad, s32 *outIdx) {
    u8 buf[16];
    u8 *ent;
    s32 i;
    for (i = 0; i < 16; i++) {
        func_00405338(pad, i, &ent);
        func_00405648(ent, buf, 16);
        if (func_002A137C((char *)buf, name) == 0) {
            if (outIdx != 0) {
                *outIdx = i;
            }
            return 1;
        }
    }
    return 0;
}
