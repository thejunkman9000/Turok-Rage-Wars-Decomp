#include "b20_types.h"

void func_00285D80(Level *lv, Entity *e, s32 arg);

void func_0028CDCC(Level *lv) {
    s32 n = lv->numEntities;
    s32 i;
    for (i = 0; i < n; i++) {
        Entity *e = (Entity *)((u8 *)lv->entities + i * 0x2E8);
        if (e->def->type == 3) {
            func_00285D80(lv, e, 0);
        }
    }
}
