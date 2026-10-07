#include "o03_types.h"
void func_0029A73C();
void func_0029A5D4(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 func_0041BE0C(O3M7D5 *m, s32 a1, s32 a2, s32 a3, s32 a4) {
    O3Item *it;
    func_0029A73C();
    if (m->flag[a2 & 0xFFFF] != 0) return 0;
    it = m->item[a2 & 0xFFFF];
    if (it != 0) {
        func_0029A5D4(it->h.id, 1, a2, a3, a4);
    }
    return 0;
}
