#include "o03_types.h"
void func_0029A5D4(s32 a, s32 b, s32 c, s32 d, s32 e);
O3Item *func_0040ECB0(s32, s32);
void func_0041B8A8(O3M7D5 *m, s32 idx, s32 id) {
    O3Item *it;
    s32 i;
    if (m->flag[idx] == 0) {
        if (m->item[idx] != 0) {
            func_0029A5D4(m->item[idx]->h.id, 0x10, 0, 0, 0);
        }
        it = func_0040ECB0((s32)m->own, id & 0xFFFF);
        func_0029A5D4(it->h.id, 0xF, 0, 0, 0);
        if (m->mode == 0) {
            m->item[idx] = it;
            return;
        }
        for (i = 3; i >= 0; i--) {
            m->item[i] = it;
        }
    }
}
