#include "o03_types.h"
void func_0040E9A8(O3Item *it, s32 on);
s32 func_0041BEA8(O3M7D5 *m) {
    s32 i;
    for (i = 0; i < m->cnt; i++) {
        func_0040E9A8(m->item[i], 1);
    }
    return 0;
}
