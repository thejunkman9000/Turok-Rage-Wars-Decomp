#include "b20_types.h"

s32 *func_0028FD94(s32 *tbl, s32 idx);
void func_0028FDD8(s32 *tbl, s32 idx);

void func_0028B64C(Level *lv, s32 a, s32 bit, s32 set) {
    s32 *t;
    u8 *bits;
    u8 *b2;
    s32 m;
    ActorDef *def;
    if (lv->unk0 == 2) {
        return;
    }
    if (lv->unk1B40C == a) {
        {
        Entity *e = &lv->entities[bit];
        def = e->def;
        }
        if ((u32)(def->type - 9) < 2) {
            if (*(u32 *)((u8 *)def + 4) & 0x200) {
                return;
            }
        }
    }
    t = func_0028FD94(func_0028FD94(func_0028FD94(lv->unk80, 0), a), 0);
    func_0028FD94(t, 0);
    func_0028FDD8(t, 1);
    bits = (u8 *)func_0028FD94(t, 1);
    b2 = bits;
    m = 1 << (bit & 7);
    if (set != 0) {
        bits[bit / 8] |= m;
    } else {
        b2[bit / 8] &= ~m;
    }
}
