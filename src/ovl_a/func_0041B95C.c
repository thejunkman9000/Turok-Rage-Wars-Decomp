#include "o03_types.h"
void func_0040E9A8(O3Item *it, s32 on);
void func_0041B95C(O3M7D5 *m, s32 idx, O3Item *it) {
    s32 i;
    if (m->flag[idx] == 0) {
        if (m->item[idx] != 0) {
            func_0040E9A8(m->item[idx], 0);
        }
        func_0040E9A8(it, 1);
        if (m->mode == 0) {
            m->item[idx] = it;
            return;
        }
        for (i = 3; i >= 0; i--) {
            m->item[i] = it;
        }
    }
}
