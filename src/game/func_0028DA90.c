#include "b20_types.h"

s32 *func_0028FD94(s32 *tbl, s32 idx);
void func_0028FDD8(s32 *tbl, s32 idx);

void func_0028DA90(Level *lv, s32 sel, s32 c, s32 b) {
    s32 *t;
    s32 *base;
    if (sel != 0) {
        base = lv->unk80;
    } else {
        base = lv->unk84;
    }
    t = func_0028FD94(func_0028FD94(func_0028FD94(base, 0), b), c);
    func_0028FD94(t, 0);
    func_0028FDD8(t, 1);
    func_0028FD94(t, 1);
}
