#include "o03_types.h"
void func_0029A73C();
void func_0041B95C(O3M7D5 *m, s32 idx, O3Item *it);
s32 func_0041BC50(O3M7D5 *m, s32 a1, s32 a2, s32 a3) {
    O3Item *it;
    s32 idx;
    func_0029A73C();
    if (a3 != 1) return 0;
    idx = a2 & 0xFFFF;
    if (m->flag[idx] != 0) return 0;
    it = m->item[idx];
    if (it != 0 && (it->h.unk12 & 0x10)) {
        if (it->nbr[0] != 0) {
            func_0041B95C(m, idx, it->nbr[0]);
        }
    }
    return 0;
}
